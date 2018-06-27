/*
#include <QCoreApplication> // Use filters to filter files/folders, and set the path in QDir object: @ https://stackoverflow.com/questions/17446881/how-to-get-a-complete-path-from-one-with-wildcards
#include <QDir>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
	QCoreApplication app(argc, argv);

	QStringList filters;
	//ORIG filters << "my*file";
	//filters << "*";
	//filters << "*.o";
	//filters << "Make*";
	//filters << "M*f*";
	//filters << "M*k*";
	//filters << "M?k*";
	//filters << "?ake*";
	//filters << "??ke*";
	filters << "???e*";
	//filters << "*??e*";

	//ORIG QDir dir("C:/path/to/");
	QDir dir(".");
	QStringList dirs = dir.entryList(filters);

//ORIG
//	if (dirs.size() > 0)	{
//		//ORIG qDebug() << dirs.at(0);
//		cout << dirs.at(0).toLocal8Bit().constData() << endl; // QStringList Class @ http://doc.qt.io/qt-5/qstringlist.html
//	}

	//ORIG QStringList::const_iterator constIterator; // STL-style iterator: @ http://doc.qt.io/qt-5/qstringlist.html
	//ORIG for (constIterator = fonts.constBegin(); constIterator != fonts.constEnd(); ++constIterator)
	for (auto constIterator = dirs.constBegin(); constIterator != dirs.constEnd(); ++constIterator) // STL-style iterator: @ http://doc.qt.io/qt-5/qstringlist.html
		cout << (*constIterator).toLocal8Bit().constData() << endl;

	return 0;
}
*/
