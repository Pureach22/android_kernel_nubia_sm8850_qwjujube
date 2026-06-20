__int64 __fastcall send_addba_clearresponse_cmd_tlv(__int64 a1, __int64 a2, unsigned __int8 *a3)
{
  unsigned int v6; // w23
  __int64 v7; // x0
  _DWORD *v8; // x8
  __int64 v9; // x19
  int v10; // w3
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  v6 = 16;
  v7 = wmi_buf_alloc_fl(a1, 0x10u, "send_addba_clearresponse_cmd_tlv", 0x32B8u);
  if ( v7 )
  {
    v8 = *(_DWORD **)(v7 + 224);
    v9 = v7;
    *v8 = 10485772;
    v10 = *a3;
    v8[1] = v10;
    v8[2] = *(_DWORD *)a2;
    v8[3] = *(unsigned __int16 *)(a2 + 4);
    qdf_mtrace(49, 100, 0x401u, v10, 0);
    v19 = wmi_unified_cmd_send_fl(
            a1,
            v9,
            0x10u,
            0x8001u,
            "send_addba_clearresponse_cmd_tlv",
            0x32C7u,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18);
    if ( v19 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send cmd to fw, ret=%d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "send_addba_clearresponse_cmd_tlv",
        v19);
      wmi_buf_free();
    }
    else
    {
      return 0;
    }
  }
  return v6;
}
