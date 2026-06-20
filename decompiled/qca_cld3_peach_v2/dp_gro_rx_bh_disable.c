__int64 __fastcall dp_gro_rx_bh_disable(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x21
  unsigned __int64 v6; // x23
  int v7; // w24
  int v8; // w22
  __int64 v9; // x0
  __int64 (__fastcall *v10)(__int64, __int64); // x8
  __int64 result; // x0
  _DWORD *v12; // x8
  unsigned __int64 v13; // x8
  char is_tcp_ack; // w8
  _BYTE v16[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a1;
  v16[0] = 0;
  v6 = *(_QWORD *)(a3 + 72);
  v7 = *(_DWORD *)(v5 + 1176);
  v8 = *((_DWORD *)a1 + 896);
  v9 = a2;
  if ( (*(_BYTE *)(a3 + 54) & 0x10) != 0 && (v6 & 4) == 0 )
  {
    is_tcp_ack = wlan_dp_stc_rx_nbuf_is_tcp_ack(a3);
    v9 = a2;
    if ( (is_tcp_ack & 1) == 0 )
    {
      wlan_dp_stc_track_flow_features();
      v9 = a2;
    }
  }
  if ( *(_DWORD *)(v5 + 1024) != 1 && v7 && !v8 )
  {
    v10 = *(__int64 (__fastcall **)(__int64, __int64))(v5 + 456);
    if ( *((_DWORD *)v10 - 1) != 667692554 )
      __break(0x8228u);
    result = v10(v9, a3);
    goto LABEL_19;
  }
  v12 = *(_DWORD **)(v5 + 440);
  if ( *(v12 - 1) != -362009893 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _BYTE *))v12)(v9, a3, v16);
  if ( v16[0] )
  {
    v13 = (v6 >> 18) & 0xF;
    if ( v7 )
      goto LABEL_12;
  }
  else
  {
    ++*((_DWORD *)a1 + 671);
    v13 = (v6 >> 18) & 0xF;
    if ( v7 )
    {
LABEL_12:
      if ( !v8 )
        goto LABEL_19;
      goto LABEL_17;
    }
  }
  if ( v13 >= 8 )
    goto LABEL_23;
  *(_BYTE *)(v5 + v13 + 1180) = 1;
  if ( !v8 )
  {
LABEL_19:
    _ReadStatusReg(SP_EL0);
    return result;
  }
LABEL_17:
  if ( v13 <= 7 )
  {
    *((_BYTE *)a1 + v13 + 3588) = 1;
    goto LABEL_19;
  }
LABEL_23:
  __break(0x5512u);
  return wlan_dp_stc_rx_nbuf_is_tcp_ack(result);
}
