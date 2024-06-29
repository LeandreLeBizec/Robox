#ifndef LIGHTED_CONTROLLED_PARTICLE_RENDERABLE_HPP
#define LIGHTED_CONTROLLED_PARTICLE_RENDERABLE_HPP

#include "./../lighting/LightedMeshRenderable.hpp"
#include "./../lighting/Material.hpp"
#include "./../dynamics/Particle.hpp"
#include <vector>
#include <glm/glm.hpp>

class LightedControlledParticleRenderable : public LightedMeshRenderable
{
public:
    ~LightedControlledParticleRenderable();
    LightedControlledParticleRenderable( ShaderProgramPtr program, const ParticlePtr & particle, const MaterialPtr & mat, unsigned int strips=10u, unsigned int slices=20u);

private:
    void do_animate(float);
    ParticlePtr m_particle;
};

typedef std::shared_ptr<LightedControlledParticleRenderable> LightedControlledParticleRenderablePtr;

#endif
