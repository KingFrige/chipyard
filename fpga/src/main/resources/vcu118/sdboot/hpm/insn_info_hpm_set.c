// See LICENSE for license details.

#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "hpm.h"
#include "encoding.h"

int insnInfoCntSet(){
  write_csr(scounteren, -1);
  write_csr(mcounteren, -1);

  write_csr(minstret, 0);
  write_csr(mcycle, 0);

  SET_PERFCNT( 3,  8, 4); // int load
  SET_PERFCNT( 4,  9, 4); // int store
  SET_PERFCNT( 5, 10, 4); // int amo
  SET_PERFCNT( 6, 11, 4); // int system
  SET_PERFCNT( 7, 12, 4); // int arith
  SET_PERFCNT( 8, 13, 4); // int branch
  SET_PERFCNT( 9, 14, 4); // int jal
  SET_PERFCNT(10, 15, 4); // int jalr
  SET_PERFCNT(11, 16, 4); // int mul
  SET_PERFCNT(12, 17, 4); // int div
  SET_PERFCNT(13, 18, 4); // fp
  SET_PERFCNT(14, 19, 4); // fp load
  SET_PERFCNT(15, 20, 4); // fp store
  SET_PERFCNT(16, 21, 4); // fp add
  SET_PERFCNT(17, 22, 4); // fp mul
  SET_PERFCNT(18, 23, 4); // fp mul-add
  SET_PERFCNT(19, 24, 4); // fp div
  SET_PERFCNT(20, 25, 4); // fp other

  SET_PERFCNT(21,  8, 5); // exception
  SET_PERFCNT(22,  9, 5); // f1 clear
  SET_PERFCNT(23, 10, 5); // f2 clear

  SET_PERFCNT(24, 10, 0); // br retired
  SET_PERFCNT(25, 11, 0); // br retired and taken
  SET_PERFCNT(26, 12, 0); // br retired and not taken

  SET_PERFCNT(27, 20, 1); // br target misp
  SET_PERFCNT(28, 21, 1); // br dir misp
  SET_PERFCNT(29, 22, 1); // taken conditional misp
  SET_PERFCNT(30, 23, 1); // not taken conditional misp
  SET_PERFCNT(31, 11, 1); // flush

  return 0;
}
