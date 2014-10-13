/**
 * simple-vm-opcodes.h - Definitions of our opcode-handlers.
 *
 * Copyright (c) 2014 by Steve Kemp.  All rights reserved.
 *
 **
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 dated June, 1991, or (at your
 * option) any later version.
 *
 * On Debian GNU/Linux systems, the complete text of version 2 of the GNU
 * General Public License can be found in `/usr/share/common-licenses/GPL-2'
 *
 **
 *
 */


#ifndef SIMPLE_VM_OPCODES_H
#define SIMPLE_VM_OPCODES_H 1


/**
 * This ENUM stores the values of our opcodes.
 *
 * This is less painful to update than having a series of #define instructions,
 * and ensure that we have unique and incrementing values for the various
 * opcodes.
 *
 * Opcodes are configured in bunches of 16, with instructions broadly
 * grouped together by class/type.
 *
 */
enum opcode_values {

    /**
     * Early opcodes.
     */
    EXIT = 0,
    INT_STORE,
    INT_PRINT,
    INT_TOSTRING,
    INT_RANDOM,

    /**
     * Jump operations.
     */
    JUMP_TO = 0x10,
    JUMP_Z,
    JUMP_NZ,

    /**
     * Math operations.
     */
    XOR = 0x20,
    ADD,
    SUB,
    MUL,
    DIV,
    INC,
    DEC,
    AND,
    OR,

    /**
     * String operations.
     */
    STRING_STORE = 0x30,
    STRING_PRINT,
    STRING_CONCAT,
    STRING_SYSTEM,
    STRING_TOINT,

    /**
     * Comparison operations.
     */
    CMP_REG = 0x40,
    CMP_IMMEDIATE,
    CMP_STRING,

    /**
     * Misc.
     */
    NOP = 0x50,

    /**
     * PEEK/POKE operations.
     */
    PEEK = 0x60,
    POKE,
    MEMCPY,

    /**
     * Stack operations.
     */
    STACK_PUSH = 0x70,
    STACK_POP,
    STACK_RET,
    STACK_CALL
};



/* 0x00 - 0x0F */
_Bool op_exit(struct svm *in);
_Bool op_int_store(struct svm *in);
_Bool op_int_print(struct svm *in);
_Bool op_int_tostring(struct svm *in);
_Bool op_int_random(struct svm *in);

/* 0x10 - 0x1F */
_Bool op_jump_to(struct svm *in);
_Bool op_jump_z(struct svm *in);
_Bool op_jump_nz(struct svm *in);

/* 0x20 - 0x2F */
_Bool op_xor(struct svm *in);
_Bool op_or(struct svm *in);
_Bool op_add(struct svm *in);
_Bool op_and(struct svm *in);
_Bool op_sub(struct svm *in);
_Bool op_mul(struct svm *in);
_Bool op_div(struct svm *in);
_Bool op_inc(struct svm *in);
_Bool op_dec(struct svm *in);

/* 0x30 - 0x3F */
_Bool op_string_store(struct svm *in);
_Bool op_string_print(struct svm *in);
_Bool op_string_concat(struct svm *in);
_Bool op_string_system(struct svm *in);
_Bool op_string_toint(struct svm *in);

/* 0x40 - 0x4F */
_Bool op_cmp_reg(struct svm *in);
_Bool op_cmp_immediate(struct svm *in);
_Bool op_cmp_string(struct svm *in);

/* 0x50 - 0x5F */
_Bool op_nop(struct svm *in);
_Bool op_mem_cpy(struct svm *in);

/* 0x60 - 0x6F */
_Bool op_peek(struct svm *in);
_Bool op_poke(struct svm *in);
_Bool op_memcpy(struct svm *in);

/* 0x70 - 0x7F */
_Bool op_stack_push(struct svm *in);
_Bool op_stack_pop(struct svm *in);
_Bool op_stack_ret(struct svm *in);
_Bool op_stack_call(struct svm *in);



/**
 * Initialization function.
 */
void opcode_init(struct svm *cpu);

#endif                          /* SIMPLE_VM_OPCODES_H */
