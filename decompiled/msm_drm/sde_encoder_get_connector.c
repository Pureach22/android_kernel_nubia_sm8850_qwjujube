__int64 __fastcall sde_encoder_get_connector(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x19
  _QWORD v6[3]; // [xsp+8h] [xbp-18h] BYREF

  v6[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  v6[1] = 0;
  drm_connector_list_iter_begin(a1, v6);
  do
    v3 = drm_connector_list_iter_next(v6);
  while ( v3 && *(_QWORD *)(v3 + 2272) != a2 );
  v4 = v3;
  drm_connector_list_iter_end(v6);
  _ReadStatusReg(SP_EL0);
  return v4;
}
