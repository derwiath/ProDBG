#include "Qt5Locals.h"
#include "ProDBGAPI.h"
#include "Qt5DebugSession.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace prodbg
{

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Qt5Locals::Qt5Locals(QWidget* parent) : QTreeWidget(parent)
{
	setColumnCount(4);

	QStringList headers;
	headers << "Name" << "Value" << "Type" << "Address";

	setHeaderLabels(headers);

	g_debugSession->addLocals(this);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Qt5Locals::updateLocals(PDLocals* locals, int count)
{
	QList<QTreeWidgetItem*> items;

	clear();
	
	for (int i = 0; i < count; ++i) 
	{
		QStringList temp;
		
		PDLocals* local = &locals[i];

		temp << local->name << local->value << local->type << local->address;
		items.append(new QTreeWidgetItem((QTreeWidget*)0, temp)); 
	}

	insertTopLevelItems(0, items);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


}

