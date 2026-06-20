__int64 __fastcall sde_crtc_mdnie_art_event_notify(__int64 *a1)
{
  __int64 v1; // t1
  __int64 result; // x0
  __int64 v3; // [xsp+8h] [xbp-18h] BYREF
  int v4; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+18h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *a1;
  v3 = 0x480000012LL;
  v4 = 1;
  result = msm_mode_object_event_notify(a1 + 14, v1, &v3, &v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
