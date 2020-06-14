#pragma once
#pragma once
#include"Solver.h"
#include"../grid/GridMPM.h"
#include"../grid/GridMAC.h"


class SolverMAC
	:public Solver
{
public:
	SolverMAC();
	~SolverMAC();
	ParticleCloudMPM* bar;
	GridMAC* grid;
	int Resolution;
	//void Initial(SolverType SType);
	//void Update();
	//void PointListCheck();
	//void SourceCheck();//��һ���ֻ�Ҫ�ع������Դ�������
	void SolverInitial(IntegralType SType, vector<SDFInfo>* SDFlist);
	void SolverUpdate();
	void AddParticle(vector<Vector2d> *particleList, ParticleType particleType, Vector2d particleVelocity, Vector3d particleColor);
private:
	void InformationReturn();
};