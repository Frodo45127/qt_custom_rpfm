#include "treeview_filter.h"
#include <QSortFilterProxyModel>
#include <QItemSelection>
#include <QRegExp>
#include <QStandardItem>
#include <QStandardItemModel>

// Function to create the filter in a way that we don't need to bother Rust with new types.
extern "C" QSortFilterProxyModel* new_treeview_filter(QObject *parent) {
    QTreeViewSortFilterProxyModel* filter = new QTreeViewSortFilterProxyModel(parent);
    return dynamic_cast<QSortFilterProxyModel*>(filter);
}

// Funtion to trigger the filter we want, instead of the default one from Rust.
extern "C" void trigger_treeview_filter(QSortFilterProxyModel* filter, QRegExp* pattern) {
    QTreeViewSortFilterProxyModel* filter2 = static_cast<QTreeViewSortFilterProxyModel*>(filter);
    filter2->setFilterRegExp(*pattern);
}

// Constructor of QTreeViewSortFilterProxyModel.
QTreeViewSortFilterProxyModel::QTreeViewSortFilterProxyModel(QObject *parent): QSortFilterProxyModel(parent) {}

// Function called when the filter changes.
bool QTreeViewSortFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {

    // Check the current item.
    bool result = QSortFilterProxyModel::filterAcceptsRow(source_row, source_parent);
    QModelIndex currntIndex = sourceModel()->index(source_row, 0, source_parent);
    if (sourceModel()->hasChildren(currntIndex)) {

        // If it has children...
        for (int i = 0; i < sourceModel()->rowCount(currntIndex) && !result; ++i) {

            // Keep the parent if a children is shown.
            result = result || filterAcceptsRow(i, currntIndex);
        }
    }
    return result;
}
