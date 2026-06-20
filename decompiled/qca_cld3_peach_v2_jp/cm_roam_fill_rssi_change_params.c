__int64 __fastcall cm_roam_fill_rssi_change_params(__int64 a1, __int64 a2, _DWORD *a3)
{
  int v4; // w19
  int v5; // w21
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  __int64 rso_config_fl; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w2
  __int64 result; // x0
  unsigned int *v27; // x8
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
  unsigned int *v44; // x8
  _QWORD v45[4]; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v46[5]; // [xsp+28h] [xbp-28h] BYREF

  v4 = a2;
  v5 = a1;
  v46[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v46, 0, 32);
  memset(v45, 0, sizeof(v45));
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( v6 )
  {
    v15 = v6;
    rso_config_fl = wlan_cm_get_rso_config_fl(v6, "cm_roam_fill_rssi_change_params", 178);
    if ( rso_config_fl )
    {
      *a3 = (unsigned __int8)v4;
      if ( *(_BYTE *)(rso_config_fl + 1367) == 1 && *(_BYTE *)(rso_config_fl + 92) != 1 )
        v25 = 35;
      else
        v25 = 0;
      wlan_cm_roam_cfg_get_value(v5, v4, v25, (int)v46);
      a3[3] = HIDWORD(v46[0]);
      wlan_cm_roam_cfg_get_value(v5, v4, 41, (int)v45);
      v44 = (unsigned int *)LODWORD(v45[0]);
      if ( LODWORD(v45[0]) )
        a3[3] = 0;
      wlan_objmgr_vdev_release_ref(v15, 0x4Du, v44, v36, v37, v38, v39, v40, v41, v42, v43);
      wlan_cm_roam_cfg_get_value(v5, v4, 1, (int)v46);
      a3[1] = v46[0];
      wlan_cm_roam_cfg_get_value(v5, v4, 2, (int)v46);
      result = 0;
      a3[2] = v46[0];
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: rso_cfg is NULL",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "cm_roam_fill_rssi_change_params");
      wlan_objmgr_vdev_release_ref(v15, 0x4Du, v27, v28, v29, v30, v31, v32, v33, v34, v35);
      result = 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
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
      "cm_roam_fill_rssi_change_params",
      (unsigned __int8)v4);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
