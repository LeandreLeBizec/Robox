#ifndef TEXTURED_LIGHTED_CONTROLLED_PARTICLE_RENDERABLE_HPP
#define TEXTURED_LIGHTED_CONTROLLED_PARTICLE_RENDERABLE_HPP

#include "./../texturing/TexturedLightedMeshRenderable.hpp"
#include "./../lighting/Material.hpp"
#include "./../dynamics/Particle.hpp"
#include <vector>
#include <glm/glm.hpp>

class TexturedLightedControlledParticleRenderable : public TexturedLightedMeshRenderable
{
public:
    ~TexturedLightedControlledParticleRenderable();
    TexturedLightedControlledParticleRenderable(
            ShaderProgramPtr program,
            const ParticlePtr & particle,
            const MaterialPtr & mat,
            const std::string& filename,
            unsigned int strips=10u,
            unsigned int slices=20u,
            bool vertex_normals=true);

private:
    void do_animate(float);
    ParticlePtr m_particle;
};

typedef std::shared_ptr<TexturedLightedControlledParticleRenderable> TexturedLightedControlledParticleRenderablePtr;

#endif
