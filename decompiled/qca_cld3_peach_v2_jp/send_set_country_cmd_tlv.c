__int64 __fastcall send_set_country_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v3; // w22
  __int64 v5; // x0
  _DWORD *v6; // x23
  __int64 v7; // x19
  _DWORD *v8; // x8
  unsigned int v9; // w0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w20

  v3 = a2[3];
  v5 = wmi_buf_alloc_fl(a1, 0xCu, "send_set_country_cmd_tlv", 0x4ACBu);
  if ( !v5 )
    return 2;
  v6 = *(_DWORD **)(v5 + 224);
  v7 = v5;
  *v6 = 39780360;
  v8 = *(_DWORD **)(*(_QWORD *)(a1 + 728) + 3704LL);
  if ( *(v8 - 1) != -2112860426 )
    __break(0x8228u);
  v9 = ((__int64 (__fastcall *)(__int64, _QWORD))v8)(a1, v3);
  v6[1] = v9;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: setting current country to  %s and target pdev_id = %u",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "send_set_country_cmd_tlv",
    a2,
    v9);
  qdf_mem_copy(v6 + 2, a2, 3u);
  qdf_mtrace(49, 100, 0x1D01u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v7,
             0xCu,
             0x3A001u,
             "send_set_country_cmd_tlv",
             0x4AE1u,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25);
  if ( (_DWORD)result )
  {
    v35 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_SET_CURRENT_COUNTRY_CMDID",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "send_set_country_cmd_tlv");
    wmi_buf_free();
    return v35;
  }
  return result;
}
