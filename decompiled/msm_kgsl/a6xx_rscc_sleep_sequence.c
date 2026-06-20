__int64 __fastcall a6xx_rscc_sleep_sequence(__int64 a1)
{
  unsigned __int64 v9; // x8

  _X20 = (unsigned __int64 *)(a1 - 352);
  if ( (*(_QWORD *)(a1 - 352) & 1) != 0 && (*_X20 & 8) == 0 )
  {
    gmu_core_regwrite(a1, 129024, 1);
    __dsb(0xEu);
    gmu_core_regread(a1, 129281, a1 - 372);
    gmu_core_regwrite(a1, 146183, 1);
    __dsb(0xEu);
    if ( (unsigned int)timed_poll_check_rscc(a1, 4, 0x10000u, 0x64u, 0x10000u) )
    {
      dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GPU RSC power off fail\n");
      return 4294967186LL;
    }
    gmu_core_regwrite(a1, 146183, 0);
    if ( *(_BYTE *)(a1 + 20432) == 1 )
      gmu_core_regwrite(a1, 146198, 0);
    __asm { PRFM            #0x11, [X20] }
    do
      v9 = __ldxr(_X20);
    while ( __stxr(v9 | 8, _X20) );
  }
  return 0;
}
