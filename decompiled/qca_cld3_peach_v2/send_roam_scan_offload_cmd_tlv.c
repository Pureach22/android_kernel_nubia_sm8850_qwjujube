__int64 __fastcall send_roam_scan_offload_cmd_tlv(__int64 a1, int a2, int a3)
{
  __int64 v6; // x0
  _DWORD *v7; // x8
  __int64 v8; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w20

  v6 = wmi_buf_alloc_fl(a1, 0xCu, "send_roam_scan_offload_cmd_tlv", 0x16C0u);
  if ( !v6 )
    return 2;
  v7 = *(_DWORD **)(v6 + 224);
  v8 = v6;
  *v7 = 17432584;
  v7[1] = a3;
  v7[2] = a2;
  wmi_mtrace(0xB007u, 0xFFu, 0);
  v17 = wmi_unified_cmd_send_fl(
          a1,
          v8,
          0xCu,
          0xB007u,
          "send_roam_scan_offload_cmd_tlv",
          0x16CFu,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16);
  if ( v17 )
  {
    v26 = v17;
    wmi_buf_free();
    return v26;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      4u,
      "%s: WMI --> WMI_ROAM_SCAN_CMD",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "send_roam_scan_offload_cmd_tlv");
    return 0;
  }
}
