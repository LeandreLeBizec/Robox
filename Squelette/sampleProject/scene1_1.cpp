//Base
#include <list>
#include <Viewer.hpp>
#include <ShaderProgram.hpp>
#include <FrameRenderable.hpp>

//Primitives
#include <HierarchicalRenderable.hpp>
#include <QuadMeshRenderable.hpp>
#include <CylinderMeshRenderable.hpp>
#include <MeshRenderable.hpp>
#include <SphereMeshRenderable.hpp>
#include <GeometricTransformation.hpp>


//Collision and forces
#include <dynamics/ParticleRenderable.hpp>
#include <dynamics/ControlledParticleRenderable.hpp>
#include <dynamics/ParticleListRenderable.hpp>
#include <dynamics/DynamicSystemRenderable.hpp>
#include <dynamics/DampingForceField.hpp>
#include <dynamics/ConstantForceField.hpp>
#include <dynamics/SpringForceField.hpp>
#include <dynamics/SpringListRenderable.hpp>
#include <dynamics/ControlledForceFieldRenderable.hpp>
#include <dynamics/EulerExplicitSolver.hpp>

//Light
#include <lighting/LightedMeshRenderable.hpp>
#include <lighting/LightedCubeRenderable.hpp>
#include <lighting/LightedCylinderRenderable.hpp>
#include <lighting/LightedSphereRenderable.hpp>
#include <lighting/LightedParticleRenderable.hpp>
#include <lighting/LightedControlledParticleRenderable.hpp>
#include <lighting/DirectionalLightRenderable.hpp>
#include <lighting/PointLightRenderable.hpp>
#include <lighting/SpotLightRenderable.hpp>

//Texturing
#include <texturing/CubeMapRenderable.hpp>
#include <texturing/TexturedCubeRenderable.hpp>
#include <texturing/TexturedLightedMeshRenderable.hpp>
#include <texturing/TexturedLightedCubeRenderable.hpp>
#include <texturing/TexturedLightedCylinderRenderable.hpp>
#include <texturing/TexturedLightedSphereRenderable.hpp>
#include <texturing/TexturedLightedParticleRenderable.hpp>
#include <texturing/TexturedLightedControlledParticleRenderable.hpp>

#include <iostream>
#include <iomanip>

const bool indexed = false; // indexed version already implemented
const unsigned int strips = 10u; // number of strips
const unsigned int slices = 50u; // number of slices
const bool vertex_normals = true; // use vertex normals ? else triangle normals

float stiffness = 8e3, l0 = 4.0, damping = 50.0;

void createAnimateRobox(Viewer& viewer, ShaderProgramPtr& shader, MaterialPtr& mat, DynamicSystemPtr& system, DynamicSystemRenderablePtr &systemRenderable);
void createPunchingBag(Viewer& viewer, ShaderProgramPtr& shader, MaterialPtr& mat, DynamicSystemPtr& system, DynamicSystemRenderablePtr& systemRenderable);
void createPlane(Viewer& viewer, ShaderProgramPtr& shader, MaterialPtr& mat);
void createEnvironment(Viewer& viewer, ShaderProgramPtr& shader, MaterialPtr& mat);
void createLight(Viewer& viewer, ShaderProgramPtr& shader);
void createCubeMap(Viewer& viewer);
void camera(Viewer& viewer);

