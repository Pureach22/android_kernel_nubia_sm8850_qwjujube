unsigned __int64 __fastcall kgsl_ioctl_gpumem_alloc(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 result; // x0
  int v10; // w8

  result = gpumem_alloc_entry(
             a1,
             *(_QWORD *)(a3 + 8),
             (*(_QWORD *)_ReadStatusReg(SP_EL0) << 10) & 0x100000000LL | *(_DWORD *)(a3 + 16) & 0xEFFFFFFF);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)a3 = *(_QWORD *)(result + 32);
    *(_QWORD *)(a3 + 8) = *(_QWORD *)(result + 48);
    *(_DWORD *)(a3 + 16) = *(_QWORD *)(result + 80);
    if ( result )
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v10 = __ldxr((unsigned int *)result);
      while ( __stlxr(v10 - 1, (unsigned int *)result) );
      if ( v10 == 1 )
      {
        __dmb(9u);
        kgsl_mem_entry_destroy((_QWORD *)result);
      }
      else if ( v10 <= 0 )
      {
        refcount_warn_saturate(result, 3);
      }
      return 0;
    }
  }
  return result;
}
