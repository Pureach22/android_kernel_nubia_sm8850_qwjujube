_QWORD *__fastcall ieee80211_handle_reconfig_failure(__int64 a1)
{
  _QWORD *result; // x0
  __int64 *i; // x8
  __int64 *j; // x8
  unsigned __int64 v11; // x9

  *(_BYTE *)(a1 + 1467) = 0;
  *(_BYTE *)(a1 + 1465) = 0;
  *(_WORD *)(a1 + 1470) = 256;
  if ( (*(_QWORD *)(a1 + 4696) & 8) != 0 )
  {
    _X8 = (unsigned __int64 *)(a1 + 4696);
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldxr(_X8);
    while ( __stxr(v11 | 0x10, _X8) );
    wiphy_delayed_work_queue(*(_QWORD *)(a1 + 72), a1 + 4896, 0);
    wiphy_delayed_work_flush(*(_QWORD *)(a1 + 72), a1 + 4896);
  }
  result = ieee80211_sched_scan_end((_QWORD *)a1);
  for ( i = *(__int64 **)(a1 + 4616); i != (__int64 *)(a1 + 4616); i = (__int64 *)*i )
    *((_DWORD *)i + 406) &= ~0x20u;
  for ( j = *(__int64 **)(a1 + 4984); j != (__int64 *)(a1 + 4984); j = (__int64 *)*j )
    *((_BYTE *)j + 84) = 0;
  return result;
}
