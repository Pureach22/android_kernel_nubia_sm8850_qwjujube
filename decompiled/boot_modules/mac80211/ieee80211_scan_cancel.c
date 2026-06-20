_QWORD *__fastcall ieee80211_scan_cancel(_QWORD *result)
{
  _QWORD *v1; // x19
  __int64 v2; // x9
  int v3; // w2
  __int64 (*v4)(void); // x8
  __int64 v5; // x10
  const char *v6; // x1
  __int64 v7; // x19
  unsigned __int64 v14; // x9
  unsigned __int64 v17; // x9
  _QWORD *v18; // [xsp+28h] [xbp+18h]

  if ( result[594] )
  {
    if ( (result[587] & 2) != 0 && (result[587] & 8) != 0 )
    {
      _X8 = result + 587;
      __asm { PRFM            #0x11, [X8] }
      do
        v17 = __ldxr(_X8);
      while ( __stxr(v17 | 0x20, _X8) );
      return result;
    }
    if ( (result[587] & 2) == 0 )
    {
      v1 = result;
      wiphy_delayed_work_cancel(result[9], result + 612);
      v1[603] = 0;
      v1[602] = 0;
      return _ieee80211_scan_completed(v1, 1);
    }
    _X8 = result + 587;
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stxr(v14 | 0x20, _X8) );
    if ( *(_QWORD *)(result[58] + 192LL) )
    {
      v2 = result[621];
      if ( (*(_BYTE *)(*(_QWORD *)(v2 + 1616) + 1471LL) & 1) != 0
        || (v3 = *(_DWORD *)(v2 + 1624), (v3 & 0x20) != 0)
        || (drv_cancel_hw_scan___already_done & 1) != 0 )
      {
        if ( (*(_BYTE *)(v2 + 1624) & 0x20) == 0 )
          return result;
        goto LABEL_12;
      }
      v5 = *(_QWORD *)(v2 + 1608);
      drv_cancel_hw_scan___already_done = 1;
      v18 = result;
      if ( v5 )
        v6 = (const char *)(v5 + 296);
      else
        v6 = (const char *)(v2 + 1640);
      v7 = v2;
      _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v6, v3);
      result = v18;
      __break(0x800u);
      if ( (*(_BYTE *)(v7 + 1624) & 0x20) != 0 )
      {
LABEL_12:
        v4 = *(__int64 (**)(void))(result[58] + 192LL);
        if ( *((_DWORD *)v4 - 1) != 1098857213 )
          __break(0x8228u);
        return (_QWORD *)v4();
      }
    }
  }
  return result;
}
