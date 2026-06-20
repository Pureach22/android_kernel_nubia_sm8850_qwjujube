__int64 __fastcall devm_regulator_proxy_consumer_release(__int64 a1, __int64 **a2)
{
  __int64 *v3; // x0
  __int64 *v4; // x9

  mutex_lock(&proxy_consumer_list_lock);
  v3 = *a2;
  v4 = (__int64 *)&proxy_consumer_list;
  while ( 1 )
  {
    v4 = (__int64 *)*v4;
    if ( v4 == (__int64 *)&proxy_consumer_list )
      break;
    if ( v4 == v3 )
    {
      regulator_proxy_consumer_remove(v3);
      return mutex_unlock(&proxy_consumer_list_lock);
    }
  }
  return mutex_unlock(&proxy_consumer_list_lock);
}
