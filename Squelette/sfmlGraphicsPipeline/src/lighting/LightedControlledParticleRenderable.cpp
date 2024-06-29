#include "./../../include/lighting/LightedControlledParticleRenderable.hpp"
#include "./../../include/MeshRenderable.hpp"
#include "./../../include/gl_helper.hpp"
#include "./../../include/log.hpp"
#include "./../../include/Utils.hpp"


#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/io.hpp>
#include <GL/glew.h>

LightedControlledParticleRenderable::~LightedControlledParticleRenderable()
{}

LightedControlledParticleRenderable::LightedControlledParticleRenderable(
        ShaderProgramPtr program,
        const ParticlePtr & particle,
        const MaterialPtr & mat,
        unsigned int strips,
        unsigned int slices) :
        LightedMeshRenderable(program, true, mat),
        m_particle(particle)
{
    std::vector<glm::uvec3> uvec3_indices;
    getUnitIndexedSphere(m_positions, m_normals, uvec3_indices, strips, slices);
    // Need to unpack the indices
    unpack(uvec3_indices, m_indices);

    m_colors.resize( m_positions.size() );
    for( size_t i = 0; i < m_positions.size(); ++ i ){
        m_colors[i] = getColor( m_positions[i].x, -1, 1 );

    }

    for( size_t i = 0; i < m_positions.size(); ++ i ){
        m_positions[i] = m_particle->getRadius() * m_positions[i];
    }

    update_all_buffers();

    m_particle->setFixed(true);
    glm::vec3 world_position = glm::vec3(m_model[3]);
    m_particle->setPosition(world_position);
}

void LightedControlledParticleRenderable::do_animate(float time)
{
    MeshRenderable::do_animate(time);

    glm::vec3 world_position = glm::vec3(m_model[3]);
    float dt = 0.01;
    m_particle->setVelocity((world_position - m_particle->getPosition()) / dt);
    m_particle->setPosition(world_position);
}
