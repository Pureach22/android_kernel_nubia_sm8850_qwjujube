__int64 __fastcall drv_get_tsf(__int64 a1, __int64 a2)
{
  int v2; // w2
  __int64 v4; // x9
  __int64 v5; // x19
  const char *v7; // x8
  __int64 (*v8)(void); // x8

  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1616) + 1471LL) & 1) != 0
    || (v2 = *(_DWORD *)(a2 + 1624), (v2 & 0x20) != 0)
    || (drv_get_tsf___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
      return -1;
  }
  else
  {
    v4 = *(_QWORD *)(a2 + 1608);
    drv_get_tsf___already_done = 1;
    v5 = a1;
    if ( v4 )
      v7 = (const char *)(v4 + 296);
    else
      v7 = (const char *)(a2 + 1640);
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v7, v2);
    a1 = v5;
    __break(0x800u);
    if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
      return -1;
  }
  v8 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 464) + 344LL);
  if ( !v8 )
    return -1;
  if ( *((_DWORD *)v8 - 1) != -1655125308 )
    __break(0x8228u);
  return v8();
}
