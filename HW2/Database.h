#pragma once
#include <vector>
#include "Media.h"
using namespace std;

class Database {
    vector<media::Media*> items;

public:
    ~Database();
    void add(media::Media* item);
    void remove(int id);
    void list() const;
};
