__int64 __fastcall policy_mgr_set_pcl_for_connected_vdev(__int64 a1, unsigned int a2, char a3)
{
  __int64 v6; // x0
  unsigned int *v7; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w22
  __int64 result; // x0
  unsigned int v18; // w21
  char v19; // w22
  char dual_sta_roaming_enabled; // w23
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  const char *v38; // x3
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  _BYTE v47[516]; // [xsp+0h] [xbp-410h] BYREF
  _BYTE s[516]; // [xsp+204h] [xbp-20Ch] BYREF
  __int64 v49; // [xsp+408h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v47, 0, sizeof(v47));
  v6 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( !v6 )
  {
    v37 = "%s: vdev is NULL";
    v38 = "policy_mgr_set_pcl_for_connected_vdev";
LABEL_8:
    result = qdf_trace_msg(0x4Fu, 2u, v37, v8, v9, v10, v11, v12, v13, v14, v15, v38);
    goto LABEL_9;
  }
  v16 = *(_DWORD *)(v6 + 16);
  result = wlan_objmgr_vdev_release_ref(v6, 0x18u, v7, v8, v9, v10, v11, v12, v13, v14, v15);
  if ( !v16 )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD))policy_mgr_get_roam_enabled_sta_session_id)(a1, a2);
    if ( (_BYTE)result != 0xFF )
    {
      v18 = result;
      v19 = policy_mgr_concurrent_sta_on_different_mac(a1);
      dual_sta_roaming_enabled = wlan_mlme_get_dual_sta_roaming_enabled(a1);
      result = qdf_trace_msg(
                 0x4Fu,
                 8u,
                 "%s: dual_sta_roam:%d, sta concurrency on different mac:%d, clear_pcl:%d",
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 "policy_mgr_set_pcl_for_connected_vdev",
                 dual_sta_roaming_enabled & 1,
                 v19 & 1,
                 a3 & 1);
      if ( (dual_sta_roaming_enabled & 1) != 0 )
      {
        if ( (a3 & 1) != 0 )
        {
          policy_mgr_set_pcl(a1, (__int64)v47, v18, 1, v29, v30, v31, v32, v33, v34, v35, v36);
        }
        else if ( (v19 & 1) == 0 )
        {
LABEL_12:
          memset(s, 0, sizeof(s));
          result = ((__int64 (__fastcall *)(__int64, _QWORD, _BYTE *, _BYTE *, _BYTE *, __int64, _QWORD))policy_mgr_get_pcl_for_vdev_id)(
                     a1,
                     0,
                     s,
                     &s[512],
                     &s[408],
                     102,
                     v18);
          if ( !(_DWORD)result )
          {
            result = policy_mgr_set_pcl(a1, (__int64)s, v18, 0, v39, v40, v41, v42, v43, v44, v45, v46);
            if ( (_DWORD)result )
            {
              v37 = "%s: Send set PCL to policy mgr failed";
              v38 = "policy_mgr_set_pcl_for_existing_combo";
              goto LABEL_8;
            }
          }
          goto LABEL_9;
        }
        wlan_cm_roam_activate_pcl_per_vdev(a1, v18, (a3 & 1) == 0);
        goto LABEL_12;
      }
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
