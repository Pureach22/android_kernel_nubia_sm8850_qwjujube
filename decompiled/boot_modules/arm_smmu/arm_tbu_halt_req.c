__int64 __fastcall arm_tbu_halt_req(__int64 a1)
{
  unsigned int *v1; // x19
  int v2; // w0

  v1 = *(unsigned int **)(a1 + 32);
  v2 = readl_relaxed_1(v1);
  writel_relaxed_1(v2 | 0x10000, v1);
  return 0;
}
