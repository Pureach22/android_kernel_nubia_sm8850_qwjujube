__int64 __fastcall sde_kms_display_early_ept_hint(__int64 a1, int a2, __int64 a3, unsigned __int64 a4)
{
  __int64 v6; // x8
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x5
  int v14; // w6
  int v15; // w7
  __int64 v16; // x8
  __int64 result; // x0
  _QWORD v18[3]; // [xsp+8h] [xbp-18h] BYREF

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  _ReadStatusReg(SP_EL0);
  v18[2] = v6;
  v18[0] = 0;
  v18[1] = 0;
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_kms_display_early_ept_hint", 4758, -1, a2, a3, a4, SHIDWORD(a4), 239);
  drm_connector_list_iter_begin(a1, v18);
  while ( 1 )
  {
    v10 = drm_connector_list_iter_next(v18);
    if ( !v10 )
      break;
    if ( (a2 == -1 || *(_DWORD *)(v10 + 64) == a2) && *(_DWORD *)(v10 + 2736) == 16 )
    {
      v16 = *(_QWORD *)(v10 + 2512);
      if ( !v16 || (v9 = *(_QWORD *)(v16 + 16)) == 0 )
        v9 = *(_QWORD *)(v10 + 2272);
      sde_encoder_early_ept_hint(v9, a3, a4, v11, v12, v13, v14, v15);
    }
  }
  result = drm_connector_list_iter_end(v18);
  _ReadStatusReg(SP_EL0);
  return result;
}
