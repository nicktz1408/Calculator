#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)   //Constructor of UI
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()    //Destructor of UI
{
    delete ui;
}

//----------------------------------------------------------------------------------------

void MainWindow::on_button0_clicked()     //When the '0' button clicked
{
    procedure(0, situation);     //Adding an 0 to the current number
}

void MainWindow::on_button1_clicked()     //When the '1' button clicked
{
    procedure(1, situation);     //Adding an 1 to the current number
}

void MainWindow::on_button2_clicked()     //When the '2' button clicked
{
    procedure(2, situation);     //Adding an 2 to the current number
}

void MainWindow::on_button3_clicked()     //When the '3' button clicked
{
    procedure(3, situation);     //Adding an 3 to the current number
}

void MainWindow::on_button4_clicked()     //When the '4' button clicked
{
    procedure(4, situation);     //Adding an 4 to the current number
}

void MainWindow::on_button5_clicked()     //When the '5' button clicked
{
    procedure(5, situation);     //Adding an 5 to the current number
}

void MainWindow::on_button6_clicked()     //When the '6' button clicked
{
    procedure(6, situation);     //Adding an 6 to the current number
}

void MainWindow::on_button7_clicked()     //When the '7' button clicked
{
    procedure(7, situation);     //Adding an 7 to the current number
}

void MainWindow::on_button8_clicked()     //When the '8' button clicked
{
    procedure(8, situation);     //Adding an 8 to the current number
}

void MainWindow::on_button9_clicked()     //When the '9' button clicked
{
    procedure(9, situation);     //Adding an 9 to the current number
}

//----------------------------------------------------------------------------------------

void MainWindow::on_adding_clicked()     //When the addition button clicked
{
    operation = 1;     //We are declaring the addition operation
    situation = 2;     //We are procceding to the second number (after operation)
}

void MainWindow::on_subducting_clicked()     //When the subduction button clicked
{
    operation = 2;     //We are declaring the subduction operation
    situation = 2;     //We are procceding to the second number (after operation)
}

void MainWindow::on_multiplying_clicked()     //When the multiplication button clicked
{
    operation = 3;     //We are declaring the multiplication operation
    situation = 2;     //We are procceding to the second number (after operation)
}

void MainWindow::on_dividing_clicked()     //When the division button clicked
{
    operation = 4;     //We are declaring the division operation
    situation = 2;     //We procced to the second number (after operation)
}

void MainWindow::on_clear_clicked()     //When the c button clicked
{
    situation = 1;     //We are returning to the first number (before operation)
    number1 = number2 = 0;     //We are setting the numbers' variables to zero in order to reuse safely
    ui -> lineEdit -> setText("0");     //We are displaying the number zero
}

//----------------------------------------------------------------------------------------

void MainWindow::on_equals_clicked()     //When the equals button clicked
{
    if (situation == 2)     //If we have already inputed both numbers
    {
        int result;     //This variable stores the result of the ordered operation
        QString toString;     //This string is used to display the result

        switch (operation)     //Options for the operation we chose
        {
        case 1:     //If we chose addition
            result = number1 + number2;     //Adding
            break;     //Exits

        case 2:     //If we chose subduction
            result = number1 - number2;     //Subducting
            break;     //Exits

        case 3:     //If we chose multiplication
            result = number1 * number2;     //Multiplying
            break;     //Exits

        case 4:     //If we chose division
            result = number1 / number2;     //Dividing
            break;     //Exits
        }

        toString.setNum(result);     //We are setting the result to the displaying string
        ui -> lineEdit -> setText(toString);     //We are displaying the result

        number1 = result;     //The result is stored at the first number (we are currently using the second number until
                              //the user presses the clear button)
        number2 = 0;          //We reintillize the second number to zero in order to reuse in future calculations
    }
}

//----------------------------------------------------------------------------------------

void MainWindow::procedure(int number, int situation)     //Adding the number that pressed to the lineEdid and to the current variable
{
    QString toString;     //Display string

    if (situation == 1)     //If we are typing the first number (before operation)
    {
        number1 *= 10;     //Number maniplication
        number1 += number;     //Number maniplication

        toString.setNum(number1);     //Setting number to display string
        ui -> lineEdit -> setText(toString);     //Display the string (the number modified)
    }

    else if (situation == 2)     //If we are typing the second number (after operation)
    {
        number2 *= 10;     //Number maniplication
        number2 += number;     //Number maniplication

        toString.setNum(number2);     //Setting number to display string
        ui -> lineEdit -> setText(toString);     //Display the string (the number modified)
    }
}

void MainWindow::on_lineEdit_editingFinished()     //When the edit of lineEdit finishes
{
    QString outputString = ui -> lineEdit -> text();     //String that stores the output number
    int outputNumber = outputString.toInt();     //Convert the string to integer variable

    if (situation == 1)     //If we are currently writting the first number
        number1 = outputNumber;     //Set output number to first number variable

    else     //If we are currently writting the second number
        number2 = outputNumber;     //Set output number to second number variable

    ui -> lineEdit -> clear();     //We are clearing the input
}

void MainWindow::on_lineEdit_selectionChanged()     //When we click at the lineEdit
{
    ui -> lineEdit -> clear();
}
