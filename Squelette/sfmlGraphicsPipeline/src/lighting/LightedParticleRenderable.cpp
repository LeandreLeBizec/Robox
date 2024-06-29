#include "./../../include/lighting/LightedParticleRenderable.hpp"
#include "./../../include/MeshRenderable.hpp"
#include "./../../include/gl_helper.hpp"
#include "./../../include/log.hpp"
#include "./../../include/Utils.hpp"


#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/io.hpp>
#include <GL/glew.h>

LightedParticleRenderable::~LightedParticleRenderable()
{}

LightedParticleRenderable::LightedParticleRenderable(ShaderProgramPtr program, const ParticlePtr & particle, const MaterialPtr & mat, unsigned int strips, unsigned int slices) :
        LightedMeshRenderable(program, true, mat),
        m_particle(particle)
{
    std::vector<glm::uvec3> uvec3_indices;
    getUnitIndexedSphere(m_positions, m_normals, uvec3_indices, strips, slices);
    // Need to unpack the indices
    unpack(uvec3_indices, m_indices);

    m_colors.resize( m_positions.size() );
    for( size_t i = 0; i < m_positions.size(); ++ i )
        m_colors[i] = getColor( m_positions[i].x, -1, 1 );

    update_all_buffers();
}

void LightedParticleRenderable::do_draw()
{
    //Update the parent and local transform matrix to position the geometric data according to the particle's data.
    const float& pRadius = m_particle->getRadius();
    const glm::vec3& pPosition = m_particle->getPosition();
    glm::mat4 scale = glm::scale(glm::mat4(1.0), glm::vec3(pRadius));
    glm::mat4 translate = glm::translate(glm::mat4(1.0), glm::vec3(pPosition));
    setLocalTransform(translate*scale);
    MeshRenderable::do_draw();
}
