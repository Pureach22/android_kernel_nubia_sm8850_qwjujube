_DWORD *__fastcall sde_crtc_static_img_control(_DWORD *result, int a2, char a3)
{
  _DWORD *v3; // x19
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x8
  int v7; // w9
  void *v8; // x0
  int v9; // w7
  int v10; // w20
  __int64 v11; // x8
  __int64 *i; // x20

  if ( !result )
    return result;
  v3 = result;
  if ( !*(_QWORD *)result )
    return result;
  v4 = *(_QWORD *)(*(_QWORD *)result + 56LL);
  if ( !v4 )
  {
    v8 = &unk_25E167;
LABEL_22:
    printk(v8, "_sde_crtc_get_kms");
    return (_DWORD *)printk(&unk_223EAA, "sde_crtc_static_img_control");
  }
  v5 = *(_QWORD *)(v4 + 8);
  if ( !v5 )
  {
    v8 = &unk_234896;
    goto LABEL_22;
  }
  v6 = *(_QWORD *)(v5 + 152);
  if ( !v6 )
    return (_DWORD *)printk(&unk_223EAA, "sde_crtc_static_img_control");
  if ( (*(_QWORD *)(v6 + 21696) & 1) == 0 )
  {
    if ( (_drm_debug & 4) != 0 )
      return (_DWORD *)_drm_dev_dbg(0, 0, 0, "DISP syscache not supported\n");
    return result;
  }
  v7 = result[1964];
  if ( v7 == a2 )
    return result;
  if ( a2 > 3 )
  {
    if ( a2 == 4 )
    {
      if ( v7 != 2 )
        return result;
    }
    else if ( a2 != 5 || v7 != 4 )
    {
      return result;
    }
  }
  else if ( a2 )
  {
    if ( a2 != 2 || !v7 && (a3 & 1) == 0 )
      return result;
    kthread_cancel_delayed_work_sync(result + 1944);
    sde_core_perf_llcc_stale_frame(v3, 0);
    v6 = *(_QWORD *)(v5 + 152);
    a2 = 2;
  }
  if ( (*(_QWORD *)(v6 + 21696) & 2) == 0 || (*(_QWORD *)(v6 + 22008) & 0x40000000000LL) != 0 )
  {
    v10 = a2;
    v9 = 0;
    v3[1965] = 0;
  }
  else
  {
    v9 = v3[1965];
    v10 = a2;
    if ( a2 == 4 )
    {
      v9 = v9 == 0;
      v3[1965] = v9;
    }
  }
  result = (_DWORD *)sde_evtlog_log(
                       sde_dbg_base_evtlog,
                       "sde_crtc_static_img_control",
                       9132,
                       -1,
                       v3[28],
                       v10,
                       v3[1964],
                       v9,
                       239);
  v11 = *(_QWORD *)v3;
  v3[1964] = v10;
  for ( i = *(__int64 **)(v11 + 840); i != (__int64 *)(v11 + 840); i = (__int64 *)*i )
  {
    if ( ((*(_DWORD *)(*((_QWORD *)v3 + 251) + 12LL) >> *((_DWORD *)i + 437)) & 1) != 0 )
    {
      result = (_DWORD *)sde_plane_static_img_control(i - 1, (unsigned int)v3[1964], (unsigned int)v3[1965]);
      v11 = *(_QWORD *)v3;
    }
  }
  return result;
}
