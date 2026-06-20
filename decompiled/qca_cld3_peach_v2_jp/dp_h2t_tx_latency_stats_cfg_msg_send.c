__int64 __fastcall dp_h2t_tx_latency_stats_cfg_msg_send(
        __int64 a1,
        unsigned __int16 a2,
        char a3,
        unsigned int a4,
        unsigned int a5)
{
  __int64 result; // x0
  __int64 v8; // x22
  _DWORD *v12; // x0
  __int64 v13; // x21
  __int64 v14; // x2
  int v15; // w8
  int v16; // w9
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int *v25; // x25
  int v26; // w8
  unsigned int v27; // w24
  int v28; // w9
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x25
  int v39; // w8
  int v40; // w8
  unsigned int v41; // w26
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  result = 4;
  if ( HIWORD(a4) || a5 > 0xF )
    return result;
  v8 = *(_QWORD *)(a1 + 48);
  v12 = (_DWORD *)_qdf_nbuf_alloc(*(_QWORD *)(v8 + 56), 12, 8, 4, 1, "dp_htt_htc_msg_alloc", 87);
  if ( !v12 )
    return 2;
  v13 = (__int64)v12;
  if ( v12[29] )
  {
    v14 = 4;
  }
  else
  {
    v16 = v12[52];
    v15 = v12[53];
    if ( (unsigned int)(v15 - v16) > 3 )
      goto LABEL_10;
    v14 = (unsigned int)(v16 - v15 + 4);
  }
  if ( (unsigned int)pskb_expand_head(v12, 0, v14, 2080) )
  {
    dev_kfree_skb_any_reason(v13, 1);
    goto LABEL_27;
  }
LABEL_10:
  if ( !skb_put(v13, 4) )
  {
LABEL_27:
    qdf_trace_msg(
      0x80u,
      2u,
      "%s: Failed to expand head",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "dp_h2t_tx_latency_stats_cfg_msg_send");
    _qdf_nbuf_free(v13);
    return 16;
  }
  v25 = *(int **)(v13 + 224);
  *v25 = 0;
  skb_push(v13, 0);
  v26 = *v25 | 0x25;
  *v25 = v26;
  if ( a2 >= 8u )
  {
    printk(
      &unk_881311,
      "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
      4365,
      "!((vdev_id) & ~((HTT_H2T_TX_LATENCY_STATS_CFG_VDEV_ID_M) >> (HTT_H2T_TX_LATENCY_STATS_CFG_VDEV_ID_S)))");
    v26 = *v25;
  }
  v27 = a3 & 1;
  if ( v27 )
    v28 = 2048;
  else
    v28 = 0;
  *v25 = v28 | (a2 << 8) | (a4 << 12) | (a5 << 28) | v26;
  v29 = htt_htc_pkt_alloc(v8);
  if ( v29 )
  {
    *(_QWORD *)v29 = 0;
    *(_QWORD *)(v29 + 32) = dp_htt_h2t_send_complete_free_netbuf;
    v38 = v29;
    *(_QWORD *)(v29 + 48) = *(_QWORD *)(v13 + 224);
    if ( (*(_BYTE *)(v13 + 68) & 4) != 0 )
      v39 = *(unsigned __int16 *)(v13 + 66);
    else
      v39 = 0;
    *(_DWORD *)(v29 + 60) = *(_DWORD *)(v13 + 112) + v39;
    v40 = *(_DWORD *)(v8 + 64);
    *(_WORD *)(v29 + 72) = 13;
    *(_DWORD *)(v29 + 88) = 0;
    *(_BYTE *)(v29 + 80) = 0;
    *(_DWORD *)(v29 + 64) = v40;
    *(_QWORD *)(v29 + 112) = v13;
    v41 = htc_send_pkt(*(_QWORD *)(v8 + 48), v29 + 16);
    if ( v41 )
    {
      ++*(_DWORD *)(v8 + 104);
      _qdf_nbuf_free(v13);
      htt_htc_pkt_free(v8, v38);
    }
    else if ( (*(_DWORD *)(v38 + 68) | 8) == 9 )
    {
      ++*(_DWORD *)(v8 + 104);
    }
    qdf_trace_msg(
      0x80u,
      8u,
      "%s: vdev id %u enable %u period %u granularity %u status %d",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "dp_h2t_tx_latency_stats_cfg_msg_send",
      a2,
      v27,
      a4,
      a5,
      v41);
    return v41;
  }
  else
  {
    qdf_trace_msg(
      0x80u,
      2u,
      "%s: Fail to allocate dp_htt_htc_pkt buffer",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "dp_h2t_tx_latency_stats_cfg_msg_send");
    _qdf_nbuf_free(v13);
    return 2;
  }
}
