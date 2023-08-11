#pragma once

#include "DataPacket.h"
#include "UdpManager.h"

namespace UdpForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net::Sockets;
	using namespace System::Net;
	using namespace System::Threading;
	using namespace System::Text;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		UdpClient^ ClientSocket;
		UdpClient^ ServerSocket;
		IPEndPoint^ remoteEndPoint;
		IPEndPoint^ EndPoint;
		IPAddress^ UserIPAddress;
		int UserPortNumber;
		array<Byte>^ receivedBytes;
		UdpManager^ TempClientSocket;
		UdpManager^ TempServerSocket;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Button^ btnRestart;
	private: System::Windows::Forms::Button^ btnConfirm;
	private: System::Windows::Forms::TextBox^ tBoxPortNumber;
	private: System::Windows::Forms::TextBox^ tBoxIPAddress;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RichTextBox^ tBoxServer;
	private: System::Windows::Forms::RichTextBox^ tBoxClient;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnStart;
	private: System::Windows::Forms::Button^ btnStop;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnRestart = (gcnew System::Windows::Forms::Button());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->tBoxPortNumber = (gcnew System::Windows::Forms::TextBox());
			this->tBoxIPAddress = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tBoxServer = (gcnew System::Windows::Forms::RichTextBox());
			this->tBoxClient = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnRestart);
			this->groupBox1->Controls->Add(this->btnConfirm);
			this->groupBox1->Controls->Add(this->tBoxPortNumber);
			this->groupBox1->Controls->Add(this->tBoxIPAddress);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 41);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(279, 210);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Socket Settings";
			// 
			// btnRestart
			// 
			this->btnRestart->Location = System::Drawing::Point(141, 127);
			this->btnRestart->Name = L"btnRestart";
			this->btnRestart->Size = System::Drawing::Size(101, 32);
			this->btnRestart->TabIndex = 2;
			this->btnRestart->Text = L"Restart";
			this->btnRestart->UseVisualStyleBackColor = true;
			this->btnRestart->Click += gcnew System::EventHandler(this, &MyForm::btnRestart_Click);
			// 
			// btnConfirm
			// 
			this->btnConfirm->Location = System::Drawing::Point(19, 127);
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->Size = System::Drawing::Size(101, 32);
			this->btnConfirm->TabIndex = 1;
			this->btnConfirm->Text = L"Confirm";
			this->btnConfirm->UseVisualStyleBackColor = true;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &MyForm::btnConfirm_Click);
			// 
			// tBoxPortNumber
			// 
			this->tBoxPortNumber->Location = System::Drawing::Point(125, 82);
			this->tBoxPortNumber->Name = L"tBoxPortNumber";
			this->tBoxPortNumber->Size = System::Drawing::Size(100, 22);
			this->tBoxPortNumber->TabIndex = 3;
			// 
			// tBoxIPAddress
			// 
			this->tBoxIPAddress->Location = System::Drawing::Point(125, 39);
			this->tBoxIPAddress->Name = L"tBoxIPAddress";
			this->tBoxIPAddress->Size = System::Drawing::Size(100, 22);
			this->tBoxIPAddress->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Port Number";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"IP Address";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(310, 22);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 16);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Server";
			// 
			// tBoxServer
			// 
			this->tBoxServer->Location = System::Drawing::Point(313, 41);
			this->tBoxServer->Name = L"tBoxServer";
			this->tBoxServer->Size = System::Drawing::Size(299, 86);
			this->tBoxServer->TabIndex = 2;
			this->tBoxServer->Text = L"";
			// 
			// tBoxClient
			// 
			this->tBoxClient->Location = System::Drawing::Point(313, 154);
			this->tBoxClient->Name = L"tBoxClient";
			this->tBoxClient->Size = System::Drawing::Size(299, 86);
			this->tBoxClient->TabIndex = 4;
			this->tBoxClient->Text = L"";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(310, 135);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 16);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Client";
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(313, 255);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(101, 32);
			this->btnStart->TabIndex = 5;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &MyForm::btnStart_Click);
			// 
			// btnStop
			// 
			this->btnStop->Location = System::Drawing::Point(511, 255);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(101, 32);
			this->btnStop->TabIndex = 6;
			this->btnStop->Text = L"Stop";
			this->btnStop->UseVisualStyleBackColor = true;
			this->btnStop->Click += gcnew System::EventHandler(this, &MyForm::btnStop_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 298);
			this->Controls->Add(this->btnStop);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->tBoxClient);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tBoxServer);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void UpdateServerTextBox(String^ text)
		{
			if (tBoxServer->InvokeRequired)
			{
				tBoxServer->Invoke(gcnew Action<String^>(this, &MyForm::UpdateServerTextBox), text);
			}
			else
			{
				tBoxServer->AppendText(text);
			}
		}

		void UpdateClientTextBox(String^ text)
		{
			if (tBoxClient->InvokeRequired)
			{
				tBoxClient->Invoke(gcnew Action<String^>(this, &MyForm::UpdateClientTextBox), text);
			}
			else
			{
				tBoxClient->AppendText(text);
			}
		}

	private: void GetSocketSettings() {

		UserIPAddress = IPAddress::Parse(tBoxIPAddress->Text);
		UserPortNumber = int::Parse(tBoxPortNumber->Text);
		ClientSocket = gcnew UdpClient();
		ServerSocket = gcnew UdpClient(UserPortNumber);
		remoteEndPoint = gcnew IPEndPoint(UserIPAddress, UserPortNumber); // send
		EndPoint = gcnew IPEndPoint(IPAddress::Any, UserPortNumber); // receive
	}
	
	private: System::Void btnConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
		GetSocketSettings();
	}

		   void ClientThreadFunction() {
			   while (true)
			   {
				   S_APP_TO_SIMULATOR sendData;
				   sendData.stx = 0x0055; 
				   sendData.messageId = 0x00c0; 
				   String^ data = sendData.stx + " " + sendData.messageId;
				   array<Byte>^ message = Encoding::ASCII->GetBytes(data);  
				   ClientSocket->Send(message, message->Length, remoteEndPoint);
				   UpdateClientTextBox("Client To Master: " + data + Environment::NewLine);
				   Thread::Sleep(200);
			   }
		   }

		   void ServerThreadFunction() {
			   while (true)
			   {
				   array<Byte>^ receivedData = ServerSocket->Receive(EndPoint); 
				   String^ receivedMessage = Encoding::ASCII->GetString(receivedData);
				   UpdateServerTextBox("Client To Master " + receivedMessage + Environment::NewLine);
				   Thread::Sleep(200);
			   }
		   }

	private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
		Thread^ serverThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::ServerThreadFunction));
		serverThread->Start();
		Thread^ clientThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::ClientThreadFunction));
		clientThread->Start(); 
	}
	private: System::Void btnStop_Click(System::Object^ sender, System::EventArgs^ e) {
		ClientSocket->Close();
		ServerSocket->Close();
	}

	private: System::Void btnRestart_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Restart();
	}
};
}
