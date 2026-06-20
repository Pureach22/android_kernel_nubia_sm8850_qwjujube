__int64 __fastcall hdd_cleanup_conn_info(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x0
  __int64 result; // x0

  qdf_trace_msg(
    0x33u,
    8u,
    "%s: cleanup he operation info",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "hdd_cleanup_he_operation_info");
  v18 = *(_QWORD *)(a1 + 1520);
  if ( v18 )
  {
    _qdf_mem_free(v18);
    *(_QWORD *)(a1 + 1520) = 0;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: cleanup previous ap bcn ie",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "hdd_cleanup_prev_ap_bcn_ie");
  result = *(_QWORD *)(a1 + 968);
  if ( result )
  {
    result = _qdf_mem_free(result);
    *(_QWORD *)(a1 + 968) = 0;
    *(_DWORD *)(a1 + 960) = 0;
  }
  return result;
}
