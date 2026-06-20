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
  __int64 v30; // x11
  char v31; // w10
  int v32; // w8
  unsigned int v33; // w27
  __int16 v34; // w12
  bool is_24ghz_ch_freq; // w0
  __int64 v36; // x9
  unsigned int v37; // w8
  char v38; // w25
  char v39; // w8
  char nss_supported_by_ap; // w0
  char v41; // w8
  int v42; // w8
  __int64 v43; // x5
  int v44; // w9
  __int64 v45; // x4
  char v46; // w7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  char v55; // w8
  const char *v56; // x2
  unsigned int v57; // w8
  char v58; // w10
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x0
  unsigned int v68; // w8
  int v69; // w9
  char v70; // w8
  __int64 v71; // x9
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  char v73; // w8
  bool v74; // zf
  char v75; // w8
  unsigned int v76; // w8
  unsigned __int8 v77; // w8
  unsigned int vht_ch_width; // w8
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned int v87; // w11
  unsigned __int8 v88; // w10
  int v89; // w9
  char v91; // w8
  _BYTE *v92; // x25
  unsigned __int8 v93; // w27
  __int64 v94; // x0
  unsigned __int8 v95; // w9
  _BYTE *v96; // x27
  char v97; // w8
  char v98; // w0
  int v99; // w8
  char _80Mhz_center_channel; // w0
  char v101; // [xsp+Ch] [xbp-24h]
  __int64 v102; // [xsp+10h] [xbp-20h]
  unsigned int v103; // [xsp+10h] [xbp-20h]
  unsigned __int8 v104; // [xsp+18h] [xbp-18h]

  v16 = _qdf_mem_malloc(0xD80u, "lim_extract_ap_capability", 618);
  if ( !v16 )
    return 2;
  *a4 = 0;
  v17 = v16;
  *a5 = 0;
  v18 = *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(a7 + 8608) + 8LL) + 3331LL);
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
        v102 = v30;
        if ( (_BYTE)v34 )
          v74 = v33 == 1;
        else
          v74 = 0;
        v75 = v74;
        v101 = v75;
        if ( v74 )
        {
          v76 = *(unsigned __int8 *)(v17 + 2502);
          if ( v76 >= (unsigned __int8)v34 )
            v77 = v76 - v34;
          else
            v77 = v34 - v76;
          if ( v77 == 8 )
          {
            v33 = 2;
          }
          else if ( v77 <= 0x10u )
          {
            v33 = 1;
          }
          else
          {
            v33 = 3;
          }
        }
        v104 = v34;
        vht_ch_width = (unsigned __int8)wma_get_vht_ch_width(v19);
        if ( vht_ch_width >= v33 )
          v87 = v33;
        else
          v87 = vht_ch_width;
        if ( v33 == 3 && v87 >= 2 && *(_BYTE *)(v102 + 2684) == 1 )
        {
          v88 = v104;
          v89 = *(unsigned __int8 *)(v17 + 2502);
          if ( v104 == 138 && v89 == 155 )
          {
            LOBYTE(v87) = 3;
          }
          else if ( v89 == 138 && v104 == 155 )
          {
            LOBYTE(v87) = 3;
          }
          else
          {
            LOBYTE(v87) = 2;
          }
        }
        else
        {
          v88 = v104;
          if ( v87 < 2 )
            goto LABEL_154;
        }
        if ( v18 == 2
          || v18 == 1 && *(unsigned __int16 *)(v17 + 2494) <= 0xFFFBu && *(unsigned __int16 *)(v17 + 2490) <= 0xFFFBu )
        {
          v97 = *(_BYTE *)(v17 + 2502);
          *(_BYTE *)(a7 + 7184) = v88;
          v92 = (_BYTE *)(a7 + 7184);
          *(_BYTE *)(a7 + 7174) = v97;
          v96 = (_BYTE *)(a7 + 7174);
          v94 = wlan_reg_freq_to_chan(
                  *(_QWORD *)(a1 + 21560),
                  *(_DWORD *)(v17 + 72),
                  v79,
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  v86);
          goto LABEL_161;
        }
