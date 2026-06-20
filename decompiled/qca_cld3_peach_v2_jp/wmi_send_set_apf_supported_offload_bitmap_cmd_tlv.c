__int64 __fastcall wmi_send_set_apf_supported_offload_bitmap_cmd_tlv(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v12; // w22
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _DWORD *v23; // x8
  unsigned int v24; // w20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  v12 = a2;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Sending WMI_BPF_SET_SUPPORTED_OFFLOAD_BITMAP_CMDID(%u, %u)",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wmi_send_set_apf_supported_offload_bitmap_cmd_tlv",
    a2,
    a3);
  v14 = wmi_buf_alloc_fl(a1, 0xCu, "wmi_send_set_apf_supported_offload_bitmap_cmd_tlv", 0xF8u);
  if ( v14 )
  {
    v23 = *(_DWORD **)(v14 + 224);
    *v23 = 84279304;
    v23[1] = v12;
    v23[2] = a3;
    v24 = wmi_unified_cmd_send_fl(
            a1,
            v14,
            0xCu,
            0x36009u,
            "wmi_send_set_apf_supported_offload_bitmap_cmd_tlv",
            0x10Au,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22);
    if ( v24 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send WMI_BPF_SET_SUPPORTED_OFFLOAD_BITMAP_CMDID:%d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "wmi_send_set_apf_supported_offload_bitmap_cmd_tlv",
        v24);
      wmi_buf_free();
    }
  }
  else
  {
    v24 = 2;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi_buf_alloc failed",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wmi_send_set_apf_supported_offload_bitmap_cmd_tlv");
  }
  return v24;
}
