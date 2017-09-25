#include "Block.h"


//block constructor
Block::Block(Vector3 pos, float size, Color color, Vector3 texCoord, bool textured)
{
	//set the position
	this->position = pos;
	//set the size
	this->size = size;
	//set the color
	this->color = color;
	//make it textured or not
	this->textured = textured;
	//set the texture coordinate
	this->texCoord = texCoord;
	//set the bouding box
	bb = BoundingBox(this->position, this->size, this->size, this->size);
}

//render the block
void Block::Render()
{
	//apply the texture if textured is true
	if (this->textured)
	{
		glEnable(GL_TEXTURE_2D);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	}
	//disable the texture in opengl
	else
	{
		glDisable(GL_TEXTURE_2D);
	}

	//begin the rendering
	glBegin(GL_QUADS);



	/* Cube Top */
	if (this->textured)
	{
		glTexCoord2f(0.5f, 0);
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	else
		glColor3f(this->color.r, this->color.g, this->color.b);

	glVertex3f(this->position.x - (this->size / 2), this->position.y + (this->size / 2), this->position.z + (this->size / 2));
	if (this->textured)
		glTexCoord2f(1, 0);
	glVertex3f(this->position.x + (this->size / 2), this->position.y + (this->size / 2), this->position.z + (this->size / 2));
	if (this->textured)
		glTexCoord2f(1, 1);
	glVertex3f(this->position.x + (this->size / 2), this->position.y + (this->size / 2), this->position.z - (this->size / 2));
	if (this->textured)
		glTexCoord2f(0.5f, 1);
	glVertex3f(this->position.x - (this->size / 2), this->position.y + (this->size / 2), this->position.z - (this->size / 2));


	/* Cube Bottom */
	if (this->textured)
	{
		glTexCoord2f(0.5f, 0);
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	else
		glColor3f(this->color.r, this->color.g, this->color.b);

	glVertex3f(this->position.x - (this->size / 2), this->position.y - (this->size / 2), this->position.z + (this->size / 2));
	if (this->textured)
		glTexCoord2f(0.5f, 1);
	glVertex3f(this->position.x - (this->size / 2), this->position.y - (this->size / 2), this->position.z - (this->size / 2));
	if (this->textured)
		glTexCoord2f(1, 1);
	glVertex3f(this->position.x + (this->size / 2), this->position.y - (this->size / 2), this->position.z - (this->size / 2));
	if (this->textured)
		glTexCoord2f(1, 0);
	glVertex3f(this->position.x + (this->size / 2), this->position.y - (this->size / 2), this->position.z + (this->size / 2));

	/* Cube Front */
	if (this->textured)
	{
		glTexCoord2f(0.5f, 0);
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	else
		glColor3f(this->color.r, this->color.g, this->color.b);

	glVertex3f(this->position.x - (this->size / 2), this->position.y + (this->size / 2), this->position.z + (this->size / 2));
	if (this->textured)
		glTexCoord2f(0, 1);
	glVertex3f(this->position.x - (this->size / 2), this->position.y - (this->size / 2), this->position.z + (this->size / 2));
	if (this->textured)
		glTexCoord2f(0.5f, 1);
	glVertex3f(this->position.x + (this->size / 2), this->position.y - (this->size / 2), this->position.z + (this->size / 2));
	if (this->textured)
		glTexCoord2f(0.5f, 0);
	glVertex3f(this->position.x + (this->size / 2), this->position.y + (this->size / 2), this->position.z + (this->size / 2));



	/* Cube Back */
	if (this->textured)
	{
		glTexCoord2f(0.5f, 0);
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	else
		glColor3f(this->color.r, this->color.g, this->color.b);

	glVertex3f(this->position.x - (this->size / 2), this->position.y + (this->size / 2), this->position.z - (this->size / 2));
	if (this->textured)
		glTexCoord2f(0.5f, 0);
	glVertex3f(this->position.x + (this->size / 2), this->position.y + (this->size / 2), this->position.z - (this->size / 2));
	if (this->textured)
		glTexCoord2f(0.5f, 1);
	glVertex3f(this->position.x + (this->size / 2), this->position.y - (this->size / 2), this->position.z - (this->size / 2));
	if (this->textured)
		glTexCoord2f(0, 1);
	glVertex3f(this->position.x - (this->size / 2), this->position.y - (this->size / 2), this->position.z - (this->size / 2));

	/* Cube Left Side */
	if (this->textured)
	{

		glTexCoord2f(0.5f, 0);
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	else
		glColor3f(this->color.r, this->color.g, this->color.b);

	glVertex3f(this->position.x - (this->size / 2), this->position.y + (this->size / 2), this->position.z - (this->size / 2));
	if (this->textured)
		glTexCoord2f(0, 1);
	glVertex3f(this->position.x - (this->size / 2), this->position.y - (this->size / 2), this->position.z - (this->size / 2));
	if (this->textured)
		glTexCoord2f(0.5f, 1);
	glVertex3f(this->position.x - (this->size / 2), this->position.y - (this->size / 2), this->position.z + (this->size / 2));
	if (this->textured)
		glTexCoord2f(0.5f, 0);
	glVertex3f(this->position.x - (this->size / 2), this->position.y + (this->size / 2), this->position.z + (this->size / 2));


	/* Cube Right Side */

	if (this->textured)
	{
		glTexCoord2f(0.5f, 0);
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	else
		glColor3f(this->color.r, this->color.g, this->color.b);

	glVertex3f(this->position.x + (this->size / 2), this->position.y + (this->size / 2), this->position.z - (this->size / 2));
	if (this->textured)
		glTexCoord2f(0.5f, 0);
	glVertex3f(this->position.x + (this->size / 2), this->position.y + (this->size / 2), this->position.z + (this->size / 2));
	if (this->textured)
		glTexCoord2f(0.5f, 1);
	glVertex3f(this->position.x + (this->size / 2), this->position.y - (this->size / 2), this->position.z + (this->size / 2));
	if (this->textured)
		glTexCoord2f(0, 1);
	glVertex3f(this->position.x + (this->size / 2), this->position.y - (this->size / 2), this->position.z - (this->size / 2));

	glEnd();

	//end the rendering 
	glDisable(GL_TEXTURE_2D);

}

