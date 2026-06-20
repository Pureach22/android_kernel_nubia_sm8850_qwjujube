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
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w8
  __int64 v45; // x0
  __int64 v46; // x22
  unsigned __int16 *active_channel; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x23
  const char *v57; // x2
  __int64 v59; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x2
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  size_t v77; // x24
  __int64 v78; // x4
  const char *v79; // x2
  bool is_24ghz_ch_freq; // w0
  unsigned int v81; // w8
  int v82; // w9
  int v83; // w9
  int v84; // w9
  unsigned int v85; // w0
  unsigned int *v86; // x8
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  int v95; // w22
  unsigned int v96; // w21
  unsigned int *v97; // x8
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned __int16 *bonded_chan_entry; // x0
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  unsigned __int16 *v115; // x25
  _BYTE *v116; // x0
  unsigned __int8 v117; // w11
  unsigned int v118; // w8
  unsigned int *v119; // x9
  __int64 v120; // x10
  unsigned int v121; // w8
  __int64 v122; // x0
  unsigned int v123; // w25
  unsigned int v124; // w22
  unsigned __int64 v125; // x28
  int v126; // w3
  int v127; // w0
  __int64 v128; // [xsp+18h] [xbp-8h]

  ext_hdl = wlan_psoc_mlme_get_ext_hdl(a1);
  if ( !ext_hdl )
  {
    v57 = "%s: vdev %d : NULL mlme psoc object";
LABEL_11:
    qdf_trace_msg(
      0x68u,
      8u,
      v57,
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
    v57 = "%s: vdev %d : NULL vdev object";
    goto LABEL_11;
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
    goto LABEL_36;
  *(_DWORD *)(v26 + 8) = wlan_scan_get_scan_id(a1, v28, v29, v30, v31, v32, v33, v34, v35);
  v44 = *(unsigned __int16 *)(v13 + 7608);
  *(_DWORD *)(v26 + 28) = 0;
  *(_DWORD *)(v26 + 12) = v44;
  *(_DWORD *)(v26 + 16) = (unsigned __int8)a2;
  if ( (*(_BYTE *)(a1 + 25) & 4) != 0 )
  {
    *(_BYTE *)(v26 + 120) = 0;
    v59 = wlan_vdev_mlme_get_ext_hdl(v15, v36, v37, v38, v39, v40, v41, v42, v43);
    if ( v59 )
    {
      v68 = *(unsigned int *)(v59 + 24248);
      if ( (_DWORD)v68 == 8 )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: vdev %d :Invalid associated ch_width",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "mlme_fill_freq_in_wide_scan_start_request",
          *(unsigned int *)(v26 + 16));
      }
      else if ( !(unsigned int)((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD))mlme_update_freq_in_scan_start_req)(
                                 v15,
                                 v26,
                                 v68,
                                 102,
                                 *(unsigned int *)(v59 + 24264)) )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: vdev %d :trigger wide band scan, num freq %d",
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          "mlme_fill_freq_in_wide_scan_start_request",
          *(unsigned int *)(v26 + 16),
          *(unsigned __int8 *)(v26 + 120));
        v83 = *(_DWORD *)(v26 + 92);
        *(_DWORD *)(v26 + 44) = 110;
        *(_DWORD *)(v26 + 56) = 110;
        *(_DWORD *)(v26 + 92) = v83 | 0x5000000;
        goto LABEL_34;
      }
    }
LABEL_17:
    inited = 16;
