__int64 __fastcall sde_kms_cancel_delayed_work(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x8
  __int64 *i; // x21
  _QWORD v6[3]; // [xsp+8h] [xbp-18h] BYREF

  v6[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  v6[1] = 0;
  sde_crtc_cancel_delayed_work((__int64)a1);
  drm_connector_list_iter_begin(*a1, v6);
  while ( 1 )
  {
    v2 = drm_connector_list_iter_next(v6);
    if ( !v2 )
      break;
    if ( ((*(_DWORD *)(a1[251] + 16LL) >> *(_DWORD *)(v2 + 152)) & 1) != 0 )
      sde_connector_schedule_status_work(v2, 0);
  }
  result = drm_connector_list_iter_end(v6);
  v4 = *a1;
  for ( i = *(__int64 **)(*a1 + 816LL); i != (__int64 *)(v4 + 816); i = (__int64 *)*i )
  {
    if ( ((*(_DWORD *)(a1[251] + 20LL) >> *((_DWORD *)i + 15)) & 1) != 0 )
    {
      result = ((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(i - 1);
      if ( (result & 1) == 0 )
        result = sde_encoder_cancel_delayed_work((__int64)(i - 1));
    }
    v4 = *a1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
