__int64 __fastcall ucfg_mlme_stats_is_link_speed_report_max(__int64 a1)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    return *(_DWORD *)(result + 3408) == 1;
  return result;
}
