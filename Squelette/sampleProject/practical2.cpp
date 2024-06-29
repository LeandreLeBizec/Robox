#include <Viewer.hpp>
#include <ShaderProgram.hpp>
#include <CylinderMeshRenderable.hpp>
#include <MeshRenderable.hpp>
#include <FrameRenderable.hpp>
#include <MeshRenderable.hpp>

void initialize_scene( Viewer& viewer )
{
    // Create a shader program
	ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(
        "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
        "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");

    // Add the shader program to the viewer
    viewer.addShaderProgram( flatShader );

     /*
	// Create a cylinder
    bool indexed = false; // indexed version already implemented
    unsigned int slices = 20u; // number of slices
    bool vertex_normals = false; // use vertex normals ? else triangle normals
    // See CylinderMeshRenderable.cpp 
    CylinderMeshRenderablePtr cylinder = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);

    // Add the cylinder to the viewer
    viewer.addRenderable(cylinder);
    */

    /*
    // Create suzanne
    const std::string suzanne_path = "../../sfmlGraphicsPipeline/meshes/suzanne.obj";
    MeshRenderablePtr suzanne = std::make_shared<MeshRenderable>(flatShader, suzanne_path);
    suzanne->setModelMatrix(getTranslationMatrix(5,0,0));
    // Add suzanne to the viewer
    viewer.addRenderable(suzanne);
    */


    const std::string cat_path = "../../sfmlGraphicsPipeline/meshes/cat.obj";
    MeshRenderablePtr cat = std::make_shared<MeshRenderable>(flatShader, cat_path);
    glm::mat4 translate_cat = getTranslationMatrix(-0.2,3.2,-0.7);
    glm::mat4 rotate_cat = glm::rotate(glm::mat4(), 3.14f, glm::vec3(0,1,0));
    cat->setModelMatrix(translate_cat*rotate_cat);
    viewer.addRenderable(cat);


    const std::string pillar_path = "../../sfmlGraphicsPipeline/meshes/pillar.obj";
    MeshRenderablePtr pillar = std::make_shared<MeshRenderable>(flatShader, pillar_path);
    glm::mat4 translate = getTranslationMatrix(0,0,0);
    glm::mat4 rotate = glm::rotate(glm::mat4(), 3.14f/2, glm::vec3(0,0,1));
    pillar->setModelMatrix(translate*rotate);
    viewer.addRenderable(pillar);



}

int main() 
{
    glm::vec4 background_color(0.8,0.8,0.8,1);
	Viewer viewer(1280,720, background_color);
	initialize_scene(viewer);

	while( viewer.isRunning() )
	{
		viewer.handleEvent();
		viewer.animate();
		viewer.draw();
		viewer.display();
	}	

	return EXIT_SUCCESS;
}