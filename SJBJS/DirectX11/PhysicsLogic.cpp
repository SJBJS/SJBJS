#include "PhysicsLogic.h"

PhysicsLogic::PhysicsLogic()
{
	TileWidth = 32;
	TileMaxX = 10;
	TileMaxY = 10;

}


PhysicsLogic::~PhysicsLogic()
{
}
bool PhysicsLogic::IsCollision()
{

}
boolean PhysicsLogic::overlapPT(Player r1, Tile r2)
{   //첫 번째 조건절에서는 첫 번째 사각형의 왼쪽 모서리가 두 번째 사각형의 오른쪽 모서리보다 항상 
	//왼쪽에 있어야 한다고 지정한다. 두 번째 조건문에서는 첫 번째 사각형의 오른쪽 모서리가 두 번째 사각형의 왼쪽 모서리보다 오른쪽에 있어야 한다
	if (GetElement(r2) &&
		r1.Prect.left < r2.Trect.left + r2.width &&
		r1.Prect.left + r1.width > r2.Trect.left &&
		r1.Prect.top  < r2.Trect.top + r2.height &&
		r1.Prect.top + r1.height > r2.Trect.top)
		return true;
	else
		false;
}
boolean PhysicsLogic::overlapPE(Player r1, Enermy r2)
{
	if (r1.Prect.left  < r2.Erect.left + r2.width &&
		r1.Prect.left + r1.width > r2.Erect.left &&
		r1.Prect.top  < r2.Erect.top + r2.height &&
		r1.Prect.top + r1.height > r2.Erect.top)
		return true;
	else
		false;
}
boolean PhysicsLogic::overlapET(Enermy r1, Tile r2)
{
	
	if (GetElement(r2) &&
		r1.Erect.left < r2.Trect.left + r2.width &&
		r1.Erect.left + r1.width > r2.Trect.left &&
		r1.Erect.top < r2.Trect.top + r2.height &&
		r1.Erect.top + r1.height > r2.Trect.top)
		return true;
	else
		false;
}
boolean PhysicsLogic::SetElement(Tile r1) {


}
bool PhysicsLogic::GetElement(Tile r1)
{
	if (r1.coll) {
		return true;
	}
	else 
		return false;
}
void PhysicsLogic::initTileSet() {
	
	Tile tile[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			tile[i][j].Tndex = 0;
			tile[i][j].coll = false;
			tile[i][j].width = TileWidth;
		}
	}
	// 임시 충돌 타일 인덱스 설정
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j % 3 == 0) { //조건에 맞는 타일에 충돌 true 설정
				tile[i][j].coll = true;
			}
		}
	}
}
