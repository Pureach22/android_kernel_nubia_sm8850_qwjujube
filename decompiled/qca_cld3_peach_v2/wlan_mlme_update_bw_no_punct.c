__int64 __fastcall wlan_mlme_update_bw_no_punct(__int64 a1, unsigned __int8 a2)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 pdev_by_id; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  _QWORD *vdev_by_id_from_pdev; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _QWORD *v24; // x22
  unsigned __int16 *v25; // x2
  unsigned int bw_no_punct; // w0
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w20
  unsigned int *v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 result; // x0
  unsigned int v47; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v48; // [xsp+8h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl && *(_BYTE *)(psoc_ext_obj_fl + 3600) == 1 )
  {
    pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, 0, 2u);
    if ( pdev_by_id )
    {
      v14 = pdev_by_id;
      vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(pdev_by_id, a2, 2u);
      if ( vdev_by_id_from_pdev )
      {
        v24 = vdev_by_id_from_pdev;
        v25 = (unsigned __int16 *)vdev_by_id_from_pdev[5];
        v47 = 0;
        bw_no_punct = wlan_mlme_get_bw_no_punct(a1, (__int64)vdev_by_id_from_pdev, v25, &v47);
        if ( !bw_no_punct )
          bw_no_punct = wlan_mlme_send_ch_width_update_with_notify(
                          a1,
                          v24,
                          a2,
                          v47,
                          v28,
                          v29,
                          v30,
                          v31,
                          v32,
                          v33,
                          v34,
                          v35);
        v36 = bw_no_punct;
        wlan_objmgr_vdev_release_ref((__int64)v24, 2u, v27, v28, v29, v30, v31, v32, v33, v34, v35);
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: VDEV not found for vdev id : %d",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "wlan_mlme_update_bw_no_punct",
          a2);
        v36 = 16;
      }
      wlan_objmgr_pdev_release_ref(v14, 2u, v37, v38, v39, v40, v41, v42, v43, v44, v45);
      result = v36;
    }
    else
    {
      qdf_trace_msg(0x34u, 2u, "%s: pdev is NULL", v6, v7, v8, v9, v10, v11, v12, v13, "wlan_mlme_update_bw_no_punct");
      result = 16;
    }
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
