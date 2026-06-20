__int64 __fastcall dp_rx_reorder_flush_frag(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x22
  __int64 v13; // x0
  __int64 v14; // x1
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w23
  __int64 v24; // x21
  __int64 v25; // x24
  _QWORD *v26; // x0
  _QWORD *v27; // x19
  __int64 result; // x0
  __int64 v29; // x19
  _QWORD *v30; // x19
  __int64 v31; // t1

  v11 = jiffies;
  if ( dp_rx_reorder_flush_frag___last_ticks - jiffies + 125 >= 0 )
  {
    if ( a1 )
      goto LABEL_3;
    return qdf_trace_msg(0x45u, 2u, "%s: NULL peer", a3, a4, a5, a6, a7, a8, a9, a10, "dp_rx_reorder_flush_frag");
  }
  qdf_trace_msg(0x45u, 5u, "%s: Flushing TID %d", a3, a4, a5, a6, a7, a8, a9, a10, "dp_rx_reorder_flush_frag", a2);
  dp_rx_reorder_flush_frag___last_ticks = v11;
  if ( !a1 )
    return qdf_trace_msg(0x45u, 2u, "%s: NULL peer", a3, a4, a5, a6, a7, a8, a9, a10, "dp_rx_reorder_flush_frag");
LABEL_3:
  v13 = dp_rx_return_head_frag_desc(a1, a2);
  if ( a2 >= 0x11 )
  {
    __break(0x5512u);
    return dp_rx_return_head_frag_desc(v13, v14);
  }
  else
  {
    v23 = a2;
    v24 = a1 + 176 + 120LL * a2;
    v25 = *(_QWORD *)(v24 + 48);
    if ( v25 )
    {
      v26 = *(_QWORD **)v25;
      if ( *(_QWORD *)v25 )
      {
        do
        {
          v27 = (_QWORD *)*v26;
          _qdf_nbuf_free((__int64)v26);
          v26 = v27;
        }
        while ( v27 );
      }
      *(_QWORD *)v25 = 0;
      *(_QWORD *)(v25 + 8) = 0;
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Cleanup self peer %pK and TID %u",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "dp_rx_defrag_cleanup",
        a1,
        a2);
    }
    v29 = a1 + 176 + 120LL * v23;
    v31 = *(_QWORD *)(v29 + 24);
    v30 = (_QWORD *)(v29 + 24);
    result = v31;
    if ( v31 )
      result = _qdf_mem_free(result);
    *(_DWORD *)(v24 + 104) = 0;
    *v30 = 0;
    v30[1] = 0;
    v30[2] = 0;
  }
  return result;
}
