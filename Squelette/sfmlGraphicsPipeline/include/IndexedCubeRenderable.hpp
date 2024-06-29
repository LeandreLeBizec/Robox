#ifndef INDEXED_CUBE_RENDERABLE_HPP
#define INDEXED_CUBE_RENDERABLE_HPP

#include "Renderable.hpp"
#include <vector>
#include <glm/glm.hpp>

class IndexedCubeRenderable : public Renderable
{
    public:
        ~IndexedCubeRenderable();
        IndexedCubeRenderable(ShaderProgramPtr program);

    private:
        void do_draw();

        std::vector< glm::vec3 > m_positions;
        unsigned int m_vBuffer;

        //Exo1
        std::vector< glm::vec4 > m_colors;
        unsigned int m_cBuffer;

        std::vector<unsigned int> m_index;
        unsigned int m_iBuffer;

        glm::mat4 m_model;
};

typedef std::shared_ptr<IndexedCubeRenderable> IndexedCubeRenderablePtr; 

#endif
