#ifndef OBJECT_H
#define OBJECT_H


namespace Object
{

	extern struct VertexObject
	{
		unsigned int VBO, VAO;
	};

	extern VertexObject quad;
	extern VertexObject plane;

	void Quad();
	void Plane();

}

#endif