LABEL_154:
        v91 = *(_BYTE *)(v17 + 2502);
        v103 = v33;
        *(_BYTE *)(a7 + 7184) = v88;
        v92 = (_BYTE *)(a7 + 7184);
        *(_BYTE *)(a7 + 7174) = v91;
        v93 = v87;
        v94 = wlan_reg_freq_to_chan(
                *(_QWORD *)(a1 + 21560),
                *(_DWORD *)(v17 + 72),
                v79,
                v80,
                v81,
                v82,
                v83,
                v84,
                v85,
                v86);
        if ( v93 != 1 )
        {
          v95 = v93;
          if ( v93 != 2 )
          {
LABEL_163:
            v99 = v95 + 1;
            *(_DWORD *)(a7 + 7176) = v99;
            *(_DWORD *)(a7 + 7180) = v99;
            goto LABEL_29;
          }
          if ( v103 != 2 )
          {
            *v92 = 0;
            _80Mhz_center_channel = lim_get_80Mhz_center_channel(v94);
            v95 = 1;
            *(_BYTE *)(a7 + 7174) = _80Mhz_center_channel;
            goto LABEL_163;
          }
          v96 = (_BYTE *)(a7 + 7174);
          if ( (v101 & 1) != 0 )
          {
            v95 = 2;
            goto LABEL_163;
          }
          *v92 = *(_BYTE *)(v17 + 2502);
          v98 = lim_get_80Mhz_center_channel(v94);
          v95 = 2;
LABEL_162:
          *v96 = v98;
          goto LABEL_163;
        }
        v96 = (_BYTE *)(a7 + 7174);
LABEL_161:
        v98 = lim_get_80Mhz_center_channel(v94);
        *v92 = 0;
        v95 = 1;
        goto LABEL_162;
      }
    }
    else
    {
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 2652LL) & 1) == 0 )
        *(_DWORD *)(a7 + 7268) &= ~0x1000u;
      if ( *(_DWORD *)(a7 + 7036) == 2 && !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v17 + 72)) && *(_DWORD *)(a1 + 17124) )
        lim_update_ch_width_for_p2p_client(a1, a7, *(unsigned int *)(v17 + 72));
    }
  }
  else
  {
    *(_BYTE *)(a7 + 7173) = 0;
  }
