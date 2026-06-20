__int64 __fastcall kgsl_ioctl_timeline_wait(__int64 *a1, __int64 a2, __int64 a3)
{
  int v3; // w8
  __int64 result; // x0
  unsigned __int64 v6; // x19
  __int64 v7; // x9
  __int64 v8; // x2
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x0
  __int64 (__fastcall *v12)(unsigned __int64, __int64); // x8
  int v19; // w9

  v3 = *(_DWORD *)(a3 + 32);
  if ( (unsigned int)(v3 - 1) > 1 || *(_DWORD *)(a3 + 36) )
    return -22;
  v6 = kgsl_timelines_to_fence_array(
         *a1,
         *(_QWORD *)(a3 + 16),
         *(_DWORD *)(a3 + 24),
         *(unsigned int *)(a3 + 28),
         v3 == 2);
  if ( v6 >= 0xFFFFFFFFFFFFF001LL )
    return v6;
  v7 = a3;
  if ( *(__int64 *)a3 <= 0x225C17D03LL )
  {
    v9 = _msecs_to_jiffies((unsigned int)((*(_DWORD *)(a3 + 8) + 1000000000 * *(_DWORD *)a3) / 1000000));
    v7 = a3;
    v8 = v9;
  }
  else
  {
    v8 = 0x7FFFFFFFFFFFFFFFLL;
  }
  v10 = *(unsigned int *)(v7 + 32);
  if ( !v8 )
  {
    if ( (*(_QWORD *)(v6 + 48) & 1) == 0 )
    {
      v12 = *(__int64 (__fastcall **)(unsigned __int64, __int64))(*(_QWORD *)(v6 + 8) + 32LL);
      if ( !v12 )
        goto LABEL_20;
      if ( *((_DWORD *)v12 - 1) != 1879296680 )
        __break(0x8228u);
      if ( (v12(v6, v10) & 1) == 0 )
      {
LABEL_20:
        result = -16;
        goto LABEL_21;
      }
      dma_fence_signal(v6);
    }
    result = 0;
    goto LABEL_21;
  }
  v11 = dma_fence_wait_timeout(v6, 1, v8, *(_QWORD *)(v7 + 8));
  if ( v11 )
    result = v11 & (v11 >> 63);
  else
    result = -110;
LABEL_21:
  if ( !v6 )
    return result;
  _X8 = (unsigned int *)(v6 + 56);
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stlxr(v19 - 1, _X8) );
  if ( v19 == 1 )
  {
    __dmb(9u);
    v6 = result;
    dma_fence_release(_X8);
    return v6;
  }
  if ( v19 <= 0 )
  {
    v6 = result;
    refcount_warn_saturate(_X8, 3);
    return v6;
  }
  return result;
}
