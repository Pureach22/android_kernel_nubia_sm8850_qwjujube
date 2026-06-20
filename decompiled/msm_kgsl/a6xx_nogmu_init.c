unsigned __int64 __fastcall a6xx_nogmu_init(_QWORD *a1)
{
  unsigned __int64 result; // x0
  int v3; // w0

  result = ((__int64 (*)(void))a6xx_ringbuffer_init)();
  if ( !(_DWORD)result )
  {
    result = adreno_get_firmware(a1, *(const char **)(a1[1783] + 104LL), (__int64)(a1 + 1784));
    if ( !(_DWORD)result )
    {
      v3 = kgsl_regmap_add_region(a1 + 1650, a1[1396], "gmu_wrapper", 0, 0);
      if ( v3 != -19 )
      {
        if ( v3 )
          dev_err(*a1, "Couldn't map the GMU wrapper registers\n");
      }
      adreno_create_profile_buffer((unsigned __int64)a1);
      return a6xx_init((__int64)a1);
    }
  }
  return result;
}
