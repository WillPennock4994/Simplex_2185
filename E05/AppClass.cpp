#include "AppClass.h"
void Application::InitVariables(void)
{
	//init the mesh
	m_pMesh = new MyMesh();
	//m_pMesh->GenerateCube(1.0f, C_WHITE);
	m_pMesh->GenerateCube(1.0f, C_BLACK);
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
	
	//matrix4 m4Scale = glm::scale(IDENTITY_M4, vector3(1.0f,1.0f,1.0f));
	static float value = 0.0f;
	matrix4 m4Translate = glm::translate(IDENTITY_M4, vector3(value, 1.0f, 1.0f));
	static float changeVal = .1f;
	
	value += changeVal;
	if (value > 5.0f|| value<-5.0f)
	{
		changeVal = -1.0f*changeVal;
		//value = -value;
	}

	//matrix4 m4Model = m4Translate * m4Scale;
	matrix4 m4Model = IDENTITY_M4 * m4Translate;

	m_pMesh->Render(m4Projection, m4View, m4Model);
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(0.0f + value, -1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(0.0f + value, 3.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(0.0f + value, 5.0f, 1.0f)));

	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(2.0f + value, 1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(4.0f + value, 1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(6.0f + value, 1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(8.0f + value, 1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(10.0f + value, 1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(2.0f + value, 3.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(2.0f + value, 5.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(2.0f + value, -1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(2.0f + value, -5.0f, 1.0f)));

	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(4.0f + value, 5.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(4.0f + value, 7.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(4.0f + value, -1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(4.0f + value, -5.0f, 1.0f)));

	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(6.0f + value, 3.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(6.0f + value, 5.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(6.0f + value, 9.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(6.0f + value, -1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(6.0f + value, -3.0f, 1.0f)));

	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(8.0f + value, 3.0f, 1.0f)));

	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(10.0f + value, -1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(10.0f + value, -3.0f, 1.0f)));

	//left
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-2.0f + value, 1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-4.0f + value, 1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-6.0f + value, 1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-8.0f + value, 1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-10.0f + value, 1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-2.0f + value, 3.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-2.0f + value, 5.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-2.0f + value, -1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-2.0f + value, -5.0f, 1.0f)));

	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-4.0f + value, 5.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-4.0f + value, 7.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-4.0f + value, -1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-4.0f + value, -5.0f, 1.0f)));

	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-6.0f + value, 3.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-6.0f + value, 5.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-6.0f + value, 9.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-6.0f + value, -1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-6.0f + value, -3.0f, 1.0f)));

	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-8.0f + value, 3.0f, 1.0f)));

	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-10.0f + value, -1.0f, 1.0f)));
	m_pMesh->Render(m4Projection, m4View, m4Model + translate(IDENTITY_M4, vector3(-10.0f + value, -3.0f, 1.0f)));

	//m_pMesh->Render(m4Projection, m4View, m4Model);
	
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