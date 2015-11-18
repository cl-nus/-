//trie
class Trie {
	private: 
		class TrieNode {
			public:
				bool isString;
				unordered_map<char, shared_ptr<TrieNode>> l;
	};
		shared_ptr<TrieNode> root;

	public:
		Trie(): root(shared_ptr<TrieNode> (new TrieNode{false})) {}

}