__int64 __fastcall drv_unassign_vif_chanctx(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w8
  int v5; // w8
  void (*v6)(void); // x8
  __int64 v7; // x19
  __int64 v8; // x10
  __int64 v9; // x19
  __int64 v10; // x20
  const char *v11; // x9
  __int64 v12; // x21
  __int64 v13; // x22

  if ( *(_DWORD *)(a2 + 4720) == 6 && *(_BYTE *)(result + 1400) == 1 && (*(_QWORD *)(result + 96) & 0x1000) == 0 )
    return result;
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1616) + 1471LL) & 1) != 0
    || (v4 = *(_DWORD *)(a2 + 1624), (v4 & 0x20) != 0)
    || (drv_unassign_vif_chanctx___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
      return result;
  }
  else
  {
    v8 = *(_QWORD *)(a2 + 1608);
    drv_unassign_vif_chanctx___already_done = 1;
    v9 = result;
    v10 = a2;
    if ( v8 )
      v11 = (const char *)(v8 + 296);
    else
      v11 = (const char *)(a2 + 1640);
    v12 = a3;
    v13 = a4;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v11, v4);
    a2 = v10;
    a4 = v13;
    a3 = v12;
    result = v9;
    __break(0x800u);
    if ( (*(_BYTE *)(v10 + 1624) & 0x20) == 0 )
      return result;
  }
  v5 = *(_DWORD *)(a3 + 24);
  if ( *(_WORD *)(a2 + 5800) )
  {
    if ( (((unsigned __int64)*(unsigned __int16 *)(a2 + 5802) >> v5) & 1) == 0 )
      return result;
  }
  else if ( v5 )
  {
    return result;
  }
  v6 = *(void (**)(void))(*(_QWORD *)(result + 464) + 624LL);
  if ( v6 )
  {
    if ( (*(_BYTE *)(a4 + 84) & 1) == 0 )
    {
      __break(0x800u);
      v6 = *(void (**)(void))(*(_QWORD *)(result + 464) + 624LL);
    }
    v7 = result;
    if ( *((_DWORD *)v6 - 1) != -993004536 )
      __break(0x8228u);
    v6();
    return v7;
  }
  return result;
}
