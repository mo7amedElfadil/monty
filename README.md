# Stacks, Queues, and The Monty Language

This project will introduce the idea of **Stacks**, **Queues**, and The **Monty** Language.

## Stacks
- A #stack is a linear data structure
- Elements can be inserted and deleted only from one side of the list, called the top.
- A stack follows the LIFO (Last In First Out) principle, i.e., the element inserted at the last is the first element to come out.
- The insertion of an element into the stack is called push operation
- the deletion of an element from the stack is called pop operation.
- In stack, we always keep track of the last element present in the list with a pointer called top.
## Queues
- A #queue is a linear data structure 
- Elements can be inserted only from one side of the list called rear
- Elements can be deleted only from the other side called the front.
- The queue data structure follows the FIFO (First In First Out) principle, i.e. the element inserted at first in the list, is the first element to be removed from the list. 
- The insertion of an element in a queue is called an enqueue operation 
- The deletion of an element is called a dequeue operation. 
- In queue, we always maintain two pointers, one pointing to the element which was inserted at the first and still present in the list with the front pointer and the second pointer pointing to the element inserted at the last with the rear pointer.
## The Monty Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line.
