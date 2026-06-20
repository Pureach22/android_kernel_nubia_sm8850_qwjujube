__int64 __fastcall wlansap_pre_start_bss_acs_scan_callback(
        __int64 a1,
        unsigned int *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  const char *v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  const char *v17; // x2
  const char *v18; // x3
  unsigned int v19; // w1
  _QWORD *vdev_by_id_from_pdev; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x24
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x23
  unsigned __int64 v33; // x26
  unsigned __int8 v34; // w20
  unsigned int v35; // w22
  unsigned __int16 v36; // w28
  __int64 v37; // x10
  unsigned __int64 v38; // x9
  unsigned int v39; // w27
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  int v48; // w0
  __int64 v49; // x0
  __int64 v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x8
  __int64 v60; // x23
  unsigned __int64 v61; // x21
  unsigned __int8 v62; // w20
  unsigned int v63; // w28
  char v64; // w27
  unsigned __int16 v65; // w26
  __int64 v66; // x9
  __int64 v67; // x8
  int v68; // w3
  int v70; // w0
  __int64 v71; // x20
  unsigned int valid_freq_for_csa; // w22
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x22
  unsigned __int64 v91; // x8
  _QWORD *scan_result; // x23
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  double v101; // d0
  unsigned int v102; // w0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  unsigned int v119; // [xsp+Ch] [xbp-14h]
  __int64 v120; // [xsp+10h] [xbp-10h]
  __int64 v121; // [xsp+18h] [xbp-8h]

  if ( a5 > 3 )
    v8 = "Unknown";
  else
    v8 = off_A16D88[a5];
  host_log_acs_scan_done(v8, a3, a4);
  if ( *((_BYTE *)a2 + 1754) == 1 )
  {
    v17 = "%s: SAP channel selected using first clean channel, ignore scan complete event";
    v18 = "wlansap_pre_start_bss_acs_scan_callback";
    v19 = 8;
LABEL_71:
    qdf_trace_msg(0x39u, v19, v17, v9, v10, v11, v12, v13, v14, v15, v16, v18);
    return 0;
  }
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(a1 + 21560), *((_BYTE *)a2 + 12), 0x2Cu);
  if ( vdev_by_id_from_pdev )
  {
    v120 = (__int64)vdev_by_id_from_pdev;
    v29 = *(_QWORD *)(a1 + 21552);
    v119 = a5;
    v30 = _qdf_mem_malloc(0x96u, "wlansap_filter_unsafe_ch", 301);
    v31 = *((_QWORD *)a2 + 192);
    v32 = v30;
    v121 = a1;
    if ( *(_BYTE *)(v31 + 24) )
    {
      v33 = 0;
      v34 = 0;
      v35 = 0;
      v36 = 0;
      do
      {
        v39 = *(_DWORD *)(*(_QWORD *)(v31 + 16) + 4 * v33);
        if ( (policy_mgr_is_sap_freq_allowed(v29, *(_DWORD *)(*((_QWORD *)a2 + 2) + 16LL), v39) & 1) != 0 )
        {
          v37 = v36++;
          *(_DWORD *)(*(_QWORD *)(*((_QWORD *)a2 + 192) + 16LL) + 4 * v37) = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)a2 + 192) + 16LL)
                                                                                       + 4 * v33);
        }
        else if ( v32 )
        {
          v40 = scnprintf(v32 + v35, 150 - v35, "%d ", v39);
          v35 += v48;
          ++v34;
          if ( v35 >= 0x90 )
          {
            qdf_trace_msg(0x39u, 8u, "Remove unsafe freq(%d): %s", v40, v41, v42, v43, v44, v45, v46, v47, v34, v32);
            v35 = 0;
            v34 = 0;
          }
        }
        v31 = *((_QWORD *)a2 + 192);
        ++v33;
        v38 = *(unsigned __int8 *)(v31 + 24);
      }
      while ( v33 < v38 );
      if ( v35 && v32 )
      {
        qdf_trace_msg(0x39u, 8u, "Remove unsafe freq(%d): %s", v40, v41, v42, v43, v44, v45, v46, v47, v34, v32);
      }
      else if ( !v32 )
      {
        goto LABEL_24;
      }
    }
    else
    {
      if ( !v30 )
        goto LABEL_26;
      v36 = 0;
    }
    _qdf_mem_free(v32);
    v31 = *((_QWORD *)a2 + 192);
    LODWORD(v38) = *(unsigned __int8 *)(v31 + 24);
LABEL_24:
    if ( (_DWORD)v38 != v36 )
      *(_BYTE *)(v31 + 24) = v36;
