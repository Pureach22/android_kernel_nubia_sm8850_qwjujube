__int64 __fastcall ieee80211_request_sched_scan_stop(_QWORD *a1)
{
  __int64 v1; // x19
  int v2; // w2
  __int64 result; // x0
  __int64 v4; // x9
  _QWORD *v5; // x20
  const char *v6; // x1
  _QWORD *v7; // x19
  __int64 (*v8)(void); // x8

  if ( !*(_QWORD *)(a1[58] + 208LL) )
    return 4294967201LL;
  a1[608] = 0;
  v1 = a1[607];
  if ( !v1 )
    return 4294967294LL;
  if ( (*(_BYTE *)(*(_QWORD *)(v1 + 1616) + 1471LL) & 1) != 0
    || (v2 = *(_DWORD *)(v1 + 1624), (v2 & 0x20) != 0)
    || (drv_sched_scan_stop___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(v1 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  else
  {
    v4 = *(_QWORD *)(v1 + 1608);
    drv_sched_scan_stop___already_done = 1;
    v5 = a1;
    if ( v4 )
      v6 = (const char *)(v4 + 296);
    else
      v6 = (const char *)(v1 + 1640);
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v6, v2);
    a1 = v5;
    __break(0x800u);
    if ( (*(_BYTE *)(v1 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  v7 = a1;
  v8 = *(__int64 (**)(void))(a1[58] + 208LL);
  if ( *((_DWORD *)v8 - 1) != 844051912 )
    __break(0x8228u);
  result = v8();
  if ( !(_DWORD)result )
    v7[607] = 0;
  return result;
}
