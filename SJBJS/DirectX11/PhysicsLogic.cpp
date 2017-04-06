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
{   //ù ��° ������������ ù ��° �簢���� ���� �𼭸��� �� ��° �簢���� ������ �𼭸����� �׻� 
	//���ʿ� �־�� �Ѵٰ� �����Ѵ�. �� ��° ���ǹ������� ù ��° �簢���� ������ �𼭸��� �� ��° �簢���� ���� �𼭸����� �����ʿ� �־�� �Ѵ�
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
	// �ӽ� �浹 Ÿ�� �ε��� ����
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j % 3 == 0) { //���ǿ� �´� Ÿ�Ͽ� �浹 true ����
				tile[i][j].coll = true;
			}
		}
	}
}
