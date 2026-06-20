__int64 __fastcall sme_add_key_krk(
        __int64 a1,
        unsigned __int8 a2,
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
  unsigned int v12; // w19
  __int64 v13; // x8
  _QWORD *vdev_by_id_from_pdev; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  __int64 rso_config_fl; // x0
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int *v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7

  if ( a4 <= 15 )
  {
    qdf_trace_msg(
      0x34u,
      3u,
      "%s: Invalid KRK keylength [= %d]",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "sme_add_key_krk",
      (unsigned int)a4);
    return 4294967274LL;
  }
  if ( !a1 || (v12 = a2, a2 > 5u) || (v13 = *(_QWORD *)(a1 + 17224)) == 0 || (*(_BYTE *)(v13 + 96LL * a2 + 1) & 1) == 0 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: incorrect session/vdev ID", a5, a6, a7, a8, a9, a10, a11, a12, "sme_add_key_krk");
    return 4294967274LL;
  }
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(a1 + 21560), a2, 0xBu);
  if ( vdev_by_id_from_pdev )
  {
    v24 = (__int64)vdev_by_id_from_pdev;
    rso_config_fl = wlan_cm_get_rso_config_fl(
                      (__int64)vdev_by_id_from_pdev,
                      (__int64)"sme_add_key_krk",
                      0x1AEDu,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      v22,
                      v23);
    if ( rso_config_fl )
    {
      qdf_mem_copy((void *)(rso_config_fl + 679), a3, 0x10u);
      wlan_objmgr_vdev_release_ref(v24, 0xBu, v35, v36, v37, v38, v39, v40, v41, v42, v43);
      return 0;
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v24, 0xBu, v26, v27, v28, v29, v30, v31, v32, v33, v34);
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: vdev object is NULL for vdev %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "sme_add_key_krk",
      v12);
    return 4;
  }
}
