__int64 __fastcall send_unit_test_cmd_tlv(__int64 a1, _DWORD *a2)
{
  int v4; // w24
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD *v14; // x25
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned __int64 v32; // x26
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 result; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  v4 = 4 * a2[2] + 24;
  v5 = wmi_buf_alloc_fl(a1, (unsigned __int16)v4 & 0xFFFC, "send_unit_test_cmd_tlv", 0x30BDu);
  if ( !v5 )
    return 2;
  v14 = *(_DWORD **)(v5 + 224);
  *v14 = 21430288;
  v15 = v5;
  v14[1] = *a2;
  v14[2] = a2[1];
  v14[3] = a2[2];
  v14[4] = a2[3];
  v14[5] = (4 * (a2[2] & 0x3FFF)) | 0x100000;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: VDEV ID: %d MODULE ID: %d TOKEN: %d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "send_unit_test_cmd_tlv");
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: %d num of args = ",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "send_unit_test_cmd_tlv",
    (unsigned int)a2[2]);
  if ( a2[2] )
  {
    v32 = 0;
    do
    {
      v14[v32 + 6] = a2[v32 + 4];
      qdf_trace_msg(0x31u, 8u, "%s: %d,", v24, v25, v26, v27, v28, v29, v30, v31, "send_unit_test_cmd_tlv");
      if ( v32 > 0x62 )
        break;
      ++v32;
    }
    while ( v32 < (unsigned int)a2[2] );
  }
  qdf_mtrace(49, 100, 0xF83u, v14[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v15,
             (unsigned __int16)v4 & 0xFFFC,
             0x1F003u,
             "send_unit_test_cmd_tlv",
             0x30D7u,
             v33,
             v34,
             v35,
             v36,
             v37,
             v38,
             v39,
             v40);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send unit test command",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "send_unit_test_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
