_DWORD *__fastcall hdd_open_adapter(
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
  __int64 v35; // x0
  __int64 v36; // x22
  __int64 v37; // x26
  int v38; // w8
  _DWORD *v39; // x25
  void *ap_dev; // x0
  int v41; // w8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  const char *v50; // x2
  __int64 v51; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  _DWORD *result; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  _DWORD *v69; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x8
  const char *v79; // x20
  const char *v80; // x21
  __int64 v81; // x8
  const char *v82; // x20
  const char *v83; // x21
  bool v84; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v85; // [xsp+8h] [xbp-8h]

  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v84 = 0;
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
LABEL_39:
    result = nullptr;
    goto LABEL_40;
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
LABEL_38:
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
      goto LABEL_39;
    }
LABEL_37:
    v33 = 0;
    v31 = 0;
    v32 = 0;
    v34 = 0;
    goto LABEL_38;
  }
  if ( (*a7 & 1) != 0 )
  {
    v30 = "%s: not able to find the sta adapter";
    goto LABEL_3;
  }
  if ( (unsigned __int8)a2 <= 0x10u )
  {
    if ( ((1 << a2) & 0x109C4) != 0 )
      goto LABEL_10;
    if ( ((1 << a2) & 0xA) != 0 )
    {
      ap_dev = hdd_wlan_create_ap_dev(a1, a4, a5, a3, v22, v23, v24, v25, v26, v27, v28, v29);
      if ( !ap_dev )
        goto LABEL_27;
      v36 = *((_QWORD *)ap_dev + 4);
      v39 = ap_dev;
      if ( (unsigned int)ucfg_dp_create_intf(*a1, (unsigned __int8 *)ap_dev + 1617, v36) )
        goto LABEL_61;
      if ( (unsigned __int8)a2 == 1 )
        v41 = 3;
      else
        v41 = 9;
      v39[10] = (unsigned __int8)a2;
      v39[30] = v41;
      if ( !(unsigned int)hdd_register_interface(v39, a6 & 1, a7) )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: vdev %d Disabling queues",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "hdd_open_adapter",
          *(unsigned __int8 *)(*((_QWORD *)v39 + 6604) + 8LL));
        wlan_hdd_netif_queue_control(v39, 4, 1);
        *((_QWORD *)v39 + 6) = 0xFFFFFFFE00000LL;
        *((_QWORD *)v39 + 7) = v39 + 14;
        *((_QWORD *)v39 + 8) = v39 + 14;
        *((_QWORD *)v39 + 9) = hdd_ipv4_notifier_work_queue;
        *((_QWORD *)v39 + 10) = 0xFFFFFFFE00000LL;
        *((_QWORD *)v39 + 11) = v39 + 22;
        *((_QWORD *)v39 + 12) = v39 + 22;
        *((_QWORD *)v39 + 13) = hdd_ipv6_notifier_work_queue;
        if ( (unsigned __int8)a2 == 1 && (*(_DWORD *)a7 & 0x200) == 0 )
          *(_DWORD *)a7 |= 4u;
        goto LABEL_55;
      }
LABEL_32:
      v37 = (__int64)v39;
      goto LABEL_60;
    }
    if ( (unsigned __int8)a2 == 4 )
    {
      v51 = hdd_alloc_station_adapter(a1, a4, a5, a3, 4);
      if ( !v51 )
      {
        v30 = "%s: Failed to allocate adapter for FTM mode";
        goto LABEL_3;
      }
      v36 = *(_QWORD *)(v51 + 32);
      v39 = (_DWORD *)v51;
      if ( (unsigned int)ucfg_dp_create_intf(*a1, (unsigned __int8 *)(v51 + 1617), v36) )
      {
LABEL_61:
        if ( v36 )
          free_netdev(v36);
        goto LABEL_39;
      }
      v39[30] = 2;
      v39[10] = 4;
      if ( !(unsigned int)hdd_register_interface(v39, a6 & 1, a7) )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: vdev %d Disabling queues",
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          "hdd_open_adapter",
          *(unsigned __int8 *)(*((_QWORD *)v39 + 6604) + 8LL));
        v69 = v39;
        goto LABEL_54;
      }
      goto LABEL_32;
    }
  }
  if ( (_BYTE)a2 )
  {
    v50 = "%s: Invalid session type %d";
    goto LABEL_42;
  }
  if ( (*(_BYTE *)(a1[13] + 126) & 1) == 0 )
  {
    hdd_reset_locally_admin_bit(a1, a4);
    if ( (unsigned int)hdd_check_for_existing_macaddr(a1, a4) == 16 )
    {
      if ( a4 )
        goto LABEL_6;
      goto LABEL_37;
    }
  }
