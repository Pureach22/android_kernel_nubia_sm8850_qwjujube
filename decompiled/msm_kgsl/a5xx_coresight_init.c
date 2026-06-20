unsigned __int64 __fastcall a5xx_coresight_init(__int64 a1)
{
  return adreno_coresight_add_device(a1, (__int64)"coresight-gfx", (__int64)&a5xx_coresight, a1 + 20664);
}
