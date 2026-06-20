__int64 __fastcall sde_kms_display_early_wakeup(__int64 a1, int a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 result; // x0
  _QWORD v7[3]; // [xsp+8h] [xbp-18h] BYREF

  v7[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0;
  v7[1] = 0;
  drm_connector_list_iter_begin(a1, v7);
  while ( 1 )
  {
    v4 = drm_connector_list_iter_next(v7);
    if ( !v4 )
      break;
    if ( (a2 == -1 || *(_DWORD *)(v4 + 64) == a2)
      && ((v5 = *(_QWORD *)(v4 + 2512)) != 0 && (v3 = *(_QWORD *)(v5 + 16)) != 0 || (v3 = *(_QWORD *)(v4 + 2272)) != 0) )
    {
      sde_encoder_early_wakeup(v3);
    }
  }
  result = drm_connector_list_iter_end(v7);
  _ReadStatusReg(SP_EL0);
  return result;
}
