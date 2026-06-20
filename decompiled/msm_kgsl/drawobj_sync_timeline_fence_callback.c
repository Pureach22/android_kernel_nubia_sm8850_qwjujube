__int64 __fastcall drawobj_sync_timeline_fence_callback(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x20
  __int64 *v10; // x23
  int v11; // w22
  int v12; // w24
  __int64 v13; // x0
  _DWORD *v14; // x8
  const char *v15; // x0
  unsigned __int64 v16; // x9
  __int64 v17; // x21
  __int64 v18; // x8
  void (__fastcall *v19)(__int64, __int64); // x8
  __int64 v20; // x1
  unsigned __int64 v27; // x9
  __int64 v28; // [xsp+0h] [xbp-60h] BYREF
  char s[8]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v30; // [xsp+10h] [xbp-50h]
  __int64 v31; // [xsp+18h] [xbp-48h]
  __int64 v32; // [xsp+20h] [xbp-40h]
  __int64 v33; // [xsp+28h] [xbp-38h]
  __int64 v34; // [xsp+30h] [xbp-30h]
  __int64 v35; // [xsp+38h] [xbp-28h]
  __int64 v36; // [xsp+40h] [xbp-20h]
  __int64 v37; // [xsp+48h] [xbp-18h]
  __int16 v38; // [xsp+50h] [xbp-10h]
  __int64 v39; // [xsp+58h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a2 - 56);
  v28 = result;
  if ( result && *(_UNKNOWN **)(result + 8) == &dma_fence_array_ops )
  {
    v11 = *(_DWORD *)(result + 68);
    if ( !v11 )
      goto LABEL_9;
    v10 = *(__int64 **)(result + 80);
  }
  else
  {
    v10 = &v28;
    v11 = 1;
  }
  v12 = 0;
  _ReadStatusReg(SP_EL0);
  do
  {
    v38 = 0;
    v36 = 0;
    v37 = 0;
    v34 = 0;
    v35 = 0;
    v32 = 0;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    *(_QWORD *)s = 0;
    v13 = v10[v12];
    v14 = *(_DWORD **)(*(_QWORD *)(v13 + 8) + 16LL);
    if ( *(v14 - 1) != -352706110 )
      __break(0x8228u);
    v15 = (const char *)((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, _QWORD, __int64, __int64))v14)(
                          v13,
                          a2,
                          a3,
                          a4,
                          a5,
                          a6,
                          a7,
                          a8,
                          v28,
                          *(_QWORD *)s,
                          v30,
                          v31);
    snprintf(s, 0x4Au, "%s:%llu", v15, *(_QWORD *)(v10[v12] + 40));
    result = log_kgsl_syncpoint_fence_expire_event(*(unsigned int *)(*(_QWORD *)(v9 + 8) + 4LL), s);
    ++v12;
  }
  while ( v11 != v12 );
  v9 = *(_QWORD *)(a2 - 56);
LABEL_9:
  v16 = *(unsigned int *)(a2 - 64);
  v17 = *(_QWORD *)(a2 - 24);
  v18 = 1LL << v16;
  _X10 = (unsigned __int64 *)(v9 + 72 + 8 * (v16 >> 6));
  __asm { PRFM            #0x11, [X10] }
  do
    v27 = __ldxr(_X10);
  while ( __stlxr(v27 & ~v18, _X10) );
  __dmb(0xBu);
  if ( (v27 & v18) != 0 )
  {
    if ( !*(_DWORD *)(*(_QWORD *)(a2 - 56) + 72LL) )
    {
      timer_delete((timer_t)(v9 + 80));
      v19 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v17 + 8752) + 184LL);
      if ( v19 )
      {
        v20 = *(_QWORD *)(*(_QWORD *)(a2 - 56) + 8LL);
        if ( *((_DWORD *)v19 - 1) != 2043251089 )
          __break(0x8228u);
        v19(v17, v20);
      }
    }
    result = queue_work_on(32, qword_3A908, a2 + 24);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
