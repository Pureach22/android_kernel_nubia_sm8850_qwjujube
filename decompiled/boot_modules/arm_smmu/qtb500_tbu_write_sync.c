__int64 __fastcall qtb500_tbu_write_sync(__int64 a1)
{
  return readl_relaxed_1(*(unsigned int **)(a1 + 32));
}
