#include<iostream>
#include<math.h>
#include<time.h>
#include"../include/common/Parameters.h"
#include"../include/geometry/SDFObject.h"
#include"../include/common/File.h"
#include"../include/scene/Scene.h"
#include"../include/render/Render2D.h"
#include"../include/visual/UI2D.h"
#include"../include/simulation/Simulator.h"
using namespace std;

int main()
{
	//��������
	ParametersInput();

	Scene sc;

	//������
	SDFJet a(0,WATER, BOUNDSDF_P, Vector2d(-2, 0), 0.1);
	a.Insert(4.7, 1.75);
	a.Insert(4.8, 1.75);
	a.Insert(4.8, 1.90);
	a.Insert(4.7, 1.90);
	sc.AddObject(&a);

	//���ʪɳ��
	SDFSampleBound b(0, WETSAND, BOUNDSDF_P);
	b.Insert(2.25, 0.70);
	b.Insert(3.05, 0.70);
	b.Insert(3.05, 1.70);
	b.Insert(2.25, 1.70);
	sc.AddObject(&b);

	//��������߽�
	SDFBoundary c(0, Boundary);
	c.Insert(0.2, 0.2);
	c.Insert(0.2, 2.4);
	c.Insert(4.8, 2.4);
	c.Insert(4.8, 0.2);
	sc.AddObject(&c);

	//�������߽�
	SDFBoundary d(0, Object);
	d.Insert(4.3, 0.25);
	d.Insert(4.3, 1.5);
	d.Insert(4.1, 1.5);
	d.Insert(4.1, 0.65);
	d.Insert(2.2, 0.65);
	d.Insert(1.8, 0.25);
	sc.AddObject(&d);

	//ģ������ʼ��
	Simulator sim;
	sim.SimulatorInitial(&sc, MPMMulti, EXPLICIT);
	
	int i = 0;
	//��Ⱦ����ʼ��
	Render2D render(WINDOW_HEIGHT, WINDOW_WIDTH);
	
	//�ļ���������ļ���
	File file;
	file.CreateFolder();
	
	while (1)
	{
		sim.SimulatorUpdate();
		render.CanvasDraw(&sc);
		file.CanvasOutput(i,&render.canvas);
		render.CanvasClear();
		i++;
		cout << i << endl;
	}
	
}