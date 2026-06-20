__int64 __fastcall wlan_hdd_cfg80211_init(
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
  __int64 v12; // x0
  int v13; // w8
  char v14; // w10
  char v15; // w9
  __int64 v16; // x0
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x0
  __int64 *v27; // x21
  __int64 v28; // x0
  __int64 v29; // x0
  char *v30; // x0
  char *v31; // x20
  const void *v32; // x1
  char *v33; // x0
  size_t v34; // x2
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 values; // x0
  int v38; // w23
  size_t v39; // x20
  void *v40; // x0
  void *v41; // x0
  __int64 v42; // x9
  int v43; // w10
  char v44; // w11
  int v45; // w8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7

  if ( !a2 )
  {
    __break(0x800u);
    JUMPOUT(0x2E95C4);
  }
  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_cfg80211_init");
  v12 = *(_QWORD *)(a2 + 1536);
  v13 = *(_DWORD *)(a2 + 100) | 0x3A0008;
  *(_QWORD *)(a2 + 488) = a1;
  *(_QWORD *)(a2 + 72) = &wlan_hdd_txrx_stypes;
  *(_DWORD *)(a2 + 100) = v13;
  if ( (unsigned int)ucfg_pmo_get_suspend_mode(v12) == 2 )
    *(_QWORD *)(a2 + 248) = &wowlan_support_cfg80211_init;
  v14 = *(_BYTE *)(a2 + 115);
  v15 = *(_BYTE *)(a2 + 114) | 0xC0;
  *(_DWORD *)(a2 + 100) |= 0x18000u;
  *(_BYTE *)(a2 + 114) = v15;
  *(_BYTE *)(a2 + 115) = v14 | 1;
  wlan_scan_cfg80211_add_connected_pno_support(a2);
  *(_BYTE *)(a2 + 136) = 10;
  *(_WORD *)(a2 + 140) = 2048;
  *(_DWORD *)(a2 + 96) = 2097996;
  v16 = _qdf_mem_malloc(0x380u, "wlan_hdd_cfg80211_init", 25836);
  *(_QWORD *)(a2 + 1648) = v16;
  if ( !v16 )
    return 4294967284LL;
  v17 = _qdf_mem_malloc(0x700u, "wlan_hdd_cfg80211_init", 25840);
  *(_QWORD *)(a2 + 1656) = v17;
  if ( v17 )
  {
    v26 = _qdf_mem_malloc(0x80u, "wlan_hdd_iftype_data_alloc", 25515);
    *(_QWORD *)(a2 + 1664) = v26;
    if ( !v26 )
    {
LABEL_29:
      _qdf_mem_free(*(_QWORD *)(a2 + 1656));
      *(_QWORD *)(a2 + 1656) = 0;
      goto LABEL_30;
    }
    v27 = (__int64 *)(a2 + 1664);
    v28 = _qdf_mem_malloc(0x80u, "wlan_hdd_iftype_data_alloc", 25522);
    *(_QWORD *)(a2 + 1672) = v28;
    if ( !v28 )
    {
      _qdf_mem_free(*v27);
LABEL_28:
      *v27 = 0;
      goto LABEL_29;
    }
    v29 = _qdf_mem_malloc(0x80u, "wlan_hdd_iftype_data_alloc_6ghz", 25483);
    *(_QWORD *)(a2 + 1680) = v29;
    if ( !v29 )
    {
      v35 = *(_QWORD *)(a2 + 1672);
LABEL_27:
      _qdf_mem_free(v35);
      _qdf_mem_free(*(_QWORD *)(a2 + 1664));
      *(_QWORD *)(a2 + 1672) = 0;
      goto LABEL_28;
    }
    if ( (ucfg_fwol_get_gcmp_enable(*(_QWORD *)(a2 + 1536)) & 1) != 0 )
    {
      v30 = (char *)_qdf_mem_malloc(0x38u, "wlan_hdd_cfg80211_init", 25850);
      if ( v30 )
      {
        v31 = v30;
        *(_DWORD *)(a2 + 156) = 14;
        qdf_mem_copy(v30, &hdd_cipher_suites, 0x30u);
        v32 = &hdd_gcmp_cipher_suits;
        v33 = v31 + 48;
        v34 = 8;
LABEL_16:
        qdf_mem_copy(v33, v32, v34);
        v36 = *(_QWORD *)(a2 + 1536);
        *(_QWORD *)(a2 + 160) = v31;
        *(_WORD *)(a2 + 9832) = 260;
        values = cfg_psoc_get_values(v36);
        v38 = *(unsigned __int8 *)(values + 8540);
        if ( *(_BYTE *)(values + 8540) )
          v39 = 96;
        else
          v39 = 80;
        v40 = (void *)_qdf_mem_malloc(v39, "wlan_hdd_update_akm_suite_info", 25634);
        *(_QWORD *)(a2 + 9880) = v40;
        if ( v40 )
        {
          qdf_mem_copy(v40, &hdd_sta_akm_suites, 0x50u);
          if ( v38 )
            qdf_mem_copy((void *)(*(_QWORD *)(a2 + 9880) + 80LL), &hdd_sta_fils_akm_suites, 0x10u);
          *(_QWORD *)(a2 + 9840) = *(_QWORD *)(a2 + 9880);
          *(_DWORD *)(a2 + 9848) = v39 >> 2;
          v41 = (void *)_qdf_mem_malloc(0x10u, "wlan_hdd_update_akm_suite_info", 25650);
          *(_QWORD *)(a2 + 9888) = v41;
          if ( v41 )
          {
            qdf_mem_copy(v41, &hdd_ap_akm_suites, 0x10u);
            v42 = *(_QWORD *)(a2 + 9888);
            v43 = *(_DWORD *)(a2 + 108);
            *(_WORD *)(a2 + 9856) = 520;
            v44 = *(_BYTE *)(a2 + 112);
            *(_DWORD *)(a2 + 9872) = 4;
            *(_DWORD *)(a2 + 128) = 1;
            *(_WORD *)(a2 + 264) = 2000;
            *(_QWORD *)(a2 + 9864) = v42;
            *(_QWORD *)(a2 + 1384) = 0x4B0000007CLL;
            *(_QWORD *)(a2 + 1368) = &hdd_wiphy_vendor_commands;
            *(_QWORD *)(a2 + 1376) = &wlan_hdd_cfg80211_vendor_events;
            LOBYTE(v42) = *(_BYTE *)(a2 + 116);
            *(_DWORD *)(a2 + 108) = v43 | 0x40204;
            *(_BYTE *)(a2 + 112) = v44 | 0xC0;
            v45 = *(_DWORD *)(a2 + 100);
            *(_BYTE *)(a2 + 116) = v42 | 4;
            LOBYTE(v42) = *(_BYTE *)(a2 + 113);
            *(_QWORD *)(a2 + 184) = a2 + 9832;
            *(_DWORD *)(a2 + 100) = v45 | 0x800000;
            *(_WORD *)(a2 + 1490) = 5;
            LOBYTE(v45) = v42 | 5;
            LOBYTE(v42) = *(_BYTE *)(a2 + 120);
            *(_BYTE *)(a2 + 113) = v45;
            *(_BYTE *)(a2 + 1400) = 3;
            *(_DWORD *)(a2 + 192) = 2;
            *(_BYTE *)(a2 + 1394) = 2;
            *(_BYTE *)(a2 + 120) = v42 | 1;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: enable puncture cap",
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              "wlan_hdd_set_ext_feature_punct");
            *(_BYTE *)(a2 + 119) |= 0x40u;
            qdf_trace_msg(0x33u, 8u, "%s: exit", v54, v55, v56, v57, v58, v59, v60, v61, "wlan_hdd_cfg80211_init");
            return 0;
          }
          _qdf_mem_free(*(_QWORD *)(a2 + 9880));
        }
        _qdf_mem_free(*(_QWORD *)(a2 + 160));
        *(_QWORD *)(a2 + 160) = 0;
        *(_DWORD *)(a2 + 156) = 0;
      }
    }
    else
    {
      v33 = (char *)_qdf_mem_malloc(0x30u, "wlan_hdd_cfg80211_init", 25861);
      if ( v33 )
      {
        v31 = v33;
        v32 = &hdd_cipher_suites;
        v34 = 48;
        *(_DWORD *)(a2 + 156) = 12;
        goto LABEL_16;
      }
    }
    _qdf_mem_free(*(_QWORD *)(a2 + 1680));
    v35 = *(_QWORD *)(a2 + 1672);
    *(_QWORD *)(a2 + 1680) = 0;
    goto LABEL_27;
  }
LABEL_30:
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Not enough memory to allocate channels",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "wlan_hdd_cfg80211_init");
  _qdf_mem_free(*(_QWORD *)(a2 + 1648));
  *(_QWORD *)(a2 + 1648) = 0;
  return 4294967284LL;
}
