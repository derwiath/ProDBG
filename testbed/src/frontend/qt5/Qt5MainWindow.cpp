#include "Qt5MainWindow.h"
#include "Qt5BaseView.h"
#include "Qt5DynamicView.h"
#include "Qt5DockWidget.h"
#include "Qt5HexEditWindow.h"
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QLabel>

namespace prodbg
{

const char* QT5_BUILD_VERSION = "v0.0.1";

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Qt5MainWindow::newDynamicView()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);

	Qt5DockWidget* dock = new Qt5DockWidget(tr("Dynamic View"), this, this, m_nextView);
	dock->setAttribute(Qt::WA_DeleteOnClose, true);

	Qt5DynamicView* dynamicView = new Qt5DynamicView(this, dock, this);
	dock->setWidget(dynamicView);
	addDockWidget(Qt::LeftDockWidgetArea, dock);

	emit dynamicView->signalDelayedSetCentralWidget(dynamicView->m_statusLabel);
}

void Qt5MainWindow::newExampleView1()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);

	/*Qt5DockWidget* dock = new Qt5DockWidget(tr("Dynamic View"), this, this, m_nextView);
	dock->setAttribute(Qt::WA_DeleteOnClose, true);

	Qt5DynamicView* dynamicView = new Qt5DynamicView(this, dock, this);
	dock->setWidget(dynamicView);

	Qt5ExampleView1* exampleView = new Qt5ExampleView1(this, dock, dynamicView);
	dynamicView->m_children[0] = exampleView;
	dynamicView->assignView(exampleView);

	addDockWidget(Qt::LeftDockWidgetArea, dock);*/
}

void Qt5MainWindow::newExampleView2()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);

	/*Qt5DockWidget* dock = new Qt5DockWidget(tr("Dynamic View"), this, this, m_nextView);
	dock->setAttribute(Qt::WA_DeleteOnClose, true);

	Qt5DynamicView* dynamicView = new Qt5DynamicView(this, dock, this);
	dock->setWidget(dynamicView);

	Qt5ExampleView2* exampleView = new Qt5ExampleView2(this, dock, dynamicView);
	dynamicView->m_children[0] = exampleView;
	dynamicView->assignView(exampleView);

	addDockWidget(Qt::LeftDockWidgetArea, dock);*/
}

void Qt5MainWindow::newExampleView3()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);

	/*Qt5DockWidget* dock = new Qt5DockWidget(tr("Dynamic View"), this, this, m_nextView);
	dock->setAttribute(Qt::WA_DeleteOnClose, true);

	Qt5DynamicView* dynamicView = new Qt5DynamicView(this, dock, this);
	dock->setWidget(dynamicView);

	Qt5ExampleView3* exampleView = new Qt5ExampleView3(this, dock, dynamicView);
	dynamicView->m_children[0] = exampleView;
	dynamicView->assignView(exampleView);

	addDockWidget(Qt::LeftDockWidgetArea, dock);*/
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Qt5MainWindow::fileSettingsFinished(int result)
{
	(void)result;
}

void Qt5MainWindow::createActions()
{
	// Describe file menu actions
	///////////////////////////////////////////////////////////////////////////////////////////

	m_fileSettingsAction = new QAction(tr("Settings"), this);
	m_fileSaveLayoutAction = new QAction(tr("Save Layout"), this);
	m_fileResetLayoutAction = new QAction(tr("Reset Layout"), this);
	m_fileExitAction = new QAction(tr("Exit"), this);

	// Describe debug menu actions
	///////////////////////////////////////////////////////////////////////////////////////////

	m_debugStartAction = new QAction(tr("Start"), this);

	// Describe window menu actions
	///////////////////////////////////////////////////////////////////////////////////////////

	m_windowSplitVerticallyAction = new QAction(tr("Split Vertically"), this);
	m_windowSplitHorizontallyAction = new QAction(tr("Split Horizontally"), this);
	m_windowFillMainWindowAction = new QAction(tr("Fill Main Window"), this);
	m_windowUnfillMainWindowAction = new QAction(tr("Unfill Main Window"), this);
	m_windowDeleteViewAction = new QAction(tr("Delete View"), this);
	m_windowCloseViewAction = new QAction(tr("Close View"), this);
	m_windowCloseViewAction->setEnabled(false);

	// Describe dynamic view assignment actions
	m_windowNewDynamicViewAction = new QAction(tr("Dynamic View"), this);
	m_windowNewExampleView1Action = new QAction(tr("Example View 1"), this);
	m_windowNewExampleView2Action = new QAction(tr("Example View 2"), this);
	m_windowNewExampleView3Action = new QAction(tr("Example View 3"), this);

	m_windowAssignExampleView1Action = new QAction(tr("Example View 1"), this);
	m_windowAssignExampleView2Action = new QAction(tr("Example View 2"), this);
	m_windowAssignExampleView3Action = new QAction(tr("Example View 3"), this);

	// Descibe help menu actions
	///////////////////////////////////////////////////////////////////////////////////////////

	m_helpAboutAction = new QAction(tr("&About"), this);
	m_helpContentsAction = new QAction(tr("&Contents..."), this);
	m_helpIndexAction = new QAction(tr("&Index..."), this);
}

