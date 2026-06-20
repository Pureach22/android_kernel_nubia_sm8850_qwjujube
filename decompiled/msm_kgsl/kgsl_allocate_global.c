__int64 __fastcall kgsl_allocate_global(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned __int64 a4,
        int a5,
        __int64 a6)
{
  return kgsl_alloc_map_gpu_global(a1, 0, a2, a3, a4, a5, a6);
}
