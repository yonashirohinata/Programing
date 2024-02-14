#include "Enemy.h"
#include "DxLib.h"
#include "../Utility/InputControl.h"

Enemy::Enemy(int type, int handle) : type(type), image(handle), speed(0.0f), location(0.0f), box_size(0.0f), No_box_size(0.0f),time(true)
{

}

Enemy::~Enemy()
{

}

//初期化処理
void Enemy::Initialize()
{
	//出現させるX座標パターンを取得
	float random_x = (float)(GetRand(4) * 105 + 40);
	//生成位置の設定
	location = Vector2D(250.0f,60.0f);
	//当たり判定の設定
	box_size = Vector2D(31.0f, 60.0f);
	//当たらない判定の場所設定
	No_box_size = Vector2D(31.0f, 60.0f);
	//速さの設定
	speed = (float)(this->type * 3);
	time = 0; //待機時間
	flg = false;
	attackflg = true;
	lane1 = 0;
	//画像の読み込み
	image = LoadGraph("Resource/images/target.png");
	
	damage = LoadGraph("Resource/images/dama.png");
	//注意時の画像
	Note = LoadGraph("Resource/images/Note.png");
	//アウトゾーンにいるときの画像
	Dangerous = LoadGraph("Resource/images/Dangerous.png");
	
}

void Enemy::Update(float speed)
{
	//移動処理
	Movement();
	//ターゲット場所指定(小)
	WeakTarget();
	//ターゲット場所指定(大)
	StrongTarget();
	//ダメージが入るまでのタイマー
	Timer();
	if (flg == true) {
		time++;
	}
	
	if (time > 200) {
		time = 0;
		flg = false;
		
	}
	//ダメージ範囲内にいるか
	if (time > 50 && attackflg == false) {
		box_size = Vector2D(31.0f, 300.0f);
	}
	if (time > 100 && attackflg == false) {
		box_size = Vector2D(31.0f, 60.0f);
		attackflg = true;
	}
	//位置情報に移動量を加算する
	location += Vector2D(0.0f, 0.0f);
	////位置情報に移動量を加算する
	//box_size += Vector2D(0.0f, 0.0f);
}

void Enemy::Draw() const
{
	//敵画像の描画
	DrawRotaGraphF(location.x, location.y, 1.5, 0.0, image, TRUE);
	if (time > 1 && time < 50 && attackflg == false) {
		DrawRotaGraphF(location.x, location.y, 1.0, 0.0, Note, TRUE);
	}
	if (time > 50 && attackflg == false) {
		DrawRotaGraphF(location.x, location.y, 0.5, 0.0, Dangerous, TRUE);
		DrawRotaGraphF(location.x, location.y + 200, 1.0, 0.0, damage, TRUE);
	}
	
	/*else if (time > 250) {
		DrawRotaGraphF(location.x, location.y + 200, 1.0, 0.0, bakuhatsu, TRUE);
	}*/
}

void Enemy::Finalize()
{

}

//敵のタイプを取得
int Enemy::GetType() const
{
	return type;
}

//位置情報を取得
Vector2D Enemy::GetLocation() const
{
	return location;
}

//当たり判定の大きさを取得
Vector2D Enemy::GetBoxSize() const
{
	return box_size;
}



void Enemy::Timer() {
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A)) {
		flg = true;
	}
}

//移動処理
void Enemy::Movement()
{
	Vector2D move = Vector2D(0.0f);
	cursor = 3;
	

	//十字移動処理
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_LEFT) && attackflg == true)
	{
			move += Vector2D(-100.0f, 0.0f);
			cursor--;
	}
	
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_RIGHT) && attackflg == true)
	{
		cursor++;
		move += Vector2D(100.0f, 0.0f);
	}

	location += move;

	//画面外に行かないように制限する
	if ((location.x < box_size.x) || (location.x >= 640.0f - 180.0f) || (location.y < box_size.y) || (location.y >= 480.0f - box_size.y))
	{
		location -= move;
	}
		
}
	
//ボタンを押したときの範囲攻撃（小）
void Enemy::WeakTarget()
{
	
	//場所指定（１レーン）
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A) && location.x == 50.0f)
	{
		attackflg = false;
	}
	//場所指定（２レーン）
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A) && location.x == 150.0f)
	{
		attackflg = false;
	}
	//場所指定（３レーン）
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A) && location.x == 250.0f)
	{
		attackflg = false;
	}
	//場所指定（４レーン）
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A) && location.x == 350.0f)
	{
		attackflg = false;
	}
	//場所指定（５レーン）
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A) && location.x == 450.0f)
	{
		attackflg = false;
	}
	
}

//ボタンを押したときの範囲攻撃（大）
void Enemy::StrongTarget()
{
	////場所指定（１レーン）
	//if (InputControl::GetButtonDown(XINPUT_BUTTON_X) && location.x != 50.0f)
	//{
	//	box_size = Vector2D(250.0f, 300.0f);
	//}
	//
	////場所指定（２レーン）
	//if (InputControl::GetButtonDown(XINPUT_BUTTON_X) && location.x != 150.0f)
	//{
	//	box_size = Vector2D(250.0f, 300.0f);
	//}
	////場所指定（３レーン）
	//if (InputControl::GetButtonDown(XINPUT_BUTTON_X) && location.x != 250.0f)
	//{
	//	box_size = Vector2D(250.0f, 300.0f);
	//}
	////場所指定（４レーン）
	//if (InputControl::GetButtonDown(XINPUT_BUTTON_X) && location.x != 350.0f)
	//{
	//	box_size = Vector2D(250.0f, 300.0f);
	//}
	////場所指定（５レーン）
	//if (InputControl::GetButtonDown(XINPUT_BUTTON_X) && location.x != 450.0f)
	//{
	//	box_size = Vector2D(400.0f, 300.0f);
	//}
	//
}


