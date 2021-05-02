#ifndef Z_WORK_REPORT_H
#define Z_WORK_REPORT_H
/*
    Features:
        -Not Implemented: none

        -Implemented: Ability to be able to print, insert, get (get_existing and both constant and non-constant). Array functions
        maximal, swapping, first_ge, insert_item, split, copy_array, and += operators are implemented. BTree constructor is set
        up as well. To help with insert, is_leaf, loose_insert, and fix_excess has been implemented.

        Update 5/12/2019: Ability to copy, clear, and remove nodes from the tree. The big three is also implemented. Array functions
        attach_item, detach_item, delete_item, and merge are implemented. To help with remove, loose_remove, fix_shortage, remove_biggest,
        rotate_left, rotate_right, and merge_with_next_subset has been implemented. Size and empty functions are implemented as well.

        Update 5/19/2019: Copied over BTree Project to BPlusTree. Is_valid function where it checks whether or not the BPlusTree is valid.
        Insert and Remove is implemented for the BPlusTree and is working well. Print_leaves function prints the connected leaves in a
        BPlusTree. Copy now is able to copy over a BPlusTree with correctly connected leaves. Get smallest and largest (nodes and values),
        is implemented as well (copy_tree uses both get largest and smallest nodes to connect the leaves). Note that print leaves is separate
        from the <<operator because I wasn't able to make the print leaves function a constant function.


        -Partly implemented: I'm unsure about Pair, Multipair, Map, and Multimap.




    Bugs     : no bugs

    Reflections:  The map and multimap [] operator is implemented but not working correctly.



*/
#endif // Z_WORK_REPORT_H
