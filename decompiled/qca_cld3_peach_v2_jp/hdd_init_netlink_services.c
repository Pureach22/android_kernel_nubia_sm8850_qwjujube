__int64 __fastcall hdd_init_netlink_services(__int64 a1)
{
  unsigned int v2; // w0
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x3
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w19
  __int64 v15; // x0
  unsigned int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  _QWORD v68[6]; // [xsp+0h] [xbp-30h] BYREF

  v68[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = nl_srv_init();
  if ( v2 )
  {
    v14 = v2;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: nl_srv_init failed: %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "hdd_init_netlink_services",
      v2);
  }
  else
  {
    v15 = cds_set_radio_index(*(_DWORD *)(a1 + 1456), v3, v4, v5);
    v16 = os_if_wifi_pos_register_nl(v15);
    if ( v16 )
    {
      v14 = v16;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: os_if_wifi_pos_register_nl failed",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "hdd_activate_wifi_pos");
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: hdd_activate_wifi_pos failed: %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "hdd_init_netlink_services",
        v14);
    }
    else
    {
      ptt_sock_activate_svc();
      memset(&v68[1], 0, 32);
      v68[0] = 1;
      v34 = _netlink_kernel_create(&init_net, 30, &_this_module, v68);
      cesium_nl_srv_sock = v34;
      if ( !v34 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: NLINK:  cesium netlink_kernel_create failed",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "hdd_open_cesium_nl_sock");
        v34 = qdf_trace_msg(
                0x33u,
                2u,
                "%s: hdd_open_cesium_nl_sock failed ret: %d",
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                "hdd_init_netlink_services",
                4294967185LL);
      }
      v14 = cnss_diag_activate_service(v34);
      if ( !v14 )
      {
        spectral_scan_activate_service(a1);
        goto LABEL_6;
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: cnss_diag_activate_service failed: %d",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "hdd_init_netlink_services",
        v14);
      if ( cesium_nl_srv_sock )
      {
        netlink_kernel_release();
        cesium_nl_srv_sock = 0;
      }
      v59 = ptt_sock_deactivate_svc();
      if ( (unsigned int)os_if_wifi_pos_deregister_nl(v59) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: os_if_wifi_pos_deregister_nl failed",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "hdd_deactivate_wifi_pos");
    }
    nl_srv_exit();
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return v14;
}
