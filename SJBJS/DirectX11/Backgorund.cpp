#include "Backgorund.h"

Backgorund::Backgorund()
{
	
	TileWidth = 32;
	TileMaxX = 10;
	TileMaxY = 10;

}


Backgorund::~Backgorund()
{
}
bool Backgorund::IsCollision()
{
	// Ÿ�ϼӼ� üũ�׸� true false Ȯ��

}
boolean Backgorund::overlapPT(PlayerClass r1, Tile r2)
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
boolean Backgorund::overlapPE(PlayerClass r1, Enermy r2)
{
	if (r1.Prect.left  < r2.Erect.left + r2.width &&
		r1.Prect.left + r1.width > r2.Erect.left &&
		r1.Prect.top  < r2.Erect.top + r2.height &&
		r1.Prect.top + r1.height > r2.Erect.top)
		return true;
	else
		false;
}
boolean Backgorund::overlapET(Enermy r1, Tile r2)
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
boolean Backgorund::SetElement(Tile r1) {
	if (IsCollision())
		r1.coll = true;
	else
		r1.coll = false;

}
bool Backgorund::GetElement(Tile r1)
{
	if (r1.coll) {
		return true;
	}
	else 
		return false;
}
void Backgorund::initTileSet() {
	
	Tile tile[10][10];
	// Ÿ�� �ʱ�ȭ
	for (int i = 0; i < 10; i++) {
		tile[0][i].Tndex = 0;
		tile[0][i].coll = false;
		tile[0][i].width = TileWidth;
		tile[0][i].height = TileWidth;
		tile[0][i].Tp.x = 0;
		tile[0][i].Tp.y = 0;
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			tile[i][j].Tndex = 0;
			tile[i][j].coll = false;
			tile[i][j].width = TileWidth;
			tile[i][j].height = TileWidth;
			tile[i][j].Tp.x = tile[i - 1][j].Tp.x + tile[i][j].width;
			tile[i][j].Tp.y = tile[i - 1][j].Tp.y + tile[i][j].height;

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
