__int64 __fastcall sde_kms_handle_recovery(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v9; // w4
  char v11; // [xsp+0h] [xbp+0h]

  if ( a1 )
    v9 = *(_DWORD *)(a1 + 24);
  else
    v9 = -1;
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_kms_handle_recovery", 6308, -1, v9, 3, -1059143953, a8, v11);
  return sde_encoder_wait_for_event(a1, 3u);
}
