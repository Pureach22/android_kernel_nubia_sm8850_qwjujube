__int64 __fastcall sde_kms_pd_disable(__int64 a1)
{
  int v2; // w6
  int v3; // w7
  char v5; // [xsp+0h] [xbp+0h]

  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "\n");
  _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(a1 - 24) + 8LL), 4);
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_kms_pd_disable", 5475, -1, *(_DWORD *)(a1 + 1304), -1059143953, v2, v3, v5);
  return 0;
}
