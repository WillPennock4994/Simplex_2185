#include "AppClass.h"
void Application::InitVariables(void)
{
	//init the mesh
	m_pMesh = new MyMesh();
	//m_pMesh->GenerateCube(1.0f, C_WHITE);
	m_pMesh->GenerateCone(2.0f, 5.0f, 3, C_WHITE);
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();

	
	glm::quat xAxis = glm::angleAxis(glm::radians(m_v3Rotation.x), AXIS_X);//x

	glm::quat yAxis = glm::angleAxis(glm::radians(m_v3Rotation.y), AXIS_Y);//y

	glm::quat zAxis = glm::angleAxis(glm::radians(m_v3Rotation.z), AXIS_Z);//z

	glm::quat orientation = xAxis * yAxis * zAxis;//Orientation of all axis

	
	m_v3Rotation.y = 0.0f;

	m_v3Rotation.x = 0.0f;

	m_v3Rotation.z = 0.0f;

	
	m_qOrientation = orientation * m_qOrientation;//set orientation

	m_qOrientation = glm::normalize(m_qOrientation);//normalize vectors

	
	m_pMesh->Render(m4Projection, m4View, ToMatrix4(m_qOrientation));


	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();

	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();

	//draw gui
	DrawGUI();

	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	SafeDelete(m_pMesh);

	//release GUI
	ShutdownGUI();
}