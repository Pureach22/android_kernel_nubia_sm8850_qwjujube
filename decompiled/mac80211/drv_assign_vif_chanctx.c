__int64 __fastcall drv_assign_vif_chanctx(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w8
  __int64 v6; // x10
  __int64 v7; // x19
  __int64 v8; // x20
  const char *v9; // x9
  __int64 v10; // x21
  __int64 v11; // x22
  int v12; // w8
  __int64 (*v13)(void); // x8

  if ( *(_DWORD *)(a2 + 4720) == 6 && *(_BYTE *)(a1 + 1400) == 1 && (*(_QWORD *)(a1 + 96) & 0x1000) == 0 )
    return 0;
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1616) + 1471LL) & 1) != 0
    || (v4 = *(_DWORD *)(a2 + 1624), (v4 & 0x20) != 0)
    || (drv_assign_vif_chanctx___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  else
  {
    v6 = *(_QWORD *)(a2 + 1608);
    drv_assign_vif_chanctx___already_done = 1;
    v7 = a1;
    v8 = a2;
    if ( v6 )
      v9 = (const char *)(v6 + 296);
    else
      v9 = (const char *)(a2 + 1640);
    v10 = a3;
    v11 = a4;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v9, v4);
    a2 = v8;
    a4 = v11;
    a3 = v10;
    a1 = v7;
    __break(0x800u);
    if ( (*(_BYTE *)(v8 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  v12 = *(_DWORD *)(a3 + 24);
  if ( *(_WORD *)(a2 + 5800) )
  {
    if ( (((unsigned __int64)*(unsigned __int16 *)(a2 + 5802) >> v12) & 1) != 0 )
      goto LABEL_15;
    return 0;
  }
  if ( v12 )
    return 0;
LABEL_15:
  v13 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 464) + 616LL);
  if ( !v13 )
    return 0;
  if ( (*(_BYTE *)(a4 + 84) & 1) == 0 )
  {
    __break(0x800u);
    v13 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 464) + 616LL);
  }
  if ( *((_DWORD *)v13 - 1) != -1974405541 )
    __break(0x8228u);
  return v13();
}
