__int64 __fastcall wma_del_ts_req(
        _QWORD *a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w8
  bool v21; // cf
  unsigned __int64 v22; // x9
  unsigned int v23; // w8
  __int64 v24; // x2
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  if ( (wma_is_vdev_valid(a2[8], a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
  {
    v20 = a2[9];
    v21 = v20 >= 5;
    v22 = 0x200010100uLL >> (8 * (unsigned __int8)v20);
    if ( v20 == 5 )
      v23 = 2;
    else
      v23 = 3;
    if ( v21 )
      v24 = v23;
    else
      v24 = (unsigned int)v22;
    if ( (unsigned int)wmi_unified_del_ts_cmd(*a1, a2[8], v24) )
      qdf_trace_msg(
        0x36u,
        1u,
        "%s: Failed to send vdev DELTS command",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "wma_del_ts_req");
    if ( a2[73] == 1 )
      wma_set_ric_req(a1, a2, 0);
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev id:%d is not active ",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_del_ts_req",
      a2[8]);
  }
  return _qdf_mem_free((__int64)a2);
}
