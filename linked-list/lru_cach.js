class Node {
  constructor(data) {
    this.next = null;
    this.prev = null;
    this.data = data || null;
  }
}
class LRUCache {
  constructor(capacity) {
    this.head = new Node(-1);
    this.tail = new Node(-1);
    this.head.next = this.tail;
    this.tail.prev = this.head;
    this.valueToNodeMap = new Map();
    this.capacity = capacity;
  }
  insert(data) {
    const existingNode = this.search(data);
    if (existingNode != null) {
      this.deleteNode(existingNode);
      this.appendNode(data);
    } else {
      if (this.valueToNodeMap.size === this.capacity) {
        this.deleteFirstNode();
      }
      const node = this.appendNode(data);
      this.valueToNodeMap.set(data, node);
    }
  }
  appendNode(data) {
    const node = new Node(data);
    node.prev = this.tail.prev;
    node.next = this.tail;
    this.tail.prev = node;
    node.prev.next = node;
    this.valueToNodeMap.set(data, node);
    return node;
  }
  deleteNode(node) {
    node.prev.next = node.next;
    node.next.prev = node.prev;
    this.valueToNodeMap.delete(node.data);
  }
  deleteFirstNode() {
    this.deleteNode(this.head.next);
  }
  search(data) {
    return this.valueToNodeMap.get(data) || null;
  }
  print() {
    let current = this.head.next;
    while (current.next != null) {
      console.log(current.data);
      current = current.next;
    }
  }
}

const l = new LRUCache(2);
l.insert(1);
l.insert(2);
l.insert(3);
l.insert(4);
l.insert(5);

// console.log(JSON.stringify(l, null, 4));
l.print();
