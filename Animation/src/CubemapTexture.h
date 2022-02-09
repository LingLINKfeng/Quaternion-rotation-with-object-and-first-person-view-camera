#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include<string>
#include<vector>
#include<iostream>
class CubemapTexture
{
public:
	CubemapTexture(std::vector<std::string> faces);
	~CubemapTexture();
	void Bind();
	void Unbind();
private:
	int width, height, nrChannels;
	unsigned int textureID;
};
