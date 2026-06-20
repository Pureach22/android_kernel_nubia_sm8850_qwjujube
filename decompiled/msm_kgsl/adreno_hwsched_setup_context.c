__int64 __fastcall adreno_hwsched_setup_context(__int64 a1, __int64 a2)
{
  int v2; // w8
  unsigned int v3; // w20
  __int64 v4; // x21
  unsigned int v5; // w23
  __int64 v6; // x24
  __int64 v8; // x19
  __int64 v11; // x0
  int v12; // w8
  __int64 v13; // x12
  int v14; // w11
  __int64 v15; // x10
  __int64 v16; // x12
  __int64 v17; // x11
  __int64 v18; // x10
  __int64 v19; // x11
  __int64 v20; // x2
  __int64 v21; // x1
  const char *v22; // x6
  __int64 v23; // x0

  if ( a2 )
  {
    v2 = *(_DWORD *)(a2 + 200);
    if ( (v2 & 0x20000000) != 0 )
    {
LABEL_15:
      LODWORD(v4) = 0;
      return (unsigned int)v4;
    }
  }
  else
  {
    v2 = 475220;
  }
  if ( *(_DWORD *)(a2 + 8) >> 2 >= 3u )
    v3 = 3;
  else
    v3 = *(_DWORD *)(a2 + 8) >> 2;
  if ( (v2 & 0x20000000) != 0 )
    goto LABEL_15;
  LODWORD(v4) = 0;
  if ( (~*(_DWORD *)(*(_QWORD *)(a1 + 14264) + 32LL) & 0x1000004) != 0 || !v3 )
    return (unsigned int)v4;
  v5 = v3 - 1;
  v6 = (v2 & 0x20000) != 0 ? a1 + 23536 : a1 + 23480;
  if ( *(_QWORD *)(v6 + 8LL * v5) )
    goto LABEL_15;
  v8 = *(_QWORD *)(a2 + 40);
  v11 = rt_mutex_lock(v8 + 11088);
  if ( *(_QWORD *)(v6 + 8LL * v5) )
  {
    LODWORD(v4) = 0;
  }
  else
  {
    v12 = *(_DWORD *)(a2 + 200);
    v13 = *(unsigned int *)(a1 + 22440);
    if ( (v12 & 0x20000) != 0 )
      v14 = 5;
    else
      v14 = 4;
    if ( (_DWORD)v13 )
    {
      v15 = 0;
      v16 = 48 * v13;
      while ( 1 )
      {
        if ( v15 == 1584 )
        {
          __break(0x5512u);
          return adreno_hwsched_create_hw_fence(v11);
        }
        if ( *(_DWORD *)(a1 + 20916 + v15) == v14 )
          break;
        v15 += 48;
        if ( v16 == v15 )
          goto LABEL_33;
      }
      if ( !(a1 + 20904 + v15) )
        goto LABEL_33;
      v17 = 23504;
      if ( (v12 & 0x20000) == 0 )
        v17 = 23448;
      v18 = a1 + v15;
      v19 = *(_QWORD *)(a1 + v17 + 8LL * v3);
      v20 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 64LL);
      v21 = *(_QWORD *)(v19 + 40) + *(_QWORD *)(v19 + 24);
      if ( (unsigned __int64)(v20 + v21) <= *(_QWORD *)(*(_QWORD *)(v18 + 20944) + 40LL)
                                          + *(_QWORD *)(*(_QWORD *)(v18 + 20944) + 24LL) )
      {
        if ( (v12 & 0x20000) != 0 )
          v22 = "sec_preempt_record_gmem";
        else
          v22 = "preempt_record_gmem";
        v23 = kgsl_alloc_map_gpu_global(
                v8,
                v21,
                v20,
                0,
                (((unsigned __int64)*(unsigned int *)(v18 + 20912) >> 9) & 8
               | ((((unsigned __int64)*(unsigned int *)(v18 + 20912) >> 2) & 1) << 24))
              ^ 0x1000000,
                (32 * *(_DWORD *)(v18 + 20912)) & 0x40,
                v22);
        LODWORD(v4) = 0;
        *(_QWORD *)(v6 + 8LL * v5) = v23;
        if ( !v23 )
        {
          if ( (unsigned int)__ratelimit(
                               &adreno_hwsched_alloc_preempt_record_gmem__rs_97,
                               "adreno_hwsched_alloc_preempt_record_gmem") )
            dev_err(*(_QWORD *)(v8 + 1544) + 16LL, "Failed to allocate gmem preempt record for rb:%d\n", v3);
          v4 = *(_QWORD *)(v6 + 8LL * v5);
          kfree(v4);
        }
      }
      else
      {
        LODWORD(v4) = -28;
      }
    }
    else
    {
LABEL_33:
      if ( (unsigned int)__ratelimit(
                           &adreno_hwsched_alloc_preempt_record_gmem__rs,
                           "adreno_hwsched_alloc_preempt_record_gmem") )
        dev_err(*(_QWORD *)(v8 + 1544) + 16LL, "preempt record entry not found\n");
      LODWORD(v4) = -22;
    }
  }
  rt_mutex_unlock(v8 + 11088);
  return (unsigned int)v4;
}
