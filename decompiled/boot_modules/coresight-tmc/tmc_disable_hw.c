__int64 __fastcall tmc_disable_hw(__int64 a1)
{
  return writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a1 + 8) + 32LL));
}
