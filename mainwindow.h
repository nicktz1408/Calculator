#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button0_clicked();     //Number 0 clicked
    void on_button1_clicked();     //Number 1 clicked
    void on_button2_clicked();     //Number 2 clicked
    void on_button3_clicked();     //Number 3 clicked
    void on_button4_clicked();     //Number 4 clicked
    void on_button5_clicked();     //Number 5 clicked
    void on_button6_clicked();     //Number 6 clicked
    void on_button7_clicked();     //Number 7 clicked
    void on_button8_clicked();     //Number 8 clicked
    void on_button9_clicked();     //Number 9 clicked

    void on_clear_clicked();     //Clear operator clicked
    void on_adding_clicked();     //Addition operator clicked
    void on_subducting_clicked();     //Subduction operator clicked
    void on_multiplying_clicked();     //Multiplication operator clicked
    void on_dividing_clicked();     //Division operator clicked
    void on_equals_clicked();     //Equal operator clicked

    void procedure(int number, int situation);     //Update status of  either number1 or number2 + Updated text display

    void on_lineEdit_editingFinished();     //When the edit of lineEdit finishes
    void on_lineEdit_selectionChanged();     //When we click at the lineEdit

private:
    int number1 = 0;     //The first number
    int number2 = 0;     //The second number
    int operation = 0;     //1 --> Adding, 2 --> Subducting, 3 --> Multipling, 4 --> Dividing
    int situation = 1;     //1 --> Number1, 2 --> Number2
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
