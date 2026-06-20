__int64 __fastcall dp_h2t_3tuple_config_send(unsigned __int8 *a1, unsigned int a2, unsigned __int8 a3)
{
  __int64 v7; // x19
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x20
  int v18; // w23
  __int64 v20; // x24
  unsigned int v21; // w23
  __int64 v22; // x2
  int v23; // w8
  int v24; // w9
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int *v33; // x24
  int v34; // w8
  unsigned int v35; // w8
  __int64 v36; // x0
  __int64 v37; // x21
  int v38; // w8
  int v39; // w8

  v7 = *(_QWORD *)(*((_QWORD *)a1 + 1) + 48LL);
  v8 = _qdf_nbuf_alloc(*(_QWORD *)(v7 + 56), 16, 8, 4, 1, "dp_htt_htc_msg_alloc", 87);
  if ( !v8 )
    return 2;
  v17 = v8;
  if ( a3 && *a1 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Both mac_id and pdev_id cannot be non zero",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_get_mac_id_for_pdev");
    v18 = 0;
  }
  else
  {
    v18 = *a1 + a3;
  }
  v20 = *((_QWORD *)a1 + 1);
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v20 + 40)) )
  {
    if ( v18 )
    {
      __break(0x5512u);
      __asm { STGP            X4, X10, [X25,#-0xA8]! }
      JUMPOUT(0x50FA20);
    }
    v21 = *(unsigned __int8 *)(*(_QWORD *)(v20 + 72) + 2LL);
    if ( *(_DWORD *)(v17 + 116) )
      goto LABEL_10;
  }
  else
  {
    v21 = v18 + 1;
    if ( *(_DWORD *)(v17 + 116) )
    {
LABEL_10:
      v22 = 8;
      goto LABEL_14;
    }
  }
  v24 = *(_DWORD *)(v17 + 208);
  v23 = *(_DWORD *)(v17 + 212);
  if ( (unsigned int)(v23 - v24) > 7 )
    goto LABEL_15;
  v22 = (unsigned int)(v24 - v23 + 8);
LABEL_14:
  if ( (unsigned int)pskb_expand_head(v17, 0, v22, 2080) )
  {
    dev_kfree_skb_any_reason(v17, 1);
    goto LABEL_30;
  }
LABEL_15:
  if ( !skb_put(v17, 8) )
  {
LABEL_30:
    qdf_trace_msg(0x3Fu, 2u, "Failed to expand head for HTT_3TUPLE_CONFIG", v25, v26, v27, v28, v29, v30, v31, v32);
    _qdf_nbuf_free(v17);
    return 16;
  }
  qdf_trace_msg(
    0x80u,
    5u,
    "%s: %pK: config_param_sent 0x%x for target_pdev %d\n -------------",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "dp_h2t_3tuple_config_send",
    *((_QWORD *)a1 + 1),
    a2,
    v21);
  v33 = *(int **)(v17 + 224);
  skb_push(v17, 0);
  v34 = 22;
  *v33 = 22;
  if ( v21 >= 0x100 )
  {
    printk(
      &unk_94DB9D,
      "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
      5508,
      "!((target_pdev_id) & ~((HTT_H2T_3_TUPLE_HASH_PDEV_ID_M) >> (HTT_H2T_3_TUPLE_HASH_PDEV_ID_S)))");
    v34 = *v33;
  }
  *v33 = v34 | (v21 << 8);
  v33[1] = 0;
  v35 = a2;
  if ( a2 >= 2 )
  {
    printk(
      &unk_94DB9D,
      "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
      5512,
      "!((tuple_mask) & ~((HTT_H2T_FLOW_ID_TOEPLITZ_FIELD_CONFIG_M) >> (HTT_H2T_FLOW_ID_TOEPLITZ_FIELD_CONFIG_S)))");
    v33[1] |= a2;
    printk(
      &unk_94DB9D,
      "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
      5513,
      "!((tuple_mask) & ~((HTT_H2T_TOEPLITZ_2_OR_4_FIELD_CONFIG_M) >> (HTT_H2T_TOEPLITZ_2_OR_4_FIELD_CONFIG_S)))");
    v35 = v33[1];
  }
  v33[1] = v35 | (2 * a2);
  v36 = htt_htc_pkt_alloc(v7);
  if ( v36 )
  {
    *(_QWORD *)v36 = 0;
    *(_QWORD *)(v36 + 32) = dp_htt_h2t_send_complete_free_netbuf;
    v37 = v36;
    *(_QWORD *)(v36 + 48) = *(_QWORD *)(v17 + 224);
    if ( (*(_BYTE *)(v17 + 68) & 4) != 0 )
      v38 = *(unsigned __int16 *)(v17 + 66);
    else
      v38 = 0;
    *(_DWORD *)(v36 + 60) = *(_DWORD *)(v17 + 112) + v38;
    v39 = *(_DWORD *)(v7 + 64);
    *(_WORD *)(v36 + 72) = 13;
    *(_DWORD *)(v36 + 88) = 0;
    *(_BYTE *)(v36 + 80) = 0;
    *(_DWORD *)(v36 + 64) = v39;
    *(_QWORD *)(v36 + 112) = v17;
    if ( (unsigned int)htc_send_pkt(*(_QWORD *)(v7 + 48), v36 + 16) || (*(_DWORD *)(v37 + 68) | 8) == 9 )
    {
      ++*(_DWORD *)(v7 + 104);
      return 0;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    _qdf_nbuf_free(v17);
    return 2;
  }
}
