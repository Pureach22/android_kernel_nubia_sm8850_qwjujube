__int64 __fastcall wma_csa_offload_handler(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x23
  int v21; // w9
  _QWORD *peer_by_mac; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w22
  __int64 v32; // x0
  __int64 v33; // x19
  __int64 v34; // x0
  unsigned int *v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned __int8 *v44; // x21
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x4
  __int64 v62; // x5
  const char *v63; // x2
  __int64 v64; // x6
  __int64 v65; // x7
  __int64 result; // x0
  __int16 v67; // w9
  __int64 v68; // x22
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  int v85; // w8
  unsigned int v86; // w1
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  int v95; // w8
  unsigned __int8 v96; // w1
  bool is_6ghz_op_class; // w0
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned int v106; // w1
  __int64 op_class_width; // x0
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  int chwidth_from_bw; // w0
  int v117; // w8
  int v118; // w8
  unsigned __int8 v119; // w1
  unsigned __int8 v120; // w3
  int v121; // w0
  int v122; // w8
  unsigned __int8 *v123; // x0
  unsigned __int8 v124; // w1
  unsigned __int8 v125; // w3
  int v126; // w8
  __int64 active_channel; // x0
  unsigned int *v128; // x8
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  unsigned __int16 *v137; // x22
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  unsigned int *v146; // x8
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  int v155; // [xsp+0h] [xbp-50h]
  _WORD v156[2]; // [xsp+38h] [xbp-18h] BYREF
  int v157; // [xsp+3Ch] [xbp-14h] BYREF
  __int16 v158; // [xsp+40h] [xbp-10h]
  __int16 v159; // [xsp+44h] [xbp-Ch] BYREF
  char v160; // [xsp+46h] [xbp-Ah]
  __int64 v161; // [xsp+48h] [xbp-8h]

  v161 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v158 = 0;
  v157 = 0;
  qdf_trace_msg(0x36u, 8u, "%s: Enter", a3, a4, a5, a6, a7, a8, a9, a10, "wma_csa_offload_handler");
  if ( !a2 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid csa event buffer",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_csa_offload_handler");
    goto LABEL_16;
  }
  v20 = *a2;
  if ( (~*(_DWORD *)(*a2 + 104) & 5) != 0 )
  {
    v21 = *(_DWORD *)(v20 + 20);
    v157 = *(_DWORD *)(v20 + 16);
    v158 = v21;
  }
  peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(a1 + 24), &v157, 8u);
  if ( !peer_by_mac )
  {
    v61 = (unsigned __int8)v157;
    v62 = BYTE1(v157);
    v63 = "%s: Invalid peer, peer mac addr %02x:%02x:%02x:**:**:%02x";
    v64 = BYTE2(v157);
    v65 = HIBYTE(v158);
LABEL_15:
    qdf_trace_msg(
      0x36u,
      2u,
      v63,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wma_csa_offload_handler",
      v61,
      v62,
      v64,
      v65,
      v155);
    goto LABEL_16;
  }
  v31 = *(unsigned __int8 *)(peer_by_mac[11] + 104LL);
  wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 8u, v23, v24, v25, v26, v27, v28, v29, v30);
  v32 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 24),
          v31,
          8);
  if ( !v32 )
  {
    v62 = (unsigned __int8)v157;
    v64 = BYTE1(v157);
    v63 = "%s: NULL vdev, vdev_id %d peer mac addr %02x:%02x:%02x:**:**:%02x";
    v65 = BYTE2(v157);
    v61 = v31;
    v155 = HIBYTE(v158);
    goto LABEL_15;
  }
  v33 = v32;
  v34 = _qdf_mem_malloc(0x20u, "wma_csa_offload_handler", 1753);
  if ( v34 )
  {
    v44 = (unsigned __int8 *)v34;
    if ( wlan_cm_is_vdev_roaming(v33, v36, v37, v38, v39, v40, v41, v42, v43) )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Roaming in progress for vdev %d, ignore csa event",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "wma_csa_offload_handler",
        v31);
