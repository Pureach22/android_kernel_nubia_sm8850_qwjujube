__int64 __fastcall drv_leave_ibss(__int64 result, __int64 a2)
{
  int v2; // w2
  void (*v3)(void); // x8
  __int64 v4; // x19
  __int64 v5; // x9
  __int64 v6; // x19
  const char *v8; // x8

  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1616) + 1471LL) & 1) != 0
    || (v2 = *(_DWORD *)(a2 + 1624), (v2 & 0x20) != 0)
    || (drv_leave_ibss___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
      return result;
  }
  else
  {
    v5 = *(_QWORD *)(a2 + 1608);
    drv_leave_ibss___already_done = 1;
    v6 = result;
    if ( v5 )
      v8 = (const char *)(v5 + 296);
    else
      v8 = (const char *)(a2 + 1640);
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v8, v2);
    result = v6;
    __break(0x800u);
    if ( (*(_BYTE *)(a2 + 1624) & 0x20) == 0 )
      return result;
  }
  v3 = *(void (**)(void))(*(_QWORD *)(result + 464) + 704LL);
  if ( v3 )
  {
    v4 = result;
    if ( *((_DWORD *)v3 - 1) != 1098857213 )
      __break(0x8228u);
    v3();
    return v4;
  }
  return result;
}
