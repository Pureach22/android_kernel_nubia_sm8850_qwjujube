__int64 __fastcall send_set_thermal_mgmt_cmd_tlv(
        __int64 a1,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w20
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _DWORD *v22; // x8
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
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  v10 = *((_DWORD *)a2 + 2);
  if ( v10 >= 4 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid thermal_action code %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "send_set_thermal_mgmt_cmd_tlv",
      v10);
    return 16;
  }
  v13 = wmi_buf_alloc_fl(a1, 0x1Cu, "send_set_thermal_mgmt_cmd_tlv", 0x16D1u);
  if ( !v13 )
    return 16;
  v22 = *(_DWORD **)(v13 + 224);
  v23 = v13;
  *v22 = 15990808;
  v22[1] = *a2;
  v22[2] = a2[1];
  v22[3] = *((unsigned __int8 *)a2 + 4);
  v22[4] = v10;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: TM Sending thermal mgmt cmd: low temp %d, upper temp %d, enabled %d action %d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "send_set_thermal_mgmt_cmd_tlv");
  qdf_mtrace(49, 100, 0xE8Au, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v23,
             0x1Cu,
             0x1D00Au,
             "send_set_thermal_mgmt_cmd_tlv",
             0x16E7u,
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
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send thermal mgmt command",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "send_set_thermal_mgmt_cmd_tlv");
    return v33;
  }
  return result;
}
