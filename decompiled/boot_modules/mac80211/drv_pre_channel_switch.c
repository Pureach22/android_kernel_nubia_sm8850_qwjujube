__int64 __fastcall drv_pre_channel_switch(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w2
  __int64 v5; // x9
  __int64 v6; // x20
  __int64 v7; // x21
  const char *v8; // x8
  __int64 (__fastcall *v9)(__int64, __int64, __int64); // x8

  v2 = *(_QWORD *)(a1 + 1616);
  if ( (*(_BYTE *)(v2 + 1471) & 1) != 0
    || (v3 = *(_DWORD *)(a1 + 1624), (v3 & 0x20) != 0)
    || (drv_pre_channel_switch___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(a1 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  else
  {
    v5 = *(_QWORD *)(a1 + 1608);
    drv_pre_channel_switch___already_done = 1;
    v6 = a1;
    v7 = a2;
    if ( v5 )
      v8 = (const char *)(v5 + 296);
    else
      v8 = (const char *)(a1 + 1640);
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v8, v3);
    a2 = v7;
    a1 = v6;
    __break(0x800u);
    if ( (*(_BYTE *)(v6 + 1624) & 0x20) == 0 )
      return 4294967291LL;
  }
  if ( *(_WORD *)(a1 + 5800) )
  {
    if ( (((unsigned __int64)*(unsigned __int16 *)(a1 + 5802) >> *(_BYTE *)(a2 + 49)) & 1) != 0 )
      goto LABEL_12;
    return 0;
  }
  if ( *(_BYTE *)(a2 + 49) )
    return 0;
LABEL_12:
  v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v2 + 464) + 664LL);
  if ( !v9 )
    return 0;
  if ( *((_DWORD *)v9 - 1) != 1106756285 )
    __break(0x8228u);
  return v9(v2, a1 + 4720, a2);
}
