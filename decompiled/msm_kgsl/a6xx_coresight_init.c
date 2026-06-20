unsigned __int64 __fastcall a6xx_coresight_init(__int64 a1)
{
  adreno_coresight_add_device(a1, (__int64)"coresight-gfx", (__int64)&a6xx_coresight, a1 + 20664);
  return adreno_coresight_add_device(a1, (__int64)"coresight-gfx-cx", (__int64)&a6xx_coresight_cx, a1 + 20696);
}
