#ifndef TEXTURED_LIGHTED_PARTICLE_RENDERABLE_HPP
#define TEXTURED_LIGHTED_PARTICLE_RENDERABLE_HPP

#include "./../texturing/TexturedLightedMeshRenderable.hpp"
#include "./../lighting/Material.hpp"
#include "./../dynamics/Particle.hpp"
#include <vector>
#include <glm/glm.hpp>


class TexturedLightedParticleRenderable : public TexturedLightedMeshRenderable
{
public:
    ~TexturedLightedParticleRenderable();
    TexturedLightedParticleRenderable(
            ShaderProgramPtr program,
            const ParticlePtr & particle,
            const MaterialPtr & mat,
            const std::string& filename,
            unsigned int strips=10u,
            unsigned int slices=20u,
            bool vertex_normals=true);

private:
    void do_draw();
    ParticlePtr m_particle;
};

typedef std::shared_ptr<TexturedLightedParticleRenderable> TexturedLightedParticleRenderablePtr;

#endif
