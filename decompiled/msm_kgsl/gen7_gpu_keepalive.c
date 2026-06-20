__int64 __fastcall gen7_gpu_keepalive(__int64 a1, char a2)
{
  return gmu_core_regwrite(a1, 129219, a2 & 1);
}
