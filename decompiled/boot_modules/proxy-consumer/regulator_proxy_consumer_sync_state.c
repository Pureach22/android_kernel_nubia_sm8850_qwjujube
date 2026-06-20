__int64 __fastcall regulator_proxy_consumer_sync_state(unsigned __int64 a1)
{
  __int64 *v2; // x0
  __int64 *v4; // x21

  if ( !a1 || a1 >= 0xFFFFFFFFFFFFF001LL )
    return printk(&unk_6B1B, "regulator_proxy_consumer_unregister");
  mutex_lock(&proxy_consumer_list_lock);
  v2 = (__int64 *)proxy_consumer_list;
  if ( proxy_consumer_list != (_UNKNOWN *)&proxy_consumer_list )
  {
    do
    {
      v4 = (__int64 *)*v2;
      if ( v2[3] == a1 )
        regulator_proxy_consumer_remove(v2);
      v2 = v4;
    }
    while ( v4 != (__int64 *)&proxy_consumer_list );
  }
  return mutex_unlock(&proxy_consumer_list_lock);
}
