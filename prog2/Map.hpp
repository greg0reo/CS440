#ifndef CustomMap
#include <iostream>
#include <utility>

#define MAXLEVEL 16
#endif


template <typename Key_T, typename Mapped_T>
class Map {

private:
	size_t current_size = 0;

public:
	class SkipList {
		Key_T min, max;
public:
		//Forward Delcarations
		struct Iterator;
		struct ConstIterator;
		struct ReverseIterator;

protected:
		const Iterator* head[MAXLEVEL], tail[MAXLEVEL];
public:
		struct Node {
			Key_T key;
			Mapped_T value;
			Node* next;
			Node(Mapped_T value = NULL, Node* next = nullptr, Key_T key = NULL) : key(key), value(value), next(next) {}
		};
		SkipList(Key_T min, Key_T max) : min(min), max(max){
			tail = new Node(max);
			head = new Node(min, &tail);	
			for(int i = 0; i < MAXLEVEL; ++i)
				head[i] = new Iterator(head, i);
		}
		void insert(Key_T searchKey, Mapped_T newValue) {
			//To be implemented	
		}	

	//Iterators
	struct Iterator {
		friend class SkipList;	
	
		Node* node_p;
		int tier;
		Iterator (const Node& node, int tier = 0) : node_p(node), tier(tier) {}
		~Iterator() {}	
		Iterator& operator++(){ node_p = node_p->next; return *this; }
		Iterator operator++(int) { Iterator it = *this; ++*this; return it; }
		std::pair<const Key_T, Mapped_T> operator*() const { 
			return node_p == nullptr ? std::pair<const Key_T, Mapped_T>(NULL,NULL) : std::pair<const Key_T, Mapped_T>(node_p->key, node_p->value); }
		Iterator begin() const { return Iterator(this->head[tier]); }
		Iterator end() const { return NULL; }
		
	};
	struct ConstIterator : public Iterator {	
		const std::pair<const Key_T, Mapped_T> &operator*() const;
		const std::pair<const Key_T, Mapped_T> *operator->() const;

	};
	struct ReverseIterator : public Iterator {
		ReverseIterator& operator++() {}
		ReverseIterator operator++(int) {}
		ReverseIterator& operator--() {}
		ReverseIterator operator--(int) {}
	};
	};
	
	Map() {}
	Map(const Map&) {
		//this.valueType = Map.valueType;
	}
	Map &operator=(const Map&) {
		//return this.valueType == Map.valueType;
	}
	~Map();
	size_t size() const {
		return current_size;
	}
	bool empty() const {
		return current_size == 0;
	}
	/*typename SkipList::Iterator begin() {
		return Iterator(map.begin());
	}
	typename SkipList::Iterator end() {
		return Iterator(map.end());
	}
	typename SkipList::ConstIterator begin() const {
		return ConstIterator(map.begin());
	}
	typename SkipList::ConstIterator end() const {
		return ConstIterator(map.end());
	}
	typename SkipList::ReverseIterator rbegin() {
		return ReverseIterator(map.begin());
	}
	typename SkipList::ReverseIterator rend() {
		return ReverseIterator(map.begin());
	}
	typename SkipList::Iterator find(const Key_T &x) {
		map.find(x);
	}
	typename SkipList::ConstIterator find(const Key_T &x) const {
		map.find(x);
	}*/
	Mapped_T &at(const Key_T &x);
	const Mapped_T &at(const Key_T &x) const;
	Mapped_T &operator[](const Key_T &x);
	std::pair<typename SkipList::Iterator, bool> insert(const std::pair<const Key_T, Mapped_T>&);
	template <typename IT_T> void insert(IT_T range_beg, IT_T range_end);
	void erase(typename SkipList::Iterator pos);
	void erase(const Key_T &);
	void clear();
	bool operator==(const Map&);
	bool operator!=(const Map& map) { return !(this == map); }
	bool operator<(const Map&);
};
