__int64 __fastcall wma_set_sw_retry_by_qos(
        __int64 *a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _DWORD *v19; // x8
  __int64 v20; // x19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0

  v10 = wmi_buf_alloc_fl(*a1, 0x14u, "wma_set_sw_retry_by_qos", 0x14FBu);
  if ( !v10 )
    return 2;
  v19 = *(_DWORD **)(v10 + 224);
  v20 = v10;
  *v19 = 48496656;
  v19[1] = a2;
  v19[2] = a4;
  v19[3] = a3;
  v19[4] = a5;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: ac_type: %d re_type: %d threshold: %d vid: %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "wma_set_sw_retry_by_qos",
    a4,
    a3,
    a5);
  result = wmi_unified_cmd_send_fl(
             *a1,
             v20,
             0x14u,
             0x5020u,
             "wma_set_sw_retry_by_qos",
             0x1513u,
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
    wmi_buf_free();
    return 16;
  }
  return result;
}
