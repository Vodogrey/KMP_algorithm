#include "KMP.h"

#include <qstring.h>
#include <qdebug.h>

KMP::KMP(QObject* parent) : QObject(parent)
{	
}


KMP::~KMP()
{
}

void KMP::makeKMP(QString line, QString text)
{
    str = line + "#" + text;
    inputLine = line;

    z.resize(str.size());

    z[0] = 0;

    for (int i=1;i<str.size();++i) {
        int pos = z[i-1];
        while (pos != -1 && str[i] != str[pos])
          pos = pos - 1 >= 0 ? z[pos-1] : -1;
        z[i] = pos + 1;
      }

    for(int i = 0; i< str.size(); i++) {
        if (z[i] == line.size()) {
              inputs << i - 2*line.size();
        }
    }
    emit results();
}


void KMP::clear()
{
    z.clear();
    inputs.clear();

}

int KMP::getInputsSize()
{
    return inputs.size();
}

int KMP::getInputsElement(int pos)
{
    return inputs.at(pos);
}

QString KMP::getInputLine()
{
    return inputLine;
}
