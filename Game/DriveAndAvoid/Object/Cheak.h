#pragma once
#include "../Utility/Vector2D.h"

class Cheak
{
private:
	Vector2D location;		//位置情報
	Vector2D box_size;		//当たり判定の大きさ
	bool flg;
	int time;				//秒数

public:
	Cheak(int type);
	~Cheak();
	void Update(Vector2D vector2D);
	void Draw();
	Vector2D GetLocation() const;		//位置情報の取得
	Vector2D GetBoxSize() const;		//当たり判定の大きさを取得
};

