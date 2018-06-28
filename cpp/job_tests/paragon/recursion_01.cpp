#include <QDirIterator>
#include <QDebug>
#include <QDir>

unsigned long count = 0;

void scanDir(QDir dir) { // Recursively iterate over all the files in a directory and its subdirectories in Qt @ https://stackoverflow.com/questions/8052460/recursively-iterate-over-all-the-files-in-a-directory-and-its-subdirectories-in/8057236 // Also: Recursively searching for files in the computer @ https://stackoverflow.com/questions/25639874/recursively-searching-for-files-in-the-computer
	//ORIG dir.setNameFilters(QStringList("*.nut"));
	dir.setNameFilters(QStringList("*"));
	dir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);

	qDebug() << "Scanning: " << dir.path();

	QStringList fileList = dir.entryList();
	for (int i=0; i<fileList.count(); i++)	{
		//OFF if(fileList[i] != "main.nut" && fileList[i] != "info.nut") {
		//OFF 	qDebug() << "Found file: " << fileList[i];
		//OFF }
	}

	dir.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
	QStringList dirList = dir.entryList();
	for (int i=0; i<dirList.size(); ++i) {
		QString newPath = QString("%1/%2").arg(dir.absolutePath()).arg(dirList.at(i));
		scanDir(QDir(newPath));
	}
}

int main() {
	//QDir dir("/home/alex/3.1/");
	//QDir dir("/home/alex/rp/_stepik/c_cpp_multi-thread_programming");
	QDir dir("/");
	qDebug() << "Scanning: " << dir.path();
	scanDir(dir);
}
