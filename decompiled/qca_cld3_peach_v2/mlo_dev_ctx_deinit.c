__int64 __fastcall mlo_dev_ctx_deinit(__int64 a1)
{
  __int64 mlo_ctx; // x19
  _QWORD *mld_ctx_by_mldaddr; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  __int64 v13; // x22
  __int64 v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x24
  __int16 v41; // w8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  int v58; // w8
  __int64 v59; // x8
  __int64 v60; // x0
  __int64 v61; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x0
  __int64 v79; // x8
  unsigned int (*v80)(void); // x8

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  mld_ctx_by_mldaddr = wlan_mlo_get_mld_ctx_by_mldaddr((const void *)(a1 + 80));
  v12 = *(_QWORD *)(a1 + 216);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: Failed to get psoc", v4, v5, v6, v7, v8, v9, v10, v11, "mlo_dev_ctx_deinit");
    return 16;
  }
  v14 = (__int64)mld_ctx_by_mldaddr;
  if ( mld_ctx_by_mldaddr
    || (qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Failed to get MLD dev context by mld addr %02x:%02x:%02x:**:**:%02x",
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          "mlo_dev_ctx_deinit",
          *(unsigned __int8 *)(a1 + 80),
          *(unsigned __int8 *)(a1 + 81),
          *(unsigned __int8 *)(a1 + 82),
          *(unsigned __int8 *)(a1 + 85)),
        (v14 = *(_QWORD *)(a1 + 1360)) != 0) )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: deleting vdev from MLD device ctx %02x:%02x:%02x:**:**:%02x",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "mlo_dev_ctx_deinit",
      *(unsigned __int8 *)(a1 + 80),
      *(unsigned __int8 *)(a1 + 81),
      *(unsigned __int8 *)(a1 + 82),
      *(unsigned __int8 *)(a1 + 85));
    wlan_minidump_remove(v15, v16, v17, v18, v19, v20, v21, v22, v14, 3904, v13);
    wlan_minidump_remove(v23, v24, v25, v26, v27, v28, v29, v30, mlo_ctx, 1264, v13);
    qdf_mutex_acquire(v14 + 1656);
    if ( *(_QWORD *)(v14 + 24) == a1 )
    {
      v39 = 0;
    }
    else
    {
      if ( *(_QWORD *)(v14 + 32) != a1 )
      {
LABEL_13:
        qdf_mutex_release(v14 + 1656);
        qdf_mutex_acquire(mlo_ctx);
        if ( !*(_WORD *)(v14 + 40) && !*(_WORD *)(v14 + 42) )
        {
          if ( *(_QWORD *)(v14 + 2232) )
          {
            wlan_mlo_vdev_aid_mgr_deinit(v14, v42, v43, v44, v45, v46, v47, v48, v49);
            qdf_mutex_destroy(*(_QWORD *)(v14 + 2232) + 16LL);
            _qdf_mem_free(*(_QWORD *)(v14 + 2232));
            *(_QWORD *)(v14 + 2232) = 0;
          }
          mlo_dev_mlpeer_list_deinit(v14);
          qdf_list_remove_node(mlo_ctx + 192, (_QWORD *)v14);
          v58 = *(_DWORD *)(a1 + 16);
          if ( v58 == 1 )
          {
            wlan_minidump_remove(v50, v51, v52, v53, v54, v55, v56, v57, *(_QWORD *)(v14 + 2232), 208, v13);
            _qdf_mem_free(*(_QWORD *)(v14 + 2232));
          }
          else if ( !v58 )
          {
            wlan_cm_free_connect_req(*(void **)(*(_QWORD *)(v14 + 2224) + 24LL));
            mlo_free_copied_conn_req(*(_QWORD *)(v14 + 2224));
            v59 = *(_QWORD *)(v14 + 2224);
            v60 = *(_QWORD *)(v59 + 280);
            if ( v60 )
            {
              _qdf_mem_free(v60);
              v59 = *(_QWORD *)(v14 + 2224);
            }
            v61 = *(_QWORD *)(v59 + 112);
            if ( v61 )
            {
              _qdf_mem_free(v61);
              v59 = *(_QWORD *)(v14 + 2224);
            }
            wlan_cm_free_connect_resp(*(void **)(v59 + 288));
            mlo_reset_cache_link_assoc_rsp(v14);
            qdf_mutex_destroy(*(_QWORD *)(v14 + 2224) + 40LL);
            wlan_minidump_remove(v62, v63, v64, v65, v66, v67, v68, v69, *(_QWORD *)(v14 + 2224), 1520, v13);
            _qdf_mem_free(*(_QWORD *)(v14 + 2224));
            *(_QWORD *)(v14 + 2224) = 0;
          }
          mlo_link_recfg_deinit(v14);
          mlo_mgr_link_switch_deinit(v14);
          wlan_mlo_t2lm_timer_deinit(a1);
          wlan_unregister_t2lm_link_update_notify_handler(v14, *(unsigned int *)(v14 + 3072));
          qdf_mutex_destroy(v14 + 3088);
          v78 = *(_QWORD *)(v13 + 2808);
          if ( !v78 )
            goto LABEL_33;
          if ( !*(_QWORD *)v78 )
            goto LABEL_33;
          v79 = *(_QWORD *)(*(_QWORD *)v78 + 176LL);
          if ( !v79 )
            goto LABEL_33;
          v80 = *(unsigned int (**)(void))(v79 + 24);
          if ( !v80 )
            goto LABEL_33;
          if ( *((_DWORD *)v80 - 1) != -951226545 )
            __break(0x8228u);
          if ( v80() )
LABEL_33:
            qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: Failed to destroy DP MLO Dev ctxt",
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              "mlo_dev_ctx_deinit");
          qdf_mutex_destroy(v14 + 1720);
          qdf_mutex_destroy(v14 + 1656);
          _qdf_mem_free(v14);
        }
        qdf_mutex_release(mlo_ctx);
        return 0;
      }
      v39 = 1;
    }
    if ( *(_DWORD *)(a1 + 16) == 1 )
      wlan_mlo_vdev_free_aid_mgr((_QWORD *)v14, a1, v31, v32, v33, v34, v35, v36, v37, v38);
    v41 = *(_WORD *)(v14 + 40);
    *(_QWORD *)(v14 + 24 + 8 * v39) = 0;
    *(_WORD *)(v14 + 40) = v41 - 1;
    *(_QWORD *)(a1 + 1360) = 0;
    goto LABEL_13;
  }
  qdf_trace_msg(
    0x8Fu,
    2u,
    "%s: Failed to get MLD dev context from vdev",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "mlo_dev_ctx_deinit");
  return 0;
}
