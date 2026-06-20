__int64 __fastcall kgsl_sharedmem_bind_ranges(__int64 a1)
{
  _QWORD *v3; // x19
  __int64 v4; // x1
  __int64 v6; // x1
  unsigned int v12; // w8

  _X0 = (unsigned int *)(a1 + 104);
  __asm { PRFM            #0x11, [X0] }
  do
    v12 = __ldxr(_X0);
  while ( __stxr(v12 + 1, _X0) );
  if ( !v12 )
  {
    v6 = 2;
    goto LABEL_8;
  }
  if ( (((v12 + 1) | v12) & 0x80000000) != 0 )
  {
    v6 = 1;
LABEL_8:
    refcount_warn_saturate(_X0, v6);
  }
  *(_QWORD *)(a1 + 40) = 0xFFFFFFFE00000LL;
  v3 = (_QWORD *)(a1 + 40);
  v3[1] = v3 + 1;
  v3[2] = v3 + 1;
  v4 = system_wq;
  v3[3] = kgsl_sharedmem_bind_worker;
  return queue_work_on(32, v4, v3);
}
