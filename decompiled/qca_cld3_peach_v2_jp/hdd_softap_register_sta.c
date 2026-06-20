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
  char v20; // w22
  unsigned int v21; // w23
  const void *v22; // x1
  _BOOL4 v23; // w28
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  char v32; // w22
  __int64 vdev_by_user; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x26
  unsigned int *v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  int peer_ch_width; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  _DWORD **v61; // x8
  _DWORD *v62; // x8
  unsigned int v63; // w25
  unsigned __int8 *v64; // x8
  __int64 v65; // x4
  __int64 v66; // x5
  __int64 v67; // x6
  __int64 v68; // x7
  int v69; // w8
  __int64 v71; // x5
  __int64 v72; // x6
  __int64 v73; // x7
  int v74; // w8
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
  unsigned int v91; // w0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  _QWORD *v101; // x22
  bool v102; // zf
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  __int64 v111; // [xsp+8h] [xbp-D8h]
  __int64 sta_info_by_mac; // [xsp+10h] [xbp-D0h] BYREF
  _QWORD v113[5]; // [xsp+18h] [xbp-C8h] BYREF
  __int64 (__fastcall *v114)(); // [xsp+40h] [xbp-A0h]
  __int64 v115; // [xsp+48h] [xbp-98h]
  __int64 v116; // [xsp+50h] [xbp-90h]
  __int64 v117; // [xsp+58h] [xbp-88h]
  __int64 v118; // [xsp+60h] [xbp-80h]
  __int64 v119; // [xsp+68h] [xbp-78h]
  __int64 v120; // [xsp+70h] [xbp-70h]
  __int64 v121; // [xsp+78h] [xbp-68h]
  __int64 v122; // [xsp+80h] [xbp-60h]
  __int64 v123; // [xsp+88h] [xbp-58h]
  __int64 v124; // [xsp+90h] [xbp-50h]
  __int64 v125; // [xsp+98h] [xbp-48h]
  __int64 v126; // [xsp+A0h] [xbp-40h]
  __int64 v127; // [xsp+A8h] [xbp-38h]
  __int64 v128; // [xsp+B0h] [xbp-30h]
  __int64 v129; // [xsp+B8h] [xbp-28h]
  __int64 v130; // [xsp+C0h] [xbp-20h] BYREF
  int v131; // [xsp+C8h] [xbp-18h]
  __int64 v132; // [xsp+D0h] [xbp-10h]

  v132 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)a1;
  v131 = 0;
  v130 = 0;
  v18 = *(_QWORD *)(v17 + 24);
  v128 = 0;
  v129 = 0;
  v126 = 0;
  v127 = 0;
  v124 = 0;
  v125 = 0;
  v122 = 0;
  v123 = 0;
  v120 = 0;
  v121 = 0;
  v118 = 0;
  v119 = 0;
  v116 = 0;
  v117 = 0;
  v114 = nullptr;
  v115 = 0;
  memset(v113, 0, sizeof(v113));
  context = _cds_get_context(71, (__int64)"hdd_softap_register_sta", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( a13 )
  {
    v20 = *(_BYTE *)(a13 + 32);
    v21 = hdd_convert_dot11mode_from_phymode(*(_DWORD *)(a13 + 48));
  }
  else
  {
    v20 = 0;
    v21 = 7;
  }
  if ( *(unsigned __int16 *)(a12 + 4) ^ 0xFFFF | ~*(_DWORD *)a12 )
    v22 = (const void *)a12;
  else
    v22 = (const void *)(v17 + 1617);
  v23 = (*(unsigned __int16 *)(a12 + 4) ^ 0xFFFF | ~*(_DWORD *)a12) != 0;
  qdf_mem_copy((char *)&v130 + 2, v22, 6u);
  hdd_softap_init_tx_rx_sta((__int64 *)a1, (unsigned __int8 *)a12);
  sta_info_by_mac = hdd_get_sta_info_by_mac(v17 + 38848, a12, 8, 1);
  if ( !sta_info_by_mac )
  {
    qdf_trace_msg(0x33u, 8u, "%s: STA not found", v24, v25, v26, v27, v28, v29, v30, v31, "hdd_softap_register_sta");
    goto LABEL_22;
  }
  v32 = v20 & 1;
  v111 = v18;
  LOBYTE(v130) = v32;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 0x61u, (__int64)"hdd_softap_register_sta");
  if ( !vdev_by_user )
  {
LABEL_22:
    v63 = 4;
    goto LABEL_25;
  }
  v42 = vdev_by_user;
  ucfg_dp_add_latency_critical_client(vdev_by_user, v21, v34, v35, v36, v37, v38, v39, v40, v41);
  if ( !v23 )
  {
    qdf_mem_set(v113, 0xA8u, 0);
    v114 = hdd_wmm_classify_pkt_cb;
    ucfg_dp_softap_register_txrx_ops(v42, v113);
  }
  _hdd_objmgr_put_vdev_by_user(
    v42,
    0x61u,
    (__int64)"hdd_softap_register_sta",
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51);
  peer_ch_width = wlan_mlme_get_peer_ch_width(**(_QWORD **)(v17 + 24), (unsigned __int8 *)&v130 + 2);
  v131 = hdd_convert_ch_width_to_cdp_peer_bw(peer_ch_width);
  if ( !context || !*context || (v61 = *(_DWORD ***)(*context + 72LL)) == nullptr )
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v53, v54, v55, v56, v57, v58, v59, v60, "cdp_peer_register");
    v63 = 4;
