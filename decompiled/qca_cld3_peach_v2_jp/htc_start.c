__int64 __fastcall htc_start(__int64 *a1)
{
  __int64 v2; // x21
  __int64 v3; // x0
  __int64 v4; // x20
  _DWORD *v5; // x0
  _DWORD *v6; // x21
  __int64 v7; // x2
  int v8; // w8
  int v9; // w9
  __int64 v10; // x21
  __int64 result; // x0
  unsigned int v12; // w19

  if ( (dword_B0B4 & 8) != 0 )
    qdf_trace_msg(56, 2, "%s: htc_start Enter\n", "htc_start");
  v2 = a1[432];
  v3 = _qdf_mem_malloc(112, "build_htc_tx_ctrl_packet", 77);
  if ( v3 )
  {
    v4 = v3;
    v5 = (_DWORD *)_qdf_nbuf_alloc(v2, 264, 20, 4, 1, "build_htc_tx_ctrl_packet", 81);
    if ( v5 )
    {
      *(_QWORD *)(v4 + 96) = v5;
      v6 = v5;
      if ( v5[29] )
      {
        v7 = 12;
      }
      else
      {
        v9 = v5[52];
        v8 = v5[53];
        if ( (unsigned int)(v8 - v9) > 0xB )
          goto LABEL_10;
        v7 = (unsigned int)(v9 - v8 + 12);
      }
      if ( (unsigned int)pskb_expand_head(v5, 0, v7, 2080) )
      {
        dev_kfree_skb_any_reason(v6, 1);
LABEL_11:
        v10 = *((_QWORD *)v6 + 28);
        qdf_mem_set(v10, 0xCu, 0);
        *(_WORD *)v10 = 5;
        if ( htc_credit_flow )
        {
          if ( (dword_B0B4 & 8) != 0 )
            qdf_trace_msg(56, 2, "%s: HTC using TX credit flow control", "htc_start");
        }
        else
        {
          if ( (dword_B0B4 & 8) != 0 )
            qdf_trace_msg(56, 2, "%s: HTC will not use TX credit flow control", "htc_start");
          *(_QWORD *)v10 |= 0x200000000uLL;
        }
        if ( (unsigned int)hif_get_bus_type(*a1) == 4 || (unsigned int)hif_get_bus_type(*a1) == 5 )
        {
          hif_set_bundle_mode(*a1);
          *(_BYTE *)(v10 + 8) = 64;
        }
        *(_QWORD *)(v4 + 44) = 12;
        *(_QWORD *)(v4 + 16) = 0;
        *(_QWORD *)(v4 + 32) = v10;
        *(_WORD *)(v4 + 56) = 1;
        *(_DWORD *)(v4 + 72) = 0;
        *(_BYTE *)(v4 + 64) = 0;
        result = htc_send_pkt(a1, v4);
        if ( (dword_B0B4 & 8) != 0 )
          goto LABEL_21;
        return result;
      }
LABEL_10:
      skb_put(v6, 12);
      goto LABEL_11;
    }
    _qdf_mem_free(v4);
  }
  printk(&unk_881311, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc.c", 916, "false");
  qdf_trace_msg(56, 2, "%s: %s: allocControlTxPacket failed", "htc_start", "htc_start");
  result = 2;
  if ( (dword_B0B4 & 8) != 0 )
  {
LABEL_21:
    v12 = result;
    qdf_trace_msg(56, 2, "%s: htc_start Exit\n", "htc_start");
    return v12;
  }
  return result;
}
