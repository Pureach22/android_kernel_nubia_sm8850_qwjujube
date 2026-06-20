__int64 __fastcall gen8_gpu_keepalive(__int64 a1, char a2)
{
  return gmu_core_regwrite(a1, 128996, a2 & 1);
}
