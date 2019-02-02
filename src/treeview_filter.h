#ifndef TREEVIEW_FILTER_H
#define TREEVIEW_FILTER_H

#include "qt_custom_rpfm_global.h"
#include <QSortFilterProxyModel>
#include <QStandardItem>

extern "C" QSortFilterProxyModel* new_treeview_filter(QObject *parent = 0);
extern "C" void trigger_treeview_filter(QSortFilterProxyModel *filter = 0, QRegExp* pattern = 0, bool filter_by_folder = false);

class QTreeViewSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:

    explicit QTreeViewSortFilterProxyModel(QObject *parent = 0);
    bool filterAcceptsRow(int source_row, const QModelIndex & source_parent) const;

    bool filter_by_folder;
signals:

private:
};



#endif // TREEVIEW_FILTER_H
