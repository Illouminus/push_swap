<h1 align="center">Push_Swap Project</h1>
<h2 align="center">Custom Implementation of the Push_Swap Algorithm</h2>
<div align="center" width="80%">
  <p align="justify">
    <b>Project Overview:</b> The Push_Swap project, part of the 42 school curriculum, challenges students to implement a sorting algorithm that can efficiently sort a stack of integers with a limited set of operations. This project aims to enhance students' problem-solving skills and understanding of algorithmic complexity.<br><br>
    <b>Key Features:</b> The custom Push_Swap algorithm takes as input two stacks, Stack A and Stack B, and sorts the integers in Stack A using a predefined set of operations. The algorithm strives to minimize the total number of operations required to achieve a sorted Stack A.<br><br>
    <b>Installation:</b> Clone the repository and compile the project to use it for sorting integer stacks.
  </p>
</div>
<h3 align="left">Installation Instructions:</h3>
<p align="left">
    git clone https://github.com/Illouminus/push_swap.git<br>
    cd push_swap<br>
    make<br>
</p>
<h3 align="left">Usage:</h3>
<p align="left">
  To sort a stack of integers using the Push_Swap algorithm, run the following command:<br>
  ./push_swap [list of integers]
</p>
<h3 align="left">Supported Operations:</h3>
<p align="left">
  - sa : swap the first two elements of stack A<br>
  - sb : swap the first two elements of stack B<br>
  - ss : sa and sb at the same time<br>
  - pa : push the first element from stack A to stack B<br>
  - pb : push the first element from stack B to stack A<br>
  - ra : rotate stack A (move the top element to the bottom)<br>
  - rb : rotate stack B (move the top element to the bottom)<br>
  - rr : ra and rb at the same time<br>
  - rra : reverse rotate stack A (move the bottom element to the top)<br>
  - rrb : reverse rotate stack B (move the bottom element to the top)<br>
  - rrr : rra and rrb at the same time<br>
</p>
<h3 align="left">Example:</h3>
<p align="left">
  To sort a stack with integers 3, 1, and 2, run the following command:<br>
  ./push_swap 3 1 2<br>
  This will output a series of operations to sort the stack.
</p>
<h3 align="left">Contributing:</h3>
<p align="left">
  Contributions to the Push_Swap project are welcome. Please fork the repository, make your changes, and submit a pull request.
</p>
