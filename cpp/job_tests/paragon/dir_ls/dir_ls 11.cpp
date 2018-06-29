#include <QDir>					// Access to directory structures and their contents.
#include <QDirIterator>			// An iterator for directory entrylists.
#include <QTextStream>			// A convenient interface for reading and writing QString text.
#include <iostream>				// std::cerr, std::cin.get(). //TO DO: Remove it, if unnecessary.
#include <QDateTime>				// Date and time functions.
#include <exception>
//#include "errors.h"				// Handling errors.

QTextStream out(stdout);		// Interface for writing QString text.

void listRecursively(QDir dir, const QString& mask) { // List files recursively in the selected directory and all its subdirectories.
	dir.setSorting(QDir::Name					// Sort by name.
						| QDir::DirsFirst			// Put the directories first, then the files.
						| QDir::IgnoreCase		// Sort case-insensitively.
						| QDir::LocaleAware );	// Sort items appropriately using the current locale settings.

	dir.setFilter(QDir::Dirs					// List directories that match the filters. //TO DO: Check if directories are needed.
					  | QDir::Files				// List files.
					  | QDir::NoSymLinks			// Do not list symbolic links (ignored by operating systems that don't support symbolic links).
					  | QDir::NoDotAndDotDot	// Do not list the special entries "." and "..".
					  | QDir::System);			// List system files (on Unix, FIFOs, sockets and device files are included; on Windows, .lnk files are included).

	QStringList filters(mask);		//Set the name filters. Each name filter is a wildcard filter that understands * and ? wildcards.
	dir.setNameFilters(filters);

	out << dir.absolutePath() << ":\n";						// Print the directory path atop the files contained.

	QFileInfoList list = dir.entryInfoList();				// Print each file inside that directory.
	for (const auto& fileInfo : dir.entryInfoList()) {
		out << fileInfo.fileName() << '\t';					// File name.
//		out << fileInfo.fileName();							// File name.
//		out << qSetFieldWidth(10) << left;
		if (fileInfo.isFile())									// Print only the sizes of files but skip directories.
			out << fileInfo.size() << '\t';
		else
			out << "<DIR>\t";
		out << fileInfo.lastModified().toString(Qt::SystemLocaleShortDate) << '\n';	//	The last modification date in the short format used by the operating system.
	}
	out << '\n';
	//OFF std::cin.get();

	dir.setSorting(QDir::Name					// Sort by name.
						| QDir::IgnoreCase		// Sort case-insensitively.
						| QDir::LocaleAware );	// Sort items appropriately using the current locale settings.

	dir.setFilter(QDir::AllDirs				// List all directories; i.e. don't apply the filters to directory names.
					  | QDir::NoDotAndDotDot	// Do not list the special entries "." and "..".
					  | QDir::NoSymLinks			// Do not list symbolic links (ignored by operating systems that don't support symbolic links).
					  | QDir::System);			// List system files (on Unix, FIFOs, sockets and device files are included; on Windows, .lnk files are included).

	for (const auto& entry : dir.entryList()) {
		QString subDir = QString("%1/%2").arg(dir.absolutePath()).arg(entry);
		listRecursively(QDir(subDir), mask);
	}
}

int main() {
	out << "000\n";
	try {
		out << "111\n";
		const QString mask = "*";
//		const QString path = "/home/alex/rp/_stepik/c_cpp_multi-thread_programming";
		const QString path = "/home/alex/3.1/12";
//		QDir dir(path);
//		listRecursively(dir, mask);

		QString command;
//		QString mask;
//		QString path;
		//char line[256];
		out << "222\n";
		QTextStream in(stdin);
		out << "333\n";
		//QString line;
//		while (1) {
//			out << ">> ";
//			if (fgets(line, sizeof(line), stdin) == NULL)
//				exit(0);
//			if (strlen(line) <= 1)
//				continue;
//			if (sscanf(line, "%s %256[^\n]", path, mask) < 2) {
//				fprintf(stderr, "Bad command\n");
//			} else {
//				QDir dir(path);
//				listRecursively(dir, mask);
//				out << '\n';
//			}
//		}
		out << "Before while.\n";
		while (in.readLineInto(&command)) {
			out << "command: " << command << '\n';
			QDir dir(path);
			listRecursively(dir, mask);
		}
		out << '\n';
	}
	catch(const std::exception exc) { // Dislplay an exception.
		//out << "An exception in function '" + QString(__FUNCTION__) + "':\n" + exc.what() + '\n';
		//out << "An exception occured: " + QString(exc.what()) + '\n';
		std::cerr << "An exception occured: " << exc.what() << '\n';
	}
}
