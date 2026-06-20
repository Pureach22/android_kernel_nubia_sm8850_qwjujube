__int64 __fastcall gmu_core_disable_clks(__int64 a1)
{
  unsigned int v1; // w19
  __int64 v2; // x20

  v1 = *(_DWORD *)(a1 + 8320);
  v2 = *(_QWORD *)(a1 + 8312);
  clk_bulk_disable(v1, v2);
  return clk_bulk_unprepare(v1, v2);
}
