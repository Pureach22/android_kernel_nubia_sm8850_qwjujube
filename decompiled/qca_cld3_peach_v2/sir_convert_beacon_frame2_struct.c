__int64 __fastcall sir_convert_beacon_frame2_struct(__int64 a1, int *a2, __int64 a3)
{
  __int64 v6; // x22
  __int64 v7; // x26
  unsigned int v8; // w21
  int v9; // w25
  _BYTE *v10; // x0
  _BYTE *v11; // x19
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x7
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int16 v24; // w26
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2
  unsigned int v34; // w20
  __int64 v35; // x9
  __int64 v36; // x10
  int v37; // w8
  __int64 v38; // x9
  __int64 v39; // x10
  __int64 v40; // x8
  __int64 v41; // x8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  int v51; // w8
  unsigned int v52; // w8
  unsigned int v53; // w8
  unsigned int v54; // w8
  unsigned int v55; // w8
  unsigned int v56; // w8
  unsigned int v57; // w8
  unsigned int v58; // w8
  unsigned int v59; // w8
  unsigned int v60; // w8
  unsigned int v61; // w8
  unsigned int v62; // w8
  unsigned int v63; // w8
  unsigned int v64; // w8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x26
  __int64 v74; // x0
  unsigned int v75; // w1
  int v76; // w8
  __int64 v77; // x25
  _QWORD v78[7]; // [xsp+8h] [xbp-48h] BYREF
  int v79; // [xsp+40h] [xbp-10h]
  __int64 v80; // [xsp+48h] [xbp-8h]

  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *((_QWORD *)a2 + 2);
  v6 = *((_QWORD *)a2 + 3);
  v8 = a2[10];
  v9 = *a2;
  qdf_mem_set((void *)a3, 0x1A08u, 0);
  v10 = qdf_mem_malloc_atomic_fl(0xF80u, (__int64)"sir_convert_beacon_frame2_struct", 0x176Fu);
  if ( v10 )
  {
    v11 = v10;
    qdf_mem_copy((void *)(a3 + 1183), (const void *)(v7 + 10), 6u);
    v15 = dot11f_unpack_beacon(a1, v6, v8, (__int64)v11, 0, v12, v13, v14);
    if ( (v15 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to parse Beacon IEs (0x%08x, %d bytes):",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sir_convert_beacon_frame2_struct",
        v15,
        v8);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 8, v6, v8);
LABEL_12:
      v34 = 16;
LABEL_13:
      _qdf_mem_free((__int64)v11);
      goto LABEL_14;
    }
    v24 = v8 - 12;
    if ( (unsigned int)lim_strip_and_decode_eht_op((unsigned __int8 *)(v6 + 12), (unsigned __int16)v8 - 12, v11 + 2600) )
    {
      v33 = "%s: Failed to extract eht op";
LABEL_11:
      qdf_trace_msg(0x35u, 2u, v33, v25, v26, v27, v28, v29, v30, v31, v32, "sir_convert_beacon_frame2_struct");
      goto LABEL_12;
    }
    v35 = *((_QWORD *)v11 + 288);
    v36 = *((_QWORD *)v11 + 289);
    v78[4] = *((_QWORD *)v11 + 287);
    v78[5] = v35;
    v37 = *((_DWORD *)v11 + 580);
    v38 = *((_QWORD *)v11 + 283);
    v78[6] = v36;
    v39 = *((_QWORD *)v11 + 285);
    v79 = v37;
    v40 = *((_QWORD *)v11 + 284);
    v78[0] = v38;
    v78[1] = v40;
    v41 = *((_QWORD *)v11 + 286);
    v78[2] = v39;
    v78[3] = v41;
    if ( (unsigned int)lim_strip_and_decode_eht_cap((unsigned __int8 *)(v6 + 12), v24, v11 + 2508, (__int64)v78, v9, 0) )
    {
      v33 = "%s: Failed to extract eht cap";
      goto LABEL_11;
    }
    if ( (unsigned int)lim_strip_and_decode_tpe_ie((unsigned __int8 *)(v6 + 12), v24, (__int64)(v11 + 1444)) )
    {
      v33 = "%s: Failed to extract tpe IE";
      goto LABEL_11;
    }
    qdf_mem_copy((void *)a3, v11, 8u);
    *(_WORD *)(a3 + 8) = *((_WORD *)v11 + 4);
    v51 = *(_WORD *)(a3 + 10) & 0xFFFE | *((_WORD *)v11 + 5) & 1;
    *(_WORD *)(a3 + 10) = *(_WORD *)(a3 + 10) & 0xFFFE | *((_WORD *)v11 + 5) & 1;
    v52 = v51 & 0xFFFFFFFD | (2 * ((*((unsigned __int16 *)v11 + 5) >> 1) & 1));
    *(_WORD *)(a3 + 10) = v52;
    v53 = v52 & 0xFFFFFFFB | (4 * ((*((unsigned __int16 *)v11 + 5) >> 2) & 1));
    *(_WORD *)(a3 + 10) = v53;
    v54 = v53 & 0xFFFFFFF7 | (8 * ((*((unsigned __int16 *)v11 + 5) >> 3) & 1));
    *(_WORD *)(a3 + 10) = v54;
    v55 = v54 & 0xFFFFFFEF | (16 * ((*((unsigned __int16 *)v11 + 5) >> 4) & 1));
    *(_WORD *)(a3 + 10) = v55;
    v56 = v55 & 0xFFFFFFDF | (32 * ((*((unsigned __int16 *)v11 + 5) >> 5) & 1));
    *(_WORD *)(a3 + 10) = v56;
    v57 = v56 & 0xFFFFFFBF | (((*((unsigned __int16 *)v11 + 5) >> 6) & 1) << 6);
    *(_WORD *)(a3 + 10) = v57;
    v58 = v57 & 0xFFFFFF7F | (((*((unsigned __int16 *)v11 + 5) >> 7) & 1) << 7);
    *(_WORD *)(a3 + 10) = v58;
    v59 = v58 & 0xFFFFFEFF | ((HIBYTE(*((unsigned __int16 *)v11 + 5)) & 1) << 8);
    *(_WORD *)(a3 + 10) = v59;
    v60 = v59 & 0xFFFFFDFF | (((*((unsigned __int16 *)v11 + 5) >> 9) & 1) << 9);
    *(_WORD *)(a3 + 10) = v60;
    v61 = v60 & 0xFFFFFBFF | (((*((unsigned __int16 *)v11 + 5) >> 10) & 1) << 10);
    *(_WORD *)(a3 + 10) = v61;
    v62 = v61 & 0xFFFFF7FF | (((*((unsigned __int16 *)v11 + 5) >> 11) & 1) << 11);
    *(_WORD *)(a3 + 10) = v62;
    v63 = v62 & 0xFFFFEFFF | (((*((unsigned __int16 *)v11 + 5) >> 12) & 1) << 12);
    *(_WORD *)(a3 + 10) = v63;
    v64 = v63 & 0xFFFFDFFF | (((*((unsigned __int16 *)v11 + 5) >> 13) & 1) << 13);
    *(_WORD *)(a3 + 10) = v64;
    LOWORD(v64) = v64 & 0xBFFF | (((*((_WORD *)v11 + 5) >> 14) & 1) << 14);
    *(_WORD *)(a3 + 10) = v64;
    *(_WORD *)(a3 + 10) = *((_WORD *)v11 + 5) & 0x8000 | v64 & 0x7FFF;
    if ( v11[12] )
    {
      *(_BYTE *)(a3 + 2460) = 1;
      convert_ssid(a1, a3 + 12, v11 + 12);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Mandatory IE SSID not present!",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "sir_convert_beacon_frame2_struct");
    }
    if ( v11[46] )
    {
      *(_BYTE *)(a3 + 2461) = 1;
      convert_supp_rates(a1, a3 + 46, v11 + 46);
    }
    else
    {
      v73 = jiffies;
      if ( sir_convert_beacon_frame2_struct___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Mandatory IE Supported Rates not present!",
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          "sir_convert_beacon_frame2_struct");
        sir_convert_beacon_frame2_struct___last_ticks = v73;
      }
    }
    if ( v11[861] )
    {
      *(_BYTE *)(a3 + 2462) = 1;
      convert_ext_supp_rates(a1, a3 + 59, v11 + 861);
    }
    if ( v11[70] )
    {
      *(_BYTE *)(a3 + 2464) = 1;
      convert_cf_params(a1, a3 + 76, v11 + 70);
    }
    if ( v11[78] )
    {
      *(_BYTE *)(a3 + 2466) = 1;
      convert_tim(a1, a3 + 82, v11 + 78);
    }
    if ( v11[334] )
    {
      *(_BYTE *)(a3 + 2472) = 1;
      convert_country(a1, a3 + 364);
    }
    if ( v11[1158] )
    {
      *(_BYTE *)(a3 + 2468) = 1;
      convert_qos_caps(a1, a3 + 361, v11 + 1158);
    }
    if ( v11[1138] )
    {
      *(_BYTE *)(a3 + 2467) = 1;
      convert_edca_param(a1, a3 + 337, v11 + 1138);
    }
    if ( v11[844] )
    {
      *(_BYTE *)(a3 + 2476) = 1;
      qdf_mem_copy((void *)(a3 + 1138), v11 + 844, 4u);
    }
    if ( v11[1226] )
    {
      *(_BYTE *)(a3 + 2478) = 1;
      qdf_mem_copy((void *)(a3 + 1144), v11 + 1226, 5u);
    }
    if ( v11[2384] )
    {
      *(_BYTE *)(a3 + 2477) = 1;
      qdf_mem_copy((void *)(a3 + 1142), v11 + 2384, 2u);
    }
    if ( v11[856] )
    {
      *(_BYTE *)(a3 + 2480) = 1;
      qdf_mem_copy((void *)(a3 + 1135), v11 + 856, 3u);
    }
    if ( v11[842] )
    {
      *(_BYTE *)(a3 + 2481) = 1;
      qdf_mem_copy((void *)(a3 + 1133), v11 + 842, 2u);
    }
    if ( v11[848] )
    {
      *(_BYTE *)(a3 + 2479) = 1;
      qdf_mem_copy((void *)(a3 + 1190), v11 + 848, 8u);
    }
    if ( v11[1268] )
      qdf_mem_copy((void *)(a3 + 1200), v11 + 1268, 0x3Cu);
    if ( v11[1328] )
      qdf_mem_copy((void *)(a3 + 1260), v11 + 1328, 0x3Au);
    if ( (v11[2327] & 0x20) != 0 )
    {
      *(_DWORD *)(a3 + 72) = wlan_reg_chan_band_to_freq(
                               *(_QWORD *)(a1 + 21632),
                               (unsigned __int8)v11[2336],
                               4u,
                               v65,
                               v66,
                               v67,
                               v68,
                               v69,
                               v70,
                               v71,
                               v72);
      *(_BYTE *)(a3 + 3435) = (v11[2337] >> 3) & 0xF;
    }
    else
    {
      if ( v11[68] )
      {
        *(_BYTE *)(a3 + 2465) = 1;
        v74 = *(_QWORD *)(a1 + 21632);
        v75 = (unsigned __int8)v11[69];
      }
      else
      {
        if ( !v11[1328] )
        {
          *(_DWORD *)(a3 + 72) = *a2;
          v77 = jiffies;
          if ( sir_convert_beacon_frame2_struct___last_ticks_94 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: In Beacon No Channel info",
              v65,
              v66,
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              "sir_convert_beacon_frame2_struct");
            sir_convert_beacon_frame2_struct___last_ticks_94 = v77;
          }
          goto LABEL_57;
        }
        v74 = *(_QWORD *)(a1 + 21632);
        v75 = (unsigned __int8)v11[1329];
      }
      *(_DWORD *)(a3 + 72) = wlan_reg_legacy_chan_to_freq(v74, v75, v65, v66, v67, v68, v69, v70, v71, v72);
    }
