// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"

#include <iostream>
#include <time.h>

#include "Vertice.h"
#include "Shader.h"
#include "Modelo.h"
#include "nave.h"
#include "Camion.h"
#include "Tortuga.h"

using namespace std;

GLfloat red, green, blue;

GLuint posicionID;
GLuint colorID;
GLuint modeloID;
GLuint vistaID;
GLuint proyeccionID;

float camaraX = 12.0f;
float camaraY = 30.0f;
float camaraZ = 0.0f;

vec3 posicionCamara;

double tiempoAnterior;

mat4 vista;
mat4 proyeccion;

Camion *camion;
Tortuga *tortuga;

Shader *shader;
//Declaración de ventana
GLFWwindow *window;

//Propiedades de la ventana
GLfloat ancho = 1024;
GLfloat alto = 768;

void actualizar() {
	double tiempoActual = glfwGetTime();
	double tiempoDelta = tiempoActual - tiempoAnterior;

	int estadoderecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoderecha == GLFW_PRESS) {
		camaraX += 0.1f;
		}
	
	int estadoizq = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoizq == GLFW_PRESS) {
		camaraX -= 0.1f;
	}

	int estadoArriba = glfwGetKey(window, GLFW_KEY_UP);
	if (estadoArriba == GLFW_PRESS) {
		camaraY += 0.1f;
	}

	int estadoAbajo = glfwGetKey(window, GLFW_KEY_DOWN);
	if (estadoAbajo == GLFW_PRESS) {
		camaraY -= 0.1f;
	}

	int estadoQ = glfwGetKey(window, GLFW_KEY_Q);
	if (estadoQ == GLFW_PRESS) {
		camaraZ += 0.1f;
	}

	int estadoE = glfwGetKey(window, GLFW_KEY_E);
	if (estadoE == GLFW_PRESS) {
		camaraZ -= 0.1f;
	}

	int estadoJ = glfwGetKey(window, GLFW_KEY_J);
	if (estadoJ == GLFW_PRESS) {
		camion->direccion = 1;
	}
	int estadoL = glfwGetKey(window, GLFW_KEY_L);
	if (estadoL == GLFW_PRESS) {
		camion->direccion = 0;
	}
	int estadoI = glfwGetKey(window, GLFW_KEY_I);
	if (estadoI == GLFW_PRESS) {
		camion->direccion = 2;
	}
	int estadoK = glfwGetKey(window, GLFW_KEY_K);
	if (estadoK == GLFW_PRESS) {
		camion->direccion = 3;
	}

	camion->mover(tiempoDelta);

	posicionCamara = vec3(camaraX, camaraY, camaraZ);

	vista = lookAt(posicionCamara, //Posicion de la camara
		vec3(0.0f, 0.0f, 0.0f),		//Posicion del objetivo
		vec3(0.0f, 1.0f, 0.0f));

	camion->vista = vista;
	tortuga->vista = vista;

	tiempoAnterior = tiempoActual;
};

void dibujar() {
	camion->dibujar(GL_TRIANGLES);
	tortuga->dibujar(GL_TRIANGLES);
}

void inicializarTortuga() {
	tortuga = new Tortuga();
	tortuga->vista = vista;
	tortuga->proyeccion = proyeccion;
}

void inicializarCamion() {
	camion = new Camion();
	camion->vista = vista;
	camion->proyeccion = proyeccion;
}

void inicializarvista() {
	vista = lookAt(posicionCamara, //Posicion de la camara
		vec3(0.0f, 0.0f, 0.0f),		//Posicion del objetivo
		vec3(0.0f, 1.0f, 0.0f));	//Vector hacia arriba (rotacion camara)
}

void inicializarproyeccion() {
	proyeccion = perspective(45.0f, //Campo de vision (FoV)
		ancho / alto,				//Realcion de aspecto (Apect ratio) 
		0.1f,						//Near clipping (Desde donde renderea)
		150.0f);					//Far clipping (Hasta donde renderea)
}

int main()
{
	//Inicialización de GLFW
	if (!glfwInit()) {
		//Si no se inició bien, terminar la ejecución
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana
	window = glfwCreateWindow(ancho, alto, "Graficos", NULL, NULL);
	//Verficar si se creó bien la ventana
	if (!window) {
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Termina ejecución
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno
	glewExperimental = true;
	//Inicializar GLEW
	GLenum glewError = glewInit();
	//Verificar que GLEW se inicializó bien
	if (glewError != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL: " << version << endl;

	red = green = blue = 0.5f;

	posicionCamara = vec3(camaraX, camaraY, camaraZ);

	inicializarvista();
	inicializarproyeccion();

	inicializarTortuga();
	inicializarCamion();

	//crear instancia del shader
	const char * rutaVertex = "vShaderSimple.shader";
	const char * rutaFragment = "fShaderSimple.shader";

	shader = new  Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos 
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");
	modeloID = glGetUniformLocation (shader->getID(), "modelo");
	vistaID = glGetUniformLocation(shader->getID(), "vista");
	proyeccionID = glGetUniformLocation(shader->getID(), "proyeccion");

	//Desenlazar el shader
	shader->desenlazarShader();

	camion->shader = shader;
	camion->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	tortuga->shader = shader;
	tortuga->inicializarVertexArray(posicionID, colorID, modeloID, vistaID, proyeccionID);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	tiempoAnterior = glfwGetTime();

	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window)) {
		//Establecer el area de render (viewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla
		glClearColor(red, green, blue, 1);
		//Limpiar la pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo
		actualizar();
		dibujar();

		//Intercambio de buffers
		glfwSwapBuffers(window);
		//Buscar señales de entrada
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
