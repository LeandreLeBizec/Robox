#include <Viewer.hpp>
#include <ShaderProgram.hpp>
#include <FrameRenderable.hpp>
#include <HierarchicalRenderable.hpp>
#include <CylinderMeshRenderable.hpp>
#include <MeshRenderable.hpp>
#include <SphereMeshRenderable.hpp>



const bool indexed = false; // indexed version already implemented
const unsigned int strips = 10u; // number of strips
const unsigned int slices = 50u; // number of slices
const bool vertex_normals = true; // use vertex normals ? else triangle normals

void exercice1(Viewer& viewer)
{
    ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(
        "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
        "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");

	viewer.addShaderProgram( flatShader );

    //Frame
	FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
	viewer.addRenderable(frame);

    // Create renderables
    const std::string pillar_path = "../../sfmlGraphicsPipeline/meshes/pillar.obj";
    MeshRenderablePtr pillar = std::make_shared<MeshRenderable>(flatShader, pillar_path);
    const std::string cat_path = "../../sfmlGraphicsPipeline/meshes/cat.obj";
    MeshRenderablePtr cat = std::make_shared<MeshRenderable>(flatShader, cat_path);
    MeshRenderablePtr littleCat = std::make_shared<MeshRenderable>(flatShader, cat_path);

    // Make transformation
    pillar->setGlobalTransform(getRotationMatrix(3.14f/2, glm::vec3(0,0,1)));
    cat->setLocalTransform(getRotationMatrix(3.14, glm::vec3(0,1,0)) * getRotationMatrix(3.14/2, glm::vec3(0,0,1)) * getTranslationMatrix(0.2,3.2,0.7) );

    // Define parent / children relationships
    HierarchicalRenderable::addChild(pillar, cat);
    HierarchicalRenderable::addChild(cat, littleCat);

    // Add the root of the hierarchy to the viewer
    viewer.addRenderable(pillar);
}


void exercice2( Viewer& viewer )
{
	ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(
        "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
        "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");

	viewer.addShaderProgram( flatShader );
	
	//Frame
	FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
	viewer.addRenderable(frame);

    // Hierarchical Tree
    // niveau0
    CylinderMeshRenderablePtr cylinder = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
    //niveau1
    CylinderMeshRenderablePtr cylinder1 = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
    CylinderMeshRenderablePtr cylinder2 = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
    //niveau2
    CylinderMeshRenderablePtr cylinder1_1 = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
    CylinderMeshRenderablePtr cylinder1_2 = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
    CylinderMeshRenderablePtr cylinder2_1 = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
    CylinderMeshRenderablePtr cylinder2_2 = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);

    cylinder->setLocalTransform(getScaleMatrix(0.5,0.5,4));
    cylinder1->setLocalTransform(getScaleMatrix(0.5,0.5,4));
    cylinder2->setLocalTransform(getScaleMatrix(0.5,0.5,4));

    cylinder1_1->setLocalTransform(getTranslationMatrix(0,0,4) * getRotationMatrix(3.14/6, glm::vec3(0,1,0)) * getScaleMatrix(0.5,0.5,4));
    cylinder1_2->setLocalTransform(getTranslationMatrix(0,0,4) * getRotationMatrix(-3.14/6, glm::vec3(0,1,0)) * getScaleMatrix(0.5,0.5,4) );
    cylinder2_1->setLocalTransform(getTranslationMatrix(0,0,4) * getRotationMatrix(3.14/6, glm::vec3(0,1,0)) * getScaleMatrix(0.5,0.5,4) );
    cylinder2_2->setLocalTransform(getTranslationMatrix(0,0,4) * getRotationMatrix(-3.14/6, glm::vec3(0,1,0)) * getScaleMatrix(0.5,0.5,4) );
    cylinder1->setGlobalTransform(getTranslationMatrix(0,0,4) * getRotationMatrix(3.14/6, glm::vec3(0,1,0)) );
    cylinder2->setGlobalTransform(getTranslationMatrix(0,0,4) * getRotationMatrix(-3.14/6, glm::vec3(0,1,0)) );

    //Sphere

    // niveau0
    SphereMeshRenderablePtr sphere = std::make_shared<SphereMeshRenderable>(flatShader, indexed, strips, slices, vertex_normals);
    //niveau1
    SphereMeshRenderablePtr sphere1 = std::make_shared<SphereMeshRenderable>(flatShader, indexed, strips, slices, vertex_normals);
    SphereMeshRenderablePtr sphere2 = std::make_shared<SphereMeshRenderable>(flatShader, indexed, strips, slices, vertex_normals);
    //niveau2
    SphereMeshRenderablePtr sphere1_1 = std::make_shared<SphereMeshRenderable>(flatShader, indexed, strips, slices, vertex_normals);
    SphereMeshRenderablePtr sphere1_2 = std::make_shared<SphereMeshRenderable>(flatShader, indexed, strips, slices, vertex_normals);
    SphereMeshRenderablePtr sphere2_1 = std::make_shared<SphereMeshRenderable>(flatShader, indexed, strips, slices, vertex_normals);
    SphereMeshRenderablePtr sphere2_2 = std::make_shared<SphereMeshRenderable>(flatShader, indexed, strips, slices, vertex_normals);

    sphere->setLocalTransform(getScaleMatrix(0.5,0.5,0.5));
    sphere->setGlobalTransform(getTranslationMatrix(0,0,4));

    sphere1->setLocalTransform(getScaleMatrix(0.5,0.5,0.5));
    sphere2->setLocalTransform(getScaleMatrix(0.5,0.5,0.5));
    sphere1->setGlobalTransform(getRotationMatrix(3.14/6, glm::vec3(0,1,0)) * getTranslationMatrix(0,0,4) );
    sphere2->setGlobalTransform(getRotationMatrix(-3.14/6, glm::vec3(0,1,0)) * getTranslationMatrix(0,0,4) );

    sphere1_1->setLocalTransform(getRotationMatrix(3.14/6, glm::vec3(0,1,0)) * getTranslationMatrix(0,0,4) * getScaleMatrix(0.5,0.5,0.5));
    sphere1_2->setLocalTransform(getRotationMatrix(-3.14/6, glm::vec3(0,1,0)) * getTranslationMatrix(0,0,4) *  getScaleMatrix(0.5,0.5,0.5) );
    sphere2_1->setLocalTransform(getRotationMatrix(3.14/6, glm::vec3(0,1,0)) * getTranslationMatrix(0,0,4) * getScaleMatrix(0.5,0.5,0.5) );
    sphere2_2->setLocalTransform(getRotationMatrix(-3.14/6, glm::vec3(0,1,0)) * getTranslationMatrix(0,0,4) * getScaleMatrix(0.5,0.5,0.5) );

    // Define parent / children relationships
    HierarchicalRenderable::addChild(cylinder, cylinder1);
    HierarchicalRenderable::addChild(cylinder, cylinder2);
    HierarchicalRenderable::addChild(cylinder1, cylinder1_1);
    HierarchicalRenderable::addChild(cylinder1, cylinder1_2);
    HierarchicalRenderable::addChild(cylinder2, cylinder2_1);
    HierarchicalRenderable::addChild(cylinder2, cylinder2_2);

    HierarchicalRenderable::addChild(sphere, sphere1);
    HierarchicalRenderable::addChild(sphere, sphere2);
    HierarchicalRenderable::addChild(sphere1, sphere1_1);
    HierarchicalRenderable::addChild(sphere1, sphere1_2);
    HierarchicalRenderable::addChild(sphere2, sphere2_1);
    HierarchicalRenderable::addChild(sphere2, sphere2_2);

    // Add the root of the hierarchy to the viewer
    viewer.addRenderable(cylinder);
    viewer.addRenderable(sphere);

}


