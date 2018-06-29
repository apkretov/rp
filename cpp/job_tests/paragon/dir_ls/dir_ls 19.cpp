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

	//out << dir.absolutePath() << ":\n";						// Print the directory path atop the files contained.
	out << dir.absolutePath() << ":" << endl;						// Print the directory path atop the files contained.

	QFileInfoList list = dir.entryInfoList();				// Print each file inside that directory.
	for (const auto& fileInfo : dir.entryInfoList()) {
		out << fileInfo.fileName() << '\t';					// File name.
		if (fileInfo.isFile())									// Print only the sizes of files but skip directories.
			out << fileInfo.size() << '\t';
		else
			out << "<DIR>\t";
		//out << fileInfo.lastModified().toString(Qt::SystemLocaleShortDate) << '\n';	//	The last modification date in the short format used by the operating system.
		out << fileInfo.lastModified().toString(Qt::SystemLocaleShortDate) << endl;	//	The last modification date in the short format used by the operating system.
	}
	//out << '\n';
	out << endl;

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
		//const QString prompt("Enter: tdir [path/mask] [-r]");
		const QString tdir = QString(chrTdir);

		constexpr unsigned length = 256;
		char line[length];
		char chrCommand[length / 3]; //TO DO: Improve it.
		char chrPath[length / 3]; //TO DO: Improve it.
		char chrMask[length / 3]; //TO DO: Improve it.
		QString command;

		QString path(".");
		QString mask("*");
		const QDir currentDir(path);
		const QString prompt = currentDir.absolutePath() + " >> ";

		out << "#PSG Coding Challenge" << endl			//Welcome. Abstract.
			 << "dir/ls Utility Program" << endl << endl
			 << "To list files and directories enter: tdir [path/mask] [-r]" << endl
			 << "To quit the program enter: Ctrl+C" << endl << endl;

		while (1) {
			//out << currentDir.absolutePath();
			//printf(">> ");
			//printf(prompt);
			out << prompt;
			out.flush();
			if (fgets(line, sizeof(line), stdin) == NULL)
				exit(0);
			if (strlen(line) < strlen(chrTdir)) {		// The first item must be the tdir command. Check it first by its length.
				fprintf(stderr, "Bad command\n");
				continue;
			}

			int itemsRead = sscanf(line, "%s %s %s", chrCommand, chrPath, chrMask);
			switch (itemsRead) {
			//case 1: case 2:									// Only one item entered. That must be the tdir command.
			case 1:									// Only one item entered. That must be the tdir command.
				//OFF std::cout << "chrCommand: " << chrCommand << '\t' << "chrPath: " << chrPath << '\t' << "chrMask: " << chrMask << std::endl;
				if (QString(chrCommand) == tdir) {
					//listRecursively(QDir(path), mask);
					listRecursively(currentDir, mask);
				} else
					fprintf(stderr, "Bad command\n");
				break;
			case 2:												// Two items entered. Those must be the tdir command and a path.
				if (QString(chrCommand) == tdir)
					listRecursively(QDir(path), mask);
				else
					fprintf(stderr, "Bad command\n");
				break;
			}
		}
	}
	catch(const std::exception exc) { // Dislplay an exception.
		std::cerr << "An exception occured: " << exc.what() << std::endl;
	}
}
//		out << fileInfo.fileName();							// File name.
//		out << qSetFieldWidth(10) << left;
