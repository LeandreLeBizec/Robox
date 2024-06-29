#include "./../../include/texturing/TexturedLightedParticleRenderable.hpp"
#include "./../../include/texturing/TexturedLightedMeshRenderable.hpp"
#include "./../../include/gl_helper.hpp"
#include "./../../include/log.hpp"
#include "./../../include/Utils.hpp"


#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/io.hpp>
#include <GL/glew.h>

TexturedLightedParticleRenderable::~TexturedLightedParticleRenderable()
{}

TexturedLightedParticleRenderable::TexturedLightedParticleRenderable(
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

    // Load image
    m_image.loadFromFile(filename);
    m_image.flipVertically(); // sfml inverts the v axis... put the image in OpenGL convention: lower left corner is (0,0)

    update_all_buffers();
}

void TexturedLightedParticleRenderable::do_draw()
{
    //Update the parent and local transform matrix to position the geometric data according to the particle's data.
    const float& pRadius = m_particle->getRadius();
    const glm::vec3& pPosition = m_particle->getPosition();
    glm::mat4 scale = glm::scale(glm::mat4(1.0), glm::vec3(pRadius));
    glm::mat4 translate = glm::translate(glm::mat4(1.0), glm::vec3(pPosition));
    setLocalTransform(translate*scale);
    TexturedLightedMeshRenderable::do_draw();
}
