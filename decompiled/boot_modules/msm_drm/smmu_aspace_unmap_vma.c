__int64 __fastcall smmu_aspace_unmap_vma(__int64 result, __int64 a2)
{
  __int64 v3; // x19
  void (*v4)(void); // x8
  __int64 v5; // x0
  void (*v6)(void); // x8
  int v12; // w8

  if ( *(_QWORD *)(a2 + 168) )
  {
    v3 = result;
    if ( result )
    {
      v4 = *(void (**)(void))(**(_QWORD **)(result + 256) + 56LL);
      if ( *((_DWORD *)v4 - 1) != -699315076 )
        __break(0x8228u);
      v4();
      result = v3 + 264;
      *(_QWORD *)(a2 + 168) = 0;
      __asm { PRFM            #0x11, [X0] }
      do
        v12 = __ldxr((unsigned int *)result);
      while ( __stlxr(v12 - 1, (unsigned int *)result) );
      if ( v12 == 1 )
      {
        __dmb(9u);
        drm_mm_takedown(v3 + 8);
        v5 = *(_QWORD *)(v3 + 256);
        if ( v5 )
        {
          v6 = *(void (**)(void))(*(_QWORD *)v5 + 64LL);
          if ( *((_DWORD *)v6 - 1) != -1262402125 )
            __break(0x8228u);
          v6();
        }
        return kfree(v3);
      }
      else if ( v12 <= 0 )
      {
        return refcount_warn_saturate(result, 3);
      }
    }
    else
    {
      *(_QWORD *)(a2 + 168) = 0;
    }
  }
  return result;
}
