__int64 __fastcall bindobj_destroy(__int64 result)
{
  unsigned __int64 v1; // x8
  int v7; // w8

  v1 = *(_QWORD *)(result + 64);
  if ( v1 && v1 <= 0xFFFFFFFFFFFFF000LL )
  {
    result = v1 + 104;
    __asm { PRFM            #0x11, [X0] }
    do
      v7 = __ldxr((unsigned int *)result);
    while ( __stlxr(v7 - 1, (unsigned int *)result) );
    if ( v7 == 1 )
    {
      __dmb(9u);
      return kgsl_sharedmem_bind_range_destroy();
    }
    else if ( v7 <= 0 )
    {
      return refcount_warn_saturate(result, 3);
    }
  }
  return result;
}
