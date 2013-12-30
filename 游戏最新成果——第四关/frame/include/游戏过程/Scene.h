#ifndef SCENE_H
#define SCENE_H

#include "..\\��Դ����\\ResourceManager.h"
#include "..\\�˻�\\Account.h"

#include "Dimensionality.h"
#include "..\\ά��ת��\\BackGround1.h"
#include "..\\ά��ת��\\BackGround3.h"
#include "..\\ά��ת��\\BackGround4.h"

enum SceneState{NORMAL, TRANSFORM, PASS};

bool FrameFunc_scene();
bool RenderFunc_scene();

class Scene
{	
public :
	static Scene* getScene(unsigned int = 0);							//����ģʽ���õ���������

	inline Dimensionality* getDimenNow() const { return DimenNow; };    //ȡ�õ�ǰά��

	inline SceneState getState() const { return state; };				//ȡ�ó�����״̬

	inline void setState( SceneState _state ) { state = _state; };		//���ó�����״̬

	void TransformJudge( Player* );										//�ж��������

	BackGround* background;												//ά��ת��������

	hgeFont* getFont();

	int getDimenNOWID();												//ȡ�õ�ǰά�ȵı��

private :
	static Scene* instance;
	Scene(unsigned int = 0);                                      //���캯������ʼ��������ά�ȡ�����
	void initialize();                                                  //����ĳ�ʼ������

	static unsigned int scene_id;										//������¼�ó�����ת����ʽ

	int DimenQuantity;													//ά�ȵ�����
	Dimensionality* dimens[10];											//���ά��ָ�������
	Dimensionality* DimenNow;											//��ŵ�ǰ��ά��

	MapCal* aMapCal;													//������Ӧ�������ͼ��
	
	SceneState state;													//������״̬

	hgeFont* fnt;
};

#endif