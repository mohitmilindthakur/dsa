export class Node {
  constructor(data) {
    this.next = null;
    this.random = null;
    this.data = data;
  }
}

function create_random_int() {
  return parseInt(Math.random() * 10000);
}

export function createLinkedList(num, starting = 1) {
  const head = new Node(starting);
  let tail = head;
  for (let i = starting + 1; i < starting + num; i++) {
    const data = i;
    const node = new Node(data);
    tail.next = node;
    tail = node;
  }
  return head;
}

export function print_ll(head) {
  let current = head;
  while (current != null) {
    console.log(current.data);
    current = current.next;
  }
}

export function get_tail_from_head(head) {
  let curr = head;
  while (curr.next != null) {
    curr = curr.next;
  }
  return curr;
}

export function reverse_inplace(head) {
  let curr = head;
  let prev = null;
  while (curr != null) {
    let next = curr.next;
    curr.next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

export function get_cyclic_node(head) {
  let fp = head;
  let sp = head;
  let hasCycle = false;

  while (fp != null && fp.next != null && fp.next.next != null) {
    fp = fp.next.next;
    sp = sp.next;
    if (sp == fp) {
      hasCycle = true;
      break;
    }
  }

  if (!hasCycle) {
    return null;
  }

  let temp = head;
  while (temp != fp) {
    fp = fp.next;
    temp = temp.next;
  }

  return temp;
}
