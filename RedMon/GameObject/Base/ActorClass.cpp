#include "ActorClass.h"
#include"ObjectManager.h"

/////////////////////////////////
// ActorClass
/////////////////////////////////

ActorClass::ActorClass()
{
	position.x = position.y = position.z = rotate = 0;

	Width = Hight = 0;

	collision.isCollision = false;
	collision.other = nullptr;
	collision.isPhysics = false;
	collision.mode = CollisionMode::None;
	collision.type = BodyType::DynamicBody;
	collision.bullet = false;
	collision.density = 0.7;
	collision.friction = 1.0;
	collision.restitution = 0.0;
	collision.gravityScale = 0.0;
	collision.isRotateFrozen = false;

	textureAddress = tag = "";
	textureTranslate = { 0,0 };
	textureUV = { 0,0,1,1 };
	ObjectManager::Instance()->PushObject(this);
}

ActorClass::~ActorClass()
{
}
XMFLOAT3 ActorClass::GetPosition() const
{
	return position;
}
float ActorClass::GetRotate() const
{
	return rotate;
}
void ActorClass::SetRotate(float rot)
{
	rotate = rot;
}
char* ActorClass::GetTextureAddress() const
{
	return textureAddress;
}

XMFLOAT2 ActorClass::GetActorWH() const
{
	return XMFLOAT2(Width, Hight);
}

char * ActorClass::GetTag() const
{
	return tag;
}

bool ActorClass::IsCollistion() const
{
	return collision.isCollision;
}

ActorClass * ActorClass::GetCollisionOther() const
{
	return collision.other;
}

CollisionMode ActorClass::GetCollisionMode() const
{
	return collision.mode;
}

CollisionData ActorClass::GetCollisionData() const
{
	return collision;
}

bool ActorClass::IsPhysics() const
{
	return collision.isPhysics;
}

void ActorClass::SetPhysics(bool active)
{
	collision.isPhysics = active;
}

void ActorClass::SetCollistionType(BodyType type)
{
	collision.type = type;
}

void ActorClass::SetDensity(float d)
{
	collision.density = d;
}

void ActorClass::SetFriction(float f)
{
	collision.friction = f;
}

void ActorClass::SetRestitution(float r)
{
	collision.restitution = r;
}

void ActorClass::SetGravityScale(float s)
{
	collision.gravityScale = s;
}

void ActorClass::SetRotateFrozen(bool isFrozen)
{
	collision.isRotateFrozen = true;
}

void ActorClass::SetBullet(bool isBullet)
{
	collision.bullet = isBullet;
}

void ActorClass::Initialize()
{
}

void ActorClass::Update(float dt)
{
}

void ActorClass::OnCollisionEnter(ActorClass * other)
{
}


void ActorClass::OnCollisionExit(ActorClass * other)
{
}

void ActorClass::OnDestory()
{
}

void ActorClass::Move(float x, float y)
{
	position.x += x;
	position.y += y;
}

void ActorClass::LocalMove(float x, float y)
{
	position.x += (x * cos(rotate) - y * sin(rotate));
	position.y += (x * sin(rotate) + y * cos(rotate));
}

void ActorClass::Rotate(float angle)
{
	rotate += angle;
}

void ActorClass::TextureTranslate(float x, float y)
{
	textureTranslate.x += x;
	textureTranslate.y += y;
}

void ActorClass::SetTextureUV(float u, float v, float w, float h)
{

	textureUV.x = u / imgOriginalSize.x;
	textureUV.y = v / imgOriginalSize.y;
	textureUV.z = w / imgOriginalSize.x;
	textureUV.w = h / imgOriginalSize.y;

}

XMFLOAT2 ActorClass::GetTextureTranlsate() const
{
	return textureTranslate;
}

XMFLOAT4 ActorClass::GetTextureUV() const
{
	return textureUV;
}

void ActorClass::SetOriginalImgSize(XMFLOAT2 original)
{
	imgOriginalSize = original;
}

void ActorClass::SetPosition(const float & x, const float & y)
{
	position.x = x;
	position.y = y;
}

void ActorClass::SetCollistion(bool isCollistion, ActorClass * other, CollisionMode mode)
{
	collision.isCollision = isCollistion;
	collision.other = other;
	collision.mode = mode;
}

XMFLOAT3 operator+(const XMFLOAT3 & vec1, const XMFLOAT3 & vec2)
{
	return XMFLOAT3(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
}

XMFLOAT3 operator-(const XMFLOAT3 & vec1, const XMFLOAT3 & vec2)
{
	return XMFLOAT3(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
}

XMFLOAT3 operator*(const XMFLOAT3 & vec1, const float & scalar)
{
	return XMFLOAT3(vec1.x*scalar, vec1.y*scalar, vec1.z*scalar);
}

XMFLOAT3 operator/(const XMFLOAT3 & vec1, const float & scalar)
{
	return XMFLOAT3(vec1.x / scalar, vec1.y / scalar, vec1.z / scalar);
}

XMFLOAT3 operator+=(XMFLOAT3 & vec1, const XMFLOAT3 & vec2)
{
	vec1 = vec1 + vec2;
	return vec1;
}

XMFLOAT3 operator-=(XMFLOAT3 & vec1, const XMFLOAT3 & vec2)
{
	vec1 = vec1 - vec2;
	return vec1;
}
