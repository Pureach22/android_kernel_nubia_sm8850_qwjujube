bool __fastcall gmu_core_is_trace_empty(__int64 a1)
{
  int v2; // w20

  v2 = readl_3((unsigned int *)(a1 + 16));
  return v2 == (unsigned int)readl_3((unsigned int *)(a1 + 20));
}
