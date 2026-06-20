__int64 __fastcall cm_roam_restore_default_config(__int64 result, unsigned int a2)
{
  __int64 v2; // x20
  __int64 v4; // x21
  __int64 v5; // x22
  _QWORD *vdev_by_id_from_pdev; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x23
  __int64 rso_config_fl; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int *v25; // x8
  __int64 v26; // x24
  int roaming_triggers; // w0
  int v28; // w0
  __int64 v29; // [xsp+8h] [xbp-28h] BYREF
  __int64 v30; // [xsp+10h] [xbp-20h]
  __int64 v31; // [xsp+18h] [xbp-18h]
  __int64 v32; // [xsp+20h] [xbp-10h]
  __int64 v33; // [xsp+28h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(result + 80);
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  if ( v2 )
  {
    v4 = result;
    result = mlme_get_psoc_ext_obj_fl(v2);
    if ( result )
    {
      v5 = result;
      vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(v4, a2, 0x4Du);
      if ( vdev_by_id_from_pdev )
      {
        v15 = (__int64)vdev_by_id_from_pdev;
        rso_config_fl = wlan_cm_get_rso_config_fl(vdev_by_id_from_pdev, "cm_roam_clear_is_disable_btm_flag", 6008);
        if ( rso_config_fl )
        {
          v25 = (unsigned int *)*(unsigned __int8 *)(rso_config_fl + 1382);
          if ( (_DWORD)v25 == 1 )
          {
            v26 = rso_config_fl;
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: vdev: %d clear is_disable_btm flag",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              "cm_roam_clear_is_disable_btm_flag",
              (unsigned __int8)a2);
            *(_BYTE *)(v26 + 1382) = 0;
          }
        }
        else
        {
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: vdev: %d rso_cfg is NULL",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "cm_roam_clear_is_disable_btm_flag",
            (unsigned __int8)a2);
        }
        wlan_objmgr_vdev_release_ref(v15, 0x4Du, v25, v17, v18, v19, v20, v21, v22, v23, v24);
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
          "cm_roam_clear_is_disable_btm_flag",
          (unsigned __int8)a2);
      }
      if ( *(_BYTE *)(v5 + 1912) == 1 )
      {
        wlan_cm_roam_cfg_get_value(v2, a2, 9, (int)&v29);
        if ( (unsigned __int8)v30 == 1 )
        {
          roaming_triggers = wlan_mlme_get_roaming_triggers(v2);
          mlme_set_roam_trigger_bitmap(v2, a2, roaming_triggers);
        }
        LOBYTE(v30) = 0;
        wlan_cm_roam_cfg_set_value(v2, a2, 9, &v29);
        wlan_cm_roam_cfg_get_value(v2, a2, 43, (int)&v29);
        if ( (unsigned __int8)v30 == 1 )
        {
          v28 = wlan_mlme_get_roaming_triggers(v2);
          mlme_set_roam_trigger_bitmap(v2, a2, v28);
        }
        LOBYTE(v30) = 0;
        wlan_cm_roam_cfg_set_value(v2, a2, 43, &v29);
      }
      cm_roam_control_restore_default_config(v4, a2);
      mlme_set_roam_policy(v2, a2, 1);
      LOBYTE(v30) = 0;
      result = wlan_cm_roam_cfg_set_value(v2, a2, 32, &v29);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
