__int64 __fastcall sme_set_roam_score_delta_value(_QWORD *a1, unsigned int a2, unsigned int a3)
{
  __int64 v5; // x0
  _QWORD *vdev_by_id_from_pdev; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  __int64 rso_config_fl; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int *v26; // x8
  __int64 result; // x0
  _QWORD v28[5]; // [xsp+8h] [xbp-28h] BYREF

  v28[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a1[2704];
  memset(&v28[1], 0, 24);
  v28[0] = a3;
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(v5, a2, 0xBu);
  if ( !vdev_by_id_from_pdev )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: vdev object is NULL for vdev %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "sme_set_roam_score_delta_value",
      (unsigned __int8)a2);
LABEL_9:
    result = 4;
    goto LABEL_10;
  }
  v15 = (__int64)vdev_by_id_from_pdev;
  rso_config_fl = wlan_cm_get_rso_config_fl(
                    (__int64)vdev_by_id_from_pdev,
                    (__int64)"sme_set_roam_score_delta_value",
                    0x45CFu,
                    v7,
                    v8,
                    v9,
                    v10,
                    v11,
                    v12,
                    v13,
                    v14);
  if ( !rso_config_fl )
  {
    wlan_objmgr_vdev_release_ref(v15, 0xBu, v17, v18, v19, v20, v21, v22, v23, v24, v25);
    goto LABEL_9;
  }
  v26 = (unsigned int *)*(unsigned __int8 *)(rso_config_fl + 1383);
  if ( (_DWORD)v26 == 1 )
  {
    v26 = (unsigned int *)*(unsigned __int8 *)(rso_config_fl + 92);
    if ( ((unsigned __int8)v26 & 1) == 0 )
      wlan_cm_roam_cfg_set_value(a1[2703], a2, 0x22u, (unsigned int *)v28);
  }
  wlan_objmgr_vdev_release_ref(v15, 0xBu, v26, v18, v19, v20, v21, v22, v23, v24, v25);
  *(_DWORD *)(a1[1] + 3632LL) = v28[0];
  result = wlan_cm_roam_cfg_set_value(a1[2703], a2, 0x2Au, (unsigned int *)v28);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
