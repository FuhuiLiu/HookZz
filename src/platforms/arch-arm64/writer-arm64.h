/**
 *    Copyright 2017 jmpews
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#ifndef platforms_arch_arm64_writer_h
#define platforms_arch_arm64_writer_h

#include "hookzz.h"
#include "kitzz.h"

#include "memory.h"
#include "writer.h"

#include "instructions.h"
#include "regs-arm64.h"
#include "writer-arm64.h"

typedef ZzWriter ZzArm64Writer;

ZzArm64Writer *zz_arm64_writer_new(zz_ptr_t data_ptr);

void zz_arm64_writer_reset(ZzArm64Writer *self, zz_ptr_t data_ptr);

void zz_arm64_writer_init(ZzArm64Writer *self, zz_ptr_t target_addr);

zz_size_t zz_arm64_writer_near_jump_range_size();

// ======= user custom =======

void zz_arm64_writer_put_ldr_br_reg_address(ZzArm64Writer *self, ZzARM64Reg reg, zz_addr_t address);

void zz_arm64_writer_put_ldr_blr_b_reg_address(ZzArm64Writer *self, ZzARM64Reg reg, zz_addr_t address);

void zz_arm64_writer_put_ldr_b_reg_address(ZzArm64Writer *self, ZzARM64Reg reg, zz_addr_t address);

void zz_arm64_writer_put_ldr_br_b_reg_address(ZzArm64Writer *self, ZzARM64Reg reg, zz_addr_t address);

// ======= default =======

void zz_arm64_writer_put_ldr_reg_imm(ZzWriter *self, ZzARM64Reg reg, uint32_t offset);

void zz_arm64_writer_put_str_reg_reg_offset(ZzWriter *self, ZzARM64Reg src_reg, ZzARM64Reg dst_reg, uint64_t offset);

void zz_arm64_writer_put_ldr_reg_reg_offset(ZzWriter *self, ZzARM64Reg dst_reg, ZzARM64Reg src_reg, uint64_t offset);

void zz_arm64_writer_put_br_reg(ZzWriter *self, ZzARM64Reg reg);

void zz_arm64_writer_put_blr_reg(ZzWriter *self, ZzARM64Reg reg);

void zz_arm64_writer_put_b_imm(ZzWriter *self, uint64_t offset);

void zz_arm64_writer_put_b_cond_imm(ZzWriter *self, uint32_t condition, uint64_t imm);

void zz_arm64_writer_put_add_reg_reg_imm(ZzWriter *self, ZzARM64Reg dst_reg, ZzARM64Reg left_reg, uint64_t imm);

void zz_arm64_writer_put_sub_reg_reg_imm(ZzWriter *self, ZzARM64Reg dst_reg, ZzARM64Reg left_reg, uint64_t imm);

void zz_arm64_writer_put_bytes(ZzWriter *self, char *data, zz_size_t size);

void zz_arm64_writer_put_instruction(ZzWriter *self, uint32_t insn);

// ======= relocator =======

ZzLiteralInstruction *zz_arm64_writer_put_ldr_br_reg_relocate_address(ZzWriter *self, ZzARM64Reg reg, zz_addr_t address,
                                                                      ZzLiteralInstruction **literal_insn_ptr);

#endif