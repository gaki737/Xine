#include "Renderer.h"
#include <SDL_opengl.h>
#include <gl\GL.h>
#include <gl\GLU.h>


void Renderer::Render()
{
	/*
	float verts = { };
	float colors = { };
	static_assert(sizeof(verts) == sizeof(colors), "");

	// not really needed for this example, but mandatory in core profile after GL 3.2
	GLuint vao;
	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint buf[2];
	glGenBuffers(2, buf);

	// assuming a layout(location = 0) for position and 
	// layout(location = 1) for color in the vertex shader

	// vertex positions
	glBindBuffer(GL_ARRAY_BUFFER, buf[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// copy/paste for color... same code as above. A real, non-trivial program would
	// normally use a single buffer for both -- usually with stride (5th param) to
	// glVertexAttribPointer -- that presumes interleaving the verts and colors arrays.
	// It's somewhat uglier but has better cache performance (ugly does however not
	// matter for a real program, since data is loaded from a modelling-tool generated
	// binary file anyway).
	glBindBuffer(GL_ARRAY_BUFFER, buf[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	*/
}
