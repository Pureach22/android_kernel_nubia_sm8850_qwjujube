__int64 __fastcall drv_set_key(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w8
  __int64 v7; // x10
  __int64 v8; // x19
  const char *v9; // x9
  __int64 v10; // x21
  __int64 v11; // x22
  __int64 v12; // x8
  __int64 (*v13)(void); // x8

  if ( a3 && *(_DWORD *)(a3 + 4720) == 4 )
    a3 = *(_QWORD *)(a3 + 2032) - 2264LL;
  if ( (*(_BYTE *)(*(_QWORD *)(a3 + 1616) + 1471LL) & 1) != 0
    || (v5 = *(_DWORD *)(a3 + 1624), (v5 & 0x20) != 0)
    || (drv_set_key___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(a3 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  else
  {
    v7 = *(_QWORD *)(a3 + 1608);
    drv_set_key___already_done = 1;
    v8 = a1;
    if ( v7 )
      v9 = (const char *)(v7 + 296);
    else
      v9 = (const char *)(a3 + 1640);
    v10 = a3;
    v11 = a5;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v9, v5);
    a3 = v10;
    a5 = v11;
    a1 = v8;
    __break(0x800u);
    if ( (*(_BYTE *)(v10 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  v12 = *(char *)(a5 + 18);
  if ( v12 < 0 || !*(_WORD *)(a3 + 5802) || (((unsigned __int64)*(unsigned __int16 *)(a3 + 5802) >> v12) & 1) != 0 )
  {
    v13 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 464) + 152LL);
    if ( *((_DWORD *)v13 - 1) != -391330876 )
      __break(0x8228u);
    return v13();
  }
  else
  {
    __break(0x800u);
    return 4294967229LL;
  }
}
