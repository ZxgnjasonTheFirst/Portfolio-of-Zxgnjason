#ifndef Z_OUTPUT_LIST_H
#define Z_OUTPUT_LIST_H
/*
 ***** ALL RESULTS ARE VERIFIED *****

----------------------------------
Testing list copy constructor and insert (1 argument):
----------------------------------
test->[3]->[2]->[1]->|||

yes->[3]->[2]->[1]->|||

----------------------------------

----------------------------------
Testing insert(here, item) (two arguments):
----------------------------------
test->[3]->[2]->[5]->[1]->|||
----------------------------------

----------------------------------
Testing list destructor (filled list):
----------------------------------
->[2]->[1]->|||

this is test after destructor->|||

----------------------------------

----------------------------------
Testing list destructor (empty list):
----------------------------------
->|||

this is test after destructor->|||

----------------------------------

----------------------------------
Testing list equals operator:
----------------------------------
test->[2]->[1]->|||
yes->[2]->[1]->|||
----------------------------------

----------------------------------
Testing erase (deleting head of list):
----------------------------------
test->[3]->[2]->[1]->|||
test->[2]->[1]->|||
test->[1]->|||
test->|||
test->|||  //<< called pop on empty queue
----------------------------------

----------------------------------
Testing getting head value:
----------------------------------
Test: ->[3]->[2]->[1]->|||
Head value is: 3
----------------------------------

----------------------------------
Testing if list is empty (yes):
----------------------------------
->[1]->[2]->|||
->|||
list is empty!
----------------------------------

----------------------------------
Testing if list is empty (no):
----------------------------------
->[1]->[2]->|||
->[2]->|||
list is not empty!
----------------------------------

----------------------------------
Testing if list is empty (yes):
*testing if erase after destructor deletes
empty list*
----------------------------------
->[1]->[2]->|||
->|||
list is empty!
----------------------------------

*/
#endif // Z_OUTPUT_LIST_H
