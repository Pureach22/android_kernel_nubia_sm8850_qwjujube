__int64 __fastcall sde_cp_notify_ltm_wb_pb(__int64 *a1)
{
  __int64 v1; // t1
  __int64 result; // x0
  __int64 v3; // [xsp+0h] [xbp-20h] BYREF
  int v4; // [xsp+8h] [xbp-18h]
  _QWORD v5[2]; // [xsp+10h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  v4 = 0;
  v3 = 0;
  if ( a1 )
  {
    v1 = *a1;
    v5[0] = 0xC80000009LL;
    result = msm_mode_object_event_notify(a1 + 14, v1, v5, &v3);
  }
  else
  {
    result = _drm_err("invalid drm_crtc %pK\n", nullptr);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
