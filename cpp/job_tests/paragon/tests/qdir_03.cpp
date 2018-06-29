#include <QCoreApplication>
#include <QTextStream> // Last read, last modified @ http://zetcode.com/gui/qt5/files/
#include <QFileInfo>
#include <QDateTime>

int main_qdir_03(int argc, char *argv[]) {
	QCoreApplication app(argc, argv);

	QTextStream out(stdout);

	if (argc != 2) {

		qWarning("Usage: file_times file");
		return 1;
	}

	QString filename = argv[1];

	QFileInfo fileinfo(filename);

	QDateTime last_rea = fileinfo.lastRead();
	QDateTime last_mod = fileinfo.lastModified();

	out << "Last read: " << last_rea.toString() << endl;
	out << "Last modified: " << last_mod.toString() << endl;
}