void initialize_scene( Viewer& viewer )
{
    ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>("../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
                                                                  "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
//    ShaderProgramPtr phongShader = std::make_shared<ShaderProgram>( "../../sfmlGraphicsPipeline/shaders/phongVertex.glsl",
//                                                                    "../../sfmlGraphicsPipeline/shaders/phongFragment.glsl");
    ShaderProgramPtr textureShader = std::make_shared<ShaderProgram>(   "../../sfmlGraphicsPipeline/shaders/textureVertex.glsl",
                                                                    "../../sfmlGraphicsPipeline/shaders/textureFragment.glsl");
    viewer.addShaderProgram( flatShader );
    //    viewer.addShaderProgram( phongShader );
    viewer.addShaderProgram( textureShader );


    auto mat = std::make_shared<Material>(glm::vec3(0), glm::vec3(1), glm::vec3(0), 100.0f);

    //Frame
    FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
    viewer.addRenderable(frame);

    //Initialize a dynamic system (Solver, Time step, Restitution coefficient)
    DynamicSystemPtr system = std::make_shared<DynamicSystem>();
    system->setRestitution(0.0);
    EulerExplicitSolverPtr solver = std::make_shared<EulerExplicitSolver>();
    system->setSolver(solver);
    system->setDt(0.01);

    //Create a renderable associated to the dynamic system
    //This renderable is responsible for calling DynamicSystem::computeSimulationStep() in the animate() function
    //It is also responsible for some key/mouse events
    DynamicSystemRenderablePtr systemRenderable = std::make_shared<DynamicSystemRenderable>(system);
    viewer.addRenderable(systemRenderable);

    createAnimateRobox(viewer, textureShader, mat, system, systemRenderable);
    createPlane(viewer, textureShader, mat);
    createEnvironment(viewer, textureShader, mat);
    createLight(viewer, flatShader);
    createCubeMap(viewer);
    camera(viewer);

    viewer.startAnimation();
}

void createAnimateRobox(Viewer& viewer, ShaderProgramPtr& shader, MaterialPtr& mat, DynamicSystemPtr& system, DynamicSystemRenderablePtr &systemRenderable){
    std::string metal_rouille = "./../../sfmlGraphicsPipeline/textures/metal_rouille.png";
    std::string metal_raye = "./../../sfmlGraphicsPipeline/textures/rouille.png";

    //Create Renderables
    TexturedLightedCylinderRenderablePtr root = std::make_shared<TexturedLightedCylinderRenderable>(shader, mat, metal_rouille, slices, vertex_normals);
    root -> setLocalTransform(getScaleMatrix(1, 1, 2));
    root -> setGlobalTransform(getTranslationMatrix(0,4,0) * getRotationMatrix(M_PI/2, 1, 0, 0));
    //root->setLocalTransform( GeometricTransformation(glm::vec3(0,4,0), glm::angleAxis(M_PIf/2, glm::vec3(1,0,0)), glm::vec3(1,1,2)).toMatrix() );

    TexturedLightedSphereRenderablePtr right_shoulder = std::make_shared<TexturedLightedSphereRenderable>(shader, mat, metal_raye, strips, slices, vertex_normals);
    TexturedLightedSphereRenderablePtr left_shoulder = std::make_shared<TexturedLightedSphereRenderable>(shader, mat, metal_raye, strips, slices, vertex_normals);
    left_shoulder->setWrapOptions(2);
    left_shoulder -> setLocalTransform(getScaleMatrix(0.25, 0.25, 0.25));
    left_shoulder -> setGlobalTransform(getTranslationMatrix(-1,0,0));
    right_shoulder->setWrapOptions(2);
    right_shoulder -> setLocalTransform(getScaleMatrix(0.25, 0.25, 0.25));
    right_shoulder -> setGlobalTransform(getTranslationMatrix(1,0,0));

    TexturedLightedCylinderRenderablePtr right_arm = std::make_shared<TexturedLightedCylinderRenderable>(shader, mat, metal_rouille, slices, vertex_normals);
    TexturedLightedCylinderRenderablePtr left_arm= std::make_shared<TexturedLightedCylinderRenderable>(shader, mat, metal_rouille, slices, vertex_normals);
    left_arm -> setLocalTransform(getScaleMatrix(0.25, 0.25, 1));
    left_arm -> setGlobalTransform(getTranslationMatrix(-0.25,0,0) * getRotationMatrix(M_PI/2, 0, -1, 0));
    right_arm -> setLocalTransform(getScaleMatrix(0.25, 0.25, 1));
    right_arm -> setGlobalTransform(getTranslationMatrix(0.25,0,0) * getRotationMatrix(M_PI/2, 0, 1, 0));

    TexturedLightedSphereRenderablePtr right_elbow = std::make_shared<TexturedLightedSphereRenderable>(shader, mat, metal_raye, strips, slices, vertex_normals);
    TexturedLightedSphereRenderablePtr left_elbow = std::make_shared<TexturedLightedSphereRenderable>(shader, mat, metal_raye, strips, slices, vertex_normals);
    left_elbow->setWrapOptions(2);
    left_elbow -> setLocalTransform(getScaleMatrix(0.25, 0.25, 0.25));
    left_elbow -> setGlobalTransform(getTranslationMatrix(0,0,1.25));
    right_elbow->setWrapOptions(2);
    right_elbow -> setLocalTransform(getScaleMatrix(0.25, 0.25, 0.25));
    right_elbow -> setGlobalTransform(getTranslationMatrix(0,0,1.25));

    TexturedLightedCylinderRenderablePtr right_front_arm = std::make_shared<TexturedLightedCylinderRenderable>(shader, mat, metal_rouille, slices, vertex_normals);
    TexturedLightedCylinderRenderablePtr left_front_arm = std::make_shared<TexturedLightedCylinderRenderable>(shader, mat, metal_rouille, slices, vertex_normals);
    left_front_arm -> setLocalTransform(getScaleMatrix(0.25, 0.25, 1));
    left_front_arm -> setGlobalTransform(getTranslationMatrix(0,0,0.25));
    right_front_arm -> setLocalTransform(getScaleMatrix(0.25, 0.25, 1));
    right_front_arm -> setGlobalTransform(getTranslationMatrix(0,0,0.25));

    //Initialize a particle with position, velocity, mass and radius and add it to the system
    glm::vec3 px = glm::vec3(0,0,0);
    glm::vec3 pv = glm::vec3(0,0,0);
    float pr = 0.5;
    float pm = 10.0;
    ParticlePtr right_hand_particule = std::make_shared<Particle>( px, pv, pm, pr);
    system->addParticle( right_hand_particule );
    ParticlePtr left_hand_particule = std::make_shared<Particle>( px, pv, pm, pr);
    system->addParticle( left_hand_particule );

    TexturedLightedControlledParticleRenderablePtr right_hand = std::make_shared<TexturedLightedControlledParticleRenderable>(shader, right_hand_particule, mat, metal_raye);
    HierarchicalRenderable::addChild( systemRenderable, right_hand );
    right_hand->setWrapOptions(2);
    right_hand -> setGlobalTransform(getTranslationMatrix(0,0,1.5));
    TexturedLightedControlledParticleRenderablePtr left_hand = std::make_shared<TexturedLightedControlledParticleRenderable>(shader, left_hand_particule, mat, metal_raye);
    HierarchicalRenderable::addChild( systemRenderable, left_hand );
    left_hand->setWrapOptions(2);
    left_hand -> setGlobalTransform(getTranslationMatrix(0,0,1.5));

//    SphereMeshRenderablePtr right_hand = std::make_shared<SphereMeshRenderable>(shader, indexed, strips, slices, vertex_normals);
//    SphereMeshRenderablePtr left_hand = std::make_shared<SphereMeshRenderable>(shader, indexed, strips, slices, vertex_normals);
//    left_hand -> setLocalTransform(getScaleMatrix(0.5, 0.5, 0.5));
//    left_hand -> setGlobalTransform(getTranslationMatrix(0,0,1.5));
//    right_hand -> setLocalTransform(getScaleMatrix(0.5, 0.5, 0.5));
//    right_hand -> setGlobalTransform(getTranslationMatrix(0,0,1.5));

    TexturedLightedCylinderRenderablePtr neck = std::make_shared<TexturedLightedCylinderRenderable>(shader, mat, metal_rouille, slices, vertex_normals);
    neck -> setLocalTransform(getScaleMatrix(0.25, 0.25, 0.5));
    neck -> setGlobalTransform(getTranslationMatrix(0,0,-0.5));

    TexturedLightedSphereRenderablePtr head = std::make_shared<TexturedLightedSphereRenderable>(shader, mat, metal_raye, strips, slices, vertex_normals);
    head->setWrapOptions(2);
    head -> setLocalTransform(getScaleMatrix(0.75, 0.75, 0.75));
    head -> setGlobalTransform(getTranslationMatrix(0,0,-0.5));

    HierarchicalRenderable::addChild(root, neck);
    HierarchicalRenderable::addChild(neck, head);
    HierarchicalRenderable::addChild(root, right_shoulder);
    HierarchicalRenderable::addChild(root, left_shoulder);
    HierarchicalRenderable::addChild(right_shoulder, right_arm);
    HierarchicalRenderable::addChild(left_shoulder, left_arm);
    HierarchicalRenderable::addChild(right_arm, right_elbow);
    HierarchicalRenderable::addChild(left_arm, left_elbow);
    HierarchicalRenderable::addChild(right_elbow, right_front_arm);
    HierarchicalRenderable::addChild(left_elbow, left_front_arm);
    HierarchicalRenderable::addChild(right_front_arm, right_hand);
    HierarchicalRenderable::addChild(left_front_arm, left_hand);

    viewer.addRenderable(root);

    //Tronc----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    root->addGlobalTransformKeyframe(GeometricTransformation(getTranslationMatrix(0,4,0) * getRotationMatrix(M_PIf/2.5,1,0,0)), 0.0);
    root->addGlobalTransformKeyframe(GeometricTransformation(getTranslationMatrix(0,4,0) * getRotationMatrix(M_PIf/2.5,1,0,0) * getRotationMatrix(M_PIf/12,0,0,1)), 0.2);
    root->addGlobalTransformKeyframe(GeometricTransformation(getTranslationMatrix(0,4,0) * getRotationMatrix(M_PIf/2.5,1,0,0) * getRotationMatrix(0,0,0,1)), 0.4);
    root->addGlobalTransformKeyframe(GeometricTransformation(getTranslationMatrix(0,4,-0.5) * getRotationMatrix(M_PIf/2.5,1,0,0) * getRotationMatrix(-M_PIf/12,0,0,1)), 0.6);
    root->addGlobalTransformKeyframe(GeometricTransformation(getTranslationMatrix(0,4,-0.5) * getRotationMatrix(M_PIf/2.5,1,0,0) * getRotationMatrix(0,0,0,1)), 0.8);
    root->addGlobalTransformKeyframe(GeometricTransformation(getTranslationMatrix(0,4,-0.5) * getRotationMatrix(M_PIf/2.5,1,0,0) * getRotationMatrix(0,0,0,1)), 1.6);

    //Bras gauche (jab 0.4 sec) puis ( uppercut 0.4 sec )---------------------------------------------------------------------------------------------------------------------------------------------
    left_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/3,1,0,0) * getRotationMatrix(M_PIf/8,0,-1,0) * getTranslationMatrix(0,0,0.25)), 0.0);
    left_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(2*M_PIf/3,1,0,0) * getRotationMatrix(M_PIf/8,0,-1,0) * getTranslationMatrix(0,0,0.25)), 0.2);
    left_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/3,1,0,0) * getRotationMatrix(M_PIf/8,0,-1,0) * getTranslationMatrix(0,0,0.25)), 0.4);
    left_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/3,1,0,0) * getRotationMatrix(M_PIf/8,0,-1,0) * getTranslationMatrix(0,0,0.25)), 0.6);
    left_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(0,0,1,0) * getRotationMatrix(0,0,-1,0) * getTranslationMatrix(0,0,0.25)), 0.8);
    left_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,1,0,0) * getRotationMatrix(0,0,-1,0) * getTranslationMatrix(0,0,0.25)), 1.0);
    left_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/3,1,0,0) * getRotationMatrix(M_PIf/8,0,-1,0) * getTranslationMatrix(0,0,0.25)), 1.4);
    left_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/3,1,0,0) * getRotationMatrix(M_PIf/8,0,-1,0) * getTranslationMatrix(0,0,0.25)), 1.6);

    left_front_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,1,0,0) * getRotationMatrix(M_PIf/8,0,1,0) * getTranslationMatrix(0,0,0.25)), 0.0);
    left_front_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/8,1,0,0) * getRotationMatrix(M_PIf/8,0,1,0) * getTranslationMatrix(0,0,0.25)), 0.2);
    left_front_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,1,0,0) * getRotationMatrix(M_PIf/8,0,1,0) * getTranslationMatrix(0,0,0.25)), 0.4);
    left_front_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,1,0,0) * getRotationMatrix(M_PIf/8,0,1,0) * getTranslationMatrix(0,0,0.25)), 0.6);
    left_front_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,1,0,0) * getRotationMatrix(0,0,1,0) * getTranslationMatrix(0,0,0.25)), 0.8);
    left_front_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,1,0,0) * getRotationMatrix(0,0,1,0) * getTranslationMatrix(0,0,0.25)), 1.0);
    left_front_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,1,0,0) * getRotationMatrix(M_PIf/8,0,1,0) * getTranslationMatrix(0,0,0.25)), 1.4);
    left_front_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,1,0,0) * getRotationMatrix(M_PIf/8,0,1,0) * getTranslationMatrix(0,0,0.25)), 1.6);


    //Bras droit (crochet 0.4s)---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    right_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/3,1,0,0) * getRotationMatrix(-M_PIf/8,0,-1,0) * getTranslationMatrix(0,0,0.25)), 0.0);
    right_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/3,1,0,0) * getRotationMatrix(-M_PIf/8,0,-1,0) * getTranslationMatrix(0,0,0.25)), 0.2);
    right_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,0,1,0) * getRotationMatrix(-M_PIf/8,0,-1,0) * getTranslationMatrix(0,0,0.25)), 0.4);
    right_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,0,1,0) * getRotationMatrix(M_PIf/4,1,0,0) * getRotationMatrix(-M_PIf/8,0,-1,0) * getTranslationMatrix(0,0,0.25)), 0.6);
    right_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/3,1,0,0) * getRotationMatrix(-M_PIf/8,0,-1,0) * getTranslationMatrix(0,0,0.25)), 0.8);
    right_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/3,1,0,0) * getRotationMatrix(-M_PIf/8,0,-1,0) * getTranslationMatrix(0,0,0.25)), 1.6);

    right_front_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,1,0,0) * getRotationMatrix(-M_PIf/8,0,1,0) * getTranslationMatrix(0,0,0.25)), 0.0);
    right_front_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,1,0,0) * getRotationMatrix(-M_PIf/10,0,1,0) * getTranslationMatrix(0,0,0.25)), 0.2);
    right_front_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,1,0,0) * getRotationMatrix(M_PIf/10,0,1,0) * getTranslationMatrix(0,0,0.25)), 0.4);
    right_front_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,1,0,0) * getRotationMatrix(M_PIf/8,0,1,0) * getTranslationMatrix(0,0,0.25)), 0.6);
    right_front_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,1,0,0) * getRotationMatrix(-M_PIf/8,0,1,0) * getTranslationMatrix(0,0,0.25)), 0.8);
    right_front_arm->addGlobalTransformKeyframe(GeometricTransformation(getRotationMatrix(M_PIf/2,1,0,0) * getRotationMatrix(-M_PIf/8,0,1,0) * getTranslationMatrix(0,0,0.25)), 1.6);
}

