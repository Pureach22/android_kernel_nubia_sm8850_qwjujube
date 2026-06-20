__int64 __fastcall send_beacon_tmpl_send_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  int v2; // w22
  int v5; // w20
  int v6; // w23
  __int64 v7; // x0
  __int64 v8; // x24
  __int64 v9; // x20
  int v10; // w9
  unsigned int v11; // w8
  int v12; // w9
  int v13; // w9
  __int64 v14; // x0
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

  v2 = *((_DWORD *)a2 + 4);
  v5 = bcn_tmpl_mlo_param_size(a2);
  v6 = v2 + v5 + bcn_tmpl_ml_info_size(a2);
  v7 = wmi_buf_alloc_fl(a1, v6 + 72, "send_beacon_tmpl_send_cmd_tlv", 0xF3Bu);
  if ( !v7 )
    return 2;
  v8 = *(_QWORD *)(v7 + 224);
  v9 = v7;
  *(_DWORD *)v8 = 6750260;
  v10 = *(_DWORD *)(v8 + 48);
  *(_DWORD *)(v8 + 4) = *a2;
  *(_DWORD *)(v8 + 8) = *((_DWORD *)a2 + 1);
  *(_DWORD *)(v8 + 28) = *((_DWORD *)a2 + 2);
  *(_DWORD *)(v8 + 16) = *((_DWORD *)a2 + 5);
  *(_DWORD *)(v8 + 20) = *((_DWORD *)a2 + 6);
  *(_DWORD *)(v8 + 32) = *((_DWORD *)a2 + 7);
  *(_DWORD *)(v8 + 44) = *((_DWORD *)a2 + 8);
  *(_DWORD *)(v8 + 52) = *((_DWORD *)a2 + 9);
  *(_DWORD *)(v8 + 12) = *((_DWORD *)a2 + 3);
  v11 = v10 & 0xFFFFFFFE;
  v12 = *((_DWORD *)a2 + 10);
  *(_DWORD *)(v8 + 48) = v11;
  *(_DWORD *)(v8 + 24) = v12;
  v13 = a2[44];
  *(_QWORD *)(v8 + 56) = 6881288;
  *(_DWORD *)(v8 + 64) = 0;
  *(_DWORD *)(v8 + 48) = v11 | v13;
  *(_DWORD *)(v8 + 68) = *((unsigned __int16 *)a2 + 8) | 0x110000;
  qdf_mem_copy((void *)(v8 + 72), *((const void **)a2 + 6), *((unsigned int *)a2 + 3));
  v14 = bcn_tmpl_add_ml_partner_links(v8 + 72 + ((*((unsigned int *)a2 + 3) + 3LL) & 0x1FFFFFFFCLL), a2);
  bcn_tmpl_add_ml_info(v14, a2);
  qdf_mtrace(49, 100, 0x383u, *(_DWORD *)(v8 + 4), 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v9,
             v6 + 72,
             0x7003u,
             "send_beacon_tmpl_send_cmd_tlv",
             0xF6Du,
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
      "%s: Failed to send bcn tmpl: %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "send_beacon_tmpl_send_cmd_tlv",
      (unsigned int)result);
    wmi_buf_free();
    return 0;
  }
  return result;
}
