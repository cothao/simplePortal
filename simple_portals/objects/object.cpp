#include "object.h"
#include <glad/glad.h>

namespace Object
{

	VertexObject quad;
	VertexObject plane;
}

void Object::Quad()
{

	if (quad.VAO == 0)
	{

		glGenVertexArrays(1, &quad.VAO);
		glGenBuffers(1, &quad.VBO);
		glBindVertexArray(quad.VAO);
		glBindBuffer(GL_ARRAY_BUFFER, quad.VBO);

		float vertices[] = {
			
			1.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f,  1., 1., // Top Right
			-1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0., 1.0, // Top Left
			1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1., 0.,// Top Right
			-1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0., 1.,// Top Right
			-1.0f, -1.0f, 0.0f,0.0f, 1.0f, 0.0f, 0., 0., // Top Right
			1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1., 0.// Top Right
			
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	};

	glBindVertexArray(quad.VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);

}

void Object::Plane()
{
    float planeVertices[] = {
        // positions            // normals         // texcoords
         25.0f, -0.5f,  25.0f,  0.0f, 1.0f, 0.0f,  25.0f,  0.0f,
        -25.0f, -0.5f,  25.0f,  0.0f, 1.0f, 0.0f,   0.0f,  0.0f,
        -25.0f, -0.5f, -25.0f,  0.0f, 1.0f, 0.0f,   0.0f, 25.0f,

         25.0f, -0.5f,  25.0f,  0.0f, 1.0f, 0.0f,  25.0f,  0.0f,
        -25.0f, -0.5f, -25.0f,  0.0f, 1.0f, 0.0f,   0.0f, 25.0f,
         25.0f, -0.5f, -25.0f,  0.0f, 1.0f, 0.0f,  25.0f, 25.0f
    };
    // plane VAO
    if (plane.VAO == 0)
    {
        glGenVertexArrays(1, &plane.VAO);
        glGenBuffers(1, &plane.VBO);
        glBindVertexArray(plane.VAO);
        glBindBuffer(GL_ARRAY_BUFFER, plane.VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glBindVertexArray(0);
    }

    glBindVertexArray(plane.VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}