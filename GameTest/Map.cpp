#include "Map.h"


Map::Map()
{

}


Map::Map(int width, int length)
{
	int counter = 0;

	for (int z = 0; z < length; z++)
	{
		for (int x = 0; x < width; x++)
		{
			for (int y = 0; y < rand() % 5 + 1; y++)
			{
				blocks.push_back(Block(Vector3(x, y, z), 1.0f, Color(1.0f, 1.0f, 1.0f), Vector3(), true));
				//counter++;
				//std::cout << "Initializing Block [" << counter << "] at " << Vector3(x, y, z) << std::endl;
			}
		}
	}
	for (Block block : blocks)
	{
		blockCols.push_back(Block(block.bb.LeftDownBack, 0.2f, Color(0.0f, 0.0f, 1.0f), false));
		blockCols.push_back(Block(block.bb.RightUpFront, 0.2f, Color(0.0f, 1.0f, 0.0f), false));
	}
}

void Map::Render(int rendermode)
{
	if (rendermode == Renderer::renderModes::Debug)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 10.0f, 0.0f);
		glVertex3f(100.0f, 10.0f, 0.0f);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 10.0f, 0.0f);
		glVertex3f(0.0f, 10.0f, 100.0f);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 10.0f, 0.0f);
		glVertex3f(0.0f, 100.0f, 0.0f);
		glEnd();

		for (Block blockCol : blockCols)
		{
			blockCol.Render();

			
		}

		for (Block block : blocks)
		{

			glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(block.bb.LeftUpBack.x, block.bb.LeftUpBack.y, block.bb.LeftUpBack.z);
			glVertex3f(block.bb.LeftDownBack.x, block.bb.LeftDownBack.y, block.bb.LeftDownBack.z);

			glVertex3f(block.bb.LeftDownBack.x, block.bb.LeftDownBack.y, block.bb.LeftDownBack.z);
			glVertex3f(block.bb.RightDownBack.x, block.bb.RightDownBack.y, block.bb.RightDownBack.z);

			glVertex3f(block.bb.RightDownBack.x, block.bb.RightDownBack.y, block.bb.RightDownBack.z);
			glVertex3f(block.bb.RightUpBack.x, block.bb.RightUpBack.y, block.bb.RightUpBack.z);

			glVertex3f(block.bb.RightUpBack.x, block.bb.RightUpBack.y, block.bb.RightUpBack.z);
			glVertex3f(block.bb.LeftUpBack.x, block.bb.LeftUpBack.y, block.bb.LeftUpBack.z);



			glVertex3f(block.bb.LeftUpFront.x, block.bb.LeftUpFront.y, block.bb.LeftUpFront.z);
			glVertex3f(block.bb.LeftDownFront.x, block.bb.LeftDownFront.y, block.bb.LeftDownFront.z);

			glVertex3f(block.bb.LeftDownFront.x, block.bb.LeftDownFront.y, block.bb.LeftDownFront.z);
			glVertex3f(block.bb.RightDownFront.x, block.bb.RightDownFront.y, block.bb.RightDownFront.z);

			glVertex3f(block.bb.RightDownFront.x, block.bb.RightDownFront.y, block.bb.RightDownFront.z);
			glVertex3f(block.bb.RightUpFront.x, block.bb.RightUpFront.y, block.bb.RightUpFront.z);

			glVertex3f(block.bb.RightUpFront.x, block.bb.RightUpFront.y, block.bb.RightUpFront.z);
			glVertex3f(block.bb.LeftUpFront.x, block.bb.LeftUpFront.y, block.bb.LeftUpFront.z);



			glVertex3f(block.bb.LeftUpBack.x, block.bb.LeftUpBack.y, block.bb.LeftUpBack.z);
			glVertex3f(block.bb.LeftUpFront.x, block.bb.LeftUpFront.y, block.bb.LeftUpFront.z);

			glVertex3f(block.bb.LeftDownBack.x, block.bb.LeftDownBack.y, block.bb.LeftDownBack.z);
			glVertex3f(block.bb.LeftDownFront.x, block.bb.LeftDownFront.y, block.bb.LeftDownFront.z);

			glVertex3f(block.bb.RightDownBack.x, block.bb.RightDownBack.y, block.bb.RightDownBack.z);
			glVertex3f(block.bb.RightDownFront.x, block.bb.RightDownFront.y, block.bb.RightDownFront.z);

			glVertex3f(block.bb.RightUpBack.x, block.bb.RightUpBack.y, block.bb.RightUpBack.z);
			glVertex3f(block.bb.RightUpFront.x, block.bb.RightUpFront.y, block.bb.RightUpFront.z);


			glEnd();

		}
	}

	if (rendermode == Renderer::renderModes::Normal)
	{
		for (Block block : blocks)
		{
			block.Render();

		}

		
	}
}

void Map::findBlock(Vector3 pos)
{

}
