#ifndef TEXTURED_LIGHTED_SPHERE_RENDERABLE_HPP
#define TEXTURED_LIGHTED_SPHERE_RENDERABLE_HPP

#include "./../texturing/TexturedLightedMeshRenderable.hpp"
#include "./../lighting/Material.hpp"
#include <vector>
#include <glm/glm.hpp>

class TexturedLightedSphereRenderable : public TexturedLightedMeshRenderable
{
public:
    ~TexturedLightedSphereRenderable();
    TexturedLightedSphereRenderable(ShaderProgramPtr prog, const MaterialPtr & mat, const std::string& filename, unsigned int strips=10u, unsigned int slice=30u, bool vertex_normals=true);
};

typedef std::shared_ptr<TexturedLightedSphereRenderable> TexturedLightedSphereRenderablePtr;

#endif
