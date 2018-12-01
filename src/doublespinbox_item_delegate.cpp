#include "doublespinbox_item_delegate.h"
#include "float.h"
#include <QDebug>
#include <QTableView>
#include <QDoubleSpinBox>

extern "C" void new_doublespinbox_item_delegate(QObject *parent, const int column) {
    QDoubleSpinBoxItemDelegate* delegate = new QDoubleSpinBoxItemDelegate(parent);
    dynamic_cast<QTableView*>(parent)->setItemDelegateForColumn(column, delegate);
}

QDoubleSpinBoxItemDelegate::QDoubleSpinBoxItemDelegate(QObject *parent): QStyledItemDelegate(parent)
{

}

QWidget* QDoubleSpinBoxItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    // create widget for use
    QDoubleSpinBox* spinBox = new QDoubleSpinBox(parent);
    spinBox->setRange(-3.402823e+38, 3.402823e+38);
    spinBox->setDecimals(3);
    return spinBox;
}

void QDoubleSpinBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    // update model widget
    QDoubleSpinBox* spinBox = static_cast<QDoubleSpinBox*>(editor);
    double value = index.model()->data(index, Qt::EditRole).toDouble();
    spinBox->setValue(value);
}

void QDoubleSpinBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    // store edited model data to model
    QDoubleSpinBox* spinBox = static_cast<QDoubleSpinBox*>(editor);
    double value = spinBox->value();
    model->setData(index, value, Qt::EditRole);
}

void QDoubleSpinBoxItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    editor->setGeometry(option.rect);
}
