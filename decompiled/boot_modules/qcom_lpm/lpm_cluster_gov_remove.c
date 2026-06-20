__int64 __fastcall lpm_cluster_gov_remove(__int64 result)
{
  _UNKNOWN **v1; // x20

  v1 = &cluster_dev_list;
  while ( 1 )
  {
    v1 = (_UNKNOWN **)*v1;
    if ( v1 == &cluster_dev_list )
      break;
    if ( *(v1 - 28) == (_UNKNOWN *)(*(_QWORD *)(result + 608) - 912LL) )
    {
      if ( v1 != (_UNKNOWN **)&print_fmt_cluster_pred_select[8] )
      {
        _pm_runtime_disable(result + 16, 1);
        *((_DWORD *)*(v1 - 28) + 358) &= ~0x40u;
        ((void (__fastcall *)(_UNKNOWN **))remove_cluster_sysfs_nodes)(v1 - 48);
        return dev_pm_genpd_remove_notifier(*(v1 - 48));
      }
      return result;
    }
  }
  return result;
}