void Qt5MainWindow::createMenus()
{
	QMenuBar* mainMenuBar = menuBar();

	// Connect file menu
	///////////////////////////////////////////////////////////////////////////////////////////

	m_fileMenu = menuBar()->addMenu(tr("&File"));
	m_fileMenu->addAction(m_fileSaveLayoutAction);
	m_fileMenu->addAction(m_fileSettingsAction);
	m_fileMenu->addAction(m_fileResetLayoutAction);
	m_fileMenu->addSeparator();
	m_fileMenu->addAction(m_fileExitAction);

	// Connect debug menu
	///////////////////////////////////////////////////////////////////////////////////////////

	m_debugMenu = menuBar()->addMenu(tr("&Debug"));
	m_debugMenu->addAction(m_debugStartAction);

	// Connect window menu
	///////////////////////////////////////////////////////////////////////////////////////////

	m_newWindowMenu = new QMenu("New View", mainMenuBar);
	m_newWindowMenu->addAction(m_windowNewDynamicViewAction);
	m_newWindowMenu->addAction(m_windowNewExampleView1Action);
	m_newWindowMenu->addAction(m_windowNewExampleView2Action);
	m_newWindowMenu->addAction(m_windowNewExampleView3Action);

	m_dynamicWindowAssignViewMenu = new QMenu("Assign View", mainMenuBar);
	m_dynamicWindowAssignViewMenu->addAction(m_windowAssignExampleView1Action);
	m_dynamicWindowAssignViewMenu->addAction(m_windowAssignExampleView2Action);
	m_dynamicWindowAssignViewMenu->addAction(m_windowAssignExampleView3Action);

	m_dynamicWindowMenu = new QMenu("Dynamic View", mainMenuBar);
	m_dynamicWindowMenu->addAction(m_windowSplitVerticallyAction);
	m_dynamicWindowMenu->addAction(m_windowSplitHorizontallyAction);
	m_dynamicWindowMenu->addAction(m_windowFillMainWindowAction);
	m_dynamicWindowMenu->addAction(m_windowDeleteViewAction);
	m_dynamicWindowMenu->addSeparator();
	m_dynamicWindowMenu->setEnabled(false);
	m_dynamicWindowMenu->addMenu(m_dynamicWindowAssignViewMenu);

	m_windowMenu = new QMenu("&Window", mainMenuBar);
	m_windowMenu->addMenu(m_newWindowMenu);
	m_windowMenu->addAction(m_windowCloseViewAction);
	m_windowMenu->addSeparator();
	m_windowMenu->addMenu(m_dynamicWindowMenu);	

	// Connect help menu
	///////////////////////////////////////////////////////////////////////////////////////////

	m_helpMenu = menuBar()->addMenu(tr("&Help"));
	m_helpMenu->addAction(m_helpContentsAction);
	m_helpMenu->addAction(m_helpIndexAction);
	m_helpMenu->addSeparator();
	m_helpMenu->addAction(m_helpAboutAction);
}

void Qt5MainWindow::createToolBars()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

