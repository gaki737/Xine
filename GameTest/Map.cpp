#include "Map.h"

//default empty map constructor
Map::Map()
{

}

//actual map construction with passed width, length and height range values
Map::Map(int width, int length, int heightMin, int heightMax)
{
	//iterating through the maps length
	for (int x = 0; x < length; x++)
	{
		//nested loop for iterating through the maps width
		for (int z = 0; z < width; z++)
		{
			//nested loop to iterate through the (more or less) randomly determined height 
			for (int y = 0; y < rand() % (heightMax-heightMin+1) + heightMin; y++)
			{
				//add a Block instance with it's properties in the blocks vector (the map)
				blocks.push_back(Block(Vector3(x, y, z), 1.0f, Color(1.0f, 1.0f, 1.0f), Vector3(), true));
			}
		}
	}
	//iterating through the block vector to add smaller blocks as collision indicators in the blockCols vector
	for (Block block : blocks)
	{
		//add a small blue block as the indicator for the lower left back corner
		blockCols.push_back(Block(block.bb.LeftDownBack, 0.2f, Color(0.0f, 0.0f, 1.0f), false));
		//add a small green block as the indicator for the upper right front corner
		blockCols.push_back(Block(block.bb.RightUpFront, 0.2f, Color(0.0f, 1.0f, 0.0f), false));
	}
}

//the actual render method to render the map in it's desired state (e.g. debug mode)
void Map::Render(int rendermode)
{
	//render the debug mode of the map
	if (rendermode == Renderer::renderModes::Debug)
	{
		//draw three coloured lines to indicate the world axes
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

		//render the block collision indicators of each block (blockCol)
		for (Block blockCol : blockCols)
		{
			blockCol.Render();

			
		}
		//draw a red wireframe for each block instead of it's full version
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

	//the normal render mode of the map rendering 
	if (rendermode == Renderer::renderModes::Normal)
	{
		//render each block
		for (Block block : blocks)
		{
			block.Render();

		}

		
	}
}

//find a block by it's coordinates
//TO BE IMPLEMENTED                       <-----------
void Map::findBlock(Vector3 pos)
{

}
