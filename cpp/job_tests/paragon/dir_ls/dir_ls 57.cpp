#include <QDir>					// Access to directory structures and their contents.
#include <QDirIterator>			// An iterator for directory entrylists.
#include <QTextStream>			// A convenient interface for reading and writing QString text.
#include <QDateTime>				// Date and time functions.
#include <iostream>				// std::cerr, std::cin.get(). //TO DO: Substitute with Qt.
#include <exception>

QTextStream out(stdout);		// Interface for writing QString text.

void listRecursively(QDir, const QString&, const bool);
//QString retrieveMask(const QString&);
bool retrieveMask(const QString&, QString&);

//*********************************************************************************************************************************************************
// main
// TO DO: Comment.
//*********************************************************************************************************************************************************
int main() {
	try {
		const char* const tdir = "tdir";										// The tdir command.

		const char* const recurKey = "-r";									// The recursion key.
		//OFF const QString cmdExit("exit");								// The exit command. //TO DO: Introduce this command.

		constexpr unsigned cmdLength = 256;									// The command maximal lengh.
		char line[cmdLength];
		char command[cmdLength];												// Either of the three entered parameters might be of the maximal lenght. That's why reserve the
																						//		maximal space for all the three.
		char pathRKey1[cmdLength];												// Either a path/mask or a recursion key (-r) (parameters 2 and 3) can be entered under these variables.
		char pathRKey2[cmdLength];
		QString path;																// Path to a directory listed.

		const QDir currentDir(".");											// The current directory.
		const QString prompt = currentDir.absolutePath() + " >> ";	// The prompt with the current directory.
		QString mask("*");														// All directories/files mask ('*' wildcard). Default.

		const char* const badCommand = "Bad command!\n\n";				// A 'Bad command' comment.

		out << "#PSG Coding Challenge" << endl								// Welcome. Abstract.
			 << "dir/ls Utility Program" << endl << endl
			 << "To list files and directories enter: tdir [path/mask] [-r]" << endl
			 << "To quit the program enter: Ctrl+C" << endl << endl;

		while (1) {															// In an endless loop, keep entering 'tdir [path/mask] [-r]' to list files and directories or 'Ctrl+C' to quit.
			out << prompt;
			out.flush();

			if (fgets(line, sizeof(line), stdin) == NULL)		// Enter the tdir command and its parameters.
				exit(0);														// Ctrl+Z pressed. Exit.
			if (strlen(line) < strlen(tdir)) {						// The first parameter must be the tdir command. First check it just by its length.
				fprintf(stderr, badCommand);							// Bad command.
				continue;
			}
			int paramsRead = sscanf(line, "%s %s %s", command, pathRKey1, pathRKey2);  //Read parameters. Get the number of them successfully read. //TO DO: Use sscan_s instead.

			if (strcmp(command, tdir) != 0) {						// Check the tdir command first. //TO DO: Resctrict the number of parameters entered to 3.
				fprintf(stderr, badCommand);							// Bad command.
				continue;
			}

			switch (paramsRead) {										// Parse the command line based on the number of parameters successfully read.
			case 1:															// Only one parameter entered. That must be the tdir command. List without recursion. //TO DO: Introduce an enumeration for cases.
				listRecursively(currentDir, mask, false);
				break;
			case 2:															// Two parameters entered. The second parameter can be either a path or a recursion key.
				if (strcmp(pathRKey1, recurKey) == 0)				// Check if the second parameter is a recursion key or not.
					listRecursively(currentDir, mask, true);		// The second parameter is a recursion key. List recursively.
				else {
					path = QString(pathRKey1);							// The second parameter is a path.
					retrieveMask(path, mask);							// If included, retrieve a mask from the end of the path.
					listRecursively(QDir(path), mask, false);		// List without recursion. //TO DO: Check if a directory entered exists. //TO DO: Parse to cut out a mask, if any.
				}
				break;
			case 3: {														// All the three parameters entered.
				if (strcmp(pathRKey1, pathRKey2) == 0) {			// The second and the third paramenters must not be the same.
					fprintf(stderr, "The second and the third paramenters must not be the same!\n\n"); // Bad command.
					continue;
				}

				bool recursive1 = false;
				if (strcmp(pathRKey1, recurKey) == 0)				// Check if the second parameter is a recursion key or not.
					recursive1 = true;									// The second parameter is a recursion key. List recursively.
				else
					path = QString(pathRKey1);							// The second parameter is a path. //TO DO: Check if a directory entered exists. //TO DO: Parse to cut out a mask, if any.

				bool recursive2 = false;
				if (strcmp(pathRKey2, recurKey) == 0)				// Check if the third parameter is a recursion key or not.
					recursive2 = true;									// The third parameter a recursion key. List recursively.
				else
					path = QString(pathRKey2);							// The third parameter is a path. //TO DO: Check if a directory entered exists. //TO DO: Parse to cut out a mask, if any.

				if (!(recursive1 || recursive2)) {					// Neither the second nor the third paramenter is a recursion key.
					fprintf(stderr, "Neither the second parameter nor the third one is a recursion key!\n\n"); // Bad command.
					continue;
				}

				listRecursively(QDir(path), mask, true);			// List recursively. //TO DO: Check if a directory entered exists. //TO DO: Parse to cut out a mask, if any.
				break;
			}
			}
		}
	}
	catch(const std::exception exc) {								// Catch and dislplay an exception.
		std::cerr << "An exception occured: " << exc.what() << std::endl;
	}
}

