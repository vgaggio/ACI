.global comparePasswords
.type comparePasswords, %function


comparePasswords:
    push {lr}           //Save the return address
    ldr r1, =savedPassword // Load the address of the saved password
    ldr r2, [r1]            //Load the first word of the saved password

loop;
    ldrb r3, [r0], #1     //Load a byte from user input and increment the pointer
    ldrb r4, [r1], #1       // Load a byte from the saved password and increment the pointer
    сmp r3, r4              // Compare the bytes

    bne mismatch            //Branch to missmatch if the bytes are not equal
    сmp г3, #0                 //Check if we have reached the end of the user
    bne loop                    //Continue looping if not

    mov r0, #0
    bne loop                //Continue looping if not

    mov r0, #0              // Return 0 (passwords match)
    pop {pc}                // Restore the return address and return

mismatch:
    mov r0, #1              // Return 1 (passwords don't match)
    pop {pc}                // Restore the return address and return

savedPassword:
    .asciz "abc"     //the saved password













