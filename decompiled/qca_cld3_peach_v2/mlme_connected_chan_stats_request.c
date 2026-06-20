__int64 __fastcall mlme_connected_chan_stats_request(__int64 a1, unsigned int a2)
{
  __int64 ext_hdl; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x23
  __int64 v14; // x0
  __int64 v15; // x19
  __int64 *v16; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x20
  int inited; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w21
  unsigned int *v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  const char *v47; // x2
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w8
  __int64 v57; // x0
  __int64 v58; // x22
  unsigned __int16 *active_channel; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned int v68; // w23
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x8
  __int64 v78; // x28
  __int64 v79; // x24
  __int64 v80; // x22
  __int64 v81; // x5
  __int64 v82; // x9
  int *v83; // x26
  unsigned int v84; // w25
  unsigned int v85; // w8
  unsigned int v86; // w23
  unsigned __int16 *v87; // x0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  unsigned int v96; // w27
  unsigned int v97; // w26
  __int64 v98; // x5
  unsigned int v99; // w8
  unsigned int *v100; // x9
  unsigned int v101; // w8
  unsigned int *v102; // x9
  __int64 v103; // x0
  __int64 v104; // x2
  __int64 v105; // x4
  const char *v106; // x2
  const char *v107; // x3
  unsigned int v108; // w24
  __int64 v109; // x4
  const char *v110; // x2
  bool is_24ghz_ch_freq; // w0
  unsigned int v112; // w8
  unsigned int v113; // w9
  unsigned int v114; // w1
  unsigned __int16 *bonded_chan_entry; // x0
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  unsigned __int16 *v124; // x25
  _BYTE *v125; // x0
  unsigned __int8 v126; // w11
  unsigned int v127; // w8
  unsigned int *v128; // x9
  __int64 v129; // x10
  unsigned int v130; // w8
  size_t v131; // x24
  __int64 v132; // x0
  __int64 v133; // x23
  unsigned int v134; // w25
  unsigned int v135; // w22
  unsigned __int64 v136; // x28
  int v137; // w3
  int v138; // w0
  __int64 v139; // x4
  const char *v140; // x2
  const char *v141; // x3
  int v142; // w9
  int v143; // w9
  unsigned int v144; // w0
  unsigned int *v145; // x8
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  int v154; // w22
  __int64 v155; // [xsp+0h] [xbp-20h]
  __int64 v156; // [xsp+8h] [xbp-18h]
  __int64 v157; // [xsp+18h] [xbp-8h]

  ext_hdl = wlan_psoc_mlme_get_ext_hdl(a1);
  if ( !ext_hdl )
  {
    v47 = "%s: vdev %d : NULL mlme psoc object";
LABEL_8:
    qdf_trace_msg(
      0x68u,
      8u,
      v47,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "mlme_connected_chan_stats_request",
      (unsigned __int8)a2);
    return 16;
  }
  v13 = ext_hdl;
  v14 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v14 )
  {
    v47 = "%s: vdev %d : NULL vdev object";
    goto LABEL_8;
  }
  v15 = v14;
  v16 = (__int64 *)_qdf_mem_malloc(0x8F0u, "mlme_connected_chan_stats_request", 781);
  if ( !v16 )
  {
    wlan_objmgr_vdev_release_ref(v15, 2u, v17, v18, v19, v20, v21, v22, v23, v24, v25);
    return 2;
  }
  v26 = (__int64)v16;
  inited = wlan_scan_init_default_params(v15, v16, v18, v19, v20, v21, v22, v23, v24, v25);
  if ( inited )
    goto LABEL_5;
  *(_DWORD *)(v26 + 8) = wlan_scan_get_scan_id(a1, v28, v29, v30, v31, v32, v33, v34, v35);
  v56 = *(unsigned __int16 *)(v13 + 7832);
  *(_DWORD *)(v26 + 28) = 0;
  *(_DWORD *)(v26 + 12) = v56;
  *(_DWORD *)(v26 + 16) = (unsigned __int8)a2;
  if ( (*(_BYTE *)(a1 + 25) & 4) == 0 )
  {
    v57 = wlan_vdev_mlme_get_ext_hdl(v15, v48, v49, v50, v51, v52, v53, v54, v55);
    if ( v57 )
    {
      v58 = v57 + 20480;
      active_channel = (unsigned __int16 *)wlan_vdev_get_active_channel(v15);
      if ( active_channel )
        v68 = *active_channel;
      else
        v68 = 0;
      v108 = *(_DWORD *)(v58 + 3768);
      if ( v108 == 8 )
      {
        v109 = *(unsigned int *)(v26 + 16);
        v110 = "%s: vdev %d : Invalid associated ch width for freq %d";
LABEL_38:
        qdf_trace_msg(
          0x68u,
          8u,
          v110,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "mlme_fill_freq_in_scan_start_request",
          v109,
          v68);
        inited = 16;
        goto LABEL_5;
      }
      *(_DWORD *)(v26 + 44) = 40;
      *(_DWORD *)(v26 + 56) = 40;
      if ( !v108 )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: vdev %d :Trigger scan for associated freq %d bw %d",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "mlme_fill_freq_in_scan_start_request",
          *(unsigned int *)(v26 + 16),
          v68,
          0);
        *(_DWORD *)(v26 + 124) = v68;
        *(_BYTE *)(v26 + 120) = 1;
        goto LABEL_78;
      }
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v68);
      if ( v108 == 1 && is_24ghz_ch_freq )
      {
        v112 = *(_DWORD *)(v58 + 3780);
        if ( !v112 )
        {
          v109 = *(unsigned int *)(v26 + 16);
          v110 = "%s: vdev %d : Invalid sec 2g freq for freq: %d";
          goto LABEL_38;
        }
        if ( v68 >= v112 )
          v113 = *(_DWORD *)(v58 + 3780);
        else
          v113 = v68;
        if ( v68 > v112 )
          v112 = v68;
        *(_DWORD *)(v26 + 124) = v113;
        *(_DWORD *)(v26 + 136) = v112;
        *(_BYTE *)(v26 + 120) = 2;
LABEL_78:
        v143 = *(_DWORD *)(v26 + 92);
        *(_DWORD *)(v26 + 100) = 4;
        *(_DWORD *)(v26 + 48) = 0;
        *(_DWORD *)(v26 + 92) = v143 | 0x2000001;
        v144 = wlan_scan_start((__int64 *)v26, v60, v61, v62, v63, v64, v65, v66, v67);
        if ( v144 )
        {
          v154 = v144;
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: vdev %d :Failed to send scan req, status %d",
            v146,
            v147,
            v148,
            v149,
            v150,
            v151,
            v152,
            v153,
            "mlme_connected_chan_stats_request",
            (unsigned __int8)a2,
            v144);
          inited = v154;
          goto LABEL_5;
        }
        wlan_objmgr_vdev_release_ref(v15, 2u, v145, v146, v147, v148, v149, v150, v151, v152, v153);
        return 0;
      }
      bonded_chan_entry = wlan_reg_get_bonded_chan_entry(v68, v108, 0, v60, v61, v62, v63, v64, v65, v66, v67);
      if ( !bonded_chan_entry )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: vdev %d: Invalid freq range for freq: %d bw: %d",
          v116,
          v117,
          v118,
          v119,
          v120,
          v121,
          v122,
          v123,
          "mlme_fill_freq_in_scan_start_request",
          *(unsigned int *)(v26 + 16),
          v68,
          v108);
        inited = 16;
        goto LABEL_5;
      }
      v124 = bonded_chan_entry;
      v125 = (_BYTE *)_qdf_mem_malloc(0x4CCu, "mlme_fill_freq_in_scan_start_request", 180);
      if ( v125 )
      {
        *v125 = 0;
        v126 = 0;
        v127 = *v124;
        if ( v127 <= v124[1] )
        {
          v128 = (unsigned int *)(v125 + 4);
          v129 = 1;
          while ( v129 != 103 )
          {
            *v128 = v127;
            v128 += 3;
            v127 += 20;
            *v125 = v129;
            v126 = v129++;
            if ( v127 > v124[1] )
              goto LABEL_61;
          }
LABEL_73:
          __break(0x5512u);
LABEL_74:
          v139 = *(unsigned int *)(v26 + 16);
          v81 = *(unsigned __int8 *)(v26 + 120);
          v140 = "%s: vdev %d :trigger wide band scan, num freq %d";
          v141 = "mlme_fill_freq_in_wide_scan_start_request";
LABEL_77:
          qdf_trace_msg(0x68u, 8u, v140, v69, v70, v71, v72, v73, v74, v75, v76, v141, v139, v81);
          v142 = *(_DWORD *)(v26 + 92);
          *(_DWORD *)(v26 + 44) = 110;
          *(_DWORD *)(v26 + 56) = 110;
          *(_DWORD *)(v26 + 92) = v142 | 0x5000000;
          goto LABEL_78;
        }
LABEL_61:
        *(_BYTE *)(v26 + 120) = v126;
        v157 = (__int64)v125;
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: vdev %d : freq %d bw %d, range [%d-%d], Total freq %d",
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          "mlme_fill_freq_in_scan_start_request",
          *(unsigned int *)(v26 + 16),
          v68,
          v108,
          *v124,
          v124[1],
          v126);
        v130 = *(unsigned __int8 *)(v26 + 120);
        if ( v130 < 0x27 )
          v131 = 5 * v130 + 1;
        else
          v131 = 196;
        v132 = _qdf_mem_malloc(v131, "mlme_fill_freq_in_scan_start_request", 202);
        if ( v132 )
        {
          v133 = v132;
          if ( *(_BYTE *)(v26 + 120) )
          {
            v134 = 0;
            v135 = 0;
            v136 = 0;
            while ( 1 )
            {
              while ( 1 )
              {
                v137 = *(_DWORD *)(v157 + 4 + 12 * v136);
                *(_DWORD *)(v26 + 124 + 12 * v136) = v137;
                v69 = scnprintf(v133 + v134, (unsigned int)v131 - v134, " %d", v137);
                if ( v135 <= 0x25 )
                  break;
                qdf_trace_msg(
                  0x68u,
                  8u,
                  "%s: Freq list: %s",
                  v69,
                  v70,
                  v71,
                  v72,
                  v73,
                  v74,
                  v75,
                  v76,
                  "mlme_fill_freq_in_scan_start_request",
                  v133);
                if ( ++v136 >= *(unsigned __int8 *)(v26 + 120) )
                  goto LABEL_93;
                v135 = 0;
                v134 = 0;
                if ( v136 == 102 )
                  goto LABEL_73;
              }
              ++v136;
              v134 += v138;
              if ( v136 >= *(unsigned __int8 *)(v26 + 120) )
                break;
              ++v135;
              if ( v136 == 102 )
                goto LABEL_73;
            }
            if ( v134 )
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: Freq list: %s",
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                v76,
                "mlme_fill_freq_in_scan_start_request",
                v133);
          }
