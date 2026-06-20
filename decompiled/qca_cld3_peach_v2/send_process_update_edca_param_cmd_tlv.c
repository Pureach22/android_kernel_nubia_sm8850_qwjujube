__int64 __fastcall send_process_update_edca_param_cmd_tlv(__int64 a1, unsigned __int8 a2, char a3, _DWORD *a4)
{
  __int64 v8; // x0
  _DWORD *v9; // x8
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  v8 = wmi_buf_alloc_fl(a1, 0x7Cu, "send_process_update_edca_param_cmd_tlv", 0x179Bu);
  if ( !v8 )
    return 2;
  v9 = *(_DWORD **)(v8 + 224);
  v10 = v8;
  v9[2] = 13041688;
  *v9 = 13041784;
  v9[1] = a2;
  v9[30] = a3 & 1;
  v9[3] = a4[2];
  v9[4] = a4[3];
  v9[5] = a4[1];
  v9[6] = a4[4];
  v9[7] = *a4;
  v9[8] = a4[5];
  v9[9] = 13041688;
  v9[10] = a4[8];
  v9[11] = a4[9];
  v9[12] = a4[7];
  v9[13] = a4[10];
  v9[14] = a4[6];
  v9[15] = a4[11];
  v9[16] = 13041688;
  v9[17] = a4[14];
  v9[18] = a4[15];
  v9[19] = a4[13];
  v9[20] = a4[16];
  v9[21] = a4[12];
  v9[22] = a4[17];
  v9[23] = 13041688;
  v9[24] = a4[20];
  v9[25] = a4[21];
  v9[26] = a4[19];
  v9[27] = a4[22];
  v9[28] = a4[18];
  v9[29] = a4[23];
  qdf_mtrace(49, 100, 0x28Du, a2, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v10,
             0x7Cu,
             0x500Du,
             "send_process_update_edca_param_cmd_tlv",
             0x17BCu,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18);
  if ( (_DWORD)result )
  {
    wmi_buf_free();
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to set WMM Parameters",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "send_process_update_edca_param_cmd_tlv");
    return 16;
  }
  return result;
}
