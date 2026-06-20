__int64 __fastcall sir_parse_beacon_ie(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  _BYTE *v8; // x0
  _BYTE *v9; // x19
  __int64 v10; // x5
  __int64 v11; // x6
  __int64 v12; // x7
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w20
  __int64 v31; // x23
  __int64 v32; // x0
  unsigned int v33; // w1
  int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w8

  qdf_mem_set((void *)a2, 0xD80u, 0);
  v8 = (_BYTE *)_qdf_mem_malloc(0x1490u, "sir_parse_beacon_ie", 5470);
  if ( v8 )
  {
    v9 = v8;
    qdf_mem_set(v8, 0x1490u, 0);
    v13 = dot11f_unpack_beacon_i_es(a1, a3, a4, (__int64)v9, 0, v10, v11, v12);
    if ( (v13 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to parse Beacon IEs (0x%08x, %d bytes):",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "sir_parse_beacon_ie",
        v13,
        a4);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 2, a3, a4);
      v30 = 16;
LABEL_108:
      _qdf_mem_free((__int64)v9);
      return v30;
    }
    if ( v13 )
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: warnings (0x%08x, %d bytes):",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "sir_parse_beacon_ie",
        v13,
        a4);
    if ( *v9 )
    {
      *(_BYTE *)(a2 + 2460) = 1;
      convert_ssid(a1, a2 + 12, v9);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Mandatory IE SSID not present!",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "sir_parse_beacon_ie");
    }
    if ( v9[34] )
    {
      *(_BYTE *)(a2 + 2461) = 1;
      convert_supp_rates(a1, a2 + 46, v9 + 34);
    }
    else
    {
      v31 = jiffies;
      if ( sir_parse_beacon_ie___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Mandatory IE Supported Rates not present!",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "sir_parse_beacon_ie");
        sir_parse_beacon_ie___last_ticks = v31;
      }
    }
    if ( v9[849] )
    {
      *(_BYTE *)(a2 + 2462) = 1;
      convert_ext_supp_rates(a1, a2 + 59, v9 + 849);
    }
    if ( v9[58] )
    {
      *(_BYTE *)(a2 + 2464) = 1;
      convert_cf_params(a1, a2 + 76, v9 + 58);
    }
    if ( v9[66] )
    {
      *(_BYTE *)(a2 + 2466) = 1;
      convert_tim(a1, a2 + 82, v9 + 66);
    }
    if ( v9[322] )
    {
      *(_BYTE *)(a2 + 2472) = 1;
      convert_country(a1, a2 + 364);
    }
    if ( v9[844] )
    {
      *(_BYTE *)(a2 + 2480) = 1;
      qdf_mem_copy((void *)(a2 + 1135), v9 + 844, 3u);
    }
    if ( v9[830] )
    {
      *(_BYTE *)(a2 + 2481) = 1;
      qdf_mem_copy((void *)(a2 + 1133), v9 + 830, 2u);
    }
    if ( v9[3449] )
      *(_BYTE *)(a2 + 2574) = 1;
    if ( v9[2486] )
    {
      *(_BYTE *)(a2 + 2449) = 1;
      *(_BYTE *)(a2 + 2450) = v9[2487];
    }
    if ( v9[1118] )
      qdf_mem_copy((void *)(a2 + 2452), v9 + 1118, 8u);
    if ( v9[1126] )
    {
      *(_BYTE *)(a2 + 2467) = 1;
      convert_edca_param(a1, a2 + 337, v9 + 1126);
    }
    if ( v9[1146] )
    {
      *(_BYTE *)(a2 + 2468) = 1;
      convert_qos_caps(a1, a2 + 361, v9 + 1146);
    }
    if ( v9[832] )
    {
      *(_BYTE *)(a2 + 2476) = 1;
      qdf_mem_copy((void *)(a2 + 1138), v9 + 832, 4u);
    }
    if ( v9[1219] )
    {
      *(_BYTE *)(a2 + 2463) = 1;
      qdf_mem_copy((void *)(a2 + 1149), v9 + 1219, 0x22u);
    }
    if ( v9[1214] )
    {
      *(_BYTE *)(a2 + 2478) = 1;
      qdf_mem_copy((void *)(a2 + 1144), v9 + 1214, 5u);
    }
    if ( v9[2372] )
    {
      *(_BYTE *)(a2 + 2477) = 1;
      qdf_mem_copy((void *)(a2 + 1142), v9 + 2372, 2u);
    }
    if ( v9[836] )
    {
      *(_BYTE *)(a2 + 2479) = 1;
      qdf_mem_copy((void *)(a2 + 1190), v9 + 836, 8u);
    }
    if ( v9[1256] )
      qdf_mem_copy((void *)(a2 + 1200), v9 + 1256, 0x3Cu);
    if ( v9[1316] )
      qdf_mem_copy((void *)(a2 + 1260), v9 + 1316, 0x3Au);
    if ( (v9[2315] & 0x20) != 0 )
    {
      v34 = wlan_reg_chan_band_to_freq(
              *(_QWORD *)(a1 + 21560),
              (unsigned __int8)v9[2324],
              4u,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29);
    }
    else
    {
      if ( v9[56] )
      {
        *(_BYTE *)(a2 + 2465) = 1;
        v32 = *(_QWORD *)(a1 + 21560);
        v33 = (unsigned __int8)v9[57];
      }
      else
      {
        if ( !v9[1316] )
          goto LABEL_58;
        v32 = *(_QWORD *)(a1 + 21560);
        v33 = (unsigned __int8)v9[1317];
      }
      v34 = wlan_reg_legacy_chan_to_freq(v32, v33, v22, v23, v24, v25, v26, v27, v28, v29);
    }
    *(_DWORD *)(a2 + 72) = v34;