void addBranch(int depth, float angle, CylinderMeshRenderablePtr root, ShaderProgramPtr shader)
{
    CylinderMeshRenderablePtr left = std::make_shared<CylinderMeshRenderable>(shader, indexed, slices, vertex_normals);
    CylinderMeshRenderablePtr right = std::make_shared<CylinderMeshRenderable>(shader, indexed, slices, vertex_normals);
    left->setLocalTransform(getScaleMatrix(0.5,0.5,5));
    right->setLocalTransform(getScaleMatrix(0.5,0.5,5));
    left->setGlobalTransform(getTranslationMatrix(0,0,5) * getRotationMatrix(angle, glm::vec3(0,1,0)) );
    right->setGlobalTransform(getTranslationMatrix(0,0,5) * getRotationMatrix(-angle, glm::vec3(0,1,0)) );

    HierarchicalRenderable::addChild(root, left);
    HierarchicalRenderable::addChild(root, right);

    depth--;
    angle /= 1.5;
    if(depth>0)
    {
        addBranch(depth, angle, left, shader);
        addBranch(depth, angle, right, shader);
    }
}

void RecursiveTree( Viewer& viewer )
{
	ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(
        "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
        "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
	viewer.addShaderProgram( flatShader );
	//Frame
	FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
	viewer.addRenderable(frame);

	//Create Renderables
	// niveau 0
	CylinderMeshRenderablePtr root = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
	root -> setLocalTransform(getScaleMatrix(0.5,0.5,5));
	root -> setGlobalTransform(getRotationMatrix(-3.14f/2, glm::vec3(1,0,0)));

	addBranch(5, 3.14f/4, root, flatShader);
    // Add the root of the hierarchy to the viewer
    viewer.addRenderable(root);
}

int main() 
{
	Viewer viewer(1280,720);
	RecursiveTree(viewer);

	while( viewer.isRunning() )
	{
		viewer.handleEvent();
		viewer.animate();
		viewer.draw();
		viewer.display();
	}	

	return EXIT_SUCCESS;
}
