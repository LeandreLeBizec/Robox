#ifndef LIGHTED_PARTICLE_RENDERABLE_HPP
#define LIGHTED_PARTICLE_RENDERABLE_HPP

#include "./../lighting/LightedMeshRenderable.hpp"
#include "./../lighting/Material.hpp"
#include "./../dynamics/Particle.hpp"
#include <vector>
#include <glm/glm.hpp>


class LightedParticleRenderable : public LightedMeshRenderable
{
public:
    ~LightedParticleRenderable();
//    LightedParticleRenderable( ShaderProgramPtr program, const ParticlePtr & particle, const MaterialPtr & mat, unsigned int strips=10u, unsigned int slices=20u, bool vertex_normals=true);
    LightedParticleRenderable( ShaderProgramPtr program, const ParticlePtr & particle, const MaterialPtr & mat, unsigned int strips=10u, unsigned int slices=20u);



protected:
    void do_draw();

private:
    ParticlePtr m_particle;
};

typedef std::shared_ptr<LightedParticleRenderable> LightedParticleRenderablePtr;

#endif
