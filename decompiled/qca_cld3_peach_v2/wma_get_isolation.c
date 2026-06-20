__int64 __fastcall wma_get_isolation(
        __int64 *a1,
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
  __int64 v18; // x20
  __int64 result; // x0
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  qdf_trace_msg(0x36u, 8u, "%s: get isolation", a2, a3, a4, a5, a6, a7, a8, a9, "wma_get_isolation");
  if ( (unsigned int)_wma_validate_handle(a1, "wma_get_isolation") )
    return 4;
  v18 = *a1;
  if ( (unsigned int)_wmi_validate_handle(*a1, (__int64)"wma_get_isolation", v10, v11, v12, v13, v14, v15, v16, v17) )
    return 4;
  v20 = wmi_buf_alloc_fl(v18, 4u, "wma_get_isolation", 0x400u);
  if ( v20 )
  {
    **(_DWORD **)(v20 + 224) = 37224448;
    result = wmi_unified_cmd_send_fl(
               v18,
               v20,
               4u,
               0x29005u,
               "wma_get_isolation",
               0x40Fu,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to get isolation request from fw",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "wma_get_isolation");
      wmi_buf_free();
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(0x36u, 2u, "%s: wmi_buf_alloc failed", v21, v22, v23, v24, v25, v26, v27, v28, "wma_get_isolation");
    return 2;
  }
  return result;
}
