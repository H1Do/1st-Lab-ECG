#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"

GLuint VBO; // Указатель на буфер вершины

static void RenderSceneCB() 
{
    glClear(GL_COLOR_BUFFER_BIT); // Очищение буфера кадра 

    glEnableVertexAttribArray(0); // Включаем атрибуты вершины
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Указываем конвейеру, как воспринимать данные внутри буфера

    glDrawArrays(GL_POINTS, 0, 1); // Запускаем функцию для отрисовки

    glDisableVertexAttribArray(0); // Выключаем атрибуты вершины
    
    glutSwapBuffers(); // Меняем местами фоновый буфер и буфер кадра
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}

static void CreateVertexBuffer()
{
    Vector3f Vertices[1];
    Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Иницианализируем GLUT

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // Включаем двойную буферизацию и буфер цвета 

    glutInitWindowSize(1024, 768); // Задаём размер окна
    glutInitWindowPosition(100, 100); // Позицию окна
    glutCreateWindow("Something"); // Создаём окно и задаём ему заголовок

    InitializeGlutCallbacks();

    GLenum res = glewInit(); // Инициализируем GLEW
    if (res != GLEW_OK) { // Проверяем на ошибку
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Задаем цвет, к. будет использован во время очистки буфера кадра

    CreateVertexBuffer();

    glutMainLoop(); // Передаём контроль GLUT

    return 0;
}
