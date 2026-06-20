__int64 __fastcall dp_mst_sim_reset(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x2
  __int64 v5; // x1

  if ( *(_QWORD *)(a2 + 16) )
  {
    if ( !**(_BYTE **)(a2 + 8) )
    {
      mutex_lock(a1 + 688);
      ++*(_DWORD *)(a1 + 776);
      complete(a1 + 736);
      mutex_unlock(a1 + 688);
      v4 = (_QWORD *)_kmalloc_cache_noprof(_drm_debug, 3520, 48);
      if ( v4 )
      {
        *v4 = 0xFFFFFFFE00000LL;
        v4[1] = v4 + 1;
        v4[2] = v4 + 1;
        v5 = *(_QWORD *)(a1 + 768);
        v4[3] = dp_mst_sim_reset_work;
        v4[4] = a1;
        queue_work_on(32, v5, v4);
      }
    }
  }
  return *(unsigned int *)(a2 + 16);
}
