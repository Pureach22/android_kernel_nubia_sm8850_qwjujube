__int64 __fastcall dp_rx_tm_enqueue_pkt(
        unsigned __int8 *a1,
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
  __int64 v10; // x20
  unsigned int v12; // w21
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  int v16; // w9
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x19
  __int64 v26; // x8
  unsigned __int64 v27; // x23
  int v28; // w22
  unsigned int v29; // w8
  __int64 v30; // x21
  __int64 v31; // x9
  __int64 v32; // x10
  __int64 v33; // x24
  __int64 v34; // x1
  unsigned int v35; // w21
  __int64 v36; // x11
  __int64 v37; // x8
  unsigned __int64 v38; // x8
  unsigned int v39; // w6
  unsigned int v40; // w9
  __int64 v42; // x21

  v10 = a2;
  v12 = ((*(_DWORD *)(a2 + 72) >> 18) & 0xFu) % *a1;
  v13 = qdf_trace_msg(
          0x45u,
          8u,
          "%s: ring_num %d, selected thread %u",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "dp_rx_tm_select_thread");
  v25 = *(_QWORD *)(*((_QWORD *)a1 + 3) + 8LL * v12);
  v26 = *(_QWORD *)(v25 + 696);
  if ( !v26 )
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s: tm_handle_cmn is null!",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "dp_rx_tm_thread_enqueue");
    return 0;
  }
  v27 = *(_QWORD *)(v10 + 72);
  if ( (((unsigned int)v27 >> 18) & 0xF) >= 8 )
  {
    qdf_trace_msg(0x45u, 1u, "%s: incorrect ring %u", v17, v18, v19, v20, v21, v22, v23, v24, "dp_rx_tm_thread_enqueue");
    return 0;
  }
  v28 = BYTE3(v27);
  if ( (unsigned __int8)*(_DWORD *)(v26 + 32) )
  {
    if ( v10 )
    {
      do
      {
        v42 = *(_QWORD *)v10;
        v13 = _qdf_nbuf_free(v10);
        v10 = v42;
      }
      while ( v42 );
    }
    v28 = 0;
    *(_DWORD *)(v25 + 548) += BYTE3(v27);
  }
  else if ( v10 )
  {
    v29 = BYTE3(v27) << 24;
    v30 = v10;
    while ( 1 )
    {
      v31 = *(_QWORD *)(v30 + 216) + *(unsigned int *)(v30 + 212);
      v32 = *(_QWORD *)(v30 + 72);
      if ( !*(_QWORD *)(v31 + 8) )
        break;
      v33 = *(_QWORD *)v30;
      *(_QWORD *)v30 = 0;
      v34 = v30;
      *(_QWORD *)(v30 + 72) = v32 & 0xFFFFFFFF00FFFFFFLL | 0x1000000;
      v35 = v29;
      v28 += *(unsigned __int16 *)(v31 + 6);
      v13 = skb_queue_tail(v25 + 440, v34);
      v16 = -16777216;
      v29 = v35 - 0x1000000;
      v30 = v33;
      if ( !v33 )
        goto LABEL_14;
    }
    v36 = v29;
    v37 = *(_QWORD *)v30;
    *(_QWORD *)(v30 + 72) = v32 & 0xFFFFFFFF00FFFFFFLL | v36;
    if ( v37 )
    {
      *(_QWORD *)(v31 + 8) = v37;
      qdf_trace_msg(
        0x45u,
        8u,
        "%s: appended next_ptr_list %pK to nbuf %pK ext list %pK",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "dp_rx_tm_thread_enqueue",
        *(_QWORD *)v10,
        v10,
        *(_QWORD *)(*(_QWORD *)(v10 + 216) + *(unsigned int *)(v10 + 212) + 8LL));
    }
    *(_QWORD *)v30 = 0;
    v13 = skb_queue_tail(v25 + 440, v30);
  }
LABEL_14:
  v38 = (v27 >> 18) & 0xF;
  if ( v38 < 8 )
  {
    v39 = *(_DWORD *)(v25 + 456);
    *(_DWORD *)(v25 + 4 * v38 + 472) += v28;
    v40 = *(_DWORD *)(v25 + 524);
    *(_DWORD *)(v25 + 504) += v28;
    if ( v39 > v40 )
      *(_DWORD *)(v25 + 524) = v39;
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: enqueue packet thread %pK wait queue %pK qlen %u",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "dp_rx_tm_thread_enqueue",
      v25,
      v25 + 1136);
    *(_QWORD *)(v25 + 424) |= 2uLL;
    _wake_up(v25 + 1136, 1, 1, 0);
    return 0;
  }
  __break(0x5512u);
  if ( !v16 )
    JUMPOUT(0x7DC5EC);
  return dp_rx_tm_gro_flush_ind(v13, v14, v15);
}
