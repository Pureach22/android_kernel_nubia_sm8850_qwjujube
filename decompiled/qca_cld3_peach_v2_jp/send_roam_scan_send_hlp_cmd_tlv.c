__int64 __fastcall send_roam_scan_send_hlp_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v4; // w22
  __int64 v5; // x0
  _DWORD *v6; // x23
  __int64 v7; // x19
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

  v4 = (*((_DWORD *)a2 + 1) + 3) & 0xFFFFFFFC;
  v5 = wmi_buf_alloc_fl(a1, v4 + 24, "send_roam_scan_send_hlp_cmd_tlv", 0x17E3u);
  if ( !v5 )
    return 2;
  v6 = *(_DWORD **)(v5 + 224);
  v7 = v5;
  *v6 = 43974672;
  v6[2] = *a2;
  v6[3] = *((_DWORD *)a2 + 1);
  v6[4] = 1;
  v6[5] = (((unsigned __int16)(*((_DWORD *)a2 + 1) - 1) | 3) + 1) & 0xFFFC | 0x110000;
  qdf_mem_copy(v6 + 6, a2 + 8, *((unsigned int *)a2 + 1));
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: send FILS HLP pkt vdev %d len %d",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "send_roam_scan_send_hlp_cmd_tlv",
    (unsigned int)v6[2],
    (unsigned int)v6[3]);
  wmi_mtrace(0x402Fu, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v7,
             v4 + 24,
             0x402Fu,
             "send_roam_scan_send_hlp_cmd_tlv",
             0x17FEu,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send FILS HLP pkt cmd",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "send_roam_scan_send_hlp_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