LABEL_93:
          _qdf_mem_free(v133);
          _qdf_mem_free(v157);
          goto LABEL_78;
        }
        _qdf_mem_free(v157);
      }
      inited = 2;
      goto LABEL_5;
    }
LABEL_51:
    inited = 16;
    goto LABEL_5;
  }
  *(_BYTE *)(v26 + 120) = 0;
  if ( (wlan_vdev_mlme_is_mlo_vdev(v15, v48, v49, v50, v51, v52, v53, v54, v55) & 1) == 0 )
  {
    v103 = wlan_vdev_mlme_get_ext_hdl(v15, v69, v70, v71, v72, v73, v74, v75, v76);
    if ( v103 )
    {
      v104 = *(unsigned int *)(v103 + 24248);
      if ( (_DWORD)v104 == 8 )
      {
        v105 = *(unsigned int *)(v26 + 16);
        v106 = "%s: vdev %d :Invalid associated ch_width";
        v107 = "mlme_fill_freq_in_wide_scan_start_request";
        goto LABEL_87;
      }
      if ( !(unsigned int)((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD))mlme_update_freq_in_scan_start_req)(
                            v15,
                            v26,
                            v104,
                            102,
                            *(unsigned int *)(v103 + 24264)) )
        goto LABEL_74;
    }
    goto LABEL_51;
  }
  v77 = *(_QWORD *)(v15 + 1360);
  if ( !v77 )
  {
    v105 = *(unsigned int *)(v26 + 16);
    v106 = "%s: vdev %d :mlo_dev_ctx is NULL";
LABEL_53:
    v107 = "mlme_fill_freq_in_mlo_wide_band_scan_start_req";
    v114 = 2;
    goto LABEL_88;
  }
  v78 = *(_QWORD *)(v77 + 3880);
  if ( !v78 )
  {
    v105 = *(unsigned int *)(v26 + 16);
    v106 = "%s: vdev %d :mlo_link_ctx is NULL";
    goto LABEL_53;
  }
  v79 = 0;
  v80 = v26 + 124;
  while ( 1 )
  {
    if ( *(unsigned __int8 *)(v78 + v79 + 6) == 255 )
    {
      v81 = *(unsigned __int8 *)(v26 + 120);
LABEL_76:
      v139 = *(unsigned int *)(v26 + 16);
      v140 = "%s: vdev %d :trigger wide band scan for mlo conn, num freq %d";
      v141 = "mlme_fill_freq_in_mlo_wide_band_scan_start_req";
      goto LABEL_77;
    }
    v83 = *(int **)(v78 + v79 + 32);
    if ( !v83 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: link chan info is null for link_id: %d",
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        "mlme_update_freq_from_link_ctx");
      goto LABEL_86;
    }
    v84 = *(unsigned __int16 *)v83;
    v85 = v83[7] - 31;
    if ( v85 >= 0xA )
    {
      LODWORD(v156) = v83[5];
      LODWORD(v155) = 34;
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: link_id: %d, op_freq: %d, scan_ch_width: %d, ch_phymode: %d, scan_phy_mode: %d, ch_cfreq2: %d",
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        "mlme_update_freq_from_link_ctx",
        v155,
        v156);
      goto LABEL_86;
    }
    v86 = dword_AEF788[v85];
    LODWORD(v155) = v86;
    LODWORD(v156) = v83[5];
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: link_id: %d, op_freq: %d, scan_ch_width: %d, ch_phymode: %d, scan_phy_mode: %d, ch_cfreq2: %d",
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      "mlme_update_freq_from_link_ctx",
      v155,
      v156);
    if ( v83[6] == 7 )
      break;
    v101 = *(unsigned __int8 *)(v26 + 120);
    if ( v101 > 0x65 )
      goto LABEL_73;
    v81 = v101 + 1;
    v102 = (unsigned int *)(v80 + 12LL * *(unsigned __int8 *)(v26 + 120));
    *v102 = v84;
    v102[1] = v86;
