__int64 __fastcall sme_add_key_btk(
        _QWORD *a1,
        unsigned int a2,
        const void *a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w20
  __int64 v14; // x8
  _QWORD *vdev_by_id_from_pdev; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x22
  __int64 rso_config_fl; // x0
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

  if ( a4 <= 31 )
  {
    qdf_trace_msg(
      0x34u,
      3u,
      "%s: Invalid BTK keylength [= %d]",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "sme_add_key_btk",
      (unsigned int)a4);
    return 4294967274LL;
  }
  if ( !a1
    || (v12 = (unsigned __int8)a2, (unsigned __int8)a2 > 5u)
    || (v14 = a1[2162]) == 0
    || (*(_BYTE *)(v14 + 96LL * (unsigned __int8)a2 + 1) & 1) == 0 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: incorrect session/vdev ID", a5, a6, a7, a8, a9, a10, a11, a12, "sme_add_key_btk");
    return 4294967274LL;
  }
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1[2704], a2, 0xBu);
  if ( vdev_by_id_from_pdev )
  {
    v26 = (__int64)vdev_by_id_from_pdev;
    rso_config_fl = wlan_cm_get_rso_config_fl(
                      (__int64)vdev_by_id_from_pdev,
                      (__int64)"sme_add_key_btk",
                      0x1B12u,
                      v18,
                      v19,
                      v20,
                      v21,
                      v22,
                      v23,
                      v24,
                      v25);
    if ( rso_config_fl )
    {
      qdf_mem_copy((void *)(rso_config_fl + 695), a3, 0x20u);
      wlan_objmgr_vdev_release_ref(v26, 0xBu, v37, v38, v39, v40, v41, v42, v43, v44, v45);
      wlan_roam_update_cfg(a1[2703], a2, 0x25u);
      return 0;
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v26, 0xBu, v28, v29, v30, v31, v32, v33, v34, v35, v36);
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: vdev object is NULL for vdev %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "sme_add_key_btk",
      v12);
    return 4;
  }
}
