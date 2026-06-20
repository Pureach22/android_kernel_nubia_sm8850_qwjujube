__int64 __fastcall nl80211_register_mgmt(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x9
  __int16 *v3; // x3
  __int64 v4; // x8
  _DWORD *v5; // x0
  unsigned __int16 v6; // w2
  unsigned int v7; // w8
  unsigned int v8; // w11
  _BYTE *v9; // x10
  __int64 v10; // x9
  _QWORD *v11; // x20
  const void *v12; // x3
  __int16 v13; // t1
  bool v14; // zf
  unsigned __int16 v15; // w9
  char v16; // w5

  v2 = *(_QWORD **)(a2 + 32);
  v3 = (__int16 *)v2[91];
  if ( v3 )
  {
    v4 = v2[101];
    v5 = *(_DWORD **)(a2 + 56);
    if ( v4 )
      v6 = *(_WORD *)(v4 + 4);
    else
      v6 = 208;
    v8 = v5[2];
    v7 = -95;
    if ( v8 <= 0xC )
    {
      v9 = *(_BYTE **)(a2 + 48);
      if ( ((1 << v8) & 0x79E) == 0 )
      {
        if ( v8 != 12 )
          return v7;
        if ( (*(char *)(*(_QWORD *)v5 + 119LL) & 0x80000000) == 0 )
          return (unsigned int)-95;
      }
      if ( !*(_QWORD *)(*(_QWORD *)v9 + 520LL) )
        return (unsigned int)-95;
      v10 = v2[289];
      if ( v10 && (v9[1109] & 0x20) == 0 )
      {
        v11 = *(_QWORD **)(a2 + 64);
        do_trace_netlink_extack("multicast RX registrations are not supported");
        if ( v11 )
          *v11 = "multicast RX registrations are not supported";
        return (unsigned int)-95;
      }
      v13 = *v3;
      v12 = v3 + 2;
      v14 = v10 == 0;
      v15 = v13 - 4;
      v16 = !v14;
      return (unsigned int)cfg80211_mlme_register_mgmt(
                             (unsigned __int64)v5,
                             *(_DWORD *)(a2 + 4),
                             v6,
                             v12,
                             v15,
                             v16,
                             *(const char ***)(a2 + 64));
    }
  }
  else
  {
    return (unsigned int)-22;
  }
  return v7;
}
