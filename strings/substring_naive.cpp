# include <iostream>
# include <string>
# include <cassert>

int IsSubstring(const std::string &str, const std::string &pattern)
{
    bool found;
    int ss = str.size(), ps = pattern.size();

    // O(ss * ps)
    for (int i = 0; i <= ss - ps; ++i) {
        found = true;
        for (int j = 0; j < ps; ++j) {
            if (pattern[j] != str[i+j]) {
                found = false;
                break;
            }
        }
        if (found)
            return i;
    }
    return -1;
}

int main(int argc, char **argv)
{
    assert(IsSubstring("hello world", "he") == 0);
    assert(IsSubstring("hello world", "ello") == 1);
    assert(IsSubstring("hello world", "l") == 2);
    assert(IsSubstring("hello world", "world") == 6);

    assert(IsSubstring("hello world", "hello awesome world") == -1);
    assert(IsSubstring("hello world", "rlde") == -1);
    assert(IsSubstring("hello world", "ellow") == -1);
    assert(IsSubstring("hello world", "hi") == -1);

    return 0;
}