void createPunchingBag(Viewer& viewer, ShaderProgramPtr& shader, MaterialPtr& mat, DynamicSystemPtr& system, DynamicSystemRenderablePtr &systemRenderable){

    std::list<SpringForceFieldPtr> springForceFields;
    glm::vec3 px,pv;
    float pm, pr;

    //Initialize a particle with position, velocity, mass and radius and add it to the system
    px = glm::vec3(0,8,-4);
    pv = glm::vec3(0,0,0);
    pr = 0.5;
    pm = 10.0;
    ParticlePtr upFixedParticle = std::make_shared<Particle>( px, pv, pm, pr);
    system->addParticle( upFixedParticle );
    upFixedParticle -> setFixed(true);

    px = glm::vec3(0,4,-4);
    pr = 2.0;
    pm = 2.0;
    ParticlePtr punchingBagParticle = std::make_shared<Particle>( px, pv, pm, pr);
    system->addParticle( punchingBagParticle );

    px = glm::vec3(0,0,-4);
    pr = 0.5;
    ParticlePtr downFixedParticle = std::make_shared<Particle>( px, pv, pm, pr);
    system->addParticle( downFixedParticle );
    downFixedParticle -> setFixed(true);


    SpringForceFieldPtr spring1 = std::make_shared<SpringForceField>( upFixedParticle, punchingBagParticle, stiffness, l0, damping );
    springForceFields.push_back(spring1);
    system->addForceField( spring1 );
    SpringForceFieldPtr spring2 = std::make_shared<SpringForceField>( punchingBagParticle, downFixedParticle, stiffness, l0, damping );
    springForceFields.push_back(spring2);
    system->addForceField( spring2 );

    //Initialize a force field that apply to all the particles of the system to simulate gravity
    //Add it to the system as a force field
    ConstantForceFieldPtr gravityForceField = std::make_shared<ConstantForceField>(system->getParticles(), DynamicSystem::gravity  );
    system->addForceField( gravityForceField );

    //Initialize a force field that apply to all the particles of the system to simulate vicosity (air friction)
    float dampingCoefficient = 5;
    DampingForceFieldPtr dampingForceField = std::make_shared<DampingForceField>(system->getParticles(), dampingCoefficient);
    system->addForceField(dampingForceField);

    //création des renderables pour les particules
    std::string punching_bag_texture = "./../../sfmlGraphicsPipeline/textures/punching_bag_texture.png";
    TexturedLightedParticleRenderablePtr upFixed = std::make_shared<TexturedLightedParticleRenderable>(shader, upFixedParticle, mat, punching_bag_texture);
    upFixed->setWrapOptions(2);
    HierarchicalRenderable::addChild(systemRenderable, upFixed);
    TexturedLightedParticleRenderablePtr punchingBag = std::make_shared<TexturedLightedParticleRenderable>(shader, punchingBagParticle, mat, punching_bag_texture);
    punchingBag->setWrapOptions(2);
    HierarchicalRenderable::addChild(systemRenderable, punchingBag);
    TexturedLightedParticleRenderablePtr downFixed = std::make_shared<TexturedLightedParticleRenderable>(shader, downFixedParticle, mat, punching_bag_texture);
    downFixed->setWrapOptions(2);
    HierarchicalRenderable::addChild(systemRenderable, downFixed);

    //Create a springListRenderable to efficiently visualize the springs of the system
    SpringListRenderablePtr springsRenderable = std::make_shared<SpringListRenderable>(shader, springForceFields);
    HierarchicalRenderable::addChild( systemRenderable, springsRenderable );

    //Display gravity
//    ConstantForceFieldRenderablePtr gravityRenderable = std::make_shared<ConstantForceFieldRenderable>(shader, gravityForceField);
//    HierarchicalRenderable::addChild( systemRenderable, gravityRenderable );
}