LABEL_24:
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev %d cdp_peer_register() failed to register.  Status = %d [0x%08X]",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "hdd_softap_register_sta",
      *(unsigned __int8 *)(a1 + 8),
      v63,
      v63);
    hdd_put_sta_info_ref(v17 + 38848, &sta_info_by_mac, 1, 8);
    goto LABEL_25;
  }
  v62 = *v61;
  if ( !v62 )
  {
    v63 = 11;
    goto LABEL_24;
  }
  if ( *(v62 - 1) != -974215578 )
    __break(0x8228u);
  v63 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64 *))v62)(context, 0, &v130);
  if ( v63 )
    goto LABEL_24;
  v64 = (unsigned __int8 *)sta_info_by_mac;
  *(_BYTE *)(sta_info_by_mac + 48) = v32;
  v65 = *(unsigned __int8 *)(a1 + 8);
  if ( (a2 & 1) != 0 )
  {
    if ( v64 == (unsigned __int8 *)-32LL )
    {
      v68 = 0;
      v66 = 0;
      v67 = 0;
      v69 = 0;
    }
    else
    {
      v66 = v64[32];
      v67 = v64[33];
      v68 = v64[34];
      v69 = v64[37];
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Vdev %d ULA auth STA %02x:%02x:%02x:**:**:%02x Changing TL state to CONNECTED at Join time",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "hdd_softap_register_sta",
      v65,
      v66,
      v67,
      v68,
      v69);
    v63 = hdd_change_peer_state((unsigned __int8 *)a1, (__int64)&v130 + 2, 2, v75, v76, v77, v78, v79, v80, v81, v82);
    *(_DWORD *)(sta_info_by_mac + 44) = 2;
    goto LABEL_38;
  }
  if ( v64 == (unsigned __int8 *)-32LL )
  {
    v73 = 0;
    v71 = 0;
    v72 = 0;
    v74 = 0;
  }
  else
  {
    v71 = v64[32];
    v72 = v64[33];
    v73 = v64[34];
    v74 = v64[37];
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Vdev %d open/shared/FILS auth STA %02x:%02x:%02x:**:**:%02x Changing TL state to AUTHENTICATED at Join time",
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    "hdd_softap_register_sta",
    v65,
    v71,
    v72,
    v73,
    v74);
  v91 = hdd_change_peer_state((unsigned __int8 *)a1, (__int64)&v130 + 2, 3, v83, v84, v85, v86, v87, v88, v89, v90);
  *(_DWORD *)(sta_info_by_mac + 44) = 3;
  if ( *(_DWORD *)a12 == -1 && *(__int16 *)(a12 + 4) == -1 )
  {
    v63 = v91;
LABEL_38:
    v101 = (_QWORD *)v111;
    goto LABEL_39;
  }
  v101 = (_QWORD *)v111;
  v63 = wlan_hdd_send_sta_authorized_event(v17, v111, a12, v92, v93, v94, v95, v96, v97, v98, v99);
LABEL_39:
  v102 = *(_DWORD *)a12 == -1 && *(__int16 *)(a12 + 4) == -1;
  if ( !v102 && v21 <= 6 )
    ++*(_WORD *)(a1 + 2LL * v21 + 2352);
  hdd_put_sta_info_ref(v17 + 38848, &sta_info_by_mac, 1, 8);
  if ( !v23 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev %d Enabling queues",
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      "hdd_softap_register_sta",
      *(unsigned __int8 *)(a1 + 8));
    wlan_hdd_netif_queue_control(v17, 5, 1);
  }
  wlan_mlme_update_oce_flags(v101[1]);
  ucfg_twt_init_context(*v101, a12, 255);
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return v63;
}
