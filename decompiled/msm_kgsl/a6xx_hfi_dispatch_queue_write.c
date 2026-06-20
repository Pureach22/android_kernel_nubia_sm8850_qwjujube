__int64 __fastcall a6xx_hfi_dispatch_queue_write(
        __int64 a1,
        unsigned int a2,
        int *a3,
        unsigned int a4,
        __int64 a5,
        _QWORD *a6)
{
  _DWORD *v6; // x27
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 result; // x0
  __int64 v16; // x9
  __int64 v17; // x27
  int v18; // t1
  unsigned int v19; // w8
  __int64 v20; // x10
  __int64 v21; // x9
  unsigned int v22; // w10
  unsigned int v23; // w10
  __int64 v24; // x11
  int *v25; // x12
  int v26; // t1
  bool v27; // cf
  unsigned int v28; // w8
  unsigned int v29; // w10
  unsigned __int64 StatusReg; // x19
  __int64 v31; // x0
  __int64 v32; // x8

  v13 = to_a6xx_gmu(a1);
  if ( a2 >= 0x12 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v31 = _traceiter_kgsl_hfi_send(0);
      v32 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v32;
      if ( !v32 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v31);
    }
LABEL_20:
    __dsb(0xEu);
    v6[11] = a2;
    result = 0;
    __dsb(0xEu);
    return result;
  }
  v14 = v13;
  result = 4294967274LL;
  if ( (a4 & 3) == 0 )
  {
    v16 = *(_QWORD *)(*(_QWORD *)(v14 + 40) + 8LL);
    v17 = v16 + 48LL * a2;
    v18 = *(_DWORD *)(v17 + 24);
    v6 = (_DWORD *)(v17 + 24);
    if ( v18 )
    {
      v19 = ((a4 >> 2) + 3) & 0x7FFFFFFC;
      if ( v6[11] >= v6[10] )
      {
        if ( v6[3] - v6[11] + v6[10] <= v19 )
          return 4294967268LL;
      }
      else if ( v6[10] - v6[11] <= v19 )
      {
        return 4294967268LL;
      }
      v20 = (a2 << 12) | 0x350;
      a2 = v6[11];
      v21 = v16 + v20;
      if ( a4 >= 4 )
      {
        v23 = v6[3];
        v24 = a4 >> 2;
        v25 = a3;
        do
        {
          v26 = *v25++;
          *(_DWORD *)(v21 + 4LL * a2) = v26;
          --v24;
          a2 = (a2 + 1) % v23;
        }
        while ( v24 );
        v22 = a4 >> 2;
      }
      else
      {
        v22 = 0;
      }
      if ( *(_DWORD *)(a1 + 8280) >> 29 )
      {
        v27 = v22 >= v19;
        v28 = v22 - v19;
        if ( !v27 )
        {
          v29 = v6[3];
          do
          {
            *(_DWORD *)(v21 + 4LL * a2) = -84215046;
            v27 = __CFADD__(v28++, 1);
            a2 = (a2 + 1) % v29;
          }
          while ( !v27 );
        }
      }
      __dsb(0xEu);
      if ( a5 )
      {
        adreno_hwsched_add_profile_events(a1, a5, a6);
        adreno_profile_submit_time(a6);
      }
      goto LABEL_20;
    }
  }
  return result;
}
