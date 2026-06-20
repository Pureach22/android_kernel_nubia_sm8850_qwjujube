unsigned __int64 __fastcall devm_regulator_proxy_consumer_unregister(unsigned __int64 result)
{
  unsigned __int64 v1; // x19
  _QWORD *v2; // x3
  _UNKNOWN **v3; // x23

  if ( result )
  {
    v1 = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      mutex_lock(&proxy_consumer_list_lock);
      v2 = proxy_consumer_list;
      if ( proxy_consumer_list != (_UNKNOWN *)&proxy_consumer_list )
      {
        do
        {
          v3 = (_UNKNOWN **)*v2;
          if ( v2[3] == v1 )
            devres_release(v1, devm_regulator_proxy_consumer_release, devm_regulator_proxy_consumer_match);
          v2 = v3;
        }
        while ( v3 != &proxy_consumer_list );
      }
      return mutex_unlock(&proxy_consumer_list_lock);
    }
  }
  return result;
}
