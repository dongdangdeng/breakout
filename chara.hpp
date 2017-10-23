#ifndef CHARA_HPP
#define CHARA_HPP
#include <memory>
/*
キャラクターの基底クラス
抽象クラスなので必ず派生クラスで使うこと
*/

enum ChrType { TYPE_NONE, TYPE_SHOT, TYPE_PLAYER, TYPE_BLOCK, TYPE_NUM };

class Chr;
typedef std::shared_ptr<Chr> ChrRef;

class Chr {
	bool remove_flag;
protected:
	double x, y;				//キャラクタの座標
	int width, height;			//キャラクタのサイズ
	int hit_x, hit_y;			//キャラクタの当たり判定の右上座標
	int hit_width, hit_height;	//キャラクタの当たり判定のサイズ
	unsigned int color;			//キャラの色(画像を使わず円や矩形で描画する場合に指定)
	void remove();				//remove_flagをtrueに
public:
	Chr();
	void setPosition(int, int);				//座標を指定
	void setSize(int, int);					//サイズを指定・暗黙的に当たり判定も指定(キャラクタの表示に画像を使う場合、setImage関数内で自動取得するためこの関数で指定する必要はない)
		//TODO setImage関数の実装
	//void SetImage(char*);					
	void setHitArea(int, int, int, int);	//当たり判定を明示的に指定
	void setColor(unsigned int);			//<DxLib.h>のGetColorで引数を渡すことを推奨
	bool isRemove();						//remove_flagの値を返す
	virtual ChrType getType() = 0;			//自身のキャラクタタイプを返す
	virtual ChrType hitType();				//自身と当たり判定のあるキャラクタタイプを返す
	virtual void move() = 0;				//キャラクタの座標を移動させる
	virtual void draw() = 0;				//キャラクタの描画
	bool isHit(ChrRef&);					//他キャラクタとのあたり判定を行う

};

#endif // !CHARA_HPP