LABEL_26:
    v50 = _qdf_mem_malloc(0x96u, "wlan_sap_filter_non_preferred_channels", 358);
    v59 = *((_QWORD *)a2 + 192);
    v60 = v50;
    if ( !*(_BYTE *)(v59 + 24) )
    {
      v71 = v121;
      if ( v50 )
        _qdf_mem_free(v50);
LABEL_46:
      if ( !*(_BYTE *)(*((_QWORD *)a2 + 192) + 24LL) )
      {
        valid_freq_for_csa = sap_select_default_oper_chan(v71, a2);
        *a2 = valid_freq_for_csa;
        goto LABEL_66;
      }
      if ( v119 )
      {
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: ACS scan failued (%d), choose default channel",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "wlansap_pre_start_bss_acs_scan_callback");
      }
      else
      {
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: ACS scan completed",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "wlansap_pre_start_bss_acs_scan_callback");
        if ( policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(v71 + 21552), *((unsigned __int8 *)a2 + 12)) && a2[182] == 2 )
        {
          valid_freq_for_csa = wlan_ll_sap_get_valid_freq_for_csa(
                                 *(_QWORD *)(v71 + 21552),
                                 *((unsigned __int8 *)a2 + 12),
                                 *a2,
                                 0);
        }
        else
        {
          v81 = _qdf_mem_malloc(0x2D0u, "wlansap_calculate_chan_from_scan_result", 263);
          if ( v81 )
          {
            v90 = v81;
            if ( *((_BYTE *)a2 + 1753) == 1 )
              v91 = *(unsigned int *)(*((_QWORD *)a2 + 192) + 588LL);
            else
              v91 = qdf_get_time_of_the_day_ms() - *((_QWORD *)a2 + 193);
            *(_QWORD *)(v90 + 8) = v91;
            scan_result = scm_get_scan_result(*(_QWORD *)(v71 + 21560), v90, v82, v83, v84, v85, v86, v87, v88, v89);
            _qdf_mem_free(v90);
          }
          else
          {
            scan_result = scm_get_scan_result(*(_QWORD *)(v71 + 21560), 0, v82, v83, v84, v85, v86, v87, v88, v89);
          }
          if ( scan_result )
            qdf_trace_msg(
              0x39u,
              8u,
              "%s: num_entries %d",
              v93,
              v94,
              v95,
              v96,
              v97,
              v98,
              v99,
              v100,
              "wlansap_calculate_chan_from_scan_result",
              *((unsigned int *)scan_result + 4));
          v101 = sap_select_channel(v71, a2, scan_result);
          valid_freq_for_csa = v102;
          scm_purge_scan_results((__int64)scan_result, v101, v103, v104, v105, v106, v107, v108, v109);
        }
        if ( valid_freq_for_csa )
          goto LABEL_65;
        qdf_trace_msg(
          0x39u,
          4u,
          "%s: No suitable channel, so select default channel",
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          "wlansap_pre_start_bss_acs_scan_callback");
      }
      valid_freq_for_csa = sap_select_default_oper_chan(v71, a2);
LABEL_65:
      wlansap_set_acs_ch_freq(v71, a2, valid_freq_for_csa);
LABEL_66:
      *(_DWORD *)(*((_QWORD *)a2 + 192) + 564LL) = valid_freq_for_csa;
      sap_config_acs_result(v71, (__int64)a2, *(_DWORD *)(*((_QWORD *)a2 + 192) + 568LL));
      *((_QWORD *)a2 + 200) = 21;
      wlan_objmgr_vdev_release_ref(
        v120,
        0x2Cu,
        (unsigned int *)((char *)&off_10 + 5),
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        v117);
      v49 = *((_QWORD *)a2 + 186);
      if ( !v49 )
        goto LABEL_68;
      goto LABEL_67;
    }
    v61 = 0;
    v62 = 0;
    v63 = 0;
    v64 = 0;
    v65 = 0;
    do
    {
      v67 = *(_QWORD *)(v59 + 16);
      v68 = *(_DWORD *)(v67 + 4 * v61);
      if ( (unsigned int)(v68 - 2467) > 0xA || ((1 << (v68 + 93)) & 0x421) == 0 )
      {
        v66 = v65;
        v64 = 1;
        ++v65;
        *(_DWORD *)(v67 + 4 * v66) = v68;
      }
      else if ( v60 )
      {
        v51 = scnprintf(v60 + v63, 150 - v63, "%d ", v68);
        v63 += v70;
        ++v62;
        if ( v63 >= 0x90 )
        {
          qdf_trace_msg(0x39u, 8u, "Remove non pref freq(%d): %s", v51, v52, v53, v54, v55, v56, v57, v58, v62, v60);
          v63 = 0;
          v62 = 0;
        }
      }
      v59 = *((_QWORD *)a2 + 192);
      ++v61;
    }
    while ( v61 < *(unsigned __int8 *)(v59 + 24) );
    if ( v63 && v60 )
    {
      qdf_trace_msg(0x39u, 8u, "Remove non pref freq(%d): %s", v51, v52, v53, v54, v55, v56, v57, v58, v62, v60);
    }
    else if ( !v60 )
    {
      goto LABEL_44;
    }
    _qdf_mem_free(v60);
LABEL_44:
    v71 = v121;
    if ( (v64 & 1) != 0 )
      *(_BYTE *)(*((_QWORD *)a2 + 192) + 24LL) = v65;
    goto LABEL_46;
  }
  qdf_trace_msg(
    0x39u,
    2u,
    "%s: Unable to get vdev ref vdev_id:%d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "wlansap_pre_start_bss_acs_scan_callback",
    *((unsigned __int8 *)a2 + 12));
  v49 = *((_QWORD *)a2 + 186);
  if ( v49 )
  {
LABEL_67:
    _qdf_mem_free(v49);
    *((_QWORD *)a2 + 186) = 0;
    *((_BYTE *)a2 + 1496) = 0;
  }
LABEL_68:
  if ( !a2 )
  {
    v17 = "%s: sap context is not valid";
    v18 = "sap_hdd_signal_event_handler";
    v19 = 2;
    goto LABEL_71;
  }
  sap_signal_hdd_event(a2, 0, a2[400], a2[401]);
  return 0;
}
