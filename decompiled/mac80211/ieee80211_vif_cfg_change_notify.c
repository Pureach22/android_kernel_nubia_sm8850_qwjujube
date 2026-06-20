__int64 __fastcall ieee80211_vif_cfg_change_notify(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w2
  __int64 v4; // x10
  __int64 (__fastcall *v5)(__int64, __int64, __int64); // x9
  __int64 (__fastcall *v6)(__int64, __int64, __int64, __int64); // x9
  __int64 v7; // x9
  __int64 v8; // x20
  const char *v9; // x8
  __int64 v10; // [xsp+8h] [xbp-8h]

  v2 = *(_QWORD *)(result + 1616);
  if ( (a2 & 0xFFFFFFF9FFFD27FELL) != 0 )
  {
    __break(0x800u);
  }
  else if ( !a2 )
  {
    return result;
  }
  if ( *(_DWORD *)(result + 4720) != 4 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(result + 1616) + 1471LL) & 1) != 0
      || (v3 = *(_DWORD *)(result + 1624), (v3 & 0x20) != 0)
      || (drv_vif_cfg_changed___already_done & 1) != 0 )
    {
      if ( (*(_BYTE *)(result + 1624) & 0x20) == 0 )
        return result;
    }
    else
    {
      v7 = *(_QWORD *)(result + 1608);
      drv_vif_cfg_changed___already_done = 1;
      v8 = a2;
      if ( v7 )
        v9 = (const char *)(v7 + 296);
      else
        v9 = (const char *)(result + 1640);
      v10 = result;
      _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v9, v3);
      result = v10;
      a2 = v8;
      __break(0x800u);
      if ( (*(_BYTE *)(v10 + 1624) & 0x20) == 0 )
        return result;
    }
    v4 = *(_QWORD *)(v2 + 464);
    v5 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v4 + 88);
    if ( v5 )
    {
      if ( *((_DWORD *)v5 - 1) != -1003313279 )
        __break(0x8229u);
      return v5(v2, result + 4720, a2);
    }
    else
    {
      v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v4 + 80);
      if ( v6 )
      {
        if ( *((_DWORD *)v6 - 1) != 642518393 )
          __break(0x8229u);
        return v6(v2, result + 4720, result + 4808, a2);
      }
    }
  }
  return result;
}
