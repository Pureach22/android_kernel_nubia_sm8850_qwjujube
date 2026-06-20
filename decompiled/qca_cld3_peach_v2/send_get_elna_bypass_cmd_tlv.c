__int64 __fastcall send_get_elna_bypass_cmd_tlv(__int64 a1, unsigned __int8 *a2)
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

  v4 = wmi_buf_alloc_fl(a1, 8u, "send_get_elna_bypass_cmd_tlv", 0x57u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 54001668;
    v13[1] = *a2;
    wmi_mtrace(0x1D01Cu, *a2, 0);
    v23 = wmi_unified_cmd_send_fl(
            a1,
            v14,
            8u,
            0x1D01Cu,
            "send_get_elna_bypass_cmd_tlv",
            0x65u,
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
        "%s: Failed to send set param command ret = %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "send_get_elna_bypass_cmd_tlv",
        v23);
      wmi_buf_free();
    }
  }
  else
  {
    v23 = 2;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to allocate wmi buffer",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_get_elna_bypass_cmd_tlv");
  }
  return v23;
}
