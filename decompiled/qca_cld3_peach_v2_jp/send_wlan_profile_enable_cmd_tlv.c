__int64 __fastcall send_wlan_profile_enable_cmd_tlv(__int64 a1, __int64 a2)
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
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v4 = wmi_buf_alloc_fl(a1, 0xCu, "send_wlan_profile_enable_cmd_tlv", 0x2F56u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 8847368;
    v13[1] = *(_DWORD *)(a2 + 4);
    v13[2] = *(_DWORD *)(a2 + 8);
    qdf_mtrace(49, 100, 0x804u, 0xFFu, 0);
    v23 = wmi_unified_cmd_send_fl(
            a1,
            v14,
            0xCu,
            0x10004u,
            "send_wlan_profile_enable_cmd_tlv",
            0x2F69u,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22);
    if ( v23 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send PROFILE_ENABLE_PROFILE_ID_CMDID",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "send_wlan_profile_enable_cmd_tlv");
      wmi_buf_free();
    }
  }
  else
  {
    v23 = 2;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_WLAN_PROFILE_ENABLE_PROFILE_ID_CMDID",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_wlan_profile_enable_cmd_tlv");
  }
  return v23;
}
