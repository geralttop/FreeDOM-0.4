#pragma once
#include "Lib1.h"
namespace FreeDOM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ RegestrationOfUser
	/// </summary>
	public ref class RegestrationOfUser : public System::Windows::Forms::Form
	{
	public:
		RegestrationOfUser(void)
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
		~RegestrationOfUser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ usLogin;
	private: System::Windows::Forms::TextBox^ usPass;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ usSignIn;

	private: System::Windows::Forms::Button^ usSignUp;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegestrationOfUser::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->usLogin = (gcnew System::Windows::Forms::TextBox());
			this->usPass = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->usSignIn = (gcnew System::Windows::Forms::Button());
			this->usSignUp = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(65, 78);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(556, 40);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter your details to log in to your account";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label2->Location = System::Drawing::Point(66, 148);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 33);
			this->label2->TabIndex = 1;
			this->label2->Text = L"login";
			this->label2->Click += gcnew System::EventHandler(this, &RegestrationOfUser::label2_Click);
			// 
			// usLogin
			// 
			this->usLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->usLogin->Location = System::Drawing::Point(153, 148);
			this->usLogin->Name = L"usLogin";
			this->usLogin->Size = System::Drawing::Size(251, 34);
			this->usLogin->TabIndex = 2;
			// 
			// usPass
			// 
			this->usPass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->usPass->Location = System::Drawing::Point(153, 212);
			this->usPass->Name = L"usPass";
			this->usPass->PasswordChar = '*';
			this->usPass->Size = System::Drawing::Size(251, 34);
			this->usPass->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label3->Location = System::Drawing::Point(66, 212);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 33);
			this->label3->TabIndex = 4;
			this->label3->Text = L"pass";
			// 
			// usSignIn
			// 
			this->usSignIn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usSignIn->Location = System::Drawing::Point(71, 303);
			this->usSignIn->Name = L"usSignIn";
			this->usSignIn->Size = System::Drawing::Size(268, 46);
			this->usSignIn->TabIndex = 5;
			this->usSignIn->Text = L"Sign In";
			this->usSignIn->UseVisualStyleBackColor = true;
			this->usSignIn->Click += gcnew System::EventHandler(this, &RegestrationOfUser::usSignIn_Click);
			// 
			// usSignUp
			// 
			this->usSignUp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usSignUp->Location = System::Drawing::Point(353, 303);
			this->usSignUp->Name = L"usSignUp";
			this->usSignUp->Size = System::Drawing::Size(268, 46);
			this->usSignUp->TabIndex = 6;
			this->usSignUp->Text = L"Sign up";
			this->usSignUp->UseVisualStyleBackColor = true;
			// 
			// RegestrationOfUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(672, 432);
			this->Controls->Add(this->usSignUp);
			this->Controls->Add(this->usSignIn);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->usPass);
			this->Controls->Add(this->usLogin);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"RegestrationOfUser";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FreeDOM";
			this->Load += gcnew System::EventHandler(this, &RegestrationOfUser::RegestrationOfUser_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		System::Diagnostics::Process::Start("FireFox", "https://rutracker.net/forum/dl.php?t=5957448");
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void RegestrationOfUser_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void usSignIn_Click(System::Object^ sender, System::EventArgs^ e) {
	ttt();
}
};
}
