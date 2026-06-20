__int64 __fastcall wmi_send_set_active_apf_mode_cmd_tlv(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v14; // w23
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _DWORD *v25; // x8
  unsigned int v26; // w20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  v14 = a2;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Sending WMI_BPF_SET_VDEV_ACTIVE_MODE_CMDID(%u, %d, %d)",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "wmi_send_set_active_apf_mode_cmd_tlv",
    a2,
    a3,
    a4);
  v16 = wmi_buf_alloc_fl(a1, 0x10u, "wmi_send_set_active_apf_mode_cmd_tlv", 0x2Cu);
  if ( v16 )
  {
    v25 = *(_DWORD **)(v16 + 224);
    *v25 = 40566796;
    v25[1] = v14;
    v25[2] = a4;
    v25[3] = a3;
    v26 = wmi_unified_cmd_send_fl(
            a1,
            v16,
            0x10u,
            0x36005u,
            "wmi_send_set_active_apf_mode_cmd_tlv",
            0x3Du,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24);
    if ( v26 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send WMI_BPF_SET_VDEV_ACTIVE_MODE_CMDID:%d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "wmi_send_set_active_apf_mode_cmd_tlv",
        v26);
      wmi_buf_free();
    }
  }
  else
  {
    v26 = 2;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi_buf_alloc failed",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wmi_send_set_active_apf_mode_cmd_tlv");
  }
  return v26;
}
