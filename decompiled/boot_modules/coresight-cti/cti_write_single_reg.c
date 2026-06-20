__int64 __fastcall cti_write_single_reg(__int64 *a1, int a2, unsigned int a3)
{
  __int64 v6; // x8

  writel_relaxed(0xC5ACCE55, (unsigned int *)(*a1 + 4016));
  __dsb(0xFu);
  writel_relaxed(a3, (unsigned int *)(*a1 + a2));
  v6 = *a1;
  __dsb(0xFu);
  return writel_relaxed(0, (unsigned int *)(v6 + 4016));
}
