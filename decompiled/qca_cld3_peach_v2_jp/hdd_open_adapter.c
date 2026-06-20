__int64 __fastcall hdd_open_adapter(
        __int64 *a1,
        unsigned int a2,
        const char *a3,
        unsigned __int8 *a4,
        unsigned int a5,
        char a6,
        _BYTE *a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  const char *v30; // x2
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7
  unsigned int v35; // w19
  __int64 v36; // x0
  __int64 v37; // x22
  char *v38; // x25
  int v39; // w8
  __int64 v40; // x24
  char *ap_dev; // x0
  int v42; // w8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  const char *v51; // x2
  __int64 v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 result; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  char *v70; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x8
  const char *v80; // x20
  const char *v81; // x21
  __int64 v82; // x8
  const char *v83; // x20
  const char *v84; // x21
  unsigned __int64 v91; // x10
  bool v92; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v93; // [xsp+8h] [xbp-8h]

  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v92 = 0;
  if ( (unsigned int)_wlan_hdd_validate_mac_address(
                       (__int64)a4,
                       (__int64)"hdd_open_adapter",
                       a8,
                       a9,
                       a10,
                       a11,
                       a12,
                       a13,
                       a14,
                       a15) )
  {
    v30 = "%s: Unable to add virtual intf: Not able to get valid mac address";
LABEL_3:
    qdf_trace_msg(0x33u, 2u, v30, v22, v23, v24, v25, v26, v27, v28, v29, "hdd_open_adapter");
LABEL_38:
    result = 0;
    goto LABEL_39;
  }
  if ( (unsigned int)hdd_check_for_existing_macaddr(a1, a4) == 16 )
  {
    if ( a4 )
    {
LABEL_6:
      v31 = *a4;
      v32 = a4[1];
      v33 = a4[2];
      v34 = a4[5];
LABEL_37:
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Duplicate MAC addr: %02x:%02x:%02x:**:**:%02x already exists",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_open_adapter",
        v31,
        v32,
        v33,
        v34);
      goto LABEL_38;
    }
LABEL_36:
    v33 = 0;
    v31 = 0;
    v32 = 0;
    v34 = 0;
    goto LABEL_37;
  }
  if ( (*a7 & 1) != 0 )
  {
    v30 = "%s: not able to find the sta adapter";
    goto LABEL_3;
  }
  v35 = (unsigned __int8)a2;
  if ( (unsigned __int8)a2 > 0x10u )
  {
LABEL_32:
    if ( (_BYTE)a2 )
    {
      v51 = "%s: Invalid session type %d";
      goto LABEL_41;
    }
    if ( (*(_BYTE *)(a1[13] + 126) & 1) == 0 )
    {
      hdd_reset_locally_admin_bit(a1, a4);
      if ( (unsigned int)hdd_check_for_existing_macaddr(a1, a4) == 16 )
      {
        if ( a4 )
          goto LABEL_6;
        goto LABEL_36;
      }
    }
    goto LABEL_10;
  }
  if ( ((1 << a2) & 0x109C4) != 0 )
  {
LABEL_10:
    v36 = hdd_alloc_station_adapter(a1, a4, a5, a3, a2);
    if ( v36 )
    {
      v37 = *(_QWORD *)(v36 + 32);
      v38 = (char *)v36;
      if ( (unsigned int)ucfg_dp_create_intf(*a1, (unsigned __int8 *)(v36 + 1617), v37) )
        goto LABEL_59;
      v39 = (unsigned __int8)a2;
      if ( (unsigned __int8)a2 > 6u )
      {
        v40 = (__int64)v38;
        if ( v39 != 16 )
        {
          if ( v39 == 7 )
          {
            v39 = 10;
            goto LABEL_49;
          }
          goto LABEL_46;
        }
        v39 = 12;
      }
      else
      {
        v40 = (__int64)v38;
        if ( v39 != 2 )
        {
          if ( v39 == 6 )
            goto LABEL_49;
LABEL_46:
          v39 = 2;
          goto LABEL_49;
        }
        v39 = 8;
      }
LABEL_49:
      *(_DWORD *)(v40 + 120) = v39;
      *(_DWORD *)(v40 + 40) = v35;
      *(_QWORD *)(v40 + 48) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v40 + 56) = v40 + 56;
      *(_QWORD *)(v40 + 64) = v40 + 56;
      *(_QWORD *)(v40 + 72) = hdd_ipv4_notifier_work_queue;
      *(_QWORD *)(v40 + 80) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v40 + 88) = v40 + 88;
      *(_QWORD *)(v40 + 96) = v40 + 88;
      *(_QWORD *)(v40 + 104) = hdd_ipv6_notifier_work_queue;
      if ( (*a7 & 1) != 0 )
        goto LABEL_54;
      if ( !(unsigned int)hdd_register_interface(v40, a6 & 1, a7) )
      {
        v40 = (__int64)v38;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: vdev %d Disabling queues",
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          "hdd_open_adapter",
          *(unsigned __int8 *)(*((_QWORD *)v38 + 6603) + 8LL));
        v70 = v38;
