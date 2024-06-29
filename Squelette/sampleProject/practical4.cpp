#include <ShaderProgram.hpp>
#include <Viewer.hpp>

#include <CylinderMeshRenderable.hpp>
#include <FrameRenderable.hpp>
#include <GeometricTransformation.hpp>
#include <iostream>
#include <iomanip>

void movingTree(Viewer& viewer);
void movingCylinder(Viewer& viewer);

void initialize_scene( Viewer& viewer )
{
    movingCylinder(viewer);
//    movingTree(viewer);
}

int main() 
{
    glm::vec4 background_color(0.7,0.7,0.7,1);
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

void movingCylinder( Viewer& viewer )
{
    //Add shader
    ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(  "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl", 
                                                                    "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
    viewer.addShaderProgram( flatShader );

    //Frame
    FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
    viewer.addRenderable(frame);

    //Animated cylinder
    auto cylinder = std::make_shared<CylinderMeshRenderable>(flatShader, false);
    cylinder->setLocalTransform(GeometricTransformation(glm::vec3{}, glm::angleAxis(-3.14f/2, glm::vec3(1,0,0)), glm::vec3(0.1,0.1,2.0)).toMatrix());

    // TODO: Keyframes on parent transformation
    cylinder->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(0.0f, glm::vec3(0,0,0)), glm::vec3(1,1,1)), 0.0);
    cylinder->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(-3.14f/2, glm::vec3(0,0,1)), glm::vec3(1,1,1)), 5.0);
    cylinder->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(0.0f, glm::vec3(0,0,1)), glm::vec3(1,1,1)), 10.0);
    //...

    // TODO: Keyframes on local transformation
    //cylinder->addLocalTransformKeyframe(GeometricTransformation(glm::vec3(3,3,3), glm::quat{}, glm::vec3(1,1,1)), 5.0);
    //...

    viewer.addRenderable(cylinder);
    viewer.startAnimation();
}
bool indexed = false; // indexed version already implemented
unsigned int slices = 50u; // number of slices
bool vertex_normals = true; // use vertex normals ? else triangle normals

void movingTree( Viewer& viewer )
{
    //Add shader
    ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(  "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl", "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
    viewer.addShaderProgram( flatShader );

    //Frame
    FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
    viewer.addRenderable(frame);

    //Tree modeling:
    //The modeling is hierarchical (setLocalTransform, setGlobalTransform)
    //The animation is hierarchical too (addGlobalTransformKeyframe, addLocalTransformKeyframe)

    // Hierarchical Tree
    // TODO: Create and animate the main branch 
    CylinderMeshRenderablePtr root = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
    root->setLocalTransform( GeometricTransformation(glm::vec3{}, glm::angleAxis(-3.14f/2, glm::vec3(1,0,0)), glm::vec3(0.1,0.1,2.0)).toMatrix() );
    //Pour faire 2 transformations → un objet vide root avec la transformation statique (HierarchicalRenderable) puis l'objet qui hérite avec la transformation dynamique.

    // TODO: root->addGlobalTransformKeyframe(...)
    root->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(0.0f, glm::vec3(0,1,0)), glm::vec3(1,1,1)), 0.0);
    root->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(3.14f, glm::vec3(0,1,0)), glm::vec3(1,1,1)), 5.0);
    root->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(6.28f, glm::vec3(0,1,0)), glm::vec3(1,1,1)), 10.0);

    //TODO: Add and animate a child branch
    CylinderMeshRenderablePtr root1 = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
    root1->setLocalTransform( GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(0.0f, glm::vec3(0,1,0)), glm::vec3(0.1,0.1,2.0)).toMatrix() );

    CylinderMeshRenderablePtr root2 = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
    root2->setLocalTransform( GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(3.14f/4, glm::vec3(0,1,0)), glm::vec3(0.1,0.1,2.0)).toMatrix() );

    CylinderMeshRenderablePtr root3 = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
    root3->setLocalTransform( GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(3.14f/2, glm::vec3(0,1,0)), glm::vec3(0.1,0.1,2.0)).toMatrix() );

    CylinderMeshRenderablePtr root4 = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
    root4->setLocalTransform( GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(3*3.14f/4, glm::vec3(0,1,0)), glm::vec3(0.1,0.1,2.0)).toMatrix() );

    CylinderMeshRenderablePtr root5 = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
    root5->setLocalTransform( GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(3.14f, glm::vec3(0,1,0)), glm::vec3(0.1,0.1,2.0)).toMatrix() );

    CylinderMeshRenderablePtr root6 = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
    root6->setLocalTransform( GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(-3*3.14f/4, glm::vec3(0,1,0)), glm::vec3(0.1,0.1,2.0)).toMatrix() );

    CylinderMeshRenderablePtr root7 = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
    root7->setLocalTransform( GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(-3.14f/2, glm::vec3(0,1,0)), glm::vec3(0.1,0.1,2.0)).toMatrix() );

    CylinderMeshRenderablePtr root8 = std::make_shared<CylinderMeshRenderable>(flatShader, indexed, slices, vertex_normals);
    root8->setLocalTransform( GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(-3.14f/4, glm::vec3(0,1,0)), glm::vec3(0.1,0.1,2.0)).toMatrix() );


    root1->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(0.0f, glm::vec3(1,0,0)), glm::vec3(1,1,1)), 0.0);
    root1->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(-3.14f/2, glm::vec3(1,0,0)), glm::vec3(1,1,1)), 5.0);
    root1->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(0.0f, glm::vec3(1,0,0)), glm::vec3(1,1,1)), 10.0);

    root3->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(0.0f, glm::vec3(0,0,1)), glm::vec3(1,1,1)), 0.0);
    root3->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(3.14f/2, glm::vec3(0,0,1)), glm::vec3(1,1,1)), 5.0);
    root3->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(0.0f, glm::vec3(0,0,1)), glm::vec3(1,1,1)), 10.0);

    root5->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(0.0f, glm::vec3(1,0,0)), glm::vec3(1,1,1)), 0.0);
    root5->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(3.14f/2, glm::vec3(1,0,0)), glm::vec3(1,1,1)), 5.0);
    root5->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(0.0f, glm::vec3(1,0,0)), glm::vec3(1,1,1)), 10.0);

    root7->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(0.0f, glm::vec3(0,0,1)), glm::vec3(1,1,1)), 0.0);
    root7->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(-3.14f/2, glm::vec3(0,0,1)), glm::vec3(1,1,1)), 5.0);
    root7->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3(0,0,0), glm::angleAxis(0.0f, glm::vec3(0,0,1)), glm::vec3(1,1,1)), 10.0);


    HierarchicalRenderable::addChild(root, root1);
    HierarchicalRenderable::addChild(root, root2);
    HierarchicalRenderable::addChild(root, root3);
    HierarchicalRenderable::addChild(root, root4);
    HierarchicalRenderable::addChild(root, root5);
    HierarchicalRenderable::addChild(root, root6);
    HierarchicalRenderable::addChild(root, root7);
    HierarchicalRenderable::addChild(root, root8);

    viewer.addRenderable(root);

    viewer.startAnimation();
}