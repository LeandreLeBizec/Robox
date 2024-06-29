# include "../../include/texturing/TexturedLightedCylinderRenderable.hpp"
# include "../../include/gl_helper.hpp"
# include "../../include/Utils.hpp"

# include <glm/gtc/type_ptr.hpp>
# include <GL/glew.h>

TexturedLightedCylinderRenderable::~TexturedLightedCylinderRenderable()
{}

TexturedLightedCylinderRenderable::TexturedLightedCylinderRenderable( ShaderProgramPtr shaderProgram, const MaterialPtr & material, const std::string& filename, unsigned int slices, bool vertex_normals)
        : TexturedLightedMeshRenderable(shaderProgram, false, material)
{
    getUnitCylinder(m_positions, m_normals, m_tcoords, slices, vertex_normals);
    m_original_tcoords = m_tcoords;

    m_colors.resize(m_positions.size(), glm::vec4(0));
    for (size_t i=0; i<m_colors.size(); ++i)
        m_colors[i] = randomColor();

    // Load image
    m_image.loadFromFile(filename);
    m_image.flipVertically(); // sfml inverts the v axis... put the image in OpenGL convention: lower left corner is (0,0)

    update_all_buffers();
}