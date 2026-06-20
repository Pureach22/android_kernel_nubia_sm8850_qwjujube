__int64 __fastcall target_if_direct_buf_rx_get_ring_params(
        __int64 a1,
        _DWORD *a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v25; // x8

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 8u);
    if ( !comp_private_obj )
    {
      qdf_trace_msg(
        0x5Bu,
        2u,
        "%s: dir buf rx object is null",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "target_if_direct_buf_rx_get_ring_params");
      return 16;
    }
    if ( a3 <= 3u && a4 < 2u )
    {
      v25 = *(_QWORD *)(comp_private_obj + 8) + 112LL * a3 + 56LL * a4;
      *a2 = **(_DWORD **)(v25 + 24);
      a2[1] = *(_DWORD *)(*(_QWORD *)(v25 + 24) + 64LL);
      return 0;
    }
    qdf_trace_msg(
      0x5Bu,
      2u,
      "%s: invalid params, mod id %d, srng id %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "target_if_direct_buf_rx_get_ring_params");
  }
  else
  {
    qdf_trace_msg(
      0x5Bu,
      2u,
      "%s: pdev context passed is null",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "target_if_direct_buf_rx_get_ring_params");
  }
  return 4;
}