LABEL_9:
      _qdf_mem_free((__int64)v44);
      goto LABEL_10;
    }
    qdf_mem_set(v44, 0x20u, 0);
    v67 = v158;
    v160 = 0;
    *((_DWORD *)v44 + 6) = v157;
    *((_WORD *)v44 + 14) = v67;
    v68 = *(_QWORD *)(a1 + 32);
    v159 = 0;
    v156[0] = 0;
    wlan_reg_read_current_country(*(_QWORD *)(v68 + 80), &v159, v69, v70, v71, v72, v73, v74, v75, v76);
    v85 = *(_DWORD *)(v20 + 52);
    if ( (v85 & 1) != 0 )
    {
      v86 = *(unsigned __int8 *)(v20 + 27);
      *v44 = v86;
      *((_DWORD *)v44 + 1) = wlan_reg_legacy_chan_to_freq(v68, v86, v77, v78, v79, v80, v81, v82, v83, v84);
      v95 = 1;
      v44[8] = *(_BYTE *)(v20 + 26);
    }
    else
    {
      if ( (v85 & 2) == 0 )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: CSA Event error: No CSA IE present",
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          "wma_csa_offload_handler");
        goto LABEL_9;
      }
      *v44 = *(_BYTE *)(v20 + 36);
      v44[8] = *(_BYTE *)(v20 + 34);
      v96 = *(_BYTE *)(v20 + 35);
      v44[16] = v96;
      is_6ghz_op_class = wlan_reg_is_6ghz_op_class(v68, v96);
      v106 = *(unsigned __int8 *)(v20 + 36);
      if ( is_6ghz_op_class )
      {
        *((_DWORD *)v44 + 1) = wlan_reg_chan_band_to_freq(v68, v106, 4u, v98, v99, v100, v101, v102, v103, v104, v105);
        op_class_width = wlan_reg_get_op_class_width();
      }
      else
      {
        *((_DWORD *)v44 + 1) = wlan_reg_legacy_chan_to_freq(v68, v106, v98, v99, v100, v101, v102, v103, v104, v105);
        op_class_width = wlan_reg_dmn_get_chanwidth_from_opclass_auto(
                           (unsigned __int8 *)&v159,
                           *(_BYTE *)(v20 + 36),
                           *(_BYTE *)(v20 + 35),
                           v108,
                           v109,
                           v110,
                           v111,
                           v112,
                           v113,
                           v114,
                           v115);
      }
      wlan_reg_convert_chan_spacing_to_width(op_class_width, v156);
      chwidth_from_bw = wlan_reg_find_chwidth_from_bw(v156[0]);
      v95 = 2;
      *((_DWORD *)v44 + 3) = chwidth_from_bw;
    }
    *((_DWORD *)v44 + 5) |= v95;
    v117 = *(_DWORD *)(v20 + 52);
    if ( (v117 & 0x40) != 0 )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: WMI_CSWRAP_IE_EXT_VER_2 received",
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        "wma_csa_offload_handler");
      v117 = *(_DWORD *)(v20 + 52);
    }
    if ( (v117 & 4) != 0 )
    {
      v119 = *v44;
      v44[17] = *(_BYTE *)(v20 + 43);
      v120 = *(_BYTE *)(v20 + 44);
      v44[18] = v120;
      v121 = wlan_mlme_convert_vht_op_bw_to_phy_ch_width(*(_BYTE *)(v20 + 42), v119, *(_BYTE *)(v20 + 43), v120);
      v122 = *((_DWORD *)v44 + 5);
      *((_DWORD *)v44 + 3) = v121;
      v118 = v122 | 4;
    }
    else
    {
      if ( (v117 & 0x20) == 0 )
      {
        v118 = *((_DWORD *)v44 + 5);
LABEL_37:
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: CSA: BSSID %02x:%02x:%02x:**:**:%02x chan %d freq %d flag 0x%x width = %d freq1 = %d freq2 = %d op class = %d",
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          "wma_csa_offload_handler",
          v44[24],
          v44[25],
          v44[26],
          v44[29],
          *v44,
          *((_DWORD *)v44 + 1),
          v118,
          *((_DWORD *)v44 + 3),
          v44[17],
          v44[18],
          v44[16]);
        active_channel = wlan_vdev_get_active_channel(v33);
        if ( !active_channel )
        {
          qdf_trace_msg(
            0x31u,
            2u,
            "%s: failed to get active channel",
            v129,
            v130,
            v131,
            v132,
            v133,
            v134,
            v135,
            v136,
            "wma_csa_offload_handler");
          wlan_objmgr_vdev_release_ref(v33, 8u, v146, v147, v148, v149, v150, v151, v152, v153, v154);
          _qdf_mem_free((__int64)v44);
          result = 0;
          goto LABEL_17;
        }
        v137 = (unsigned __int16 *)active_channel;
        wlan_objmgr_vdev_release_ref(v33, 8u, v128, v129, v130, v131, v132, v133, v134, v135, v136);
        cds_freq_to_chan(*v137);
        if ( *v44 )
        {
          wma_send_msg(a1, 4297, v44, 0);
          result = 0;
          goto LABEL_17;
        }
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: CSA Event with channel %d. Ignore !!",
          v138,
          v139,
          v140,
          v141,
          v142,
          v143,
          v144,
          v145,
          "wma_csa_offload_handler",
          0);
        _qdf_mem_free((__int64)v44);
        goto LABEL_11;
      }
      v123 = (unsigned __int8 *)wma_parse_ch_switch_wrapper_ie(v20 + 60);
      if ( v123 )
      {
        v124 = *v44;
        v44[17] = v123[3];
        v125 = v123[4];
        v44[18] = v125;
        *((_DWORD *)v44 + 3) = wlan_mlme_convert_vht_op_bw_to_phy_ch_width(v123[2], v124, v123[3], v125);
        *(_DWORD *)(v20 + 52) |= 4u;
        v126 = *((_DWORD *)v44 + 5) | 4;
      }
      else
      {
        v126 = *((_DWORD *)v44 + 5);
      }
      v118 = v126 | 8;
    }
    *((_DWORD *)v44 + 5) = v118;
    goto LABEL_37;
  }
LABEL_10:
  wlan_objmgr_vdev_release_ref(v33, 8u, v35, v36, v37, v38, v39, v40, v41, v42, v43);
LABEL_11:
  wlan_mlme_send_csa_event_status_ind(v33, 0, v53, v54, v55, v56, v57, v58, v59, v60);
LABEL_16:
  result = 4294967274LL;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
