__int64 __fastcall sir_convert_probe_frame2_struct(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 v8; // x0
  __int64 v9; // x5
  __int64 v10; // x6
  __int64 v11; // x7
  char *v12; // x19
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x25
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  __int64 v40; // x25
  __int64 v41; // x0
  unsigned int v42; // w1
  int v43; // w0
  __int64 v44; // x4
  __int64 v45; // x5
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int v54; // w8
  void *v55; // x21
  void *v56; // x22
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  char *v65; // x20
  __int64 v66; // x26
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  size_t v84; // x2
  void *v85; // x0
  const char *v86; // x25
  int v87[2]; // [xsp+0h] [xbp-150h] BYREF
  __int64 v88; // [xsp+8h] [xbp-148h]
  __int64 v89; // [xsp+10h] [xbp-140h]
  __int64 v90; // [xsp+18h] [xbp-138h]
  __int64 v91; // [xsp+20h] [xbp-130h]
  __int64 v92; // [xsp+28h] [xbp-128h]
  int v93; // [xsp+30h] [xbp-120h]
  _QWORD s[35]; // [xsp+38h] [xbp-118h] BYREF

  s[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_mem_set((void *)a4, 0x1A08u, 0);
  v8 = _qdf_mem_malloc(0x13A8u, "sir_convert_probe_frame2_struct", 3346);
  if ( !v8 )
  {
    result = 2;
    goto LABEL_115;
  }
  v12 = (char *)v8;
  v13 = dot11f_unpack_probe_response(a1, a2, a3, v8, 0, v9, v10, v11);
  if ( (v13 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to parse a Probe Response (0x%08x, %d bytes):",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "sir_convert_probe_frame2_struct",
      v13,
      a3);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 8, a2, a3);
    _qdf_mem_free((__int64)v12);
    result = 16;
    goto LABEL_115;
  }
  if ( v13 )
  {
    v22 = jiffies;
    if ( sir_convert_probe_frame2_struct___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Warned to parse a Probe Response (0x%08x, %d bytes) ch %d %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "sir_convert_probe_frame2_struct");
      sir_convert_probe_frame2_struct___last_ticks = v22;
    }
  }
  qdf_mem_copy((void *)a4, v12, 8u);
  *(_WORD *)(a4 + 8) = *((_WORD *)v12 + 4);
  *(_WORD *)(a4 + 10) = *((_WORD *)v12 + 5);
  if ( v12[12] )
  {
    *(_BYTE *)(a4 + 2460) = 1;
    convert_ssid(a1, a4 + 12, v12 + 12);
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
      "sir_convert_probe_frame2_struct");
  }
  if ( v12[46] )
  {
    *(_BYTE *)(a4 + 2461) = 1;
    convert_supp_rates(a1, a4 + 46, v12 + 46);
  }
  else
  {
    v40 = jiffies;
    if ( sir_convert_probe_frame2_struct___last_ticks_49 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Mandatory IE Supported Rates not present!",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "sir_convert_probe_frame2_struct");
      sir_convert_probe_frame2_struct___last_ticks_49 = v40;
    }
  }
  if ( v12[605] )
  {
    *(_BYTE *)(a4 + 2462) = 1;
    convert_ext_supp_rates(a1, a4 + 59, v12 + 605);
  }
  if ( v12[70] )
  {
    *(_BYTE *)(a4 + 2464) = 1;
    convert_cf_params(a1, a4 + 76, v12 + 70);
  }
  if ( v12[78] )
  {
    *(_BYTE *)(a4 + 2472) = 1;
    convert_country(a1, a4 + 364);
  }
  if ( v12[882] )
  {
    *(_BYTE *)(a4 + 2467) = 1;
    convert_edca_param(a1, a4 + 337, v12 + 882);
  }
  if ( v12[588] )
  {
    *(_BYTE *)(a4 + 2476) = 1;
    qdf_mem_copy((void *)(a4 + 1138), v12 + 588, 4u);
  }
  if ( v12[968] )
  {
    *(_BYTE *)(a4 + 2478) = 1;
    qdf_mem_copy((void *)(a4 + 1144), v12 + 968, 5u);
  }
  if ( v12[973] )
  {
    *(_BYTE *)(a4 + 2463) = 1;
    qdf_mem_copy((void *)(a4 + 1149), v12 + 973, 0x22u);
  }
  if ( v12[2120] )
  {
    *(_BYTE *)(a4 + 2477) = 1;
    qdf_mem_copy((void *)(a4 + 1142), v12 + 2120, 2u);
  }
  if ( v12[600] )
  {
    *(_BYTE *)(a4 + 2480) = 1;
    qdf_mem_copy((void *)(a4 + 1135), v12 + 600, 3u);
  }
  if ( v12[586] )
  {
    *(_BYTE *)(a4 + 2481) = 1;
    qdf_mem_copy((void *)(a4 + 1133), v12 + 586, 2u);
  }
  if ( v12[592] )
  {
    *(_BYTE *)(a4 + 2479) = 1;
    qdf_mem_copy((void *)(a4 + 1190), v12 + 592, 8u);
  }
  if ( v12[1008] )
    qdf_mem_copy((void *)(a4 + 1200), v12 + 1008, 0x3Cu);
  if ( v12[1068] )
    qdf_mem_copy((void *)(a4 + 1260), v12 + 1068, 0x3Au);
  if ( (v12[2063] & 0x20) != 0 )
  {
    v43 = wlan_reg_chan_band_to_freq(
            *(_QWORD *)(a1 + 21632),
            (unsigned __int8)v12[2072],
            4u,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38);
LABEL_48:
    *(_DWORD *)(a4 + 72) = v43;
    goto LABEL_49;
  }
  if ( v12[68] )
  {
    *(_BYTE *)(a4 + 2465) = 1;
    v41 = *(_QWORD *)(a1 + 21632);
    v42 = (unsigned __int8)v12[69];
LABEL_47:
    v43 = wlan_reg_legacy_chan_to_freq(v41, v42, v31, v32, v33, v34, v35, v36, v37, v38);
    goto LABEL_48;
  }
  if ( v12[1068] )
  {
    v41 = *(_QWORD *)(a1 + 21632);
    v42 = (unsigned __int8)v12[1069];
    goto LABEL_47;
  }
