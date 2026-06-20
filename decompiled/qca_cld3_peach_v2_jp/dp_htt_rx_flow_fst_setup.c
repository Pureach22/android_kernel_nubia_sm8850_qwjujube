__int64 __fastcall dp_htt_rx_flow_fst_setup(__int64 a1, unsigned __int8 *a2)
{
  __int64 v3; // x20
  _DWORD *v4; // x0
  __int64 v5; // x21
  __int64 v6; // x2
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
  unsigned int v19; // w8
  int v20; // w8
  unsigned int v21; // w9
  int v22; // w8
  unsigned int v23; // w9
  int v24; // w8
  int v25; // w9
  int v26; // w10
  _DWORD *v27; // x8
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x22
  int v38; // w8
  int v39; // w8
  unsigned int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w19

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 48LL);
  v4 = (_DWORD *)_qdf_nbuf_alloc(*(_QWORD *)(v3 + 56), 64, 8, 4, 1, "dp_htt_htc_msg_alloc", 87);
  if ( !v4 )
    return 2;
  v5 = (__int64)v4;
  if ( v4[29] )
  {
    v6 = 56;
  }
  else
  {
    v9 = v4[52];
    v8 = v4[53];
    if ( (unsigned int)(v8 - v9) > 0x37 )
      goto LABEL_8;
    v6 = (unsigned int)(v9 - v8 + 56);
  }
  if ( (unsigned int)pskb_expand_head(v4, 0, v6, 2080) )
  {
    dev_kfree_skb_any_reason(v5, 1);
    goto LABEL_26;
  }
LABEL_8:
  if ( !skb_put(v5, 56) )
  {
LABEL_26:
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Failed to expand head for HTT RX_FSE_SETUP msg",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "dp_htt_rx_flow_fst_setup");
    return 16;
  }
  v18 = *(_QWORD *)(v5 + 224);
  *(_QWORD *)(v18 + 40) = 0;
  *(_QWORD *)(v18 + 48) = 0;
  *(_QWORD *)(v18 + 24) = 0;
  *(_QWORD *)(v18 + 32) = 0;
  *(_QWORD *)(v18 + 8) = 0;
  *(_QWORD *)(v18 + 16) = 0;
  *(_QWORD *)v18 = 0;
  skb_push(v5, 0);
  *(_DWORD *)v18 = 18;
  *(_DWORD *)v18 = (*a2 << 8) | 0x12;
  v19 = *((_DWORD *)a2 + 1);
  if ( v19 >= 0x100000 )
  {
    printk(
      &unk_881311,
      "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
      5714,
      "!((fse_setup_info->max_entries) & ~((HTT_RX_FSE_SETUP_NUM_REC_M) >> (HTT_RX_FSE_SETUP_NUM_REC_S)))");
    v19 = *((_DWORD *)a2 + 1);
  }
  v20 = *(_DWORD *)(v18 + 4) | v19;
  *(_DWORD *)(v18 + 4) = v20;
  v21 = *((_DWORD *)a2 + 2);
  if ( v21 >= 0x100 )
  {
    printk(
      &unk_881311,
      "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
      5715,
      "!((fse_setup_info->max_search) & ~((HTT_RX_FSE_SETUP_MAX_SEARCH_M) >> (HTT_RX_FSE_SETUP_MAX_SEARCH_S)))");
    v21 = *((_DWORD *)a2 + 2);
    v20 = *(_DWORD *)(v18 + 4);
  }
  v22 = v20 | (v21 << 20);
  *(_DWORD *)(v18 + 4) = v22;
  v23 = *((_DWORD *)a2 + 5);
  if ( v23 >= 4 )
  {
    printk(
      &unk_881311,
      "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
      5717,
      "!((fse_setup_info->ip_da_sa_prefix) & ~((HTT_RX_FSE_SETUP_IP_DA_SA_PREFIX_M) >> (HTT_RX_FSE_SETUP_IP_DA_SA_PREFIX_S)))");
    v23 = *((_DWORD *)a2 + 5);
    v22 = *(_DWORD *)(v18 + 4);
  }
  v24 = v22 | (v23 << 28);
  v25 = *(_DWORD *)(v18 + 8);
  v26 = *(_DWORD *)(v18 + 12);
  *(_DWORD *)(v18 + 4) = v24;
  *(_DWORD *)(v18 + 8) = v25 | *((_DWORD *)a2 + 3);
  *(_DWORD *)(v18 + 12) = v26 | *((_DWORD *)a2 + 4);
  v27 = *((_DWORD **)a2 + 4);
  *(_DWORD *)(v18 + 16) = *v27;
  *(_DWORD *)(v18 + 20) = v27[1];
  *(_DWORD *)(v18 + 24) = v27[2];
  *(_DWORD *)(v18 + 28) = v27[3];
  *(_DWORD *)(v18 + 32) = v27[4];
  *(_DWORD *)(v18 + 36) = v27[5];
  *(_DWORD *)(v18 + 40) = v27[6];
  *(_DWORD *)(v18 + 44) = v27[7];
  *(_DWORD *)(v18 + 48) = v27[8];
  *(_DWORD *)(v18 + 52) = *(_DWORD *)(v18 + 52) & 0xF8000000 | v27[9] & 0x7FFFFFF;
  v28 = htt_htc_pkt_alloc(v3);
  if ( v28 )
  {
    *(_QWORD *)v28 = 0;
    *(_QWORD *)(v28 + 32) = dp_htt_h2t_send_complete_free_netbuf;
    v37 = v28;
    *(_QWORD *)(v28 + 48) = *(_QWORD *)(v5 + 224);
    if ( (*(_BYTE *)(v5 + 68) & 4) != 0 )
      v38 = *(unsigned __int16 *)(v5 + 66);
    else
      v38 = 0;
    *(_DWORD *)(v28 + 60) = *(_DWORD *)(v5 + 112) + v38;
    v39 = *(_DWORD *)(v3 + 64);
    *(_WORD *)(v28 + 72) = 13;
    *(_DWORD *)(v28 + 88) = 0;
    *(_BYTE *)(v28 + 80) = 0;
    *(_DWORD *)(v28 + 64) = v39;
    *(_QWORD *)(v28 + 112) = v5;
    v40 = htc_send_pkt(*(_QWORD *)(v3 + 48), v28 + 16);
    if ( v40 )
    {
      v49 = v40;
      ++*(_DWORD *)(v3 + 104);
      _qdf_nbuf_free(v5);
      htt_htc_pkt_free(v3, v37);
      return v49;
    }
    else
    {
      if ( (*(_DWORD *)(v37 + 68) | 8) == 9 )
        ++*(_DWORD *)(v3 + 104);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: HTT_H2T RX_FSE_SETUP sent to FW for pdev = %u",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "dp_htt_rx_flow_fst_setup",
        *a2);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(
        166,
        8,
        *((_QWORD *)a2 + 4),
        *((unsigned int *)a2 + 6));
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Fail to allocate dp_htt_htc_pkt buffer",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "dp_htt_rx_flow_fst_setup");
    _qdf_nbuf_free(v5);
    return 1;
  }
}
