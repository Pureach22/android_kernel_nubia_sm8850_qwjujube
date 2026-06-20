_QWORD *__fastcall kgsl_mmu_putpagetable(_QWORD *result)
{
  _QWORD *v2; // x19
  int v8; // w9

  if ( result && (unsigned __int64)result <= 0xFFFFFFFFFFFFF000LL )
  {
    _X8 = (unsigned int *)result + 1;
    __asm { PRFM            #0x11, [X8] }
    do
      v8 = __ldxr(_X8);
    while ( __stlxr(v8 - 1, _X8) );
    if ( v8 == 1 )
    {
      __dmb(9u);
      v2 = result;
      kgsl_mmu_detach_pagetable(result);
      return (_QWORD *)queue_work_on(32, qword_3A900, v2 + 5);
    }
    else if ( v8 <= 0 )
    {
      return (_QWORD *)refcount_warn_saturate((char *)result + 4, 3);
    }
  }
  return result;
}
