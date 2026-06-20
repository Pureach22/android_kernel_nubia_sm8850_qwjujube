__int64 __fastcall hdd_ndp_peer_departed_handler(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        int *a11,
        char a12)
{
  __int64 result; // x0
  __int64 *v16; // x19
  __int64 *link_info_by_vdev; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x23
  __int64 v27; // x24
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x1
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
  const char *v69; // x2

  result = (__int64)_cds_get_context(51, (__int64)"hdd_ndp_peer_departed_handler", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !result )
    return result;
  v16 = (__int64 *)result;
  link_info_by_vdev = (__int64 *)hdd_get_link_info_by_vdev(result, a1);
  if ( !link_info_by_vdev )
  {
    v69 = "%s: Invalid vdev";
    return qdf_trace_msg(0x33u, 2u, v69, v18, v19, v20, v21, v22, v23, v24, v25, "hdd_ndp_peer_departed_handler");
  }
  v26 = *link_info_by_vdev;
  v27 = (__int64)link_info_by_vdev;
  hdd_delete_peer(*link_info_by_vdev, (__int64)(link_info_by_vdev + 10), (__int64)a11);
  ucfg_nan_clear_peer_mc_list(*v16, *(_QWORD *)(v27 + 32), (__int64)a11, v28, v29, v30, v31, v32, v33, v34, v35);
  if ( !*v16 )
  {
    v69 = "%s: psoc is null";
    return qdf_trace_msg(0x33u, 2u, v69, v18, v19, v20, v21, v22, v23, v24, v25, "hdd_ndp_peer_departed_handler");
  }
  result = ucfg_nan_remove_ndp_peer_mac_addr(*v16, a11, v18, v19, v20, v21, v22, v23, v24, v25);
  if ( (a12 & 1) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: No more ndp peers.",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "hdd_ndp_peer_departed_handler");
    hdd_cleanup_ndi(v27, v44, v45, v46, v47, v48, v49, v50, v51);
    qdf_event_set(v26 + 52408, v52);
    if ( (ucfg_is_ndi_dbs_supported(*v16, v53, v54, v55, v56, v57, v58, v59, v60) & 1) == 0
      && (ucfg_is_nan_conc_control_supported(*v16, v61, v62, v63, v64, v65, v66, v67, v68) & 1) == 0 )
    {
      v61 = hdd_indicate_active_ndp_cnt(*v16, a1, 0, v61, v62, v63, v64, v65, v66, v67, v68);
    }
    return hdd_send_obss_scan_req((__int64)v16, 0, v61, v62, v63, v64, v65, v66, v67, v68);
  }
  return result;
}
