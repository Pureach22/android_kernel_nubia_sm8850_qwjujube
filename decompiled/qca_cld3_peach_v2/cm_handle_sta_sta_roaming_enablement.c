__int64 __fastcall cm_handle_sta_sta_roaming_enablement(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v5; // x0
  unsigned int *v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  __int64 v16; // x19
  unsigned int mode_specific_conn_info; // w23
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w25
  unsigned int v35; // w24
  unsigned int v36; // w24
  unsigned int v37; // w24
  unsigned int v38; // w24
  __int64 v39; // [xsp+0h] [xbp-10h] BYREF
  __int64 v40; // [xsp+8h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v39) = 0;
  LODWORD(v39) = 0;
  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    v5 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
    if ( v5 )
    {
      v15 = *(_QWORD *)(v5 + 216);
      v16 = v5;
      if ( v15 )
      {
        mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(a1, 0, (unsigned __int64)&v39, 0);
        if ( (wlan_mlme_get_dual_sta_roaming_enabled(a1) & 1) != 0 && mode_specific_conn_info > 1 )
        {
          if ( (policy_mgr_concurrent_sta_on_different_mac(a1) & 1) != 0 )
          {
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: After roam on vdev_id:%d, sta concurrency on different mac:%d",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              "cm_handle_sta_sta_roaming_enablement",
              (unsigned __int8)a2,
              mode_specific_conn_info);
            v34 = (unsigned __int8)v39;
            wlan_cm_roam_activate_pcl_per_vdev(a1, (unsigned __int8)v39, 1);
            policy_mgr_set_pcl_for_existing_combo(a1, 0, v34);
            if ( v34 != (unsigned __int8)a2 )
              if_mgr_enable_roaming(v15, v16, 32);
            v35 = BYTE1(v39);
            wlan_cm_roam_activate_pcl_per_vdev(a1, BYTE1(v39), 1);
            policy_mgr_set_pcl_for_existing_combo(a1, 0, v35);
            if ( v35 != (unsigned __int8)a2 )
              if_mgr_enable_roaming(v15, v16, 32);
            if ( mode_specific_conn_info != 2 )
            {
              v36 = BYTE2(v39);
              wlan_cm_roam_activate_pcl_per_vdev(a1, BYTE2(v39), 1);
              policy_mgr_set_pcl_for_existing_combo(a1, 0, v36);
              if ( v36 != (unsigned __int8)a2 )
                if_mgr_enable_roaming(v15, v16, 32);
              if ( mode_specific_conn_info != 3 )
              {
                v37 = BYTE3(v39);
                wlan_cm_roam_activate_pcl_per_vdev(a1, BYTE3(v39), 1);
                policy_mgr_set_pcl_for_existing_combo(a1, 0, v37);
                if ( v37 != (unsigned __int8)a2 )
                  if_mgr_enable_roaming(v15, v16, 32);
                if ( mode_specific_conn_info != 4 )
                {
                  v38 = BYTE4(v39);
                  wlan_cm_roam_activate_pcl_per_vdev(a1, BYTE4(v39), 1);
                  policy_mgr_set_pcl_for_existing_combo(a1, 0, v38);
                  if ( v38 != (unsigned __int8)a2 )
                    if_mgr_enable_roaming(v15, v16, 32);
                  if ( mode_specific_conn_info != 5 )
                  {
                    __break(0x5512u);
                    goto LABEL_22;
                  }
                }
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: After roam STA + STA concurrency is in MCC/SCC",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              "cm_handle_sta_sta_roaming_enablement");
          }
        }
        else
        {
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: Dual sta roaming is not enabled or count:%d",
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            "cm_handle_sta_sta_roaming_enablement",
            mode_specific_conn_info,
            v39,
            v40);
        }
      }
      result = wlan_objmgr_vdev_release_ref(v16, 0x4Du, v6, v7, v8, v9, v10, v11, v12, v13, v14);
      goto LABEL_26;
    }
LABEL_22:
    result = qdf_trace_msg(
               0x68u,
               8u,
               "%s: vdev object is NULL",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "cm_handle_sta_sta_roaming_enablement",
               v39,
               v40);
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
