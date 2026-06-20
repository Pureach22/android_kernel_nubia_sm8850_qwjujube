__int64 __fastcall send_set_elna_bypass_cmd_tlv(__int64 a1, unsigned __int8 *a2)
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
  int v15; // w2
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  v4 = wmi_buf_alloc_fl(a1, 0xCu, "send_set_elna_bypass_cmd_tlv", 0x2Du);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 53936136;
    v13[1] = *a2;
    v15 = *((_DWORD *)a2 + 1);
    v13[2] = v15;
    wmi_mtrace(0x1D01Bu, *a2, v15);
    v24 = wmi_unified_cmd_send_fl(
            a1,
            v14,
            0xCu,
            0x1D01Bu,
            "send_set_elna_bypass_cmd_tlv",
            0x3Cu,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23);
    if ( v24 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send set param command ret = %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "send_set_elna_bypass_cmd_tlv",
        v24);
      wmi_buf_free();
    }
  }
  else
  {
    v24 = 2;
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
      "send_set_elna_bypass_cmd_tlv");
  }
  return v24;
}
