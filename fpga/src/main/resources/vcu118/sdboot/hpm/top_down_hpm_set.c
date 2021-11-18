// See LICENSE for license details.

#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "hpm.h"
#include "encoding.h"

int topDownCntSet(){
  write_csr(scounteren, -1);
  write_csr(mcounteren, -1);

  write_csr(minstret, 0);
  write_csr(mcycle, 0);

  SET_PERFCNT( 3,  8, 0);
  SET_PERFCNT( 4,  9, 0);
  SET_PERFCNT( 5, 10, 0);

  SET_PERFCNT( 6,  8, 1);
  SET_PERFCNT( 7,  9, 1);
  SET_PERFCNT( 8, 10, 1);
  SET_PERFCNT( 9, 11, 1);
  SET_PERFCNT(10, 12, 1);
  SET_PERFCNT(11, 13, 1);
  SET_PERFCNT(12, 14, 1);
  SET_PERFCNT(13, 15, 1);
  SET_PERFCNT(14, 16, 1);

  SET_PERFCNT(15, 13, 2); //
  SET_PERFCNT(16, 14, 2);
  SET_PERFCNT(17, 15, 2);
  SET_PERFCNT(18, 16, 2);
  SET_PERFCNT(19, 17, 2);
  SET_PERFCNT(20, 24, 2); //
  SET_PERFCNT(21, 25, 2);
  SET_PERFCNT(22, 26, 2); //

  SET_PERFCNT(29, 23, 1);
  SET_PERFCNT(30, 17, 1);
  SET_PERFCNT(31, 18, 5);

  return 0;
}

