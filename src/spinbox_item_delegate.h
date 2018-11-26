#ifndef SPINBOX_ITEM_DELEGATE_H
#define SPINBOX_ITEM_DELEGATE_H

#include "qt_custom_rpfm_global.h"
#include <QStyledItemDelegate>
#include <QAbstractItemDelegate>
#include <QSpinBox>

extern "C" void new_spinbox_item_delegate(QObject *parent = 0, const int column = 0, const int integer_type = 0);

class QSpinBoxItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:

    explicit QSpinBoxItemDelegate(QObject *parent = 0, const int integer_type = 0);

    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:

private:
    int type;
};

#endif // SPINBOX_ITEM_DELEGATE_H
