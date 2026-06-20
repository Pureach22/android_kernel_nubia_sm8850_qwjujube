__int64 __fastcall tmc_enable_hw(__int64 a1)
{
  return writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a1 + 8) + 32LL));
}
