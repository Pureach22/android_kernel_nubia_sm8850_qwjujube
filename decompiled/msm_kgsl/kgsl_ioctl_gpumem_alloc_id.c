unsigned __int64 __fastcall kgsl_ioctl_gpumem_alloc_id(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 result; // x0
  unsigned __int64 v5; // x8
  int v11; // w8

  result = gpumem_alloc_entry(
             a1,
             *(_QWORD *)(a3 + 8),
             *(unsigned int *)(a3 + 4) | (((*(_QWORD *)_ReadStatusReg(SP_EL0) >> 22) & 1LL) << 32));
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    *(_DWORD *)a3 = *(_DWORD *)(result + 248);
    *(_DWORD *)(a3 + 4) = *(_QWORD *)(result + 80);
    v5 = *(_QWORD *)(result + 48);
    *(_QWORD *)(a3 + 8) = v5;
    if ( (*(_DWORD *)(result + 56) & 1) != 0 )
      v5 = (v5 + 0x1FFF) & 0xFFFFFFFFFFFFF000LL;
    *(_QWORD *)(a3 + 16) = v5;
    *(_QWORD *)(a3 + 24) = *(_QWORD *)(result + 32);
    if ( result )
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v11 = __ldxr((unsigned int *)result);
      while ( __stlxr(v11 - 1, (unsigned int *)result) );
      if ( v11 == 1 )
      {
        __dmb(9u);
        kgsl_mem_entry_destroy((_QWORD *)result);
      }
      else if ( v11 <= 0 )
      {
        refcount_warn_saturate(result, 3);
      }
      return 0;
    }
  }
  return result;
}
