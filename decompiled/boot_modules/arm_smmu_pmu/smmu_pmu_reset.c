__int64 __fastcall smmu_pmu_reset(__int64 a1)
{
  unsigned __int64 v2; // x21

  if ( *(_DWORD *)(a1 + 2464) )
  {
    v2 = 0;
    do
    {
      writel_relaxed((unsigned int)(1LL << v2), *(_QWORD *)(a1 + 2480) + 3104LL);
      writel_relaxed((unsigned int)(1LL << v2++), *(_QWORD *)(a1 + 2480) + 3168LL);
    }
    while ( v2 < *(unsigned int *)(a1 + 2464) );
  }
  return writel_relaxed(0, *(_QWORD *)(a1 + 2480) + 3588LL);
}
