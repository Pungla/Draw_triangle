#pragma once

namespace Drawtriangle {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Points {
    public:
        int x, y;
    };

    public ref class Triangle {
    public:
        array<Points^>^ points;
        Color colorArgb;

        Triangle(Points^ p1, Points^ p2, Points^ p3, Color color) {
            points = gcnew array<Points^>(3);
            points[0] = p1;
            points[1] = p2;
            points[2] = p3;
            colorArgb = color;
        }
    };

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            // Инициализация массива треугольников
            triangles = gcnew array<Triangle^>(MAX_TRIANGLES);
            currentTriangle = 0;
            clickCount = 0;
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;

        static const int MAX_TRIANGLES = 100;
        array<Triangle^>^ triangles;
        int currentTriangle;
        int clickCount;
        array<Points^>^ points;
        bool isCreate_triangles = false;

        Color currentColor;

        // UI Components
        System::Windows::Forms::Button^ btnCreateArray;
        System::Windows::Forms::Button^ btnColorPicker;
        System::Windows::Forms::Button^ btnAddToArray;
        System::Windows::Forms::Button^ btnDrawAll;
        System::Windows::Forms::Button^ btnExit;
        System::Windows::Forms::TextBox^ txtNumElements;
        System::Windows::Forms::ColorDialog^ colorDialog;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->SuspendLayout();

            // 
            // MyForm
            // 
            this->ClientSize = System::Drawing::Size(600, 400);
            this->Name = L"MyForm";
            this->Text = L"Работа со структурами";
            this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::FormMouseDown);

            // 
            // btnCreateArray
            // 
            this->btnCreateArray = gcnew System::Windows::Forms::Button();
            this->btnCreateArray->Location = System::Drawing::Point(10, 350);
            this->btnCreateArray->Size = System::Drawing::Size(120, 30);
            this->btnCreateArray->Text = L"Создать массив объектов";
            this->btnCreateArray->Click += gcnew System::EventHandler(this, &MyForm::btnCreateArray_Click);
            this->Controls->Add(this->btnCreateArray);

            // 
            // btnColorPicker
            // 
            this->btnColorPicker = gcnew System::Windows::Forms::Button();
            this->btnColorPicker->Location = System::Drawing::Point(140, 350);
            this->btnColorPicker->Size = System::Drawing::Size(100, 30);
            this->btnColorPicker->Text = L"Выбор цвета";
            this->btnColorPicker->Click += gcnew System::EventHandler(this, &MyForm::btnColorPicker_Click);
            this->Controls->Add(this->btnColorPicker);

            // 
            // btnAddToArray
            // 
            this->btnAddToArray = gcnew System::Windows::Forms::Button();
            this->btnAddToArray->Location = System::Drawing::Point(250, 350);
            this->btnAddToArray->Size = System::Drawing::Size(120, 30);
            this->btnAddToArray->Text = L"Занести в массив";
            this->btnAddToArray->Click += gcnew System::EventHandler(this, &MyForm::btnAddToArray_Click);
            this->Controls->Add(this->btnAddToArray);

            // 
            // btnDrawAll
            // 
            this->btnDrawAll = gcnew System::Windows::Forms::Button();
            this->btnDrawAll->Location = System::Drawing::Point(380, 350);
            this->btnDrawAll->Size = System::Drawing::Size(120, 30);
            this->btnDrawAll->Text = L"Нарисовать все";
            this->btnDrawAll->Click += gcnew System::EventHandler(this, &MyForm::btnDrawAll_Click);
            this->Controls->Add(this->btnDrawAll);

            // 
            // btnExit
            // 
            this->btnExit = gcnew System::Windows::Forms::Button();
            this->btnExit->Location = System::Drawing::Point(510, 350);
            this->btnExit->Size = System::Drawing::Size(70, 30);
            this->btnExit->Text = L"Выход";
            this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
            this->Controls->Add(this->btnExit);

            // 
            // txtNumElements
            // 
            this->txtNumElements = gcnew System::Windows::Forms::TextBox();
            this->txtNumElements->Location = System::Drawing::Point(10, 10);
            this->txtNumElements->Size = System::Drawing::Size(100, 20);
            this->Controls->Add(this->txtNumElements);

            // 
            // colorDialog
            // 
            this->colorDialog = gcnew System::Windows::Forms::ColorDialog();

            this->ResumeLayout(false);
        }
#pragma endregion

        void MyForm_Load(Object^ sender, EventArgs^ e)
        {
            // Здесь можно инициализировать компоненты формы и установить начальные параметры
        }

        void btnCreateArray_Click(Object^ sender, EventArgs^ e)
        {
            // Обработчик нажатия кнопки для создания массива треугольников
            try {
                int n = Convert::ToInt32(txtNumElements->Text);
                if (triangles)
                {
                    delete[] triangles;
                }
                triangles = gcnew array<Triangle^>(n);
                points = gcnew array<Points^>(3);
                currentTriangle = 0;
                isCreate_triangles = true;
            }
            catch (const char* error_message) {
                MessageBox::Show("Введите число!");
            }
        }

        void btnColorPicker_Click(Object^ sender, EventArgs^ e)
        {
            // Обработчик нажатия кнопки для выбора цвета
            if (colorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                currentColor = colorDialog->Color;
            }
        }

        void btnAddToArray_Click(Object^ sender, EventArgs^ e)
        {
            // Обработчик нажатия кнопки для добавления треугольника в массив
            if (currentTriangle < triangles->Length)
            {
                if (clickCount == 3)
                {
                    triangles[currentTriangle] = gcnew Triangle(points[0], points[1], points[2], currentColor);
                    currentTriangle++;
                    clickCount = 0;
                    points = gcnew array<Points^>(3);
                    this->Invalidate();
                }
                else {
                    MessageBox::Show("Не дорисован треугольник!");
                }
            }
            else {
                this->Invalidate();
                MessageBox::Show("Переполнение массива!");
            }
        }

        void btnDrawAll_Click(Object^ sender, EventArgs^ e)
        {
            // Обработчик нажатия кнопки для отрисовки всех треугольников
            this->Invalidate();
            for (int i = 0; i < currentTriangle; i++)
            {
                DrawTriangle(triangles[i]);
            }
        }

        void btnExit_Click(Object^ sender, EventArgs^ e)
        {
            // Обработчик нажатия кнопки для выхода из приложения
            this->Close();
        }

        void FormMouseDown(Object^ sender, MouseEventArgs^ e)
        {
            if (!isCreate_triangles) {
                MessageBox::Show("Создайте массив!");
            }
            else if (clickCount < 3)
            {
                points[clickCount] = gcnew Points();
                points[clickCount]->x = e->X;
                points[clickCount]->y = e->Y;
                clickCount++;
                if (clickCount == 3)
                {
                    DrawTriangle(gcnew Triangle(points[0], points[1], points[2], currentColor));
                }
            }
        }

        void DrawTriangle(Triangle^ triangle)
        {
            Graphics^ g = this->CreateGraphics();
            array<Point>^ pts = gcnew array<Point>(3);
            pts[0] = Point(triangle->points[0]->x, triangle->points[0]->y);
            pts[1] = Point(triangle->points[1]->x, triangle->points[1]->y);
            pts[2] = Point(triangle->points[2]->x, triangle->points[2]->y);
            g->DrawPolygon(gcnew Pen(triangle->colorArgb), pts);
        }
    };
}
