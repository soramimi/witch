
#ifndef __PATHCAT__H
#define __PATHCAT__H

#include <stdlib.h>
#include <vector>
#include <string>

#ifdef _WIN32
#include <mbctype.h>
#endif

template <typename T> static inline void trim_quote_(T const **begin, T const **end)
{
	if (*begin + 1 < *end && (*begin)[0] == '"' && (*end)[-1] == '"') {
		(*begin)++;
		(*end)--;
	}
}

template <typename T> static inline void trim_right_separator_(T const *left, T const **right)
{
	T const *p = *right;
	while (left < p && (p[-1] == '/' || p[-1] == '\\')) {
		p--;
	}
	*right = p;
}

#ifdef _WIN32
template <> static inline void trim_right_separator_<char>(char const *left, char const **right)
{
	char const *end = *right;
	char const *s = 0;
	char const *p = left;
	while (p < end) {
		int c = *p & 0xff;
		if (_ismbblead(c)) {
			s = 0;
			p++;
			if (p < end) {
				p++;
			}
		} else if (c == '/' || c == '\\') {
			if (!s) s = p;
			p++;
		} else {
			s = 0;
			p++;
		}
	}
	if (s) *right = s;
}
#endif

template <typename T> static inline void trim_left_separator_(T const **left, T const *right)
{
	T const *p = *left;
	while (p < right && (p[0] == '/' || p[0] == '\\')) {
		p++;
	}
	*left = p;
}

template <typename T, typename U> void pathcat_(T const *left, T const *leftend, T const *right, T const *rightend, U *vec)
{
	size_t len = 1;
	if (left) {
		trim_quote_(&left, &leftend);
		trim_right_separator_(left, &leftend);
		len += leftend - left;
	}
	if (right) {
		trim_quote_(&right, &rightend);
		trim_left_separator_(&right, rightend);
		len += rightend - right;
	}
	vec->clear();
	vec->reserve(len);
	if (left) {
		vec->insert(vec->end(), left, leftend);
	}
	vec->push_back('/');
	if (right) {
		vec->insert(vec->end(), right, rightend);
	}
}

template <typename T, typename U> void pathcat_(T const *left, T const *right, U *vec)
{
	T const *leftend = 0;
	T const *rightend = 0;
	if (left)  leftend = left + std::char_traits<T>::length(left);
	if (right) rightend = right + std::char_traits<T>::length(right);
	pathcat_(left, leftend, right, rightend, vec);
}

#endif
