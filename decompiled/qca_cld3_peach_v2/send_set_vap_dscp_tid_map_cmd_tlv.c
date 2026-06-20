__int64 __fastcall send_set_vap_dscp_tid_map_cmd_tlv(__int64 a1, const void **a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x22
  __int64 v6; // x19
  int v7; // w4
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x10Cu, "send_set_vap_dscp_tid_map_cmd_tlv", 0x22C0u);
  if ( v4 )
  {
    v5 = *(_DWORD **)(v4 + 224);
    v6 = v4;
    qdf_mem_copy(v5 + 2, a2[1], 0x100u);
    v7 = *(unsigned __int8 *)a2;
    v5[66] = 0;
    v5[1] = v7;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Setting dscp for vap id: %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "send_set_vap_dscp_tid_map_cmd_tlv");
    qdf_mtrace(49, 100, 0x296u, v5[1], 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v6,
               0x10Cu,
               0x5016u,
               "send_set_vap_dscp_tid_map_cmd_tlv",
               0x22CEu,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23);
    if ( !(_DWORD)result )
      return result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to set dscp cmd",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "send_set_vap_dscp_tid_map_cmd_tlv");
    wmi_buf_free();
  }
  return 16;
}
