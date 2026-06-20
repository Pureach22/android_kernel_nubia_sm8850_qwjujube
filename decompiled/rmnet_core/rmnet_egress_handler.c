__int64 __fastcall rmnet_egress_handler(__int64 a1, char a2)
{
  __int64 v4; // x8
  __int64 v5; // x21
  __int64 v6; // x0
  char v7; // w28
  __int64 port; // x0
  int v9; // w8
  __int64 v10; // x22
  char v11; // w23
  unsigned int v12; // w26
  unsigned int v13; // w24
  unsigned int v14; // w25
  __int64 v15; // x8
  char v16; // w23
  char v17; // w8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v20; // x9
  unsigned int *v21; // x9
  unsigned int v22; // w12
  __int64 v23; // x9
  unsigned __int64 v24; // x8
  __int64 v25; // x9
  unsigned int *v26; // x9
  unsigned int v27; // w12
  __int64 v28; // x9
  unsigned int v29; // [xsp+Ch] [xbp-4h]

  v4 = *(_QWORD *)(a1 + 24);
  if ( v4 && ((1 << *(_BYTE *)(v4 + 18)) & 0xFFFFEFBF) != 0 && *(_BYTE *)(v4 + 560) != 8 )
    *(_BYTE *)(v4 + 560) = 8;
  v5 = *(_QWORD *)(a1 + 16);
  v6 = *(_QWORD *)(v5 + 2696);
  *(_QWORD *)(a1 + 16) = v6;
  v7 = *(_BYTE *)(v5 + 2688);
  port = rmnet_get_port(v6);
  if ( !port )
    goto LABEL_37;
  v9 = *(_DWORD *)(port + 8);
  v10 = port;
  if ( (v9 & 8) != 0 )
  {
    v11 = 0;
    v12 = 8;
    goto LABEL_10;
  }
  if ( (v9 & 0x10000040) != 0 )
  {
    v11 = 0;
    v12 = 64;
LABEL_10:
    v13 = 4;
    goto LABEL_11;
  }
  v13 = 0;
  v12 = 0;
  v11 = 1;
LABEL_11:
  v14 = v13 + 4;
  v29 = *(_DWORD *)(a1 + 112);
  if ( v13 + 4 > *(_DWORD *)(a1 + 224) - *(_DWORD *)(a1 + 216) )
  {
    port = pskb_expand_head(a1, v14, 0, 2080);
    if ( (_DWORD)port )
      goto LABEL_37;
    v9 = *(_DWORD *)(v10 + 8);
  }
  if ( (v9 & 0x8000000) != 0 )
    qmi_rmnet_work_maybe_restart(v10, 0, 0);
  if ( (v11 & 1) != 0 )
    goto LABEL_22;
  v15 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
  if ( (*(_DWORD *)(v15 + 24) & 0x20011) == 0 || !*(_WORD *)(v15 + 4) )
  {
    rmnet_map_checksum_uplink_packet(a1, v10, v5, v12, a2 & 1);
LABEL_22:
    v16 = 0;
    goto LABEL_23;
  }
  raw_spin_lock_bh(v10 + 200LL * (a2 & 1) + 2208);
  rmnet_map_send_agg_skb(v10 + 200LL * (a2 & 1) + 2072);
  port = rmnet_map_add_tso_header(a1, v10, v5);
  if ( (_DWORD)port )
    goto LABEL_37;
  v16 = 1;
LABEL_23:
  port = rmnet_map_add_map_header(a1, v13, 0, v10);
  if ( port )
  {
    *(_BYTE *)(port + 1) = v7;
    if ( (*(_DWORD *)(v10 + 8) & 0x80000000) != 0
      && *(unsigned __int8 *)(v10 + 200LL * (a2 & 1) + 2074) >= 2u
      && ((unsigned int)rmnet_map_tx_agg_skip(a1, v14) ? (v17 = 1) : (v17 = v16), (v17 & 1) == 0) )
    {
      rmnet_map_tx_aggregate(a1, v10, a2 & 1);
      return rmnet_vnd_tx_fixup(v5, v29);
    }
    else
    {
      *(_WORD *)(a1 + 180) = -1792;
      rmnet_vnd_tx_fixup(v5, v29);
      if ( (a2 & 1) != 0 )
      {
        result = rmnet_ll_send_skb(a1);
        if ( (_DWORD)result )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          ++*(_DWORD *)(StatusReg + 16);
          v20 = *(_QWORD *)(v5 + 2704);
          v21 = (unsigned int *)(v20 + _ReadStatusReg(TPIDR_EL1) + 32);
          do
            v22 = __ldxr(v21);
          while ( __stxr(v22 + 1, v21) );
          v23 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v23;
          if ( !v23 || !*(_QWORD *)(StatusReg + 16) )
            return preempt_schedule_notrace(result);
        }
      }
      else
      {
        return _dev_queue_xmit(a1, 0);
      }
    }
    return result;
  }
LABEL_37:
  v24 = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(v24 + 16);
  v25 = *(_QWORD *)(v5 + 2704);
  v26 = (unsigned int *)(v25 + _ReadStatusReg(TPIDR_EL1) + 32);
  do
    v27 = __ldxr(v26);
  while ( __stxr(v27 + 1, v26) );
  v28 = *(_QWORD *)(v24 + 16) - 1LL;
  *(_DWORD *)(v24 + 16) = v28;
  if ( !v28 || !*(_QWORD *)(v24 + 16) )
    preempt_schedule_notrace(port);
  return sk_skb_reason_drop(0, a1, 2);
}
