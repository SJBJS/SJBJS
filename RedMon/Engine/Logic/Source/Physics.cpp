#include "../Physics.h"

Physics::Physics()
{

}

Physics::~Physics()
{
}

bool Physics::Initialize()
{
	if (!ObjectManager::Instance())
		return false;
	m_manager = ObjectManager::Instance();

	settings = new Settings;
	settings->hz = 60.0f;

	b2Vec2 gravity;
	gravity.Set(0.0f, -9.8f);
	m_world = new b2World(gravity);

	myListener = new Listener();
	m_world->SetContactListener(myListener);


	objectSize = m_manager->Size();
	m_objects = new b2Body*[objectSize];
	for (int i = 0; i < objectSize; ++i)
	{
		CreateObject(*(m_manager->at(i)), i);
	}
	return true;
}

void Physics::Update()
{
	float32 timeStep = settings->hz > 0.0f ? 1.0f / 60 : float32(0.0f);

	if (settings->pause)
	{
		if (settings->singleStep)
		{
			settings->singleStep = 0;
		}
		else
		{
			timeStep = 0.0f;
		}
	}
	// 물리 처리 전에 값 갱신.
	for (int i = 0; i < m_manager->Size(); ++i)
		UpdateObject(*(m_manager->at(i)), i);

	settings->velocityIterations = 8;
	settings->positionIterations = 3;

	m_world->SetAllowSleeping(false);
	m_world->SetWarmStarting(settings->enableWarmStarting > 0);
	m_world->SetContinuousPhysics(settings->enableContinuous > 0);
	m_world->SetSubStepping(settings->enableSubStepping > 0);

	// 물리 업데이트.
	m_world->Step(timeStep, settings->velocityIterations, settings->positionIterations);

	//물리 처리 값을 저장.
	SaveObject();
}

void Physics::Shutdown()
{
	if (m_objects) {
		for (int i = 0; i < objectSize; ++i) {
			if (m_objects[i])
			{
				m_world->DestroyBody(m_objects[i]);
				m_objects[i] = NULL;
			}
		}
		delete[] m_objects;
	}
	if (myListener)
		delete myListener;
	if (m_world)
	{
		delete m_world;
		m_world = NULL;
	}
	if (settings)
	{
		delete settings;
		settings = NULL;
	}
}

void Physics::CreateObject(ActorClass & data, int idx)
{
	b2Vec2 textureWH = { data.GetActorWH().x / 2, data.GetActorWH().y / 2 };
	b2Vec2 position = { data.GetPosition().x, data.GetPosition().y };
	CollisionData collsionData = data.GetCollisionData();


	b2BodyDef bodyDef;
	bodyDef.type = static_cast<b2BodyType>(collsionData.type);
	bodyDef.bullet = collsionData.bullet;
	bodyDef.position.Set(position.x, position.y);
	bodyDef.gravityScale = collsionData.gravityScale;

	b2PolygonShape polygons;
	polygons.SetAsBox(textureWH.x, textureWH.y);

	b2FixtureDef fd;
	fd.shape = &polygons;
	fd.density = collsionData.density;
	fd.friction = collsionData.friction;
	fd.restitution = collsionData.restitution;

	m_objects[idx] = m_world->CreateBody(&bodyDef);
	m_objects[idx]->CreateFixture(&fd);
	m_objects[idx]->SetUserData(&data);
}

void Physics::UpdateObject(ActorClass & data, int idx)
{
	CollisionData colldata = data.GetCollisionData();
	b2Vec2 position = { data.GetPosition().x, data.GetPosition().y };
	m_objects[idx]->SetTransform(b2Vec2(position.x, position.y), -data.GetRotate()* 3.1415 / 180);
	m_objects[idx]->SetActive(data.IsPhysics());
	m_objects[idx]->SetBullet(colldata.bullet);
	m_objects[idx]->SetType(static_cast<b2BodyType>(colldata.type));
	m_objects[idx]->SetGravityScale(colldata.gravityScale);
	m_objects[idx]->GetFixtureList()->SetDensity(colldata.density);
	m_objects[idx]->GetFixtureList()->SetFriction(colldata.friction);
	m_objects[idx]->GetFixtureList()->SetRestitution(colldata.restitution);
}

void Physics::SaveObject()
{
	for (int i = 0; i < objectSize; ++i)
	{
		b2Vec2 position = m_objects[i]->GetPosition();
		m_manager->at(i)->SetPosition(position.x, position.y);
		if (m_manager->at(i)->GetCollisionData().isRotateFrozen) {
			m_objects[i]->SetTransform(b2Vec2(position.x, position.y), -m_manager->at(i)->GetRotate()* 3.1415 / 180);
		}
		else {
			m_manager->at(i)->SetRotate(-m_objects[i]->GetAngle() / 3.1415 * 180);
		}
	}
	for (int i = 0; i < m_manager->Size(); ++i)
	{
		ActorClass * taget = m_manager->at(i);
		if (taget->IsCollistion())
		{
			ActorClass * other = m_manager->at(i)->GetCollisionOther();
			switch (taget->GetCollisionMode())
			{
			case CollisionMode::Enter:
				taget->OnCollisionEnter(other);
				break;
			case CollisionMode::Stay:
				break;
			case CollisionMode::Exit:
				taget->OnCollisionExit(other);
				break;

			default:
				break;
			}
			m_manager->at(i)->SetCollistion(false, nullptr, CollisionMode::None);
		}
	}
}
