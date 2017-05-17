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
	gravity.Set(0.0f, 1.0f);
	m_world = new b2World(gravity);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;

	float x = ObjectManager::Instance()->FindObjectWithTag("player")->GetPosition().x;
	float y = ObjectManager::Instance()->FindObjectWithTag("player")->GetPosition().y;
	bodyDef.position.Set(x,y);
	m_object = m_world->CreateBody(&bodyDef);

	float h = ObjectManager::Instance()->FindObjectWithTag("player")->GetTextureWH().y;
	float w = ObjectManager::Instance()->FindObjectWithTag("player")->GetTextureWH().x;
	
	b2PolygonShape polygons;
	polygons.SetAsBox(w, h);

	b2FixtureDef fd;
	fd.shape = &polygons;
	fd.density = 1.0f;
	fd.friction = 0.3f;
	m_object->CreateFixture(&fd);
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
	uint32 flags = 0;
	flags += settings->drawShapes			* b2Draw::e_shapeBit;
	flags += settings->drawJoints			* b2Draw::e_jointBit;
	flags += settings->drawAABBs			* b2Draw::e_aabbBit;
	flags += settings->drawCOMs				* b2Draw::e_centerOfMassBit;

	//settings->velocityIterations = 0;
	//settings->positionIterations = 0;

	m_world->Step(timeStep, settings->velocityIterations, settings->positionIterations);

	float x = ObjectManager::Instance()->FindObjectWithTag("player")->GetPosition().x;
	float y = ObjectManager::Instance()->FindObjectWithTag("player")->GetPosition().y;
	ObjectManager::Instance()->FindObjectWithTag("player")->SetPosition(m_object->GetPosition().x, m_object->GetPosition().y);
	m_object->SetTransform(b2Vec2(x, y), 0);
}

void Physics::Shutdown()
{
	if (m_object)
	{
		m_world->DestroyBody(m_object);
		m_object = NULL;
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
