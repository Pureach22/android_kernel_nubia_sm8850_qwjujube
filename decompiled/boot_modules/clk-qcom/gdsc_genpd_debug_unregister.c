__int64 __fastcall gdsc_genpd_debug_unregister(__int64 a1)
{
  _QWORD *v2; // x20
  _UNKNOWN **v3; // x23
  __int64 v4; // x0
  _QWORD *v5; // x8
  _UNKNOWN **v6; // x9

  mutex_lock(&gdsc_genpd_debug_lock);
  v2 = gdsc_genpd_debug_list;
  if ( gdsc_genpd_debug_list != (_UNKNOWN *)&gdsc_genpd_debug_list )
  {
    do
    {
      v3 = (_UNKNOWN **)*v2;
      if ( v2[2] == a1 )
      {
        v4 = v2[3];
        if ( v4 )
        {
          _pm_runtime_disable(v4, 1);
          pm_genpd_remove_device(v2[3]);
          device_unregister(v2[3]);
          v2[3] = 0;
        }
        v5 = (_QWORD *)v2[1];
        v2[2] = 0;
        if ( (_QWORD *)*v5 == v2 && (v6 = (_UNKNOWN **)*v2, *(_QWORD **)(*v2 + 8LL) == v2) )
        {
          v6[1] = v5;
          *v5 = v6;
        }
        else
        {
          _list_del_entry_valid_or_report(v2);
        }
        *v2 = 0xDEAD000000000100LL;
        v2[1] = 0xDEAD000000000122LL;
        kfree(v2);
      }
      v2 = v3;
    }
    while ( v3 != &gdsc_genpd_debug_list );
  }
  return mutex_unlock(&gdsc_genpd_debug_lock);
}
