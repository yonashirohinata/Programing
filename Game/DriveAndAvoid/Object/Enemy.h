#pragma once

#include "../Utility/Vector2D.h"
#include "../Object/Player.h"

class Enemy
{
private:
	int type;				//タイプ
	int image;				//画像
	float speed;			//速さ
	Vector2D location;		//位置情報
	Vector2D box_size;		//当たり判定の大きさ
	Vector2D No_box_size;		//当たり判定の大きさ
	int cursor;				//カーソルの選択
	int time;				//待機時間
public:
	Enemy(int type, int handle);
	~Enemy();

	void Initialize();				//初期化処理
	void Update(float speed);		//更新処理
	void Draw() const;				//描画処理
	void Finalize();				//終了時処理

	int GetType() const;				//タイプの取得
	Vector2D GetLocation() const;		//位置情報の取得
	Vector2D GetBoxSize() const;		//当たり判定の大きさを取得
	Vector2D GetBoxSize2() const;		//当たり判定の大きさを取得

private:
	void Movement();			//移動処理
	void WeakTarget();				//ターゲット場所指定（小）
	void StrongTarget();				//ターゲット場所指定（大）

};
