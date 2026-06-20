__int64 __fastcall p2p_deinit_random_mac_vdev(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  p2p_del_all_rand_mac_vdev(*(_QWORD *)a1);
  qdf_mc_timer_destroy(a1 + 64);
  if ( *(_DWORD *)(a1 + 248) )
    qdf_trace_msg(0x33u, 2u, "%s: list length not equal to zero", v2, v3, v4, v5, v6, v7, v8, v9, "qdf_list_destroy");
  qdf_mc_timer_destroy(a1 + 280);
  if ( *(_DWORD *)(a1 + 464) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: list length not equal to zero",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "qdf_list_destroy");
  qdf_mc_timer_destroy(a1 + 496);
  if ( *(_DWORD *)(a1 + 680) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: list length not equal to zero",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "qdf_list_destroy");
  result = qdf_mc_timer_destroy(a1 + 712);
  if ( *(_DWORD *)(a1 + 896) )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: list length not equal to zero",
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34,
             "qdf_list_destroy");
  return result;
}