//*********************************************************************************************************************************************************
// Unless the path argument is completely a file mask, retrieve it from the end of the path. A mask can be appended at the end of a path after the last
// right/left slash (Linux /, Windows \). A mask must wildcards ('*', '?', [, ]). If there is any of those wildcards that is a file mask.
// TO DO: More comments on the function agruments and return values.
//*********************************************************************************************************************************************************
bool retrieveMask(const QString& path, QString& mask) {
	const char wildcards[] = {'*', '?', '['};							// The wildcards to detect a file mask.
#ifdef linux																	// OS-based slash directory separator.
	const char slash('/');
#else //#elif windows //TO DO: Correct it under in Windows Qt.
	const char slash('\\');											// Windows directory separator. //TO DO: Check a right slash in Windows.
#endif //linux

	int wildcardPos{};
	for (auto& wildcard : wildcards) {									// Find a wildcard to detect a file mask, if any.
		wildcardPos = path.indexOf(wildcard);							// The first wildcard's position.
		if (wildcardPos > -1)
			break;																// The first wildcard found.
	}
	if (wildcardPos == -1)
		return false;															// No wildcard, no mask.

	int slashPos = path.lastIndexOf(slash, wildcardPos);	// Find the position of the a slash before the first wildcard.
	if (slashPos == -1)														// No slash there.
		mask = path;															// The whole path is a mask.
	else
		mask = path.mid(slashPos + 1);									// A mask is the section of the path after the last slash.
	return true;
}

//*********************************************************************************************************************************************************
// List files recursively in the selected directory and all its subdirectories, if necessary.
// TO DO: More comments on the function agruments.
//*********************************************************************************************************************************************************
void listRecursively(QDir dir, const QString& mask, const bool recursive) { //TO DO: Arrange a break-out with a thread.
	dir.setSorting(QDir::Name					// Sort by name.
						| QDir::DirsFirst			// Put the directories first, then the files.
						| QDir::IgnoreCase		// Sort case-insensitively.
						| QDir::LocaleAware );	// Sort items appropriately using the current locale settings.

	dir.setFilter(QDir::Dirs					// List directories that match the filters. //TO DO: Check if directories are needed.
					  | QDir::Files				// List files.
					  | QDir::NoSymLinks			// Do not list symbolic links (ignored by operating systems that don't support symbolic links).
					  | QDir::NoDotAndDotDot	// Do not list the special entries "." and "..".
					  | QDir::System);			// List system files (on Unix, FIFOs, sockets and device files are included; on Windows, .lnk files are included).

	QStringList filters(mask);					//Set the name filters. Each name filter is a wildcard filter that understands wildcards.
	dir.setNameFilters(filters);

	out << dir.absolutePath() << ":" << endl;														// Print the directory path atop the files contained.
	QFileInfoList list = dir.entryInfoList();														// Print each file inside that directory.
	for (const auto& fileInfo : dir.entryInfoList()) {
		if (fileInfo.isFile())																			// Print the sizes of files only but skip directories'.
			out << fileInfo.size() << '\t';
		else
			out << "<DIR>\t";
		out << fileInfo.lastModified().toString(Qt::SystemLocaleShortDate) << '\t';	//	The last modification date in the short format used by the operating system.
		out << fileInfo.fileName() << endl;															// File name.
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
