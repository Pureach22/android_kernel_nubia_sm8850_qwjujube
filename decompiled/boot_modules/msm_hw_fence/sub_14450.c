__int64 __fastcall sub_14450(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x18
  __int64 v5; // x20

  return create_signaled_hw_fence(v4 & ~(v5 >> 11), a2, a3, a4);
}
