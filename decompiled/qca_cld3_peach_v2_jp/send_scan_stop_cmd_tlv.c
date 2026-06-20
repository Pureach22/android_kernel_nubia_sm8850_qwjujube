__int64 __fastcall send_scan_stop_cmd_tlv(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x22
  __int64 v6; // x19
  __int64 v7; // x1
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w8
  int v18; // w3
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w20
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x18u, "send_scan_stop_cmd_tlv", 0x12CFu);
  if ( v4 )
  {
    v5 = *(_DWORD **)(v4 + 224);
    v6 = v4;
    *v5 = 5111828;
    v5[4] = a2[3];
    v5[1] = *a2;
    v5[2] = a2[1];
    v7 = (unsigned int)a2[4];
    v8 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3664LL);
    if ( *((_DWORD *)v8 - 1) != -2112860426 )
      __break(0x8228u);
    v5[5] = v8(a1, v7);
    v17 = a2[2] - 1;
    if ( v17 >= 4 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid Scan cancel req type: %d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "send_scan_stop_cmd_tlv");
      v27 = 4;
      goto LABEL_9;
    }
    v18 = v5[4];
    v5[3] = dword_A2F9A8[v17];
    qdf_mtrace(49, 100, 0x182u, v18, 0);
    v27 = wmi_unified_cmd_send_fl(
            a1,
            v6,
            0x18u,
            0x3002u,
            "send_scan_stop_cmd_tlv",
            0x12F3u,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26);
    if ( v27 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send stop scan: %d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "send_scan_stop_cmd_tlv",
        v27);
LABEL_9:
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v27;
}
