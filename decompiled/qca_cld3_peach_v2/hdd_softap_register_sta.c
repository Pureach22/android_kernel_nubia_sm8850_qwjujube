__int64 __fastcall hdd_softap_register_sta(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  __int64 v17; // x19
  __int64 v18; // x26
  _QWORD *context; // x25
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  char v28; // w22
  unsigned int v29; // w23
  bool v30; // zf
  int v31; // w27
  const void *v32; // x1
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  char v41; // w22
  __int64 vdev_by_user; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x26
  unsigned int *v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  int peer_ch_width; // w0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  _DWORD **v70; // x8
  _DWORD *v71; // x8
  unsigned int v72; // w25
  unsigned __int8 *v73; // x8
  __int64 v74; // x4
  __int64 v75; // x5
  __int64 v76; // x6
  __int64 v77; // x7
  int v78; // w8
  __int64 v80; // x5
  __int64 v81; // x6
  __int64 v82; // x7
  int v83; // w8
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
  unsigned int v100; // w0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  _QWORD *v110; // x22
  bool v111; // zf
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  __int64 v120; // [xsp+8h] [xbp-D8h]
  __int64 sta_info_by_mac; // [xsp+10h] [xbp-D0h] BYREF
  _QWORD v122[5]; // [xsp+18h] [xbp-C8h] BYREF
  __int64 (__fastcall *v123)(); // [xsp+40h] [xbp-A0h]
  __int64 v124; // [xsp+48h] [xbp-98h]
  __int64 v125; // [xsp+50h] [xbp-90h]
  __int64 v126; // [xsp+58h] [xbp-88h]
  __int64 v127; // [xsp+60h] [xbp-80h]
  __int64 v128; // [xsp+68h] [xbp-78h]
  __int64 v129; // [xsp+70h] [xbp-70h]
  __int64 v130; // [xsp+78h] [xbp-68h]
  __int64 v131; // [xsp+80h] [xbp-60h]
  __int64 v132; // [xsp+88h] [xbp-58h]
  __int64 v133; // [xsp+90h] [xbp-50h]
  __int64 v134; // [xsp+98h] [xbp-48h]
  __int64 v135; // [xsp+A0h] [xbp-40h]
  __int64 v136; // [xsp+A8h] [xbp-38h]
  __int64 v137; // [xsp+B0h] [xbp-30h]
  __int64 v138; // [xsp+B8h] [xbp-28h]
  __int64 v139; // [xsp+C0h] [xbp-20h] BYREF
  int v140; // [xsp+C8h] [xbp-18h]
  __int64 v141; // [xsp+D0h] [xbp-10h]

  v141 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)a1;
  v140 = 0;
  v139 = 0;
  v18 = *(_QWORD *)(v17 + 24);
  v137 = 0;
  v138 = 0;
  v135 = 0;
  v136 = 0;
  v133 = 0;
  v134 = 0;
  v131 = 0;
  v132 = 0;
  v129 = 0;
  v130 = 0;
  v127 = 0;
  v128 = 0;
  v125 = 0;
  v126 = 0;
  v123 = nullptr;
  v124 = 0;
  memset(v122, 0, sizeof(v122));
  context = _cds_get_context(71, (__int64)"hdd_softap_register_sta", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( a13 )
  {
    v28 = *(_BYTE *)(a13 + 32);
    v29 = hdd_convert_dot11mode_from_phymode(*(_DWORD *)(a13 + 48));
  }
  else
  {
    v28 = 0;
    v29 = 7;
  }
  v30 = *(_DWORD *)a12 == -1 && *(__int16 *)(a12 + 4) == -1;
  v31 = !v30;
  if ( v30 )
  {
    if ( *(_DWORD *)(v17 + 40) == 1
      && (wlan_vdev_mlme_is_mlo_vdev(
            *(_QWORD *)(*(_QWORD *)(v17 + 52832) + 32LL),
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27)
        & 1) != 0 )
    {
      v32 = (const void *)(a1 + 72);
    }
    else
    {
      v32 = (const void *)(v17 + 1617);
    }
  }
  else
  {
    v32 = (const void *)a12;
  }
  qdf_mem_copy((char *)&v139 + 2, v32, 6u);
  hdd_softap_init_tx_rx_sta((__int64 *)a1, (unsigned __int8 *)a12);
  sta_info_by_mac = hdd_get_sta_info_by_mac(v17 + 38848, a12, 8, 1);
  if ( !sta_info_by_mac )
  {
    qdf_trace_msg(0x33u, 8u, "%s: STA not found", v33, v34, v35, v36, v37, v38, v39, v40, "hdd_softap_register_sta");
    goto LABEL_31;
  }
  v41 = v28 & 1;
  v120 = v18;
  LOBYTE(v139) = v41;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 0x61u, (__int64)"hdd_softap_register_sta");
  if ( !vdev_by_user )
  {
LABEL_31:
    v72 = 4;
    goto LABEL_34;
  }
  v51 = vdev_by_user;
  ucfg_dp_add_latency_critical_client(vdev_by_user, v29, v43, v44, v45, v46, v47, v48, v49, v50);
  if ( !v31 )
  {
    qdf_mem_set(v122, 0xA8u, 0);
    v123 = hdd_wmm_classify_pkt_cb;
    ucfg_dp_softap_register_txrx_ops(v51, v122);
  }
  _hdd_objmgr_put_vdev_by_user(
    v51,
    0x61u,
    (__int64)"hdd_softap_register_sta",
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60);
  peer_ch_width = wlan_mlme_get_peer_ch_width(**(_QWORD **)(v17 + 24), (unsigned __int8 *)&v139 + 2);
  v140 = hdd_convert_ch_width_to_cdp_peer_bw(peer_ch_width);
  if ( !context || !*context || (v70 = *(_DWORD ***)(*context + 72LL)) == nullptr )
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v62, v63, v64, v65, v66, v67, v68, v69, "cdp_peer_register");
    v72 = 4;
