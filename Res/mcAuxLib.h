void mcCreateWindow(int wdth, int hght, int pos,char *name){
	glutInitWindowSize(wdth,hght);
	glutInitWindowPosition(pos,pos);
	glutCreateWindow(name);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0);
}

void stand(){
	usleep(33);
	glutPostRedisplay();
}

void mcFog(float strt , float end ,float dens){
	GLuint filter;
	GLfloat FogColor[4] = {0.8,0.8,1.0,1.0};
	glClearColor(0.8,0.8,1.0,0);
	glFogi(GL_FOG_MODE , GL_LINEAR);
	glFogfv(GL_FOG_COLOR , FogColor);
	glFogf(GL_FOG_DENSITY , dens );
	glHint(GL_FOG_HINT , GL_DONT_CARE);
	glFogf(GL_FOG_START , strt );
	glFogf(GL_FOG_END , end);
	glEnable(GL_FOG);
}

void keybd(unsigned char key, int x, int y){
	switch(key){
		case 'f':exit(1);break;
		case 'a':dir = dir-15;steve.setRotation(dir);break;
		case 'd':dir = dir+15;steve.setRotation(dir);break;
		case 'w':steve.moveForward();steve.coliderSpw(world);break;
		case ' ':steve.setPosition(rx,ry+2,rz);break;
		case 'e':steve.setViewSpot('u');break;
		case 'q':steve.setViewSpot('d');break;
		case 'x':steve.rayCast(world,4,'b',cb);break;
		case 'z':steve.rayCast(world,4,'p',cb);break;
		case 'i':steve.damage(world);break;
		case 'k':steve.regen();break;
		case '1':cb = 1;break;case '2':cb = 2;break;case '3':cb = 3;break;case '4':cb = 4;break;case '5':cb = 5;break;case '6':cb = 6;break;
		default:std::cout<<"rot: "<<dir<<" X:"<<rx<<"Z: "<<rz<<std::endl;break;
	}
}

void glInitialize(){
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glClearColor(0.7,0.7,1.0,0.0);
    glAlphaFunc(GL_GREATER, 0.5);
 	glEnable(GL_ALPHA_TEST);
 	glLoadIdentity();                                                // load all objects in scene
 	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 
	glLoadIdentity();
//	gluPerspective(60,0.5,1,250);
	gluPerspective(60, 1, 0.1, 3000);
}
/*
int createTexture(int bpp,int width,int height,const void *data){
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );
	gluBuild2DMipmaps( GL_TEXTURE_2D, bpp, width ,height,GL_RGBA, GL_UNSIGNED_BYTE,data );
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}*/

GLuint createTexture(int bpp, int w, int h, const void *data){
 GLuint tmp_txt;
 glGenTextures(1, &tmp_txt);                                                  // CREATION OF A NEW TEXTURE
 glBindTexture(GL_TEXTURE_2D, tmp_txt);
 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);                 // generate the default texture once again
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
 glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
 gluBuild2DMipmaps(GL_TEXTURE_2D, bpp, w, h, GL_RGBA, GL_UNSIGNED_BYTE, data);
 glEnable(GL_BLEND);
 return tmp_txt;
}

int gcd (int a, int b) {
    return (b == 0) ? a : gcd (b, a%b);
}

void resz(int xs, int ys){ // FUNCION DE REESCALAMIENTO
    const float ar = (float) xs / (float) ys; // TAMAÑO DEL PIXEL ( ASPECT RATIO )
    int BON_SCREEN_W = xs; // DEFINIR EL TAMAÑO NUEVO DE LA PANTALLA
    int BON_SCREEN_H = ys; // DEFINIR EL TAMAÑO NUEVO DE LA PANTALLA
    glViewport(0, 0, xs, ys); // GENERAR UN VIEWPORT DE DIBUJO
    glMatrixMode(GL_PROJECTION); // CAMBIAR EL MODO A PROYECCION
    glLoadIdentity(); // CARGAR LOS OBJETOS
    gluPerspective(60, gcd(xs,ys), 0.1, 3000);
    //gluPerspective(60,1,0.1,3000);
    glMatrixMode(GL_MODELVIEW); // CAMBIAR EL MODO OTRA VEZ A MEMORIA
    glLoadIdentity() ; // MOSTRAR LOS OBJETOS
//    current_block = 3;
//    block_selecting = 0;
//    pointer_inv = 1;
//    pointer_blk = 1;
}