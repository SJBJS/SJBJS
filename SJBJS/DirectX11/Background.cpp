#include "Background.h"

Background::Background()
{
	
	TileWidth = 32;
	TileMaxX = 10;
	TileMaxY = 10;

}


Background::~Background()
{
}
bool Background::IsCollision()
{
	// 타일속성 체크항목 true false 확인
	return true;

}
boolean Background::overlapPT(PlayerClass r1, Tile r2)
{   //첫 번째 조건절에서는 첫 번째 사각형의 왼쪽 모서리가 두 번째 사각형의 오른쪽 모서리보다 항상 
	//왼쪽에 있어야 한다고 지정한다. 두 번째 조건문에서는 첫 번째 사각형의 오른쪽 모서리가 두 번째 사각형의 왼쪽 모서리보다 오른쪽에 있어야 한다
	/*if (GetElement(r2) &&
		r1.Prect.left < r2.Trect.left + r2.width &&
		r1.Prect.left + r1.width > r2.Trect.left &&
		r1.Prect.top  < r2.Trect.top + r2.height &&
		r1.Prect.top + r1.height > r2.Trect.top)
		return true;
	else
		false;*/
	return true;
}
boolean Background::overlapPE(PlayerClass r1, Enermy r2)
{/*
	if (r1.Prect.left  < r2.Erect.left + r2.width &&
		r1.Prect.left + r1.width > r2.Erect.left &&
		r1.Prect.top  < r2.Erect.top + r2.height &&
		r1.Prect.top + r1.height > r2.Erect.top)
		return true;
	else
		return false;*/
	return true;
}
boolean Background::overlapET(Enermy r1, Tile r2)
{
	
	if (GetElement(r2) &&
		r1.Erect.left < r2.Trect.left + r2.width &&
		r1.Erect.left + r1.width > r2.Trect.left &&
		r1.Erect.top < r2.Trect.top + r2.height &&
		r1.Erect.top + r1.height > r2.Trect.top)
		return true;
	else
		return false;
}
boolean Background::SetElement(Tile r1) {
	if (IsCollision())
		r1.coll = true;
	else
		r1.coll = false;

	return r1.coll;

}
bool Background::GetElement(Tile r1)
{
	if (r1.coll) {
		return true;
	}
	else 
		return false;
}
void Background::initTileSet() {
	
	Tile tile[10][10];
	// 타일 초기화
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
	// 임시 충돌 타일 인덱스 설정
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j % 3 == 0) { //조건에 맞는 타일에 충돌 true 설정
				tile[i][j].coll = true;
			}
		}
	}
}