void createPlane(Viewer& viewer, ShaderProgramPtr& shader, MaterialPtr& mat){
    std::string ground_texture = "./../../sfmlGraphicsPipeline/textures/desert_ground.png";

    auto ground = std::make_shared<TexturedLightedCubeRenderable>(shader, mat, ground_texture);
    ground->setWrapOptions(2);
    ground->setLocalTransform(getScaleMatrix(200,.2,200));
    viewer.addRenderable(ground);
}

void createEnvironment(Viewer& viewer, ShaderProgramPtr& shader, MaterialPtr& mat){
    const std::string tree_path = "../../sfmlGraphicsPipeline/meshes/dead_tree2_obj.obj";
    std::string tree_texture = "./../../sfmlGraphicsPipeline/textures/tree_BaseColor.png";

    auto tree0 = std::make_shared<TexturedLightedMeshRenderable>(shader, tree_path, mat, tree_texture);
    tree0 -> setLocalTransform(getScaleMatrix(4));
    tree0 -> setGlobalTransform(getTranslationMatrix(31,0,-14));

    auto tree1 = std::make_shared<TexturedLightedMeshRenderable>(shader, tree_path, mat, tree_texture);
    tree1 -> setLocalTransform(getScaleMatrix(2));
    tree1 -> setGlobalTransform(getTranslationMatrix(-15,0,19));

    const std::string container_path = "../../sfmlGraphicsPipeline/meshes/container.obj";
    std::string container_texture = "./../../sfmlGraphicsPipeline/textures/container_BaseColor.png";
    auto container = std::make_shared<TexturedLightedMeshRenderable>(shader, container_path,mat, container_texture);
    container->setLocalTransform(getScaleMatrix(4));
    container->setGlobalTransform(getTranslationMatrix(8,4,15) * getRotationMatrix(M_PIf/6, 0,-1,0));

    viewer.addRenderable(tree0);
    viewer.addRenderable(tree1);
    viewer.addRenderable(container);
}

