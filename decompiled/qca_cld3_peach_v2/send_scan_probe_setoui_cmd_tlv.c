__int64 __fastcall send_scan_probe_setoui_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  int v4; // w22
  __int64 v5; // x0
  _DWORD *v6; // x23
  __int64 v7; // x19
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w3
  int v17; // w8
  __int64 v18; // x9
  __int64 result; // x0
  int *v20; // x8
  _DWORD *v21; // x10
  int v22; // t1
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  v4 = 8 * *((_DWORD *)a2 + 12);
  v5 = wmi_buf_alloc_fl(a1, v4 + 60, "send_scan_probe_setoui_cmd_tlv", 0x1A1Au);
  if ( !v5 )
    return 2;
  v6 = *(_DWORD **)(v5 + 224);
  v7 = v5;
  *v6 = 22872116;
  qdf_mem_set(v6 + 1, 4u, 0);
  v6[1] = (*a2 << 16) | (a2[1] << 8) | a2[2];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: wmi:oui received from hdd %08x",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "send_scan_probe_setoui_cmd_tlv");
  v16 = *((_DWORD *)a2 + 1);
  v6[2] = v16;
  v6[3] = 1;
  if ( a2[8] )
    v17 = 3;
  else
    v17 = 1;
  v6[3] = v17;
  if ( (a2[12] & 1) != 0 )
  {
    v6[4] = *((_DWORD *)a2 + 4);
    v6[5] = *((_DWORD *)a2 + 5);
    v6[6] = *((_DWORD *)a2 + 6);
    v6[7] = *((_DWORD *)a2 + 7);
    v6[8] = *((_DWORD *)a2 + 8);
    v6[9] = *((_DWORD *)a2 + 9);
    v6[10] = *((_DWORD *)a2 + 10);
    v6[11] = *((_DWORD *)a2 + 11);
    LODWORD(v18) = *((_DWORD *)a2 + 12);
    v6[3] = v17 | 4;
    v6[12] = v18;
  }
  else
  {
    LODWORD(v18) = v6[12];
  }
  v6[14] = (8 * (*((_DWORD *)a2 + 12) & 0x1FFF)) | 0x120000;
  if ( (_DWORD)v18 )
  {
    v20 = (int *)(a2 + 52);
    v18 = (unsigned int)v18;
    v21 = v6 + 16;
    do
    {
      *(v21 - 1) = 39256068;
      --v18;
      v22 = *v20++;
      *v21 = v22;
      v21 += 2;
    }
    while ( v18 );
    v16 = v6[2];
  }
  qdf_mtrace(49, 100, 0x186u, v16, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v7,
             v4 + 60,
             0x3006u,
             "send_scan_probe_setoui_cmd_tlv",
             0x1A45u,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send command WMI_SCAN_PROB_REQ_OUI_CMDID",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "send_scan_probe_setoui_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
