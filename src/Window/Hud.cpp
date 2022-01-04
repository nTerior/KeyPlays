#include "Hud.h"
#include "Capture/Capture.h"

#include "imgui.h"

namespace KeyPlays::Window {
  void RenderHud() {
		using namespace std::string_literals;

    CreateGlobalDockSpace();

    ImGui::Begin("KeyPlays");
		if(ImGui::Button(Capture::recording ? "Stop Recording" : "Start Recording")) {
			// When starting
			if(!Capture::recording) {
				Timer::Reset();
				Capture::dispatchedEvents.clear();
			}

			Capture::recording = !Capture::recording;
		}
    ImGui::End();

    ImGui::Begin("Log");
    ImGui::BeginChild("log_scrolling_area", ImVec2(), false, ImGuiWindowFlags_HorizontalScrollbar);

		// Log
		for(auto entry : Capture::dispatchedEvents) {
			ImGui::Text("[%s] %.2fs", entry.GetEventType() == Events::EventType::KeyPressed ? "Key Pressed" : "Key Released", entry.GetTimePoint() * 0.001f * 0.001f * 0.001f);
		}

		// Autoscrolling
		if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
    	ImGui::SetScrollHereY(1.0f);

		ImGui::EndChild();
    ImGui::End();
    
    ImGui::Begin("Settings");
    // Settings
    ImGui::End();

  }
  void ApplyStyle() {
    ImGuiStyle & style = ImGui::GetStyle();
		ImVec4 * colors = style.Colors;

		ImVec4 bg = ImVec4(0.25f, 0.25f, 0.25f, 1.0f);

		colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_TextDisabled]           = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
		colors[ImGuiCol_ChildBg]                = bg;
		colors[ImGuiCol_WindowBg]               = bg;
		colors[ImGuiCol_PopupBg]                = bg;
		colors[ImGuiCol_Border]                 = ImVec4(0.12f, 0.12f, 0.12f, 0.71f);
		colors[ImGuiCol_BorderShadow]           = ImVec4(0.f, 0.f, 0.f, 0.f);
		colors[ImGuiCol_FrameBg]                = ImVec4(0.42f, 0.42f, 0.42f, 0.54f);
		colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.42f, 0.42f, 0.42f, 0.40f);
		colors[ImGuiCol_FrameBgActive]          = ImVec4(0.56f, 0.56f, 0.56f, 0.67f);
		colors[ImGuiCol_TitleBg]                = ImVec4(0.2f, 0.2f, 0.2f, 1.00f);
		colors[ImGuiCol_TitleBgActive]          = ImVec4(0.2f, 0.2f, 0.2f, 1.00f);
		colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.2f, 0.2f, 0.2f, 1.00f);
		colors[ImGuiCol_MenuBarBg]              = bg;
		colors[ImGuiCol_ScrollbarBg]            = bg;
		colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.52f, 0.52f, 0.52f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.76f, 0.76f, 0.76f, 1.00f);
		colors[ImGuiCol_CheckMark]              = ImVec4(0.65f, 0.65f, 0.65f, 1.00f);
		colors[ImGuiCol_SliderGrab]             = ImVec4(0.52f, 0.52f, 0.52f, 1.00f);
		colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.64f, 0.64f, 0.64f, 1.00f);
		colors[ImGuiCol_Button]                 = ImVec4(0.54f, 0.54f, 0.54f, 0.35f);
		colors[ImGuiCol_ButtonHovered]          = ImVec4(0.52f, 0.52f, 0.52f, 0.59f);
		colors[ImGuiCol_ButtonActive]           = ImVec4(0.76f, 0.76f, 0.76f, 1.00f);
		colors[ImGuiCol_Header]                 = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
		colors[ImGuiCol_HeaderHovered]          = ImVec4(0.47f, 0.47f, 0.47f, 1.00f);
		colors[ImGuiCol_HeaderActive]           = ImVec4(0.76f, 0.76f, 0.76f, 0.77f);
		colors[ImGuiCol_Separator]              = ImVec4(0.000f, 0.000f, 0.000f, 0.137f);
		colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.700f, 0.671f, 0.600f, 0.290f);
		colors[ImGuiCol_SeparatorActive]        = ImVec4(0.702f, 0.671f, 0.600f, 0.674f);
		colors[ImGuiCol_ResizeGrip]             = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
		colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
		colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
		colors[ImGuiCol_PlotLines]              = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		colors[ImGuiCol_PlotHistogram]          = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.73f, 0.73f, 0.73f, 0.35f);
		colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
		colors[ImGuiCol_DragDropTarget]         = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		colors[ImGuiCol_NavHighlight]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);

		style.PopupRounding = 3;

		style.WindowPadding = ImVec2(4, 4);
		style.FramePadding  = ImVec2(6, 4);
		style.ItemSpacing   = ImVec2(6, 4);

		style.ScrollbarSize = 15;

		style.WindowBorderSize = 1;
		style.ChildBorderSize  = 1;
		style.PopupBorderSize  = 1;
		style.FrameBorderSize  = 0;

		style.WindowRounding    = 1;
		style.PopupRounding     = 1;
		style.ChildRounding     = 3;
		style.FrameRounding     = 3;
		style.ScrollbarRounding = 5;
		style.GrabRounding      = 3;

		#ifdef IMGUI_HAS_DOCK
			style.TabBorderSize = 0;
			style.TabRounding   = 3;

			colors[ImGuiCol_DockingEmptyBg]     = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
			colors[ImGuiCol_Tab]                = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
			colors[ImGuiCol_TabHovered]         = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
			colors[ImGuiCol_TabActive]          = ImVec4(0.33f, 0.33f, 0.33f, 1.00f);
			colors[ImGuiCol_TabUnfocused]       = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
			colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.33f, 0.33f, 0.33f, 1.00f);
			colors[ImGuiCol_DockingPreview]     = ImVec4(0.85f, 0.85f, 0.85f, 0.28f);

			if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
				style.WindowRounding = 0.0f;
				style.Colors[ImGuiCol_WindowBg].w = 1.0f;
			}
		#endif
  }
  void CreateGlobalDockSpace() {
    ImGuiIO &io = ImGui::GetIO();
    ImGuiWindowFlags dockspaceFlags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    const ImGuiViewport *viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("global_docking_space", nullptr, dockspaceFlags);
    ImGui::PopStyleVar(3);
    if(io.ConfigFlags & ImGuiConfigFlags_DockingEnable) {
      ImGuiID dockspaceId = ImGui::GetID("global_dock_space");
      ImGui::DockSpace(dockspaceId, ImVec2(0.f, 0.f));
    }
    ImGui::End();
  }
}