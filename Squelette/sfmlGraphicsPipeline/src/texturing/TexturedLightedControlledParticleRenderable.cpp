#include "./../../include/texturing/TexturedLightedControlledParticleRenderable.hpp"
#include "./../../include/MeshRenderable.hpp"
#include "./../../include/gl_helper.hpp"
#include "./../../include/log.hpp"
#include "./../../include/Utils.hpp"


#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/io.hpp>
#include <GL/glew.h>

TexturedLightedControlledParticleRenderable::~TexturedLightedControlledParticleRenderable()
{}

TexturedLightedControlledParticleRenderable:: TexturedLightedControlledParticleRenderable(
        ShaderProgramPtr program,
        const ParticlePtr & particle,
        const MaterialPtr & mat,
        const std::string& filename,
        unsigned int strips,
        unsigned int slices,
        bool vertex_normals) :
        TexturedLightedMeshRenderable(program, false, mat),
        m_particle(particle)
{
    getUnitSphere(m_positions, m_normals, m_tcoords, strips, slices, vertex_normals);
    m_original_tcoords = m_tcoords;

    m_colors.resize( m_positions.size() );
    for( size_t i = 0; i < m_positions.size(); ++ i ){
        m_colors[i] = getColor( m_positions[i].x, -1, 1 );
    }

    for( size_t i = 0; i < m_positions.size(); ++ i ){
        m_positions[i] = m_particle->getRadius() * m_positions[i];
    }

    // Load image
    m_image.loadFromFile(filename);
    m_image.flipVertically(); // sfml inverts the v axis... put the image in OpenGL convention: lower left corner is (0,0)

    update_all_buffers();
    m_particle->setFixed(true);
    glm::vec3 world_position = glm::vec3(m_model[3]);
    m_particle->setPosition(world_position);
}

void TexturedLightedControlledParticleRenderable::do_animate(float time)
{
    MeshRenderable::do_animate(time);

    glm::vec3 world_position = glm::vec3(m_model[3]);
    float dt = 0.01;
    m_particle->setVelocity((world_position - m_particle->getPosition()) / dt);
    m_particle->setPosition(world_position);
}
