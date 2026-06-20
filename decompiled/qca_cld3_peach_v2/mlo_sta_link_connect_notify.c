__int64 __fastcall mlo_sta_link_connect_notify(
        __int64 result,
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
  __int64 v10; // x21
  __int64 v11; // x22
  __int64 v12; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  const char *v30; // x2
  __int64 v31; // x20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  bool is_vdev_disconnected; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  void *v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x0
  size_t v75; // x0
  const void *v76; // x1
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x8

  v10 = *(_QWORD *)(result + 1360);
  if ( v10 )
  {
    v11 = *(_QWORD *)(v10 + 2224);
    v12 = result;
    if ( v11 && *(_QWORD *)(v11 + 280) )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Handle pending disconnect for vdev %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "mlo_sta_link_connect_notify",
        *(unsigned __int8 *)(result + 168));
      return mlo_handle_pending_disconnect(v12, v14, v15, v16, v17, v18, v19, v20, v21);
    }
    if ( (wlan_cm_is_link_switch_connect_resp(a2) & 1) != 0 )
    {
      v30 = "%s: Skip for link switch connect request";
      return qdf_trace_msg(0x8Fu, 4u, v30, v22, v23, v24, v25, v26, v27, v28, v29, "mlo_sta_link_connect_notify");
    }
    if ( (wlan_cm_is_link_add_connect_resp(a2) & 1) != 0 )
    {
      v30 = "%s: Skip for link_add connect request";
      return qdf_trace_msg(0x8Fu, 4u, v30, v22, v23, v24, v25, v26, v27, v28, v29, "mlo_sta_link_connect_notify");
    }
    result = wlan_cm_is_vdev_disconnected(v12, v22, v23, v24, v25, v26, v27, v28, v29);
    if ( (result & 1) == 0 || (*(_BYTE *)(v12 + 60) & 2) == 0 )
    {
      is_vdev_disconnected = wlan_cm_is_vdev_disconnected(v12, v32, v33, v34, v35, v36, v37, v38, v39);
      if ( v11 && is_vdev_disconnected )
      {
        qdf_trace_msg(0x8Fu, 8u, "%s: enter", v41, v42, v43, v44, v45, v46, v47, v48, "mlo_free_copied_conn_req");
        qdf_mutex_acquire(v11 + 40);
        v49 = *(void **)(v11 + 32);
        if ( v49 )
        {
          wlan_cm_free_connect_req(v49);
          *(_QWORD *)(v11 + 32) = 0;
        }
        qdf_mutex_release(v11 + 40);
      }
      result = wlan_vdev_mlme_is_mlo_vdev(v12, v41, v42, v43, v44, v45, v46, v47, v48);
      if ( (result & 1) == 0 )
        goto LABEL_33;
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Vdev: %d",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "mlo_sta_link_connect_notify",
        *(unsigned __int8 *)(v12 + 168));
      if ( wlan_cm_is_vdev_disconnected(v12, v58, v59, v60, v61, v62, v63, v64, v65) )
        return mlo_handle_sta_link_connect_failure(v12, a2, v66, v67, v68, v69, v70, v71, v72, v73);
      result = wlan_cm_is_vdev_connected(v12, v66, v67, v68, v69, v70, v71, v72, v73);
      if ( (result & 1) != 0 )
      {
        if ( !v11 || (*(_DWORD *)(v12 + 60) & 2) != 0 )
        {
LABEL_32:
          mlo_mgr_update_parnter_info(v12, a2);
          result = mlo_send_link_connect(v12, a2);
LABEL_33:
          v85 = *(_QWORD *)(v12 + 1360);
          if ( v85 )
          {
            result = *(_QWORD *)(v85 + 2224);
            if ( result )
              return (__int64)qdf_mem_set((void *)result, 8u, 0);
          }
          return result;
        }
        v74 = *(_QWORD *)(v11 + 112);
        if ( v74 )
        {
          _qdf_mem_free(v74);
          *(_QWORD *)(v11 + 112) = 0;
        }
        v75 = *(unsigned int *)(a2 + 120);
        *(_DWORD *)(v11 + 104) = v75;
        result = _qdf_mem_malloc(v75, "mlo_sta_link_connect_notify", 1657);
        *(_QWORD *)(v11 + 112) = result;
        if ( result )
        {
          v76 = *(const void **)(a2 + 128);
          if ( v76 )
            qdf_mem_copy((void *)result, v76, *(unsigned int *)(a2 + 120));
          memcpy((void *)(v11 + 1168), (const void *)(a2 + 160), 0xB0u);
          mlo_update_connected_links(v12, 1);
          mlo_update_connected_links_bmap(v10, (unsigned __int8 *)(a2 + 160), v77, v78, v79, v80, v81, v82, v83, v84);
          goto LABEL_32;
        }
      }
    }
  }
  else
  {
    v31 = jiffies;
    if ( mlo_sta_link_connect_notify___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x8Fu,
                 8u,
                 "%s: mlo_dev_ctx is NULL",
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 "mlo_sta_link_connect_notify");
      mlo_sta_link_connect_notify___last_ticks = v31;
    }
  }
  return result;
}
