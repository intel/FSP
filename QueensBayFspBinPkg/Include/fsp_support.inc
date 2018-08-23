/** @file
 * 
 * Copyright (C) 2013, Intel Corporation
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * * Neither the name of Intel Corporation nor the names of its contributors may
 *   be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 * 
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 *   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 *   THE POSSIBILITY OF SUCH DAMAGE.
 * 
**/
  
/*
 * Assume the processor is in flat mode with 4GB space access  
 */
  jmp  temp_ram_init

fsp_ret_failed:  
  jmp fsp_ret_failed

.align 4
find_fsp_header_stack_rom:
  .long  find_fsp_header_ret  
  
temp_ram_init_stack_rom:
  .long  temp_ram_init_done
  .long  temp_ram_init_params
  
temp_ram_init_params:
  .long  CFG_CPU_MICROCODE_BASE
  .long  CFG_CPU_MICROCODE_SIZE
  .long  CFG_CACHABLE_ROM_BASE
  .long  CFG_CACHABLE_ROM_SIZE
    
temp_ram_init:  
  /*
   * Find the FSP binary.
   * Use a rom based stack so that the call will return back to this code.
   */
  lea   find_fsp_header_stack_rom,  %esp
  jmp   FindFspHeader
find_fsp_header_ret:
  cmp   $0,   %eax 
  jz    fsp_ret_failed
  
  /* 
   * Save the FSP header in EBP for later use
   */
  movl  %eax, %ebp

  /* 
   * Calculate TempRamInit API entry point
   */
  mov   0x30(%ebp), %eax
  add   0x1c(%ebp), %eax

  /*
   * Pass early init variables on a fake stack (no memory yet)
   * as well as the return location
   */
  lea   temp_ram_init_stack_rom, %esp

  /* 
   * call FSP binary to setup temporary stack
   */
  jmp   *%eax

temp_ram_init_done:
  addl  $4, %esp
  cmp   $0, %eax
  jne   fsp_ret_failed

  /*
   * setup the stack
   * ecx:  stack base
   * edx:  stack top   
   */
  lea   (%edx), %esp
  movl  %esp, %ebp
    
  /*
   * save current stack base and top
   */
  pushl  %ecx
  pushl  %edx

  /* 
   * Call C functions now
   */  
    
