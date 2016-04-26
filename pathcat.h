
#ifndef PATHCAT_H__
#define PATHCAT_H__

#include <stdlib.h>
#include "pathcat_.h"
#include <string>

std::string pathcat(char const *left, char const *right);
std::string pathcat(std::string const &left, std::string const &right);

static inline std::string operator / (std::string const &left, std::string const &right)
{
	return pathcat(left, right);
}

#ifdef QT_VERSION
QString qpathcat(ushort const *left, ushort const *right);
QString qpathcat(QString const &left, QString const &right);

static inline QString operator / (QString const &left, QString const &right)
{
	return qpathcat(left, right);
}

#endif

#endif
