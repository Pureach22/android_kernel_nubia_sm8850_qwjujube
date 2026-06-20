__int64 __fastcall lim_extract_ap_capability(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int16 a3,
        char *a4,
        _BYTE *a5,
        _BYTE *a6,
        __int64 a7,
        char *a8)
{
  __int64 v16; // x0
  __int64 v17; // x19
  int v18; // w25
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w20
  __int64 v30; // x24
  char v31; // w10
  int v32; // w8
  unsigned int v33; // w27
  __int16 v34; // w11
  _BYTE *v35; // x24
  bool is_24ghz_ch_freq; // w0
  __int64 v37; // x9
  unsigned int v38; // w8
  char v39; // w24
  char v40; // w8
  char nss_supported_by_ap; // w0
  char v42; // w8
  int v43; // w8
  __int64 v44; // x5
  int v45; // w9
  __int64 v46; // x4
  char v47; // w7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  char v64; // w8
  const char *v65; // x2
  unsigned int v66; // w8
  char v67; // w10
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x0
  unsigned int v77; // w8
  int v78; // w9
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  char v87; // w8
  __int64 v88; // x9
  __int64 v89; // x9
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  char v91; // w8
  bool v92; // zf
  char v93; // w8
  unsigned int v94; // w8
  unsigned __int8 v95; // w8
  unsigned int vht_ch_width; // w8
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  unsigned int v105; // w11
  unsigned __int8 v106; // w10
  int v107; // w9
  char v109; // w8
  unsigned __int8 v110; // w24
  _BYTE *v111; // x25
  __int64 v112; // x0
  unsigned __int8 v113; // w9
  _BYTE *v114; // x24
  char v115; // w8
  char v116; // w0
  int v117; // w8
  char _80Mhz_center_channel; // w0
  char v119; // [xsp+Ch] [xbp-24h]
  unsigned __int8 v120; // [xsp+10h] [xbp-20h]
  _BYTE *v121; // [xsp+28h] [xbp-8h]

  v16 = _qdf_mem_malloc(0x1A08u, "lim_extract_ap_capability", 618);
  if ( !v16 )
    return 2;
  *a4 = 0;
  v17 = v16;
  *a5 = 0;
  v18 = *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(a7 + 8608) + 8LL) + 3531LL);
  v19 = sir_parse_beacon_ie(a1, v16);
  if ( (_DWORD)v19 )
  {
    v28 = v19;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: sir_parse_beacon_ie failed to parse beacon",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "lim_extract_ap_capability");
    _qdf_mem_free(v17);
    return v28;
  }
  v121 = a6;
  v30 = *(_QWORD *)(a1 + 8);
  if ( *(_BYTE *)(v17 + 2470) || *(_BYTE *)(v17 + 2469) || *(_BYTE *)(v17 + 1200) )
  {
    v31 = *a4 | 2;
    *a4 = v31;
  }
  else
  {
    v31 = *a4;
  }
  if ( (v31 & 2) != 0 && *(_BYTE *)(v17 + 2471) )
    *a4 = v31 | 4;
  *(_BYTE *)(a1 + 12209) = *(_BYTE *)(v17 + 1200) != 0;
  if ( *(_BYTE *)(v17 + 2484)
    && *(__int16 *)(v17 + 2490) != -1
    && *(__int16 *)(v17 + 2494) != -1
    && *(_BYTE *)(v17 + 2500)
    && *(_BYTE *)(a7 + 7170) )
  {
    *(_BYTE *)(a7 + 7173) = 1;
    if ( *(_BYTE *)(v17 + 2536) )
    {
      if ( *(_BYTE *)(v17 + 2540) )
      {
        if ( *(_BYTE *)(v17 + 2568) )
        {
          v32 = *(unsigned __int16 *)(v17 + 2494);
          if ( (~v32 & 0x30) == 0 && (v32 & 0xC) != 0xC )
            *(_DWORD *)(a7 + 7268) &= ~0x1000u;
        }
      }
    }
    if ( *(_BYTE *)(a7 + 160) )
    {
      v33 = *(unsigned __int8 *)(v17 + 2501);
      if ( *(_BYTE *)(v17 + 2501) )
      {
        if ( (*(_WORD *)(v17 + 2496) & 0x2000) != 0 && (*(_WORD *)(v17 + 2488) & 0x180) != 0 )
          v34 = *(_WORD *)(v17 + 1264);
        else
          LOBYTE(v34) = *(_BYTE *)(v17 + 2503);
        if ( (_BYTE)v34 )
          v92 = v33 == 1;
        else
          v92 = 0;
        v93 = v92;
        v119 = v93;
        if ( v92 )
        {
          v94 = *(unsigned __int8 *)(v17 + 2502);
          if ( v94 >= (unsigned __int8)v34 )
            v95 = v94 - v34;
          else
            v95 = v34 - v94;
          if ( v95 == 8 )
          {
            v33 = 2;
          }
          else if ( v95 <= 0x10u )
          {
            v33 = 1;
          }
          else
          {
            v33 = 3;
          }
        }
        v120 = v34;
        vht_ch_width = (unsigned __int8)wma_get_vht_ch_width(v19);
        if ( vht_ch_width >= v33 )
          v105 = v33;
        else
          v105 = vht_ch_width;
        if ( v33 == 3 && v105 >= 2 && *(_BYTE *)(v30 + 2888) == 1 )
        {
          v106 = v120;
          v107 = *(unsigned __int8 *)(v17 + 2502);
          if ( v120 == 138 && v107 == 155 )
          {
            LOBYTE(v105) = 3;
          }
          else if ( v107 == 138 && v120 == 155 )
          {
            LOBYTE(v105) = 3;
          }
          else
          {
            LOBYTE(v105) = 2;
          }
        }
        else
        {
          v106 = v120;
          if ( v105 < 2 )
            goto LABEL_161;
        }
        if ( v18 == 2
          || v18 == 1 && *(unsigned __int16 *)(v17 + 2494) <= 0xFFFBu && *(unsigned __int16 *)(v17 + 2490) <= 0xFFFBu )
        {
          v115 = *(_BYTE *)(v17 + 2502);
          *(_BYTE *)(a7 + 7186) = v106;
          v111 = (_BYTE *)(a7 + 7186);
          *(_BYTE *)(a7 + 7174) = v115;
          v114 = (_BYTE *)(a7 + 7174);
          v112 = wlan_reg_freq_to_chan(
                   *(_QWORD *)(a1 + 21632),
                   *(_DWORD *)(v17 + 72),
                   v97,
                   v98,
                   v99,
                   v100,
                   v101,
                   v102,
                   v103,
                   v104);
          goto LABEL_168;
        }
LABEL_161:
        v109 = *(_BYTE *)(v17 + 2502);
        v110 = v105;
        *(_BYTE *)(a7 + 7186) = v106;
        v111 = (_BYTE *)(a7 + 7186);
        *(_BYTE *)(a7 + 7174) = v109;
        v112 = wlan_reg_freq_to_chan(
                 *(_QWORD *)(a1 + 21632),
                 *(_DWORD *)(v17 + 72),
                 v97,
                 v98,
                 v99,
                 v100,
                 v101,
                 v102,
                 v103,
                 v104);
        if ( v110 != 1 )
        {
          v113 = v110;
          if ( v110 != 2 )
          {
LABEL_170:
            v117 = v113 + 1;
            *(_DWORD *)(a7 + 7176) = v117;
            *(_DWORD *)(a7 + 7180) = v117;
            goto LABEL_29;
          }
          if ( v33 != 2 )
          {
            *v111 = 0;
            _80Mhz_center_channel = lim_get_80Mhz_center_channel(v112);
            v113 = 1;
            *(_BYTE *)(a7 + 7174) = _80Mhz_center_channel;
            goto LABEL_170;
          }
          v114 = (_BYTE *)(a7 + 7174);
          if ( (v119 & 1) != 0 )
          {
            v113 = 2;
            goto LABEL_170;
          }
          *v111 = *(_BYTE *)(v17 + 2502);
          v116 = lim_get_80Mhz_center_channel(v112);
          v113 = 2;
LABEL_169:
          *v114 = v116;
          goto LABEL_170;
        }
        v114 = (_BYTE *)(a7 + 7174);
LABEL_168:
        v116 = lim_get_80Mhz_center_channel(v112);
        *v111 = 0;
        v113 = 1;
        goto LABEL_169;
      }
    }
    else
    {
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 2856LL) & 1) == 0 )
        *(_DWORD *)(a7 + 7268) &= ~0x1000u;
      if ( *(_DWORD *)(a7 + 7036) == 2 && !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v17 + 72)) && *(_DWORD *)(a1 + 17196) )
        lim_update_ch_width_for_p2p_client(a1, a7, *(unsigned int *)(v17 + 72));
    }
  }
  else
  {
    *(_BYTE *)(a7 + 7173) = 0;
  }
