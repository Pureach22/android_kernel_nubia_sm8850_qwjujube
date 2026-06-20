__int64 __fastcall send_lro_config_cmd_tlv(__int64 a1, __int64 a2)
{
  unsigned int v3; // w21
  __int64 v5; // x0
  _DWORD *v6; // x23
  __int64 v7; // x19
  int v8; // w8
  unsigned int v9; // w8
  _DWORD *v10; // x8
  unsigned int v11; // w0
  __int64 v12; // x4
  __int64 v13; // x5
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  unsigned int v31; // w20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  v3 = *(unsigned __int8 *)(a2 + 72);
  v5 = wmi_buf_alloc_fl(a1, 0x50u, "send_lro_config_cmd_tlv", 0x1703u);
  if ( !v5 )
    return 16;
  v6 = *(_DWORD **)(v5 + 224);
  v7 = v5;
  *v6 = 27918412;
  v8 = v6[2];
  v6[1] = *(_DWORD *)a2;
  v6[2] = v8 & 0xFFFFFE00;
  v9 = v8 & 0xFFFC0000 | *(_DWORD *)(a2 + 4) & 0x1FF;
  v6[2] = v9;
  v6[2] = *(_DWORD *)(a2 + 4) & 0x3FE00 | v9;
  v6[3] = *(_DWORD *)(a2 + 8);
  v6[4] = *(_DWORD *)(a2 + 12);
  v6[5] = *(_DWORD *)(a2 + 16);
  v6[6] = *(_DWORD *)(a2 + 20);
  v6[7] = *(_DWORD *)(a2 + 24);
  v6[8] = *(_DWORD *)(a2 + 28);
  v6[9] = *(_DWORD *)(a2 + 32);
  v6[10] = *(_DWORD *)(a2 + 36);
  v6[11] = *(_DWORD *)(a2 + 40);
  v6[12] = *(_DWORD *)(a2 + 44);
  v6[13] = *(_DWORD *)(a2 + 48);
  v6[14] = *(_DWORD *)(a2 + 52);
  v6[15] = *(_DWORD *)(a2 + 56);
  v6[16] = *(_DWORD *)(a2 + 60);
  v6[17] = *(_DWORD *)(a2 + 64);
  v6[18] = *(_DWORD *)(a2 + 68);
  v10 = *(_DWORD **)(*(_QWORD *)(a1 + 728) + 3664LL);
  if ( *(v10 - 1) != -2112860426 )
    __break(0x8228u);
  v11 = ((__int64 (__fastcall *)(__int64, _QWORD))v10)(a1, v3);
  v12 = (unsigned int)v6[1];
  v13 = (unsigned int)v6[2];
  v6[19] = v11;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: WMI_LRO_CONFIG: lro_enable %d, tcp_flag 0x%x, pdev_id: %d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "send_lro_config_cmd_tlv",
    v12,
    v13,
    v11);
  qdf_mtrace(49, 100, 0xE90u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v7,
             0x50u,
             0x1D010u,
             "send_lro_config_cmd_tlv",
             0x173Cu,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29);
  if ( (_DWORD)result )
  {
    v31 = result;
    wmi_buf_free();
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_LRO_CONFIG_CMDID",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "send_lro_config_cmd_tlv");
    return v31;
  }
  return result;
}