void Qt5MainWindow::createStatusBar()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Qt5MainWindow::Qt5MainWindow()
: Qt5BaseView(this, nullptr, nullptr)
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);

	

	m_backgroundWidget = new QWidget;
	QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	m_backgroundWidget->setSizePolicy(sizePolicy);
	m_backgroundWidget->setAutoFillBackground(true);
	m_backgroundWidget->setFocusProxy(this);
	setCentralWidget(m_backgroundWidget);


	createActions();
	createMenus();
	createToolBars();
	createStatusBar();

	setWindowTitle(QApplication::translate("ProDBG", "ProDBG"));
	//setUnifiedTitleAndToolBarOnMac(true);

	setCurrentWindow(nullptr, Qt5ViewType_Init);

	m_centralWidgetSet = false;

	QApplication::setStartDragDistance(48);

	m_currentViewType = Qt5ViewType_Init;
	m_lastViewType = Qt5ViewType_Init;

	m_currentView = nullptr;
	m_lastView = nullptr;
	m_currentWindowMenu = nullptr;
	m_deletingDockWidget = false;
	//m_settingsWindow = nullptr;
	m_shutdown = false;

	resetViews();

	m_id = m_mainWindow->addView();

	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(contextMenuProxy(const QPoint&)));
	connect(m_backgroundWidget, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(contextMenuProxy(const QPoint&)));

	

	QString objectName;
	objectName.setNum(m_id);
	setObjectName(objectName);

	connect(this, SIGNAL(destroyed(QObject*)), this, SLOT(shutdown(QObject*)));
}

Qt5MainWindow::~Qt5MainWindow()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);

	m_shutdown = true;
}

void Qt5MainWindow::setupWorkspace()
{
	connect(m_fileSettingsAction, SIGNAL(triggered()), this, SLOT(fileSettings()));
	connect(m_fileSaveLayoutAction, SIGNAL(triggered()), this, SLOT(fileSaveLayout()));
	connect(m_fileResetLayoutAction, SIGNAL(triggered()), this, SLOT(fileResetLayout()));
	connect(m_fileExitAction, SIGNAL(triggered()), this, SLOT(fileExit()));

	// Describe debug menu actions
	///////////////////////////////////////////////////////////////////////////////////////////

	connect(m_debugStartAction, SIGNAL(triggered()), this, SLOT(debugStart()));

	// Describe window menu actions
	///////////////////////////////////////////////////////////////////////////////////////////

	connect(m_windowSplitVerticallyAction, SIGNAL(triggered()), this, SLOT(windowSplitVertically()));
	connect(m_windowSplitHorizontallyAction, SIGNAL(triggered()), this, SLOT(windowSplitHorizontally()));
	connect(m_windowFillMainWindowAction, SIGNAL(triggered()), this, SLOT(windowFillMainWindow()));
	connect(m_windowUnfillMainWindowAction, SIGNAL(triggered()), this, SLOT(windowUnfillMainWindow()));
	connect(m_windowDeleteViewAction, SIGNAL(triggered()), this, SLOT(windowDeleteView()));
	connect(m_windowCloseViewAction, SIGNAL(triggered()), this, SLOT(windowCloseView()));

	// Describe dynamic view assignment actions
	connect(m_windowNewDynamicViewAction, SIGNAL(triggered()), this, SLOT(newDynamicView()));
	connect(m_windowNewExampleView1Action, SIGNAL(triggered()), this, SLOT(newExampleView1()));
	connect(m_windowNewExampleView2Action, SIGNAL(triggered()), this, SLOT(newExampleView2()));
	connect(m_windowNewExampleView3Action, SIGNAL(triggered()), this, SLOT(newExampleView3()));

	// Descibe help menu actions
	///////////////////////////////////////////////////////////////////////////////////////////

	connect(m_helpAboutAction, SIGNAL(triggered()), this, SLOT(helpAbout()));
	connect(m_helpContentsAction, SIGNAL(triggered()), this, SLOT(helpContents()));
	connect(m_helpIndexAction, SIGNAL(triggered()), this, SLOT(helpIndex()));

	focusInEvent(nullptr);
	m_type = Qt5ViewType_Main;
}

