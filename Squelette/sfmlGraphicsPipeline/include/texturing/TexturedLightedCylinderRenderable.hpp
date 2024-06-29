#ifndef TEXTURED_LIGHTED_CYLINDER_RENDERABLE_HPP
#define TEXTURED_LIGHTED_CYLINDER_RENDERABLE_HPP

#include "./../texturing/TexturedLightedMeshRenderable.hpp"
#include "./../lighting/Material.hpp"
#include <vector>
#include <glm/glm.hpp>

class TexturedLightedCylinderRenderable : public TexturedLightedMeshRenderable
{
public:
    ~TexturedLightedCylinderRenderable();
    TexturedLightedCylinderRenderable(ShaderProgramPtr prog, const MaterialPtr & mat, const std::string& filename, unsigned int slice=30u, bool vertex_normals=true);
};

typedef std::shared_ptr<TexturedLightedCylinderRenderable> TexturedLightedCylinderRenderablePtr;

#endif
