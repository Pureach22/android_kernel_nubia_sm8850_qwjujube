__int64 __fastcall wlan_dp_rx_deliver_to_stack(__int64 *a1, __int64 a2)
{
  __int64 v4; // x21
  unsigned __int64 v5; // x22
  __int64 context; // x8
  _BOOL4 v7; // w9
  __int64 v8; // x0
  unsigned __int64 v9; // x22
  bool v10; // w10
  bool v11; // w11
  __int64 (__fastcall *v12)(__int64 *, __int64); // x8
  __int64 v13; // x1
  __int64 v14; // x20
  __int64 (__fastcall *v15)(__int64, __int64); // x8
  __int64 result; // x0
  unsigned int v17; // w23
  int v18; // w8
  unsigned int v19; // w21
  char is_tcp_ack; // w0

  v4 = *a1;
  v5 = *(_QWORD *)(a2 + 72);
  context = _cds_get_context(71, "wlan_dp_rx_deliver_to_stack");
  v7 = (*(_BYTE *)(a2 + 72) & 2) != 0 && (*(_BYTE *)(a2 + 48) & 2) == 0;
  v8 = ((unsigned int)v5 >> 18) & 0xF;
  v9 = (v5 >> 18) & 0xF;
  if ( *((_DWORD *)a1 + 896) )
  {
    if ( v9 > 7 )
      goto LABEL_52;
    if ( *((_BYTE *)a1 + v9 + 3588) )
      v10 = v7;
    else
      v10 = 0;
    if ( !v10 && context )
    {
      if ( (unsigned int)v8 < 8 )
      {
        *((_BYTE *)a1 + v9 + 3596) = 1;
        goto LABEL_22;
      }
LABEL_52:
      __break(0x5512u);
      return dp_rx_flush_packet_cbk(v8);
    }
  }
  else
  {
    if ( v9 >= 8 )
      goto LABEL_52;
    if ( *((_BYTE *)a1 + v9 + 3588) )
      v11 = 0;
    else
      v11 = v7;
    if ( !v11 )
    {
      if ( context )
      {
        if ( (unsigned int)v8 >= 8 )
          goto LABEL_52;
        *((_BYTE *)a1 + v9 + 3596) = 0;
      }
      *((_BYTE *)a1 + v9 + 3588) = 0;
    }
  }
LABEL_22:
  if ( v7 )
  {
    v12 = *(__int64 (__fastcall **)(__int64 *, __int64))(v4 + 1168);
    if ( v12 )
    {
      if ( !*(_BYTE *)(v4 + v9 + 1180) && !*((_BYTE *)a1 + v9 + 3588) )
      {
        v17 = v8;
        if ( *((_DWORD *)v12 - 1) != 1018794528 )
          __break(0x8228u);
        result = v12(a1, a2);
        if ( (_DWORD)result == 47 )
        {
          ++*((_DWORD *)a1 + 668);
          return result;
        }
        v18 = result;
        v8 = v17;
        if ( !v18 )
        {
          ++*((_DWORD *)a1 + 667);
          return 0;
        }
      }
    }
  }
  if ( *(_DWORD *)(v4 + 1176) && *(_BYTE *)(v4 + 1180 + v9) )
    *(_BYTE *)(v4 + 1180 + v9) = 0;
  ++*((_DWORD *)a1 + 669);
  if ( *(_WORD *)(*(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + 6LL) )
  {
    if ( (*(_BYTE *)(v4 + 371) & 1) != 0 )
      goto LABEL_34;
  }
  else
  {
    ++*(_QWORD *)(v4 + 856);
    if ( (*(_BYTE *)(v4 + 371) & 1) != 0 )
      goto LABEL_34;
  }
  if ( *(_BYTE *)(v4 + 370) != 1 )
  {
LABEL_36:
    v13 = ((*(_DWORD *)(a2 + 48) >> 1) & 1) == 0;
    goto LABEL_39;
  }
LABEL_34:
  if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFF00) != 0
    && ((dp_rx_is_ring_latency_sensitive_reo(v8) & 1) != 0 || *((_BYTE *)a1 + 3614) == 1) )
  {
    goto LABEL_36;
  }
  v13 = 2;
LABEL_39:
  v14 = *a1;
  if ( (*(_BYTE *)(a2 + 54) & 0x10) != 0 && (*(_BYTE *)(a2 + 72) & 4) == 0 )
  {
    v19 = v13;
    is_tcp_ack = wlan_dp_stc_rx_nbuf_is_tcp_ack(a2);
    v13 = v19;
    if ( (is_tcp_ack & 1) == 0 )
    {
      wlan_dp_stc_track_flow_features();
      v13 = v19;
    }
  }
  v15 = *(__int64 (__fastcall **)(__int64, __int64))(v14 + 432);
  if ( *((_DWORD *)v15 - 1) != 1638896126 )
    __break(0x8228u);
  return v15(a2, v13);
}
