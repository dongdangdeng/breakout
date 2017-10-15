#ifndef CHARA_HPP
#define CHARA_HPP
#include <memory>
/*
キャラクターの基底クラス
抽象クラスなので必ず派生クラスで使うこと
*/

enum ChrType { TYPE_NONE, TYPE_SHOT, TYPE_PLAYER, TYPE_ENEMY, TYPE_NUM };


class Chr;
typedef std::shared_ptr<Chr> ChrRef;

class Chr {
	bool remove_flag;
protected:
	int x, y;					//キャラクタの座標
	int width, height;			//キャラクタのサイズ
	int hit_x, hit_y;			//キャラクタの当たり判定の右上座標
	int hit_width, hit_height;	//キャラクタの当たり判定のサイズ
	void remove();				//remove_flagをtrueに
public:
	Chr();
	void setPosition(int, int);				//座標を指定
	void setHitArea(int, int, int, int);	//当たり判定を明示的に指定
	bool isRemove();						//remove_flagの値を返す
	virtual ChrType getType() = 0;			//自身のキャラクタタイプを返す
	virtual ChrType hitType();				//自身と当たり判定のあるキャラクタタイプを返す
	virtual void move() = 0;				//キャラクタの座標を移動させる
	virtual void draw() = 0;				//キャラクタの描画
	bool isHit(ChrRef&);					//他キャラクタとのあたり判定を行う

};



#endif // !CHARA_HPP
