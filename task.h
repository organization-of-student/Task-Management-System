#ifndef TASK_H
#define TASK_H

#include <QString>

class Task {
public:
    Task(const QString &title, const QString &description, const QString &dueDate);

    QString getTitle() const;
    QString getDescription() const;
    QString getDueDate() const;

private:
    QString title;
    QString description;
    QString dueDate;
};

#endif // TASK_H
