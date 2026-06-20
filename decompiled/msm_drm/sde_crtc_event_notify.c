__int64 __fastcall sde_crtc_event_notify(__int64 *a1, int a2, int *a3, int a4)
{
  __int64 v7; // t1
  __int64 result; // x0
  _DWORD v10[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 v11; // [xsp+28h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v7 = *a1;
    v10[0] = a2;
    v10[1] = a4;
    msm_mode_object_event_notify(a1 + 14, v7, v10, a3);
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "sde_crtc_event_notify",
               900,
               -1,
               *((_DWORD *)a1 + 28),
               a2,
               a4,
               *a3,
               SBYTE4(a3));
    if ( (_drm_debug & 4) != 0 )
      result = _drm_dev_dbg(
                 0,
                 0,
                 0,
                 "crtc:%d event(%u) ptr(%pK) value(%u) notified\n",
                 *((_DWORD *)a1 + 28),
                 a2,
                 a3,
                 *a3);
  }
  else
  {
    result = printk(&unk_25E167, "sde_crtc_event_notify");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
