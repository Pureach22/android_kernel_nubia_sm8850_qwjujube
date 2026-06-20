__int64 __fastcall wma_delete_bss(
        __int64 *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x25
  __int64 v22; // x21
  int bss_peer_mac; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x22
  const char *v33; // x2
  __int64 result; // x0
  int v35; // w23
  _QWORD *v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x8
  __int64 (*v46)(void); // x8
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 cmpt_obj; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  const char *v77; // x2
  const char *v78; // x3
  unsigned int v79; // w0
  unsigned int v80; // w1
  const char *v81; // x2
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  int v90; // w0
  unsigned int v91; // w23
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
  __int64 v132; // x9
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  _BYTE v141[4]; // [xsp+14h] [xbp-2Ch] BYREF
  _QWORD v142[3]; // [xsp+18h] [xbp-28h] BYREF
  int v143; // [xsp+30h] [xbp-10h] BYREF
  __int16 v144; // [xsp+34h] [xbp-Ch]
  __int64 v145; // [xsp+38h] [xbp-8h]

  v145 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v142, 0, sizeof(v142));
  context = _cds_get_context(71, (__int64)"wma_delete_bss", a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = a1[65] + 488LL * (unsigned __int8)a2;
  v144 = 0;
  v143 = 0;
  if ( !v21 || !*(_QWORD *)v21 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev id %d is already deleted",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_delete_bss",
      (unsigned __int8)a2);
    LODWORD(v32) = 0;
    goto LABEL_7;
  }
  v22 = (__int64)context;
  bss_peer_mac = wlan_vdev_get_bss_peer_mac(*(_QWORD *)v21, &v143, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( bss_peer_mac )
  {
    LODWORD(v32) = bss_peer_mac;
    v33 = "%s: vdev id %d : failed to get bssid";
LABEL_5:
    qdf_trace_msg(0x36u, 2u, v33, v24, v25, v26, v27, v28, v29, v30, v31, "wma_delete_bss", (unsigned __int8)a2);
    goto LABEL_7;
  }
  v32 = *(_QWORD *)v21 + 74LL;
  if ( *(_QWORD *)v21 == -74 )
  {
    v33 = "%s: vdev id %d : failed to get macaddr";
    goto LABEL_5;
  }
  v35 = *(_DWORD *)(a1[65] + 488LL * (unsigned __int8)a2 + 164);
  v36 = _cds_get_context(71, (__int64)"wma_cdp_find_peer_by_addr", v24, v25, v26, v27, v28, v29, v30, v31);
  if ( v35 != 7 )
  {
    if ( v36 )
    {
      if ( *v36 )
      {
        v47 = *(_QWORD *)(*v36 + 72LL);
        if ( v47 )
        {
          v46 = *(__int64 (**)(void))(v47 + 16);
          if ( v46 )
            goto LABEL_22;
LABEL_38:
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Failed to find peer %02x:%02x:%02x:**:**:%02x",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "wma_delete_bss",
            (unsigned __int8)v143,
            BYTE1(v143),
            BYTE2(v143),
            HIBYTE(v144));
LABEL_39:
          LODWORD(v32) = 16;
LABEL_7:
          result = _qdf_mem_malloc(8u, "wma_delete_bss", 6742);
          if ( result )
          {
            *(_BYTE *)(result + 4) = a2;
            *(_DWORD *)result = v32;
            result = wma_send_msg_high_priority(a1, 4136, result, 0);
          }
          goto LABEL_9;
        }
      }
      goto LABEL_35;
    }
LABEL_36:
    v77 = "%s: Failed to get pdev/soc";
    v78 = "wma_cdp_find_peer_by_addr";
    v79 = 54;
    v80 = 2;
    goto LABEL_37;
  }
  if ( !v36 )
    goto LABEL_36;
  if ( !*v36 || (v45 = *(_QWORD *)(*v36 + 72LL)) == 0 )
  {
LABEL_35:
    v77 = "%s invalid instance";
    v78 = "cdp_find_peer_exist";
    v79 = 69;
    v80 = 1;
LABEL_37:
    qdf_trace_msg(v79, v80, v77, v37, v38, v39, v40, v41, v42, v43, v44, v78);
    goto LABEL_38;
  }
  v46 = *(__int64 (**)(void))(v45 + 16);
  if ( !v46 )
    goto LABEL_38;
