__int64 __fastcall hdd_nan_concurrency_update(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  context = _cds_get_context(51, (__int64)"hdd_nan_concurrency_update", a1, a2, a3, a4, a5, a6, a7, a8);
  qdf_trace_msg(0x33u, 8u, "%s: enter", v9, v10, v11, v12, v13, v14, v15, v16, "hdd_nan_concurrency_update");
  result = _wlan_hdd_validate_context(
             (__int64)context,
             (__int64)"hdd_nan_concurrency_update",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24);
  if ( !(_DWORD)result )
  {
    wlan_twt_concurrency_update(context);
    return qdf_trace_msg(0x33u, 8u, "%s: exit", v26, v27, v28, v29, v30, v31, v32, v33, "hdd_nan_concurrency_update");
  }
  return result;
}
