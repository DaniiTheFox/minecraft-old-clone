#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<cstdio>
#include<time.h>
#include<math.h>
//#include<windows.h>
#include"Res/GlobalVariables.h"
#include"Res/Models/tiles.c"
#include"Res/Models/Player.h"
#include"Res/Models/Arm.h"
#include"Res/Player.c"
#include"Res/Textures/textures.c"
Player steve(50,0,50);
int rx = 0,ry = 0,rz = 0,dir = 0,cb = 1;
#include"Res/mcAuxLib.h"
#include"Res/Models/ModelCube.h"
#include"Res/mcDisplay.h"
int sid = 10;
int main(int argc , char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	std::cout<<"type your seed(blank for default): "<<std::endl;std::cin>>sid;
	std::cout<<"genmap start"<<std::endl;
	mcGenMap(world,prefabs,sid);
	std::cout<<"genmap end"<<std::endl;
	steve.coliderSpw(world);
	ry = steve.getPosition(2);
	std::cout<<"prefab"<<std::endl;
	PrefabCopy(prefabs,world,47,ry-2,47,1);
	mcCreateWindow(640,480,64,"Minecraft C++ edition Infdev 0.13");
	glInitialize();
	std::cout<<"rendering..."<<std::endl;
//	glutIgnoreKeyRepeat(1);
	glutDisplayFunc(display);
	glutKeyboardFunc(keybd);
	glutIdleFunc(stand);
	glutReshapeFunc(resz);
	glutMainLoop();
//	system("pause");
	return 0;
}

