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
	settings = new Settings;
	settings->hz = 60.0f;
	
	b2Vec2 gravity;
	gravity.Set(0.0f, 0.0f);
	m_world = new b2World(gravity);

	myListener = new Listener();
	m_world->SetContactListener(myListener);

	b2BodyDef bd;
	b2Body* ground = m_world->CreateBody(&bd);

	objectSize = ObjectManager::Instance()->Size();
	m_objects = new b2Body*[objectSize];
	for (int i = 0; i < objectSize; ++i)
	{
		ActorClass * temp = ObjectManager::Instance()->at(i);
		b2Vec2 textureWH = { temp->GetActorWH().x / 2, temp->GetActorWH().y / 2 };
		b2Vec2 position = { temp->GetPosition().x, temp->GetPosition().y };

		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.bullet = false;
		bodyDef.position.Set(position.x, position.y);
		//bodyDef.allowSleep =false;
		m_objects[i] = m_world->CreateBody(&bodyDef);
		m_objects[i]->SetUserData(temp);
		b2PolygonShape polygons;
		polygons.SetAsBox(textureWH.x, textureWH.y);

		b2FixtureDef fd;
		fd.shape = &polygons;
		fd.density = 3.0f;
		fd.friction = 0.3f;
		fd.restitution = 0.4f;
		m_objects[i]->CreateFixture(&fd);
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
	for (int i = 0; i < objectSize; ++i)
	{
		ActorClass * temp = ObjectManager::Instance()->at(i);
		b2Vec2 position = { temp->GetPosition().x, temp->GetPosition().y };
		m_objects[i]->SetTransform(b2Vec2(position.x, position.y), -temp->GetRotate());
		if (!temp->IsPhysics())
		{
			m_objects[i]->SetActive(false);
		}
		else {
			m_objects[i]->SetActive(true);
		}

	}
	settings->velocityIterations = 8;
	settings->positionIterations = 3;

	m_world->SetAllowSleeping(false);
	m_world->SetWarmStarting(settings->enableWarmStarting > 0);
	m_world->SetContinuousPhysics(settings->enableContinuous > 0);
	m_world->SetSubStepping(settings->enableSubStepping > 0);

	m_world->Step(timeStep, settings->velocityIterations, settings->positionIterations);

	//물리 처리 값을 저장.
	for (int i = 0; i < objectSize; ++i)
	{
		b2Vec2 position = m_objects[i]->GetPosition();
		ObjectManager::Instance()->at(i)->SetPosition(position.x, position.y);
		ObjectManager::Instance()->at(i)->SetRotate(-m_objects[i]->GetAngle());
	}
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
