__int64 __fastcall dp_softap_rx_packet_cbk(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *v10; // x19
  __int64 *v11; // x21
  __int64 v12; // x20
  int v13; // w25
  unsigned __int64 StatusReg; // x28
  __int64 v15; // x26
  __int64 v16; // x23
  unsigned int v17; // w22
  __int64 v18; // x8
  _DWORD *v19; // x22
  __int64 v20; // x8
  int v21; // w8
  const void **v22; // x24
  __int64 v23; // x6
  __int64 v24; // x7
  unsigned int v25; // w24
  const char *v26; // x0
  _DWORD *v27; // x8
  __int64 v28; // x0
  char v29; // w24
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( !a1 || (v10 = a2) == nullptr )
  {
    qdf_trace_msg(0x45u, 2u, "%s: Null params being passed", a3, a4, a5, a6, a7, a8, a9, a10, "dp_softap_rx_packet_cbk");
    result = 16;
    goto LABEL_33;
  }
  v11 = *(__int64 **)(a1 + 32);
  v12 = a1;
  v13 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v15 = *v11;
  do
  {
    v16 = (__int64)v10;
    v10 = (_QWORD *)*v10;
    *(_QWORD *)v16 = 0;
    *(_QWORD *)(v16 + 16) = v11[7];
    ++*(_DWORD *)(StatusReg + 16);
    v17 = *(_DWORD *)(StatusReg + 40);
    v18 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v18;
    if ( v18 && *(_QWORD *)(StatusReg + 16) )
    {
      if ( v17 >= 0x20 )
        goto LABEL_35;
    }
    else
    {
      preempt_schedule(a1);
      if ( v17 >= 0x20 )
LABEL_35:
        __break(0x5512u);
    }
    v19 = (_DWORD *)v11 + 19 * v17 + 58;
    ++v19[15];
    v20 = v11[361] + 1;
    v11[361] = v20;
    v11[361] = v20 + *(unsigned __int16 *)(*(_QWORD *)(v16 + 216) + *(unsigned int *)(v16 + 212) + 6LL);
    if ( (*(_BYTE *)(v16 + 68) & 4) != 0 )
      v21 = *(unsigned __int16 *)(v16 + 66);
    else
      v21 = 0;
    v11[363] += (unsigned int)(*(_DWORD *)(v16 + 112) + v21);
    dp_softap_inspect_dhcp_packet(v12, v16, 1);
    v22 = (const void **)(v16 + 224);
    v13 |= _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(v16 + 224));
    if ( (v13 & 1) != 0 )
    {
      if ( (unsigned int)qdf_mem_cmp((const void *)(v12 + 25), *v22, 6u)
        && (!(*((_DWORD *)v11 + 5) | *((unsigned __int16 *)v11 + 12))
         || (unsigned int)qdf_mem_cmp((char *)v11 + 20, *v22, 6u)) )
      {
        a1 = _qdf_nbuf_free(v16);
        continue;
      }
      dp_softap_update_eapol_da_non_mld_peer(v12, v16);
    }
    wlan_dp_pkt_add_timestamp(v11, 3, v16);
    dp_event_eapol_log(v16, 1);
    qdf_dp_trace_log_pkt(*(unsigned __int8 *)(v12 + 24), v16, 1u, 0xFFu, *((_DWORD *)v11 + 7));
    qdf_dp_trace(v16, 0x1Au, 0xFFu, v16 + 224, 8u, 1, v23, v24);
    qdf_dp_trace_data_pkt(v16, 0xFFu, 0xFu, 0, 1);
    *(_WORD *)(v16 + 180) = eth_type_trans(v16, *(_QWORD *)(v16 + 16));
    v25 = *(_DWORD *)(v15 + 176);
    if ( v25 && (*(_BYTE *)(v16 + 128) & 7u) - 1 >= 2 )
    {
      if ( (unsigned int)cds_get_ring_log_level(0) >= 3 )
      {
        v26 = qdf_wake_lock_name(v15 + 1200);
        ((void (__fastcall *)(__int64, const char *, _QWORD, _QWORD))host_diag_log_wlock)(10, v26, v25, 0);
      }
      qdf_wake_lock_timeout_acquire(v15 + 1200, *(unsigned int *)(v15 + 176));
    }
    if ( (v13 & 1) != 0 && (v27 = *(_DWORD **)(v15 + 504)) != nullptr )
    {
      v28 = v11[7];
      if ( *(v27 - 1) != 326986700 )
        __break(0x8228u);
      v29 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v27)(v28, v12 + 70, v16, 0);
      a1 = consume_skb(v16);
      if ( (v29 & 1) == 0 )
      {
LABEL_5:
        ++v19[18];
        continue;
      }
    }
    else
    {
      a1 = wlan_dp_rx_deliver_to_stack(v11, v16);
      if ( (_DWORD)a1 )
        goto LABEL_5;
    }
    ++v19[17];
  }
  while ( v10 );
  result = 0;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
