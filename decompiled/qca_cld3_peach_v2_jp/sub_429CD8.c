__int64 __fastcall sub_429CD8(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x18

  return sme_acquire_global_lock(a1, a2, a3, v3 << 60 >> 16);
}
