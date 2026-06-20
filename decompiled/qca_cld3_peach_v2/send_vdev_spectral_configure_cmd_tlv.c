__int64 __fastcall send_vdev_spectral_configure_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x8
  __int64 v6; // x21
  int v7; // w3
  unsigned __int64 v8; // x9
  int v9; // w9
  unsigned int v10; // w20
  int v11; // w9
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
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
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7

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
    if ( v8 > 7 )
      v9 = 10;
    else
      v9 = dword_B35288[v8];
    v5[23] = v9;
    v11 = *((unsigned __int16 *)a2 + 3);
    v5[22] = 0;
    v5[25] = v11;
    qdf_mtrace(49, 100, 0xA81u, v7, 0);
    v10 = wmi_unified_cmd_send_fl(
            a1,
            v6,
            0x68u,
            0x15001u,
            "send_vdev_spectral_configure_cmd_tlv",
            0x249Du,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19);
    if ( v10 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Sending set quiet cmd failed",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "send_vdev_spectral_configure_cmd_tlv");
      wmi_buf_free();
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Sent WMI_VDEV_SPECTRAL_SCAN_CONFIGURE_CMDID",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "send_vdev_spectral_configure_cmd_tlv");
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev_id: %u spectral_scan_count: %u",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "send_vdev_spectral_configure_cmd_tlv",
      *a2,
      *((unsigned __int16 *)a2 + 1));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_period: %u spectral_scan_priority: %u",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 2),
      *((unsigned __int16 *)a2 + 4));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_fft_recapture_cap: %u",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 3));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_fft_size: %u spectral_scan_gc_ena: %u",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 5),
      *((unsigned __int16 *)a2 + 6));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_restart_ena: %u",
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 7));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_noise_floor_ref: %u",
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 8));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_init_delay: %u",
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 9));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_nb_tone_thr: %u",
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 10));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_str_bin_thr: %u",
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 11));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_wb_rpt_mode: %u",
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 12));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_rssi_rpt_mode: %u",
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      v115,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 13));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_rssi_thr: %u spectral_scan_pwr_format: %u",
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 14),
      *((unsigned __int16 *)a2 + 15));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_rpt_mode: %u spectral_scan_bin_scale: %u",
      v124,
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      v131,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 16),
      *((unsigned __int16 *)a2 + 17));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_dBm_adj: %u spectral_scan_chn_mask: %u",
      v132,
      v133,
      v134,
      v135,
      v136,
      v137,
      v138,
      v139,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 18),
      *((unsigned __int16 *)a2 + 19));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_mode: %u spectral_scan_center_freq1: %u",
      v140,
      v141,
      v142,
      v143,
      v144,
      v145,
      v146,
      v147,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 20),
      *((unsigned __int16 *)a2 + 21));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_center_freq2: %u spectral_scan_chan_freq: %u",
      v148,
      v149,
      v150,
      v151,
      v152,
      v153,
      v154,
      v155,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 22),
      *((unsigned __int16 *)a2 + 23));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_chan_width: %u Status: %d",
      v156,
      v157,
      v158,
      v159,
      v160,
      v161,
      v162,
      v163,
      "send_vdev_spectral_configure_cmd_tlv",
      *((unsigned __int16 *)a2 + 24),
      v10);
  }
  else
  {
    return 16;
  }
  return v10;
}
