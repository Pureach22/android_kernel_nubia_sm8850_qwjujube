__int64 __fastcall gen7_rscc_wakeup_sequence(__int64 a1)
{
  __int64 v3; // x0
  _QWORD *v4; // x22
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x20
  unsigned __int64 v14; // x9

  _X21 = (unsigned __int64 *)(a1 - 680);
  if ( (*(_QWORD *)(a1 - 680) & 8) == 0 )
    return 0;
  gmu_core_regwrite(a1, 146183, 2);
  __dsb(0xEu);
  v3 = gmu_core_timed_poll_check(a1, 146184, 2, 100, 2);
  if ( (_DWORD)v3 )
  {
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Failed to do GPU RSC power on\n");
  }
  else
  {
    v4 = (_QWORD *)(a1 - 672);
    v5 = ktime_get(v3);
    v6 = readl_1(*(_QWORD *)(a1 - 672) + 1028LL);
    if ( !(_DWORD)v6 )
      goto LABEL_9;
    v7 = v5 + 100000000;
    while ( ktime_get(v6) <= v7 )
    {
      usleep_range_state(26, 100, 2);
      __yield();
      v6 = readl_1(*v4 + 1028LL);
      if ( !(_DWORD)v6 )
        goto LABEL_9;
    }
    if ( !(unsigned int)readl_1(*v4 + 1028LL) )
    {
LABEL_9:
      gmu_core_regwrite(a1, 146183, 0);
      __asm { PRFM            #0x11, [X21] }
      do
        v14 = __ldxr(_X21);
      while ( __stxr(v14 & 0xFFFFFFFFFFFFFFF7LL, _X21) );
      return 0;
    }
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GPU RSC sequence stuck in waking up GPU\n");
  }
  return 4294967186LL;
}
