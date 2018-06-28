#include <QCoreApplication> // qdir_01.cpp // A program that lists all the files in the current directory (excluding symbolic links), sorted by size, smallest first: @ http://doc.qt.io/qt-5/qdir.html#examples
#include <QDir>
#include <QTextStream>		// Provides a convenient interface for reading and writing QString text.
#include <QFileInfo>
#include <QDateTime>

int main(int argc, char *argv[]) {
	QCoreApplication app(argc, argv); // TO DO: Comment.
	QDir dir("/home/alex"); //QDir dir("."); //ORIG QDir dir; //TO DO: Comment.
	QTextStream out(stdout);		// Interface for writing text.

	dir.setSorting(QDir::Name		// Sort by name.
		| QDir::DirsFirst				// Put the directories first, then the files.
		| QDir::IgnoreCase			// Sort case-insensitively.
		| QDir::LocaleAware );		// Sort items appropriately using the current locale settings.

	dir.setFilter(QDir::Dirs		// List directories that match the filters. //TO DO: Check if directories are needed.
		| QDir::Files					// List files.
		| QDir::NoSymLinks			// Do not list symbolic links (ignored by operating systems that don't support symbolic links).
		| QDir::NoDotAndDotDot		// Do not list the special entries "." and "..".
		| QDir::System);				// List system files (on Unix, FIFOs, sockets and device files are included; on Windows, .lnk files are included).

	QStringList filters;				//Sets the name filters. Each name filter is a wildcard filter that understands * and ? wildcards.
	//OFF filters << "test*"; //TO DO: Set it.
	dir.setNameFilters(filters);

	QFileInfoList list = dir.entryInfoList();
	out << "qdir_01\n\n";
	//OFF out << "path/file_name\t file_size\t file_modification_time\n";						// Print the header.
	for (int i = 0; i < list.size(); ++i) {
		QFileInfo fileInfo = list.at(i);
		out << fileInfo.fileName() << '\t';															// Print the file name.
		out << fileInfo.size() << '\t';																// Print the size.
		out << fileInfo.lastModified().toString(Qt::SystemLocaleShortDate) << endl;	//	Print the last modification date in the short format used by the operating system.
	}
	out << '\n';
	return 0;
}
