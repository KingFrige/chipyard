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

  SET_PERFCNT(14,  8, 2);
  SET_PERFCNT(15,  9, 2);
  SET_PERFCNT(16, 10, 2);
  SET_PERFCNT(17, 11, 2);
  SET_PERFCNT(18, 12, 2); //
  SET_PERFCNT(19, 13, 2);
  SET_PERFCNT(20, 14, 2);
  SET_PERFCNT(21, 15, 2);
  SET_PERFCNT(22, 16, 2);
  SET_PERFCNT(23, 17, 2); //
  SET_PERFCNT(24, 18, 2);

  SET_PERFCNT(25, 16, 1);
  SET_PERFCNT(26, 17, 1);
  SET_PERFCNT(27, 18, 1);
  SET_PERFCNT(28, 19, 1);

  return 0;
}

