#include "lexer.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "Command.h"
#include "AssignCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include <vector>
#include <unordered_map>
#include "LoopCommand.h"
#include "IfCommand.h"

using namespace std;
bool flag = true;
vector<string>vec;
symbolTables st;
unordered_map<string,Command*> cmdMap({
                                             {"openDataServer", new OpenServerCommand(&st)},
                                             {"connectControlClient",new ConnectCommand(&st)},
                                             {"=", new AssignCommand(&st)},
                                             {"var", new DefineVarCommand(&st)},
                                             {"Print", new PrintCommand(&st)},
                                             {"Sleep", new SleepCommand(&st)},
                                             {"if", new IfCommand(&st)},
                                             {"while", new LoopCommand(&st)}
                                     });

/**this is the main class.
 * @param argc the size of argsv.
 * @param argv the argumants, the file name.
 * @return int 0 if all goes well.
 */
int main(int argc, char const *argv[]) {
    lexer l;
    vec = l.open_file_for_lex(argv[argc-1]);
    unsigned int i = 0;
    while (i < vec.size() - 2) {
        if (cmdMap[vec[i]]) {
            Command *c = cmdMap[vec[i]];
            i += c->execute(i);
        } else if (vec[i+1] == "=") {
            Command *c = cmdMap[vec[i+1]];
            i += c->execute(i);
        }
    }
    return 0;
}