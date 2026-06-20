__int64 __fastcall target_if_vdev_mgr_up_send(
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
  __int64 v10; // x8
  __int64 *v11; // x9
  __int64 v12; // x20
  __int64 v13; // x19
  unsigned int v15; // w20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  const char *v25; // x2
  const char *v26; // x2
  __int64 v27; // [xsp+0h] [xbp-10h] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v27) = 0;
  LODWORD(v27) = 0;
  if ( !a1 || !a2 )
  {
    v25 = "%s: Invalid input";
LABEL_12:
    qdf_trace_msg(0x68u, 2u, v25, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_up_send", v27);
    result = 4;
    goto LABEL_13;
  }
  v10 = *(_QWORD *)(a1 + 152);
  if ( !v10 )
  {
    v26 = "%s: PDEV is NULL";
    goto LABEL_11;
  }
  v11 = *(__int64 **)(v10 + 1232);
  if ( !v11 || (v12 = *v11) == 0 )
  {
    v26 = "%s: wmi_handle is null";
LABEL_11:
    qdf_trace_msg(0x68u, 2u, v26, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_wmi_handle_get", v27, v28);
    v25 = "%s: Failed to get WMI handle!";
    goto LABEL_12;
  }
  v13 = *(_QWORD *)(v10 + 80);
  if ( !v13 )
  {
    v25 = "%s: Failed to get PSOC Object";
    goto LABEL_12;
  }
  ucfg_wlan_vdev_mgr_get_param_bssid(a1, &v27);
  v15 = wmi_unified_vdev_up_send(v12, &v27, a2);
  target_if_wake_lock_timeout_release(v13, 0);
  target_if_release_vdev_cmd_rt_lock(v13, *a2, v16, v17, v18, v19, v20, v21, v22, v23);
  result = v15;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
