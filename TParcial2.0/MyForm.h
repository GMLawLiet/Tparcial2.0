#pragma once
#include"CJuego.h"

namespace TParcial20 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		// creacion de objetos para poder llamar 
		// tambien para el g quien dibuja
		// tambien el buffer por el parpadeo 
		CJuego*objJuego;
		Bitmap^imgPersonaje;
		Graphics ^g;
		BufferedGraphics^buffer;

	private: System::Windows::Forms::Timer^  timer1;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  PcBoxPersonaje;
	private: System::ComponentModel::IContainer^  components;
	protected:

	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->PcBoxPersonaje = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PcBoxPersonaje))->BeginInit();
			this->SuspendLayout();
			// 
			// PcBoxPersonaje
			// 
			this->PcBoxPersonaje->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PcBoxPersonaje.Image")));
			this->PcBoxPersonaje->Location = System::Drawing::Point(912, 31);
			this->PcBoxPersonaje->Name = L"PcBoxPersonaje";
			this->PcBoxPersonaje->Size = System::Drawing::Size(132, 238);
			this->PcBoxPersonaje->TabIndex = 0;
			this->PcBoxPersonaje->TabStop = false;
			this->PcBoxPersonaje->Visible = false;
			this->PcBoxPersonaje->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1102, 676);
			this->Controls->Add(this->PcBoxPersonaje);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PcBoxPersonaje))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

		// inicializacion de CJuego la imagen de personaje, fondo etc
		objJuego = new CJuego(0,0);
		g = this->CreateGraphics();

		BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
		buffer = context->Allocate(g, this->ClientRectangle);

		imgPersonaje = gcnew Bitmap(PcBoxPersonaje->Image);

		// por si algun sprite tiene color en la parte trasera 
		imgPersonaje->MakeTransparent(imgPersonaje->GetPixel(0, 0));

	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		// timer 
		buffer->Graphics->Clear(this->BackColor);
		objJuego->Dibujar(buffer->Graphics, imgPersonaje);


		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		objJuego->MoverPersonaje(e->KeyCode);

	}

	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {


	}
	

	};

}
