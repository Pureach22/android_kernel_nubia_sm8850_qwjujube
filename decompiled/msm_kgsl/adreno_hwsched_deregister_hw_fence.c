__int64 __fastcall adreno_hwsched_deregister_hw_fence(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x0
  unsigned __int64 v9; // x10

  if ( (*(_QWORD *)(result + 22496) & 0x10) != 0 )
  {
    v1 = (_QWORD *)result;
    kgsl_hw_fence_close();
    if ( v1[2910] )
      sg_free_table();
    v2 = v1[2865];
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
    result = kmem_cache_destroy(v2);
    _X8 = v1 + 2812;
    __asm { PRFM            #0x11, [X8] }
    do
      v9 = __ldxr(_X8);
    while ( __stxr(v9 & 0xFFFFFFFFFFFFFFEFLL, _X8) );
  }
  return result;
}
