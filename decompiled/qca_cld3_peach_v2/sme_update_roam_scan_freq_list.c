__int64 __fastcall sme_update_roam_scan_freq_list(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned __int8 a4,
        int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x9
  __int64 v14; // x14
  __int64 v15; // x0
  unsigned int v16; // w2
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  _QWORD v26[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v27; // [xsp+18h] [xbp-18h]
  __int64 v28; // [xsp+20h] [xbp-10h]
  __int64 v29; // [xsp+28h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[1] = 0;
  v27 = 0;
  v26[0] = 0;
  if ( !a3 || !a4 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Freq list empty %pK or num_channels is 0",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "sme_validate_freq_list",
      a3);
LABEL_16:
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: List contains invalid channel(s)",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "sme_update_roam_scan_freq_list");
    result = 4;
    goto LABEL_17;
  }
  if ( !*(_BYTE *)(a1 + 16604) )
  {
    v13 = 0;
LABEL_15:
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Invalid frequency %u",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "sme_validate_freq_list",
      *(unsigned int *)(a3 + 4 * v13));
    goto LABEL_16;
  }
  v13 = 0;
  do
  {
    v14 = 0;
    while ( 1 )
    {
      if ( v14 == 400 )
        __break(0x5512u);
      if ( *(_DWORD *)(a1 + 16608 + v14) == *(_DWORD *)(a3 + 4 * v13) )
        break;
      v14 += 4;
      if ( 4LL * *(unsigned __int8 *)(a1 + 16604) == v14 )
      {
        v13 = (unsigned __int8)v13;
        goto LABEL_15;
      }
    }
    ++v13;
  }
  while ( v13 != a4 );
  v15 = *(_QWORD *)(a1 + 21624);
  LOBYTE(v27) = a4;
  v28 = a3;
  if ( a5 == 1 )
    v16 = 10;
  else
    v16 = 11;
  result = wlan_cm_roam_cfg_set_value(v15, a2, v16, (unsigned int *)v26);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
