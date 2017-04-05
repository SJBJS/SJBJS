#include "PhysicsLogic.h"

PhysicsLogic::PhysicsLogic()
{
}


PhysicsLogic::~PhysicsLogic()
{
}
//bool PhysicsLogic::IsCollision()
//{
//}
boolean PhysicsLogic::overlapPT(Player r1, Tile r2)
{
	if (GetElement() &&
		r1.leftLine < r2.leftLine + r2.width &&
		r1.leftLine + r1.width > r2.leftLine &&
		r1.leftLine < r2.leftLine + r2.height &&
		r1.leftLine + r1.height > r2.leftLine)
		return true;
	else
		false;
}
boolean PhysicsLogic::overlapPE(Player r1, Enermy r2)
{
	if (GetElement() &&
		r1.leftLine < r2.leftLine + r2.width &&
		r1.leftLine + r1.width > r2.leftLine &&
		r1.leftLine < r2.leftLine + r2.height &&
		r1.leftLine + r1.height > r2.leftLine)
		return true;
	else
		false;
}
boolean PhysicsLogic::overlapET(Enermy r1, Tile r2)
{
	if (GetElement() &&
		r1.leftLine < r2.leftLine + r2.width &&
		r1.leftLine + r1.width > r2.leftLine &&
		r1.leftLine < r2.leftLine + r2.height &&
		r1.leftLine + r1.height > r2.leftLine)
		return true;
	else
		false;
}
bool PhysicsLogic::GetElement()
{
	return true;
}