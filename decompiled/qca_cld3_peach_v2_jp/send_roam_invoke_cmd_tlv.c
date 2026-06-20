__int64 __fastcall send_roam_invoke_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  int v4; // w22
  __int64 v5; // x0
  __int64 v6; // x23
  __int64 v7; // x19
  int v8; // w9
  int v9; // w8
  int v10; // w9
  bool v11; // zf
  int v12; // w9
  int v13; // w10
  int v14; // w9
  int v15; // w10
  __int64 result; // x0
  int v18; // w8
  int v19; // w8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7

  v4 = *((_DWORD *)a2 + 3) + 79;
  v5 = wmi_buf_alloc_fl(a1, (unsigned __int16)v4 & 0xFFFC, "send_roam_invoke_cmd_tlv", 0x51Cu);
  if ( !v5 )
    return 2;
  v6 = *(_QWORD *)(v5 + 224);
  v7 = v5;
  *(_DWORD *)v6 = 23461924;
  v8 = *(_DWORD *)(v6 + 8);
  v9 = v8 | 2;
  *(_DWORD *)(v6 + 4) = *a2;
  *(_DWORD *)(v6 + 8) = v8 | 2;
  if ( a2[24] )
  {
    v9 = v8 | 6;
    *(_DWORD *)(v6 + 8) = v8 | 6;
  }
  v10 = *((_DWORD *)a2 + 3);
  v11 = v10 == 0;
  if ( v10 )
    v12 = 3;
  else
    v12 = 0;
  v13 = !v11;
  *(_DWORD *)(v6 + 12) = v12;
  *(_DWORD *)(v6 + 32) = v13;
  *(_QWORD *)(v6 + 16) = 0;
  *(_QWORD *)(v6 + 24) = 0x100000001LL;
  if ( (a2[25] & 1) != 0 )
  {
    v14 = 1;
    v15 = 8;
  }
  else
  {
    v14 = 2;
    if ( *(_DWORD *)(a2 + 1) != -1 || *(__int16 *)(a2 + 5) != -1 )
      goto LABEL_20;
    v15 = 24;
  }
  *(_QWORD *)(v6 + 24) = 0;
  *(_DWORD *)(v6 + 8) = v9 | v15;
  *(_DWORD *)(v6 + 12) = 4;
LABEL_20:
  *(_DWORD *)(v6 + 36) = v14;
  *(_DWORD *)(v6 + 40) = 1048580;
  *(_DWORD *)(v6 + 44) = *((_DWORD *)a2 + 2);
  *(_DWORD *)(v6 + 48) = 1245192;
  *(_DWORD *)(v6 + 52) = *(_DWORD *)(a2 + 1);
  v18 = *(unsigned __int16 *)(a2 + 5);
  *(_QWORD *)(v6 + 60) = 0x22E000400130008LL;
  *(_DWORD *)(v6 + 56) = v18;
  v19 = *((_DWORD *)a2 + 3);
  *(_DWORD *)(v6 + 68) = v19;
  *(_DWORD *)(v6 + 72) = ((_WORD)v19 + 3) & 0xFFFC | 0x110000;
  qdf_mem_copy((void *)(v6 + 76), *((const void **)a2 + 2), *((unsigned int *)a2 + 3));
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: flag:%d, MODE:%d, ap:%d, dly:%d, n_ch:%d, n_bssid:%d, ch_freq:%d, is_same_bss:%d",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "send_roam_invoke_cmd_tlv",
    *(unsigned int *)(v6 + 8),
    *(unsigned int *)(v6 + 12),
    *(unsigned int *)(v6 + 16),
    *(unsigned int *)(v6 + 20),
    *(_DWORD *)(v6 + 24),
    *(_DWORD *)(v6 + 28),
    *((_DWORD *)a2 + 2),
    a2[24]);
  wmi_mtrace(0xB00Au, *(_DWORD *)(v6 + 4), 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v7,
             (unsigned __int16)v4 & 0xFFFC,
             0xB00Au,
             "send_roam_invoke_cmd_tlv",
             0x574u,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34,
             v35);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send roam invoke command",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "send_roam_invoke_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
