__int64 __fastcall wma_set_tsf_auto_report(
        __int64 *a1,
        unsigned int a2,
        int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 result; // x0
  __int64 v15; // x19
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _DWORD *v27; // x23
  int v28; // w5
  __int64 v29; // x20
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w19
  __int64 v39; // [xsp+8h] [xbp-38h]

  if ( (unsigned int)(a3 - 13) < 0xFFFFFFFE )
    return 16;
  v39 = v13;
  v15 = *a1;
  if ( (unsigned int)_wmi_validate_handle(*a1, (__int64)"wma_set_tsf_auto_report", a5, a6, a7, a8, a9, a10, a11, a12) )
    return 4;
  v18 = wmi_buf_alloc_fl(v15, 0x14u, "wma_set_tsf_auto_report", 0x221u);
  if ( !v18 )
    return 2;
  v27 = *(_DWORD **)(v18 + 224);
  if ( (a4 & 1) != 0 )
    v28 = 5;
  else
    v28 = 6;
  v29 = v18;
  v27[1] = a2;
  v27[2] = v28;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev_id %u tsf_action %d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "wma_set_tsf_auto_report",
    a2,
    v12,
    v39);
  *v27 = 25821200;
  result = wmi_unified_cmd_send_fl(
             v15,
             v29,
             0x14u,
             0x5012u,
             "wma_set_tsf_auto_report",
             0x234u,
             v30,
             v31,
             v32,
             v33,
             v34,
             v35,
             v36,
             v37);
  if ( (_DWORD)result )
  {
    v38 = result;
    wmi_buf_free();
    return v38;
  }
  return result;
}
