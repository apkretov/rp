#include <QDir>					// Access to directory structures and their contents.
#include <QDirIterator>			// An iterator for directory entrylists.
#include <QTextStream>			// A convenient interface for reading and writing QString text.
#include <iostream>				// std::cerr, std::cin.get(). //TO DO: Remove it, if unnecessary.
#include <QDateTime>				// Date and time functions.
#include <vector>
#include <string>
#include <exception>

QTextStream out(stdout);		// Interface for writing QString text.

//*********************************************************************************************************************************************************
// List files recursively in the selected directory and all its subdirectories, if necessary.
// TO DO: More comments on dir, mask, recursive.
//*********************************************************************************************************************************************************
void listRecursively(QDir dir, const QString& mask, const bool recursive) {
	dir.setSorting(QDir::Name					// Sort by name.
						| QDir::DirsFirst			// Put the directories first, then the files.
						| QDir::IgnoreCase		// Sort case-insensitively.
						| QDir::LocaleAware );	// Sort items appropriately using the current locale settings.

	dir.setFilter(QDir::Dirs					// List directories that match the filters. //TO DO: Check if directories are needed.
					  | QDir::Files				// List files.
					  | QDir::NoSymLinks			// Do not list symbolic links (ignored by operating systems that don't support symbolic links).
					  | QDir::NoDotAndDotDot	// Do not list the special entries "." and "..".
					  | QDir::System);			// List system files (on Unix, FIFOs, sockets and device files are included; on Windows, .lnk files are included).

	QStringList filters(mask);					//Set the name filters. Each name filter is a wildcard filter that understands * and ? wildcards.
	dir.setNameFilters(filters);

	out << dir.absolutePath() << ":" << endl;				// Print the directory path atop the files contained.

	QFileInfoList list = dir.entryInfoList();				// Print each file inside that directory.
	for (const auto& fileInfo : dir.entryInfoList()) {
		//out << fileInfo.fileName() << '\t';					// File name.
		out << fileInfo.filePath() << '\t';					// File name.
		if (fileInfo.isFile())									// Print only the sizes of files but skip directories.
			out << fileInfo.size() << '\t';
		else
			out << "<DIR>\t";
		out << fileInfo.lastModified().toString(Qt::SystemLocaleShortDate) << endl;	//	The last modification date in the short format used by the operating system.
	}
	out << endl;

	if (recursive) {									// If listing is recursive keep iterating recursively.
		dir.setSorting(QDir::Name					// Sort by name.
							| QDir::IgnoreCase		// Sort case-insensitively.
							| QDir::LocaleAware );	// Sort items appropriately using the current locale settings.

		dir.setFilter(QDir::AllDirs				// List all directories; i.e. don't apply the filters to directory names.
						  | QDir::NoDotAndDotDot	// Do not list the special entries "." and "..".
						  | QDir::NoSymLinks			// Do not list symbolic links (ignored by operating systems that don't support symbolic links).
						  | QDir::System);			// List system files (on Unix, FIFOs, sockets and device files are included; on Windows, .lnk files are included).

		for (const auto& entry : dir.entryList()) {
			QString subDir = QString("%1/%2").arg(dir.absolutePath()).arg(entry);
			listRecursively(QDir(subDir), mask, recursive);
		}
	}
}

//*********************************************************************************************************************************************************
// main
// TO DO: Comment.
//*********************************************************************************************************************************************************
int main() {
	try {
		const char* const chrTdir = "tdir";									// The tdir command.
		const QString cmdTdir = QString(chrTdir);
		//OFF const QString cmdExit("exit");								// The exit command.

		constexpr unsigned cmdLength = 1024;								// The command maximum lengh.
		char line[cmdLength];
		char chrCommand[cmdLength / 3]; //TO DO: Improve it.
//		char chrPath[cmdLength / 3]; //TO DO: Improve it.
//		char chrMask[cmdLength / 3]; //TO DO: Improve it.
		//char chrParam1[cmdLength / 3]; //TO DO: Improve it.
		//char chrParam2[cmdLength / 3]; //TO DO: Improve it.

		std::vector<std::string> params;										// Path and recursion key command parameters.
		//std::vector<char*> params;										// Path and recursion key command parameters.

		const QDir currentDir(".");											// The current directory.
		const QString prompt = currentDir.absolutePath() + " >> ";	// The prompt with the current directory.
		QString mask("*");

		const char* const errComment = "Bad command!\n";				// A 'Bad command' comment. //TO DO: Remove it, if used only in one place as so far.

		out << "#PSG Coding Challenge" << endl								// Welcome. Abstract.
			 << "dir/ls Utility Program" << endl << endl
			 //<< "To list files and directories enter: tdir [path/mask] [-r]" << endl
				 << "To list files and directories enter: tdir [path/mask] [-r]" << endl
			 << "To quit the program enter: Ctrl+C" << endl << endl;

		while (1) {														// In an endless loop, keep entering 'tdir [path/mask] [-r]' to list files and directories or 'Ctrl+C' to quit.
			out << prompt;
			out.flush();
			if (fgets(line, sizeof(line), stdin) == NULL)
				exit(0);
			if (strlen(line) < strlen(chrTdir)) {				// The first item must be the tdir command. First check it just by its length.
				fprintf(stderr, "Bad command\n");
				continue;
			}
			//int itemsRead = sscanf(line, "%s %s %s", chrCommand, chrPath, chrMask); //TO DO: Use sscan_s instead.
			//int itemsRead = sscanf(line, "%s %s %s", chrCommand, chrParam1, chrParam2); //TO DO: Use sscan_s instead.
			//int itemsRead = sscanf(line, "%s %s %s", chrCommand, params[0], params[1]); //TO DO: Use sscan_s instead.
			int itemsRead = sscanf(line, "%s %s %s", chrCommand, params[0], params[1]); //TO DO: Use sscan_s instead.
			//OFF std::cout << "chrCommand: " << chrCommand << '\t' << "chrPath: " << chrPath << '\t' << "chrMask: " << chrMask << std::endl;

			if (QString(chrCommand) != cmdTdir) {			// Check the tdir command first.
				fprintf(stderr, errComment);					// Bad command.
				continue;
			}

			switch (itemsRead) {										// Parse the command line based on the number of parameters entered.
			case 1:														// Only one item entered. That must be the tdir command. List without recursion. //TO DO: Introduce an enumeration for cases.
					listRecursively(currentDir, mask, false);
				break;
//			case 2:														// Two items entered. Those must be the tdir command and a path. List without recursion.
//					QString path(chrPath);							// Create a path entered.
//					listRecursively(QDir(path), mask, false);
			case 2:														// Two items entered. The second item can be either a path or a recursion key.
					//QString path(chrParam1);						// Create a path entered.
					//QString path(params[0]);						// Create a path entered.
					QString path(params[0].c_str());				// Create a path entered.
					listRecursively(QDir(path), mask, false);
				break;
			}
		}
	}
	catch(const std::exception exc) {							// Catch and dislplay an exception.
		std::cerr << "An exception occured: " << exc.what() << std::endl;
	}
}
//		out << qSetFieldWidth(10) << left;
