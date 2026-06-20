__int64 __fastcall sir_convert_beacon_frame2_struct(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x24
  __int64 v4; // x25
  unsigned int v7; // w21
  _BYTE *v9; // x0
  _BYTE *v10; // x19
  __int64 v11; // x5
  __int64 v12; // x6
  __int64 v13; // x7
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w8
  unsigned int v32; // w8
  unsigned int v33; // w8
  unsigned int v34; // w8
  unsigned int v35; // w8
  unsigned int v36; // w8
  unsigned int v37; // w8
  unsigned int v38; // w8
  unsigned int v39; // w8
  unsigned int v40; // w8
  unsigned int v41; // w8
  unsigned int v42; // w8
  unsigned int v43; // w8
  unsigned int v44; // w8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w20
  __int64 v54; // x25
  __int64 v55; // x0
  unsigned int v56; // w1
  int v57; // w8
  __int64 v59; // x24

  v4 = *(_QWORD *)(a2 + 16);
  v3 = *(_QWORD *)(a2 + 24);
  v7 = *(_DWORD *)(a2 + 40);
  qdf_mem_set((void *)a3, 0xD80u, 0);
  v9 = qdf_mem_malloc_atomic_fl(0xF80u, (__int64)"sir_convert_beacon_frame2_struct", 0x176Fu);
  if ( v9 )
  {
    v10 = v9;
    qdf_mem_copy((void *)(a3 + 1183), (const void *)(v4 + 10), 6u);
    v14 = dot11f_unpack_beacon(a1, v3, v7, (__int64)v10, 0, v11, v12, v13);
    if ( (v14 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to parse Beacon IEs (0x%08x, %d bytes):",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "sir_convert_beacon_frame2_struct",
        v14,
        v7);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 8, v3, v7);
      v53 = 16;
LABEL_110:
      _qdf_mem_free((__int64)v10);
      return v53;
    }
    qdf_mem_copy((void *)a3, v10, 8u);
    *(_WORD *)(a3 + 8) = *((_WORD *)v10 + 4);
    v31 = *(_WORD *)(a3 + 10) & 0xFFFE | *((_WORD *)v10 + 5) & 1;
    *(_WORD *)(a3 + 10) = *(_WORD *)(a3 + 10) & 0xFFFE | *((_WORD *)v10 + 5) & 1;
    v32 = v31 & 0xFFFFFFFD | (2 * ((*((unsigned __int16 *)v10 + 5) >> 1) & 1));
    *(_WORD *)(a3 + 10) = v32;
    v33 = v32 & 0xFFFFFFFB | (4 * ((*((unsigned __int16 *)v10 + 5) >> 2) & 1));
    *(_WORD *)(a3 + 10) = v33;
    v34 = v33 & 0xFFFFFFF7 | (8 * ((*((unsigned __int16 *)v10 + 5) >> 3) & 1));
    *(_WORD *)(a3 + 10) = v34;
    v35 = v34 & 0xFFFFFFEF | (16 * ((*((unsigned __int16 *)v10 + 5) >> 4) & 1));
    *(_WORD *)(a3 + 10) = v35;
    v36 = v35 & 0xFFFFFFDF | (32 * ((*((unsigned __int16 *)v10 + 5) >> 5) & 1));
    *(_WORD *)(a3 + 10) = v36;
    v37 = v36 & 0xFFFFFFBF | (((*((unsigned __int16 *)v10 + 5) >> 6) & 1) << 6);
    *(_WORD *)(a3 + 10) = v37;
    v38 = v37 & 0xFFFFFF7F | (((*((unsigned __int16 *)v10 + 5) >> 7) & 1) << 7);
    *(_WORD *)(a3 + 10) = v38;
    v39 = v38 & 0xFFFFFEFF | ((HIBYTE(*((unsigned __int16 *)v10 + 5)) & 1) << 8);
    *(_WORD *)(a3 + 10) = v39;
    v40 = v39 & 0xFFFFFDFF | (((*((unsigned __int16 *)v10 + 5) >> 9) & 1) << 9);
    *(_WORD *)(a3 + 10) = v40;
    v41 = v40 & 0xFFFFFBFF | (((*((unsigned __int16 *)v10 + 5) >> 10) & 1) << 10);
    *(_WORD *)(a3 + 10) = v41;
    v42 = v41 & 0xFFFFF7FF | (((*((unsigned __int16 *)v10 + 5) >> 11) & 1) << 11);
    *(_WORD *)(a3 + 10) = v42;
    v43 = v42 & 0xFFFFEFFF | (((*((unsigned __int16 *)v10 + 5) >> 12) & 1) << 12);
    *(_WORD *)(a3 + 10) = v43;
    v44 = v43 & 0xFFFFDFFF | (((*((unsigned __int16 *)v10 + 5) >> 13) & 1) << 13);
    *(_WORD *)(a3 + 10) = v44;
    LOWORD(v44) = v44 & 0xBFFF | (((*((_WORD *)v10 + 5) >> 14) & 1) << 14);
    *(_WORD *)(a3 + 10) = v44;
    *(_WORD *)(a3 + 10) = *((_WORD *)v10 + 5) & 0x8000 | v44 & 0x7FFF;
    if ( v10[12] )
    {
      *(_BYTE *)(a3 + 2460) = 1;
      convert_ssid(a1, a3 + 12, v10 + 12);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Mandatory IE SSID not present!",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "sir_convert_beacon_frame2_struct");
    }
    if ( v10[46] )
    {
      *(_BYTE *)(a3 + 2461) = 1;
      convert_supp_rates(a1, a3 + 46, v10 + 46);
    }
    else
    {
      v54 = jiffies;
      if ( sir_convert_beacon_frame2_struct___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Mandatory IE Supported Rates not present!",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "sir_convert_beacon_frame2_struct");
        sir_convert_beacon_frame2_struct___last_ticks = v54;
      }
    }
    if ( v10[861] )
    {
      *(_BYTE *)(a3 + 2462) = 1;
      convert_ext_supp_rates(a1, a3 + 59, v10 + 861);
    }
    if ( v10[70] )
    {
      *(_BYTE *)(a3 + 2464) = 1;
      convert_cf_params(a1, a3 + 76, v10 + 70);
    }
    if ( v10[78] )
    {
      *(_BYTE *)(a3 + 2466) = 1;
      convert_tim(a1, a3 + 82, v10 + 78);
    }
    if ( v10[334] )
    {
      *(_BYTE *)(a3 + 2472) = 1;
      convert_country(a1, a3 + 364);
    }
    if ( v10[1158] )
    {
      *(_BYTE *)(a3 + 2468) = 1;
      convert_qos_caps(a1, a3 + 361, v10 + 1158);
    }
    if ( v10[1138] )
    {
      *(_BYTE *)(a3 + 2467) = 1;
      convert_edca_param(a1, a3 + 337, v10 + 1138);
    }
    if ( v10[844] )
    {
      *(_BYTE *)(a3 + 2476) = 1;
      qdf_mem_copy((void *)(a3 + 1138), v10 + 844, 4u);
    }
    if ( v10[1226] )
    {
      *(_BYTE *)(a3 + 2478) = 1;
      qdf_mem_copy((void *)(a3 + 1144), v10 + 1226, 5u);
    }
    if ( v10[2384] )
    {
      *(_BYTE *)(a3 + 2477) = 1;
      qdf_mem_copy((void *)(a3 + 1142), v10 + 2384, 2u);
    }
    if ( v10[856] )
    {
      *(_BYTE *)(a3 + 2480) = 1;
      qdf_mem_copy((void *)(a3 + 1135), v10 + 856, 3u);
    }
    if ( v10[842] )
    {
      *(_BYTE *)(a3 + 2481) = 1;
      qdf_mem_copy((void *)(a3 + 1133), v10 + 842, 2u);
    }
    if ( v10[848] )
    {
      *(_BYTE *)(a3 + 2479) = 1;
      qdf_mem_copy((void *)(a3 + 1190), v10 + 848, 8u);
    }
    if ( v10[1268] )
      qdf_mem_copy((void *)(a3 + 1200), v10 + 1268, 0x3Cu);
    if ( v10[1328] )
      qdf_mem_copy((void *)(a3 + 1260), v10 + 1328, 0x3Au);
    if ( (v10[2327] & 0x20) != 0 )
    {
      *(_DWORD *)(a3 + 72) = wlan_reg_chan_band_to_freq(
                               *(_QWORD *)(a1 + 21560),
                               (unsigned __int8)v10[2336],
                               4u,
                               v45,
                               v46,
                               v47,
                               v48,
                               v49,
                               v50,
                               v51,
                               v52);
      *(_BYTE *)(a3 + 3435) = (v10[2337] >> 3) & 0xF;
    }
    else
    {
      if ( v10[68] )
      {
        *(_BYTE *)(a3 + 2465) = 1;
        v55 = *(_QWORD *)(a1 + 21560);
        v56 = (unsigned __int8)v10[69];
      }
      else
      {
        if ( !v10[1328] )
        {
          *(_DWORD *)(a3 + 72) = *(_DWORD *)a2;
          v59 = jiffies;
          if ( sir_convert_beacon_frame2_struct___last_ticks_94 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: In Beacon No Channel info",
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              "sir_convert_beacon_frame2_struct");
            sir_convert_beacon_frame2_struct___last_ticks_94 = v59;
          }
          goto LABEL_47;
        }
        v55 = *(_QWORD *)(a1 + 21560);
        v56 = (unsigned __int8)v10[1329];
      }
      *(_DWORD *)(a3 + 72) = wlan_reg_legacy_chan_to_freq(v55, v56, v45, v46, v47, v48, v49, v50, v51, v52);
    }
