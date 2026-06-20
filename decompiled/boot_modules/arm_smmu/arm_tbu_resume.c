__int64 __fastcall arm_tbu_resume(__int64 a1)
{
  unsigned int *v1; // x19
  int v2; // w0

  v1 = *(unsigned int **)(a1 + 32);
  v2 = readl_relaxed_1(v1);
  return writel_relaxed_1(v2 & 0xFFFEFFFF, v1);
}
