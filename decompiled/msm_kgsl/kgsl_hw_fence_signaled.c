__int64 __fastcall kgsl_hw_fence_signaled(__int64 a1)
{
  return (*(_QWORD *)(a1 + 48) >> 30) & 1LL;
}
