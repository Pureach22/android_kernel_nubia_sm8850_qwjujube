__int64 __fastcall gen8_rscc_sleep_sequence(__int64 a1)
{
  unsigned int v2; // w8
  int v4; // w19
  __int64 v5; // x21
  unsigned __int64 v12; // x8

  _X23 = (unsigned __int64 *)(a1 - 784);
  v2 = **(_DWORD **)(a1 + 14264);
  if ( v2 >> 1 == 262400 || v2 == 526592 )
    v4 = 0x40000000;
  else
    v4 = 0x10000;
  if ( (*(_QWORD *)(a1 - 784) & 1) != 0 && (*_X23 & 8) == 0 )
  {
    v5 = a1 - 1824;
    gmu_core_regwrite(a1, 129024, 1);
    __dsb(0xEu);
    gmu_core_regread(a1, 129481, a1 - 800);
    gmu_core_regwrite(a1, 146183, 1);
    __dsb(0xEu);
    if ( (unsigned int)gen8_timed_poll_check_rscc(v5, 4, v4, 100, v4) )
    {
      dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GPU RSC power off fail\n");
      return 4294967186LL;
    }
    gmu_core_regwrite(a1, 146183, 0);
    __asm { PRFM            #0x11, [X23] }
    do
      v12 = __ldxr(_X23);
    while ( __stxr(v12 | 8, _X23) );
  }
  return 0;
}
