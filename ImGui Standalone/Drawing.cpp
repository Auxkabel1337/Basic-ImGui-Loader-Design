#include "Drawing.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <TlHelp32.h>
#include <random>
#include <csignal>
#include <sstream>
#include <strsafe.h>
#include "font_awesome.cpp"
#include <chrono>
#include <ctime>
#include <iomanip>
#pragma comment(lib, "urlmon.lib")

using namespace std;

/*Window*/
LPCSTR Drawing::lpWindowName = "https://github.com/Auxkabel1337";
ImVec2 Drawing::vWindowSize = { 440, 300 };
ImGuiWindowFlags Drawing::WindowFlags = ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar;
bool Drawing::bDraw = true;

/*Clients*/
static const char* selectables[]{ " Test Release"," Test Release 2"," Test Release 3" };
static int currentselection = 0;
static int tabs = 0;

/* Login */
static char username[50] = "Username";
static char password[50] = "1234";
static bool mainForm = false;

void Drawing::Active()
{
	bDraw = true;
}

bool Drawing::isActive()
{
	return bDraw == true;
}

void Drawing::Draw()
{
	if (isActive())
	{
		ImGui::SetNextWindowSize(vWindowSize);
		ImGui::SetNextWindowBgAlpha(1.0f);
		ImGui::Begin(lpWindowName, &bDraw, WindowFlags);
		{

			if (!mainForm) {


				ImGui::SetCursorPos({ 70,135 });
				ImGui::Text(""); // If u have a API Response, draw it here

				ImGui::SetNextItemWidth(280);
				ImGui::SetCursorPos({ 70,150 });
				ImGui::InputTextWithHint("##Username", username, username, IM_ARRAYSIZE(username), ImGuiInputTextFlags_None);

				ImGui::SetNextItemWidth(280);
				ImGui::SetCursorPos({ 70,180 });
				ImGui::InputTextWithHint("##Password", password, password, IM_ARRAYSIZE(password), ImGuiInputTextFlags_Password);


				ImGui::SetCursorPos({ 70,210 });
				if (ImGui::Button(" Login", {280, 30}))
				{
					mainForm = true;
				}
			}
				

			if (mainForm)
			{
				ImGui::SetNextItemWidth(130);
				ImGui::SetCursorPos({ 10,20 });
				ImGui::ListBox("##1", &currentselection, selectables, IM_ARRAYSIZE(selectables), 3);

				static const char* cock = " Launch";
				ImVec2 windowSize = ImGui::GetWindowSize();
				ImVec2 windowPos = ImGui::GetWindowPos();
				float lineWidth = 1.5f;
				ImDrawList* drawList = ImGui::GetWindowDrawList();

				// Down
				drawList->AddLine(ImVec2(windowPos.x + 150, windowPos.y + 20), ImVec2(windowPos.x + 150, windowPos.y + 295), ImColor(45, 44, 56), lineWidth);

				// Right
				drawList->AddLine(ImVec2(windowPos.x + 6, windowPos.y + 225), ImVec2(windowPos.x + 140, windowPos.y + 225), ImColor(45, 44, 56), lineWidth);

				ImGui::SetCursorPos({ 6,234 });
				if (ImGui::Button(ICON_FA_GEAR " Settings", { 133, 25 })) {
					/*Do Settings*/
				}

				ImGui::SetCursorPos({ 6,264 });
				if (ImGui::Button(ICON_FA_XMARK " Quit", { 133, 25 })) {
					exit(1377);
				}

				// Line below the cheat name
				drawList->AddLine(ImVec2(windowPos.x + 160, windowPos.y + 70), ImVec2(windowPos.x + 420, windowPos.y + 70), ImColor(45, 44, 56), lineWidth);



				if (currentselection == 0) {

					
					ImGui::SetCursorPos({ 160,30 });
					ImGui::Text("Test Release #000000");
					ImGui::SetCursorPos({ 160,47 });
					ImGui::Text("0 days ago");
					ImGui::SetCursorPos({ 160,80 });
					ImGui::Text("[+]  Example 1");
					ImGui::SetCursorPos({ 160,95 });
					ImGui::Text("[+]  Example 2");
					ImGui::SetCursorPos({ 160,110 });
					ImGui::Text("[+]  Example 3");

				}
				if (currentselection == 1) {

					ImGui::SetCursorPos({ 160,30 });
					ImGui::Text("Test Release2 #000000");
					ImGui::SetCursorPos({ 160,47 });
					ImGui::Text("3 days ago");
					ImGui::SetCursorPos({ 160,80 });
					ImGui::Text("[+]  Example 1");
					ImGui::SetCursorPos({ 160,95 });
					ImGui::Text("[+]  Example 2");
					ImGui::SetCursorPos({ 160,110 });
					ImGui::Text("[+]  Example 3");
				}
				if (currentselection == 2) {

					ImGui::SetCursorPos({ 160,30 });
					ImGui::Text("Test Release3 #000000");
					ImGui::SetCursorPos({ 160,47 });
					ImGui::Text("1 days ago");
					ImGui::SetCursorPos({ 160,80 });
					ImGui::Text("[+]  Example 1");
					ImGui::SetCursorPos({ 160,95 });
					ImGui::Text("[+]  Example 2");
					ImGui::SetCursorPos({ 160,110 });
					ImGui::Text("[+]  Example 3");
				}
			
				ImGui::SetCursorPos({ 160,265 });
				if (ImGui::Button(cock, { 270, 25 }))
				{
					cock = ICON_FA_ROCKET " Launching...";

					/*Start*/
					switch (currentselection) {
						
					}
				}
			}
		}
		ImGui::End();
	}
}
