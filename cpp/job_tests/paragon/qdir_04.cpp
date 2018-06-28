/*
#include <QDirIterator>
#include <QDebug>
#include <QDir>					// Access to directory structures and their contents.

int main() {
	QDir dir("/home/alex/3.1/"); //QDir dir("/home/alex"); //QDir dir("."); //QDir dir("g:\\"); //QDir dir; //ORIG QDir dir; //TO DO: Comment.
//	// Unlike QDir::entryList(), QDirIterator does not support sorting.
//	dir.setSorting(QDir::Name			// Sort by name.
//		 | QDir::DirsFirst				// Put the directories first, then the files.
//		 | QDir::IgnoreCase				// Sort case-insensitively.
//		 | QDir::LocaleAware );			// Sort items appropriately using the current locale settings.

	dir.setFilter(QDir::Dirs			// List directories that match the filters. //TO DO: Check if directories are needed.
		 | QDir::Files						// List files.
		 | QDir::NoSymLinks				// Do not list symbolic links (ignored by operating systems that don't support symbolic links).
		 | QDir::NoDotAndDotDot			// Do not list the special entries "." and "..".
		 | QDir::System);					// List system files (on Unix, FIFOs, sockets and device files are included; on Windows, .lnk files are included).

	//ORIG QDirIterator it("/sys", QStringList() << "scaling_cur_freq", QDir::NoFilter, QDirIterator::Subdirectories); // Here's how to find and read all files filtered by name, recursively: @ http://doc.qt.io/qt-5/qdiriterator.html
	//QDirIterator it("/home/alex/3.1/", QDirIterator::Subdirectories); // Here's how to find and read all files filtered by name, recursively: @ http://doc.qt.io/qt-5/qdiriterator.html
	QDirIterator it(dir, QDirIterator::Subdirectories); // Here's how to find and read all files filtered by name, recursively: @ http://doc.qt.io/qt-5/qdiriterator.html
	while (it.hasNext()) {
		 QFile f(it.next());
		 //ORIG f.open(QIODevice::ReadOnly);
		 //ORIG qDebug() << f.fileName() << f.readAll().trimmed().toDouble() / 1000 << "MHz";
		 qDebug() << f.fileName();
	}
}
*/
