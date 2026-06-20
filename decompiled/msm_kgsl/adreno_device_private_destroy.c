__int64 __fastcall adreno_device_private_destroy(__int64 *a1)
{
  __int64 v1; // x20
  __int64 *v3; // x21
  __int64 *v4; // x26
  __int64 **v5; // x8
  __int64 *v6; // x9

  v1 = *a1;
  rt_mutex_lock(*a1 + 11088);
  v3 = (__int64 *)a1[2];
  if ( v3 != a1 + 2 )
  {
    do
    {
      v4 = (__int64 *)*v3;
      adreno_perfcounter_put(v1, *((unsigned int *)v3 - 2), *((unsigned int *)v3 - 1), 0);
      v5 = (__int64 **)v3[1];
      if ( *v5 == v3 && (v6 = (__int64 *)*v3, *(__int64 **)(*v3 + 8) == v3) )
      {
        v6[1] = (__int64)v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      kfree(v3 - 1);
      v3 = v4;
    }
    while ( v4 != a1 + 2 );
  }
  rt_mutex_unlock(v1 + 11088);
  return kfree(a1);
}