LABEL_47:
    if ( v10[875] )
    {
      *(_BYTE *)(a3 + 2474) = 1;
      convert_rsn_opaque(a1, a3 + 876, v10 + 875);
    }
    if ( v10[3386] )
    {
      *(_BYTE *)(a3 + 2473) = 1;
      convert_wpa(a1, a3 + 620, v10 + 3386);
    }
    if ( v10[3438] )
    {
      *(_BYTE *)(a3 + 2469) = 1;
      convert_wmm_params(a1, a3 + 337, v10 + 3438);
    }
    if ( v10[3434] )
    {
      *(_BYTE *)(a3 + 2470) = 1;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: WMM Info present in Beacon Frame!",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "sir_convert_beacon_frame2_struct");
    }
    if ( v10[3458] )
      *(_BYTE *)(a3 + 2471) = 1;
    if ( v10[859] )
    {
      *(_BYTE *)(a3 + 2475) = 1;
      convert_erp_info(a1, a3 + 1132, v10 + 859);
    }
    if ( v10[1220] )
    {
      *(_BYTE *)(a3 + 2482) = 1;
      qdf_mem_copy((void *)(a3 + 2446), v10 + 1222, 2u);
      *(_BYTE *)(a3 + 2448) = v10[1224] & 3;
    }
    if ( v10[3461] )
      *(_BYTE *)(a3 + 2574) = 1;
    if ( v10[2498] )
    {
      *(_BYTE *)(a3 + 2449) = 1;
      qdf_mem_copy((void *)(a3 + 2449), v10 + 2498, 3u);
    }
    if ( v10[1130] )
      qdf_mem_copy((void *)(a3 + 2452), v10 + 1130, 8u);
    if ( v10[1420] )
      qdf_mem_copy((void *)(a3 + 2484), v10 + 1420, 0x10u);
    if ( v10[1436] )
      qdf_mem_copy((void *)(a3 + 2500), v10 + 1436, 6u);
    if ( v10[1892] )
      qdf_mem_copy((void *)(a3 + 2506), v10 + 1892, 6u);
    if ( v10[1898] )
      qdf_mem_copy((void *)(a3 + 2529), v10 + 1898, 2u);
    if ( v10[2501] )
    {
      *(_BYTE *)(a3 + 2531) = 1;
      qdf_mem_copy((void *)(a3 + 2532), v10 + 2501, 4u);
    }
    *(_BYTE *)(a3 + 2536) = v10[3575];
    *(_BYTE *)(a3 + 2568) = v10[3604];
    v57 = (unsigned __int8)v10[3576];
    *(_BYTE *)(a3 + 2540) = v57;
    if ( v57 )
      *(_BYTE *)(a3 + 2541) = v10[3577];
    if ( v10[3580] )
      qdf_mem_copy((void *)(a3 + 2544), v10 + 3580, 0x10u);
    if ( v10[3596] )
      qdf_mem_copy((void *)(a3 + 2560), v10 + 1436, 6u);
    if ( v10[3606] )
    {
      qdf_mem_copy((void *)(a3 + 2570), v10 + 3606, 2u);
      if ( (v10[3607] & 6) != 0 )
        qdf_mem_copy((void *)(a3 + 2572), v10 + 3608, 2u);
    }
    if ( v10[1386] )
      qdf_mem_copy((void *)(a3 + 2576), v10 + 1386, 0x10u);
    if ( v10[3614] )
    {
      *(_BYTE *)(a3 + 2592) = 1;
      if ( v10[3874] )
        *(_BYTE *)(a3 + 2593) = v10[3875];
      if ( v10[3876] )
      {
        *(_BYTE *)(a3 + 2594) = 1;
        *(_BYTE *)(a3 + 2595) = v10[3877];
      }
    }
    if ( v10[3896] )
      qdf_mem_copy((void *)(a3 + 2596), v10 + 3896, 0x2Cu);
    if ( v10[2264] )
      qdf_mem_copy((void *)(a3 + 2640), v10 + 2264, 0x3Cu);
    if ( v10[2324] )
      qdf_mem_copy((void *)(a3 + 2700), v10 + 2324, 0x12u);
    if ( v10[2508] )
      qdf_mem_copy((void *)(a3 + 2740), v10 + 2508, 0x5Cu);
    if ( v10[2600] )
      qdf_mem_copy((void *)(a3 + 2832), v10 + 2600, 0xCu);
    *(_BYTE *)(a3 + 3218) = v10[1442];
    if ( *((_WORD *)v10 + 721) )
      qdf_mem_copy((void *)(a3 + 3219), v10 + 1444, 27 * (unsigned int)*((unsigned __int16 *)v10 + 721));
    if ( v10[2363] )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: 11AX: HE BSS color change present",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "convert_bcon_bss_color_change_ie");
      qdf_mem_copy((void *)(a3 + 2844), v10 + 2363, 3u);
    }
    if ( v10[2342] )
      qdf_mem_copy((void *)(a3 + 2718), v10 + 2342, 0x15u);
    v53 = 0;
    goto LABEL_110;
  }
  return 2;
}
