__int64 __fastcall sub_10975C(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w11
  unsigned __int64 *v5; // x29

  __stlxp(__PAIR64__(a2, v4), v5);
  return kgsl_mmu_map_zero_page_to_range(a1, a2, a3, a4);
}
