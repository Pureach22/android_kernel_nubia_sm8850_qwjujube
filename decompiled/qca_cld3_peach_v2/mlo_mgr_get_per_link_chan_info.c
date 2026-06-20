__int64 __fastcall mlo_mgr_get_per_link_chan_info(__int64 a1, __int64 a2, void *a3)
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

  v4 = a2;
  ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(a1 + 1360), a2);
  if ( ap_link_by_link_id )
  {
    qdf_mem_copy(a3, *(const void **)(ap_link_by_link_id + 32), 0x28u);
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
      "mlo_mgr_get_per_link_chan_info",
      v4);
    return 4294967274LL;
  }
}