LABEL_10:
  v35 = hdd_alloc_station_adapter(a1, a4, a5, a3, a2);
  if ( !v35 )
  {
LABEL_27:
    v50 = "%s: failed to allocate adapter for session %d";
LABEL_42:
    qdf_trace_msg(0x33u, 2u, v50, v22, v23, v24, v25, v26, v27, v28, v29, "hdd_open_adapter", (unsigned __int8)a2);
    goto LABEL_39;
  }
  v36 = *(_QWORD *)(v35 + 32);
  v37 = v35;
  if ( (unsigned int)ucfg_dp_create_intf(*a1, (unsigned __int8 *)(v35 + 1617), v36) )
    goto LABEL_61;
  v38 = (unsigned __int8)a2;
  if ( (unsigned __int8)a2 > 6u )
  {
    v39 = (_DWORD *)v37;
    if ( (unsigned __int8)a2 != 16 )
    {
      if ( (unsigned __int8)a2 == 7 )
      {
        v38 = 10;
        goto LABEL_50;
      }
      goto LABEL_47;
    }
    v38 = 12;
  }
  else
  {
    v39 = (_DWORD *)v37;
    if ( (unsigned __int8)a2 != 2 )
    {
      if ( (unsigned __int8)a2 == 6 )
        goto LABEL_50;
LABEL_47:
      v38 = 2;
      goto LABEL_50;
    }
    v38 = 8;
  }
LABEL_50:
  v39[30] = v38;
  v39[10] = (unsigned __int8)a2;
  *((_QWORD *)v39 + 6) = 0xFFFFFFFE00000LL;
  *((_QWORD *)v39 + 7) = v39 + 14;
  *((_QWORD *)v39 + 8) = v39 + 14;
  *((_QWORD *)v39 + 9) = hdd_ipv4_notifier_work_queue;
  *((_QWORD *)v39 + 10) = 0xFFFFFFFE00000LL;
  *((_QWORD *)v39 + 11) = v39 + 22;
  *((_QWORD *)v39 + 12) = v39 + 22;
  *((_QWORD *)v39 + 13) = hdd_ipv6_notifier_work_queue;
  if ( (*a7 & 1) == 0 )
  {
    if ( !(unsigned int)hdd_register_interface(v39, a6 & 1, a7) )
    {
      v39 = (_DWORD *)v37;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: vdev %d Disabling queues",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "hdd_open_adapter",
        *(unsigned __int8 *)(*(_QWORD *)(v37 + 52832) + 8LL));
      v69 = (_DWORD *)v37;
LABEL_54:
      wlan_hdd_netif_queue_control(v69, 4, 1);
      goto LABEL_55;
    }
LABEL_60:
    ucfg_dp_destroy_intf(*a1, (unsigned __int8 *)(v37 + 1617));
    goto LABEL_61;
  }
LABEL_55:
  hdd_adapter_init_link_info(v39);
  hdd_adapter_enable_links(v39, a7);
  ucfg_psoc_mlme_get_11be_capab(*a1, &v84);
  if ( (*a7 & 4) != 0 && v84 )
    hdd_adapter_set_ml_adapter(v39);
  hdd_adapter_feature_update_work_init(v39);
  *((_BYTE *)v39 + 42083) = 1;
  hdd_init_completion(v39);
  *((_QWORD *)v39 + 5213) = 0xFFFFFFFE00000LL;
  *((_QWORD *)v39 + 5214) = v39 + 10428;
  *((_QWORD *)v39 + 5215) = v39 + 10428;
  *((_QWORD *)v39 + 5216) = wlan_hdd_cfg80211_scan_block_cb;
  *((_QWORD *)v39 + 5217) = v39 + 10434;
  *((_QWORD *)v39 + 5218) = v39 + 10434;
  *((_QWORD *)v39 + 5219) = 0x800000000LL;
  qdf_mutex_create((__int64)(v39 + 10440));
  v39[9900] = 0;
  *((_QWORD *)v39 + 4951) = 0;
  qdf_event_create(v39 + 13102);
  hdd_sta_info_init(v39 + 9712);
  hdd_sta_info_init(v39 + 9722);
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  v39[13199] = 0;
  if ( (unsigned int)hdd_add_adapter_back(a1, v39) )
  {
    hdd_adapter_feature_update_work_deinit(v39);
    hdd_cleanup_adapter(v39, a6 & 1);
    v37 = 0;
    goto LABEL_60;
  }
  hdd_apf_context_init(v39);
  ((void (__fastcall *)(__int64, _QWORD))policy_mgr_set_concurrency_mode)(*a1, (unsigned __int8)a2);
  if ( (unsigned int)hdd_debugfs_init(v39) )
  {
    v78 = *((_QWORD *)v39 + 4);
    v79 = "(unnamed net_device)";
    if ( *(_BYTE *)(v78 + 296) )
    {
      v80 = (const char *)(v78 + 296);
      if ( !strchr((const char *)(v78 + 296), 37) )
        v79 = v80;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: debugfs: Interface %s init failed",
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      "hdd_open_adapter",
      v79);
  }
  v81 = *((_QWORD *)v39 + 4);
  v82 = "(unnamed net_device)";
  if ( *(_BYTE *)(v81 + 296) )
  {
    v83 = (const char *)(v81 + 296);
    if ( !strchr((const char *)(v81 + 296), 37) )
      v82 = v83;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: %s interface created. iftype: %d",
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    v76,
    v77,
    "hdd_open_adapter",
    v82,
    (unsigned __int8)a2);
  if ( !v39[10] )
    wlan_hdd_debugfs_csr_init(v39);
  result = v39;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
