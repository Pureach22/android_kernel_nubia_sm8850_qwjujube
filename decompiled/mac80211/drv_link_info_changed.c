__int64 __fastcall drv_link_info_changed(__int64 result, __int64 a2, __int64 a3, int a4, int a5)
{
  int v5; // w8
  unsigned int v7; // w9
  unsigned __int64 v8; // t2
  bool v9; // cc
  int v10; // w9
  bool v11; // zf
  int v12; // w8
  __int64 v13; // x9
  void (*v14)(void); // x8
  __int64 v15; // x19
  __int64 v16; // x10
  const char *v17; // x9
  __int64 v18; // [xsp+10h] [xbp-10h]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v5 = *(_DWORD *)(a2 + 4720);
  if ( (a5 & 0x300) != 0
    && ((HIDWORD(v8) = v5 - 1, LODWORD(v8) = v5 - 1, v7 = v8 >> 1, v9 = v7 > 5, v10 = (1 << v7) & 0x2B, !v9)
      ? (v11 = v10 == 0)
      : (v11 = 1),
        v11)
    || v5 == 12
    || v5 == 10
    || v5 == 6 && (a5 & 0x40000) == 0 && (*(_BYTE *)(a2 + 5639) & 1) == 0 )
  {
    __break(0x800u);
    return result;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1616) + 1471LL) & 1) != 0
    || (v12 = *(_DWORD *)(a2 + 1624), (v12 & 0x20) != 0)
    || (drv_link_info_changed___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
      return result;
  }
  else
  {
    v16 = *(_QWORD *)(a2 + 1608);
    drv_link_info_changed___already_done = 1;
    if ( v16 )
      v17 = (const char *)(v16 + 296);
    else
      v17 = (const char *)(a2 + 1640);
    v19 = result;
    v18 = a2;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v17, v12);
    a2 = v18;
    result = v19;
    __break(0x800u);
    if ( (*(_BYTE *)(v18 + 1624) & 0x20) == 0 )
      return result;
  }
  if ( *(_WORD *)(a2 + 5800) )
  {
    if ( (((unsigned __int64)*(unsigned __int16 *)(a2 + 5802) >> a4) & 1) == 0 )
      return result;
  }
  else if ( a4 )
  {
    return result;
  }
  v13 = *(_QWORD *)(result + 464);
  v14 = *(void (**)(void))(v13 + 96);
  if ( v14 || (v14 = *(void (**)(void))(v13 + 80)) != nullptr )
  {
    v15 = result;
    if ( *((_DWORD *)v14 - 1) != 642518393 )
      __break(0x8228u);
    v14();
    return v15;
  }
  return result;
}
