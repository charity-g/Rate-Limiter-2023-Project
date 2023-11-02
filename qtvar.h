#ifndef _QTVAR_H_
#define _QTVAR_H_

#include <cmath>
#include <utility>

using namespace std;

class qtvar : public quadtree {
public:
    qtvar(PNG& im) : quadtree(im) {}

private:
    bool prunable(Node* node, const int tol) const;
};

#endif