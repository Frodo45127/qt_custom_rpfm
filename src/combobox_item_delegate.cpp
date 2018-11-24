#include "combobox_item_delegate.h"
#include <QDebug>
#include <QTableView>

extern "C" void new_combobox_item_delegate(QObject *parent, const int column, const QStringList* values, const bool is_editable) {
    QComboBoxItemDelegate* delegate = new QComboBoxItemDelegate(parent, *values, is_editable);
    dynamic_cast<QTableView*>(parent)->setItemDelegateForColumn(column, delegate);
}

QComboBoxItemDelegate::QComboBoxItemDelegate(QObject *parent, const QStringList provided_values, bool is_editable): QStyledItemDelegate(parent)
{
    editable = is_editable;
    values = provided_values;
}

QWidget* QComboBoxItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    // create widget for use
    QComboBox* comboBox = new QComboBox(parent);
    comboBox->setEditable(editable);
    comboBox->addItems(values);
    return comboBox;
}

void QComboBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    // update model widget
    QString value = index.model()->data(index, Qt::EditRole).toString();
    QComboBox* comboBox = static_cast<QComboBox*>(editor);
    comboBox->setCurrentIndex(comboBox->findText(value));
}

void QComboBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    // store edited model data to model
    QComboBox* comboBox = static_cast<QComboBox*>(editor);
    QString value = comboBox->currentText();
    model->setData(index, value, Qt::EditRole);
}

void QComboBoxItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    editor->setGeometry(option.rect);
}
