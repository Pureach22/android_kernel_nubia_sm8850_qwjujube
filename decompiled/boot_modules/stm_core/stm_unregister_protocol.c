__int64 __fastcall stm_unregister_protocol(__int64 a1)
{
  __int64 *v2; // x8
  __int64 v3; // x10
  __int64 *v4; // x19
  __int64 **v5; // x9
  __int64 v6; // x8

  mutex_lock(&stm_pdrv_mutex);
  v2 = (__int64 *)stm_pdrv_head;
  while ( v2 != &stm_pdrv_head )
  {
    v3 = v2[2];
    v4 = v2;
    v2 = (__int64 *)*v2;
    if ( v3 == a1 )
    {
      v5 = (__int64 **)v4[1];
      if ( *v5 == v4 && (__int64 *)v2[1] == v4 )
      {
        v2[1] = (__int64)v5;
        *v5 = v2;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
      }
      v6 = v4[3];
      *v4 = 0xDEAD000000000100LL;
      v4[1] = 0xDEAD000000000122LL;
      if ( v6 )
      {
        kfree(*(_QWORD *)(v6 + 24));
        kfree(v4[3]);
      }
      kfree(v4);
      return mutex_unlock(&stm_pdrv_mutex);
    }
  }
  return mutex_unlock(&stm_pdrv_mutex);
}
