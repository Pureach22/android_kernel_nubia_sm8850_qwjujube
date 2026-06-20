bool __fastcall ucfg_mlme_stats_is_link_speed_report_actual(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  return !psoc_ext_obj_fl || *(_DWORD *)(psoc_ext_obj_fl + 3620) == 0;
}
