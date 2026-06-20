__int64 __fastcall drv_change_sta_links(__int64 a1, __int64 a2, __int64 a3, __int16 a4, __int16 a5)
{
  int v5; // w8
  __int64 v7; // x10
  __int64 v8; // x19
  __int64 v9; // x20
  const char *v10; // x9
  __int16 v11; // w22
  __int16 v12; // w23
  __int64 (*v13)(void); // x8

  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1616) + 1471LL) & 1) != 0
    || (v5 = *(_DWORD *)(a2 + 1624), (v5 & 0x20) != 0)
    || (drv_change_sta_links___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  else
  {
    v7 = *(_QWORD *)(a2 + 1608);
    drv_change_sta_links___already_done = 1;
    v8 = a1;
    v9 = a2;
    if ( v7 )
      v10 = (const char *)(v7 + 296);
    else
      v10 = (const char *)(a2 + 1640);
    v11 = a5;
    v12 = a4;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v10, v5);
    a4 = v12;
    a5 = v11;
    a2 = v9;
    a1 = v8;
    __break(0x800u);
    if ( (*(_BYTE *)(v9 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  if ( (unsigned __int16)(*(_WORD *)(a2 + 5802) & a4) == (unsigned __int16)(*(_WORD *)(a2 + 5802) & a5) )
    return 0;
  v13 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 464) + 936LL);
  if ( !v13 )
    return 4294967201LL;
  if ( *((_DWORD *)v13 - 1) != 269072108 )
    __break(0x8228u);
  return v13();
}
