__int64 __fastcall epping_tx_send(
        _QWORD *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x24
  __int64 result; // x0
  __int64 *v14; // x21
  __int64 *v15; // x25
  __int64 *v16; // x9
  __int64 v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x8
  int v43; // w8
  int v44; // w8

  v10 = a1[28];
  if ( *(unsigned __int8 *)(v10 + 12) != 170
    || *(_BYTE *)(v10 + 13) != 85
    || *(unsigned __int8 *)(v10 + 14) != 206
    || *(unsigned __int8 *)(v10 + 15) != 236 )
  {
    qdf_trace_msg(
      0x33u,
      1u,
      "%s: Received non endpoint ping packets\n",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "epping_tx_send");
    if ( !a1 )
      return 4294967284LL;
LABEL_9:
    _qdf_nbuf_free((__int64)a1);
    return 4294967284LL;
  }
  if ( *(unsigned __int8 *)(v10 + 11) > 1u )
  {
    qdf_trace_msg(
      0x33u,
      1u,
      "%s: ac %d is not mapped to mboxping service\n",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "epping_tx_send");
    if ( !a1 )
      return 4294967284LL;
    goto LABEL_9;
  }
  v15 = (__int64 *)(a2 + 48);
  v14 = *(__int64 **)(a2 + 48);
  if ( v14 )
  {
    while ( 1 )
    {
      v16 = *(__int64 **)(a2 + 56);
      --*(_DWORD *)(a2 + 64);
      if ( v14 == v16 )
      {
        v17 = 0;
        *(_QWORD *)(a2 + 56) = 0;
      }
      else
      {
        v17 = *v14;
      }
      *(_QWORD *)(a2 + 48) = v17;
      *v14 = 0;
      htc_set_nodrop_pkt(*(_QWORD *)(*(_QWORD *)a2 + 56LL), 1);
      if ( (unsigned int)epping_tx_send_int((__int64)v14, (__int64 *)a2) )
        break;
      htc_set_nodrop_pkt(*(_QWORD *)(*(_QWORD *)a2 + 56LL), 0);
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: nodrop: %pK xmit ok\n",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "epping_tx_send",
        v14);
      v14 = *(__int64 **)(a2 + 48);
      if ( !v14 )
        goto LABEL_17;
    }
    qdf_trace_msg(
      0x33u,
      1u,
      "%s: nodrop: %pK xmit fail\n",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "epping_tx_send",
      v14);
    v42 = *v15;
    if ( !*v15 )
      *(_QWORD *)(a2 + 56) = v14;
    *v14 = v42;
    v43 = *(_DWORD *)(a2 + 64);
    *(_QWORD *)(a2 + 48) = v14;
    *(_DWORD *)(a2 + 64) = v43 + 1;
  }
  else
  {
LABEL_17:
    result = epping_tx_send_int((__int64)a1, (__int64 *)a2);
    if ( !(_DWORD)result )
      return result;
  }
  if ( (*(_WORD *)(v10 + 42) & 4) == 0 )
  {
    if ( a1 )
      _qdf_nbuf_free((__int64)a1);
    ++*(_QWORD *)(a2 + 192);
    qdf_trace_msg(
      0x33u,
      1u,
      "%s: Tx skb %pK dropped, stats.tx_dropped = %ld\n",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "epping_tx_send",
      a1);
    return 4294967284LL;
  }
  qdf_trace_msg(0x33u, 1u, "%s: nodrop: %pK queued\n", v34, v35, v36, v37, v38, v39, v40, v41, "epping_tx_send", a1);
  *a1 = 0;
  if ( *v15 )
    v15 = *(__int64 **)(a2 + 56);
  *v15 = (__int64)a1;
  v44 = *(_DWORD *)(a2 + 64);
  *(_QWORD *)(a2 + 56) = a1;
  *(_DWORD *)(a2 + 64) = v44 + 1;
  qdf_spin_lock_bh_11(a2 + 32);
  if ( *(_DWORD *)(a2 + 128) != 1 )
  {
    *(_DWORD *)(a2 + 128) = 1;
    qdf_timer_mod_1(a2 + 72);
  }
  qdf_spin_unlock_bh_12(a2 + 32);
  return 0;
}