LABEL_29:
  if ( *(_BYTE *)(a7 + 7170) && *(_BYTE *)(a7 + 7173) && *(_BYTE *)(v17 + 2512) )
  {
    *(_BYTE *)(a7 + 7171) = (*(_QWORD *)(v17 + 2514) & 0x4000000000000000LL) != 0;
    if ( (*(_BYTE *)(v17 + 2521) & 0x40) != 0 )
    {
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 284));
      v36 = 21522;
      v37 = *(_DWORD *)(a7 + 7176);
      if ( is_24ghz_ch_freq )
        v36 = 21512;
      v38 = *(_BYTE *)(a1 + v36);
      if ( v37 > 2 )
        v39 = *(_BYTE *)(a7 + 7172) & 0xF0 | 3;
      else
        v39 = *(_BYTE *)(a7 + 7172) & 0xF0 | v37;
      *(_BYTE *)(a7 + 7172) = v39;
      if ( (*(_BYTE *)(v17 + 2524) & 0x10) == 0
        || *(_DWORD *)(a7 + 7036)
        || (*(_BYTE *)(a7 + 8636) & 1) != 0
        || (nss_supported_by_ap = lim_get_nss_supported_by_ap(v17 + 2484, (_BYTE *)(v17 + 1200), v17 + 2640),
            v39 = *(_BYTE *)(a7 + 7172),
            nss_supported_by_ap != 1) )
      {
        v41 = (16 * *(_BYTE *)(a7 + 8635) + 112) & 0x70 | v39 & 0x8F;
      }
      else
      {
        v41 = v39 & 0x8F | (16 * v38 + 112) & 0x70;
      }
      *(_BYTE *)(a7 + 7172) = v41;
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
  v42 = *(unsigned __int8 *)(a7 + 8676);
  if ( v42 != 1 || !*(_BYTE *)(v17 + 2640) )
  {
    if ( !*(_BYTE *)(a7 + 8676) )
      goto LABEL_70;
    goto LABEL_59;
  }
  v43 = *(unsigned __int16 *)(v17 + 2660);
  if ( *(_BYTE *)(a7 + 8635) )
  {
    v44 = 0;
    while ( (~((unsigned int)v43 >> v44) & 3) == 0 )
    {
      v44 += 2;
      if ( 2 * *(unsigned __int8 *)(a7 + 8635) == v44 )
        goto LABEL_52;
    }
  }
  else
  {
LABEL_52:
    v45 = *(unsigned __int8 *)(a7 + 10);
    if ( *(_BYTE *)(a7 + 7170) )
      v46 = 8;
    else
      v46 = 5;
    *(_BYTE *)(a7 + 8676) = 0;
    *(_BYTE *)(a7 + 154) = v46;
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
      v45,
      v43);
    LOBYTE(v42) = *(_BYTE *)(a7 + 8676);
  }
  if ( (v42 & 1) != 0 )
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
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "lim_check_peer_ldpc_and_update");
      if ( *(_BYTE *)(a7 + 7170) )
        v55 = 8;
      else
        v55 = 5;
      if ( *(_BYTE *)(a7 + 7170) )
        v56 = "%s: Update dot11mode to 11ac";
      else
        v56 = "%s: Update dot11mode to 11N";
      *(_BYTE *)(a7 + 154) = v55;
      qdf_trace_msg(0x35u, 8u, v56, v47, v48, v49, v50, v51, v52, v53, v54, "lim_check_peer_ldpc_and_update");
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
          v57 = *(unsigned __int8 *)(a7 + 8753);
          v58 = *(_BYTE *)(a7 + 8755);
          *(_BYTE *)(a7 + 7174) = *(_BYTE *)(a7 + 8754);
          *(_DWORD *)(a7 + 7176) = v57 & 3;
          *(_BYTE *)(a7 + 7184) = v58;
          *(_BYTE *)(a7 + 10068) = (v57 >> 3) & 0xF;
          if ( (lim_is_ap_power_type_6g_invalid(a7) & 1) != 0 )
          {
            *(_BYTE *)(a7 + 10068) = 4;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: AP power type invalid, defaulting to MAX_AP_TYPE",
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              "lim_extract_he_op");
          }
          v67 = qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: 6G op info: ch_wd %d cntr_freq_seg0 %d cntr_freq_seg1 %d",
                  v59,
                  v60,
                  v61,
                  v62,
                  v63,
                  v64,
                  v65,
                  v66,
                  "lim_extract_he_op",
                  *(unsigned int *)(a7 + 7176),
                  *(unsigned __int8 *)(a7 + 7174),
                  *(unsigned __int8 *)(a7 + 7184));
          if ( *(_BYTE *)(a7 + 7184) )
          {
            v68 = (unsigned __int8)wma_get_vht_ch_width(v67);
            if ( v68 <= 1 )
              goto LABEL_85;
            v69 = *(unsigned __int8 *)(a7 + 7184) - *(unsigned __int8 *)(a7 + 7174);
            if ( v69 < 0 )
              v69 = *(unsigned __int8 *)(a7 + 7174) - *(unsigned __int8 *)(a7 + 7184);
            if ( (unsigned int)v69 <= 0x10 && v69 != 8 || v68 != 3 && v69 != 8 )
            {
LABEL_85:
              *(_BYTE *)(a7 + 7184) = 0;
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
  if ( (*(_BYTE *)(a1 + 21713) & 1) == 0 )
    lim_update_he_bw_cap_mcs(a7, v17, v20, v21, v22, v23, v24, v25, v26, v27);
  if ( *(_BYTE *)(v17 + 2469) )
    *a5 = *(_BYTE *)(v17 + 339) >> 7;
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3338LL) != 1 )
    goto LABEL_97;
  v70 = *(_BYTE *)(v17 + 2481);
  if ( v70 )
  {
    v70 = 1;
    v71 = 1134;
LABEL_95:
    *a6 = *(_BYTE *)(v17 + v71);
    goto LABEL_96;
  }
  if ( *(_BYTE *)(v17 + 2449) )
  {
    v71 = 2450;
    goto LABEL_95;
  }
LABEL_96:
  *a8 = v70;
LABEL_97:
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1562LL) == 1 )
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
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "lim_extract_ap_capability",
      *(unsigned __int8 *)(v17 + 2571) >> 4,
      (*(unsigned __int8 *)(v17 + 2571) >> 1) & 3);
    qdf_mem_copy((void *)(a7 + 8630), (const void *)(v17 + 2570), 2u);
    if ( (*(_BYTE *)(v17 + 2571) & 6) != 0 )
      qdf_mem_copy((void *)(a7 + 8632), (const void *)(v17 + 2572), 2u);
  }
  lim_objmgr_update_vdev_nss(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a7 + 10), *(_BYTE *)(a7 + 8635));
  vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(&unk_A0A0A0, 4u, a2, a3);
  if ( vendor_ie_ptr_from_oui && (unsigned int)vendor_ie_ptr_from_oui[1] - 9 >= 0xFFFFFFFC )
    v73 = vendor_ie_ptr_from_oui[6] & 1;
  else
    v73 = 0;
  *(_BYTE *)(a7 + 7042) = v73;
  _qdf_mem_free(v17);
  return 0;
}
