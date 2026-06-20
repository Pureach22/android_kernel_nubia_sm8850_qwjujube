__int64 __fastcall qmp_v3_dp_aux_init(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x8

  v2 = *(_QWORD *)(a1 + 8);
  writel(101, *(_QWORD *)(a1 + 120) + 24LL);
  writel(27, *(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 40LL));
  writel(2, *(_QWORD *)(a1 + 120) + 24LL);
  writel(125, *(_QWORD *)(a1 + 120) + 24LL);
  writel(63, *(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 40LL));
  writel(0, *(_QWORD *)(a1 + 120) + 32LL);
  writel(19, *(_QWORD *)(a1 + 120) + 36LL);
  writel(36, *(_QWORD *)(a1 + 120) + 40LL);
  writel(0, *(_QWORD *)(a1 + 120) + 44LL);
  writel(10, *(_QWORD *)(a1 + 120) + 48LL);
  writel(38, *(_QWORD *)(a1 + 120) + 52LL);
  writel(10, *(_QWORD *)(a1 + 120) + 56LL);
  writel(3, *(_QWORD *)(a1 + 120) + 60LL);
  writel(187, *(_QWORD *)(a1 + 120) + 64LL);
  writel(3, *(_QWORD *)(a1 + 120) + 68LL);
  v3 = *(_QWORD *)(a1 + 120);
  *(_DWORD *)(a1 + 296) = 0;
  return writel(31, v3 + 72);
}
