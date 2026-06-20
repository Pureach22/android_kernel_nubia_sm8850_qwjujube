__int64 __fastcall gmu_core_alloc_kernel_block(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  __int64 result; // x0
  unsigned int v10; // w20

  result = kgsl_allocate_kernel(a1, a2, a3, 0, 512);
  if ( !(_DWORD)result )
  {
    result = gmu_core_map_gmu(a1, a2, 0, a4, a5, 0);
    if ( (_DWORD)result )
    {
      v10 = result;
      kgsl_sharedmem_free(a2);
      return v10;
    }
  }
  return result;
}
