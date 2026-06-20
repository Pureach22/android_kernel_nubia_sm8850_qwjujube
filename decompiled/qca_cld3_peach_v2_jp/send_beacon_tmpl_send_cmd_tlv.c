__int64 __fastcall send_beacon_tmpl_send_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  int v2; // w23
  __int64 v5; // x0
  __int64 v6; // x24
  __int64 v7; // x19
  int v8; // w9
  unsigned int v9; // w8
  int v10; // w9
  int v11; // w9
  int v12; // w3
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  v2 = *((_DWORD *)a2 + 4);
  v5 = wmi_buf_alloc_fl(a1, v2 + 80, "send_beacon_tmpl_send_cmd_tlv", 0xF3Bu);
  if ( !v5 )
    return 2;
  v6 = *(_QWORD *)(v5 + 224);
  v7 = v5;
  *(_DWORD *)v6 = 6750260;
  v8 = *(_DWORD *)(v6 + 48);
  *(_DWORD *)(v6 + 4) = *a2;
  *(_DWORD *)(v6 + 8) = *((_DWORD *)a2 + 1);
  *(_DWORD *)(v6 + 28) = *((_DWORD *)a2 + 2);
  *(_DWORD *)(v6 + 16) = *((_DWORD *)a2 + 5);
  *(_DWORD *)(v6 + 20) = *((_DWORD *)a2 + 6);
  *(_DWORD *)(v6 + 32) = *((_DWORD *)a2 + 7);
  *(_DWORD *)(v6 + 44) = *((_DWORD *)a2 + 8);
  *(_DWORD *)(v6 + 52) = *((_DWORD *)a2 + 9);
  *(_DWORD *)(v6 + 12) = *((_DWORD *)a2 + 3);
  v9 = v8 & 0xFFFFFFFE;
  v10 = *((_DWORD *)a2 + 10);
  *(_DWORD *)(v6 + 48) = v9;
  *(_DWORD *)(v6 + 24) = v10;
  v11 = a2[44];
  *(_QWORD *)(v6 + 56) = 6881288;
  *(_DWORD *)(v6 + 64) = 0;
  *(_DWORD *)(v6 + 48) = v9 | v11;
  *(_DWORD *)(v6 + 68) = *((unsigned __int16 *)a2 + 8) | 0x110000;
  qdf_mem_copy((void *)(v6 + 72), *((const void **)a2 + 6), *((unsigned int *)a2 + 3));
  v12 = *(_DWORD *)(v6 + 4);
  *(_QWORD *)(v6 + 72 + ((*((unsigned int *)a2 + 3) + 3LL) & 0x1FFFFFFFCLL)) = 0x12000000120000LL;
  qdf_mtrace(49, 100, 0x383u, v12, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v7,
             v2 + 80,
             0x7003u,
             "send_beacon_tmpl_send_cmd_tlv",
             0xF6Du,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send bcn tmpl: %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "send_beacon_tmpl_send_cmd_tlv",
      (unsigned int)result);
    wmi_buf_free();
    return 0;
  }
  return result;
}
