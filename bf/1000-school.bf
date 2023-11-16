[School = 83 99 104 111 111 108]
83

++++++++               Set Cell #0 to 8
[
    >++++               Add 4 to Cell #1; this will always set Cell #1 to 4
    [                   as the cell will be cleared by the loop
        >++             Add 2 to Cell #2
        >+++            Add 3 to Cell #3
		>           Add 3 to Cell #4
        >              Add 1 to Cell #5
        <<<<-           Decrement the loop counter in Cell #1
    ]                   Loop until Cell #1 is zero; number of iterations is 4
    >++                 Add 1 to Cell #2
    >
	>+
    [<]                 Move back to the first zero cell you find; this will
                        be Cell #1 which was cleared by the previous loop
    <-                  Decrement the loop Counter in Cell #0
]                       Loop until Cell #0 is zero; number of iterations is 8


>>+++.                  Cell #2 has value 72 which is 'H'
>+++.                   Subtract 3 from Cell #3 to get 101 which is 'e'
+++++.+++++++..---.           Likewise for 'llo' from Cell #3
>++.
