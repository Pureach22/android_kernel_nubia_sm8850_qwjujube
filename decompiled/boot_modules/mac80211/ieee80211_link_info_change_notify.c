__int64 __fastcall ieee80211_link_info_change_notify(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  int v4; // w9
  __int64 v5; // x11
  const char *v6; // x10
  int v7; // [xsp+0h] [xbp-30h]
  __int64 v8; // [xsp+8h] [xbp-28h]
  __int64 v9; // [xsp+10h] [xbp-20h]
  __int64 v10; // [xsp+18h] [xbp-18h]

  v3 = *(_QWORD *)(result + 1616);
  if ( (a3 & 0x60002D801LL) != 0 )
  {
    __break(0x800u);
  }
  else if ( !a3 )
  {
    return result;
  }
  if ( *(_DWORD *)(result + 4720) != 4 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(result + 1616) + 1471LL) & 1) != 0
      || (v4 = *(_DWORD *)(result + 1624), (v4 & 0x20) != 0)
      || (ieee80211_link_info_change_notify___already_done & 1) != 0 )
    {
      if ( (*(_BYTE *)(result + 1624) & 0x20) == 0 )
        return result;
      return drv_link_info_changed(v3, result, *(_QWORD *)(a2 + 944), *(_DWORD *)(a2 + 8), a3);
    }
    v5 = *(_QWORD *)(result + 1608);
    ieee80211_link_info_change_notify___already_done = 1;
    if ( v5 )
      v6 = (const char *)(v5 + 296);
    else
      v6 = (const char *)(result + 1640);
    v10 = result;
    v8 = a2;
    v9 = v3;
    v7 = a3;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v6, v4);
    a2 = v8;
    v3 = v9;
    result = v10;
    LODWORD(a3) = v7;
    __break(0x800u);
    if ( (*(_BYTE *)(v10 + 1624) & 0x20) != 0 )
      return drv_link_info_changed(v3, result, *(_QWORD *)(a2 + 944), *(_DWORD *)(a2 + 8), a3);
  }
  return result;
}
