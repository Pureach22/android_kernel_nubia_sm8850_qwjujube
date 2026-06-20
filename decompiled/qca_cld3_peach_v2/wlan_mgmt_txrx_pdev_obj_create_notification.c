__int64 __fastcall wlan_mgmt_txrx_pdev_obj_create_notification(
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
  unsigned int v11; // w23
  unsigned int v12; // w24
  __int64 *v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 *v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w20
  const char *v41; // x2
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x22
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7

  if ( !a1 )
  {
    v41 = "%s: pdev context passed is NULL";
LABEL_8:
    qdf_trace_msg(0x4Bu, 2u, v41, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mgmt_txrx_pdev_obj_create_notification");
    return 4;
  }
  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 )
  {
    v41 = "%s: psoc context in pdev is NULL";
    goto LABEL_8;
  }
  v11 = *(unsigned __int8 *)(a1 + 40);
  v12 = *(unsigned __int8 *)(v9 + 48);
  qdf_trace_msg(
    0x4Bu,
    8u,
    "%s: enter pdev_id:%d psoc_id:%d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_mgmt_txrx_pdev_obj_create_notification",
    *(unsigned __int8 *)(a1 + 40),
    *(unsigned __int8 *)(v9 + 48));
  v13 = (__int64 *)_qdf_mem_malloc(0x110u, "wlan_mgmt_txrx_pdev_obj_create_notification", 197);
  if ( !v13 )
    return 2;
  v22 = v13;
  *v13 = a1;
  qdf_trace_msg(
    0x4Bu,
    8u,
    "%s: pool init pdev_id:%d psoc_id:%d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "wlan_mgmt_txrx_pdev_obj_create_notification",
    v11,
    v12);
  v31 = wlan_mgmt_txrx_desc_pool_init(v22, v23, v24, v25, v26, v27, v28, v29, v30);
  if ( v31 )
  {
    v40 = v31;
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: Failed to initialize mgmt desc. pool with status: %u",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "wlan_mgmt_txrx_pdev_obj_create_notification");
  }
  else
  {
    v43 = _qdf_mem_malloc(0x120u, "wlan_mgmt_txrx_pdev_obj_create_notification", 215);
    if ( v43 )
    {
      v52 = v43;
      v22[7] = v43;
      qdf_trace_msg(
        0x4Bu,
        8u,
        "%s: lock create pdev_id:%d psoc_id:%d",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "wlan_mgmt_txrx_pdev_obj_create_notification",
        v11,
        v12);
      _qdf_wake_lock_create(v22 + 8, (__int64)"mgmt_txrx tx_cmp");
      _qdf_runtime_lock_init(v22 + 33, "&mgmt_txrx_pdev_ctx->wakelock_tx_runtime_cmp");
      qdf_trace_msg(
        0x4Bu,
        8u,
        "%s: notification create pdev_id:%d psoc_id:%d",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "wlan_mgmt_txrx_pdev_obj_create_notification",
        v11,
        v12);
      qdf_trace_msg(
        0x4Bu,
        8u,
        "%s: obj attach pdev_id:%d psoc_id:%d",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "wlan_mgmt_txrx_pdev_obj_create_notification",
        v11,
        v12);
      if ( !(unsigned int)wlan_objmgr_pdev_component_obj_attach(a1, 1, v22, 0) )
      {
        qdf_trace_msg(
          0x4Bu,
          8u,
          "%s: Mgmt txrx creation successful, mgmt txrx ctx: %pK, pdev: %pK",
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          "wlan_mgmt_txrx_pdev_obj_create_notification",
          v22,
          a1);
        wlan_minidump_log(v22, 272, v9, 10, "mgmt_txrx_priv_pdev_context");
        wlan_minidump_log(v52, 288, v9, 11, "mgmt_txrx_stats_t");
        return 0;
      }
      qdf_trace_msg(
        0x4Bu,
        2u,
        "%s: Failed to attach mgmt txrx ctx in pdev ctx",
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        "wlan_mgmt_txrx_pdev_obj_create_notification");
      qdf_runtime_lock_deinit(v22 + 33);
      _qdf_wake_lock_destroy((__int64)(v22 + 8));
      _qdf_mem_free(v52);
      v40 = 16;
    }
    else
    {
      v40 = 2;
    }
    wlan_mgmt_txrx_desc_pool_deinit((__int64)v22, v44, v45, v46, v47, v48, v49, v50, v51);
  }
  _qdf_mem_free((__int64)v22);
  return v40;
}
