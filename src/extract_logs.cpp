#include <bits/stdc++.h>

using namespace std;

void createIndex(const string& logFilePath, const string& indexFilePath) {
    ifstream logFile(logFilePath, ios::binary);
    if (!logFile) {
        cerr << "Error: Unable to open log file." << endl;
        return;
    }

    ofstream indexFile(indexFilePath);
    if (!indexFile) {
        cerr << "Error: Unable to create index file." << endl;
        return;
    }

    string line, lastDate;
    streampos lastPos = 0;

    while (getline(logFile, line)) {
        if (line.size() < 10) continue; 
        string date = line.substr(0, 10); 
        if (date != lastDate) {
            indexFile << date << " " << lastPos << "\n";
            lastDate = date;
        }
        lastPos = logFile.tellg();
    }

    logFile.close();
    indexFile.close();
    cout << "Index file created successfully." << endl;
}

void extractLogs(const string& logFilePath, const string& indexFilePath, const string& targetDate, const string& outputFilePath) {
    ifstream indexFile(indexFilePath);
    if (!indexFile) {
        cerr << "Error: Unable to open index file." << endl;
        return;
    }

    unordered_map<string, streampos> indexMap;
    string date;
    streamoff offset;

    while (indexFile >> date >> offset) {
        indexMap[date] = streampos(offset);
    }
    indexFile.close();

    if (indexMap.find(targetDate) == indexMap.end()) {
        cerr << "Error: No logs found for the specified date." << endl;
        return;
    }

    ifstream logFile(logFilePath, ios::binary);
    if (!logFile) {
        cerr << "Error: Unable to open log file." << endl;
        return;
    }

    logFile.seekg(indexMap[targetDate]);

    ofstream outputFile(outputFilePath);
    if (!outputFile) {
        cerr << "Error: Unable to create output file." << endl;
        return;
    }

    string line;
    while (getline(logFile, line)) {
        if (line.size() < 10) continue;
        string currentDate = line.substr(0, 10);
        if (currentDate != targetDate) break;
        outputFile << line << "\n";
    }

    logFile.close();
    outputFile.close();
    cout << "Logs extracted successfully to " << outputFilePath << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <YYYY-MM-DD>" << endl;
        return 1;
    }

    string targetDate = argv[1];
    string logFilePath = "large_log_file.txt"; 
    string indexFilePath = "log_index.txt";    
    string outputFilePath = "output/output_" + targetDate + ".txt";

    ifstream indexFile(indexFilePath);
    if (!indexFile.good()) {
        createIndex(logFilePath, indexFilePath);
    }
    indexFile.close();

    extractLogs(logFilePath, indexFilePath, targetDate, outputFilePath);

    return 0;
}
