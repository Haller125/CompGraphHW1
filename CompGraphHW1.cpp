#include <GL/freeglut.h>
#include <vector>

struct Square {
	float scale;
	Square() : scale(1.0f) {}
};

float a = 0.01;
double width = 5;
double x1 = 0.3;

float elapsedTime = 0.0f;
std::vector<Square> squares;

void createsquare() {


	glBegin(GL_LINES);

	glColor3ub(255, 255, 255);

	glVertex2f(x1, x1);
	glVertex2f(x1, -x1);

	glColor3ub(255, 255, 255);

	glVertex2f(x1, -x1);
	glVertex2f(-x1, -x1);

	glColor3ub(255, 255, 255);

	glVertex2f(-x1, -x1);
	glVertex2f(-x1, x1);

	glColor3ub(255, 255, 255);

	glVertex2f(-x1, x1);
	glVertex2f(x1, x1);

	glEnd();
}


void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto& square : squares) {
		glPushMatrix();
		glScalef(square.scale, square.scale, 1.0f);

		createsquare();

		glPopMatrix();
	}

	glutSwapBuffers();
}


void myidle()
{
	float delta = 0.0003f;
	elapsedTime += delta;

	//glTranslatef(-0.001, -0.001, 0);
	//glPushMatrix();
	//glScalef(1 + a * 0.01, 1 + a * 0.01, 0);
	//glRotatef(a, 0, 0, 1);
	
	for (auto& square : squares) {
		square.scale += delta;
	}

	if (elapsedTime > 0.5f) {
		squares.push_back(Square());
		elapsedTime = 0.0f;
		//createsquare();
	}

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(512, 512);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("title");

	glClearColor(0, 0, 0, 1);

	squares.push_back(Square());

	glutDisplayFunc(mydisplay);
	glutIdleFunc(myidle);

	glutMainLoop();
	return 0;
}