__int64 __fastcall hdd_ndi_drv_ndi_create_rsp_handler(
        unsigned __int8 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  __int64 *v13; // x23
  __int64 *link_info_by_vdev; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  __int64 v24; // x22
  __int64 v25; // x24
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x21
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w9
  char v44; // w2
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  const char *v53; // x2
  __int64 vdev_by_user; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x25
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int *v72; // x8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x3
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  _WORD v114[2]; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int16 v115; // [xsp+Ch] [xbp-24h] BYREF
  int v116; // [xsp+10h] [xbp-20h] BYREF
  __int16 v117; // [xsp+14h] [xbp-1Ch]
  __int64 v118; // [xsp+18h] [xbp-18h] BYREF
  __int64 v119; // [xsp+20h] [xbp-10h]
  __int64 v120; // [xsp+28h] [xbp-8h]

  v120 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v115 = 0;
  v114[0] = 0;
  v117 = -1;
  v116 = -1;
  v118 = 0;
  v119 = 0;
  result = (__int64)_cds_get_context(51, (__int64)"hdd_ndi_drv_ndi_create_rsp_handler", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v13 = (__int64 *)result;
    link_info_by_vdev = (__int64 *)hdd_get_link_info_by_vdev(result, a1);
    if ( !link_info_by_vdev )
    {
      v53 = "%s: Invalid vdev";
      goto LABEL_8;
    }
    v23 = (__int64)link_info_by_vdev;
    v24 = (__int64)(link_info_by_vdev + 10);
    v25 = *link_info_by_vdev;
    result = _qdf_mem_malloc(0x180u, "hdd_ndi_drv_ndi_create_rsp_handler", 1028);
    if ( result )
    {
      v34 = result;
      if ( *a2 )
      {
        qdf_trace_msg(
          0x33u,
          1u,
          "%s: NDI interface creation failed with reason %d",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "hdd_ndi_drv_ndi_create_rsp_handler",
          (unsigned int)a2[1]);
LABEL_6:
        hdd_cstats_log_ndi_create_resp_evt(v23, a2);
        hdd_save_peer(v24, (unsigned __int8 *)&v116, v35, v36, v37, v38, v39, v40, v41, v42);
        v43 = v116;
        v44 = *(_BYTE *)(v34 + 42);
        *(_WORD *)(v34 + 21) = v117;
        *(_DWORD *)(v34 + 17) = v43;
        hdd_roam_register_sta(
          (__int64 *)v23,
          (unsigned __int8 *)(v34 + 17),
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52);
        result = _qdf_mem_free(v34);
        goto LABEL_9;
      }
      qdf_trace_msg(
        0x33u,
        1u,
        "%s: NDI interface successfully created",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "hdd_ndi_drv_ndi_create_rsp_handler");
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(v23, 0x52u, (__int64)"hdd_ndi_drv_ndi_create_rsp_handler");
      if ( vdev_by_user )
      {
        v63 = vdev_by_user;
        ucfg_nan_set_ndp_create_transaction_id(vdev_by_user, 0, v55, v56, v57, v58, v59, v60, v61, v62);
        _ucfg_nan_set_ndi_state(v63, 1u, (__int64)"os_if_nan_set_ndi_state", v64, v65, v66, v67, v68, v69, v70, v71);
        _hdd_objmgr_put_vdev_by_user(
          v63,
          0x52u,
          (__int64)"hdd_ndi_drv_ndi_create_rsp_handler",
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80);
        wlan_hdd_netif_queue_control(v25, 5u, 1u, v81, v82, v83, v84, v85, v86, v87, v88);
        if ( (unsigned int)cfg_nan_get_ndp_inactivity_timeout(*v13, &v115, v89, v90, v91, v92, v93, v94, v95, v96) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to fetch inactivity timeout value",
            v97,
            v98,
            v99,
            v100,
            v101,
            v102,
            v103,
            v104,
            "hdd_ndi_drv_ndi_create_rsp_handler");
        LODWORD(v118) = 151;
        HIDWORD(v118) = v115;
        if ( (unsigned int)cfg_nan_get_ndp_keepalive_period(*v13, v114, v97, v98, v99, v100, v101, v102, v103, v104) )
        {
          v105 = 1;
        }
        else
        {
          v105 = 2;
          LODWORD(v119) = 155;
          HIDWORD(v119) = v114[0];
        }
        if ( (unsigned int)sme_send_multi_pdev_vdev_set_params(1, *(unsigned __int8 *)(v23 + 8), (__int64)&v118, v105) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: failed to send vdev set params",
            v106,
            v107,
            v108,
            v109,
            v110,
            v111,
            v112,
            v113,
            "hdd_ndi_drv_ndi_create_rsp_handler");
        goto LABEL_6;
      }
      _qdf_mem_free(v34);
      v53 = "%s: vdev is NULL";
LABEL_8:
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 v53,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 "hdd_ndi_drv_ndi_create_rsp_handler");
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
