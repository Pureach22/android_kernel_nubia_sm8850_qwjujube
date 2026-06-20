__int64 __fastcall ieee80211_bss_info_change_notify(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w8
  unsigned int v4; // w8
  unsigned __int64 v5; // t2
  int v6; // w2
  void (__fastcall *v7)(__int64, __int64, __int64); // x8
  __int64 v8; // x21
  __int64 v9; // x22
  void (__fastcall *v10)(__int64, __int64, __int64, unsigned __int64); // x9
  __int64 v11; // x21
  __int64 v12; // x22
  __int64 (__fastcall *v13)(__int64, __int64, __int64, __int64); // x8
  __int64 v14; // x9
  __int64 v15; // x21
  __int64 v16; // x22
  const char *v17; // x8

  v2 = *(_QWORD *)(result + 1616);
  if ( *(_WORD *)(result + 5800) )
  {
    __break(0x800u);
    if ( !a2 )
      return result;
  }
  else if ( !a2 )
  {
    return result;
  }
  v3 = *(_DWORD *)(result + 4720);
  if ( v3 == 4 )
    return result;
  if ( (a2 & 0x300) != 0 )
  {
    HIDWORD(v5) = v3 - 1;
    LODWORD(v5) = v3 - 1;
    v4 = v5 >> 1;
    if ( v4 > 5 || ((1 << v4) & 0x2B) == 0 )
    {
      __break(0x800u);
      return result;
    }
  }
  else if ( v3 == 12 || v3 == 10 || v3 == 6 && (a2 & 0x40000) == 0 && (*(_BYTE *)(result + 5639) & 1) == 0 )
  {
    __break(0x800u);
    return result;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(result + 1616) + 1471LL) & 1) != 0
    || (v6 = *(_DWORD *)(result + 1624), (v6 & 0x20) != 0)
    || (ieee80211_bss_info_change_notify___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(result + 1624) & 0x20) == 0 )
      return result;
  }
  else
  {
    v14 = *(_QWORD *)(result + 1608);
    ieee80211_bss_info_change_notify___already_done = 1;
    v15 = result;
    v16 = a2;
    if ( v14 )
      v17 = (const char *)(v14 + 296);
    else
      v17 = (const char *)(result + 1640);
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v17, v6);
    a2 = v16;
    result = v15;
    __break(0x800u);
    if ( (*(_BYTE *)(v15 + 1624) & 0x20) == 0 )
      return result;
  }
  if ( (a2 & 0x60002D801LL) != 0 )
  {
    v7 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v2 + 464) + 88LL);
    if ( v7 )
    {
      v8 = a2;
      v9 = result;
      if ( *((_DWORD *)v7 - 1) != -1003313279 )
        __break(0x8228u);
      v7(v2, result + 4720, a2 & 0x60002D801LL);
      a2 = v8;
      result = v9;
    }
  }
  if ( (a2 & 0xFFFFFFF9FFFD27FELL) != 0 )
  {
    v10 = *(void (__fastcall **)(__int64, __int64, __int64, unsigned __int64))(*(_QWORD *)(v2 + 464) + 96LL);
    if ( v10 )
    {
      v11 = a2;
      v12 = result;
      if ( *((_DWORD *)v10 - 1) != 642518393 )
        __break(0x8229u);
      v10(v2, result + 4720, result + 4808, a2 & 0xFFFFFFF9FFFD27FELL);
      a2 = v11;
      result = v12;
    }
  }
  v13 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)(v2 + 464) + 80LL);
  if ( v13 )
  {
    if ( *((_DWORD *)v13 - 1) != 642518393 )
      __break(0x8228u);
    return v13(v2, result + 4720, result + 4808, a2);
  }
  return result;
}
