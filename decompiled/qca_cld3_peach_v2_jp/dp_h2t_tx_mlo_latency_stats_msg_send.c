__int64 __fastcall dp_h2t_tx_mlo_latency_stats_msg_send(__int64 a1, unsigned __int16 *a2)
{
  __int64 v2; // x20
  _DWORD *v4; // x0
  __int64 v5; // x19
  __int64 v6; // x2
  __int64 result; // x0
  int v8; // w8
  int v9; // w9
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x22
  int v19; // w8
  int v20; // w8
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x21
  int v31; // w8
  int v32; // w8
  unsigned int v33; // w0
  unsigned int v34; // w22

  v2 = *(_QWORD *)(a1 + 48);
  v4 = (_DWORD *)_qdf_nbuf_alloc(*(_QWORD *)(v2 + 56), 16, 8, 4, 1, "dp_htt_htc_msg_alloc", 87);
  if ( !v4 )
    return 2;
  v5 = (__int64)v4;
  if ( v4[29] )
  {
    v6 = 8;
  }
  else
  {
    v9 = v4[52];
    v8 = v4[53];
    if ( (unsigned int)(v8 - v9) > 7 )
      goto LABEL_8;
    v6 = (unsigned int)(v9 - v8 + 8);
  }
  if ( (unsigned int)pskb_expand_head(v4, 0, v6, 2080) )
  {
    dev_kfree_skb_any_reason(v5, 1);
    goto LABEL_20;
  }
LABEL_8:
  if ( !skb_put(v5, 8) )
  {
LABEL_20:
    qdf_trace_msg(
      0x80u,
      2u,
      "%s: Failed to expand head",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "dp_h2t_tx_mlo_latency_stats_msg_send");
    _qdf_nbuf_free(v5);
    return 16;
  }
  v18 = *(_QWORD *)(v5 + 224);
  *(_QWORD *)v18 = 0;
  skb_push(v5, 0);
  *(_DWORD *)v18 = 40;
  v19 = (*(unsigned __int8 *)a2 << 8) | 0x28;
  *(_DWORD *)v18 = v19;
  *(_DWORD *)v18 = v19 | (a2[1] << 16);
  *(_DWORD *)(v18 + 4) = 0;
  v20 = a2[2];
  *(_DWORD *)(v18 + 4) = v20;
  *(_DWORD *)(v18 + 4) = v20 | (a2[3] << 16);
  v21 = htt_htc_pkt_alloc(v2);
  if ( v21 )
  {
    *(_QWORD *)v21 = 0;
    *(_QWORD *)(v21 + 32) = dp_htt_h2t_send_complete_free_netbuf;
    v30 = v21;
    *(_QWORD *)(v21 + 48) = *(_QWORD *)(v5 + 224);
    if ( (*(_BYTE *)(v5 + 68) & 4) != 0 )
      v31 = *(unsigned __int16 *)(v5 + 66);
    else
      v31 = 0;
    *(_DWORD *)(v21 + 60) = *(_DWORD *)(v5 + 112) + v31;
    v32 = *(_DWORD *)(v2 + 64);
    *(_WORD *)(v21 + 72) = 13;
    *(_DWORD *)(v21 + 88) = 0;
    *(_BYTE *)(v21 + 80) = 0;
    *(_DWORD *)(v21 + 64) = v32;
    *(_QWORD *)(v21 + 112) = v5;
    v33 = htc_send_pkt(*(_QWORD *)(v2 + 48), v21 + 16);
    if ( v33 )
    {
      v34 = v33;
      ++*(_DWORD *)(v2 + 104);
      _qdf_nbuf_free(v5);
      htt_htc_pkt_free(v2, v30);
      return v34;
    }
    else
    {
      result = 0;
      if ( (*(_DWORD *)(v30 + 68) | 8) == 9 )
        ++*(_DWORD *)(v2 + 104);
    }
  }
  else
  {
    qdf_trace_msg(
      0x80u,
      2u,
      "%s: Fail to allocate dp_htt_htc_pkt buffer",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "dp_h2t_tx_mlo_latency_stats_msg_send");
    _qdf_nbuf_free(v5);
    return 2;
  }
  return result;
}
