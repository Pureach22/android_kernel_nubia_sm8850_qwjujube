__int64 __fastcall tdls_update_pmo_status(
        __int64 a1,
        unsigned int a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x19
  const char *v26; // x2
  const char *v27; // x3
  unsigned int v28; // w1
  const char *v29; // x2
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x19
  const char *v33; // x2
  _QWORD v34[2]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v35; // [xsp+10h] [xbp-10h]
  __int64 v36; // [xsp+18h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)a1 )
  {
    v29 = "%s: NULL vdev";
    goto LABEL_13;
  }
  v11 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 80)) == 0 )
  {
    v29 = "%s: can't get psoc";
LABEL_13:
    qdf_trace_msg(0, 2u, v29, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_vdev_get_tdls_soc_obj");
    goto LABEL_14;
  }
  result = wlan_objmgr_psoc_get_comp_private_obj(v12, 0xAu);
  if ( !result )
  {
LABEL_14:
    v26 = "%s: NULL psoc object";
    v27 = "tdls_update_pmo_status";
    v28 = 2;
    goto LABEL_15;
  }
  if ( (*(_BYTE *)(result + 369) & 1) != 0 )
    goto LABEL_16;
  if ( a2 > 2 || a3 != 3 )
  {
    if ( !a2 || a3 || *(_WORD *)(result + 202) )
      goto LABEL_16;
    v34[0] = 0;
    if ( a1 )
    {
      v30 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
      if ( v30 )
      {
        v31 = *(_QWORD *)(v30 + 80);
        if ( v31 )
        {
          v32 = result;
          v34[1] = 0;
          v35 = 0;
          result = wlan_objmgr_iterate_obj_list(v31, 2, tdls_find_progress_peer_handler, (__int64)v34, 0, 0x11u);
          if ( v35 )
            goto LABEL_16;
          goto LABEL_28;
        }
      }
      v32 = result;
      v33 = "%s: invalid psoc";
    }
    else
    {
      v32 = result;
      v33 = "%s: invalid tdls vdev object";
    }
    result = qdf_trace_msg(0, 2u, v33, v17, v18, v19, v20, v21, v22, v23, v24, "tdls_is_progress", v34[0]);
LABEL_28:
    if ( *(_BYTE *)(v32 + 368) != 1 )
      goto LABEL_16;
    qdf_wake_lock_release(v32 + 376, 0x19u);
    qdf_runtime_pm_allow_suspend((__int64 *)(v32 + 576));
    v26 = "%s: Release WIFI_POWER_EVENT_WAKELOCK_TDLS";
    v27 = "tdls_allow_suspend";
    *(_BYTE *)(v32 + 368) = 0;
    goto LABEL_10;
  }
  if ( (*(_BYTE *)(result + 368) & 1) == 0 )
  {
    v25 = result;
    qdf_wake_lock_acquire(result + 376, 0x19u);
    qdf_runtime_pm_prevent_suspend((__int64 *)(v25 + 576));
    v26 = "%s: Acquire WIFI_POWER_EVENT_WAKELOCK_TDLS";
    *(_BYTE *)(v25 + 368) = 1;
    v27 = "tdls_prevent_suspend";
LABEL_10:
    v28 = 8;
LABEL_15:
    result = qdf_trace_msg(0, v28, v26, v17, v18, v19, v20, v21, v22, v23, v24, v27, v34[0]);
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
