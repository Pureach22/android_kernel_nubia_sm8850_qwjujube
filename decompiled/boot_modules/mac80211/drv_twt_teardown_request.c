__int64 __fastcall drv_twt_teardown_request(__int64 result, __int64 a2)
{
  int v2; // w8
  __int64 (*v3)(void); // x8
  __int64 v4; // x10
  __int64 v5; // x19
  const char *v7; // x9

  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1616) + 1471LL) & 1) != 0
    || (v2 = *(_DWORD *)(a2 + 1624), (v2 & 0x20) != 0)
    || (drv_twt_teardown_request___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
      return result;
  }
  else
  {
    v4 = *(_QWORD *)(a2 + 1608);
    drv_twt_teardown_request___already_done = 1;
    v5 = result;
    if ( v4 )
      v7 = (const char *)(v4 + 296);
    else
      v7 = (const char *)(a2 + 1640);
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v7, v2);
    result = v5;
    __break(0x800u);
    if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
      return result;
  }
  if ( *(_QWORD *)(*(_QWORD *)(result + 464) + 896LL) )
  {
    v3 = *(__int64 (**)(void))(*(_QWORD *)(result + 464) + 896LL);
    if ( *((_DWORD *)v3 - 1) != -818061135 )
      __break(0x8228u);
    return v3();
  }
  return result;
}
