__int64 __fastcall send_stats_request_cmd_tlv(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  _DWORD *v7; // x23
  __int64 v8; // x19
  __int64 v9; // x1
  __int64 (__fastcall *v10)(__int64, __int64); // x8
  unsigned int v11; // w0
  unsigned int v12; // w22
  __int64 v13; // x4
  __int64 v14; // x5
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  v6 = wmi_buf_alloc_fl(a1, 0x18u, "send_stats_request_cmd_tlv", 0x2C2u);
  if ( !v6 )
    return 2;
  v7 = *(_DWORD **)(v6 + 224);
  v8 = v6;
  *v7 = 9371668;
  v7[1] = *(_DWORD *)a3;
  v7[2] = *(unsigned __int8 *)(a3 + 4);
  v9 = *(unsigned __int8 *)(a3 + 5);
  v10 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3664LL);
  if ( *((_DWORD *)v10 - 1) != -2112860426 )
    __break(0x8228u);
  v11 = v10(a1, v9);
  v7[5] = v11;
  v12 = *(unsigned __int8 *)(a3 + 10);
  v13 = (unsigned int)v7[1];
  v14 = (unsigned int)v7[2];
  v7[3] = *(_DWORD *)a2;
  v7[4] = *(unsigned __int16 *)(a2 + 4);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: STATS REQ STATS_ID:%d VDEV_ID:%d PDEV_ID:%d, is_qmi_send_support %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "send_stats_request_cmd_tlv",
    v13,
    v14,
    v11,
    v12);
  wmi_mtrace(0x16001u, v7[2], 0);
  v31 = wmi_unified_cmd_send_pm_chk(a1, v8, 0x18u, 0x16001u, v12, v23, v24, v25, v26, v27, v28, v29, v30);
  if ( v31 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send stats request to fw =%d",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "send_stats_request_cmd_tlv",
      v31);
    wmi_buf_free();
  }
  return qdf_status_from_os_return(v31);
}
