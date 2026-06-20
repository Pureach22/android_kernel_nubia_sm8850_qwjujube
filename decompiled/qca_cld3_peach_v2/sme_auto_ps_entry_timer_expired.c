__int64 __fastcall sme_auto_ps_entry_timer_expired(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *v9; // x19
  const char *v11; // x2
  unsigned int v13; // w20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  const char *v23; // x3

  if ( !a1 )
  {
    v11 = "%s: ps_params is NULL";
    return qdf_trace_msg(0x34u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "sme_auto_ps_entry_timer_expired");
  }
  v9 = *(_QWORD **)a1;
  if ( !*(_QWORD *)a1 )
  {
    v11 = "%s: mac_ctx is NULL";
    return qdf_trace_msg(0x34u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "sme_auto_ps_entry_timer_expired");
  }
  if ( !(unsigned int)sme_acquire_global_lock((__int64)(v9 + 1605)) )
  {
    v13 = *(_DWORD *)(a1 + 8);
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: auto_ps_timer expired, enabling powersave",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "sme_auto_ps_entry_timer_expired");
    if ( v13 <= 5 )
    {
      if ( (*(_BYTE *)(v9[1] + 5633LL) & 1) != 0 )
      {
        if ( (mlme_get_user_ps(v9[2703], v13) & 1) != 0 )
        {
          if ( cm_is_vdevid_active(v9[2704], v13) )
            sme_ps_enable_disable(v9, v13, 0);
          return sme_release_global_lock((__int64)(v9 + 1605));
        }
        v22 = "%s: vdev:%d Cannot initiate PS. PS is disabled by usr(ioctl)";
        v23 = "sme_ps_enable_user_check";
      }
      else
      {
        v22 = "%s: vdev:%d power save mode is disabled via ini";
        v23 = "sme_enable_sta_ps_check";
      }
      qdf_trace_msg(0x34u, 8u, v22, v14, v15, v16, v17, v18, v19, v20, v21, v23, v13);
    }
    return sme_release_global_lock((__int64)(v9 + 1605));
  }
  v11 = "%s: can't acquire sme global lock";
  return qdf_trace_msg(0x34u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "sme_auto_ps_entry_timer_expired");
}
