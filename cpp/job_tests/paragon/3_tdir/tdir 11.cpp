#include <QDir> // Access to directory structures and their contents.
#include <QDirIterator> // An iterator for directory entrylists.
#include <QTextStream> // A convenient interface for reading and writing QString text.
#include <QDateTime> // Date and time functions.
#include <exception>

void distinguishPathMask(QString&, QString&);
void checkPathAndList(const QString&, const QString&, const bool);
void listRecursively(QDir, const QString&, const bool);

const char* const cmdTdir{"tdir"}; // The tdir command.
//const QString maskAll("*"); // All directories/files mask ('*' wildcard).
//const QString maskAll("test tdir *"); // All directories/files mask ('*' wildcard).
//const QString maskAll("test"); // All directories/files mask ('*' wildcard).
//const QString maskAll("test*"); // All directories/files mask ('*' wildcard).
const QStringList maskAll("*"); // All directories/files mask ('*' wildcard).

QTextStream out(stdout); // Interface for writing QString text.

//*********************************************************************************************************************************************************
// The main function.
// In the command line, enter 'tdir [path/mask] [-r]' or 'tdir [-r] [path/mask]' to list files.
// Before lising files, the tdir command and its arguments ([path/mask] [-r]) are validated.
// Files are listed from a single directory or recursively from its subdirectories given the '-r' agrument.
//*********************************************************************************************************************************************************
int main(int argc, char** argv) {
	try {
		constexpr unsigned tdirOnly{1}; // The count of agruments when only the tdir command entered w/o path/mask or -r.
		const char* const recurKey{"-r"}; // The recursion key.
		const QString prompt = QDir::toNativeSeparators(QDir::currentPath()) + " >> "; // A prompt with the current directory.
		bool recursive{}; // The -r flag.

		out << "argc: " << argc << endl;
		for (int i = 0; i < argc; i++)
			out << "argv[" << i << "]: " << argv[i] << endl;
		out << endl;

		if (argc == tdirOnly) { // Only the tdir command entered w/o path/mask or -r.
			listRecursively(QDir::current(), maskAll, false); // List the current directory without recursion.
			return 0;
		}

		for (int i = 0; i < argc; i++) { // Check all combinations of arguments in a loop.
			if (strcmp(argv[i], recurKey) == 0) { // Is that -r?
				if (!recursive) { // Has not -r been entered before?
					recursive = true;
					continue;
				} else { // Prevent multiple -r.
					fprintf(stderr, "Only one -r can be entered.\n\n");
					return 0;
				}
			}
		}
		listRecursively(QDir::current(), maskAll, recursive); // List the current directory with or without recursion.
	}
	catch(const std::exception& exc) { // Catch and dislplay an exception.
		fprintf(stderr, "An exception occured: %s\n\n", exc.what());
	}
	return 0;
}

//*********************************************************************************************************************************************************
// List files recursively in the selected directory and all its subdirectories, if necessary.
// TO DO: More comments on the function agruments.
//*********************************************************************************************************************************************************
//void listRecursively(QDir dir, const QString& mask, const bool recursive) { //TO DO: Arrange a break-out with a thread.
void listRecursively(QDir dir, const QStringList& mask, const bool recursive) { //TO DO: Arrange a break-out with a thread.
	enum struct fieldWidth : int {size = 15, modificationDate = 20}; // Field widths for printing.
	const QString dirMark{"<DIR>"}; // A directory mark.

	dir.setSorting(QDir::Name // Sort by name.
						| QDir::DirsFirst	// Put the directories first, then the files.
						| QDir::IgnoreCase // Sort case-insensitively.
						| QDir::LocaleAware); // Sort items appropriately using the current locale settings.

	dir.setFilter(QDir::Dirs // List directories that match the filters.
					  | QDir::Files // List files.
					  | QDir::NoSymLinks // Do not list symbolic links (ignored by operating systems that don't support symbolic links).
					  | QDir::NoDotAndDotDot // Do not list the special entries "." and "..".
					  | QDir::System); // List system files (on Unix, FIFOs, sockets and device files are included; on Windows, .lnk files are included).

	QStringList filters(mask); //Set the name filters. Each name filter is a wildcard filter that understands wildcards.
	dir.setNameFilters(filters);

	out << QDir::toNativeSeparators(dir.absolutePath()) << ":" << endl; // Print the directory path atop the files contained.
	QFileInfoList list = dir.entryInfoList(); // Print each file inside that directory.
	for (const auto& fileInfo : dir.entryInfoList()) {
		out.setFieldAlignment(QTextStream::AlignRight); // Right-align file sizes and modification dates.
		out.setFieldWidth((int)fieldWidth::size);
		out << fileInfo.size();

		out.setFieldWidth((int)fieldWidth::modificationDate);
		out << fileInfo.lastModified().toString(Qt::SystemLocaleShortDate); //	The last modification date in the short format used by the operating system.

		out.setFieldAlignment(QTextStream::AlignLeft); // Left-align file names.
		out.setFieldWidth(0);
		out << "   ";
		if (fileInfo.isDir()) // <DIR> Prefix before a directory name for readability.
			out << dirMark << " ";
		out << fileInfo.fileName() << endl; // File/directory name.
	}
	out << endl;

	if (recursive) { // If listing is recursive keep iterating recursively.
		dir.setSorting(QDir::Name // Sort by name.
							| QDir::IgnoreCase // Sort case-insensitively.
							| QDir::LocaleAware ); // Sort items appropriately using the current locale settings.

		dir.setFilter(QDir::AllDirs // List all directories; i.e. don't apply the filters to directory names.
						  | QDir::NoDotAndDotDot // Do not list the special entries "." and "..".
						  | QDir::NoSymLinks // Do not list symbolic links (ignored by operating systems that don't support symbolic links).
						  | QDir::System); // List system files (on Unix, FIFOs, sockets and device files are included; on Windows, .lnk files are included).

		for (const auto& entry : dir.entryList()) {
			QString subDir = QString("%1/%2").arg(dir.absolutePath()).arg(entry);
			listRecursively(QDir(subDir), mask, recursive);
		}
	}
}
