__int64 __fastcall hdd_ndi_drv_ndi_delete_rsp_handler(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  __int64 *link_info_by_vdev; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x1
  __int64 vdev_by_user; // x0
  __int64 v31; // x1
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x20
  double v41; // d0
  unsigned int *v42; // x8
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // [xsp+0h] [xbp-10h] BYREF
  __int64 v51; // [xsp+8h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v50) = -1;
  LODWORD(v50) = -1;
  result = (__int64)_cds_get_context(51, (__int64)"hdd_ndi_drv_ndi_delete_rsp_handler", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    link_info_by_vdev = (__int64 *)hdd_get_link_info_by_vdev(result, a1);
    if ( link_info_by_vdev )
    {
      v20 = *link_info_by_vdev;
      hdd_delete_peer(*link_info_by_vdev, (__int64)(link_info_by_vdev + 10), (__int64)&v50);
      wlan_hdd_netif_queue_control(v20, 4u, 1u, v21, v22, v23, v24, v25, v26, v27, v28);
      if ( *(_DWORD *)(v20 + 40) == 11 )
      {
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                         *(_QWORD *)(v20 + 52824),
                         0x52u,
                         (__int64)"hdd_ndp_session_end_handler");
        if ( vdev_by_user )
        {
          v40 = vdev_by_user;
          v41 = os_if_nan_ndi_session_end(vdev_by_user, v31);
          _hdd_objmgr_put_vdev_by_user(
            v40,
            0x52u,
            (__int64)"hdd_ndp_session_end_handler",
            v42,
            v41,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49);
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: vdev is NULL",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "hdd_ndp_session_end_handler",
            v50,
            v51);
        }
      }
      result = complete(v20 + 1744, v29);
    }
    else
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: Invalid vdev",
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 "hdd_ndi_drv_ndi_delete_rsp_handler",
                 v50,
                 v51);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
