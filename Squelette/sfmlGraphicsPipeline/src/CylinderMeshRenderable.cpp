#include "./../include/CylinderMeshRenderable.hpp"
#include "./../include/gl_helper.hpp"
#include "./../include/log.hpp"
#include "./../include/Utils.hpp"

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>

CylinderMeshRenderable::~CylinderMeshRenderable()
{}

CylinderMeshRenderable::CylinderMeshRenderable(ShaderProgramPtr shaderProgram, bool indexed, unsigned int slices, bool vertex_normals) :
    MeshRenderable(shaderProgram, indexed)
{
    if (indexed){
        std::vector<glm::uvec3> indices;
        getUnitIndexedCylinder(m_positions, m_normals, indices, 3);
        // getUniIndexedCube fills a std::vector<glm::uvec3> of length n,
        // but m_indices is a std::vector<unsigned int> of length 3n.
        // We need to unpack the values.
        unpack(indices, m_indices);

        // Set random colors per vertex
        m_colors.resize(m_positions.size(), glm::vec4(0));
        for (size_t i=0; i<m_colors.size(); ++i)
            m_colors[i] = randomColor();
        
    }else{
        // Go to Utils.cpp and fill this function
        getUnitCylinder(m_positions, m_normals, m_tcoords, slices, vertex_normals);
        // Set random colors per triangle
        m_colors.resize(m_positions.size(), glm::vec4(0));
        
        /*
        for (size_t i=0; i<m_colors.size() / 3; ++i){
            glm::vec4 color = randomColor();
            m_colors[ 3 * i + 0 ] = color;
            m_colors[ 3 * i + 1 ] = color;
            m_colors[ 3 * i + 2 ] = color;
        }
        */

        
        glm::vec4 top_color = randomColor();
        glm::vec4 side_color = randomColor();
        glm::vec4 bottom_color = randomColor();

        for( size_t i = 0; i < slices; ++ i){

            size_t voffset = 12 * i;

            // top triangle
            m_colors[ voffset +  0 ] = top_color;
            m_colors[ voffset +  1 ] = top_color;
            m_colors[ voffset +  2 ] = top_color;

            // side triangles
            m_colors[ voffset +  3 ] = side_color;
            m_colors[ voffset +  4 ] = side_color;
            m_colors[ voffset +  5 ] = side_color;
            m_colors[ voffset +  6 ] = side_color;
            m_colors[ voffset +  7 ] = side_color;
            m_colors[ voffset +  8 ] = side_color;

            // bottom triangle
            m_colors[ voffset +  9 ] = bottom_color;
            m_colors[ voffset + 10 ] = bottom_color;
            m_colors[ voffset + 11 ] = bottom_color;

        }
        
    
    }

    // See MeshRenderable::update_all_buffers
    update_all_buffers();
}