__int64 __fastcall node_get(unsigned int a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  __int64 v4; // x1
  __int64 v5; // x19

  v1 = a1;
  result = xa_load(&nodes, a1);
  if ( !result )
  {
    result = _kmalloc_cache_noprof(kthread_create_on_node, 2336, 24);
    if ( result )
    {
      *(_DWORD *)result = a1;
      *(_QWORD *)(result + 8) = 0;
      *(_QWORD *)(result + 16) = 0;
      v4 = v1;
      v5 = result;
      if ( xa_store(&nodes, v4, result, 2080) )
      {
        kfree(v5);
        return 0;
      }
      else
      {
        return v5;
      }
    }
  }
  return result;
}
