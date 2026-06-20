__int64 __fastcall send_reject_ap_list_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  __int64 v2; // x23
  unsigned int v3; // w20
  unsigned int v5; // w8
  __int64 v6; // x22
  int v7; // w24
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x20
  _DWORD *v18; // x8
  _DWORD *v19; // x8
  __int64 v20; // x9
  int v21; // w13
  int v22; // w13
  __int64 v23; // x13
  int v24; // w13
  unsigned int v25; // w13
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w19
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7

  v2 = *((_QWORD *)a2 + 1);
  v3 = *a2;
  v5 = ((unsigned int)(unsigned __int16)wmi_get_max_msg_len(a1) - 8) / 0x60;
  if ( v5 >= v3 )
    LOBYTE(v5) = v3;
  v6 = (unsigned __int8)v5;
  v7 = 3 * (unsigned __int8)v5;
  v8 = wmi_buf_alloc_fl(a1, (32 * (v7 & 0x3FF)) | 8u, "send_reject_ap_list_cmd_tlv", 0x4FFu);
  if ( v8 )
  {
    v17 = v8;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: num of reject BSSIDs %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "send_reject_ap_list_cmd_tlv",
      (unsigned int)v6);
    v18 = *(_DWORD **)(v17 + 224);
    *v18 = 52887552;
    v18[1] = (32 * v7) | 0x120000;
    if ( (_DWORD)v6 )
    {
      v19 = v18 + 2;
      v20 = v2 + 20;
      do
      {
        *v19 = 52953180;
        v19[2] = *(_DWORD *)(v20 - 20);
        v19[3] = *(unsigned __int16 *)(v20 - 16);
        v23 = *(unsigned int *)(v20 - 12);
        if ( (unsigned int)v23 > 4 )
          v24 = 4;
        else
          v24 = dword_A2EAAC[v23];
        v19[1] = v24;
        v19[5] = *(_DWORD *)(v20 - 4);
        v19[4] = *(_DWORD *)(v20 - 8);
        v25 = *(_DWORD *)v20 - 1;
        if ( v25 <= 0x10 )
          v21 = dword_A2EAC0[v25];
        else
          v21 = 0;
        v19[6] = v21;
        --v6;
        v19[9] = *(_DWORD *)(v20 + 20);
        v19[8] = *(_QWORD *)(v20 + 12);
        v22 = *(_DWORD *)(v20 + 4);
        v20 += 48;
        v19[7] = v22;
        v19 += 24;
      }
      while ( v6 );
    }
    wmi_mtrace(0x4038u, 0xFFu, 0);
    v34 = wmi_unified_cmd_send_fl(
            a1,
            v17,
            (32 * (v7 & 0x3FF)) | 8u,
            0x4038u,
            "send_reject_ap_list_cmd_tlv",
            0x529u,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33);
    if ( v34 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: wmi_unified_cmd_send WMI_PDEV_DSM_FILTER_CMDID returned Error %d",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "send_reject_ap_list_cmd_tlv",
        v34);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v34;
}
