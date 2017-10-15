#ifndef __POLYCALLBACK_H_
#define __POLYCALLBACK_H_

#include<Box2D\Box2D.h>
#include"RedMon\GameObject\Base\ObjectManager.h"

struct ContactPoint
{
	b2Fixture* fixtureA;
	b2Fixture* fixtureB;
	b2Vec2 normal;
	b2Vec2 position;
	b2PointState state;
	float32 normalImpulse;
	float32 tangentImpulse;
	float32 separation;
};
class Listener : public b2ContactListener
{
public:
	Listener(){	}
	virtual ~Listener() {}
	virtual void BeginContact(b2Contact* contact) {
		ActorClass * A = static_cast<ActorClass*>(contact->GetFixtureA()->GetBody()->GetUserData());
		ActorClass * B = static_cast<ActorClass*>(contact->GetFixtureB()->GetBody()->GetUserData());
		if (A != nullptr && B != nullptr) {
			A->SetCollistion(true, B , CollisionMode::Enter);
			B->SetCollistion(true, A, CollisionMode::Enter);
		}
	}

	/// Called when two fixtures cease to touch.
	virtual void EndContact(b2Contact* contact) {
		ActorClass * A = static_cast<ActorClass*>(contact->GetFixtureA()->GetBody()->GetUserData());
		ActorClass * B = static_cast<ActorClass*>(contact->GetFixtureB()->GetBody()->GetUserData());

		if (A != nullptr && B != nullptr) {
			A->SetCollistion(true, B, CollisionMode::Exit);
			B->SetCollistion(true, A, CollisionMode::Exit);
		}
	}
	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
	{
		B2_NOT_USED(contact);
		B2_NOT_USED(oldManifold);
	}
	virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
	{
		B2_NOT_USED(contact);
		B2_NOT_USED(impulse);
	}
private:
};
class PolyShapesCallback : public b2QueryCallback
{
public:

	enum
	{
		e_maxCount = 4
	};

	PolyShapesCallback()
	{
		m_count = 0;
	}
	/// Called for each fixture found in the query AABB.
	/// @return false to terminate the query.
	bool ReportFixture(b2Fixture* fixture)
	{
		if (m_count == e_maxCount)
		{
			return false;
		}

		b2Body* body = fixture->GetBody();
		b2Shape* shape = fixture->GetShape();

		bool overlap = b2TestOverlap(shape, 0, &m_circle, 0, body->GetTransform(), m_transform);

		if (overlap)
		{
			++m_count;
		}

		return true;
	}

	b2CircleShape m_circle;
	b2Transform m_transform;
	int32 m_count;
};

#endif