void Qt5MainWindow::setCurrentWindow(Qt5BaseView* widget, Qt5ViewType type)
{
	printf("Event-S: %s - %s\n", __FILE__, __FUNCTION__);

	if (m_shutdown)
		return;

	if (type == Qt5ViewType_Reset || type == Qt5ViewType_Init)
	{
		// We reset views incase a view was destroyed, or any other "risky" situation.
		m_currentView = this;
		m_currentViewType = Qt5ViewType_Main;

		m_lastView = this;
		m_lastViewType = Qt5ViewType_Main;

		if (type == Qt5ViewType_Reset)
		{
			m_dynamicWindowMenu->setEnabled(false);

	        Qt5ContextMenu* windowMenu = new Qt5ContextMenu(m_mainWindow, m_mainWindow);
	        m_mainWindow->setWindowMenu(windowMenu);
		}

		return;
	}

	if (widget == m_currentView)
	{
		// If it's the same widget... do nothing.
	}
	else if (widget)
	{
		// If we have a valid new widget, back the old one up into LastView and assign.
		m_lastView = m_currentView;
		m_lastViewType = m_currentViewType;

		m_currentView = widget;
		m_currentViewType = type;
	}

	// Make sure we setup our menu permissions anyway

	Qt5BaseView* view = m_currentView;
	Qt5ViewType viewType = m_currentViewType;

	if (m_currentViewType == Qt5ViewType_Main)
	{
		viewType = m_lastViewType;
		view = m_lastView;
	}

	while (viewType >= Qt5ViewType_Dynamic && view->m_parent && view->m_parent != this)
	{
		view = view->m_parent;
		viewType = view->m_type;
	}

	if (view && viewType == Qt5ViewType_Dynamic)
	{
		if (view->m_parent == this && view->m_parentDock != nullptr)
		{
			m_windowFillMainWindowAction->setEnabled(true);
		}
		else
		{
			m_windowFillMainWindowAction->setEnabled(false);
		}

		if (((Qt5DynamicView*)view) == centralWidget())
		{
			m_windowUnfillMainWindowAction->setEnabled(true);
		}
		else
		{
			m_windowUnfillMainWindowAction->setEnabled(false);
		}
	}
	else
	{
		m_dynamicWindowMenu->setEnabled(false);
		m_windowCloseViewAction->setEnabled(false);
	}

	// If we are in the process of deleting a dock widget...
	if (m_deletingDockWidget)
	{
		m_windowCloseViewAction->setEnabled(false);
		m_deletingDockWidget = false;
	}

	printf("Event-E: %s - %s\n", __FILE__, __FUNCTION__);
}

Qt5BaseView* Qt5MainWindow::getCurrentWindow(Qt5ViewType type)
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);

	if (m_shutdown)
		return nullptr;

	if (type == Qt5ViewType_Dock || type == Qt5ViewType_Dynamic)
	{
		Qt5DynamicView* dynamicView = nullptr;

		if (m_currentViewType == Qt5ViewType_Main)
		{
			if (m_lastViewType > Qt5ViewType_Main)
			{
				if (m_lastViewType == Qt5ViewType_Dynamic)
				{
					dynamicView = (Qt5DynamicView*)m_lastView;
				}
				else if (m_lastViewType > Qt5ViewType_Dynamic)
				{
					dynamicView = (Qt5DynamicView*)m_lastView->parent();
				}
				else
				{
					abort();
				}
			}
			else
			{
				return nullptr;
			}
		}
		else if (m_currentViewType > Qt5ViewType_Main)
		{
			if (m_currentViewType == Qt5ViewType_Dynamic)
			{
				dynamicView = (Qt5DynamicView*)m_currentView;
			}
			else if (m_currentViewType > Qt5ViewType_Dynamic)
			{
				dynamicView = (Qt5DynamicView*)m_currentView->parent();
			}
			else
			{
				abort();
			}
		}
		else
		{
			return nullptr;
		}

		if (type == Qt5ViewType_Dock)
		{
			// Navigate the object hierarchy until we find the top-level dynamic view
			while (dynamicView->m_parentDock == nullptr && dynamicView->m_parent != this)
			{
				// This is an embedded Qt5DynamicView in the Qt5MainWindow
				if (dynamicView->m_parent == this && dynamicView->m_parentDock == nullptr)
				{
					return dynamicView;
				}

				dynamicView = (Qt5DynamicView*)dynamicView->m_parent;
			}
		}
		
		return dynamicView;
	}
	else if (m_currentViewType == type)
	{
		return m_currentView;
	}
	else if (m_currentViewType == Qt5ViewType_Main && m_lastViewType == type)
	{
		return m_lastView;
	}
	else
	{
		return nullptr;	
	}
}

