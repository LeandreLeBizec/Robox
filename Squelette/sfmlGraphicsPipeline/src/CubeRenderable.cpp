#include "./../include/CubeRenderable.hpp"
#include "./../include/gl_helper.hpp"
#include "./../include/log.hpp"
#include "./../include/Utils.hpp"

#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>


CubeRenderable::CubeRenderable(ShaderProgramPtr shaderProgram)
  : Renderable(shaderProgram), m_vBuffer(0), m_cBuffer(0)
{
	// Build the geometry : just a simple triangle for now
	m_positions.push_back(glm::vec3(-1, -1, -1));
	m_positions.push_back(glm::vec3(-1, -1, 1));
	m_positions.push_back(glm::vec3(-1, 1, 1));

	m_positions.push_back(glm::vec3(1, 1, -1));
	m_positions.push_back(glm::vec3(-1, -1, -1));
	m_positions.push_back(glm::vec3(-1, 1, -1));

	m_positions.push_back(glm::vec3(1, -1, 1));
	m_positions.push_back(glm::vec3(-1, -1, -1));
	m_positions.push_back(glm::vec3(1, -1, -1));

	m_positions.push_back(glm::vec3(1, 1, -1));
	m_positions.push_back(glm::vec3(1, -1, -1));
	m_positions.push_back(glm::vec3(-1, -1, -1));

	m_positions.push_back(glm::vec3(-1, -1, -1));
	m_positions.push_back(glm::vec3(-1, 1, 1));
	m_positions.push_back(glm::vec3(-1, 1, -1));

	m_positions.push_back(glm::vec3(1, -1, 1));
	m_positions.push_back(glm::vec3(-1, -1, 1));
	m_positions.push_back(glm::vec3(-1, -1, -1));

	m_positions.push_back(glm::vec3(-1, 1, 1));
	m_positions.push_back(glm::vec3(-1, -1, 1));
	m_positions.push_back(glm::vec3(1, -1, 1));

	m_positions.push_back(glm::vec3(1, 1, 1));
	m_positions.push_back(glm::vec3(1, -1, -1));
	m_positions.push_back(glm::vec3(1, 1, -1));

	m_positions.push_back(glm::vec3(1, -1, -1));
	m_positions.push_back(glm::vec3(1, 1, 1));
	m_positions.push_back(glm::vec3(1, -1, 1));

	m_positions.push_back(glm::vec3(1, 1, 1));
	m_positions.push_back(glm::vec3(1, 1, -1));
	m_positions.push_back(glm::vec3(-1, 1, -1));

	m_positions.push_back(glm::vec3(1, 1, 1));
	m_positions.push_back(glm::vec3(-1, 1, -1));
	m_positions.push_back(glm::vec3(-1, 1, 1));

	m_positions.push_back(glm::vec3(1, 1, 1));
	m_positions.push_back(glm::vec3(-1, 1, 1));
	m_positions.push_back(glm::vec3(1, -1, 1));
	
	
	//Color
	m_colors.push_back(glm::vec4(1.0, 0, 0, 1.0)); //(r,g,b,a)
	m_colors.push_back(glm::vec4(1.0, 0, 0, 1.0));
	m_colors.push_back(glm::vec4(1.0, 0, 0, 1.0));

	m_colors.push_back(glm::vec4(0, 1.0, 0, 1.0)); //(r,g,b,a)
	m_colors.push_back(glm::vec4(0, 1.0, 0, 1.0));
	m_colors.push_back(glm::vec4(0, 1.0, 0, 1.0));

	m_colors.push_back(glm::vec4(0, 0, 1.0, 1.0)); //(r,g,b,a)
	m_colors.push_back(glm::vec4(0, 0, 1.0, 1.0));
	m_colors.push_back(glm::vec4(0, 0, 1.0, 1.0));

	m_colors.push_back(glm::vec4(1.0, 1.0, 0, 1.0)); //(r,g,b,a)
	m_colors.push_back(glm::vec4(1.0, 1.0, 0, 1.0));
	m_colors.push_back(glm::vec4(1.0, 1.0, 0, 1.0));

	m_colors.push_back(glm::vec4(1.0, 0, 1.0, 1.0)); //(r,g,b,a)
	m_colors.push_back(glm::vec4(1.0, 0, 1.0, 1.0));
	m_colors.push_back(glm::vec4(1.0, 0, 1.0, 1.0));

	m_colors.push_back(glm::vec4(0.5, 0.5, 0, 1.0)); //(r,g,b,a)
	m_colors.push_back(glm::vec4(0.5, 0.5, 0, 1.0));
	m_colors.push_back(glm::vec4(0.5, 0.5, 0, 1.0));

	m_colors.push_back(glm::vec4(0, 1.0, 1.0, 1.0)); //(r,g,b,a)
	m_colors.push_back(glm::vec4(0, 1.0, 1.0, 1.0));
	m_colors.push_back(glm::vec4(0, 1.0, 1.0, 1.0));

	m_colors.push_back(glm::vec4(0, 0.5, 0.5, 1.0)); //(r,g,b,a)
	m_colors.push_back(glm::vec4(0, 0.5, 0.5, 1.0));
	m_colors.push_back(glm::vec4(0, 0.5, 0.5, 1.0));

	m_colors.push_back(glm::vec4(0.5, 0, 0.5, 1.0)); //(r,g,b,a)
	m_colors.push_back(glm::vec4(0.5, 0, 0.5, 1.0));
	m_colors.push_back(glm::vec4(0.5, 0, 0.5, 1.0));

	m_colors.push_back(glm::vec4(0.7, 0.3, 0, 1.0)); //(r,g,b,a)
	m_colors.push_back(glm::vec4(0.7, 0.3, 0, 1.0));
	m_colors.push_back(glm::vec4(0.7, 0.3, 0, 1.0));

	m_colors.push_back(glm::vec4(0.9, 0.2, 0.5, 1.0)); //(r,g,b,a)
	m_colors.push_back(glm::vec4(0.9, 0.2, 0.5, 1.0));
	m_colors.push_back(glm::vec4(0.9, 0.2, 0.5, 1.0));

	m_colors.push_back(glm::vec4(0.8, 0.1, 0.7, 1.0)); //(r,g,b,a)
	m_colors.push_back(glm::vec4(0.8, 0.1, 0.7, 1.0));
	m_colors.push_back(glm::vec4(0.8, 0.1, 0.7, 1.0));

	// Set the model matrix to identity
	m_model = glm::mat4(1.0);
	//m_model = glm::translate(m_model, glm::vec3(2,0,0));
	//m_model = glm::rotate(m_model, 90.0f, glm::vec3(0,1,0));

    /*
	glm::mat4 translateTransfo = glm::translate(glm::mat4(), glm::vec3(-2,0,0));
	glm::mat4 rotateTransfo = glm::rotate(m_model, -150.0f, glm::vec3(0,1,0));
	m_model = translateTransfo * rotateTransfo;
    */
	//Create buffers
	glGenBuffers(1, &m_vBuffer); //vertices

	//Activate buffer and send data to the graphics card
	glBindBuffer(GL_ARRAY_BUFFER, m_vBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_positions.size()*sizeof(glm::vec3), m_positions.data(), GL_STATIC_DRAW);

	// Exo 1
	glGenBuffers(1, &m_cBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_cBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_colors.size()*sizeof(glm::vec4), m_colors.data(), GL_STATIC_DRAW);

}

