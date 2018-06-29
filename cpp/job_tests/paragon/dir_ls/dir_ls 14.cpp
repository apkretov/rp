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
	try {
		const char* const chrTdir = "tdir";
		//const QString tdir = "tdir";
		const QString tdir = QString(chrTdir);
		//constexpr unsigned tdirLength = 4;

		constexpr unsigned length = 256;
		char line[length];
		char chrCommand[length / 3]; //TO DO: Improve it.
		char chrPath[length / 3]; //TO DO: Improve it.
		char chrMask[length / 3]; //TO DO: Improve it.

		QString command;
		QString path(".");
		QString mask("*");
		QDir currentDir;

		while (1) {
			printf(">> ");
			if (fgets(line, sizeof(line), stdin) == NULL)
				exit(0);
			//if (strlen(line) <= tdirLength)
			if (strlen(line) < strlen(chrTdir))
				continue;

			int itemsRead = sscanf(line, "%s %s %s", chrCommand, chrPath, chrMask);
//			if (sscanf(line, "%s %s %s", chrCommand, chrPath, chrMask) == 1 && QString(chrCommand) != tdir) {
//				fprintf(stderr, "Bad command\n"); //Parse input line into a path and a mask.
//			} else {
//				path = QString(chrPath);
//				mask = QString(chrMask);
//				out << "path: " << chrPath << '\t' << "mask: " << chrMask << endl;
//				listRecursively(path, mask);
//			}

			switch (itemsRead) {
			case 1:
				if (QString(chrCommand) == tdir) {
					//out << "path: " << chrPath << '\t' << "mask: " << chrMask << endl;
					//std::cout << "path: " << chrPath << '\t' << "mask: " << chrMask << std::endl;
					out << "path: " << path << '\t' << "mask: " << mask << endl;
					//listRecursively(path, mask);
					//listRecursively(QDir(path), mask);
					QDir dir(path);
					listRecursively(dir.absolutePath(), mask);
					continue;
				}
				else
					fprintf(stderr, "Bad command\n");
				break;
			default:
				break;
			}

		}
	}
	catch(const std::exception exc) { // Dislplay an exception.
		std::cerr << "An exception occured: " << exc.what() << '\n';
	}
}