LABEL_19:
    v79 += 48;
    *(_BYTE *)(v26 + 120) = v81;
    if ( v79 == 144 )
      goto LABEL_76;
  }
  v87 = wlan_reg_get_bonded_chan_entry(v84, 7u, v83[5], v69, v70, v71, v72, v73, v74, v75, v76);
  if ( v87 )
  {
    v96 = *v87;
    v97 = v84;
    v98 = v96 + 140;
    if ( (unsigned int)v98 >= v84 )
    {
      v97 = v87[1];
      v96 = v84;
    }
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: op_freq:%d, c_freq:%d, start_freq:%d, end_freq:%d",
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      "mlme_update_freq_from_link_ctx",
      v84,
      v98,
      v96,
      v97);
    v99 = *(unsigned __int8 *)(v26 + 120);
    if ( v99 >= 0x66 )
      goto LABEL_73;
    v100 = (unsigned int *)(v80 + 12LL * *(unsigned __int8 *)(v26 + 120));
    *v100 = v96;
    v100[1] = v86;
    if ( v99 == 101 )
      goto LABEL_73;
    v81 = v99 + 2;
    v82 = v80 + 12LL * v99;
    *(_DWORD *)(v82 + 12) = v97;
    *(_DWORD *)(v82 + 16) = v86;
    goto LABEL_19;
  }
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: range is null for freq %d center freq %d",
    v88,
    v89,
    v90,
    v91,
    v92,
    v93,
    v94,
    v95,
    "mlme_update_freq_from_link_ctx",
    v84,
    (unsigned int)v83[5]);
LABEL_86:
  v106 = "%s: freq update fails for link id %d";
  v105 = *(unsigned __int8 *)(v78 + v79 + 6);
  v107 = "mlme_fill_freq_in_mlo_wide_band_scan_start_req";
LABEL_87:
  v114 = 8;
LABEL_88:
  qdf_trace_msg(0x68u, v114, v106, v69, v70, v71, v72, v73, v74, v75, v76, v107, v105);
  inited = 16;
LABEL_5:
  v36 = inited;
  _qdf_mem_free(v26);
  wlan_objmgr_vdev_release_ref(v15, 2u, v37, v38, v39, v40, v41, v42, v43, v44, v45);
  return v36;
}
