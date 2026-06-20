__int64 __fastcall gen8_hwsched_clock_set(__int64 a1, __int64 a2)
{
  return gen8_hwsched_dcvs_set(a1, a2, 255, 0xFFFF);
}
