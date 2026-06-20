__int64 __fastcall dp_htt_rx_fisa_config(__int64 a1, unsigned __int8 *a2)
{
  __int64 v3; // x20
  _DWORD *v4; // x0
  __int64 v5; // x19
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
  int v19; // w8
  unsigned int v20; // w9
  int v21; // w9
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x22
  int v32; // w8
  int v33; // w8
  unsigned int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w21

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 48LL);
  v4 = (_DWORD *)_qdf_nbuf_alloc(*(_QWORD *)(v3 + 56), 20, 8, 4, 1, "dp_htt_htc_msg_alloc", 87);
  if ( !v4 )
    return 2;
  v5 = (__int64)v4;
  if ( v4[29] )
  {
    v6 = 12;
  }
  else
  {
    v9 = v4[52];
    v8 = v4[53];
    if ( (unsigned int)(v8 - v9) > 0xB )
      goto LABEL_8;
    v6 = (unsigned int)(v9 - v8 + 12);
  }
  if ( (unsigned int)pskb_expand_head(v4, 0, v6, 2080) )
  {
    dev_kfree_skb_any_reason(v5, 1);
    goto LABEL_25;
  }
LABEL_8:
  if ( !skb_put(v5, 12) )
  {
LABEL_25:
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Failed to expand head for HTT_RX_FSE_OPERATION msg",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "dp_htt_rx_fisa_config");
    _qdf_nbuf_free(v5);
    return 16;
  }
  v18 = *(_QWORD *)(v5 + 224);
  *(_DWORD *)(v18 + 8) = 0;
  *(_QWORD *)v18 = 0;
  skb_push(v5, 0);
  v19 = *(_DWORD *)(v18 + 4) | 1;
  *(_DWORD *)v18 = 21;
  *(_DWORD *)(v18 + 4) = v19;
  v20 = a2[8];
  if ( v20 >= 0x40 )
  {
    printk(
      &unk_94DB9D,
      "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
      6003,
      "!(((fisa_config->max_aggr_supported ? fisa_config->max_aggr_supported : 0xf)) & ~((HTT_RX_FISA_CONFIG_FISA_V2_AGGR"
      "_LIMIT_M) >> (HTT_RX_FISA_CONFIG_FISA_V2_AGGR_LIMIT_S)))");
    v20 = a2[8];
    v19 = *(_DWORD *)(v18 + 4);
  }
  if ( v20 )
    v21 = 2 * v20;
  else
    v21 = 30;
  *(_DWORD *)(v18 + 4) = v21 | v19;
  *(_DWORD *)(v18 + 8) = *((_DWORD *)a2 + 1);
  v22 = htt_htc_pkt_alloc(v3);
  if ( v22 )
  {
    *(_QWORD *)v22 = 0;
    *(_QWORD *)(v22 + 32) = dp_htt_h2t_send_complete_free_netbuf;
    v31 = v22;
    *(_QWORD *)(v22 + 48) = *(_QWORD *)(v5 + 224);
    if ( (*(_BYTE *)(v5 + 68) & 4) != 0 )
      v32 = *(unsigned __int16 *)(v5 + 66);
    else
      v32 = 0;
    *(_DWORD *)(v22 + 60) = *(_DWORD *)(v5 + 112) + v32;
    v33 = *(_DWORD *)(v3 + 64);
    *(_WORD *)(v22 + 72) = 13;
    *(_DWORD *)(v22 + 88) = 0;
    *(_BYTE *)(v22 + 80) = 0;
    *(_DWORD *)(v22 + 64) = v33;
    *(_QWORD *)(v22 + 112) = v5;
    v34 = htc_send_pkt(*(_QWORD *)(v3 + 48), v22 + 16);
    if ( v34 )
    {
      v43 = v34;
      ++*(_DWORD *)(v3 + 104);
      _qdf_nbuf_free(v5);
      htt_htc_pkt_free(v3, v31);
      return v43;
    }
    else
    {
      if ( (*(_DWORD *)(v31 + 68) | 8) == 9 )
        ++*(_DWORD *)(v3 + 104);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: HTT_H2T_MSG_TYPE_RX_FISA_CFG sent to FW for pdev = %u",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "dp_htt_rx_fisa_config",
        *a2);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Fail to allocate dp_htt_htc_pkt buffer",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "dp_htt_rx_fisa_config");
    _qdf_nbuf_free(v5);
    return 1;
  }
}
