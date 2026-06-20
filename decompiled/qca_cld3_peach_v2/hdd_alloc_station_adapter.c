__int64 __fastcall hdd_alloc_station_adapter(__int64 *a1, const void *a2, unsigned int a3, const char *a4, char a5)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 (**v18)(void); // x21
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v28; // x4
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x21
  __int64 v39; // x20
  __int64 v40; // x25
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x21
  size_t v50; // x0
  unsigned __int64 v51; // x2
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
  int conparam; // w0
  __int64 v69; // x22
  void *v70; // x8
  int v71; // w0
  __int16 v72; // w22
  __int64 v73; // x8
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 *v82; // x22
  __int64 v83; // x0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 v92; // x8
  __int64 v93; // x8
  unsigned __int64 v100; // x9
  unsigned __int8 v101[4]; // [xsp+0h] [xbp-10h] BYREF
  char v102[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v103; // [xsp+8h] [xbp-8h]

  v103 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v101[0] = 0;
  v18 = (__int64 (**)(void))hdd_mon_mode_ether_setup;
  if ( (unsigned int)cds_get_conparam() != 4 )
  {
    if ( _cds_get_context(51, (__int64)"wlan_hdd_is_session_type_monitor", v10, v11, v12, v13, v14, v15, v16, v17) )
    {
      if ( (unsigned int)cds_get_conparam() == 4 || a5 != 6 )
        v18 = &ether_setup;
    }
    else
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: HDD context is NULL",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "wlan_hdd_is_session_type_monitor");
      v18 = &ether_setup;
    }
  }
  if ( a5 )
    v28 = 17;
  else
    v28 = 46;
  v29 = alloc_netdev_mqs(71208, a4, a3, v18, v28, 5);
  if ( !v29 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to allocate new net_device '%s'",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "hdd_alloc_station_adapter",
      a4);
    v38 = 0;
    goto LABEL_43;
  }
  v38 = v29 + 2688;
  v39 = v29;
  v40 = v29 + 54786;
  qdf_mem_set((void *)(v29 + 2688), 0x11628u, 0);
  *(_QWORD *)(v39 + 2720) = v39;
  *(_QWORD *)(v39 + 2712) = a1;
  *(_QWORD *)(v40 + 734) = v39 + 55528;
  *(_DWORD *)(v39 + 2688) = 1885692259;
  while ( 1 )
  {
    _X8 = (unsigned __int64 *)(v39 + 4328);
    __asm { PRFM            #0x11, [X8] }
    do
      v100 = __ldxr(_X8);
    while ( __stxr(v100 | 1, _X8) );
    if ( a5 == 6 )
    {
      qdf_event_create((_DWORD *)(v39 + 4352));
      if ( (unsigned int)qdf_event_create((_DWORD *)(v39 + 4392)) )
      {
        v49 = jiffies;
        if ( hdd_alloc_station_adapter___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: create monitor mode vdve up event failed",
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            "hdd_alloc_station_adapter");
          hdd_alloc_station_adapter___last_ticks = v49;
        }
        free_netdev(*(_QWORD *)(v39 + 2720));
        v38 = 0;
        goto LABEL_43;
      }
    }
    hdd_update_dynamic_tsf_sync(v38);
    *(_BYTE *)(v39 + 4496) = 0;
    *(_BYTE *)(v40 + 110) = 1;
    *(_DWORD *)(v39 + 41616) = 0;
    v50 = strnlen(a4, 0x10u);
    if ( v50 == -1 )
    {
      _fortify_panic(2, -1, 0);
      goto LABEL_45;
    }
    v51 = v50 == 16 ? 16LL : v50 + 1;
    if ( v51 < 0x11 )
      break;
LABEL_45:
    _fortify_panic(7, 16, v51);
  }
  sized_strscpy(v39 + 296, a4, v51);
  dev_addr_mod(v39, 0, a2, 6);
  qdf_mem_copy((void *)(v39 + 4305), a2, 6u);
  *(_DWORD *)(v39 + 1296) = 1250;
  if ( _cds_get_context(51, (__int64)"wlan_hdd_is_session_type_monitor", v52, v53, v54, v55, v56, v57, v58, v59) )
  {
    conparam = cds_get_conparam();
    if ( a5 == 6 && conparam != 4 )
    {
      if ( (wlan_mlme_is_sta_mon_conc_supported(*a1) & 1) != 0 || ucfg_dp_is_local_pkt_capture_enabled() )
      {
        v69 = *(_QWORD *)(v39 + 2720);
        v70 = &wlan_mon_drv_ops;
        goto LABEL_35;
      }
      goto LABEL_36;
    }
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: HDD context is NULL",
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      "wlan_hdd_is_session_type_monitor");
  }
  v69 = *(_QWORD *)(v39 + 2720);
  v71 = cds_get_conparam();
  v70 = &wlan_drv_ops;
  if ( v71 == 4 )
    v70 = &wlan_mon_drv_ops;
LABEL_35:
  *(_QWORD *)(v69 + 8) = v70;
LABEL_36:
  v72 = 1;
  *(_BYTE *)(v39 + 1348) = 1;
  *(_QWORD *)(v39 + 992) = v39 + 2800;
  *(_DWORD *)(v39 + 1112) = 3000;
  v73 = a1[3];
  *(_QWORD *)(v39 + 2832) = v39;
  *(_QWORD *)(v39 + 2800) = v73;
  if ( (unsigned int)mlme_get_cfg_wlm_level(*a1, v101) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Can't get latency level",
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      "hdd_alloc_station_adapter");
    v101[0] = 1;
  }
  else
  {
    v72 = v101[0];
  }
  *(_WORD *)v40 = v72;
  v82 = *(__int64 **)(v39 + 2712);
  *(_WORD *)(v40 + 2) = 0;
  v83 = *v82;
  v102[0] = 0;
  ucfg_mlme_cfg_get_multi_client_ll_ini_support(v83, v102);
  LOBYTE(v82) = ucfg_mlme_get_wlm_multi_client_ll_caps(*v82);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: fw caps: %d, ini: %d",
    v84,
    v85,
    v86,
    v87,
    v88,
    v89,
    v90,
    v91,
    "hdd_set_multi_client_ll_support",
    (unsigned __int8)v82 & 1,
    (unsigned __int8)v102[0]);
  if ( ((unsigned __int8)v82 & 1) != 0 && v102[0] == 1 )
    *(_BYTE *)(v40 + 4) = v102[0];
  v92 = a1[12];
  *(_DWORD *)(v39 + 44788) = 0;
  *(_QWORD *)(v39 + 1472) = v92;
  v93 = jiffies;
  *(_QWORD *)(v39 + 44792) = jiffies;
  *(_QWORD *)(v39 + 44800) = v93;
  *(_DWORD *)(v39 + 4340) = 0;
  *(_DWORD *)(v39 + 4344) = 0;
  *(_QWORD *)(v39 + 73824) = 0;
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return v38;
}
