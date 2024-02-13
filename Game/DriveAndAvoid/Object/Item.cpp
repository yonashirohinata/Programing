#include "Item.h"
#include "DxLib.h"

Item::Item(int handle) :car_engine(NULL), oil_tank(NULL), tool_box(NULL), location(0.0f)
{

}

Item::~Item()
{

}

//初期化処理
void Item::Initialize()
{
	car_engine = LoadGraph("Resource/images/car_engine.png");
	oil_tank = LoadGraph("Resource/images/oil_tank.png");
	tool_box = LoadGraph("Resource/images/tool_box.png");

}