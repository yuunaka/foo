#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::string;

namespace csntrie {
  // namespace for trie with contiguously stored node.

  typedef unsigned int uint;

  typedef struct Node {
    char label;
    bool is_leaf;
    Node(char l) : label(l), is_leaf(false){}
  } Node;

  typedef struct Element {
    Node node;
    vector<uint> children; //子ノード(element)のid

    Element(Node n) : node(n) {}
  } Element;

  class Trie {
  public:
    int add(const string& key);
    int searchExactMatch(const string& key);
    Trie() {
      // ルートノードの作成
      _set.push_back(Element(Node(0)));
    }
    ~Trie() {}
  private:
    vector<Element> _set; //ノード(element)のid番目のelementと対応
  };


  int Trie::add(const string& key) {
    cout << key << endl;
    // root nodeから探索
    uint pos = 0;
    // keyの１文字めからマッチング key.begin();
    string::const_iterator key_it = key.begin();

    for (; key_it != key.end(); ++key_it) {
      cout << *key_it << endl;

      // 子ノードを走査
      vector<uint>::iterator c_cur = _set[pos].children.begin();
      vector<uint>::iterator c_end = _set[pos].children.end();
      while (c_cur != c_end) {

        // 注：葉であっても子を作れることにする。
        if (_set[*c_cur].node.label == *key_it) {
          pos = *c_cur;
          break;
        }
        ++c_cur;
      }
      if (c_cur == c_end) {
        // 見つからなかったのでノードを追加する
        // idは現在のelement数とすることで、_setの添字と対応させる
        _set[pos].children.push_back(_set.size());
        _set.push_back(Element(Node(*key_it)));
      }
    }
    return 1;
  }
}