LABEL_36:
    v96 = inited;
    _qdf_mem_free(v26);
    wlan_objmgr_vdev_release_ref(v15, 2u, v97, v98, v99, v100, v101, v102, v103, v104, v105);
    return v96;
  }
  v45 = wlan_vdev_mlme_get_ext_hdl(v15, v36, v37, v38, v39, v40, v41, v42, v43);
  if ( !v45 )
    goto LABEL_17;
  v46 = v45 + 20480;
  active_channel = (unsigned __int16 *)wlan_vdev_get_active_channel(v15);
  if ( active_channel )
    LODWORD(v56) = *active_channel;
  else
    LODWORD(v56) = 0;
  LODWORD(v77) = *(_DWORD *)(v46 + 3768);
  if ( (_DWORD)v77 == 8 )
  {
    v78 = *(unsigned int *)(v26 + 16);
    v79 = "%s: vdev %d : Invalid associated ch width for freq %d";
LABEL_21:
    qdf_trace_msg(
      0x68u,
      8u,
      v79,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "mlme_fill_freq_in_scan_start_request",
      v78,
      (unsigned int)v56);
    inited = 16;
    goto LABEL_36;
  }
  *(_DWORD *)(v26 + 44) = 40;
  *(_DWORD *)(v26 + 56) = 40;
  if ( !(_DWORD)v77 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d :Trigger scan for associated freq %d bw %d",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "mlme_fill_freq_in_scan_start_request",
      *(unsigned int *)(v26 + 16),
      (unsigned int)v56,
      0);
    *(_DWORD *)(v26 + 124) = v56;
    *(_BYTE *)(v26 + 120) = 1;
    goto LABEL_34;
  }
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v56);
  if ( (_DWORD)v77 != 1 || !is_24ghz_ch_freq )
  {
    bonded_chan_entry = wlan_reg_get_bonded_chan_entry(v56, v77, 0, v48, v49, v50, v51, v52, v53, v54, v55);
    if ( bonded_chan_entry )
    {
      v115 = bonded_chan_entry;
      v116 = (_BYTE *)_qdf_mem_malloc(0x4CCu, "mlme_fill_freq_in_scan_start_request", 180);
      if ( v116 )
      {
        *v116 = 0;
        v117 = 0;
        v118 = *v115;
        if ( v118 <= v115[1] )
        {
          v119 = (unsigned int *)(v116 + 4);
          v120 = 1;
          while ( v120 != 103 )
          {
            *v119 = v118;
            v119 += 3;
            v118 += 20;
            *v116 = v120;
            v117 = v120++;
            if ( v118 > v115[1] )
              goto LABEL_44;
          }
LABEL_56:
          __break(0x5512u);
          goto LABEL_57;
        }
LABEL_44:
        *(_BYTE *)(v26 + 120) = v117;
        v128 = (__int64)v116;
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: vdev %d : freq %d bw %d, range [%d-%d], Total freq %d",
          v107,
          v108,
          v109,
          v110,
          v111,
          v112,
          v113,
          v114,
          "mlme_fill_freq_in_scan_start_request",
          *(unsigned int *)(v26 + 16),
          (unsigned int)v56,
          (unsigned int)v77,
          *v115,
          v115[1],
          v117);
        v121 = *(unsigned __int8 *)(v26 + 120);
        if ( v121 < 0x27 )
          v77 = 5 * v121 + 1;
        else
          v77 = 196;
        v122 = _qdf_mem_malloc(v77, "mlme_fill_freq_in_scan_start_request", 202);
        if ( v122 )
        {
          v56 = v122;
          if ( *(_BYTE *)(v26 + 120) )
          {
            v123 = 0;
            v124 = 0;
            v125 = 0;
            while ( 1 )
            {
              while ( 1 )
              {
                v126 = *(_DWORD *)(v128 + 4 + 12 * v125);
                *(_DWORD *)(v26 + 124 + 12 * v125) = v126;
                v107 = scnprintf(v56 + v123, (unsigned int)v77 - v123, " %d", v126);
                if ( v124 <= 0x25 )
                  break;
                qdf_trace_msg(
                  0x68u,
                  8u,
                  "%s: Freq list: %s",
                  v107,
                  v108,
                  v109,
                  v110,
                  v111,
                  v112,
                  v113,
                  v114,
                  "mlme_fill_freq_in_scan_start_request",
                  v56);
                if ( ++v125 >= *(unsigned __int8 *)(v26 + 120) )
                  goto LABEL_63;
                v124 = 0;
                v123 = 0;
                if ( v125 == 102 )
                  goto LABEL_56;
              }
              ++v125;
              v123 += v127;
              if ( v125 >= *(unsigned __int8 *)(v26 + 120) )
                break;
              ++v124;
              if ( v125 == 102 )
                goto LABEL_56;
            }
            if ( v123 )
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: Freq list: %s",
                v107,
                v108,
                v109,
                v110,
                v111,
                v112,
                v113,
                v114,
                "mlme_fill_freq_in_scan_start_request",
                v56);
          }
LABEL_63:
          _qdf_mem_free(v56);
          _qdf_mem_free(v128);
          goto LABEL_34;
        }
        _qdf_mem_free(v128);
      }
      inited = 2;
      goto LABEL_36;
    }
LABEL_57:
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d: Invalid freq range for freq: %d bw: %d",
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      "mlme_fill_freq_in_scan_start_request",
      *(unsigned int *)(v26 + 16),
      (unsigned int)v56,
      (unsigned int)v77);
    inited = 16;
    goto LABEL_36;
  }
  v81 = *(_DWORD *)(v46 + 3780);
  if ( !v81 )
  {
    v78 = *(unsigned int *)(v26 + 16);
    v79 = "%s: vdev %d : Invalid sec 2g freq for freq: %d";
    goto LABEL_21;
  }
  if ( (unsigned int)v56 >= v81 )
    v82 = *(_DWORD *)(v46 + 3780);
  else
    v82 = v56;
  if ( (unsigned int)v56 > v81 )
    v81 = v56;
  *(_DWORD *)(v26 + 124) = v82;
  *(_DWORD *)(v26 + 136) = v81;
  *(_BYTE *)(v26 + 120) = 2;
LABEL_34:
  v84 = *(_DWORD *)(v26 + 92);
  *(_DWORD *)(v26 + 100) = 4;
  *(_DWORD *)(v26 + 48) = 0;
  *(_DWORD *)(v26 + 92) = v84 | 0x2000001;
  v85 = wlan_scan_start((__int64 *)v26, v48, v49, v50, v51, v52, v53, v54, v55);
  if ( v85 )
  {
    v95 = v85;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d :Failed to send scan req, status %d",
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      "mlme_connected_chan_stats_request",
      (unsigned __int8)a2,
      v85);
    inited = v95;
    goto LABEL_36;
  }
  wlan_objmgr_vdev_release_ref(v15, 2u, v86, v87, v88, v89, v90, v91, v92, v93, v94);
  return 0;
}
