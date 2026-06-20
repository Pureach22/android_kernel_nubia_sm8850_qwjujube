__int64 __fastcall send_set_sta_uapsd_auto_trig_cmd_tlv(__int64 a1, int *a2)
{
  int v4; // w22
  __int64 v5; // x0
  _DWORD *v6; // x8
  __int64 v7; // x19
  int v8; // w3
  int v9; // w9
  _DWORD *v10; // x10
  unsigned __int64 v11; // x9
  _DWORD *v12; // x11
  int v13; // w13
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  v4 = 24 * a2[3];
  v5 = wmi_buf_alloc_fl(a1, v4 + 24, "send_set_sta_uapsd_auto_trig_cmd_tlv", 0x1671u);
  if ( v5 )
  {
    v6 = *(_DWORD **)(v5 + 224);
    v7 = v5;
    *v6 = 7929872;
    v8 = *a2;
    v6[1] = *a2;
    v6[4] = a2[3];
    v6[2] = a2[1];
    v9 = *((unsigned __int16 *)a2 + 4);
    v6[5] = v4 & 0xFFF8 | 0x120000;
    v6[3] = v9;
    if ( a2[3] )
    {
      v10 = *((_DWORD **)a2 + 2);
      v11 = 0;
      v12 = v6 + 6;
      do
      {
        *v12 = 7995412;
        ++v11;
        v12[1] = *v10;
        v12[2] = v10[1];
        v12[3] = v10[2];
        v12[4] = v10[3];
        v13 = v10[4];
        v10 += 5;
        v12[5] = v13;
        v12 += 6;
      }
      while ( v11 < (unsigned int)a2[3] );
      v8 = v6[1];
    }
    qdf_mtrace(49, 100, 0xE04u, v8, 0);
    v22 = wmi_unified_cmd_send_fl(
            a1,
            v7,
            v4 + 24,
            0x1C004u,
            "send_set_sta_uapsd_auto_trig_cmd_tlv",
            0x169Cu,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21);
    if ( v22 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send set uapsd param ret = %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "send_set_sta_uapsd_auto_trig_cmd_tlv",
        v22);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v22;
}
