__int64 __fastcall drv_mgd_prepare_tx(__int64 result, __int64 a2, __int64 a3)
{
  int v3; // w8
  void (*v4)(void); // x8
  __int64 v5; // x19
  __int64 v6; // x10
  __int64 v7; // x19
  __int64 v8; // x20
  const char *v9; // x9
  __int64 v10; // x21

  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1616) + 1471LL) & 1) != 0
    || (v3 = *(_DWORD *)(a2 + 1624), (v3 & 0x20) != 0)
    || (drv_mgd_prepare_tx___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
      return result;
  }
  else
  {
    v6 = *(_QWORD *)(a2 + 1608);
    drv_mgd_prepare_tx___already_done = 1;
    v7 = result;
    v8 = a2;
    if ( v6 )
      v9 = (const char *)(v6 + 296);
    else
      v9 = (const char *)(a2 + 1640);
    v10 = a3;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v9, v3);
    a2 = v8;
    a3 = v10;
    result = v7;
    __break(0x800u);
    if ( (*(_BYTE *)(v8 + 1624) & 0x20) == 0 )
      return result;
  }
  if ( *(_DWORD *)(a2 + 4720) != 2 )
    __break(0x800u);
  *(_DWORD *)(a3 + 8) &= ~(*(int *)(a3 + 8) >> 31);
  v4 = *(void (**)(void))(*(_QWORD *)(result + 464) + 568LL);
  if ( v4 )
  {
    v5 = result;
    if ( *((_DWORD *)v4 - 1) != -1383142307 )
      __break(0x8228u);
    v4();
    return v5;
  }
  return result;
}
