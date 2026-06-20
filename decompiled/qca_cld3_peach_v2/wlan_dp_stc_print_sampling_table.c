void __fastcall wlan_dp_stc_print_sampling_table(__int64 a1)
{
  __int64 v1; // x28
  __int64 v2; // x26
  __int64 v3; // x21
  int v4; // w20
  int v5; // w27
  _WORD *v6; // x20
  _WORD *v7; // x27
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // [xsp+1Ch] [xbp-224h]
  unsigned int v17; // [xsp+20h] [xbp-220h]
  unsigned int v18; // [xsp+24h] [xbp-21Ch]
  unsigned int v19; // [xsp+28h] [xbp-218h]
  _WORD v20[2]; // [xsp+2Ch] [xbp-214h] BYREF
  _QWORD v21[32]; // [xsp+30h] [xbp-210h] BYREF
  _BYTE v22[112]; // [xsp+130h] [xbp-110h] BYREF
  _QWORD v23[2]; // [xsp+1A0h] [xbp-A0h]
  _BYTE v24[112]; // [xsp+1B0h] [xbp-90h] BYREF
  _QWORD v25[4]; // [xsp+220h] [xbp-20h]

  v25[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 2936);
  if ( v1 )
  {
    v2 = 128;
    v3 = *(_QWORD *)(v1 + 6400) + 196LL;
    while ( !*(_DWORD *)(v3 - 180) )
    {
LABEL_4:
      --v2;
      v3 += 1872;
      if ( !v2 )
        goto LABEL_18;
    }
    *(_QWORD *)((char *)v25 + 5) = 0;
    v25[0] = 0;
    memset(v24, 0, sizeof(v24));
    *(_QWORD *)((char *)v23 + 5) = 0;
    v23[0] = 0;
    memset(v22, 0, sizeof(v22));
    memset(v21, 0, sizeof(v21));
    v20[0] = 0;
    v4 = *(_DWORD *)(v3 - 164);
    LOBYTE(v5) = v4;
    if ( (v4 & 1) != 0 )
    {
      scnprintf(v22, 125, "tx: flow_id %hu mdata 0x%x", *(unsigned __int16 *)(v3 - 148), *(_DWORD *)(v3 - 144));
      v5 = *(_DWORD *)(v3 - 164);
      if ( (v5 & 2) == 0 )
        goto LABEL_3;
    }
    else if ( (*(_DWORD *)(v3 - 164) & 2) == 0 )
    {
      goto LABEL_3;
    }
    scnprintf(v24, 125, "rx: flow_id %hu mdata 0x%x", *(unsigned __int16 *)(v3 - 146), *(_DWORD *)(v3 - 140));
LABEL_3:
    if ( (*(_BYTE *)(v1 + 148) & 4) != 0 )
    {
      v16 = *(unsigned __int16 *)(v3 - 150);
      v17 = *(_DWORD *)(v3 - 176);
      if ( (v4 & 1) != 0 )
        v6 = v22;
      else
        v6 = v20;
      v18 = *(_DWORD *)(v3 - 180);
      v19 = *(unsigned __int8 *)(v3 - 156);
      if ( (v5 & 2) != 0 )
        v7 = v24;
      else
        v7 = v20;
      dp_print_tuple_to_str_0(v3, (__int64)v21);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: STC: id %d state %d dir %d peer_id %u %s %s tuple: %s",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "wlan_dp_stc_print_s_entry",
        v19,
        v18,
        v17,
        v16,
        v6,
        v7,
        v21);
    }
    goto LABEL_4;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
}
