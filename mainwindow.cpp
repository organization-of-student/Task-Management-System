#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addButton_clicked() {
    QString title = ui->titleEdit->text();
    QString description = ui->descriptionEdit->toPlainText();
    QString dueDate = ui->dueDateEdit->text();

    if (title.isEmpty() || dueDate.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in Title and Due Date.");
        return;
    }

    tasks.append(Task(title, description, dueDate));
    updateTaskList();

    ui->titleEdit->clear();
    ui->descriptionEdit->clear();
    ui->dueDateEdit->clear();
}

void MainWindow::on_deleteButton_clicked() {
    int index = ui->taskList->currentRow();
    if (index >= 0 && index < tasks.size()) {
        tasks.removeAt(index);
        updateTaskList();
    }
}

void MainWindow::updateTaskList() {
    ui->taskList->clear();
    for (const Task &task : tasks) {
        ui->taskList->addItem(task.getTitle() + " - Due: " + task.getDueDate());
    }
}
