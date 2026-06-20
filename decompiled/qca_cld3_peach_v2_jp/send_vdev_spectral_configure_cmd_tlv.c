__int64 __fastcall send_vdev_spectral_configure_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x8
  __int64 v6; // x21
  int v7; // w3
  unsigned int v8; // w9
  int v9; // w9
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
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
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x68u, "send_vdev_spectral_configure_cmd_tlv", 0x2475u);
  if ( v4 )
  {
    v5 = *(_DWORD **)(v4 + 224);
    v6 = v4;
    *v5 = 9240676;
    v7 = *a2;
    v5[1] = v7;
    v5[2] = *((unsigned __int16 *)a2 + 1);
    v5[3] = *((unsigned __int16 *)a2 + 2);
    v5[4] = *((unsigned __int16 *)a2 + 4);
    v5[5] = *((unsigned __int16 *)a2 + 5);
    v5[6] = *((unsigned __int16 *)a2 + 6);
    v5[7] = *((unsigned __int16 *)a2 + 7);
    v5[8] = *((unsigned __int16 *)a2 + 8);
    v5[9] = *((unsigned __int16 *)a2 + 9);
    v5[10] = *((unsigned __int16 *)a2 + 10);
    v5[11] = *((unsigned __int16 *)a2 + 11);
    v5[12] = *((unsigned __int16 *)a2 + 12);
    v5[13] = *((unsigned __int16 *)a2 + 13);
    v5[14] = *((unsigned __int16 *)a2 + 14);
    v5[15] = *((unsigned __int16 *)a2 + 15);
    v5[16] = *((unsigned __int16 *)a2 + 16);
    v5[17] = *((unsigned __int16 *)a2 + 17);
    v5[18] = *((unsigned __int16 *)a2 + 18);
    v5[19] = *((unsigned __int16 *)a2 + 19);
    v5[20] = *((unsigned __int16 *)a2 + 20);
    v5[21] = *((unsigned __int16 *)a2 + 21);
    v5[24] = *((unsigned __int16 *)a2 + 22);
    v8 = *((unsigned __int16 *)a2 + 24);
    if ( v8 >= 7 )
      v8 = 10;
    v5[23] = v8;
    v9 = *((unsigned __int16 *)a2 + 3);
    v5[22] = 0;
    v5[25] = v9;
    qdf_mtrace(49, 100, 0xA81u, v7, 0);
    v18 = wmi_unified_cmd_send_fl(
            a1,
            v6,
            0x68u,
            0x15001u,
            "send_vdev_spectral_configure_cmd_tlv",
            0x249Du,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17);
    if ( v18 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Sending set quiet cmd failed",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "send_vdev_spectral_configure_cmd_tlv");
      wmi_buf_free();
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Sent WMI_VDEV_SPECTRAL_SCAN_CONFIGURE_CMDID",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "send_vdev_spectral_configure_cmd_tlv");
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev_id: %u spectral_scan_count: %u",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "send_vdev_spectral_configure_cmd_tlv",
      *a2,
      *((unsigned __int16 *)a2 + 1));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_period: %u spectral_scan_priority: %u",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 2),
      *((unsigned __int16 *)a2 + 4));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_fft_recapture_cap: %u",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 3));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_fft_size: %u spectral_scan_gc_ena: %u",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 5),
      *((unsigned __int16 *)a2 + 6));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_restart_ena: %u",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 7));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_noise_floor_ref: %u",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 8));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_init_delay: %u",
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 9));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_nb_tone_thr: %u",
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 10));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_str_bin_thr: %u",
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 11));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_wb_rpt_mode: %u",
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 12));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_rssi_rpt_mode: %u",
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 13));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_rssi_thr: %u spectral_scan_pwr_format: %u",
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 14),
      *((unsigned __int16 *)a2 + 15));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_rpt_mode: %u spectral_scan_bin_scale: %u",
      v123,
      v124,
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 16),
      *((unsigned __int16 *)a2 + 17));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_dBm_adj: %u spectral_scan_chn_mask: %u",
      v131,
      v132,
      v133,
      v134,
      v135,
      v136,
      v137,
      v138,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 18),
      *((unsigned __int16 *)a2 + 19));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_mode: %u spectral_scan_center_freq1: %u",
      v139,
      v140,
      v141,
      v142,
      v143,
      v144,
      v145,
      v146,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 20),
      *((unsigned __int16 *)a2 + 21));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_center_freq2: %u spectral_scan_chan_freq: %u",
      v147,
      v148,
      v149,
      v150,
      v151,
      v152,
      v153,
      v154,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 22),
      *((unsigned __int16 *)a2 + 23));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_chan_width: %u Status: %d",
      v155,
      v156,
      v157,
      v158,
      v159,
      v160,
      v161,
      v162,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 24),
      v18);
  }
  else
  {
    return 16;
  }
  return v18;
}