void createCubeMap(Viewer& viewer){
    viewer.getCamera().setViewMatrix( glm::lookAt( glm::vec3(1, 1, 1 ), glm::vec3(0, 0, 0), glm::vec3( 0, 1, 0 ) ) );
    ShaderProgramPtr cubeMapShader = std::make_shared<ShaderProgram>(  "../../sfmlGraphicsPipeline/shaders/cubeMapVertex.glsl",
                                                                       "../../sfmlGraphicsPipeline/shaders/cubeMapFragment.glsl");
    viewer.addShaderProgram(cubeMapShader);

    std::string cubemap_dir = "../../sfmlGraphicsPipeline/textures/skybox3";
    auto cubemap = std::make_shared<CubeMapRenderable>(cubeMapShader, cubemap_dir);

    viewer.addRenderable(cubemap);
}

void createLight(Viewer& viewer, ShaderProgramPtr& shader){
    //DirLight
    glm::vec3 d_ambient(1.0,1.0,1.0), d_diffuse(1.0,1.0,1.0), d_specular(1.0,1.0,1.0);
    auto dir_light = std::make_shared<DirectionalLight>(glm::vec3(1,0,0), d_ambient, d_diffuse, d_specular);
    dir_light->setLocalTransform(getTranslationMatrix(0, 10, 0) * getRotationMatrix(M_PI/4, -1,0,0) * getRotationMatrix(M_PI/5, 0,1,0));
    viewer.addDirectionalLight(dir_light);

    //SpotLight
    glm::vec3 s_position(-100,65,55), s_spotDirection = glm::normalize(glm::vec3(0.0,-1.0,1.0));
    glm::vec3 s_ambient(0.6,0.6,0.6), s_diffuse(0.6,0.6,0.6), s_specular(0.6,0.6,0.6);
    float s_constant=1.0, s_linear=0.0, s_quadratic=0.0;
    float s_innerCutOff=std::cos(glm::radians(20.0f)), s_outerCutOff=std::cos(glm::radians(40.0f));
    SpotLightPtr spotLight = std::make_shared<SpotLight>(s_position, s_spotDirection,
                                                         s_ambient, s_diffuse, s_specular,
                                                         s_constant, s_linear, s_quadratic,
                                                         s_innerCutOff, s_outerCutOff);
    viewer.addSpotLight(spotLight);
}

void camera(Viewer& viewer){
    //lookAt(position des yeux, position de la cible, (0,1,0))
    viewer.getCamera().addGlobalTransformKeyframe(lookAtModel(glm::vec3(-10,4,-10), glm::vec3(0,4,0), glm::vec3(0,0,-1)), 0.0);
    viewer.getCamera().addGlobalTransformKeyframe(lookAtModel(glm::vec3(0,6,-20), glm::vec3(0,6,0), glm::vec3(0,0,-1)), 4.0);

}



int main()
{
    Viewer viewer(1280,720, glm::vec4(0.8, 0.8, 0.8, 1.0));
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