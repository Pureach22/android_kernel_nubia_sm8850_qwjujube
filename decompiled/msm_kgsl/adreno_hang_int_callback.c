__int64 __fastcall adreno_hang_int_callback(__int64 a1)
{
  _QWORD *v2; // x20
  _DWORD *v3; // x8
  unsigned int v11; // w9

  if ( (unsigned int)__ratelimit(&adreno_hang_int_callback__rs, "adreno_hang_int_callback") )
    dev_crit(*(_QWORD *)a1, "MISC: GPU hang detected\n");
  if ( *(_DWORD *)(a1 + 20888) )
  {
    v2 = *(_QWORD **)(*(_QWORD *)(a1 + 14264) + 40LL);
    if ( *(_DWORD *)(*v2 + 64LL) <= 0xFFFFFFFD )
      kgsl_regmap_write(a1 + 13200, 0);
    v3 = (_DWORD *)v2[32];
    if ( v3 )
    {
      if ( *(v3 - 1) != 1163613936 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v3)(a1, 0);
    }
  }
  _X8 = (unsigned int *)(a1 + 24448);
  __asm { PRFM            #0x11, [X8] }
  do
    v11 = __ldxr(_X8);
  while ( __stxr(v11 | 2, _X8) );
  __dmb(0xAu);
  return kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
}