LABEL_22:
  if ( *((_DWORD *)v46 - 1) != 454466150 )
    __break(0x8228u);
  if ( (v46() & 1) == 0 )
    goto LABEL_38;
  v48 = *(_QWORD *)(a1[65] + 488LL * (unsigned __int8)a2);
  if ( !v48 )
  {
    v81 = "%s: vdev is NULL";
LABEL_42:
    qdf_trace_msg(0x36u, 2u, v81, v37, v38, v39, v40, v41, v42, v43, v44, "wma_get_vdev_bssid");
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to bssid for vdev_%d",
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      "wma_delete_bss",
      (unsigned __int8)a2);
    goto LABEL_39;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v48, v37, v38, v39, v40, v41, v42, v43, v44);
  if ( !cmpt_obj )
  {
    v81 = "%s: Failed to get mlme_obj";
    goto LABEL_42;
  }
  qdf_mem_set((void *)(cmpt_obj + 168), 6u, 0);
  wma_delete_invalid_peer_entries(a2, nullptr, v50, v51, v52, v53, v54, v55, v56, v57);
  v58 = *(_QWORD *)(v21 + 256);
  if ( v58 )
  {
    _qdf_mem_free(v58);
    *(_QWORD *)(v21 + 256) = 0;
  }
  v59 = *(_QWORD *)(v21 + 272);
  if ( v59 )
  {
    *(_QWORD *)(v21 + 272) = 0;
    _qdf_mem_free(v59);
  }
  v60 = *(_QWORD *)(v21 + 440);
  if ( v60 )
  {
    *(_QWORD *)(v21 + 440) = 0;
    _qdf_mem_free(v60);
  }
  if ( wlan_cm_is_roam_sync_in_progress(a1[3], a2) )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: LFR3: Setting vdev_up to FALSE for vdev:%d",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "wma_delete_bss",
      (unsigned __int8)a2);
    result = wma_remove_peer(a1, &v143, a2, 1, v69, v70, v71, v72, v73, v74, v75, v76);
    goto LABEL_9;
  }
  v90 = mlme_set_vdev_stop_type(*(_QWORD *)v21, 4135, v61, v62, v63, v64, v65, v66, v67, v68);
  if ( v90 )
  {
    LODWORD(v32) = v90;
    v33 = "%s: Failed to set wma req msg_type for vdev_id: %d";
    goto LABEL_5;
  }
  cdp_txrx_get_pdev_param(v22, *(unsigned __int8 *)(a1[4] + 40), v142);
  v91 = v142[0];
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Outstanding msdu packets: %u",
    v92,
    v93,
    v94,
    v95,
    v96,
    v97,
    v98,
    v99,
    "wma_delete_bss",
    LODWORD(v142[0]));
  wma_wait_tx_complete(a1, (unsigned __int8)a2);
  cdp_txrx_get_pdev_param(v22, *(unsigned __int8 *)(a1[4] + 40), v142);
  if ( v91 )
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Outstanding msdu packets before VDEV_STOP : %u",
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      "wma_delete_bss",
      v91);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev_id: %d, pausing tx_ll_queue for VDEV_STOP (del_bss)",
    v100,
    v101,
    v102,
    v103,
    v104,
    v105,
    v106,
    v107,
    "wma_delete_bss",
    (unsigned __int8)a2);
  wma_vdev_set_pause_bit(a2, v108, v109, v110, v111, v112, v113, v114, v115);
  cdp_fc_vdev_pause(v22, v116, v117, v118, v119, v120, v121, v122, v123);
  if ( (unsigned int)wma_send_vdev_stop_to_fw(a1, a2) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to send vdev stop to FW, explicitly invoke vdev stop rsp",
      v124,
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      v131,
      "wma_delete_bss");
    v132 = a1[65];
    v141[0] = a2;
    wlan_vdev_mlme_sm_deliver_evt(
      *(_QWORD *)(v132 + 488LL * (unsigned __int8)a2),
      0xEu,
      1u,
      (__int64)v141,
      v133,
      v134,
      v135,
      v136,
      v137,
      v138,
      v139,
      v140);
    *(_DWORD *)(v21 + 228) = 2;
  }
  result = qdf_trace_msg(
             0x36u,
             8u,
             "%s: bssid %02x:%02x:%02x:**:**:%02x vdev_id %d",
             v124,
             v125,
             v126,
             v127,
             v128,
             v129,
             v130,
             v131,
             "wma_delete_bss",
             (unsigned __int8)v143,
             BYTE1(v143),
             BYTE2(v143),
             HIBYTE(v144),
             (unsigned __int8)a2);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
