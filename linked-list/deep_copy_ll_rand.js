class Node {
  constructor(data) {
    this.next = null;
    this.random = null;
    this.data = data;
  }
}

function print(head) {
  current = head;
  while (current != null) {
    console.log(current.data, current.random?.data);
    current = current.next;
  }
}

function deep_copy(head) {
  let current = head;
  while (current != null) {
    const node = new Node(current.data);
    node.next = current.next;
    current.next = node;
    current = current.next.next;
  }
  current = head;
  let newHead = null;
  let newTail = null;
  while (current != null) {
    current.next.random = current.random.next;
    current = current.next.next;
  }

  current = head;
  while (current != null) {
    if (newHead == null) {
      newHead = current.next;
      newTail = current.next;
    } else {
      newTail = newTail.next.next;
    }
    current.next = current.next.next;
    current = current.next;
  }
  console.log(newHead === head);
  return newHead;
}

function init_ll() {
  const head = new Node(1);
  head.next = new Node(2);
  head.next.next = new Node(3);
  head.next.next.next = new Node(4);

  head.random = head.next; // 0 -> 1
  head.next.random = head.next.next.next; // 1 -> 3
  head.next.next.random = head.next.next.next; // 2 -> 3
  head.next.next.next.random = head; // 3 -> 1
  return head;
}

function main() {
  const head = init_ll();
  const newll = deep_copy(head);
  print(head);
  console.log("----------------------");
  print(newll);
}

main();
