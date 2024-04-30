#pragma once
#include "RegestrationOfUser.h"
#include "RegOfDev.h"
#include "Lib1.h"
namespace FreeDOM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ HelloWin
	/// </summary>
	public ref class HelloWin : public System::Windows::Forms::Form
	{
	public:
		HelloWin(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~HelloWin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ UserReg;
	protected:

	private: System::Windows::Forms::Label^ HelloText;
	private: System::Windows::Forms::Button^ DevReg;


	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(HelloWin::typeid));
			this->UserReg = (gcnew System::Windows::Forms::Button());
			this->HelloText = (gcnew System::Windows::Forms::Label());
			this->DevReg = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// UserReg
			// 
			this->UserReg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->UserReg->Location = System::Drawing::Point(120, 147);
			this->UserReg->Name = L"UserReg";
			this->UserReg->Size = System::Drawing::Size(287, 37);
			this->UserReg->TabIndex = 0;
			this->UserReg->Text = L"User";
			this->UserReg->UseVisualStyleBackColor = true;
			this->UserReg->Click += gcnew System::EventHandler(this, &HelloWin::UserReg_Click);
			// 
			// HelloText
			// 
			this->HelloText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->HelloText->Location = System::Drawing::Point(115, 49);
			this->HelloText->Name = L"HelloText";
			this->HelloText->Size = System::Drawing::Size(292, 79);
			this->HelloText->TabIndex = 1;
			this->HelloText->Text = L"Welcome to our game shop. Choose how you wish to enter";
			this->HelloText->Click += gcnew System::EventHandler(this, &HelloWin::label1_Click);
			// 
			// DevReg
			// 
			this->DevReg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DevReg->Location = System::Drawing::Point(120, 202);
			this->DevReg->Name = L"DevReg";
			this->DevReg->Size = System::Drawing::Size(287, 37);
			this->DevReg->TabIndex = 2;
			this->DevReg->Text = L"Developer";
			this->DevReg->UseVisualStyleBackColor = true;
			this->DevReg->Click += gcnew System::EventHandler(this, &HelloWin::DevReg_Click);
			// 
			// HelloWin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(504, 351);
			this->Controls->Add(this->DevReg);
			this->Controls->Add(this->HelloText);
			this->Controls->Add(this->UserReg);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"HelloWin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FreeDOM";
			this->Load += gcnew System::EventHandler(this, &HelloWin::HelloWin_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void HelloWin_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void UserReg_Click(System::Object^ sender, System::EventArgs^ e) {
		RegestrationOfUser^ usWin = gcnew RegestrationOfUser();
		//usWin->users = ttt();
		usWin->Show();
		this->Hide();
		test();
		
	}
	private: System::Void DevReg_Click(System::Object^ sender, System::EventArgs^ e) {
		RegOfDev^ devWin = gcnew RegOfDev();
		devWin->Show();
		this->Hide();
	}
};
}
