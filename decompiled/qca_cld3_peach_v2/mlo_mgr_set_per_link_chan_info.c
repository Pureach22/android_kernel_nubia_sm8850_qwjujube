__int64 __fastcall mlo_mgr_set_per_link_chan_info(__int64 a1, __int64 a2, int a3)
{
  unsigned int v4; // w19
  __int64 ap_link_by_link_id; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8

  v4 = a2;
  ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(a1 + 1360), a2);
  if ( ap_link_by_link_id )
  {
    v14 = ap_link_by_link_id;
    *(_DWORD *)(*(_QWORD *)(v14 + 32) + 24LL) = a3;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: ml_link_info null for link_id: %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "mlo_mgr_set_per_link_chan_info",
      v4);
    return 4294967274LL;
  }
}
