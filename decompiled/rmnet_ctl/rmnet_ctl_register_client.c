__int64 *__fastcall rmnet_ctl_register_client(__int64 *result)
{
  __int64 *v1; // x19
  __int64 v2; // x8
  unsigned __int64 v3; // x19
  unsigned __int64 dir; // x2

  if ( result )
  {
    v1 = result;
    result = (__int64 *)_kmalloc_cache_noprof(raw_spin_unlock, 3520, 8);
    if ( result )
    {
      v2 = *v1;
      v3 = (unsigned __int64)result;
      *result = v2;
      raw_spin_lock(&client_lock);
      if ( qword_6B08 )
      {
        raw_spin_unlock(&client_lock);
        kfree(v3);
        return nullptr;
      }
      else
      {
        atomic_store(v3, (unsigned __int64 *)&qword_6B08);
        raw_spin_unlock(&client_lock);
        dir = qword_6B10;
        if ( !qword_6B10 || (unsigned __int64)qword_6B10 >= 0xFFFFFFFFFFFFF001LL )
        {
          dir = debugfs_create_dir("rmnet_ctl", 0, qword_6B10);
          qword_6B10 = dir;
        }
        if ( dir && dir <= 0xFFFFFFFFFFFFF000LL )
          debugfs_create_u8("ipc_log_lvl", 420);
        if ( !qword_6B20 )
          qword_6B20 = ipc_log_context_create(10, "rmnet_ctl", 0);
        return (__int64 *)v3;
      }
    }
  }
  return result;
}
