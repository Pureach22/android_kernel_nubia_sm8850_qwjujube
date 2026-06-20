__int64 __fastcall htt_soc_attach_target(__int64 a1)
{
  _DWORD *v2; // x0
  __int64 v3; // x20
  __int64 v4; // x2
  __int64 result; // x0
  int v6; // w8
  int v7; // w9
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _DWORD *v16; // x21
  __int64 v17; // x0
  __int64 v18; // x21
  int v19; // w8
  int v20; // w8
  unsigned int v21; // w0
  unsigned int v22; // w22

  v2 = (_DWORD *)_qdf_nbuf_alloc(*(_QWORD *)(a1 + 56), 12, 8, 4, 1, "dp_htt_htc_msg_alloc", 87);
  if ( !v2 )
    return 2;
  v3 = (__int64)v2;
  if ( v2[29] )
  {
    v4 = 4;
  }
  else
  {
    v7 = v2[52];
    v6 = v2[53];
    if ( (unsigned int)(v6 - v7) > 3 )
      goto LABEL_8;
    v4 = (unsigned int)(v7 - v6 + 4);
  }
  if ( (unsigned int)pskb_expand_head(v2, 0, v4, 2080) )
  {
    dev_kfree_skb_any_reason(v3, 1);
    goto LABEL_20;
  }
LABEL_8:
  if ( !skb_put(v3, 4) )
  {
LABEL_20:
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s: Failed to expand head for HTT_H2T_MSG_TYPE_VERSION_REQ msg",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "dp_htt_h2t_add_tcl_metadata_ver_v1");
    return 16;
  }
  v16 = *(_DWORD **)(v3 + 224);
  skb_push(v3, 0);
  *v16 = 0;
  v17 = htt_htc_pkt_alloc(a1);
  if ( !v17 )
  {
    _qdf_nbuf_free(v3);
    return 16;
  }
  *(_QWORD *)v17 = 0;
  *(_QWORD *)(v17 + 32) = dp_htt_h2t_send_complete_free_netbuf;
  v18 = v17;
  *(_QWORD *)(v17 + 48) = *(_QWORD *)(v3 + 224);
  if ( (*(_BYTE *)(v3 + 68) & 4) != 0 )
    v19 = *(unsigned __int16 *)(v3 + 66);
  else
    v19 = 0;
  *(_DWORD *)(v17 + 60) = *(_DWORD *)(v3 + 112) + v19;
  v20 = *(_DWORD *)(a1 + 64);
  *(_WORD *)(v17 + 72) = 14;
  *(_DWORD *)(v17 + 88) = 0;
  *(_BYTE *)(v17 + 80) = 0;
  *(_DWORD *)(v17 + 64) = v20;
  *(_QWORD *)(v17 + 112) = v3;
  v21 = htc_send_pkt(*(_QWORD *)(a1 + 48), v17 + 16);
  if ( v21 )
  {
    v22 = v21;
    ++*(_DWORD *)(a1 + 104);
    _qdf_nbuf_free(v3);
    htt_htc_pkt_free(a1, v18);
    return v22;
  }
  else
  {
    result = 0;
    if ( (*(_DWORD *)(v18 + 68) | 8) == 9 )
      ++*(_DWORD *)(a1 + 104);
  }
  return result;
}
