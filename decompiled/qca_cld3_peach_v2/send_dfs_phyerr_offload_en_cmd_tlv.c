__int64 __fastcall send_dfs_phyerr_offload_en_cmd_tlv(__int64 a1, unsigned int a2)
{
  __int64 v4; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x22
  _DWORD *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v4 = wmi_buf_alloc_fl(a1, 8u, "send_dfs_phyerr_offload_en_cmd_tlv", 0x3133u);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: pdev_id=%d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_dfs_phyerr_offload_en_cmd_tlv",
    a2);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  *v13 = 38797316;
  v14 = *(_DWORD **)(*(_QWORD *)(a1 + 728) + 3680LL);
  if ( *(v14 - 1) != -2112860426 )
    __break(0x8228u);
  v13[1] = ((__int64 (__fastcall *)(__int64, _QWORD))v14)(a1, a2);
  qdf_mtrace(49, 100, 0x505u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v4,
             8u,
             0xA005u,
             "send_dfs_phyerr_offload_en_cmd_tlv",
             0x3147u,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send cmd to fw, ret=%d, pdev_id=%d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "send_dfs_phyerr_offload_en_cmd_tlv",
      (unsigned int)result,
      a2);
    wmi_buf_free();
    return 16;
  }
  return result;
}
