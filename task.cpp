#include "task.h"

Task::Task(const QString &title, const QString &description, const QString &dueDate)
    : title(title), description(description), dueDate(dueDate) {}

QString Task::getTitle() const { return title; }
QString Task::getDescription() const { return description; }
QString Task::getDueDate() const { return dueDate; }