LABEL_29:
  v35 = v121;
  if ( *(_BYTE *)(a7 + 7170) && *(_BYTE *)(a7 + 7173) && *(_BYTE *)(v17 + 2512) )
  {
    *(_BYTE *)(a7 + 7171) = (*(_QWORD *)(v17 + 2514) & 0x4000000000000000LL) != 0;
    if ( (*(_BYTE *)(v17 + 2521) & 0x40) != 0 )
    {
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 284));
      v37 = 21594;
      v38 = *(_DWORD *)(a7 + 7176);
      if ( is_24ghz_ch_freq )
        v37 = 21584;
      v39 = *(_BYTE *)(a1 + v37);
      if ( v38 > 2 )
        v40 = *(_BYTE *)(a7 + 7172) & 0xF0 | 3;
      else
        v40 = *(_BYTE *)(a7 + 7172) & 0xF0 | v38;
      *(_BYTE *)(a7 + 7172) = v40;
      if ( (*(_BYTE *)(v17 + 2524) & 0x10) == 0
        || *(_DWORD *)(a7 + 7036)
        || (*(_BYTE *)(a7 + 8636) & 1) != 0
        || (nss_supported_by_ap = lim_get_nss_supported_by_ap(v17 + 2484, (_BYTE *)(v17 + 1200), v17 + 2640),
            v40 = *(_BYTE *)(a7 + 7172),
            nss_supported_by_ap != 1) )
      {
        v42 = (16 * *(_BYTE *)(a7 + 8635) + 112) & 0x70 | v40 & 0x8F;
      }
      else
      {
        v42 = v40 & 0x8F | (16 * v39 + 112) & 0x70;
      }
      v35 = v121;
      *(_BYTE *)(a7 + 7172) = v42;
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: AP does not support op_mode rx",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "lim_extract_ap_capability");
    }
  }
  v43 = *(unsigned __int8 *)(a7 + 8676);
  if ( v43 != 1 || !*(_BYTE *)(v17 + 2640) )
  {
    if ( !*(_BYTE *)(a7 + 8676) )
      goto LABEL_70;
    goto LABEL_59;
  }
  v44 = *(unsigned __int16 *)(v17 + 2660);
  if ( *(_BYTE *)(a7 + 8635) )
  {
    v45 = 0;
    while ( (~((unsigned int)v44 >> v45) & 3) == 0 )
    {
      v45 += 2;
      if ( 2 * *(unsigned __int8 *)(a7 + 8635) == v45 )
        goto LABEL_52;
    }
  }
  else
  {
LABEL_52:
    v46 = *(unsigned __int8 *)(a7 + 10);
    if ( *(_BYTE *)(a7 + 7170) )
      v47 = 8;
    else
      v47 = 5;
    *(_BYTE *)(a7 + 8676) = 0;
    *(_BYTE *)(a7 + 154) = v47;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: vdev %d: Invalid LT80 MCS map 0x%x with NSS %d, falback to dot11mode %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "lim_check_is_he_mcs_valid",
      v46,
      v44);
    LOBYTE(v43) = *(_BYTE *)(a7 + 8676);
  }
  if ( (v43 & 1) != 0 )
  {
LABEL_59:
    if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 284))
      && *(_BYTE *)(v17 + 2640)
      && (lim_check_he_80_mcs11_supp(a7, v17 + 2640) & 1) != 0
      && (*(_BYTE *)(v17 + 2648) & 0x40) == 0 )
    {
      *(_BYTE *)(a7 + 8676) = 0;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: LDPC check failed for HE operation",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "lim_check_peer_ldpc_and_update");
      if ( *(_BYTE *)(a7 + 7170) )
        v64 = 8;
      else
        v64 = 5;
      if ( *(_BYTE *)(a7 + 7170) )
        v65 = "%s: Update dot11mode to 11ac";
      else
        v65 = "%s: Update dot11mode to 11N";
      *(_BYTE *)(a7 + 154) = v64;
      qdf_trace_msg(0x35u, 8u, v65, v56, v57, v58, v59, v60, v61, v62, v63, "lim_check_peer_ldpc_and_update");
    }
  }
