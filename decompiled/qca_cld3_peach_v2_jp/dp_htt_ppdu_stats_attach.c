__int64 __fastcall dp_htt_ppdu_stats_attach(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w19

  v1 = *(_QWORD *)(a1 + 95560);
  v2 = _qdf_mem_malloc(0x800u, "dp_htt_ppdu_stats_attach", 853);
  *(_QWORD *)(v1 + 39256) = v2;
  if ( v2 )
  {
    return 0;
  }
  else
  {
    v11 = 2;
    qdf_trace_msg(0x45u, 2u, "%s: ppdu_tlv_buf alloc fail", v3, v4, v5, v6, v7, v8, v9, v10, "dp_htt_ppdu_stats_attach");
  }
  return v11;
}
