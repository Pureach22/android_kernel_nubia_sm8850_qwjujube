__int64 __fastcall send_sar_limit_cmd_tlv(__int64 a1, __int64 a2)
{
  unsigned int v3; // w20
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD *v14; // x24
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  _DWORD *v25; // x26
  unsigned int v26; // w23
  _DWORD *v27; // x27
  int v28; // w8
  int v29; // w9
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
  __int64 v48; // [xsp+0h] [xbp-10h]
  __int64 v49; // [xsp+8h] [xbp-8h]

  v3 = 24 * *(_DWORD *)(a2 + 4) + 20;
  v5 = wmi_buf_alloc_fl(a1, v3, "send_sar_limit_cmd_tlv", 0x59Eu);
  if ( !v5 )
    return 2;
  v14 = *(_DWORD **)(v5 + 224);
  v15 = v5;
  *v14 = 38666252;
  v14[1] = *(_DWORD *)a2;
  v14[3] = *(_DWORD *)(a2 + 8);
  v14[2] = *(_DWORD *)(a2 + 4);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: no of sar rows = %d, len = %d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "send_sar_limit_cmd_tlv");
  v24 = v14[2];
  v14[4] = (8 * ((3 * (unsigned __int16)*(_DWORD *)(a2 + 4)) & 0x1FFF)) | 0x120000;
  if ( v24 && *(_DWORD *)(a2 + 4) )
  {
    v25 = *(_DWORD **)(a2 + 16);
    v26 = 0;
    v27 = v14 + 5;
    do
    {
      *v27 = 38731796;
      v27[1] = *v25;
      v27[2] = v25[1];
      v27[3] = v25[2];
      v28 = v25[3];
      v27[4] = v28;
      v29 = v25[4];
      v27[5] = v29;
      LODWORD(v49) = v29;
      LODWORD(v48) = v28;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: row %d, band_id = %d, chain_id = %d, mod_id = %d, limit_value = %d, validity_bitmap = %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "send_sar_limit_cmd_tlv",
        v26++,
        v48,
        v49);
      v25 += 5;
      v27 += 6;
    }
    while ( v26 < *(_DWORD *)(a2 + 4) );
  }
  wmi_mtrace(0x29006u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v15,
             v3,
             0x29006u,
             "send_sar_limit_cmd_tlv",
             0x5D1u,
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
      "%s: Failed to send WMI_SAR_LIMITS_CMDID",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "send_sar_limit_cmd_tlv");
    wmi_buf_free();
    return v47;
  }
  return result;
}
