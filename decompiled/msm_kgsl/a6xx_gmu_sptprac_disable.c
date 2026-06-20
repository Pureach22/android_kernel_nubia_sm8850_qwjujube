__int64 __fastcall a6xx_gmu_sptprac_disable(__int64 result)
{
  __int64 v2; // x19
  unsigned __int64 v8; // x8

  if ( (unsigned int)(**(_DWORD **)(result + 14264) - 615) <= 0xF
    && ((1 << (**(_BYTE **)(result + 14264) - 103)) & 0x801B) != 0 )
  {
    v2 = result;
    _X9 = (unsigned __int64 *)(result + 14240);
    __asm { PRFM            #0x11, [X9] }
    do
      v8 = __ldxr(_X9);
    while ( __stlxr(v8 & 0xFFFFFFFFFFFFFEFFLL, _X9) );
    __dmb(0xBu);
    if ( (v8 & 0x100) != 0 )
    {
      gmu_core_regrmw(result, 148483, 0, 2048);
      gmu_core_regwrite(v2, 108673, 7831553);
      result = gmu_core_timed_poll_check(v2, 129232, 4, 10, 4);
      if ( (_DWORD)result )
        return dev_err(*(_QWORD *)(v2 + 1544) + 16LL, "power off SPTPRAC fail\n");
    }
  }
  return result;
}
