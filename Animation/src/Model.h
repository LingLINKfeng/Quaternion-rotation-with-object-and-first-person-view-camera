#pragma once
#include"Mesh.h"
#include"std_image/stb_image.h"

class Model
{
public:
	Model(std::string path) {
		loadModel(path);
	}
	std::vector<MeshTexture> textures_loaded;
	std::vector<Mesh> meshes;
	std::string directory;

	void Draw(Shader &shader);
private:
	void loadModel(std::string path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
	std::vector<MeshTexture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
		std::string typeName);

};

unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma = false);