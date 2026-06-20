__int64 __fastcall send_twt_del_dialog_cmd_tlv(__int64 a1, __int64 a2)
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
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w20

  v4 = wmi_buf_alloc_fl(a1, 0x1Cu, "send_twt_del_dialog_cmd_tlv", 0xFBu);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    *v13 = 47710232;
    v13[1] = *(_DWORD *)a2;
    v13[2] = *(_DWORD *)(a2 + 4);
    v13[3] = *(unsigned __int16 *)(a2 + 8);
    v13[4] = *(_DWORD *)(a2 + 12);
    result = wmi_unified_cmd_send_fl(
               a1,
               v4,
               0x1Cu,
               0x3E004u,
               "send_twt_del_dialog_cmd_tlv",
               0x10Fu,
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
      v23 = result;
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send WMI_TWT_DEL_DIALOG_CMDID",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "send_twt_del_dialog_cmd_tlv");
      wmi_buf_free();
      return v23;
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
      "send_twt_del_dialog_cmd_tlv");
    return 16;
  }
  return result;
}
