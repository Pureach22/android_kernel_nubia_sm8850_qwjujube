__int64 __fastcall qmp_v4_dp_aux_init(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x8

  v2 = *(_QWORD *)(a1 + 8);
  writel(0x67u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 24LL));
  writel(0x17u, (unsigned int *)(*(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 40LL)));
  writel(0, (unsigned int *)(*(_QWORD *)(a1 + 120) + 32LL));
  writel(0x13u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 36LL));
  writel(0xA4u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 40LL));
  writel(0, (unsigned int *)(*(_QWORD *)(a1 + 120) + 44LL));
  writel(0xAu, (unsigned int *)(*(_QWORD *)(a1 + 120) + 48LL));
  writel(0x26u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 52LL));
  writel(0xAu, (unsigned int *)(*(_QWORD *)(a1 + 120) + 56LL));
  writel(3u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 60LL));
  writel(0xB7u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 64LL));
  writel(3u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 68LL));
  v3 = *(_QWORD *)(a1 + 120);
  *(_DWORD *)(a1 + 296) = 0;
  return writel(0x1Fu, (unsigned int *)(v3 + 84));
}
