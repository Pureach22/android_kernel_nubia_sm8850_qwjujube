__int64 __fastcall drv_sta_rc_update(__int64 result, __int64 a2, __int64 a3, char a4)
{
  int v4; // w8
  int v5; // w8
  void (*v6)(void); // x8
  __int64 v7; // x19
  __int64 v8; // x10
  __int64 v9; // x19
  __int64 v10; // x20
  const char *v11; // x9
  char v12; // w22

  if ( a2 && *(_DWORD *)(a2 + 4720) == 4 )
    a2 = *(_QWORD *)(a2 + 2032) - 2264LL;
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1616) + 1471LL) & 1) != 0
    || (v4 = *(_DWORD *)(a2 + 1624), (v4 & 0x20) != 0)
    || (drv_sta_rc_update___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
      return result;
  }
  else
  {
    v8 = *(_QWORD *)(a2 + 1608);
    drv_sta_rc_update___already_done = 1;
    v9 = result;
    v10 = a2;
    if ( v8 )
      v11 = (const char *)(v8 + 296);
    else
      v11 = (const char *)(a2 + 1640);
    v12 = a4;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v11, v4);
    a2 = v10;
    a4 = v12;
    result = v9;
    __break(0x800u);
    if ( (*(_BYTE *)(v10 + 1624) & 0x20) == 0 )
      return result;
  }
  if ( (a4 & 4) != 0 )
  {
    v5 = *(_DWORD *)(a2 + 4720);
    if ( v5 != 1 && v5 != 7 )
      __break(0x800u);
  }
  v6 = *(void (**)(void))(*(_QWORD *)(result + 464) + 312LL);
  if ( v6 )
  {
    v7 = result;
    if ( *((_DWORD *)v6 - 1) != -1427988910 )
      __break(0x8228u);
    v6();
    return v7;
  }
  return result;
}
