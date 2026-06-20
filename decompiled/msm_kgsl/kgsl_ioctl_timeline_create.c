__int64 __fastcall kgsl_ioctl_timeline_create(__int64 *a1, __int64 a2, __int64 *a3)
{
  __int64 v3; // x24
  __int64 v4; // x21
  unsigned __int64 v7; // x20
  int v8; // w23
  __int64 v9; // x0
  unsigned __int64 StatusReg; // x27
  __int64 v11; // x8
  __int64 v12; // x0

  v3 = *a1;
  v4 = *a3;
  v7 = _kmalloc_cache_noprof(_check_object_size, 3520, 112);
  if ( !v7 )
    return -12;
  idr_preload(3264);
  raw_spin_lock(v3 + 13400);
  v8 = idr_alloc(v3 + 13376, 0, 1, 0, 10240);
  v9 = raw_spin_unlock(v3 + 13400);
  _ReadStatusReg(TPIDR_EL1);
  StatusReg = _ReadStatusReg(SP_EL0);
  v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v11;
  if ( v11 && *(_QWORD *)(StatusReg + 16) )
  {
    if ( (v8 & 0x80000000) == 0 )
      goto LABEL_5;
  }
  else
  {
    preempt_schedule(v9);
    if ( (v8 & 0x80000000) == 0 )
    {
LABEL_5:
      v12 = dma_fence_context_alloc(1);
      *(_DWORD *)(v7 + 8) = v8;
      *(_QWORD *)v7 = v12;
      *(_QWORD *)(v7 + 40) = v7 + 40;
      *(_QWORD *)(v7 + 48) = v7 + 40;
      *(_QWORD *)(v7 + 56) = v7 + 56;
      *(_QWORD *)(v7 + 64) = v7 + 56;
      *(_QWORD *)(v7 + 16) = v4;
      *(_QWORD *)(v7 + 104) = a1;
      snprintf((char *)(v7 + 72), 0x20u, "kgsl-sw-timeline-%d", v8);
      *(_QWORD *)(v7 + 24) = 0;
      *(_DWORD *)(v7 + 32) = 1;
      if ( v7 >= 0xFFFFFFFFFFFFF001LL )
        return v7;
      goto LABEL_9;
    }
  }
  kfree(v7);
  v7 = v8;
  if ( (unsigned __int64)v8 < 0xFFFFFFFFFFFFF001LL )
  {
LABEL_9:
    raw_spin_lock(v3 + 13400);
    idr_replace(v3 + 13376, v7, *(int *)(v7 + 8));
    *((_DWORD *)a3 + 2) = *(_DWORD *)(v7 + 8);
    raw_spin_unlock(v3 + 13400);
    return 0;
  }
  return v7;
}
