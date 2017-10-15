#ifndef CHARA_HPP
#define CHARA_HPP
#include <memory>
/*
�L�����N�^�[�̊��N���X
���ۃN���X�Ȃ̂ŕK���h���N���X�Ŏg������
*/

enum ChrType { TYPE_NONE, TYPE_SHOT, TYPE_PLAYER, TYPE_ENEMY, TYPE_NUM };


class Chr;
typedef std::shared_ptr<Chr> ChrRef;

class Chr {
	bool remove_flag;
protected:
	int x, y;					//�L�����N�^�̍��W
	int width, height;			//�L�����N�^�̃T�C�Y
	int hit_x, hit_y;			//�L�����N�^�̓����蔻��̉E����W
	int hit_width, hit_height;	//�L�����N�^�̓����蔻��̃T�C�Y
	void remove();				//remove_flag��true��
public:
	Chr();
	void setPosition(int, int);				//���W���w��
	void setHitArea(int, int, int, int);	//�����蔻��𖾎��I�Ɏw��
	bool isRemove();						//remove_flag�̒l��Ԃ�
	virtual ChrType getType() = 0;			//���g�̃L�����N�^�^�C�v��Ԃ�
	virtual ChrType hitType();				//���g�Ɠ����蔻��̂���L�����N�^�^�C�v��Ԃ�
	virtual void move() = 0;				//�L�����N�^�̍��W���ړ�������
	virtual void draw() = 0;				//�L�����N�^�̕`��
	bool isHit(ChrRef&);					//���L�����N�^�Ƃ̂����蔻����s��

};



#endif // !CHARA_HPP
