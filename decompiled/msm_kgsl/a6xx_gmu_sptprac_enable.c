__int64 __fastcall a6xx_gmu_sptprac_enable(__int64 a1)
{
  unsigned __int64 v9; // x9

  _ZF = (unsigned int)(**(_DWORD **)(a1 + 14264) - 615) > 0xF || ((1 << (**(_BYTE **)(a1 + 14264) - 103)) & 0x801B) == 0;
  if ( !_ZF && (*(_QWORD *)(a1 + 14240) & 0x100) == 0 )
  {
    gmu_core_regwrite(a1, 108673, 7831552);
    if ( (unsigned int)gmu_core_timed_poll_check(a1, 129232, 8, 10, 8) )
    {
      dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "power on SPTPRAC fail\n");
      gmu_core_fault_snapshot(a1, 0);
      return 4294967186LL;
    }
    _X8 = (unsigned __int64 *)(a1 + 14240);
    __asm { PRFM            #0x11, [X8] }
    do
      v9 = __ldxr(_X8);
    while ( __stxr(v9 | 0x100, _X8) );
  }
  return 0;
}
