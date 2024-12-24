#include <iostream>
#include "readJson.h"
#include "help.h"
#include "request.h"

int main() {
    Schema schema = readJson("C:\\Users\\USTremble\\Desktop\\pr1main\\schema.json"); // важно указать путь
    createDir(schema);

    while (true) {
        string command;
        getline(cin, command);

        Vector<string> tokens = split(command, " ");
        string SQLCommand = tokens.get(0);

        try {
            if (SQLCommand == "INSERT") {
                preInsert(tokens, schema);
            } else if (SQLCommand == "DELETE") {
                preDelete(tokens, schema);
            } else if (SQLCommand == "SELECT") {
                preSelect(tokens, schema);
            } else if (SQLCommand == "EXIT") {
                break;
            } else {
                cerr << "Unknown command" << endl;
            }
        }
        catch(const exception& e) {
            cerr << e.what() << '\n';
        }
    }
    return 0;
}
