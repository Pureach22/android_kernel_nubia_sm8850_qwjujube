__int64 __fastcall drv_conf_tx(__int64 a1, _DWORD *a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  int v5; // w8
  __int64 result; // x0
  __int64 v7; // x10
  __int64 v8; // x20
  _DWORD *v9; // x21
  const char *v10; // x9
  __int64 v11; // x23
  int v12; // w8
  unsigned int v13; // w9
  __int64 v14; // x8
  int v15; // w3
  __int64 (*v16)(void); // x10

  v4 = *(_QWORD *)a2;
  if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)a2 + 1616LL) + 1471LL) & 1) != 0
    || (v5 = *(_DWORD *)(v4 + 1624), (v5 & 0x20) != 0)
    || (drv_conf_tx___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(v4 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  else
  {
    v7 = *(_QWORD *)(v4 + 1608);
    drv_conf_tx___already_done = 1;
    v8 = a1;
    v9 = a2;
    if ( v7 )
      v10 = (const char *)(v7 + 296);
    else
      v10 = (const char *)(v4 + 1640);
    v11 = a4;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v10, v5);
    a2 = v9;
    a4 = v11;
    a1 = v8;
    __break(0x800u);
    if ( (*(_BYTE *)(v4 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  v12 = a2[2];
  if ( !*(_WORD *)(v4 + 5800) )
  {
    if ( !v12 )
      goto LABEL_12;
    return 0;
  }
  if ( (((unsigned __int64)*(unsigned __int16 *)(v4 + 5802) >> v12) & 1) == 0 )
    return 0;
LABEL_12:
  v13 = *(unsigned __int16 *)(a4 + 2);
  if ( *(_WORD *)(a4 + 2) && v13 <= *(unsigned __int16 *)(a4 + 4) )
  {
    v16 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 464) + 336LL);
    if ( v16 )
    {
      if ( *((_DWORD *)v16 - 1) != -1813400209 )
        __break(0x822Au);
      return v16();
    }
    else
    {
      return 4294967201LL;
    }
  }
  else
  {
    v14 = *(_QWORD *)(a1 + 464);
    result = 4294967274LL;
    if ( *(_QWORD *)(v14 + 336) )
    {
      if ( (drv_conf_tx___already_done_1 & 1) == 0 )
      {
        v15 = *(unsigned __int16 *)(a4 + 4);
        drv_conf_tx___already_done_1 = 1;
        _warn_printk("%s: invalid CW_min/CW_max: %d/%d\n", (const char *)(v4 + 1640), v13, v15);
        __break(0x800u);
        return 4294967274LL;
      }
    }
  }
  return result;
}
