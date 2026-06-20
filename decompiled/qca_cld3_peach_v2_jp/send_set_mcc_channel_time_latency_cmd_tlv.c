__int64 __fastcall send_set_mcc_channel_time_latency_cmd_tlv(
        __int64 a1,
        int a2,
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
  __int64 result; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w20
  _DWORD v35[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 - 1 > 0x1C )
  {
    v15 = wmi_buf_alloc_fl(a1, 0x14u, "send_set_mcc_channel_time_latency_cmd_tlv", 0x78u);
    if ( v15 )
    {
      v16 = *(_QWORD *)(v15 + 224);
      v17 = v15;
      *(_QWORD *)v16 = 0x100D10004LL;
      *(_DWORD *)(v16 + 8) = 1114120;
      v35[0] = a2;
      v35[1] = a3;
      qdf_mem_copy((void *)(v16 + 12), v35, 8u);
      wmi_mtrace(0x21003u, 0xFFu, 0);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v17,
                 0x14u,
                 0x21003u,
                 "send_set_mcc_channel_time_latency_cmd_tlv",
                 0x8Eu,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25);
      if ( (_DWORD)result )
      {
        v34 = result;
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send MCC Channel Time Latency command",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "send_set_mcc_channel_time_latency_cmd_tlv");
        wmi_buf_free();
        result = v34;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid time latency for Channel #1 = %dms Minimum is 30ms (or 0 to use default value by firmware)",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "send_set_mcc_channel_time_latency_cmd_tlv",
      a3);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
