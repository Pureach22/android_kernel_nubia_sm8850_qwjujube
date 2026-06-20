__int64 __fastcall send_reject_ap_list_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  __int64 v2; // x24
  unsigned int v3; // w20
  unsigned int v5; // w8
  __int64 v6; // x22
  int v7; // w23
  unsigned int v8; // w21
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  _DWORD *v19; // x8
  _DWORD *v20; // x23
  unsigned __int8 *v21; // x24
  int v22; // w8
  int v23; // w8
  __int64 v24; // x8
  int v25; // w8
  unsigned int v26; // w8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w19
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7

  v2 = *((_QWORD *)a2 + 1);
  v3 = *a2;
  v5 = ((unsigned int)(unsigned __int16)wmi_get_max_msg_len(a1) - 8) / 0x60;
  if ( v5 >= v3 )
    LOBYTE(v5) = v3;
  v6 = (unsigned __int8)v5;
  v7 = 3 * (unsigned __int8)v5;
  v8 = (32 * (v7 & 0x3FF)) | 8;
  v9 = wmi_buf_alloc_fl(a1, v8, "send_reject_ap_list_cmd_tlv", 0x4FFu);
  if ( v9 )
  {
    v18 = v9;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: num of reject BSSIDs %d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "send_reject_ap_list_cmd_tlv",
      (unsigned int)v6);
    v19 = *(_DWORD **)(v18 + 224);
    *v19 = 52887552;
    v19[1] = (32 * v7) | 0x120000;
    if ( (_DWORD)v6 )
    {
      v20 = v19 + 2;
      v21 = (unsigned __int8 *)(v2 + 56);
      do
      {
        *v20 = 52953180;
        v20[2] = *((_DWORD *)v21 - 14);
        v20[3] = *((unsigned __int16 *)v21 - 26);
        v24 = *((unsigned int *)v21 + 1);
        if ( (unsigned int)v24 > 4 )
          v25 = 4;
        else
          v25 = dword_B343D4[v24];
        v20[1] = v25;
        v20[5] = *((_DWORD *)v21 + 3);
        v20[4] = *((_DWORD *)v21 + 2);
        v26 = *((_DWORD *)v21 + 4) - 1;
        if ( v26 <= 0x10 )
          v22 = dword_B343E8[v26];
        else
          v22 = 0;
        v20[6] = v22;
        v20[9] = *((_DWORD *)v21 + 8);
        v20[8] = *((_QWORD *)v21 + 3);
        v20[7] = *((_DWORD *)v21 + 5);
        v20[11] = *((_DWORD *)v21 - 12);
        v20[12] = *((unsigned __int16 *)v21 - 22);
        v23 = *v21;
        v20[23] = v23;
        qdf_mem_copy(v20 + 13, v21 - 40, (unsigned int)(2 * v23));
        --v6;
        v21 += 96;
        v20 += 24;
      }
      while ( v6 );
    }
    wmi_mtrace(0x4038u, 0xFFu, 0);
    v35 = wmi_unified_cmd_send_fl(
            a1,
            v18,
            v8,
            0x4038u,
            "send_reject_ap_list_cmd_tlv",
            0x529u,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34);
    if ( v35 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: wmi_unified_cmd_send WMI_PDEV_DSM_FILTER_CMDID returned Error %d",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "send_reject_ap_list_cmd_tlv",
        v35);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v35;
}
