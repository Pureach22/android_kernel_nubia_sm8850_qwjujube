__int64 __fastcall gen7_rscc_sleep_sequence(__int64 a1)
{
  __int64 v2; // x20
  unsigned __int64 v10; // x8

  _X22 = (unsigned __int64 *)(a1 - 680);
  if ( (*(_QWORD *)(a1 - 680) & 1) != 0 && (*_X22 & 8) == 0 )
  {
    v2 = a1 - 1776;
    gmu_core_regwrite(a1, 129024, 1);
    __dsb(0xEu);
    gmu_core_regread(a1, 129486, a1 - 696);
    gmu_core_regwrite(a1, 146183, 1);
    __dsb(0xEu);
    if ( (unsigned int)gen7_timed_poll_check_rscc(v2, 4, 0x10000, 100, 0x10000) )
    {
      dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GPU RSC power off fail\n");
      return 4294967186LL;
    }
    gmu_core_regwrite(a1, 146183, 0);
    __asm { PRFM            #0x11, [X22] }
    do
      v10 = __ldxr(_X22);
    while ( __stxr(v10 | 8, _X22) );
  }
  return 0;
}
