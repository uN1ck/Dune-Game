#pragma once
#include <iostream>
#include "cWorld.h"
#include <vector>
#include "iDrawable.h"
#include "iUpdateble.h"
#include "cPosited.h"



namespace OOPDUNEGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ form
	/// </summary>
	public ref class form : public System::Windows::Forms::Form
	{
	public:
		form(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::Button^  b_showLog;
	public:

	public:

	protected:
		cWorld *world;
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  p_showingPanel;
	protected:
	private: System::Windows::Forms::Button^  b_Generate;
	private: System::Windows::Forms::Button^  b_Run;
	private: System::Windows::Forms::Button^  b_killWorld;
	private: System::Windows::Forms::Button^  b_nextStep;

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->p_showingPanel = (gcnew System::Windows::Forms::Panel());
			this->b_Generate = (gcnew System::Windows::Forms::Button());
			this->b_Run = (gcnew System::Windows::Forms::Button());
			this->b_killWorld = (gcnew System::Windows::Forms::Button());
			this->b_nextStep = (gcnew System::Windows::Forms::Button());
			this->b_showLog = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// p_showingPanel
			// 
			this->p_showingPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->p_showingPanel->Location = System::Drawing::Point(148, 12);
			this->p_showingPanel->Name = L"p_showingPanel";
			this->p_showingPanel->Size = System::Drawing::Size(494, 328);
			this->p_showingPanel->TabIndex = 0;
			// 
			// b_Generate
			// 
			this->b_Generate->Location = System::Drawing::Point(12, 12);
			this->b_Generate->Name = L"b_Generate";
			this->b_Generate->Size = System::Drawing::Size(130, 44);
			this->b_Generate->TabIndex = 1;
			this->b_Generate->Text = L"Create!";
			this->b_Generate->UseVisualStyleBackColor = true;
			this->b_Generate->Click += gcnew System::EventHandler(this, &form::b_Generate_Click);
			// 
			// b_Run
			// 
			this->b_Run->Location = System::Drawing::Point(12, 62);
			this->b_Run->Name = L"b_Run";
			this->b_Run->Size = System::Drawing::Size(130, 44);
			this->b_Run->TabIndex = 2;
			this->b_Run->Text = L"Generate!";
			this->b_Run->UseVisualStyleBackColor = true;
			this->b_Run->Click += gcnew System::EventHandler(this, &form::b_Run_Click);
			// 
			// b_killWorld
			// 
			this->b_killWorld->Location = System::Drawing::Point(12, 162);
			this->b_killWorld->Name = L"b_killWorld";
			this->b_killWorld->Size = System::Drawing::Size(130, 44);
			this->b_killWorld->TabIndex = 3;
			this->b_killWorld->Text = L"Kill";
			this->b_killWorld->UseVisualStyleBackColor = true;
			this->b_killWorld->Click += gcnew System::EventHandler(this, &form::b_killWorld_Click);
			// 
			// b_nextStep
			// 
			this->b_nextStep->Location = System::Drawing::Point(12, 112);
			this->b_nextStep->Name = L"b_nextStep";
			this->b_nextStep->Size = System::Drawing::Size(130, 44);
			this->b_nextStep->TabIndex = 4;
			this->b_nextStep->Text = L"Next Step";
			this->b_nextStep->UseVisualStyleBackColor = true;
			this->b_nextStep->Click += gcnew System::EventHandler(this, &form::b_nextStep_Click);
			// 
			// b_showLog
			// 
			this->b_showLog->Location = System::Drawing::Point(12, 212);
			this->b_showLog->Name = L"b_showLog";
			this->b_showLog->Size = System::Drawing::Size(130, 44);
			this->b_showLog->TabIndex = 5;
			this->b_showLog->Text = L"Show Current Situation";
			this->b_showLog->UseVisualStyleBackColor = true;
			this->b_showLog->Click += gcnew System::EventHandler(this, &form::b_showLog_Click);
			// 
			// form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(652, 352);
			this->Controls->Add(this->b_showLog);
			this->Controls->Add(this->b_nextStep);
			this->Controls->Add(this->b_killWorld);
			this->Controls->Add(this->b_Run);
			this->Controls->Add(this->b_Generate);
			this->Controls->Add(this->p_showingPanel);
			this->Name = L"form";
			this->Text = L"form";
			this->Load += gcnew System::EventHandler(this, &form::form_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void b_Generate_Click(System::Object^  sender, System::EventArgs^  e) {
		world = new cWorld();
		this->b_killWorld->Enabled = false;
		this->b_nextStep->Enabled = false;
		this->b_Run->Enabled = true;
		this->b_Generate->Enabled = false;
		this->b_showLog->Enabled = true;
	}
	private: System::Void b_Run_Click(System::Object^  sender, System::EventArgs^  e) {
		try{
			world->Generate(std::string{ 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 1);
			this->p_showingPanel->Height = world->getHeight() * 10;
			this->p_showingPanel->Width = world->getWidth() * 10;
		}
		catch (System::Exception ^e)
		{
			System::Console::WriteLine(e->ToString());
			this->b_showLog_Click(this, nullptr);
		}		
		this->b_killWorld->Enabled = true;
		this->b_nextStep->Enabled = true;
		this->b_Run->Enabled = false;
		this->b_Generate->Enabled = false;
		this->b_showLog->Enabled = true;
	}
private: System::Void b_nextStep_Click(System::Object^  sender, System::EventArgs^  e) {
	
	System::Console::Clear();
	try{
		world->toString();
		world->Update();
		Graphics ^value = dynamic_cast<Graphics ^> (this->p_showingPanel->CreateGraphics());

			value->Clear(Color::Silver);
			for (int x = 0; x < world->getWidth(); x++)
				for (int y = 0; y < world->getHeight(); y++)
					{
					cObject * tmp = world->at(x, y);
					cPosited *current = dynamic_cast<cPosited*>(tmp);
					if (current)
					{
						if (current->getID() == "class cBase *")
							value->FillRectangle(gcnew SolidBrush(Color::Black), current->X() * 10, current->Y() * 10, 10, 10);
						if (current->getID() == "class cGunner *")
							value->FillRectangle(gcnew SolidBrush(Color::Red), current->X() * 10, current->Y() * 10, 10, 10);
						if (current->getID() == "class cTanker *")
							value->FillRectangle(gcnew SolidBrush(Color::Green), current->X() * 10, current->Y() * 10, 10, 10);
					}
				}
	}
	catch (System::Exception ^e)
	{
		System::Console::WriteLine(e->ToString());
		this->b_showLog_Click(this, nullptr);
	}
	
}
private: System::Void b_killWorld_Click(System::Object^  sender, System::EventArgs^  e) {
	try
	{
		delete world;
		Graphics ^value = dynamic_cast<Graphics ^> (this->p_showingPanel->CreateGraphics());
		value->Clear(Color::Silver);
	}
	catch (System::Exception ^e)
	{
		System::Console::WriteLine(e->ToString());
	
	}
	this->b_killWorld->Enabled = false;
	this->b_nextStep->Enabled = false;
	this->b_Run->Enabled = false;
	this->b_showLog->Enabled = false;
	this->b_Generate->Enabled = true;
}
private: System::Void form_Load(System::Object^  sender, System::EventArgs^  e) {
	this->b_killWorld->Enabled = false;
	this->b_nextStep->Enabled = false;
	this->b_Run->Enabled = false;
	this->b_showLog->Enabled = false;

}
private: System::Void b_showLog_Click(System::Object^  sender, System::EventArgs^  e) {
	try{
		System::Console::WriteLine("--------------->LOG<---------------");
		System::String ^str = gcnew System::String(world->toString().c_str());
		System::Console::WriteLine(str);
	}
	catch (System::Exception ^e)
	{
		System::Console::WriteLine(e->ToString());
		this->b_showLog_Click(this, nullptr);
	}

}
};
}