LABEL_70:
  if ( *(_BYTE *)(a7 + 8676) == 1 )
  {
    if ( *(_BYTE *)(v17 + 2700) )
    {
      qdf_mem_copy((void *)(a7 + 8740), (const void *)(v17 + 2700), 0x12u);
      if ( *(_BYTE *)(a7 + 8764) == 1 )
      {
        if ( (*(_BYTE *)(a7 + 8743) & 0x20) != 0 )
        {
          v66 = *(unsigned __int8 *)(a7 + 8753);
          v67 = *(_BYTE *)(a7 + 8755);
          *(_BYTE *)(a7 + 7174) = *(_BYTE *)(a7 + 8754);
          *(_DWORD *)(a7 + 7176) = v66 & 3;
          *(_BYTE *)(a7 + 7186) = v67;
          *(_BYTE *)(a7 + 10068) = (v66 >> 3) & 0xF;
          if ( (lim_is_ap_power_type_6g_invalid(a7) & 1) != 0 )
          {
            *(_BYTE *)(a7 + 10068) = 4;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: AP power type invalid, defaulting to MAX_AP_TYPE",
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              "lim_extract_he_op");
          }
          v76 = qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: 6G op info: ch_wd %d cntr_freq_seg0 %d cntr_freq_seg1 %d",
                  v68,
                  v69,
                  v70,
                  v71,
                  v72,
                  v73,
                  v74,
                  v75,
                  "lim_extract_he_op",
                  *(unsigned int *)(a7 + 7176),
                  *(unsigned __int8 *)(a7 + 7174),
                  *(unsigned __int8 *)(a7 + 7186));
          if ( *(_BYTE *)(a7 + 7186) )
          {
            v77 = (unsigned __int8)wma_get_vht_ch_width(v76);
            if ( v77 <= 1 )
              goto LABEL_85;
            v78 = *(unsigned __int8 *)(a7 + 7186) - *(unsigned __int8 *)(a7 + 7174);
            if ( v78 < 0 )
              v78 = *(unsigned __int8 *)(a7 + 7174) - *(unsigned __int8 *)(a7 + 7186);
            if ( (unsigned int)v78 <= 0x10 && v78 != 8 || v77 != 3 && v78 != 8 )
            {
LABEL_85:
              *(_BYTE *)(a7 + 7186) = 0;
              *(_DWORD *)(a7 + 7176) = 2;
            }
          }
        }
        else
        {
          *(_BYTE *)(a7 + 10068) = 4;
        }
      }
    }
  }
  lim_extract_eht_op(a7, v17);
  if ( (*(_BYTE *)(a1 + 21785) & 1) == 0 )
    lim_update_he_bw_cap_mcs(a7, v17, v79, v80, v81, v82, v83, v84, v85, v86);
  if ( *(_BYTE *)(a7 + 10071) == 1 && (*(_DWORD *)(a7 + 7036) & 0xFFFFFFFD) == 0 && *(_BYTE *)(v17 + 2740) )
  {
    v89 = *(_QWORD *)(v17 + 2741);
    if ( (v89 & 0x20000) == 0 )
    {
      *(_QWORD *)(a7 + 10073) &= ~0x20000uLL;
      v89 = *(_QWORD *)(v17 + 2741);
    }
    if ( (~(_DWORD)v89 & 0x220000) != 0 )
      *(_QWORD *)(a7 + 10073) &= 0xFFFFFC7FFFFFFFFFLL;
  }
  if ( *(_BYTE *)(v17 + 2469) )
    *a5 = *(_BYTE *)(v17 + 339) >> 7;
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3538LL) != 1 )
    goto LABEL_104;
  v87 = *(_BYTE *)(v17 + 2481);
  if ( v87 )
  {
    v87 = 1;
    v88 = 1134;
LABEL_102:
    *v35 = *(_BYTE *)(v17 + v88);
    goto LABEL_103;
  }
  if ( *(_BYTE *)(v17 + 2449) )
  {
    v88 = 2450;
    goto LABEL_102;
  }
