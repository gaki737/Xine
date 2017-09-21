#pragma once
class Renderer
{
public:
	void Render();

	enum renderModes
	{
		Normal,
		Collision,
		Debug
	};
};