LABEL_49:
  if ( v12[619] )
  {
    *(_BYTE *)(a4 + 2474) = 1;
    convert_rsn_opaque(a1, a4 + 876, v12 + 619);
  }
  if ( v12[3118] )
  {
    *(_BYTE *)(a4 + 2473) = 1;
    convert_wpa(a1, a4 + 620, v12 + 3118);
  }
  if ( v12[3170] )
  {
    *(_BYTE *)(a4 + 2469) = 1;
    convert_wmm_params(a1, a4 + 337, v12 + 3170);
  }
  if ( v12[3166] )
  {
    *(_BYTE *)(a4 + 2470) = 1;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: WMM Information Element present in Probe Response Frame!",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "sir_convert_probe_frame2_struct");
  }
  if ( v12[3190] )
    *(_BYTE *)(a4 + 2471) = 1;
  if ( v12[603] )
  {
    *(_BYTE *)(a4 + 2475) = 1;
    convert_erp_info(a1, a4 + 1132, v12 + 603);
  }
  if ( v12[962] )
  {
    *(_BYTE *)(a4 + 2482) = 1;
    qdf_mem_copy((void *)(a4 + 2446), v12 + 964, 2u);
    v44 = *(unsigned __int8 *)(a4 + 2446);
    v45 = *(unsigned __int8 *)(a4 + 2447);
    *(_BYTE *)(a4 + 2448) = v12[966] & 3;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: mdie=%02x%02x%02x",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "sir_convert_probe_frame2_struct",
      v44,
      v45);
  }
  if ( v12[3193] )
    *(_BYTE *)(a4 + 2574) = 1;
  if ( v12[874] )
    qdf_mem_copy((void *)(a4 + 2452), v12 + 874, 8u);
  if ( v12[3476] )
    qdf_mem_copy((void *)(a4 + 1318), v12 + 3476, 0x468u);
  if ( v12[1160] )
    qdf_mem_copy((void *)(a4 + 2484), v12 + 1160, 0x10u);
  if ( v12[1176] )
    qdf_mem_copy((void *)(a4 + 2500), v12 + 1176, 6u);
  if ( v12[1632] )
    qdf_mem_copy((void *)(a4 + 2506), v12 + 1632, 6u);
  *(_BYTE *)(a4 + 2536) = v12[4604];
  *(_BYTE *)(a4 + 2568) = v12[4636];
  v54 = (unsigned __int8)v12[4608];
  *(_BYTE *)(a4 + 2540) = v54;
  if ( v54 )
    *(_BYTE *)(a4 + 2541) = v12[4609];
  if ( v12[4612] )
    qdf_mem_copy((void *)(a4 + 2544), v12 + 4612, 0x10u);
  if ( v12[4628] )
    qdf_mem_copy((void *)(a4 + 2560), v12 + 4628, 6u);
  if ( v12[4638] )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: HS20 Indication Element Present, rel#:%u, id:%u",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "sir_convert_probe_frame2_struct",
      (unsigned __int8)v12[4639] >> 4,
      ((unsigned __int8)v12[4639] >> 1) & 3);
    qdf_mem_copy((void *)(a4 + 2570), v12 + 4638, 2u);
    if ( (v12[4639] & 6) != 0 )
      qdf_mem_copy((void *)(a4 + 2572), v12 + 4640, 2u);
  }
  if ( v12[4646] )
  {
    *(_BYTE *)(a4 + 2592) = 1;
    if ( v12[4906] )
      *(_BYTE *)(a4 + 2593) = v12[4907];
    if ( v12[4908] )
    {
      *(_BYTE *)(a4 + 2594) = 1;
      *(_BYTE *)(a4 + 2595) = v12[4909];
    }
  }
  if ( v12[4928] )
    qdf_mem_copy((void *)(a4 + 2596), v12 + 4928, 0x2Cu);
  if ( v12[2000] )
    qdf_mem_copy((void *)(a4 + 2640), v12 + 2000, 0x3Cu);
  if ( v12[2060] )
    qdf_mem_copy((void *)(a4 + 2700), v12 + 2060, 0x12u);
  if ( v12[2240] )
    qdf_mem_copy((void *)(a4 + 2740), v12 + 2240, 0x5Cu);
  if ( v12[2099] )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: 11AX: HE BSS color change present",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "update_bss_color_change_ie_from_probe_rsp");
    qdf_mem_copy((void *)(a4 + 2844), v12 + 2099, 3u);
  }
  if ( v12[2344] )
  {
    s[0] = 0;
    *(_QWORD *)v87 = 0;
    if ( !(unsigned int)util_find_mlie(a2 + 12, a3 - 12, s, v87) )
      sir_convert_mlo_probe_rsp_frame2_struct(s[0], v87[0], a4 + 3436);
  }
  memset(s, 0, 0x102u);
  v55 = (void *)(a4 + 5796);
  v93 = 0;
  v91 = 0;
  v92 = 0;
  v89 = 0;
  v90 = 0;
  *(_QWORD *)v87 = 0;
  v88 = 0;
  qdf_mem_set((void *)(a4 + 5796), 0x34u, 0);
  v56 = (void *)(a4 + 5852);
  *(_DWORD *)(a4 + 5796) = 4;
  qdf_mem_set((void *)(a4 + 5852), 0x34u, 0);
  *(_DWORD *)(a4 + 5852) = 4;
  if ( *((_WORD *)v12 + 1301) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Number of T2LM IEs in probe rsp %d",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "sir_convert_probe_frame2_t2lm_struct");
    if ( *((_WORD *)v12 + 1301) )
    {
      v65 = v12 + 2606;
      v66 = 1;
      while ( 1 )
      {
        qdf_mem_set(s, 0x102u, 0);
        qdf_mem_set(v87, 0x34u, 0);
        LOBYTE(s[0]) = -1;
        if ( v66 == 3 )
          __break(0x5512u);
        v84 = (unsigned __int8)*(v65 - 1);
        BYTE2(s[0]) = 109;
        BYTE1(s[0]) = v84 + 1;
        qdf_mem_copy((char *)s + 3, v65, v84);
        ((void (__fastcall *)(__int64, __int64, _QWORD *, _QWORD))qdf_trace_hex_dump)(
          53,
          8,
          s,
          (unsigned int)(unsigned __int8)*(v65 - 1) + 3);
        if ( (unsigned int)wlan_mlo_parse_t2lm_info(s, v87) )
          break;
        v85 = v56;
        v86 = "%s: Parse upcoming T2LM IE success";
        if ( (v87[1] & 0x100) != 0 || (v85 = v55, v86 = "%s: Parse established T2LM IE success", BYTE2(v87[1]) == 1) )
        {
          qdf_mem_copy(v85, v87, 0x34u);
          qdf_trace_msg(0x35u, 8u, v86, v67, v68, v69, v70, v71, v72, v73, v74, "sir_convert_probe_frame2_t2lm_struct");
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Parse T2LM IE success",
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          "sir_convert_probe_frame2_t2lm_struct");
        v65 += 257;
        if ( *((unsigned __int16 *)v12 + 1301) <= (unsigned int)(unsigned __int16)v66++ )
          goto LABEL_114;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Parse T2LM IE fail",
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        "sir_convert_probe_frame2_t2lm_struct");
    }
  }
LABEL_114:
  _qdf_mem_free((__int64)v12);
  result = 0;
LABEL_115:
  _ReadStatusReg(SP_EL0);
  return result;
}