LABEL_53:
        wlan_hdd_netif_queue_control(v70, 4, 1);
        goto LABEL_54;
      }
      goto LABEL_58;
    }
    goto LABEL_26;
  }
  if ( ((1 << a2) & 0xA) == 0 )
  {
    if ( (unsigned __int8)a2 == 4 )
    {
      v52 = hdd_alloc_station_adapter(a1, a4, a5, a3, 4);
      if ( !v52 )
      {
        v30 = "%s: Failed to allocate adapter for FTM mode";
        goto LABEL_3;
      }
      v37 = *(_QWORD *)(v52 + 32);
      v40 = v52;
      if ( (unsigned int)ucfg_dp_create_intf(*a1, (unsigned __int8 *)(v52 + 1617), v37) )
      {
LABEL_59:
        if ( v37 )
          free_netdev(v37);
        goto LABEL_38;
      }
      *(_DWORD *)(v40 + 120) = 2;
      *(_DWORD *)(v40 + 40) = 4;
      if ( !(unsigned int)hdd_register_interface(v40, a6 & 1, a7) )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: vdev %d Disabling queues",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "hdd_open_adapter",
          *(unsigned __int8 *)(*(_QWORD *)(v40 + 52824) + 8LL));
        v70 = (char *)v40;
        goto LABEL_53;
      }
      v38 = (char *)v40;
LABEL_58:
      ucfg_dp_destroy_intf(*a1, (unsigned __int8 *)v38 + 1617);
      goto LABEL_59;
    }
    goto LABEL_32;
  }
  ap_dev = (char *)hdd_wlan_create_ap_dev(a1, a4, a5, a3, v22, v23, v24, v25, v26, v27, v28, v29);
  if ( !ap_dev )
  {
LABEL_26:
    v51 = "%s: failed to allocate adapter for session %d";
LABEL_41:
    qdf_trace_msg(0x33u, 2u, v51, v22, v23, v24, v25, v26, v27, v28, v29, "hdd_open_adapter", (unsigned __int8)a2);
    goto LABEL_38;
  }
  v37 = *((_QWORD *)ap_dev + 4);
  v38 = ap_dev;
  if ( (unsigned int)ucfg_dp_create_intf(*a1, (unsigned __int8 *)ap_dev + 1617, v37) )
    goto LABEL_59;
  if ( (unsigned __int8)a2 == 1 )
    v42 = 3;
  else
    v42 = 9;
  *((_DWORD *)v38 + 10) = (unsigned __int8)a2;
  *((_DWORD *)v38 + 30) = v42;
  if ( (unsigned int)hdd_register_interface(v38, a6 & 1, a7) )
    goto LABEL_58;
  v40 = (__int64)v38;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev %d Disabling queues",
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    "hdd_open_adapter",
    *(unsigned __int8 *)(*((_QWORD *)v38 + 6603) + 8LL));
  wlan_hdd_netif_queue_control(v38, 4, 1);
  *((_QWORD *)v38 + 6) = 0xFFFFFFFE00000LL;
  *((_QWORD *)v38 + 7) = v38 + 56;
  *((_QWORD *)v38 + 8) = v38 + 56;
  *((_QWORD *)v38 + 9) = hdd_ipv4_notifier_work_queue;
  *((_QWORD *)v38 + 10) = 0xFFFFFFFE00000LL;
  *((_QWORD *)v38 + 11) = v38 + 88;
  *((_QWORD *)v38 + 12) = v38 + 88;
  *((_QWORD *)v38 + 13) = hdd_ipv6_notifier_work_queue;
  if ( (*(_DWORD *)a7 & 0x200) == 0 )
    *(_DWORD *)a7 &= 0xFFFFFDFB;