LABEL_103:
  *a8 = v87;
LABEL_104:
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1766LL) == 1 )
    *(_BYTE *)(a7 + 8624) = *(_BYTE *)(v17 + 2574);
  *(_BYTE *)(a7 + 8634) = 0;
  *(_BYTE *)(a7 + 8634) = *(_BYTE *)(v17 + 2472) != 0;
  if ( *(_BYTE *)(v17 + 2512) )
    *(_BYTE *)(a7 + 8654) = 1;
  if ( *(_BYTE *)(v17 + 2570) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: HS20 Indication Element Present, rel#: %u id: %u",
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      "lim_extract_ap_capability",
      *(unsigned __int8 *)(v17 + 2571) >> 4,
      (*(unsigned __int8 *)(v17 + 2571) >> 1) & 3);
    qdf_mem_copy((void *)(a7 + 8630), (const void *)(v17 + 2570), 2u);
    if ( (*(_BYTE *)(v17 + 2571) & 6) != 0 )
      qdf_mem_copy((void *)(a7 + 8632), (const void *)(v17 + 2572), 2u);
  }
  lim_objmgr_update_vdev_nss(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a7 + 10), *(_BYTE *)(a7 + 8635));
  vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(&unk_AFC158, 4u, a2, a3);
  if ( vendor_ie_ptr_from_oui && (unsigned int)vendor_ie_ptr_from_oui[1] - 9 >= 0xFFFFFFFC )
    v91 = vendor_ie_ptr_from_oui[6] & 1;
  else
    v91 = 0;
  *(_BYTE *)(a7 + 7042) = v91;
  _qdf_mem_free(v17);
  return 0;
}
