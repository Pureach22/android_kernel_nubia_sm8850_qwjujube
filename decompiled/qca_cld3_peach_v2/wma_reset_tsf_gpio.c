__int64 __fastcall wma_reset_tsf_gpio(__int64 *a1, unsigned int a2)
{
  __int64 v4; // x19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  _DWORD *v14; // x23
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w20

  v4 = wmi_buf_alloc_fl(*a1, 0x14u, "wma_reset_tsf_gpio", 0x1D2u);
  result = 2;
  if ( v4 )
  {
    v14 = *(_DWORD **)(v4 + 224);
    v14[1] = a2;
    v14[2] = 2;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: vdev_id %u, TSF_TSTAMP_CAPTURE_RESET",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wma_reset_tsf_gpio",
      a2);
    *v14 = 25821200;
    result = wmi_unified_cmd_send_fl(
               *a1,
               v4,
               0x14u,
               0x5012u,
               "wma_reset_tsf_gpio",
               0x1E3u,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22);
    if ( (_DWORD)result )
    {
      v23 = result;
      wmi_buf_free();
      return v23;
    }
  }
  return result;
}
