__int64 __fastcall kgsl_alloc_map_gpu_global(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned __int64 a5,
        int a6,
        __int64 a7)
{
  _QWORD *v13; // x19
  int v14; // w4
  int secure; // w24
  __int64 (__fastcall *v16)(_QWORD); // x8
  int v17; // w0
  __int64 v18; // x8
  void (__fastcall *v19)(_QWORD); // x9
  void (__fastcall *v20)(_QWORD); // x8
  _QWORD *v21; // x0
  _QWORD *v22; // x1
  __int64 v23; // x2
  __int64 v24; // x8
  unsigned __int64 v32; // x3

  if ( !*(_QWORD *)(a1 + 11112) )
  {
    __break(0x800u);
    return -22;
  }
  v13 = (_QWORD *)_kmalloc_cache_noprof(mutex_unlock, 3520, 232);
  if ( !v13 )
    return -12;
  v14 = a6 | 0x202;
  if ( (a5 & 8) != 0 )
  {
    secure = kgsl_allocate_secure(a1, v13, a3, a5, v14);
    if ( !secure )
      goto LABEL_21;
LABEL_20:
    kfree(v13);
    return secure;
  }
  secure = kgsl_allocate_user(a1, v13, a3, a5, v14);
  if ( secure )
    goto LABEL_20;
  v16 = *(__int64 (__fastcall **)(_QWORD))(v13[8] + 24LL);
  if ( v16 )
  {
    if ( *((_DWORD *)v16 - 1) != -441828660 )
      __break(0x8228u);
    v17 = v16(v13);
    if ( v17 )
    {
      secure = v17;
      if ( v13[5] )
      {
        v18 = v13[8];
        if ( v18 )
        {
          v19 = *(void (__fastcall **)(_QWORD))(v18 + 40);
          if ( v19 )
          {
            if ( *((_DWORD *)v19 - 1) != 1555154090 )
              __break(0x8229u);
            v19(v13);
            v18 = v13[8];
          }
          v20 = *(void (__fastcall **)(_QWORD))(v18 + 16);
          if ( v20 )
          {
            if ( *((_DWORD *)v20 - 1) != 1555154090 )
              __break(0x8228u);
            v20(v13);
          }
        }
      }
      goto LABEL_20;
    }
  }
LABEL_21:
  if ( a2 )
    v13[3] = a2;
  v21 = v13 + 27;
  v22 = *(_QWORD **)(a1 + 13120);
  v23 = a1 + 13112;
  v13[26] = a7;
  if ( v13 + 27 == (_QWORD *)(a1 + 13112) || v22 == v21 || *v22 != v23 )
  {
    _list_add_valid_or_report(v21, v22);
  }
  else
  {
    *(_QWORD *)(a1 + 13120) = v21;
    v13[27] = v23;
    v13[28] = v22;
    *v22 = v21;
  }
  kgsl_mmu_map_global(a1);
  v24 = v13[5];
  _X9 = (unsigned __int64 *)(a1 + 11136);
  __asm { PRFM            #0x11, [X9] }
  do
    v32 = __ldxr(_X9);
  while ( __stlxr(v32 + v24, _X9) );
  __dmb(0xBu);
  return (__int64)v13;
}
