__int64 __fastcall ieee80211_stop_nan(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 v4; // x1
  void (__fastcall *v5)(__int64, __int64); // x8
  __int64 v7; // x9
  __int64 v8; // x21
  __int64 v9; // x8

  v2 = *(_QWORD *)(a2 + 1600);
  v3 = a2 - 16;
  if ( (*(_BYTE *)(v2 + 1471) & 1) == 0
    && (*(_DWORD *)(a2 + 1608) & 0x20) == 0
    && (drv_stop_nan___already_done & 1) == 0 )
  {
    v7 = *(_QWORD *)(a2 + 1592);
    drv_stop_nan___already_done = 1;
    v8 = a2;
    if ( v7 )
      v9 = v7 + 296;
    else
      v9 = a2 + 1624;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v9);
    a2 = v8;
    __break(0x800u);
  }
  v4 = a2 + 4704;
  v5 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v2 + 464) + 776LL);
  if ( *((_DWORD *)v5 - 1) != 844051912 )
    __break(0x8228u);
  v5(v2, v4);
  return ieee80211_sdata_stop(v3);
}
