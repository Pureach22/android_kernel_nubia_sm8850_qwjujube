__int64 __fastcall send_start_oem_data_cmd_tlv(__int64 a1, unsigned int a2, const void *a3)
{
  __int64 v6; // x0
  __int64 v7; // x19
  int *v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w20

  v6 = wmi_buf_alloc_fl(a1, a2 + 4, "send_start_oem_data_cmd_tlv", 0x1FE6u);
  if ( !v6 )
    return 16;
  v7 = v6;
  v8 = *(int **)(v6 + 224);
  *v8 = (unsigned __int16)a2 | 0x110000;
  qdf_mem_copy(v8 + 1, a3, a2);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Sending OEM Data Request to target, data len %d",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "send_start_oem_data_cmd_tlv",
    a2);
  qdf_mtrace(49, 100, 0x1381u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v7,
             a2 + 4,
             0x27001u,
             "send_start_oem_data_cmd_tlv",
             0x1FF6u,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24);
  if ( (_DWORD)result )
  {
    v34 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_OEM_REQ_CMDID",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "send_start_oem_data_cmd_tlv");
    wmi_buf_free();
    return v34;
  }
  return result;
}
