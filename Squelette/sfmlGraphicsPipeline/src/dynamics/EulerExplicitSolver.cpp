#include "./../../include/dynamics/EulerExplicitSolver.hpp"

EulerExplicitSolver::EulerExplicitSolver()
{

}

EulerExplicitSolver::~EulerExplicitSolver()
{

}

void EulerExplicitSolver::do_solve(const float& dt, std::vector<ParticlePtr>& particles)
{
    for(ParticlePtr p : particles)
    {
        if(!p->isFixed())
        {
            //TODO: Implement explicit euler solver
            //Functions to use:
            //Particle::getPosition(), Particle::getVelocity(), Particle::getMass(), Particle::getForce()
            //Particle::setPosition(), Particle::setVelocity()
            glm::vec3 pos = p->getPosition();
            glm::vec3 velo = p->getVelocity();
            float m = p->getMass();
            glm::vec3 f = p->getForce();

            glm::vec3 newvelo = velo+(1/m)*dt*f;
            p->setVelocity(newvelo);
            p->setPosition(pos+dt*newvelo);
        }
    }
}
