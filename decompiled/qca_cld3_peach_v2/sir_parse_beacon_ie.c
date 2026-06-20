__int64 __fastcall sir_parse_beacon_ie(__int64 a1, __int64 a2, unsigned __int8 *a3, unsigned int a4)
{
  int v8; // w25
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
  const char *v31; // x2
  unsigned int v32; // w20
  __int64 v33; // x9
  __int64 v34; // x10
  __int64 v35; // x8
  __int64 v36; // x8
  __int64 v37; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x24
  __int64 v48; // x0
  unsigned int v49; // w1
  int v50; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  int v59; // w8
  _QWORD v60[7]; // [xsp+8h] [xbp-48h] BYREF
  int v61; // [xsp+40h] [xbp-10h]
  __int64 v62; // [xsp+48h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_DWORD *)a3;
  qdf_mem_set((void *)a2, 0x1A08u, 0);
  v9 = (_BYTE *)_qdf_mem_malloc(0x1490u, "sir_parse_beacon_ie", 5470);
  if ( v9 )
  {
    v10 = v9;
    qdf_mem_set(v9, 0x1490u, 0);
    v14 = dot11f_unpack_beacon_i_es(a1, (__int64)a3, a4, (__int64)v10, 0, v11, v12, v13);
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
        "sir_parse_beacon_ie",
        v14,
        a4);
      ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(53, 2, a3, a4);
LABEL_14:
      v32 = 16;
LABEL_15:
      _qdf_mem_free((__int64)v10);
      goto LABEL_16;
    }
    if ( v14 )
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: warnings (0x%08x, %d bytes):",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "sir_parse_beacon_ie",
        v14,
        a4);
    if ( (unsigned int)lim_strip_and_decode_eht_op(a3, a4, v10 + 2588) )
    {
      v31 = "%s: Failed to extract eht op";
LABEL_13:
      qdf_trace_msg(0x35u, 2u, v31, v23, v24, v25, v26, v27, v28, v29, v30, "sir_parse_beacon_ie");
      goto LABEL_14;
    }
    v33 = *(_QWORD *)(v10 + 2284);
    v34 = *(_QWORD *)(v10 + 2292);
    v61 = *((_DWORD *)v10 + 577);
    v35 = *(_QWORD *)(v10 + 2300);
    v60[4] = v33;
    v60[5] = v34;
    v60[6] = v35;
    v36 = *(_QWORD *)(v10 + 2260);
    v60[0] = *(_QWORD *)(v10 + 2252);
    v60[1] = v36;
    v37 = *(_QWORD *)(v10 + 2276);
    v60[2] = *(_QWORD *)(v10 + 2268);
    v60[3] = v37;
    if ( (unsigned int)lim_strip_and_decode_eht_cap(a3, a4, v10 + 2496, (__int64)v60, v8, 0) )
    {
      v31 = "%s: Failed to extract eht cap";
      goto LABEL_13;
    }
    if ( (unsigned int)lim_strip_and_decode_tpe_ie(a3, a4, (__int64)(v10 + 1432)) )
    {
      v31 = "%s: Failed to extract tpe IE";
      goto LABEL_13;
    }
    if ( *v10 )
    {
      *(_BYTE *)(a2 + 2460) = 1;
      convert_ssid(a1, a2 + 12, v10);
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
        "sir_parse_beacon_ie");
    }
    if ( v10[34] )
    {
      *(_BYTE *)(a2 + 2461) = 1;
      convert_supp_rates(a1, a2 + 46, v10 + 34);
    }
    else
    {
      v47 = jiffies;
      if ( sir_parse_beacon_ie___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Mandatory IE Supported Rates not present!",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "sir_parse_beacon_ie");
        sir_parse_beacon_ie___last_ticks = v47;
      }
    }
    if ( v10[849] )
    {
      *(_BYTE *)(a2 + 2462) = 1;
      convert_ext_supp_rates(a1, a2 + 59, v10 + 849);
    }
    if ( v10[58] )
    {
      *(_BYTE *)(a2 + 2464) = 1;
      convert_cf_params(a1, a2 + 76, v10 + 58);
    }
    if ( v10[66] )
    {
      *(_BYTE *)(a2 + 2466) = 1;
      convert_tim(a1, a2 + 82, v10 + 66);
    }
    if ( v10[322] )
    {
      *(_BYTE *)(a2 + 2472) = 1;
      convert_country(a1, a2 + 364);
    }
    if ( v10[844] )
    {
      *(_BYTE *)(a2 + 2480) = 1;
      qdf_mem_copy((void *)(a2 + 1135), v10 + 844, 3u);
    }
    if ( v10[830] )
    {
      *(_BYTE *)(a2 + 2481) = 1;
      qdf_mem_copy((void *)(a2 + 1133), v10 + 830, 2u);
    }
    if ( v10[3449] )
      *(_BYTE *)(a2 + 2574) = 1;
    if ( v10[2486] )
    {
      *(_BYTE *)(a2 + 2449) = 1;
      *(_BYTE *)(a2 + 2450) = v10[2487];
    }
    if ( v10[1118] )
      qdf_mem_copy((void *)(a2 + 2452), v10 + 1118, 8u);
    if ( v10[1126] )
    {
      *(_BYTE *)(a2 + 2467) = 1;
      convert_edca_param(a1, a2 + 337, v10 + 1126);
    }
    if ( v10[1146] )
    {
      *(_BYTE *)(a2 + 2468) = 1;
      convert_qos_caps(a1, a2 + 361, v10 + 1146);
    }
    if ( v10[832] )
    {
      *(_BYTE *)(a2 + 2476) = 1;
      qdf_mem_copy((void *)(a2 + 1138), v10 + 832, 4u);
    }
    if ( v10[1219] )
    {
      *(_BYTE *)(a2 + 2463) = 1;
      qdf_mem_copy((void *)(a2 + 1149), v10 + 1219, 0x22u);
    }
    if ( v10[1214] )
    {
      *(_BYTE *)(a2 + 2478) = 1;
      qdf_mem_copy((void *)(a2 + 1144), v10 + 1214, 5u);
    }
    if ( v10[2372] )
    {
      *(_BYTE *)(a2 + 2477) = 1;
      qdf_mem_copy((void *)(a2 + 1142), v10 + 2372, 2u);
    }
    if ( v10[836] )
    {
      *(_BYTE *)(a2 + 2479) = 1;
      qdf_mem_copy((void *)(a2 + 1190), v10 + 836, 8u);
    }
    if ( v10[1256] )
      qdf_mem_copy((void *)(a2 + 1200), v10 + 1256, 0x3Cu);
    if ( v10[1316] )
      qdf_mem_copy((void *)(a2 + 1260), v10 + 1316, 0x3Au);
    if ( (v10[2315] & 0x20) != 0 )
    {
      v50 = wlan_reg_chan_band_to_freq(
              *(_QWORD *)(a1 + 21632),
              (unsigned __int8)v10[2324],
              4u,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46);
    }
    else
    {
      if ( v10[56] )
      {
        *(_BYTE *)(a2 + 2465) = 1;
        v48 = *(_QWORD *)(a1 + 21632);
        v49 = (unsigned __int8)v10[57];
      }
      else
      {
        if ( !v10[1316] )
        {
LABEL_68:
          if ( v10[863] )
          {
            *(_BYTE *)(a2 + 2474) = 1;
            convert_rsn_opaque(a1, a2 + 876, v10 + 863);
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: RSN IE is not present",
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              "sir_parse_beacon_ie");
          }
          if ( v10[3374] )
          {
            *(_BYTE *)(a2 + 2473) = 1;
            convert_wpa(a1, a2 + 620, v10 + 3374);
          }
          if ( v10[3426] )
          {
            *(_BYTE *)(a2 + 2469) = 1;
            convert_wmm_params(a1, a2 + 337, v10 + 3426);
            qdf_mem_copy((void *)(a2 + 6640), v10 + 3426, 0x14u);
          }
          if ( v10[3422] )
            *(_BYTE *)(a2 + 2470) = 1;
          if ( v10[3446] )
            *(_BYTE *)(a2 + 2471) = 1;
          if ( v10[847] )
          {
            *(_BYTE *)(a2 + 2475) = 1;
            convert_erp_info(a1, a2 + 1132, v10 + 847);
          }
          if ( v10[1408] )
          {
            *(_BYTE *)(a2 + 2484) = 1;
            qdf_mem_copy((void *)(a2 + 2484), v10 + 1408, 0x10u);
          }
          if ( v10[1424] )
          {
            *(_BYTE *)(a2 + 2500) = 1;
            qdf_mem_copy((void *)(a2 + 2500), v10 + 1424, 6u);
          }
          if ( v10[1880] )
          {
            *(_BYTE *)(a2 + 2506) = 1;
            qdf_mem_copy((void *)(a2 + 2506), v10 + 1880, 6u);
          }
          if ( v10[1886] )
          {
            *(_BYTE *)(a2 + 2529) = 1;
            qdf_mem_copy((void *)(a2 + 2529), v10 + 1886, 2u);
          }
          if ( v10[1208] )
          {
            *(_BYTE *)(a2 + 2482) = 1;
            qdf_mem_copy((void *)(a2 + 2446), v10 + 1210, 3u);
          }
          *(_BYTE *)(a2 + 2536) = v10[4868];
          *(_BYTE *)(a2 + 2568) = v10[4900];
          v59 = (unsigned __int8)v10[4872];
          *(_BYTE *)(a2 + 2540) = v59;
          if ( v59 )
            *(_BYTE *)(a2 + 2541) = v10[4873];
          if ( v10[4876] )
          {
            *(_BYTE *)(a2 + 2544) = 1;
            qdf_mem_copy((void *)(a2 + 2544), v10 + 4876, 0x10u);
          }
          if ( v10[4892] )
          {
            *(_BYTE *)(a2 + 2560) = 1;
            qdf_mem_copy((void *)(a2 + 2560), v10 + 4892, 6u);
          }
          if ( v10[1390] )
            qdf_mem_copy((void *)(a2 + 2512), v10 + 1390, 0x11u);
          if ( v10[4902] )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: HS20 Indication Element Present, rel#:%u, id:%u",
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              "sir_parse_beacon_ie",
              (unsigned __int8)v10[4903] >> 4,
              ((unsigned __int8)v10[4903] >> 1) & 3);
            qdf_mem_copy((void *)(a2 + 2570), v10 + 4902, 2u);
            if ( (v10[4903] & 6) != 0 )
              qdf_mem_copy((void *)(a2 + 2572), v10 + 4904, 2u);
          }
          if ( v10[4910] )
          {
            *(_BYTE *)(a2 + 2592) = 1;
            if ( v10[5170] )
              *(_BYTE *)(a2 + 2593) = v10[5171];
            if ( v10[5172] )
            {
              *(_BYTE *)(a2 + 2594) = 1;
              *(_BYTE *)(a2 + 2595) = v10[5173];
            }
          }
          if ( v10[5192] )
            qdf_mem_copy((void *)(a2 + 2596), v10 + 5192, 0x2Cu);
          if ( v10[2252] )
            qdf_mem_copy((void *)(a2 + 2640), v10 + 2252, 0x3Cu);
          if ( v10[2312] )
            qdf_mem_copy((void *)(a2 + 2700), v10 + 2312, 0x12u);
          if ( v10[2496] )
            qdf_mem_copy((void *)(a2 + 2740), v10 + 2496, 0x5Cu);
          if ( v10[2588] )
            qdf_mem_copy((void *)(a2 + 2832), v10 + 2588, 0xCu);
          if ( v10[2351] )
            qdf_mem_copy((void *)(a2 + 2844), v10 + 2351, 3u);
          v32 = 0;
          goto LABEL_15;
        }
        v48 = *(_QWORD *)(a1 + 21632);
        v49 = (unsigned __int8)v10[1317];
      }
      v50 = wlan_reg_legacy_chan_to_freq(v48, v49, v39, v40, v41, v42, v43, v44, v45, v46);
    }
    *(_DWORD *)(a2 + 72) = v50;
    goto LABEL_68;
  }
  v32 = 2;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return v32;
}
