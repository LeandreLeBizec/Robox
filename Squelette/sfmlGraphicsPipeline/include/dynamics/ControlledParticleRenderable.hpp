#ifndef CONTROLLED_PARTICLE_RENDERABLE_HPP
#define CONTROLLED_PARTICLE_RENDERABLE_HPP

#include "MeshRenderable.hpp"
#include "Particle.hpp"

#include <vector>
#include <glm/glm.hpp>

/**@brief Render a particle to the screen.
 *
 * Render a particle to the screen. Since a particle is modeled by
 * a ball, this renderable simply render the corresponding ball. If
 * you have more than one renderable, have a look to ParticleListRenderable.
 */
class ControlledParticleRenderable : public MeshRenderable
{
public:
    ~ControlledParticleRenderable();
    /**@brief Build a particle renderable.
        *
        * Build a renderable to render a particle.
        * @param program The shader program used to render the particle.
        * @param particle The particle to render.
        */
    ControlledParticleRenderable( ShaderProgramPtr program, const ParticlePtr & particle, unsigned int strips=10u, unsigned int slices=20u);

private:
    void do_animate(float);
    ParticlePtr m_particle;
};

typedef std::shared_ptr<ControlledParticleRenderable> ControlledParticleRenderablePtr;

#endif //CONTROLLED_PARTICLE_RENDERABLE_HPP