void Qt5MainWindow::loadLayout(Qt5Layout* layout)
{
	(void)layout;
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

void Qt5MainWindow::saveLayout()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

void Qt5MainWindow::addLayout(Qt5LayoutEntry* layoutEntry)
{
	(void)layoutEntry;
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

int Qt5MainWindow::addView()
{
	if (m_nextView >= QT5_MAX_VIEWS)
		return -1;

	int nextView = -1;

	if (m_nextView <= -1)
	{
		for (int index = 0; index < QT5_MAX_VIEWS; ++index)
		{
			if (!m_viewTable[index])
			{
				nextView = index;
				m_viewTable[index] = true;
				break;
			}
		}
	}
	else
	{
		nextView = m_nextView;
	}

	for (int index = 0; index < QT5_MAX_VIEWS; ++index)
	{
		if (!m_viewTable[index])
		{
			m_nextView = index;
			m_viewTable[index] = true;
			break;
		}
	}

	return nextView;
}

void Qt5MainWindow::deleteView(int id)
{
	m_viewTable[id] = false;
	m_nextView = -1;
}

void Qt5MainWindow::resetViews()
{
	for (int index = 0; index < QT5_MAX_VIEWS; ++index)
	{
		m_viewTable[index] = false;
	}

	m_nextView = -1;
}

void Qt5MainWindow::closeEvent(QCloseEvent*)
{
	shutdown(this);
}

void Qt5MainWindow::contextMenuEvent(QContextMenuEvent*)
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);

	if (m_shutdown)
		return;

	setCurrentWindow(this, Qt5ViewType_Main);
	
	Q_ASSERT(m_currentWindowMenu != nullptr);
	m_currentWindowMenu->display(cursor().pos());
}

void Qt5MainWindow::focusInEvent(QFocusEvent*)
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);

	if (m_currentView == this || m_shutdown)
		return;

	setCurrentWindow(this, Qt5ViewType_Main);

	if (m_lastViewType >= Qt5ViewType_Dynamic)
		return;

	Qt5ContextMenu* windowMenu = new Qt5ContextMenu(this, this);

	setWindowMenu(windowMenu);

	// We don't set a context menu here because it needs to preserve the Window
	// menu of the menuBar.
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Qt5MainWindow::fileExit()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
	close();
}

void Qt5MainWindow::fileResetLayout()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

void Qt5MainWindow::fileSettings()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

void Qt5MainWindow::fileSaveLayout()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

void Qt5MainWindow::debugStart()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

void Qt5MainWindow::helpIndex()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

void Qt5MainWindow::helpContents()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

void Qt5MainWindow::helpAbout()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

void Qt5MainWindow::setWindowMenu(Qt5ContextMenu* menu)
{
	printf("Event-S: %s - %s\n", __FILE__, __FUNCTION__);

	Q_ASSERT(menu != nullptr);

	if (m_shutdown)
		return;

	QMenuBar* mainMenuBar = menuBar();
	Q_ASSERT(mainMenuBar != nullptr);

	if (m_currentWindowMenu != nullptr)
	{		
		mainMenuBar->removeAction(m_currentWindowMenu->menuAction());
		m_currentWindowMenu->deleteLater();
	}
	else
	{
		Q_ASSERT(m_windowMenu != nullptr);
		mainMenuBar->removeAction(m_windowMenu->menuAction());
	}

	m_currentWindowMenu = menu;

	Q_ASSERT(m_helpMenu != nullptr);
	Q_ASSERT(m_currentWindowMenu != nullptr);
	mainMenuBar->insertAction(m_helpMenu->menuAction(), m_currentWindowMenu->menuAction());
	printf("Event-E: %s - %s\n", __FILE__, __FUNCTION__);
}

Qt5ContextMenu* Qt5MainWindow::getWindowMenu()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
	if (m_shutdown)
		return nullptr;

	return m_currentWindowMenu;
}

void Qt5MainWindow::triggerSignalSettings()
{
	emit signalSettings();
}

void Qt5MainWindow::triggerSignalApplyLayout(Qt5Layout* layout)
{
	emit signalApplyLayout(layout);
}

void Qt5MainWindow::windowSplitVertically()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);

	Qt5DynamicView* view = reinterpret_cast<Qt5DynamicView*>(getCurrentWindow(Qt5ViewType_Dynamic));
	if (view == nullptr)
		return;

	view->splitView(Qt::Horizontal);
}

