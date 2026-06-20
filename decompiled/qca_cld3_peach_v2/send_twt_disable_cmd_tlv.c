__int64 __fastcall send_twt_disable_cmd_tlv(__int64 a1, unsigned int *a2)
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
  _DWORD *v13; // x22
  __int64 v14; // x19
  __int64 v15; // x1
  __int64 (__fastcall *v16)(__int64, __int64); // x8
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w8
  unsigned int v27; // w8
  __int64 v28; // x5
  unsigned int v29; // w6
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 result; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w20

  v4 = wmi_buf_alloc_fl(a1, 0x10u, "send_twt_disable_cmd_tlv", 0x74u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 47579148;
    v15 = *a2;
    v16 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3720LL);
    if ( *((_DWORD *)v16 - 1) != -2112860426 )
      __break(0x8228u);
    v17 = v16(a1, v15);
    v13[1] = v17;
    if ( *((_BYTE *)a2 + 4) == 1 )
    {
      v26 = v13[2] & 0xFFFFFFE7 | 8;
      v13[2] = v26;
      v27 = v26 & 0xFFFFFFCF | (16 * (a2[2] & 1));
      v13[2] = v27;
      v13[2] = v27 & 0xFFFFFFDF | (32 * (a2[3] & 1));
    }
    v28 = (unsigned int)v13[2];
    if ( a2[4] - 1 >= 4 )
      v29 = 0;
    else
      v29 = a2[4];
    v13[3] = v29;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: pdev id %d, flags %d reason code %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "send_twt_disable_cmd_tlv",
      v17,
      v28);
    result = wmi_unified_cmd_send_fl(
               a1,
               v14,
               0x10u,
               0x3E002u,
               "send_twt_disable_cmd_tlv",
               0x91u,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37);
    if ( (_DWORD)result )
    {
      v47 = result;
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send WMI_TWT_DISABLE_CMDID",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "send_twt_disable_cmd_tlv");
      wmi_buf_free();
      return v47;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to allocate memory",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_twt_disable_cmd_tlv");
    return 16;
  }
  return result;
}
