__int64 __fastcall send_vdev_set_param_cmd_tlv(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w21
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _DWORD *v22; // x23
  __int64 v23; // x19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  unsigned int v33; // w20

  v10 = a2[1];
  if ( v10 )
  {
    v13 = wmi_buf_alloc_fl(a1, 0x10u, "send_vdev_set_param_cmd_tlv", 0xD72u);
    if ( v13 )
    {
      v22 = *(_DWORD **)(v13 + 224);
      v23 = v13;
      *v22 = 6225932;
      v22[1] = *a2;
      v22[2] = v10;
      v22[3] = a2[2];
      qdf_trace_msg(0x31u, 8u, "Set vdev %d param 0x%x to %u", v14, v15, v16, v17, v18, v19, v20, v21);
      qdf_mtrace(49, 100, 0x288u, v22[1], 0);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v23,
                 0x10u,
                 0x5008u,
                 "send_vdev_set_param_cmd_tlv",
                 0xD80u,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31);
      if ( (_DWORD)result )
      {
        v33 = result;
        wmi_buf_free();
        return v33;
      }
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Vdev param %d not available",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "send_vdev_set_param_cmd_tlv",
      0);
    return 4;
  }
  return result;
}
