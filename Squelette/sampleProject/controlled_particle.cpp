#include <ShaderProgram.hpp>
#include <Viewer.hpp>

#include <ShaderProgram.hpp>

#include <QuadMeshRenderable.hpp>
#include <FrameRenderable.hpp>

#include <dynamics/DynamicSystemRenderable.hpp>
#include <dynamics/DampingForceField.hpp>
#include <dynamics/ConstantForceField.hpp>
#include <dynamics/SpringForceField.hpp>
#include <dynamics/EulerExplicitSolver.hpp>

#include <dynamics/ParticleRenderable.hpp>
#include <dynamics/ControlledParticleRenderable.hpp>
#include <dynamics/ParticleListRenderable.hpp>
#include <dynamics/ConstantForceFieldRenderable.hpp>
#include <dynamics/SpringForceFieldRenderable.hpp>
#include <dynamics/SpringListRenderable.hpp>

void springs(Viewer& viewer, DynamicSystemPtr& system, DynamicSystemRenderablePtr &systemRenderable);

void initialize_scene( Viewer& viewer )
{
    //Set up a shader and add a 3D frame.
    ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(  "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl", 
                                                                    "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
    viewer.addShaderProgram( flatShader );
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

    //Populate the dynamic system with particles, forcefields and create renderables associated to them for visualization.
    //Uncomment only one of the following line

    springs(viewer, system, systemRenderable);

    //Finally activate animation
    viewer.startAnimation();
    // Set up a shader and add a 3D frame.
}

int main() 
{
    glm::vec4 background_color(0.7,0.7,0.7,1);
	Viewer viewer(1280,720,background_color);
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

void springs(Viewer& viewer, DynamicSystemPtr& system, DynamicSystemRenderablePtr &systemRenderable)
{
    //Initialize a shader for the following renderables
    ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(  "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
                                                                    "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
    ShaderProgramPtr debugShader = std::make_shared<ShaderProgram>(  "../../sfmlGraphicsPipeline/shaders/debugVertex.glsl",
                                                                    "../../sfmlGraphicsPipeline/shaders/debugFragment.glsl");
    ShaderProgramPtr instancedShader = std::make_shared<ShaderProgram>(  "../../sfmlGraphicsPipeline/shaders/instancedVertex.glsl",
                                                                    "../../sfmlGraphicsPipeline/shaders/instancedFragment.glsl");
    viewer.addShaderProgram( flatShader );
    viewer.addShaderProgram( instancedShader );

    //Initialize particle attributes (radius, mass)
    float pr = 0.1, pm = 10.0;
    glm::vec3 px(0.0,0.0,0.0), pv(0.0,0.0,0.0);

    //Create particles on a squared uniform grid starting at origin
    std::vector<ParticlePtr> particles;
    glm::vec3 origin(0.25,0,0.25), displacement(0.0,0.0,0.0);
    int particlePerLine = 15;
    float gridWidth=4.0, gridHeight=4.0;
    float xstep = gridWidth / (float)(particlePerLine-1);
    float zstep = gridHeight / (float)(particlePerLine-1);
    particles.resize(particlePerLine*particlePerLine);
    for( size_t i = 0; i < particlePerLine; ++ i )
    {
        for( size_t j = 0; j < particlePerLine; ++ j )
        {
            displacement = glm::vec3(i*xstep, 0.0, j*zstep);
            px = origin + displacement;
            particles[i*particlePerLine+j] = std::make_shared<Particle>( px, pv, pm, pr );
            system->addParticle( particles[i*particlePerLine+j] );
        }
    }

    //Fix particles on the y-borders
    for( size_t j = 0; j < particlePerLine; ++ j )
    {
        particles[0*particlePerLine+j]->setFixed( true );
        particles[(particlePerLine-1)*particlePerLine+j]->setFixed( true );
    }

    //Initialize springs attributes (stiffness, rest length, damping)
    float stiffness = 8e3, l0 = gridWidth / (particlePerLine-1), damping = 20;

    //Create springs between particles of the grid, horizontally and vertically
    //Store them in a list
    std::list<SpringForceFieldPtr> springForceFields;
    //Interior
    for( size_t i = 1; i < particlePerLine; ++ i )
    {
        for( size_t j = 1; j < particlePerLine; ++ j )
        {
            SpringForceFieldPtr spring1 = std::make_shared<SpringForceField>( particles[(i-1)*particlePerLine+j], particles[i*particlePerLine+j], stiffness, l0, damping );
            springForceFields.push_back(spring1);
            system->addForceField( spring1 );
            SpringForceFieldPtr spring2 = std::make_shared<SpringForceField>( particles[i*particlePerLine+(j-1)], particles[i*particlePerLine+j], stiffness, l0, damping );
            springForceFields.push_back(spring2);
            system->addForceField( spring2 );
        }
    }
    //Border case 1
    for( size_t j = 1; j < particlePerLine; ++ j )
    {
        SpringForceFieldPtr spring = std::make_shared<SpringForceField>( particles[0*particlePerLine+j], particles[0*particlePerLine+(j-1)], stiffness, l0, damping );
        springForceFields.push_back(spring);
        system->addForceField( spring );
    }
    //Border case 2
    for( size_t i = 1; i < particlePerLine; ++ i )
    {
        SpringForceFieldPtr spring = std::make_shared<SpringForceField>( particles[(i-1)*particlePerLine+0], particles[i*particlePerLine+0], stiffness, l0, damping );
        springForceFields.push_back(spring);
        system->addForceField( spring );
    }

    //Initialize a force field that apply to all the particles of the system to simulate gravity
    //Add it to the system as a force field
    ConstantForceFieldPtr gravityForceField = std::make_shared<ConstantForceField>(system->getParticles(), DynamicSystem::gravity  );
    system->addForceField( gravityForceField );

    //Initialize a force field that apply to all the particles of the system to simulate vicosity (air friction)
    float dampingCoefficient = 10;
    DampingForceFieldPtr dampingForceField = std::make_shared<DampingForceField>(system->getParticles(), dampingCoefficient);
    system->addForceField(dampingForceField);


    //Create a particleListRenderable to efficiently visualize the particles of the system
    ParticleListRenderablePtr particleListRenderable = std::make_shared<ParticleListRenderable>( instancedShader, particles);
    HierarchicalRenderable::addChild(systemRenderable, particleListRenderable);

    //Create a springListRenderable to efficiently visualize the springs of the system
    SpringListRenderablePtr springsRenderable = std::make_shared<SpringListRenderable>(flatShader, springForceFields);
    HierarchicalRenderable::addChild( systemRenderable, springsRenderable );

    //Display gravity
    ConstantForceFieldRenderablePtr gravityRenderable = std::make_shared<ConstantForceFieldRenderable>(flatShader, gravityForceField);
    HierarchicalRenderable::addChild( systemRenderable, gravityRenderable );


    // Big particle
    float big_particle_radius = 1.25;
    ParticlePtr big_particle = std::make_shared<Particle>(glm::vec3(2,-2,2), glm::vec3(0,0,0), std::numeric_limits<float>::max(), big_particle_radius);
    system->addParticle( big_particle);

    ControlledParticleRenderablePtr big_particle_renderable = std::make_shared<ControlledParticleRenderable>(debugShader, big_particle, 25, 50);
    
    float t = 1.0;
    big_particle_renderable->addGlobalTransformKeyframe(getTranslationMatrix(glm::vec3(2,-2,2)), 0*t);
    big_particle_renderable->addGlobalTransformKeyframe(getTranslationMatrix(glm::vec3(2,-0,2)), 1*t);
    big_particle_renderable->addGlobalTransformKeyframe(getTranslationMatrix(glm::vec3(2,-2,2)), 2*t);
    big_particle_renderable->addGlobalTransformKeyframe(getTranslationMatrix(glm::vec3(0, 0,2)), 3*t);
    big_particle_renderable->addGlobalTransformKeyframe(getTranslationMatrix(glm::vec3(2,0 ,2)), 4*t);
    big_particle_renderable->addGlobalTransformKeyframe(getTranslationMatrix(glm::vec3(2,-2,2)), 5*t);
    big_particle_renderable->addGlobalTransformKeyframe(getTranslationMatrix(glm::vec3(5, 1,2)), 6*t);
    big_particle_renderable->addGlobalTransformKeyframe(getTranslationMatrix(glm::vec3(4,-2,2)), 7*t);
    big_particle_renderable->addGlobalTransformKeyframe(getTranslationMatrix(glm::vec3(2,-2,2)), 8*t);

    viewer.addRenderable(big_particle_renderable);

}