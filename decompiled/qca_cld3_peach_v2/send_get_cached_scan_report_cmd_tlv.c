__int64 __fastcall send_get_cached_scan_report_cmd_tlv(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  v2 = wmi_buf_alloc_fl(a1, 4u, "send_get_cached_scan_report_cmd_tlv", 0x5B02u);
  if ( v2 )
  {
    v3 = v2;
    **(_DWORD **)(v2 + 224) = 82575360;
    qdf_mtrace(49, 100, 0xEA9u, 0xFFu, 0);
    v12 = wmi_unified_cmd_send_fl(
            a1,
            v3,
            4u,
            0x1D029u,
            "send_get_cached_scan_report_cmd_tlv",
            0x5B0Du,
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11);
    if ( v12 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send get cached scan report %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "send_get_cached_scan_report_cmd_tlv",
        v12);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v12;
}
