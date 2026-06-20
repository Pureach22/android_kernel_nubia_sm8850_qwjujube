__int64 __fastcall send_wow_sta_ra_filter_cmd_tlv(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        unsigned __int16 a4)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x24
  __int64 v18; // x19
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  v8 = wmi_buf_alloc_fl(a1, 0x2Cu, "send_wow_sta_ra_filter_cmd_tlv", 0x46Cu);
  if ( !v8 )
    return 2;
  v17 = *(_QWORD *)(v8 + 224);
  *(_DWORD *)v17 = 11730956;
  *(_DWORD *)(v17 + 4) = a2;
  *(_DWORD *)(v17 + 8) = a3;
  v18 = v8;
  *(_QWORD *)(v17 + 20) = 0x12000000120000LL;
  *(_QWORD *)(v17 + 28) = 0x10000000120000LL;
  *(_QWORD *)(v17 + 12) = 0x12000000000006LL;
  *(_DWORD *)(v17 + 36) = 1048580;
  *(_DWORD *)(v17 + 40) = a4;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: send RA rate limit [%d] to fw vdev = %d",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "send_wow_sta_ra_filter_cmd_tlv");
  wmi_mtrace(0x13001u, *(_DWORD *)(v17 + 4), 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v18,
             0x2Cu,
             0x13001u,
             "send_wow_sta_ra_filter_cmd_tlv",
             0x49Cu,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send RA rate limit to fw %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "send_wow_sta_ra_filter_cmd_tlv",
      (unsigned int)result);
    wmi_buf_free();
    return 16;
  }
  return result;
}
