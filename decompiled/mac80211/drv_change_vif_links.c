__int64 __fastcall drv_change_vif_links(__int64 a1, __int64 a2, unsigned __int16 a3, unsigned __int16 a4)
{
  int v4; // w8
  unsigned int v5; // w8
  __int64 v6; // x10
  __int64 v7; // x19
  const char *v9; // x9
  unsigned __int16 v10; // w21
  unsigned __int16 v11; // w23
  char v12; // w9
  __int16 v13; // w21
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x9
  bool v16; // cf
  __int64 (*v17)(void); // x8
  __int64 v18; // x19
  char v20; // w11
  unsigned __int64 v21; // x11
  unsigned __int64 v22; // x11

  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1616) + 1471LL) & 1) != 0
    || (v4 = *(_DWORD *)(a2 + 1624), (v4 & 0x20) != 0)
    || (drv_change_vif_links___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
      return (unsigned int)-5;
  }
  else
  {
    v6 = *(_QWORD *)(a2 + 1608);
    drv_change_vif_links___already_done = 1;
    v7 = a1;
    if ( v6 )
      v9 = (const char *)(v6 + 296);
    else
      v9 = (const char *)(a2 + 1640);
    v10 = a3;
    v11 = a4;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v9, v4);
    a3 = v10;
    a4 = v11;
    a1 = v7;
    __break(0x800u);
    if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
      return (unsigned int)-5;
  }
  if ( a3 == a4 )
    return 0;
  v12 = 0;
  v13 = a4 & ~a3;
  do
  {
    v14 = (-1LL << v12) & a3 & (unsigned __int16)~a4 & 0x7FFF;
    if ( !v14 )
      break;
    v15 = __clz(__rbit64(v14));
    v16 = v15 >= 0xE;
    v12 = v15 + 1;
  }
  while ( !v16 );
  v17 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 464) + 928LL);
  if ( v17 )
  {
    v18 = a1;
    if ( *((_DWORD *)v17 - 1) != -232326602 )
      __break(0x8228u);
    v5 = v17();
    a1 = v18;
  }
  else
  {
    v5 = -95;
  }
  if ( !v5 )
  {
    if ( (*(_BYTE *)(a1 + 1470) & 1) == 0 && (*(_BYTE *)(a1 + 1467) & 1) == 0 )
    {
      v20 = 0;
      while ( 1 )
      {
        v21 = (-1LL << v20) & v13 & 0x7FFF;
        if ( !v21 )
          break;
        v5 = 0;
        v22 = __clz(__rbit64(v21));
        v16 = v22 >= 0xE;
        v20 = v22 + 1;
        if ( v16 )
          return v5;
      }
    }
    return 0;
  }
  return v5;
}
