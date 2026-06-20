__int64 __fastcall bam_reset(__int64 a1)
{
  unsigned int v2; // w20

  v2 = readl_relaxed((unsigned int *)(*(_QWORD *)a1
                                    + **(unsigned int **)(a1 + 440)
                                    + (unsigned int)(*(_DWORD *)(a1 + 424) * *(_DWORD *)(*(_QWORD *)(a1 + 440) + 12LL))));
  writel_relaxed(
    v2 | 1,
    *(_QWORD *)a1
  + **(unsigned int **)(a1 + 440)
  + (unsigned int)(*(_DWORD *)(a1 + 424) * *(_DWORD *)(*(_QWORD *)(a1 + 440) + 12LL)));
  v2 &= ~1u;
  writel_relaxed(
    v2,
    *(_QWORD *)a1
  + **(unsigned int **)(a1 + 440)
  + (unsigned int)(*(_DWORD *)(a1 + 424) * *(_DWORD *)(*(_QWORD *)(a1 + 440) + 12LL)));
  __dsb(0xEu);
  writel_relaxed(
    v2 | 2,
    *(_QWORD *)a1
  + **(unsigned int **)(a1 + 440)
  + (unsigned int)(*(_DWORD *)(a1 + 424) * *(_DWORD *)(*(_QWORD *)(a1 + 440) + 12LL)));
  writel_relaxed(
    4,
    *(_QWORD *)a1
  + *(unsigned int *)(*(_QWORD *)(a1 + 440) + 48LL)
  + (unsigned int)(*(_DWORD *)(a1 + 424) * *(_DWORD *)(*(_QWORD *)(a1 + 440) + 60LL)));
  writel_relaxed(
    268431364,
    *(_QWORD *)a1
  + *(unsigned int *)(*(_QWORD *)(a1 + 440) + 160LL)
  + (unsigned int)(*(_DWORD *)(a1 + 424) * *(_DWORD *)(*(_QWORD *)(a1 + 440) + 172LL)));
  writel_relaxed(
    6,
    *(_QWORD *)a1
  + *(unsigned int *)(*(_QWORD *)(a1 + 440) + 144LL)
  + (unsigned int)(*(_DWORD *)(a1 + 424) * *(_DWORD *)(*(_QWORD *)(a1 + 440) + 156LL)));
  return writel_relaxed(
           0x80000000LL,
           *(_QWORD *)a1
         + *(unsigned int *)(*(_QWORD *)(a1 + 440) + 192LL)
         + (unsigned int)(*(_DWORD *)(a1 + 424) * *(_DWORD *)(*(_QWORD *)(a1 + 440) + 204LL)));
}
