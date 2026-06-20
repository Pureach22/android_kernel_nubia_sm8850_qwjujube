__int64 __fastcall sde_crtc_get_wb_usage_type(__int64 *a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x8
  unsigned int v5; // w19
  _QWORD v7[3]; // [xsp+8h] [xbp-18h] BYREF

  v7[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v7[0] = 0;
  v7[1] = 0;
  drm_connector_list_iter_begin(v2, v7);
  while ( 1 )
  {
    v3 = drm_connector_list_iter_next(v7);
    if ( !v3 )
      break;
    v4 = *(_QWORD *)(v3 + 2512);
    if ( v4 && *(__int64 **)(v4 + 8) == a1 && *(_DWORD *)(v3 + 156) == 15 )
    {
      v5 = *(_DWORD *)(v4 + 1856);
      goto LABEL_8;
    }
  }
  v5 = 0;
LABEL_8:
  drm_connector_list_iter_end(v7);
  _ReadStatusReg(SP_EL0);
  return v5;
}