LABEL_57:
    if ( v11[875] )
    {
      *(_BYTE *)(a3 + 2474) = 1;
      convert_rsn_opaque(a1, a3 + 876, v11 + 875);
    }
    if ( v11[3386] )
    {
      *(_BYTE *)(a3 + 2473) = 1;
      convert_wpa(a1, a3 + 620, v11 + 3386);
    }
    if ( v11[3438] )
    {
      *(_BYTE *)(a3 + 2469) = 1;
      convert_wmm_params(a1, a3 + 337, v11 + 3438);
    }
    if ( v11[3434] )
    {
      *(_BYTE *)(a3 + 2470) = 1;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: WMM Info present in Beacon Frame!",
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        "sir_convert_beacon_frame2_struct");
    }
    if ( v11[3458] )
      *(_BYTE *)(a3 + 2471) = 1;
    if ( v11[859] )
    {
      *(_BYTE *)(a3 + 2475) = 1;
      convert_erp_info(a1, a3 + 1132, v11 + 859);
    }
    if ( v11[1220] )
    {
      *(_BYTE *)(a3 + 2482) = 1;
      qdf_mem_copy((void *)(a3 + 2446), v11 + 1222, 2u);
      *(_BYTE *)(a3 + 2448) = v11[1224] & 3;
    }
    if ( v11[3461] )
      *(_BYTE *)(a3 + 2574) = 1;
    if ( v11[2498] )
    {
      *(_BYTE *)(a3 + 2449) = 1;
      qdf_mem_copy((void *)(a3 + 2449), v11 + 2498, 3u);
    }
    if ( v11[1130] )
      qdf_mem_copy((void *)(a3 + 2452), v11 + 1130, 8u);
    if ( v11[1420] )
      qdf_mem_copy((void *)(a3 + 2484), v11 + 1420, 0x10u);
    if ( v11[1436] )
      qdf_mem_copy((void *)(a3 + 2500), v11 + 1436, 6u);
    if ( v11[1892] )
      qdf_mem_copy((void *)(a3 + 2506), v11 + 1892, 6u);
    if ( v11[1898] )
      qdf_mem_copy((void *)(a3 + 2529), v11 + 1898, 2u);
    if ( v11[2501] )
    {
      *(_BYTE *)(a3 + 2531) = 1;
      qdf_mem_copy((void *)(a3 + 2532), v11 + 2501, 4u);
    }
    *(_BYTE *)(a3 + 2536) = v11[3575];
    *(_BYTE *)(a3 + 2568) = v11[3604];
    v76 = (unsigned __int8)v11[3576];
    *(_BYTE *)(a3 + 2540) = v76;
    if ( v76 )
      *(_BYTE *)(a3 + 2541) = v11[3577];
    if ( v11[3580] )
      qdf_mem_copy((void *)(a3 + 2544), v11 + 3580, 0x10u);
    if ( v11[3596] )
      qdf_mem_copy((void *)(a3 + 2560), v11 + 1436, 6u);
    if ( v11[3606] )
    {
      qdf_mem_copy((void *)(a3 + 2570), v11 + 3606, 2u);
      if ( (v11[3607] & 6) != 0 )
        qdf_mem_copy((void *)(a3 + 2572), v11 + 3608, 2u);
    }
    if ( v11[1386] )
      qdf_mem_copy((void *)(a3 + 2576), v11 + 1386, 0x10u);
    if ( v11[3614] )
    {
      *(_BYTE *)(a3 + 2592) = 1;
      if ( v11[3874] )
        *(_BYTE *)(a3 + 2593) = v11[3875];
      if ( v11[3876] )
      {
        *(_BYTE *)(a3 + 2594) = 1;
        *(_BYTE *)(a3 + 2595) = v11[3877];
      }
    }
    if ( v11[3896] )
      qdf_mem_copy((void *)(a3 + 2596), v11 + 3896, 0x2Cu);
    if ( v11[2264] )
      qdf_mem_copy((void *)(a3 + 2640), v11 + 2264, 0x3Cu);
    if ( v11[2324] )
      qdf_mem_copy((void *)(a3 + 2700), v11 + 2324, 0x12u);
    if ( v11[2508] )
      qdf_mem_copy((void *)(a3 + 2740), v11 + 2508, 0x5Cu);
    if ( v11[2600] )
      qdf_mem_copy((void *)(a3 + 2832), v11 + 2600, 0xCu);
    *(_BYTE *)(a3 + 3218) = v11[1442];
    if ( *((_WORD *)v11 + 721) )
      qdf_mem_copy((void *)(a3 + 3219), v11 + 1444, 27 * (unsigned int)*((unsigned __int16 *)v11 + 721));
    convert_bcon_bss_color_change_ie(v11, a3);
    sir_convert_beacon_frame2_mlo_struct(v6, v8, v11, a3);
    sir_convert_beacon_frame2_t2lm_struct(v11, a3);
    if ( v11[2342] )
      qdf_mem_copy((void *)(a3 + 2718), v11 + 2342, 0x15u);
    v34 = 0;
    goto LABEL_13;
  }
  v34 = 2;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v34;
}