LABEL_58:
    if ( v9[863] )
    {
      *(_BYTE *)(a2 + 2474) = 1;
      convert_rsn_opaque(a1, a2 + 876, v9 + 863);
      if ( !v9[3374] )
      {
LABEL_61:
        if ( v9[3426] )
        {
          *(_BYTE *)(a2 + 2469) = 1;
          convert_wmm_params(a1, a2 + 337, v9 + 3426);
          qdf_mem_copy((void *)(a2 + 3436), v9 + 3426, 0x14u);
        }
        if ( v9[3422] )
          *(_BYTE *)(a2 + 2470) = 1;
        if ( v9[3446] )
          *(_BYTE *)(a2 + 2471) = 1;
        if ( v9[847] )
        {
          *(_BYTE *)(a2 + 2475) = 1;
          convert_erp_info(a1, a2 + 1132, v9 + 847);
        }
        if ( v9[1408] )
        {
          *(_BYTE *)(a2 + 2484) = 1;
          qdf_mem_copy((void *)(a2 + 2484), v9 + 1408, 0x10u);
        }
        if ( v9[1424] )
        {
          *(_BYTE *)(a2 + 2500) = 1;
          qdf_mem_copy((void *)(a2 + 2500), v9 + 1424, 6u);
        }
        if ( v9[1880] )
        {
          *(_BYTE *)(a2 + 2506) = 1;
          qdf_mem_copy((void *)(a2 + 2506), v9 + 1880, 6u);
        }
        if ( v9[1886] )
        {
          *(_BYTE *)(a2 + 2529) = 1;
          qdf_mem_copy((void *)(a2 + 2529), v9 + 1886, 2u);
        }
        if ( v9[1208] )
        {
          *(_BYTE *)(a2 + 2482) = 1;
          qdf_mem_copy((void *)(a2 + 2446), v9 + 1210, 3u);
        }
        *(_BYTE *)(a2 + 2536) = v9[4868];
        *(_BYTE *)(a2 + 2568) = v9[4900];
        v43 = (unsigned __int8)v9[4872];
        *(_BYTE *)(a2 + 2540) = v43;
        if ( v43 )
          *(_BYTE *)(a2 + 2541) = v9[4873];
        if ( v9[4876] )
        {
          *(_BYTE *)(a2 + 2544) = 1;
          qdf_mem_copy((void *)(a2 + 2544), v9 + 4876, 0x10u);
        }
        if ( v9[4892] )
        {
          *(_BYTE *)(a2 + 2560) = 1;
          qdf_mem_copy((void *)(a2 + 2560), v9 + 4892, 6u);
        }
        if ( v9[1390] )
          qdf_mem_copy((void *)(a2 + 2512), v9 + 1390, 0x11u);
        if ( v9[4902] )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: HS20 Indication Element Present, rel#:%u, id:%u",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "sir_parse_beacon_ie",
            (unsigned __int8)v9[4903] >> 4,
            ((unsigned __int8)v9[4903] >> 1) & 3);
          qdf_mem_copy((void *)(a2 + 2570), v9 + 4902, 2u);
          if ( (v9[4903] & 6) != 0 )
            qdf_mem_copy((void *)(a2 + 2572), v9 + 4904, 2u);
        }
        if ( v9[4910] )
        {
          *(_BYTE *)(a2 + 2592) = 1;
          if ( v9[5170] )
            *(_BYTE *)(a2 + 2593) = v9[5171];
          if ( v9[5172] )
          {
            *(_BYTE *)(a2 + 2594) = 1;
            *(_BYTE *)(a2 + 2595) = v9[5173];
          }
        }
        if ( v9[5192] )
          qdf_mem_copy((void *)(a2 + 2596), v9 + 5192, 0x2Cu);
        if ( v9[2252] )
          qdf_mem_copy((void *)(a2 + 2640), v9 + 2252, 0x3Cu);
        if ( v9[2312] )
          qdf_mem_copy((void *)(a2 + 2700), v9 + 2312, 0x12u);
        if ( v9[2496] )
          qdf_mem_copy((void *)(a2 + 2740), v9 + 2496, 0x5Cu);
        if ( v9[2588] )
          qdf_mem_copy((void *)(a2 + 2832), v9 + 2588, 0xCu);
        if ( v9[2351] )
          qdf_mem_copy((void *)(a2 + 2844), v9 + 2351, 3u);
        v30 = 0;
        goto LABEL_108;
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: RSN IE is not present",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "sir_parse_beacon_ie");
      if ( !v9[3374] )
        goto LABEL_61;
    }
    *(_BYTE *)(a2 + 2473) = 1;
    convert_wpa(a1, a2 + 620, v9 + 3374);
    goto LABEL_61;
  }
  return 2;
}
