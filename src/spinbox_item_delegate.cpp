#include "spinbox_item_delegate.h"
#include "limits.h"
#include <QDebug>
#include <QTableView>
#include <QSpinBox>
#include <QLineEdit>

extern "C" void new_spinbox_item_delegate(QObject *parent, const int column, const int integer_type) {
    QSpinBoxItemDelegate* delegate = new QSpinBoxItemDelegate(parent, integer_type);
    dynamic_cast<QTableView*>(parent)->setItemDelegateForColumn(column, delegate);
}

QSpinBoxItemDelegate::QSpinBoxItemDelegate(QObject *parent, const int integer_type): QStyledItemDelegate(parent)
{
    type = integer_type;
}

QWidget* QSpinBoxItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    // create widget for use
    if (type == 64) {
        QLineEdit* lineEdit = new QLineEdit(parent);
        return lineEdit;
    }
    else {
        QSpinBox* spinBox = new QSpinBox(parent);
        spinBox->setRange(-2147483648, 2147483647);
        return spinBox;
    }
}

void QSpinBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    // update model widget
    if (type == 64) {
        QLineEdit* lineEdit = static_cast<QLineEdit*>(editor);
        QString value = index.model()->data(index, Qt::EditRole).toString();
        lineEdit->setText(value);
    }
    else {
        QSpinBox* spinBox = static_cast<QSpinBox*>(editor);
        signed int value = index.model()->data(index, Qt::EditRole).toInt();
        spinBox->setValue(value);
    }
}

void QSpinBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    // store edited model data to model
    if (type == 64) {
        QLineEdit* lineEdit = static_cast<QLineEdit*>(editor);
        bool ok;
        signed long long value = lineEdit->text().toLongLong(&ok, 10);
        if (ok) { model->setData(index, value, Qt::EditRole); }
    }
    else {
        QSpinBox* spinBox = static_cast<QSpinBox*>(editor);
        signed int value = spinBox->value();
        model->setData(index, value, Qt::EditRole);
    }
}

void QSpinBoxItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    editor->setGeometry(option.rect);
}