LABEL_33:
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev %d cdp_peer_register() failed to register.  Status = %d [0x%08X]",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "hdd_softap_register_sta",
      *(unsigned __int8 *)(a1 + 8),
      v72,
      v72);
    hdd_put_sta_info_ref(v17 + 38848, &sta_info_by_mac, 1, 8);
    goto LABEL_34;
  }
  v71 = *v70;
  if ( !v71 )
  {
    v72 = 11;
    goto LABEL_33;
  }
  if ( *(v71 - 1) != -974215578 )
    __break(0x8228u);
  v72 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64 *))v71)(context, 0, &v139);
  if ( v72 )
    goto LABEL_33;
  v73 = (unsigned __int8 *)sta_info_by_mac;
  *(_BYTE *)(sta_info_by_mac + 48) = v41;
  v74 = *(unsigned __int8 *)(a1 + 8);
  if ( (a2 & 1) != 0 )
  {
    if ( v73 == (unsigned __int8 *)-32LL )
    {
      v77 = 0;
      v75 = 0;
      v76 = 0;
      v78 = 0;
    }
    else
    {
      v75 = v73[32];
      v76 = v73[33];
      v77 = v73[34];
      v78 = v73[37];
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Vdev %d ULA auth STA %02x:%02x:%02x:**:**:%02x Changing TL state to CONNECTED at Join time",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "hdd_softap_register_sta",
      v74,
      v75,
      v76,
      v77,
      v78);
    v72 = hdd_change_peer_state((unsigned __int8 *)a1, (__int64)&v139 + 2, 2, v84, v85, v86, v87, v88, v89, v90, v91);
    *(_DWORD *)(sta_info_by_mac + 44) = 2;
    goto LABEL_47;
  }
  if ( v73 == (unsigned __int8 *)-32LL )
  {
    v82 = 0;
    v80 = 0;
    v81 = 0;
    v83 = 0;
  }
  else
  {
    v80 = v73[32];
    v81 = v73[33];
    v82 = v73[34];
    v83 = v73[37];
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Vdev %d open/shared/FILS auth STA %02x:%02x:%02x:**:**:%02x Changing TL state to AUTHENTICATED at Join time",
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    "hdd_softap_register_sta",
    v74,
    v80,
    v81,
    v82,
    v83);
  v100 = hdd_change_peer_state((unsigned __int8 *)a1, (__int64)&v139 + 2, 3, v92, v93, v94, v95, v96, v97, v98, v99);
  *(_DWORD *)(sta_info_by_mac + 44) = 3;
  if ( *(_DWORD *)a12 == -1 && *(__int16 *)(a12 + 4) == -1 )
  {
    v72 = v100;
LABEL_47:
    v110 = (_QWORD *)v120;
    goto LABEL_48;
  }
  v110 = (_QWORD *)v120;
  v72 = wlan_hdd_send_sta_authorized_event(v17, v120, a12, v101, v102, v103, v104, v105, v106, v107, v108);
LABEL_48:
  v111 = *(_DWORD *)a12 == -1 && *(__int16 *)(a12 + 4) == -1;
  if ( !v111 && v29 <= 6 )
    ++*(_WORD *)(a1 + 2LL * v29 + 2624);
  hdd_put_sta_info_ref(v17 + 38848, &sta_info_by_mac, 1, 8);
  if ( !v31 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev %d Enabling queues",
      v112,
      v113,
      v114,
      v115,
      v116,
      v117,
      v118,
      v119,
      "hdd_softap_register_sta",
      *(unsigned __int8 *)(a1 + 8));
    wlan_hdd_netif_queue_control(v17, 5, 1);
  }
  wlan_mlme_update_oce_flags(v110[1]);
  ucfg_twt_init_context(*v110, a12, 255);
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return v72;
}
