__int64 __fastcall wlan_cm_store_mlo_roam_peer_address(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int64 is_vdev_active; // x8
  __int64 v22; // x19
  __int64 result; // x0
  _BYTE *ext_hdl_fl; // x22
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // [xsp+28h] [xbp-18h] BYREF
  __int16 v34; // [xsp+2Ch] [xbp-14h]
  __int64 v35; // [xsp+38h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v33 = 0;
  if ( !a1 )
  {
    result = qdf_trace_msg(
               0x68u,
               2u,
               "%s: pdev is NULL",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "wlan_cm_store_mlo_roam_peer_address");
    goto LABEL_9;
  }
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, *a2, 7u);
  if ( !vdev_by_id_from_pdev )
  {
    result = qdf_trace_msg(
               0x68u,
               2u,
               "%s: vdev %d not found",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "wlan_cm_store_mlo_roam_peer_address",
               *a2);
    goto LABEL_9;
  }
  is_vdev_active = *((unsigned __int8 *)vdev_by_id_from_pdev + 94);
  if ( (_DWORD)is_vdev_active == 1 )
  {
    v22 = (__int64)vdev_by_id_from_pdev;
    is_vdev_active = wlan_cm_is_vdev_active((__int64)vdev_by_id_from_pdev, v13, v14, v15, v16, v17, v18, v19, v20);
    vdev_by_id_from_pdev = (_QWORD *)v22;
    if ( (is_vdev_active & 1) != 0 )
    {
      is_vdev_active = *(unsigned int *)(v22 + 16);
      if ( (is_vdev_active & 0xFFFFFFFD) == 0 )
      {
        ext_hdl_fl = (_BYTE *)cm_get_ext_hdl_fl(
                                v22,
                                (__int64)"wlan_cm_store_mlo_roam_peer_address",
                                0x17F8u,
                                v13,
                                v14,
                                v15,
                                v16,
                                v17,
                                v18,
                                v19,
                                v20);
        vdev_by_id_from_pdev = (_QWORD *)v22;
        if ( ext_hdl_fl )
        {
          qdf_mem_set(ext_hdl_fl + 949, 6u, 0);
          qdf_mem_set(ext_hdl_fl + 955, 6u, 0);
          is_vdev_active = *(_DWORD *)(a2 + 7) | (unsigned int)*(unsigned __int16 *)(a2 + 11);
          if ( !(_DWORD)is_vdev_active )
          {
            ext_hdl_fl[948] = 0;
            goto LABEL_15;
          }
          is_vdev_active = (unsigned int)scm_get_mld_addr_by_link_addr(a1, a2 + 1, &v33);
          vdev_by_id_from_pdev = (_QWORD *)v22;
          if ( !(_DWORD)is_vdev_active )
          {
            ext_hdl_fl[948] = 1;
            qdf_mem_copy(ext_hdl_fl + 949, &v33, 6u);
            qdf_mem_copy(ext_hdl_fl + 955, a2 + 1, 6u);
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: mld addr %02x:%02x:%02x:**:**:%02xlink addr %02x:%02x:%02x:**:**:%02x",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              "wlan_cm_store_mlo_roam_peer_address",
              (unsigned __int8)ext_hdl_fl[949],
              (unsigned __int8)ext_hdl_fl[950],
              (unsigned __int8)ext_hdl_fl[951],
              (unsigned __int8)ext_hdl_fl[954],
              (unsigned __int8)ext_hdl_fl[955],
              (unsigned __int8)ext_hdl_fl[956],
              (unsigned __int8)ext_hdl_fl[957],
              (unsigned __int8)ext_hdl_fl[960]);
LABEL_15:
            vdev_by_id_from_pdev = (_QWORD *)v22;
          }
        }
      }
    }
  }
  result = wlan_objmgr_vdev_release_ref(
             (__int64)vdev_by_id_from_pdev,
             7u,
             (unsigned int *)is_vdev_active,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
