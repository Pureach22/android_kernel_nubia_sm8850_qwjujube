__int64 __fastcall mlme_vdev_obj_create_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  __int64 v10; // x19
  __int64 v11; // x8
  __int64 (__fastcall *v12)(__int64, __int64); // x8
  __int64 v13; // x1
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
  __int64 cmpt_obj; // x0
  __int64 v26; // x22
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  _QWORD *v36; // x20
  unsigned int (__fastcall *v37)(_QWORD); // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  const char *v46; // x2
  const char *v47; // x2
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x1
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 216);
    if ( v9 )
    {
      v10 = *(_QWORD *)(v9 + 80);
      if ( v10 )
      {
        v11 = *(_QWORD *)(v10 + 2128);
        if ( v11 )
        {
          v12 = *(__int64 (__fastcall **)(__int64, __int64))(v11 + 1592);
          if ( v12 )
          {
            v13 = *(unsigned __int8 *)(a1 + 168);
            v15 = *(_QWORD *)(v9 + 80);
            if ( *((_DWORD *)v12 - 1) != -132374536 )
              __break(0x8228u);
            v16 = v12(v15, v13);
            if ( v16 )
            {
              if ( v16 != 6 )
              {
                qdf_trace_msg(
                  0x68u,
                  2u,
                  "%s: The vdev response is pending for VDEV_%d status:%d",
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  v22,
                  v23,
                  v24,
                  "mlme_vdev_obj_create_handler",
                  *(unsigned __int8 *)(a1 + 168),
                  v16);
                return 16;
              }
              qdf_trace_msg(
                0x68u,
                2u,
                "%s: Go through, since timer initializes later.",
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                "mlme_vdev_obj_create_handler");
            }
            cmpt_obj = wlan_pdev_mlme_get_cmpt_obj(v9);
            if ( cmpt_obj )
            {
              v26 = cmpt_obj;
              v27 = _qdf_mem_malloc(0x400u, "mlme_vdev_obj_create_handler", 96);
              if ( !v27 )
                return 2;
              v36 = (_QWORD *)v27;
              wlan_minidump_log(v28, v29, v30, v31, v32, v33, v34, v35, v27, 1024, v10);
              v36[65] = a1;
              v37 = *(unsigned int (__fastcall **)(_QWORD))(v26 + 16);
              if ( *((_DWORD *)v37 - 1) != -1843776435 )
                __break(0x8228u);
              if ( v37(v36) )
              {
                v46 = "%s: Callbacks registration is failed";
              }
              else
              {
                if ( !(unsigned int)mlme_vdev_sm_create(v36) )
                {
                  if ( (unsigned int)wlan_cm_init((__int64)v36) )
                  {
                    qdf_trace_msg(
                      0x68u,
                      2u,
                      "%s: CM SM create failed",
                      v57,
                      v58,
                      v59,
                      v60,
                      v61,
                      v62,
                      v63,
                      v64,
                      "mlme_vdev_obj_create_handler");
                  }
                  else
                  {
                    if ( (unsigned int)mlme_vdev_ops_ext_hdl_create() )
                    {
                      qdf_trace_msg(
                        0x68u,
                        2u,
                        "%s: Legacy vdev object creation failed",
                        v65,
                        v66,
                        v67,
                        v68,
                        v69,
                        v70,
                        v71,
                        v72,
                        "mlme_vdev_obj_create_handler");
                    }
                    else
                    {
                      v36[124] = mlme_vdev_reconfig_timer_cb;
                      v36[125] = v36;
                      init_timer_key(v36 + 119, _os_timer_shim_4, 0, 0, 0);
                      wlan_objmgr_vdev_component_obj_attach(a1, 0, (__int64)v36, 0);
                      if ( !(unsigned int)mlme_vdev_ops_ext_hdl_post_create() )
                      {
                        qdf_mem_set((char *)v36 + 332, 0x50u, 255);
                        return 0;
                      }
                      qdf_trace_msg(
                        0x68u,
                        2u,
                        "%s: Legacy vdev object post creation failed",
                        v74,
                        v75,
                        v76,
                        v77,
                        v78,
                        v79,
                        v80,
                        v81,
                        "mlme_vdev_obj_create_handler");
                      timer_delete_sync(v36 + 119);
                      mlme_vdev_ops_ext_hdl_destroy();
                      wlan_objmgr_vdev_component_obj_detach(a1, 0, (__int64)v36);
                    }
                    wlan_cm_deinit((__int64)v36, v73);
                  }
                  mlme_vdev_sm_destroy(v36);
                  goto LABEL_31;
                }
                v46 = "%s: SME creation failed";
              }
              qdf_trace_msg(0x68u, 2u, v46, v38, v39, v40, v41, v42, v43, v44, v45, "mlme_vdev_obj_create_handler");
LABEL_31:
              wlan_minidump_remove(v49, v50, v51, v52, v53, v54, v55, v56, (__int64)v36, 1024, v10);
              _qdf_mem_free((__int64)v36);
              return 16;
            }
            v47 = "%s: PDEV MLME is NULL";
            goto LABEL_20;
          }
        }
        else
        {
          qdf_trace_msg(0x38u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mlme_get_lmac_tx_ops");
        }
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: Failed to get mlme txrx_ops PSOC_%d",
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          "mlme_vdev_obj_create_handler",
          *(unsigned __int8 *)(v10 + 48));
        return 16;
      }
      v47 = "%s: PSOC is NULL";
    }
    else
    {
      v47 = "%s:  PDEV is NULL";
    }
  }
  else
  {
    v47 = "%s:  VDEV is NULL";
  }
LABEL_20:
  qdf_trace_msg(0x68u, 2u, v47, a2, a3, a4, a5, a6, a7, a8, a9, "mlme_vdev_obj_create_handler");
  return 16;
}
