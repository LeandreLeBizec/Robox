#ifndef TEXTURED_LIGHTED_CUBE_RENDERABLE_HPP
#define TEXTURED_LIGHTED_CUBE_RENDERABLE_HPP

#include "./../texturing/TexturedLightedMeshRenderable.hpp"
#include "./../lighting/Material.hpp"
#include <vector>
#include <glm/glm.hpp>

class TexturedLightedCubeRenderable : public TexturedLightedMeshRenderable
{
public:
    ~TexturedLightedCubeRenderable();
    TexturedLightedCubeRenderable( ShaderProgramPtr program, const MaterialPtr& material, const std::string& filename);
};

typedef std::shared_ptr<TexturedLightedCubeRenderable> TexturedLightedCubeRenderablePtr;

#endif
