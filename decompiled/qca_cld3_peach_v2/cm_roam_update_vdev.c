__int64 __fastcall cm_roam_update_vdev(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *context; // x0
  unsigned int v13; // w19
  __int64 v14; // x9
  char v15; // w10
  __int64 *v16; // x22
  int chan_freq; // w0
  unsigned int v18; // w25
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x21
  __int16 v29; // w9
  __int64 v30; // x0
  __int64 v31; // x0
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x27
  __int64 v42; // x24
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int *v61; // x8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x0
  _BYTE *v71; // x25
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned int v80; // w26
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v89; // x0
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  __int64 *v98; // x0
  unsigned int v99; // w1
  __int64 v100; // x0
  _BYTE *v101; // x25
  unsigned int v102; // w26
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  __int64 vdev_bssid; // x0
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  void *v120; // x24
  bool is_mlo_vdev; // w25
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  __int64 v130; // x5
  unsigned int v131; // w0
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  __int64 v140; // x4
  __int64 v141; // x5
  __int64 v142; // x6
  __int64 v143; // x7
  const char *v144; // x2
  unsigned int v145; // w0
  __int64 v146; // x8
  __int64 v147; // x0
  unsigned int param; // w25
  unsigned int v149; // w0
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  double v182; // d0
  double v183; // d1
  double v184; // d2
  double v185; // d3
  double v186; // d4
  double v187; // d5
  double v188; // d6
  double v189; // d7
  __int64 v190; // x8
  __int64 v192; // [xsp+0h] [xbp-20h] BYREF
  int v193; // [xsp+8h] [xbp-18h] BYREF
  __int16 v194; // [xsp+Ch] [xbp-14h]
  __int64 v195; // [xsp+18h] [xbp-8h]

  v195 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(54, (__int64)"cm_roam_update_vdev", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
  {
    v13 = *(unsigned __int8 *)(a1 + 168);
    v14 = context[65];
    v15 = *(_BYTE *)(a2 + 392);
    WORD2(v192) = 0;
    v16 = context;
    LODWORD(v192) = 0;
    *(_BYTE *)(v14 + 488LL * v13 + 236) = v15;
    *(_DWORD *)(context[65] + 488LL * v13 + 180) = *(_DWORD *)(a2 + 280);
    if ( (is_multi_link_roam(a2) & 1) != 0 )
      chan_freq = mlo_roam_get_chan_freq(v13, a2);
    else
      chan_freq = *(_DWORD *)(a2 + 64);
    *(_DWORD *)(v16[65] + 488LL * v13 + 436) = chan_freq;
    v19 = _qdf_mem_malloc(0x338u, "wma_roam_update_vdev", 721);
    if ( !v19 )
      goto LABEL_43;
    v28 = v19;
    if ( (is_multi_link_roam(a2) & 1) != 0 )
    {
      mlo_get_sta_link_mac_addr(v13, a2, &v192);
    }
    else
    {
      v29 = *(_WORD *)(a2 + 18);
      LODWORD(v192) = *(_DWORD *)(a2 + 14);
      WORD2(v192) = v29;
    }
    qdf_mem_set((void *)v28, 0x338u, 0);
    if ( (is_multi_link_roam(a2) & 1) != 0
      && (wlan_vdev_mlme_get_is_mlo_link(v16[3], v13) & 1) == 0
      && (mlo_get_single_link_ml_roaming(v16[3], v13) & 1) == 0 )
    {
LABEL_35:
      *(_BYTE *)(v28 + 8) = 0;
      *(_BYTE *)(v28 + 143) = v13;
      qdf_mem_copy((void *)v28, &v192, 6u);
      *(_WORD *)(v28 + 6) = *(_WORD *)(a2 + 304);
      vdev_bssid = wma_get_vdev_bssid(
                     *(_QWORD *)(v16[65] + 488LL * v13),
                     v103,
                     v104,
                     v105,
                     v106,
                     v107,
                     v108,
                     v109,
                     v110);
      if ( vdev_bssid )
      {
        v120 = (void *)vdev_bssid;
        is_mlo_vdev = wlan_vdev_mlme_get_is_mlo_vdev(v16[3], v13);
        if ( (is_multi_link_roam(a2) & 1) != 0 )
          v130 = a2 + 14;
        else
          v130 = 0;
        v131 = wma_create_peer(
                 (__int64)v16,
                 &v192,
                 0,
                 0,
                 v13,
                 v130,
                 is_mlo_vdev,
                 v122,
                 v123,
                 v124,
                 v125,
                 v126,
                 v127,
                 v128,
                 v129);
        if ( v131 )
        {
          v140 = (unsigned __int8)v192;
          v141 = BYTE1(v192);
          v18 = v131;
          v142 = BYTE2(v192);
          v143 = BYTE5(v192);
          v144 = "%s: Failed to create peer %02x:%02x:%02x:**:**:%02x";
LABEL_41:
          qdf_trace_msg(
            0x36u,
            2u,
            v144,
            v132,
            v133,
            v134,
            v135,
            v136,
            v137,
            v138,
            v139,
            "wma_roam_update_vdev",
            v140,
            v141,
            v142,
            v143,
            v192);
          goto LABEL_56;
        }
        if ( (is_multi_link_roam(a2) & 1) != 0 )
        {
          v145 = lim_roam_mlo_create_peer(v16[2], a2, v13, &v192);
          if ( v145 )
          {
            v140 = (unsigned __int8)v192;
            v141 = BYTE1(v192);
            v18 = v145;
            v142 = BYTE2(v192);
            v143 = BYTE5(v192);
            v144 = "%s: Failed to attach MLO peer %02x:%02x:%02x:**:**:%02x";
            goto LABEL_41;
          }
        }
        v146 = v16[65];
        v147 = *(_QWORD *)(v146 + 488LL * v13);
        if ( !*(_DWORD *)(v147 + 16) )
        {
          wlan_cdp_set_peer_freq(v16[3], &v192, *(unsigned int *)(v146 + 488LL * v13 + 436), v13);
          v147 = *(_QWORD *)(v16[65] + 488LL * v13);
        }
        param = wlan_crypto_get_param(v147, 1u);
        v149 = wlan_crypto_get_param(*(_QWORD *)(v16[65] + 488LL * v13), 4u);
        wma_set_peer_ucast_cipher((unsigned __int8 *)&v192, param, v149, v150, v151, v152, v153, v154, v155, v156, v157);
        wma_add_bss_lfr3((__int64)v16, *(unsigned __int8 **)(a2 + 272), v158, v159, v160, v161, v162, v163, v164, v165);
        wma_add_sta(v16, (unsigned __int8 *)v28, v166, v167, v168, v169, v170, v171, v172, v173);
        qdf_mem_copy(v120, &v192, 6u);
        lim_fill_roamed_peer_twt_caps(v16[2], v13, a2);
        _qdf_mem_free(v28);
        if ( (wlan_vdev_mlme_is_mlo_vdev(a1, v174, v175, v176, v177, v178, v179, v180, v181) & 1) != 0 )
        {
          if ( (wlan_vdev_mlme_is_mlo_vdev(a1, v182, v183, v184, v185, v186, v187, v188, v189) & 1) != 0
            && (*(_BYTE *)(a1 + 60) & 2) != 0 )
          {
            goto LABEL_61;
          }
          v190 = 80;
        }
        else
        {
          v190 = 74;
        }
        wlan_dp_update_def_link(v16[3], (unsigned __int8 *)(a1 + v190), a1);
LABEL_61:
        v18 = 0;
        goto LABEL_58;
      }
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to get bssid for vdev_%d",
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        "wma_roam_update_vdev",
        v13);
LABEL_43:
      v18 = 4;
LABEL_57:
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: VDEV update failed for roam on %d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "cm_roam_update_vdev",
        v13,
        v192);
      goto LABEL_58;
    }
    v30 = v16[3];
    v194 = 0;
    v193 = 0;
    v31 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v30, v13, 67);
    if ( !v31 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev object is NULL for vdev %d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "wma_delete_all_peers",
        v13);
      v18 = 29;
