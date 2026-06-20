__int64 __fastcall get_sar_limit_cmd_tlv(
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
  __int64 v10; // x0
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  qdf_trace_msg(0x31u, 8u, "%s: Enter", a2, a3, a4, a5, a6, a7, a8, a9, "get_sar_limit_cmd_tlv");
  v10 = wmi_buf_alloc_fl(a1, 8u, "get_sar_limit_cmd_tlv", 0x5E6u);
  if ( v10 )
  {
    v11 = v10;
    **(_QWORD **)(v10 + 224) = 46399492;
    wmi_mtrace(0x29007u, 0xFFu, 0);
    v20 = wmi_unified_cmd_send_fl(
            a1,
            v11,
            8u,
            0x29007u,
            "get_sar_limit_cmd_tlv",
            0x5F6u,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19);
    if ( v20 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send get SAR limit cmd: %d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "get_sar_limit_cmd_tlv",
        v20);
      wmi_buf_free();
    }
    qdf_trace_msg(0x31u, 8u, "%s: Exit", v21, v22, v23, v24, v25, v26, v27, v28, "get_sar_limit_cmd_tlv");
  }
  else
  {
    return 2;
  }
  return v20;
}
