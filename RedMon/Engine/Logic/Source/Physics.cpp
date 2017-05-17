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

	objectSize = ObjectManager::Instance()->Size();
	m_objects = new b2Body*[objectSize];
	for (int i = 0; i < objectSize; ++i)
	{
		b2Vec2 position = { ObjectManager::Instance()->at(i)->GetPosition().x, ObjectManager::Instance()->at(i)->GetPosition().y };
		b2Vec2 textureWH = { ObjectManager::Instance()->at(i)->GetTextureWH().x, ObjectManager::Instance()->at(i)->GetTextureWH().y };

		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(position.x, position.y);
		m_objects[i] = m_world->CreateBody(&bodyDef);

		b2PolygonShape polygons;
		polygons.SetAsBox(textureWH.x, textureWH.y);

		b2FixtureDef fd;
		fd.shape = &polygons;
		fd.density = 1.0f;
		fd.friction = 0.3f;
		m_objects[i]->CreateFixture(&fd);
	}
	return true;
}

void Physics::Update()
{
	float32 timeStep = settings->hz > 0.0f ? 1.0f / settings->hz : float32(0.0f);

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
		b2Vec2 position = { ObjectManager::Instance()->at(i)->GetPosition().x, ObjectManager::Instance()->at(i)->GetPosition().y };
		m_objects[i]->SetTransform(b2Vec2(position.x, position.y), 0);
	}
	uint32 flags = 0;
	flags += settings->drawShapes			* b2Draw::e_shapeBit;
	flags += settings->drawJoints			* b2Draw::e_jointBit;
	flags += settings->drawAABBs			* b2Draw::e_aabbBit;
	flags += settings->drawCOMs				* b2Draw::e_centerOfMassBit;

	//settings->velocityIterations = 0;
	//settings->positionIterations = 0;

	m_world->Step(timeStep, settings->velocityIterations, settings->positionIterations);

	//물리 처리 값을 저장.
	for (int i = 0; i < objectSize; ++i)
	{
		b2Vec2 position = m_objects[i]->GetPosition();
		ObjectManager::Instance()->at(i)->SetPosition(position.x, position.y);
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