LABEL_54:
  hdd_adapter_init_link_info(v40);
  if ( (*(_WORD *)a7 & 0x1C0) != 0 )
  {
    _X9 = (unsigned __int64 *)(v40 + 1640);
    __asm { PRFM            #0x11, [X9] }
    do
      v91 = __ldxr(_X9);
    while ( __stxr(v91 | 1, _X9) );
  }
  *(_BYTE *)(v40 + 1648) = 1;
  ucfg_psoc_mlme_get_11be_capab(*a1, &v92);
  hdd_adapter_feature_update_work_init(v40);
  *(_BYTE *)(v40 + 42083) = 1;
  hdd_init_completion(v40);
  *(_QWORD *)(v40 + 41704) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v40 + 41712) = v40 + 41712;
  *(_QWORD *)(v40 + 41720) = v40 + 41712;
  *(_QWORD *)(v40 + 41728) = wlan_hdd_cfg80211_scan_block_cb;
  *(_QWORD *)(v40 + 41736) = v40 + 41736;
  *(_QWORD *)(v40 + 41744) = v40 + 41736;
  *(_QWORD *)(v40 + 41752) = 0x800000000LL;
  qdf_mutex_create(v40 + 41760);
  *(_DWORD *)(v40 + 39600) = 0;
  *(_QWORD *)(v40 + 39608) = 0;
  qdf_event_create((_DWORD *)(v40 + 52408));
  hdd_sta_info_init(v40 + 38848);
  hdd_sta_info_init(v40 + 38888);
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  *(_DWORD *)(v40 + 52796) = 0;
  if ( (unsigned int)hdd_add_adapter_back(a1, v40) )
  {
    hdd_adapter_feature_update_work_deinit(v40);
    hdd_cleanup_adapter(v40, a6 & 1);
    v38 = nullptr;
    goto LABEL_58;
  }
  hdd_apf_context_init(v40);
  ((void (__fastcall *)(__int64, _QWORD))policy_mgr_set_concurrency_mode)(*a1, v35);
  if ( (unsigned int)hdd_debugfs_init(v40) )
  {
    v79 = *(_QWORD *)(v40 + 32);
    v80 = "(unnamed net_device)";
    if ( *(_BYTE *)(v79 + 296) )
    {
      v81 = (const char *)(v79 + 296);
      if ( !strchr((const char *)(v79 + 296), 37) )
        v80 = v81;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: debugfs: Interface %s init failed",
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      "hdd_open_adapter",
      v80);
  }
  v82 = *(_QWORD *)(v40 + 32);
  v83 = "(unnamed net_device)";
  if ( *(_BYTE *)(v82 + 296) )
  {
    v84 = (const char *)(v82 + 296);
    if ( !strchr((const char *)(v82 + 296), 37) )
      v83 = v84;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: %s interface created. iftype: %d",
    v71,
    v72,
    v73,
    v74,
    v75,
    v76,
    v77,
    v78,
    "hdd_open_adapter",
    v83,
    v35);
  if ( !*(_DWORD *)(v40 + 40) )
    wlan_hdd_debugfs_csr_init(v40);
  result = v40;
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
