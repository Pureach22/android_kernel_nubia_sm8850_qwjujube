__int64 __fastcall epping_tx_dup_pkt(__int64 *a1, int a2, __int64 a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x20
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  __int64 result; // x0
  int v27; // w9
  int v28; // w22
  __int64 v29; // x21
  int v30; // w23
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x8
  __int64 v40; // x10
  __int64 v41; // x9

  v6 = epping_alloc_cookie(*a1);
  if ( !v6 )
    return qdf_trace_msg(
             0x33u,
             1u,
             "%s: epping_alloc_cookie returns no resource\n",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "epping_tx_dup_pkt");
  v15 = v6;
  v16 = skb_copy(a3, 2080);
  if ( v16 )
  {
    *(_QWORD *)(v15 + 16) = v15;
    *(_QWORD *)(v15 + 32) = *(_QWORD *)(a3 + 224);
    if ( (*(_BYTE *)(v16 + 68) & 4) != 0 )
      v25 = *(unsigned __int16 *)(v16 + 66);
    else
      v25 = 0;
    v27 = *(_DWORD *)(v16 + 112);
    *(_WORD *)(v15 + 56) = 0;
    v28 = 0;
    *(_DWORD *)(v15 + 72) = 0;
    *(_BYTE *)(v15 + 64) = 0;
    *(_DWORD *)(v15 + 44) = v27 + v25;
    *(_DWORD *)(v15 + 48) = a2;
    *(_QWORD *)(v15 + 96) = v16;
    if ( (*(_BYTE *)(v16 + 68) & 4) != 0 )
      v28 = *(unsigned __int16 *)(v16 + 66);
    v29 = v16;
    v30 = *(_DWORD *)(v16 + 112);
    result = htc_send_pkt(*(_QWORD *)(*a1 + 56), v15);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x33u,
        1u,
        "%s: htc_send_pkt failed, ret = %d\n",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "epping_tx_dup_pkt",
        (unsigned int)result);
      epping_free_cookie(*a1, v15);
      return _qdf_nbuf_free(v29);
    }
    else
    {
      v39 = a1[24];
      v40 = a1[20] + v30 + v28;
      v41 = a1[18] + 1;
      a1[18] = v41;
      a1[20] = v40;
      if ( v39 | v41 )
      {
        if ( !((v39 + v41) % 0xC350uLL) )
          return epping_log_stats(a1, (__int64)"epping_tx_dup_pkt", v31, v32, v33, v34, v35, v36, v37, v38);
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      1u,
      "%s: qdf_nbuf_copy returns no resource\n",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "epping_tx_dup_pkt");
    return epping_free_cookie(*a1, v15);
  }
  return result;
}
