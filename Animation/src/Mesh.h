#pragma once
#include <iostream>
#include "Shader.h"
#include<vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#define MAX_BONE_INFLUENCE 4
struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
	glm::vec3 Tangent;
	glm::vec3 Bitangent;
	int m_BoneIDs[MAX_BONE_INFLUENCE];
	float m_Weights[MAX_BONE_INFLUENCE];
};
struct MeshTexture
{
	GLuint id;
	std::string type;
	aiString path;
};
class Mesh {
public:
	GLuint VAO;
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<MeshTexture> textures;
	Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<MeshTexture> textures);
	void Draw(Shader &shader);
private:
	GLuint  VBO, EBO;
	void setupMesh();
};