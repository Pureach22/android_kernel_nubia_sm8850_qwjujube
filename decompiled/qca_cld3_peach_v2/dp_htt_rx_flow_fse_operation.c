__int64 __fastcall dp_htt_rx_flow_fse_operation(__int64 a1, unsigned __int8 *a2)
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
  int v20; // w9
  int v21; // w8
  int v22; // w10
  int v23; // w10
  int v24; // w10
  int v25; // w10
  int v26; // w9
  int v27; // w8
  unsigned int v28; // w8
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x22
  int v39; // w8
  int v40; // w8
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w21

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 48LL);
  v4 = (_DWORD *)_qdf_nbuf_alloc(*(_QWORD *)(v3 + 56), 56, 8, 4, 1, "dp_htt_htc_msg_alloc", 87);
  if ( !v4 )
    return 2;
  v5 = (__int64)v4;
  if ( v4[29] )
  {
    v6 = 48;
  }
  else
  {
    v9 = v4[52];
    v8 = v4[53];
    if ( (unsigned int)(v8 - v9) > 0x2F )
      goto LABEL_8;
    v6 = (unsigned int)(v9 - v8 + 48);
  }
  if ( (unsigned int)pskb_expand_head(v4, 0, v6, 2080) )
  {
    dev_kfree_skb_any_reason(v5, 1);
    goto LABEL_32;
  }
LABEL_8:
  if ( !skb_put(v5, 48) )
  {
LABEL_32:
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
      "dp_htt_rx_flow_fse_operation");
    _qdf_nbuf_free(v5);
    return 16;
  }
  v18 = *(_QWORD *)(v5 + 224);
  *(_QWORD *)(v18 + 32) = 0;
  *(_QWORD *)(v18 + 40) = 0;
  *(_QWORD *)(v18 + 16) = 0;
  *(_QWORD *)(v18 + 24) = 0;
  *(_QWORD *)v18 = 0;
  *(_QWORD *)(v18 + 8) = 0;
  skb_push(v5, 0);
  *(_DWORD *)v18 = 19;
  *(_DWORD *)v18 = (*a2 << 8) | 0x13;
  v19 = *(_DWORD *)(v18 + 4);
  v20 = *((_DWORD *)a2 + 1);
  if ( v20 > 2 )
  {
    if ( v20 == 3 )
    {
      v21 = v19 | 8;
    }
    else
    {
      if ( v20 != 4 )
        goto LABEL_21;
      v21 = v19 | 6;
    }
    goto LABEL_20;
  }
  if ( v20 == 1 )
  {
    *(_DWORD *)(v18 + 4) = v19 | 2;
    v22 = *(_DWORD *)(v18 + 12);
    *(_DWORD *)(v18 + 8) |= bswap32(*(_DWORD *)(*((_QWORD *)a2 + 1) + 40LL));
    *(_DWORD *)(v18 + 12) = v22 | bswap32(*(_DWORD *)(*((_QWORD *)a2 + 1) + 36LL));
    v23 = *(_DWORD *)(v18 + 20);
    *(_DWORD *)(v18 + 16) |= bswap32(*(_DWORD *)(*((_QWORD *)a2 + 1) + 32LL));
    *(_DWORD *)(v18 + 20) = v23 | bswap32(*(_DWORD *)(*((_QWORD *)a2 + 1) + 28LL));
    v24 = *(_DWORD *)(v18 + 28);
    *(_DWORD *)(v18 + 24) |= bswap32(*(_DWORD *)(*((_QWORD *)a2 + 1) + 24LL));
    *(_DWORD *)(v18 + 28) = v24 | bswap32(*(_DWORD *)(*((_QWORD *)a2 + 1) + 20LL));
    v25 = *(_DWORD *)(v18 + 36);
    v26 = *(_DWORD *)(v18 + 40);
    *(_DWORD *)(v18 + 32) |= bswap32(*(_DWORD *)(*((_QWORD *)a2 + 1) + 16LL));
    *(_DWORD *)(v18 + 36) = v25 | bswap32(*(_DWORD *)(*((_QWORD *)a2 + 1) + 12LL));
    v27 = v26 | *(unsigned __int16 *)(*((_QWORD *)a2 + 1) + 46LL);
    *(_DWORD *)(v18 + 40) = v27;
    *(_DWORD *)(v18 + 40) = v27 | (*(unsigned __int16 *)(*((_QWORD *)a2 + 1) + 44LL) << 16);
    v28 = *(unsigned __int16 *)(*((_QWORD *)a2 + 1) + 48LL);
    if ( v28 >= 0x100 )
    {
      printk(
        &unk_94DB9D,
        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
        5894,
        "!((fse_op_info->rx_flow->flow_tuple_info.l4_protocol) & ~((HTT_RX_FSE_L4_PROTO_M) >> (HTT_RX_FSE_L4_PROTO_S)))");
      v28 = *(unsigned __int16 *)(*((_QWORD *)a2 + 1) + 48LL);
    }
    *(_DWORD *)(v18 + 44) |= v28;
    goto LABEL_21;
  }
  if ( v20 == 2 )
  {
    v21 = v19 | 4;
LABEL_20:
    *(_DWORD *)(v18 + 4) = v21;
  }
LABEL_21:
  v29 = htt_htc_pkt_alloc(v3);
  if ( v29 )
  {
    *(_QWORD *)v29 = 0;
    *(_QWORD *)(v29 + 32) = dp_htt_h2t_send_complete_free_netbuf;
    v38 = v29;
    *(_QWORD *)(v29 + 48) = *(_QWORD *)(v5 + 224);
    if ( (*(_BYTE *)(v5 + 68) & 4) != 0 )
      v39 = *(unsigned __int16 *)(v5 + 66);
    else
      v39 = 0;
    *(_DWORD *)(v29 + 60) = *(_DWORD *)(v5 + 112) + v39;
    v40 = *(_DWORD *)(v3 + 64);
    *(_WORD *)(v29 + 72) = 13;
    *(_DWORD *)(v29 + 88) = 0;
    *(_BYTE *)(v29 + 80) = 0;
    *(_DWORD *)(v29 + 64) = v40;
    *(_QWORD *)(v29 + 112) = v5;
    v41 = htc_send_pkt(*(_QWORD *)(v3 + 48), v29 + 16);
    if ( v41 )
    {
      v50 = v41;
      ++*(_DWORD *)(v3 + 104);
      _qdf_nbuf_free(v5);
      htt_htc_pkt_free(v3, v38);
      return v50;
    }
    else
    {
      if ( (*(_DWORD *)(v38 + 68) | 8) == 9 )
        ++*(_DWORD *)(v3 + 104);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: HTT_H2T RX_FSE_OPERATION_CFG sent to FW for pdev = %u",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "dp_htt_rx_flow_fse_operation",
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
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "dp_htt_rx_flow_fse_operation");
    _qdf_nbuf_free(v5);
    return 1;
  }
}
