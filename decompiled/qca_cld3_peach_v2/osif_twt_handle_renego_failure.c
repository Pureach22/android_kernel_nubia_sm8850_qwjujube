__int64 __fastcall osif_twt_handle_renego_failure(__int64 result, unsigned int *a2)
{
  int v2; // w21
  __int64 v4; // x19
  char pdev_id_from_vdev_id; // w0
  __int64 pdev_by_id; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  _QWORD *vdev_by_id_from_pdev; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w2
  int *v26; // x1
  __int64 v27; // x20
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int *v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7

  if ( a2 )
  {
    v2 = *a2;
    v4 = result;
    pdev_id_from_vdev_id = wlan_get_pdev_id_from_vdev_id(result, *a2, 0x5Eu);
    pdev_by_id = wlan_objmgr_get_pdev_by_id(v4, pdev_id_from_vdev_id, 0x5Eu);
    if ( pdev_by_id )
    {
      v15 = pdev_by_id;
      vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(pdev_by_id, v2, 0x5Eu);
      if ( vdev_by_id_from_pdev )
      {
        v25 = a2[3];
        v26 = (int *)(a2 + 1);
        v27 = (__int64)vdev_by_id_from_pdev;
        ucfg_twt_set_work_params((__int64)vdev_by_id_from_pdev, v26, v25, 0, 1);
        queue_work_on(32, system_wq, v27 + 1368);
        wlan_objmgr_vdev_release_ref(v27, 0x5Eu, v28, v29, v30, v31, v32, v33, v34, v35, v36);
      }
      else
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: vdev object is NULL",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "osif_twt_handle_renego_failure");
      }
      return wlan_objmgr_pdev_release_ref(v15, 0x5Eu, v37, v38, v39, v40, v41, v42, v43, v44, v45);
    }
    else
    {
      return qdf_trace_msg(
               0x48u,
               2u,
               "%s: Invalid pdev",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "osif_twt_handle_renego_failure");
    }
  }
  return result;
}
