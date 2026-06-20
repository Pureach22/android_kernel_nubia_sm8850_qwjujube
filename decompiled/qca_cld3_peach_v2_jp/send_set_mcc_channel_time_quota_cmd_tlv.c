__int64 __fastcall send_set_mcc_channel_time_quota_cmd_tlv(
        __int64 a1,
        unsigned int a2,
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
  unsigned int v15; // w23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  __int64 v26; // x0
  __int64 v27; // x25
  __int64 v28; // x20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w19
  unsigned int v46; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v47; // [xsp+4h] [xbp-Ch]
  __int64 v48; // [xsp+8h] [xbp-8h]

  v15 = 100 - a3;
  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: freq1:%dMHz, Quota1:%dms, freq2:%dMHz, Quota2:%dms",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "send_set_mcc_channel_time_quota_cmd_tlv",
    a2,
    a3,
    a4,
    100 - a3);
  if ( a3 - 81 > 0xFFFFFFC2 )
  {
    v26 = wmi_buf_alloc_fl(a1, 0x1Cu, "send_set_mcc_channel_time_quota_cmd_tlv", 0xC6u);
    if ( v26 )
    {
      v27 = *(_QWORD *)(v26 + 224);
      v28 = v26;
      *(_QWORD *)v27 = 0x200D00004LL;
      *(_DWORD *)(v27 + 8) = 1114128;
      v46 = a2;
      v47 = a3;
      qdf_mem_copy((void *)(v27 + 12), &v46, 8u);
      v46 = a4;
      v47 = v15;
      qdf_mem_copy((void *)(v27 + 20), &v46, 8u);
      wmi_mtrace(0x21002u, 0xFFu, 0);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v28,
                 0x1Cu,
                 0x21002u,
                 "send_set_mcc_channel_time_quota_cmd_tlv",
                 0xE3u,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36);
      if ( (_DWORD)result )
      {
        v45 = result;
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send MCC Channel Time Quota command",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "send_set_mcc_channel_time_quota_cmd_tlv");
        wmi_buf_free();
        result = v45;
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
      "%s: Invalid time quota for Chan #1=%dms. Min: %dms, Max: %dms",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "send_set_mcc_channel_time_quota_cmd_tlv",
      a3,
      20,
      80);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
