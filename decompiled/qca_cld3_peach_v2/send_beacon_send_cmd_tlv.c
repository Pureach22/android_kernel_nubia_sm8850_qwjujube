__int64 __fastcall send_beacon_send_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  int v14; // w9
  unsigned int v15; // w20
  _DWORD *v16; // x8
  int v17; // w1
  __int64 v18; // x10
  int v19; // w11
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x9
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

  v4 = wmi_buf_alloc_fl(a1, 0x20u, "send_beacon_send_cmd_tlv", 0x4Eu);
  if ( v4 )
  {
    v13 = v4;
    if ( a2[24] == 1 )
    {
      if ( a2[25] )
        v14 = 3;
      else
        v14 = 1;
    }
    else
    {
      v14 = 0;
    }
    v16 = *(_DWORD **)(v4 + 224);
    *v16 = 10354716;
    v17 = *a2;
    v16[1] = v17;
    v18 = *((_QWORD *)a2 + 1);
    if ( (*(_BYTE *)(v18 + 68) & 4) != 0 )
      v19 = *(unsigned __int16 *)(v18 + 66);
    else
      v19 = 0;
    v16[2] = *(_DWORD *)(v18 + 112) + v19;
    v16[4] = *((unsigned __int16 *)a2 + 8);
    v16[5] = v14;
    v20 = *((_QWORD *)a2 + 1);
    v21 = 80;
    if ( (*(_BYTE *)(v20 + 68) & 4) == 0 )
      v21 = 40;
    v22 = *(_QWORD *)(v20 + v21);
    v16[3] = v22;
    v16[7] = BYTE4(v22) & 0x1F;
    v16[6] = *((_DWORD *)a2 + 5);
    wmi_mtrace(0x7002u, v17, 0);
    v15 = wmi_unified_cmd_send_fl(
            a1,
            v13,
            0x20u,
            0x7002u,
            "send_beacon_send_cmd_tlv",
            0x6Du,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30);
    if ( v15 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send bcn: %d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "send_beacon_send_cmd_tlv",
        v15);
      wmi_buf_free();
    }
  }
  else
  {
    v15 = 2;
    qdf_trace_msg(0x31u, 2u, "%s: wmi_buf_alloc failed", v5, v6, v7, v8, v9, v10, v11, v12, "send_beacon_send_cmd_tlv");
  }
  return v15;
}