void Qt5MainWindow::windowSplitHorizontally()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);

	Qt5DynamicView* view = reinterpret_cast<Qt5DynamicView*>(getCurrentWindow(Qt5ViewType_Dynamic));
	if (view == nullptr)
		return;

	view->splitView(Qt::Vertical);
}

void Qt5MainWindow::windowFillMainWindow()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);

	Qt5DynamicView* view = reinterpret_cast<Qt5DynamicView*>(getCurrentWindow(Qt5ViewType_Dynamic));
	if (view == nullptr)
		return;

	while (view != nullptr &&
		   view->m_type >= Qt5ViewType_Dynamic &&
		   view->m_parent != nullptr &&
		   view->m_parent != this)
	{
		view = reinterpret_cast<Qt5DynamicView*>(view->m_parent);
	}

	if (view == nullptr || view->m_parent == this)
		return;

	if (m_centralWidgetSet)
	{
		Qt5DynamicView* current = reinterpret_cast<Qt5DynamicView*>(centralWidget());
		Qt5DockWidget* dock = new Qt5DockWidget(tr("Dynamic View"), this, this, current->m_id);
		dock->setAttribute(Qt::WA_DeleteOnClose, true);
		dock->setWidget(current);
		current->m_parentDock = dock;
		addDockWidget(Qt::LeftDockWidgetArea, dock);
	}
	else if (centralWidget())
	{
		centralWidget()->deleteLater();
	}

	m_centralWidgetSet = true;

	if (view->m_parentDock != nullptr)
	{
		removeDockWidget(view->m_parentDock);
		view->m_parentDock->deleteLater();
		view->m_parentDock = nullptr;
	}

	view->setParent(this);

	emit signalDelayedSetCentralWidget(view);

	if (view->m_children[0] != nullptr)
	{
		setCurrentWindow(view->m_children[0], view->m_children[0]->m_type);
	}
	else
	{
		setCurrentWindow(view, Qt5ViewType_Dynamic);
	}
}

void Qt5MainWindow::windowUnfillMainWindow()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

void Qt5MainWindow::windowDeleteView()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

void Qt5MainWindow::windowCloseView()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);

	Qt5DynamicView* view = reinterpret_cast<Qt5DynamicView*>(getCurrentWindow(Qt5ViewType_Dynamic));
	if (view == nullptr)
		return;

	setCurrentWindow(this, Qt5ViewType_Main);

	Qt5ContextMenu* windowMenu = new Qt5ContextMenu(this, this);
	setWindowMenu(windowMenu);

	if (view->m_parentDock != nullptr)
	{
		removeDockWidget(view->m_parentDock);
		view->m_parentDock->deleteLater();
		view->m_parentDock = nullptr;
	}
	else
	{
		m_centralWidgetSet = false;
		m_backgroundWidget = new QWidget;
		m_backgroundWidget->setObjectName(QString::fromUtf8("backgroundWidget"));
		m_backgroundWidget->setAutoFillBackground(true);
		emit signalDelayedSetCentralWidget(m_backgroundWidget);
	}

	view->deleteLater();
}

void Qt5MainWindow::contextMenuProxy(const QPoint&)
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);

	if (m_shutdown)
		return;

	setCurrentWindow(this, Qt5ViewType_Main);
	m_currentWindowMenu->display(cursor().pos());
}

void Qt5MainWindow::applySettings()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

void Qt5MainWindow::buildLayout()
{
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

void Qt5MainWindow::applyLayout(Qt5Layout* layout)
{
	(void)layout;
	printf("Event: %s - %s\n", __FILE__, __FUNCTION__);
}

void Qt5MainWindow::shutdown(QObject*)
{
	m_shutdown = true;

	/*if (m_settingsWindow != nullptr)
	{
		m_settingsWindow->close();
		m_settingsWindow->deleteLater();
		m_settingsWindow = nullptr;
	}*/

// saveSettings();
	saveLayout();
}

void Qt5MainWindow::errorMessage(const QString& message)
{
	QMessageBox::critical((QWidget*)parent(), QString("Error"), QString(message), QMessageBox::Ok, QMessageBox::Ok);
}

}