void CubeRenderable::do_draw()
{
	// Get the identifier ( location ) of the uniform modelMat in the shader program
	int modelLocation = m_shaderProgram->getUniformLocation("modelMat");
	// Send the data corresponding to this identifier on the GPU
	glUniformMatrix4fv( modelLocation , 1, GL_FALSE , glm::value_ptr( m_model ));

	// Get the identifier of the attribute vPosition in the shader program
	int positionLocation = m_shaderProgram->getAttributeLocation("vPosition");
	// Activate the attribute array at this location
	glEnableVertexAttribArray( positionLocation );
	// Bind the position buffer on the GL_ARRAY_BUFFER target
	glBindBuffer( GL_ARRAY_BUFFER , m_vBuffer );
	// Specify the location and the format of the vertex position attribute
	glVertexAttribPointer( positionLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	//Exo1
	int colorLocation = m_shaderProgram->getAttributeLocation("vColor");
	glEnableVertexAttribArray( colorLocation );
	glBindBuffer( GL_ARRAY_BUFFER , m_cBuffer );
	glVertexAttribPointer( colorLocation, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// Draw the triangles
	glDrawArrays( GL_TRIANGLES, 0, m_positions.size());

	
	// Release the vertex attribute array
	glDisableVertexAttribArray( positionLocation );

	//Exo1
	glDisableVertexAttribArray( colorLocation );
}

CubeRenderable::~CubeRenderable()
{
  glcheck(glDeleteBuffers(1, &m_vBuffer));
	//Exo1
	glcheck(glDeleteBuffers(1, &m_cBuffer));
}
