void __fastcall wlan_dp_stc_dump_periodic_stats(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned __int8 *v10; // x22
  __int64 v11; // x23
  unsigned __int8 *v12; // x24
  __int64 v13; // x20
  __int64 v14; // x8
  _DWORD *v15; // x9
  __int64 v16; // x13
  int v17; // w16
  __int64 v18; // x14
  unsigned __int16 v19; // w0
  unsigned __int16 v20; // w19
  __int16 v21; // w0
  unsigned __int16 v22; // w19
  __int16 v23; // w0
  unsigned int v24; // w8
  unsigned __int16 v25; // w0
  unsigned __int16 v26; // w19
  __int16 v27; // w0
  __int16 v28; // w22
  __int16 v29; // w0
  unsigned int v30; // w8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // [xsp+0h] [xbp-470h]
  __int64 v40; // [xsp+8h] [xbp-468h]
  __int64 v41; // [xsp+10h] [xbp-460h]
  __int64 v42; // [xsp+18h] [xbp-458h]
  __int64 v43; // [xsp+20h] [xbp-450h]
  _BYTE v44[512]; // [xsp+28h] [xbp-448h] BYREF
  _BYTE s[512]; // [xsp+228h] [xbp-248h] BYREF
  __int64 v46; // [xsp+428h] [xbp-48h]
  __int64 v47; // [xsp+430h] [xbp-40h]
  __int64 v48; // [xsp+438h] [xbp-38h]
  __int64 v49; // [xsp+440h] [xbp-30h]
  __int64 v50; // [xsp+448h] [xbp-28h]
  __int64 v51; // [xsp+450h] [xbp-20h]
  __int64 v52; // [xsp+458h] [xbp-18h]
  __int64 v53; // [xsp+460h] [xbp-10h]
  __int64 v54; // [xsp+468h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int8 **)(a1 + 2936);
  if ( v10 )
  {
    if ( (*((_DWORD *)v10 + 37) & 4) == 0
      || (qdf_trace_msg(
            0x45u,
            5u,
            "%s: STC: send_flow_stats %u send_flow_report %u logmask 0x%x",
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            "wlan_dp_stc_print_cfg",
            v10[8],
            v10[9]),
          (v10 = *(unsigned __int8 **)(a1 + 2936)) != nullptr) )
    {
      v11 = 64;
      v12 = v10;
      do
      {
        if ( v12[262] && (v10[148] & 4) != 0 )
        {
          LODWORD(v40) = *((_DWORD *)v12 + 80);
          LODWORD(v41) = *((_DWORD *)v12 + 81);
          LODWORD(v39) = *((_DWORD *)v12 + 79);
          LODWORD(v42) = ((unsigned int)*((_QWORD *)v12 + 42) >> 2) & 1;
          LODWORD(v43) = ((unsigned int)*((_QWORD *)v12 + 42) >> 1) & 1;
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: STC: peer_id %u bursty traffic: [%u %u %u] RT traffic: [%u %u %u] non flow traffic: [%u %u]",
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            "wlan_dp_stc_print_peer_active_traffic_map",
            *((unsigned __int16 *)v12 + 133),
            *((unsigned int *)v12 + 78),
            *((unsigned int *)v12 + 82),
            *((unsigned int *)v12 + 83),
            v39,
            v40,
            v41,
            v42,
            v43);
        }
        --v11;
        v12 += 96;
      }
      while ( v11 );
    }
  }
  wlan_dp_stc_print_sampling_table(a1);
  v13 = *(_QWORD *)(a1 + 2936);
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  if ( v13 )
  {
    memset(s, 0, sizeof(s));
    memset(v44, 0, sizeof(v44));
    v14 = 0;
    v15 = (_DWORD *)(*(_QWORD *)(v13 + 6424) + 100LL);
    do
    {
      if ( *v15 )
      {
        v16 = (unsigned int)v14 >> 6;
        v17 = *((unsigned __int8 *)v15 - 92);
        v18 = 1 << v14;
        *(&v50 + v16) |= v18;
        if ( v17 )
          *(&v46 + v16) |= v18;
      }
      ++v14;
      v15 += 32;
    }
    while ( v14 != 256 );
    scnprintf(s, 512, " 0x%llx", v50);
    if ( v19 > 0x200u )
      goto LABEL_24;
    v20 = v19;
    scnprintf(&s[v19], 512 - (unsigned int)v19, " 0x%llx", v51);
    v22 = v21 + v20;
    if ( v22 > 0x200u )
      goto LABEL_24;
    scnprintf(&s[v22], 512 - (unsigned int)v22, " 0x%llx", v52);
    v24 = (unsigned __int16)(v23 + v22);
    if ( v24 > 0x200
      || (scnprintf(&s[(unsigned __int16)(v23 + v22)], 512 - v24, " 0x%llx", v53),
          scnprintf(v44, 512, " 0x%llx", v46),
          v25 > 0x200u)
      || (v26 = v25,
          scnprintf(&v44[v25], 512 - (unsigned int)v25, " 0x%llx", v47),
          v28 = v27 + v26,
          (unsigned __int16)(v27 + v26) > 0x200u)
      || (scnprintf(
            &v44[(unsigned __int16)(v27 + v26)],
            512 - (unsigned int)(unsigned __int16)(v27 + v26),
            " 0x%llx",
            v48),
          v30 = (unsigned __int16)(v29 + v28),
          v30 > 0x200) )
    {
LABEL_24:
      __break(0x5512u);
    }
    v31 = scnprintf(&v44[(unsigned __int16)(v29 + v28)], 512 - v30, " 0x%llx", v49);
    if ( (*(_BYTE *)(v13 + 148) & 4) != 0 )
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: STC: classified flows mask - valid:%s active:%s",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "wlan_dp_stc_print_classified_table_compact",
        s,
        v44);
  }
  _ReadStatusReg(SP_EL0);
}
