__int64 __fastcall send_twt_add_dialog_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x8
  int v14; // w9
  unsigned int v15; // w9
  unsigned int v16; // w9
  unsigned int v17; // w9
  unsigned int v18; // w9
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w20

  v4 = wmi_buf_alloc_fl(a1, 0x58u, "send_twt_add_dialog_cmd_tlv", 0xB4u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    *v13 = 47644756;
    v13[1] = *(_DWORD *)a2;
    v13[2] = *(_DWORD *)(a2 + 4);
    v13[3] = *(unsigned __int16 *)(a2 + 8);
    v13[4] = *(_DWORD *)(a2 + 12);
    v13[5] = *(_DWORD *)(a2 + 16);
    v13[6] = *(_DWORD *)(a2 + 20);
    v13[7] = *(_DWORD *)(a2 + 32);
    v13[8] = *(_DWORD *)(a2 + 44);
    v13[12] = *(_DWORD *)(a2 + 24);
    v13[13] = *(_DWORD *)(a2 + 28);
    v13[14] = *(_DWORD *)(a2 + 36);
    v13[15] = *(_DWORD *)(a2 + 40);
    v13[16] = *(_QWORD *)(a2 + 56);
    v13[17] = *(_DWORD *)(a2 + 60);
    v13[18] = *(_DWORD *)(a2 + 64);
    v13[19] = *(_DWORD *)(a2 + 68);
    v13[20] = *(_DWORD *)(a2 + 72);
    v14 = v13[9];
    v13[21] = *(_DWORD *)(a2 + 76);
    v13[9] = v14 & 0xFFFFFF00;
    v15 = *(unsigned __int8 *)(a2 + 48) | v14 & 0xFFFFFE00;
    v13[9] = v15;
    v16 = v15 & 0xFFFFFCFF | ((*(_DWORD *)(a2 + 52) & 1) << 8);
    v13[9] = v16;
    v17 = v16 & 0xFFFFF9FF | (((*(_DWORD *)(a2 + 52) >> 1) & 1) << 9);
    v13[9] = v17;
    v18 = v17 & 0xFFFFF3FF | (((*(_DWORD *)(a2 + 52) >> 2) & 1) << 10);
    v13[9] = v18;
    v13[9] = v18 & 0xFFFFF7FF | (((*(_DWORD *)(a2 + 52) >> 3) & 1) << 11);
    result = wmi_unified_cmd_send_fl(
               a1,
               v4,
               0x58u,
               0x3E003u,
               "send_twt_add_dialog_cmd_tlv",
               0xDBu,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12);
    if ( (_DWORD)result )
    {
      v28 = result;
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send WMI_TWT_ADD_DIALOG_CMDID",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "send_twt_add_dialog_cmd_tlv");
      wmi_buf_free();
      return v28;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to allocate memory",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_twt_add_dialog_cmd_tlv");
    return 16;
  }
  return result;
}
