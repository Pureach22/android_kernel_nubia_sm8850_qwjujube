__int64 __fastcall extract_additional_cli_reg_rules(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x20
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x11
  __int16 v19; // w10
  __int64 v20; // x23
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x3
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w21
  unsigned __int16 *v39; // x8
  __int64 v41; // [xsp+0h] [xbp-20h]
  __int64 v42; // [xsp+8h] [xbp-18h]
  __int64 v43; // [xsp+10h] [xbp-10h]
  __int64 v44; // [xsp+18h] [xbp-8h]

  v13 = *(unsigned int *)(a2 + 4LL * a3 + 240);
  if ( (_DWORD)v13 )
  {
    v15 = _qdf_mem_malloc(14 * v13, "create_ext_reg_rules_from_wmi", 17267);
    if ( v15 )
    {
      v16 = 0;
      v17 = a1 + 8;
      do
      {
        v18 = v15 + v16;
        v16 += 14;
        *(_WORD *)v18 = *(_DWORD *)(v17 - 4);
        *(_WORD *)(v18 + 2) = *(_WORD *)(v17 - 2);
        *(_WORD *)(v18 + 4) = *(_DWORD *)v17;
        *(_BYTE *)(v18 + 6) = *(_WORD *)(v17 + 2);
        *(_BYTE *)(v18 + 7) = *(_BYTE *)(v17 + 3);
        *(_WORD *)(v18 + 8) = *(_DWORD *)(v17 + 4);
        *(_BYTE *)(v18 + 10) = *(_BYTE *)(v17 + 8) & 1;
        v19 = *(_WORD *)(v17 + 10);
        v17 += 20;
        *(_WORD *)(v18 + 12) = v19;
      }
      while ( 14 * v13 != v16 );
    }
  }
  else
  {
    v15 = 0;
  }
  v20 = a2 + 328;
  *(_QWORD *)(a2 + 328 + 8LL * a3) = v15;
  qdf_trace_msg(0x31u, 8u, "AP Power type %s", a4, a5, a6, a7, a8, a9, a10, a11, "INDOOR_ENABLED_AP");
  if ( a3 )
    v29 = "SUBORDINATE CLIENT";
  else
    v29 = "DEFAULT CLIENT";
  qdf_trace_msg(0x31u, 8u, "Client type %s", v21, v22, v23, v24, v25, v26, v27, v28, v29);
  if ( (_DWORD)v13 )
  {
    v38 = 0;
    do
    {
      v39 = (unsigned __int16 *)(*(_QWORD *)(v20 + 8LL * a3) + 14LL * (int)v38);
      LODWORD(v42) = v39[4];
      LODWORD(v44) = v39[6];
      LODWORD(v43) = *((unsigned __int8 *)v39 + 10);
      LODWORD(v41) = *((unsigned __int8 *)v39 + 7);
      qdf_trace_msg(
        0x31u,
        8u,
        "CLI 6GHz rule %u start freq %u end freq %u max_bw %u reg_power %u ant_gain %u flags %u psd_flag %u psd_eirp %u",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38++,
        *v39,
        v39[1],
        v39[2],
        *((unsigned __int8 *)v39 + 6),
        v41,
        v42,
        v43,
        v44);
    }
    while ( (_DWORD)v13 != v38 );
  }
  return (unsigned int)v13;
}
