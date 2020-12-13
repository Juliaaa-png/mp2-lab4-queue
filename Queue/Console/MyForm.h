#pragma once
#include "../Queue/Queue.h"

namespace Console {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		int MaxSize;
		int Size;
		double p;
		double q;
		int PopCount;
		int PushCount;
		TQueue<int>* queue;
		int CenterX, CenterY, Width, Height;
		Graphics^ gr;
		Random^ rndl;
		   Pen^ BlackPen;
		   Pen^ WhitePen;
	public:
		MyForm(void)
		{
			InitializeComponent();
			gr = this->CreateGraphics();
			rndl = gcnew Random();
			BlackPen = gcnew Pen(Color::Black);
			BlackPen->Width = 10.0F;
			WhitePen = gcnew Pen(SystemColors::Control);
			WhitePen->Width = 10.5F;

			CenterX = 250;
			CenterY = 300;
			Width = Height = 200;
			PopCount = PushCount = 0;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(23, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(318, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Максимальная длина очереди:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(383, 57);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(280, 26);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(76, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(265, 28);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Исходная длина очереди:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(383, 108);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(280, 26);
			this->textBox2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(75, 163);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(266, 28);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Вероятность добавления:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(384, 163);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(279, 26);
			this->textBox3->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(75, 216);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(264, 28);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Вероятность извлечения:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(385, 218);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(277, 26);
			this->textBox4->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(111, 273);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(230, 28);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Добавлено в очередь:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(388, 273);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(275, 26);
			this->textBox5->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(109, 324);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(230, 25);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Извлечено из очереди:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(388, 325);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(274, 26);
			this->textBox6->TabIndex = 11;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(812, 86);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 71);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(816, 219);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 70);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Стоп";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1060, 937);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MaxSize = Convert::ToInt32(textBox1->Text);
		Size = Convert::ToInt32(textBox2->Text);
		p = Convert::ToDouble(textBox3->Text);
		q = Convert::ToDouble(textBox4->Text);
		queue = new TQueue<int>(MaxSize);
		PushCount = 0;
		PopCount = 0;
		for (int i = 0; i < Size; i++)
			queue->Push(i);
		DrawQueue();
		timer1->Enabled = true;
	}
		   void DrawQueue()
		   {
			   int start = 360 * queue->GetNumberHead() / queue->GetMaxSize();
			   int finish = 360 * queue->GetSize() / queue->GetMaxSize();
			   gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, start, finish);
		   }
		   void Clean()
		   {
			   gr->DrawArc(WhitePen, CenterX, CenterY, Width, Height, 0, 360);
		   }
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	Clean();
	if (rndl->NextDouble() < p)
	{
		if (Size < MaxSize)
		{
			queue->Push(1);
			Size++;
			PushCount++;
		}
	}
	if (rndl->NextDouble() < q)
	{
		if (Size > 0)
		{
			queue->GetHead();
			Size--;
			PopCount++;
		}
	}
	DrawQueue();
	textBox5->Text = Convert::ToString(PushCount);
	textBox6->Text = Convert::ToString(PopCount);
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = false;
}
};
}
