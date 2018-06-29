#include <QDir>					// Access to directory structures and their contents.
#include <QDirIterator>			// An iterator for directory entrylists.
#include <QTextStream>			// A convenient interface for reading and writing QString text.
#include <iostream>				// std::cerr, std::cin.get(). //TO DO: Remove it, if unnecessary.
#include <QDateTime>				// Date and time functions.
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
		const char* const tdir = "tdir";									// The tdir command.
		//const QString cmdTdir = QString(tdir);

		const char* const recurKey = "-r";									// The recursion key.
		//OFF const QString cmdExit("exit");								// The exit command.

		constexpr unsigned cmdLength = 1024;								// The command maximal lengh.
		char line[cmdLength];
		char command[cmdLength];												// Either of the three entered parameters might be of the maximal lenght.
																						//		That's why reserve the maximal space for all the three.
		char pathRKey1[cmdLength];												// Either a path/mask or a recursion key (-r) (parameters 2 and 3) can be entered under these variables.
		char pathRKey2[cmdLength];
		QString path;																// Path to a directory listed.

		const QDir currentDir(".");											// The current directory.
		const QString prompt = currentDir.absolutePath() + " >> ";	// The prompt with the current directory.
		QString mask("*");														// All directories/files mask ('*' wildcard).

		const char* const badCommand = "Bad command!\n";				// A 'Bad command' comment.

		out << "#PSG Coding Challenge" << endl								// Welcome. Abstract.
			 << "dir/ls Utility Program" << endl << endl
				 << "To list files and directories enter: tdir [path/mask] [-r]" << endl
			 << "To quit the program enter: Ctrl+C" << endl << endl;

		while (1) {															// In an endless loop, keep entering 'tdir [path/mask] [-r]' to list files and directories or 'Ctrl+C' to quit.
			out << prompt;
			out.flush();

			// Enter the tdir command and its parameters.
			if (fgets(line, sizeof(line), stdin) == NULL)		// Ctrl+Z pressed. Exit.
				exit(0);
			if (strlen(line) < strlen(tdir)) {						// The first parameter must be the tdir command. First check it just by its length.
				fprintf(stderr, badCommand);							// Bad command.
				continue;
			}
			int paramsRead = sscanf(line, "%s %s %s", command, pathRKey1, pathRKey2);  //Read parameters. Get the number of them successfully read. //TO DO: Use sscan_s instead.

			if (strcmp(command, tdir) != 0) {						// Check the tdir command first.
				fprintf(stderr, badCommand);							// Bad command.
				continue;
			}

			switch (paramsRead) {										// Parse the command line based on the number of parameters successfully read.
			case 1:															// Only one parameter entered. That must be the tdir command. List without recursion. //TO DO: Introduce an enumeration for cases.
				listRecursively(currentDir, mask, false);
				break;
			case 2:															// Two parameters entered. The second parameter can be either a path or a recursion key.
				if (strcmp(pathRKey1, recurKey) != 0) {			// Check if the second parameter is a recursion key or not.
					//QString path(pathRKey1);							// The second parameter should be a path.
					path = QString(pathRKey1);							// The second parameter is a path.
					listRecursively(QDir(path), mask, false);		// List without recursion. //TO DO: Check if a directory entered exists. //TO DO: Parse to cut out a mask, if any.
				}
				else
					listRecursively(currentDir, mask, true);		// That is a recursion key. List recursively.
				break;
			case 3:															// All the three parameters entered.

				break;
			}
		}
	}
	catch(const std::exception exc) {							// Catch and dislplay an exception.
		std::cerr << "An exception occured: " << exc.what() << std::endl;
	}
}
//		out << qSetFieldWidth(10) << left;
