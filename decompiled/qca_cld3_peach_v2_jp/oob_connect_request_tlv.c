__int64 __fastcall oob_connect_request_tlv(__int64 a1, unsigned __int64 a2, int a3)
{
  unsigned int v6; // w23
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _DWORD *v16; // x8
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v6 = 16;
  v7 = wmi_buf_alloc_fl(a1, 0x10u, "oob_connect_request_tlv", 0xA3u);
  if ( v7 )
  {
    v16 = *(_DWORD **)(v7 + 224);
    v17 = v7;
    *v16 = 79691788;
    v16[1] = (unsigned __int8)a2;
    v16[2] = HIDWORD(a2) != 0;
    v16[3] = a3;
    qdf_trace_msg(
      0x31u,
      8u,
      "LL_LT_SAP vdev %d OOB connect req type %d duration %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15);
    v6 = wmi_unified_cmd_send_fl(
           a1,
           v17,
           0x10u,
           0x5038u,
           "oob_connect_request_tlv",
           0xB9u,
           v18,
           v19,
           v20,
           v21,
           v22,
           v23,
           v24,
           v25);
    if ( v6 )
      wmi_buf_free();
  }
  return v6;
}
