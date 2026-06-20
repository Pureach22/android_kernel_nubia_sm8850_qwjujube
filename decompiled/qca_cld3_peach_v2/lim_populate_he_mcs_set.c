__int64 __fastcall lim_populate_he_mcs_set(
        __int64 a1,
        _WORD *a2,
        __int64 a3,
        __int64 a4,
        unsigned __int8 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  int v13; // w8
  unsigned int v17; // w23
  unsigned int max_bw; // w0
  int v22; // w8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  int v41; // w25
  _BOOL8 is_24ghz_ch_freq; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x8
  __int64 v52; // x9
  __int64 min_he_mcs_map; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned __int16 sap_he_rx_mcs_map_160; // w0
  unsigned __int16 v63; // w8
  char v64; // w11
  char v65; // w12
  char v66; // w13
  unsigned __int16 v67; // w9
  unsigned __int16 v68; // w10
  unsigned __int16 v69; // w11
  unsigned __int16 v70; // w12
  unsigned __int16 v71; // w13
  __int64 v72; // [xsp+0h] [xbp-10h]
  __int64 v73; // [xsp+8h] [xbp-8h]

  v13 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5964LL);
  if ( (unsigned int)(v13 - 10) >= 4 && v13 != 0 )
    return 0;
  if ( a3 && *(_BYTE *)a3 )
  {
    if ( !a4 )
    {
      qdf_trace_msg(0x35u, 2u, "%s: session is NULL", a6, a7, a8, a9, a10, a11, a12, a13, "lim_populate_he_mcs_set");
      return 16;
    }
    v17 = *(_DWORD *)(a4 + 7176);
    if ( a1 )
    {
      max_bw = wlan_mlme_get_max_bw();
      v22 = *(_DWORD *)(a4 + 7036);
      if ( v22 )
      {
        if ( v17 == 2 && v22 == 2 && max_bw > 2 )
        {
          v17 = 3;
        }
        else if ( (v22 | 2) == 3
               && *(_DWORD *)(a4 + 7176) != v17
               && (wlan_is_dnw_in_progress(*(_QWORD *)(a1 + 21632), *(unsigned __int8 *)(a4 + 10)) & 1) != 0 )
        {
          v17 = *(_DWORD *)(a4 + 7176);
        }
      }
      else if ( max_bw > 2 && v17 == 2 )
      {
        v17 = 3;
      }
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: session chan width: %d",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "lim_populate_he_mcs_set",
      v17);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: PEER: lt 80: rx 0x%04x tx 0x%04x, 160: rx 0x%04x tx 0x%04x, 80+80: rx 0x%04x tx 0x%04x",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "lim_populate_he_mcs_set",
      *(unsigned __int16 *)(a3 + 20),
      *(unsigned __int16 *)(a3 + 22),
      *(unsigned __int16 *)(a3 + 24),
      *(unsigned __int16 *)(a3 + 26),
      *(unsigned __int16 *)(a3 + 28),
      *(unsigned __int16 *)(a3 + 30));
    if ( a5 >= 2u )
    {
      if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1072LL) != 1
        || !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284))
        || (~*(unsigned __int8 *)(a4 + 7281) & 3) == 0 )
      {
        v41 = 1;
        goto LABEL_34;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: 2x2 not enabled %d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "lim_populate_he_mcs_set");
    }
    v41 = 0;
LABEL_34:
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284));
    v51 = 21870;
    if ( is_24ghz_ch_freq )
    {
      v51 = 21810;
      v52 = 21808;
    }
    else
    {
      v52 = 21868;
    }
    min_he_mcs_map = lim_populate_he_mcs_per_bw(
                       v43,
                       v44,
                       v45,
                       v46,
                       v47,
                       v48,
                       v49,
                       v50,
                       is_24ghz_ch_freq,
                       a2 + 25,
                       a2 + 26,
                       *(unsigned __int16 *)(a3 + 20),
                       *(unsigned __int16 *)(a3 + 22),
                       a5,
                       *(unsigned __int16 *)(a1 + v52),
                       *(unsigned __int16 *)(a1 + v51));
    if ( (v17 == 3 || *(_DWORD *)(a4 + 7176) == 7) && (*(_BYTE *)(a3 + 7) & 0x10) != 0 )
    {
      min_he_mcs_map = lim_populate_he_mcs_per_bw(
                         v54,
                         v55,
                         v56,
                         v57,
                         v58,
                         v59,
                         v60,
                         v61,
                         min_he_mcs_map,
                         a2 + 27,
                         a2 + 28,
                         *(unsigned __int16 *)(a3 + 24),
                         *(unsigned __int16 *)(a3 + 26),
                         a5,
                         *(unsigned __int16 *)(a1 + 21872),
                         *(unsigned __int16 *)(a1 + 21874));
      if ( *(_DWORD *)(a4 + 88) == 1 )
      {
        sap_he_rx_mcs_map_160 = wlan_mlme_get_sap_he_rx_mcs_map_160(*(_QWORD *)(a1 + 21624));
        min_he_mcs_map = wlan_mlme_get_min_he_mcs_map(sap_he_rx_mcs_map_160, a2[27]);
        a2[27] = min_he_mcs_map;
      }
    }
    else
    {
      *(_DWORD *)(a2 + 27) = -1;
    }
    if ( v17 == 4 )
    {
      lim_populate_he_mcs_per_bw(
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        min_he_mcs_map,
        a2 + 29,
        a2 + 30,
        *(unsigned __int16 *)(a3 + 28),
        *(unsigned __int16 *)(a3 + 30),
        a5,
        *(unsigned __int16 *)(a1 + 21876),
        *(unsigned __int16 *)(a1 + 21878));
      v63 = a2[25];
      if ( !v41 )
      {
LABEL_45:
        v63 |= 0xFFFCu;
        v64 = a2[28];
        v65 = a2[29];
        v66 = a2[30];
        v67 = (unsigned __int8)a2[26] | 0xFFFC;
        v68 = (unsigned __int8)a2[27] | 0xFFFC;
        a2[25] = v63;
        v69 = *(_WORD *)&v64 | 0xFFFC;
        v70 = *(_WORD *)&v65 | 0xFFFC;
        v71 = *(_WORD *)&v66 | 0xFFFC;
        a2[26] = v67;
        a2[27] = v68;
        a2[28] = v69;
        a2[29] = v70;
        a2[30] = v71;
LABEL_48:
        LODWORD(v73) = v71;
        LODWORD(v72) = v70;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: lt 80: rx 0x%x tx 0x%x, 160: rx 0x%x tx 0x%x, 80_80: rx 0x%x tx 0x%x",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "lim_populate_he_mcs_set",
          v63,
          v67,
          v68,
          v69,
          v72,
          v73);
        return 0;
      }
    }
    else
    {
      *(_DWORD *)(a2 + 29) = -1;
      v63 = a2[25];
      if ( !v41 )
        goto LABEL_45;
    }
    v67 = a2[26];
    v68 = a2[27];
    v69 = a2[28];
    v70 = a2[29];
    v71 = a2[30];
    goto LABEL_48;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: peer not he capable or he_caps NULL",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "lim_populate_he_mcs_set");
  return 0;
}
