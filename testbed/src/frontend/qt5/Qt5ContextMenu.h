#pragma once

#include <QMenu>

namespace prodbg
{

class Qt5MainWindow;
class Qt5BaseView;

class Qt5ContextMenu : public QMenu
{
	Q_OBJECT

public:
	Qt5ContextMenu(Qt5MainWindow* mainWindow, Qt5BaseView* parent = nullptr);
	virtual ~Qt5ContextMenu();

	void display(QPoint position);

protected:
	Qt5MainWindow* m_mainWindow;
	Qt5BaseView* m_parent;
};

}