LABEL_56:
      _qdf_mem_free(v28);
      goto LABEL_57;
    }
    v41 = *(_QWORD *)(v31 + 1360);
    v42 = v31;
    if ( v41 )
    {
      v43 = *(_QWORD *)(v41 + 24);
      if ( !v43 )
        goto LABEL_18;
      if ( (unsigned int)wlan_vdev_get_bss_peer_mac(v43, &v193, v33, v34, v35, v36, v37, v38, v39, v40) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: bss peer is not present on vdev id %d, no need to cleanup",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "wma_delete_all_peers",
          *(unsigned __int8 *)(*(_QWORD *)(v41 + 24) + 168LL));
LABEL_18:
        v52 = *(_QWORD *)(v41 + 32);
        if ( !v52 )
        {
LABEL_34:
          wlan_objmgr_vdev_release_ref(v42, 0x43u, v32, v33, v34, v35, v36, v37, v38, v39, v40);
          goto LABEL_35;
        }
LABEL_19:
        if ( (unsigned int)wlan_vdev_get_bss_peer_mac(v52, &v193, v33, v34, v35, v36, v37, v38, v39, v40) )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: bss peer is not present on vdev id %d, no need to cleanup",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "wma_delete_all_peers",
            *(unsigned __int8 *)(*(_QWORD *)(v41 + 32) + 168LL));
          goto LABEL_34;
        }
        v100 = _qdf_mem_malloc(0x14u, "wma_delete_all_peers", 655);
        if ( v100 )
        {
          v101 = (_BYTE *)v100;
          lim_mlo_roam_peer_disconn_del(*(_QWORD *)(v41 + 32));
          qdf_mem_set(v101, 0x14u, 0);
          v102 = *(unsigned __int8 *)(*(_QWORD *)(v41 + 32) + 168LL);
          if ( v102 != 255 )
          {
            v101[10] = v102;
            wma_delete_sta((__int64)v16, (__int64)v101, v72, v73, v74, v75, v76, v77, v78, v79);
            v98 = v16;
            v99 = v102;
            goto LABEL_33;
          }
          goto LABEL_54;
        }
        goto LABEL_47;
      }
      v70 = _qdf_mem_malloc(0x14u, "wma_delete_all_peers", 655);
      if ( v70 )
      {
        v71 = (_BYTE *)v70;
        lim_mlo_roam_peer_disconn_del(*(_QWORD *)(v41 + 24));
        qdf_mem_set(v71, 0x14u, 0);
        v80 = *(unsigned __int8 *)(*(_QWORD *)(v41 + 24) + 168LL);
        if ( v80 == 255 )
        {
LABEL_54:
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: invalid vdev id",
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            "wma_delete_all_peers",
            v192);
          v18 = 4;
          goto LABEL_55;
        }
        v71[10] = v80;
        wma_delete_sta((__int64)v16, (__int64)v71, v72, v73, v74, v75, v76, v77, v78, v79);
        wma_delete_bss(v16, v80, v81, v82, v83, v84, v85, v86, v87, v88);
        v52 = *(_QWORD *)(v41 + 32);
        if ( !v52 )
          goto LABEL_34;
        goto LABEL_19;
      }
    }
    else
    {
      if ( *(_DWORD *)(v31 + 80) | *(unsigned __int16 *)(v31 + 84) )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: mlo_dev_ctx object is NULL for vdev %d",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "wma_delete_all_peers",
          v13);
        v18 = 29;
LABEL_55:
        wlan_objmgr_vdev_release_ref(v42, 0x43u, v61, v62, v63, v64, v65, v66, v67, v68, v69);
        goto LABEL_56;
      }
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: Non-ML STA vdev_id: %d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "wma_delete_all_peers",
        v13);
      v89 = _qdf_mem_malloc(0x14u, "wma_delete_bss_peer", 583);
      if ( v89 )
      {
        *(_BYTE *)(v89 + 10) = v13;
        wma_delete_sta((__int64)v16, v89, v62, v63, v64, v65, v66, v67, v68, v69);
        v98 = v16;
        v99 = v13;
LABEL_33:
        wma_delete_bss(v98, v99, v90, v91, v92, v93, v94, v95, v96, v97);
        goto LABEL_34;
      }
    }
LABEL_47:
    v18 = 2;
    goto LABEL_55;
  }
  v18 = 4;
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return v18;
}
