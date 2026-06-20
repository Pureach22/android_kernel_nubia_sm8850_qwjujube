__int64 __fastcall adreno_hwsched_register_hw_fence(__int64 result)
{
  _QWORD *v1; // x19
  int v2; // w0
  unsigned __int64 v9; // x9
  _QWORD v10[5]; // [xsp+8h] [xbp-28h] BYREF

  v10[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(*(_QWORD *)(result + 14264) + 34LL) & 1) != 0 )
  {
    v1 = (_QWORD *)result;
    if ( (*(_QWORD *)(result + 22496) & 0x10) == 0 )
    {
      result = kgsl_hw_fence_init(result);
      if ( !(_DWORD)result )
      {
        kgsl_memdesc_init(v1, v1 + 2903, 0);
        kgsl_hw_fence_populate_md(v1, v1 + 2903);
        v2 = kgsl_memdesc_sg_dma(v1 + 2903, v1[2907], v1[2908]);
        if ( v2 )
        {
          dev_err(*v1, "Failed to setup HW fences memdesc: %d\n", v2);
          result = kgsl_hw_fence_close(v1);
          v1[2927] = 0;
          v1[2928] = 0;
          v1[2925] = 0;
          v1[2926] = 0;
          v1[2923] = 0;
          v1[2924] = 0;
          v1[2921] = 0;
          v1[2922] = 0;
          v1[2919] = 0;
          v1[2920] = 0;
          v1[2917] = 0;
          v1[2918] = 0;
          v1[2915] = 0;
          v1[2916] = 0;
          v1[2913] = 0;
          v1[2914] = 0;
          v1[2911] = 0;
          v1[2912] = 0;
          v1[2909] = 0;
          v1[2910] = 0;
          v1[2907] = 0;
          v1[2908] = 0;
          v1[2905] = 0;
          v1[2906] = 0;
          v1[2903] = 0;
          v1[2904] = 0;
        }
        else
        {
          memset(&v10[1], 0, 24);
          v10[0] = 8;
          result = _kmem_cache_create_args("adreno_hw_fence_entry", 96, v10, 0);
          v1[2865] = result;
          _X8 = v1 + 2812;
          __asm { PRFM            #0x11, [X8] }
          do
            v9 = __ldxr(_X8);
          while ( __stxr(v9 | 0x10, _X8) );
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
