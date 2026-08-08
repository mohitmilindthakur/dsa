import {
  createLinkedList,
  get_cyclic_node,
  get_tail_from_head,
  print_ll,
  reverse_inplace,
} from "./LLNode.js";

let head1 = createLinkedList(5);
let head2 = createLinkedList(7, 6);

// let tail1 = get_tail_from_head(head1);
// tail1.next = head2.next.next.next.next.next;

function get_intersection(head1, head2) {
  let combined = reverse_inplace(head1);
  let tail1 = get_tail_from_head(combined);
  tail1.next = head2;
  let intersection_node = get_cyclic_node(combined);
  return intersection_node;
}

console.log(get_intersection(head1, head2));
