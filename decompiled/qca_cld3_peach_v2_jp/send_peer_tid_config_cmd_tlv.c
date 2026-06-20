__int64 __fastcall send_peer_tid_config_cmd_tlv(__int64 a1, unsigned __int8 *a2, _DWORD *a3)
{
  __int64 v6; // x0
  _DWORD *v7; // x8
  __int64 v8; // x21
  int v9; // w3
  int v10; // w9
  int v11; // w9
  int v12; // w9
  int v13; // w9
  int v14; // w9
  int v15; // w10
  unsigned int v16; // w9
  int v17; // w9
  int v18; // w9
  int v19; // w9
  int v20; // w9
  int v21; // w9
  int v22; // w10
  int v23; // w9
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w22
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x4
  __int64 v42; // x5
  __int64 v43; // x6
  __int64 v44; // x7

  v6 = wmi_buf_alloc_fl(a1, 0x38u, "send_peer_tid_config_cmd_tlv", 0x6EBu);
  if ( v6 )
  {
    v7 = *(_DWORD **)(v6 + 224);
    v8 = v6;
    *v7 = 48431156;
    v9 = *a3;
    v7[1] = *a3;
    v7[2] = *(_DWORD *)a2;
    v7[3] = *((unsigned __int16 *)a2 + 2);
    v7[4] = a3[1];
    v10 = a3[2];
    if ( v10 == 1 )
      v11 = 1;
    else
      v11 = 2 * (v10 == 2);
    v7[5] = v11;
    v12 = a3[3];
    if ( v12 == 1 )
      v13 = 1;
    else
      v13 = 2 * (v12 == 2);
    v7[6] = v13;
    v14 = a3[4];
    v15 = 0;
    if ( (unsigned int)(v14 - 1) >= 4 )
      v14 = 0;
    v7[7] = v14;
    v7[8] = a3[5];
    v16 = a3[6] - 1;
    if ( v16 <= 2 )
      v15 = dword_9E7018[v16];
    v7[9] = v15;
    v7[10] = a3[7] & 7;
    v17 = a3[8];
    if ( v17 == 1 )
      v18 = 1;
    else
      v18 = 2 * (v17 == 2);
    v7[11] = v18;
    v19 = a3[9];
    if ( v19 == 1 )
      v20 = 1;
    else
      v20 = (v19 == 2) << 10;
    v7[12] = v20;
    v21 = a3[10];
    if ( v21 == 2 )
      v22 = 7;
    else
      v22 = 0;
    if ( v21 == 1 )
      v23 = 1;
    else
      v23 = v22;
    v7[13] = v23;
    qdf_mtrace(49, 100, 0x319u, v9, 0);
    v32 = wmi_unified_cmd_send_fl(
            a1,
            v8,
            0x38u,
            0x6019u,
            "send_peer_tid_config_cmd_tlv",
            0x709u,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31);
    if ( v32 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send WMI_PEER_TID_CONFIGURATIONS_CMDID",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "send_peer_tid_config_cmd_tlv");
      wmi_buf_free();
    }
    if ( a2 )
    {
      v41 = *a2;
      v42 = a2[1];
      v43 = a2[2];
      v44 = a2[5];
    }
    else
    {
      v43 = 0;
      v41 = 0;
      v42 = 0;
      v44 = 0;
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: peer macaddr %02x:%02x:%02x:**:**:%02x vdev_id %d and tid_num %d",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "send_peer_tid_config_cmd_tlv",
      v41,
      v42,
      v43,
      v44,
      *a3,
      a3[1]);
  }
  else
  {
    return 2;
  }
  return v32;
}
