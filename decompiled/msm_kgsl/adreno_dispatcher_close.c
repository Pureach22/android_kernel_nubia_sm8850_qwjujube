__int64 __fastcall adreno_dispatcher_close(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x3
  int v6; // w22
  __int64 v7; // x23
  unsigned int v8; // w8
  unsigned __int64 v15; // x10

  mutex_lock(a1 + 19760);
  result = timer_delete_sync(a1 + 19816);
  if ( *(int *)(a1 + 19632) < 1 )
  {
LABEL_9:
    mutex_unlock(a1 + 19760);
    kthread_destroy_worker(*(_QWORD *)(a1 + 24400));
    *(_QWORD *)(a1 + 20896) = 0;
    kobject_put(a1 + 20160);
    result = kmem_cache_destroy(jobs_cache);
  }
  else
  {
    v6 = 0;
    v7 = a1 + 14352;
    while ( 1 )
    {
      v8 = *(_DWORD *)(v7 + 1236);
      if ( v7 == -208 )
        break;
LABEL_5:
      if ( v8 != *(_DWORD *)(v7 + 1240) )
        break;
      ++v6;
      v7 += 1320;
      if ( v6 >= *(_DWORD *)(a1 + 19632) )
        goto LABEL_9;
    }
    while ( v8 <= 0x7F )
    {
      result = kgsl_drawobj_destroy(*(_QWORD *)(v7 + 208 + 8LL * v8), v3, v4, v5);
      v8 = ((unsigned __int8)*(_DWORD *)(v7 + 1236) + 1) & 0x7F;
      *(_DWORD *)(v7 + 1236) = v8;
      if ( v7 != -208 )
        goto LABEL_5;
    }
    __break(0x5512u);
  }
  _X8 = (unsigned __int64 *)(a1 + 19808);
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr(_X8);
  while ( __stxr(v15 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
  return result;
}
