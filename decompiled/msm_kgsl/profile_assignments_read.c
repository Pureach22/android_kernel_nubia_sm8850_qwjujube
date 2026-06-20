__int64 __fastcall profile_assignments_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x25
  __int64 v8; // x0
  __int64 v9; // x22
  __int64 v10; // x23
  const char *v11; // x28
  int v12; // w26
  int v13; // w0
  __int64 v14; // x19

  v4 = *(_QWORD *)(a1 + 32);
  rt_mutex_lock(v4 + 11088);
  if ( *(_DWORD *)(v4 + 19696) )
  {
    v8 = _kmalloc_cache_noprof(socinfo_get_partinfo_vulkan_id, 3520, 4096);
    v9 = v8;
    if ( v8 )
    {
      v10 = v8;
      v11 = *(const char **)(v4 + 19680);
      if ( v11 != (const char *)(v4 + 19680) )
      {
        v12 = 4096;
        v10 = v8;
        do
        {
          v13 = scnprintf(v10, v12, "%.8s:%u ", v11 + 16, *((_DWORD *)v11 + 12));
          v11 = *(const char **)v11;
          v10 += v13;
          v12 -= v13;
        }
        while ( v11 != (const char *)(v4 + 19680) );
      }
      v14 = simple_read_from_buffer(a2, a3, a4, v9, v10 - v9);
      kfree(v9);
    }
    else
    {
      v14 = -12;
    }
  }
  else
  {
    v14 = 0;
  }
  rt_mutex_unlock(v4 + 11088);
  return v14;
}
