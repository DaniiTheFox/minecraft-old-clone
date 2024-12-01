void display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	GLuint mc_tex;
 	glGenTextures(1,&mc_tex);
	glBindTexture(GL_TEXTURE_2D,mc_tex);
	createTexture(Mc_Textures.bytes_per_pixel,Mc_Textures.width,Mc_Textures.height,Mc_Textures.pixel_data);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	mcFog(4,9,10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	std::cout << "set cam"<<std::endl;
	steve.setCamera();
	std::cout << "set grav"<<std::endl;
	steve.setGravity(world);
	std::cout << "getpos"<<std::endl;
	rx = steve.getPosition(1);
	ry = steve.getPosition(2);
	rz = steve.getPosition(3);
	dir = steve.getRotation(1);
	std::cout << "render wrl"<<std::endl;
	mcDebug(world,rx-8,ry-8,rz-8);
	std::cout << "render gui"<<std::endl;
	steve.drawGui();

	glFlush();
	glutSwapBuffers();
}
