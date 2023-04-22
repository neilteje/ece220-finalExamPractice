; left_most.asm

    .ORIG x3000

MAIN
    ; Set up stack
    LD R5, RSTACK
    LD R6, RSTACK

    ; Push argument to left_most
    LD R0, ROOT
    STR R0, R6, #0

    ; left_most(root)
    JSR LEFT_MOST

    ; Display leftmost element of tree
    LDR R0, R6, 0
    OUT

    HALT

ROOT
    .FILL x2003
RSTACK
    .FILL x7000

; char left_most(treenode *root)    // You may assume that root will never be NULL
; {
;     if (!root->left) {
;         return data;
;     }
;     return left_most(root->left);
; }
LEFT_MOST
    ; TODO: Setup activation record

    ; TODO: Check if root->left is NULL, if it is, branch to DONE
    ; if (!root->left)

    ; TODO: Call left_most(root->left) and place the return value
    ; left_most(root->left) in the correct location in the
    ; activation record.

    BR TEARDOWN

DONE
    ; TODO: return data: place the return value in the correct location
    ; in the activation record

TEARDOWN

    ; TODO: teardown activation record prior to RET

    RET

    .END
