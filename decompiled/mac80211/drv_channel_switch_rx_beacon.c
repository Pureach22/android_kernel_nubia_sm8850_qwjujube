__int64 __fastcall drv_channel_switch_rx_beacon(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  int v3; // w2
  __int64 (__fastcall *v4)(__int64, __int64, __int64); // x9
  __int64 v5; // x10
  __int64 v6; // x20
  __int64 v7; // x21
  const char *v8; // x9
  __int64 v9; // x19

  v2 = *(_QWORD *)(result + 1616);
  if ( (*(_BYTE *)(v2 + 1471) & 1) != 0
    || (v3 = *(_DWORD *)(result + 1624), (v3 & 0x20) != 0)
    || (drv_channel_switch_rx_beacon___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(result + 1624) & 0x20) == 0 )
      return result;
  }
  else
  {
    v5 = *(_QWORD *)(result + 1608);
    drv_channel_switch_rx_beacon___already_done = 1;
    v6 = result;
    v7 = a2;
    if ( v5 )
      v8 = (const char *)(v5 + 296);
    else
      v8 = (const char *)(result + 1640);
    v9 = v2;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v8, v3);
    a2 = v7;
    result = v6;
    v2 = v9;
    __break(0x800u);
    if ( (*(_BYTE *)(v6 + 1624) & 0x20) == 0 )
      return result;
  }
  if ( *(_WORD *)(result + 5800) )
  {
    if ( (((unsigned __int64)*(unsigned __int16 *)(result + 5802) >> *(_BYTE *)(a2 + 49)) & 1) == 0 )
      return result;
  }
  else if ( *(_BYTE *)(a2 + 49) )
  {
    return result;
  }
  v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v2 + 464) + 688LL);
  if ( v4 )
  {
    if ( *((_DWORD *)v4 - 1) != 5125315 )
      __break(0x8229u);
    return v4(v2, result + 4720, a2);
  }
  return result;
}
