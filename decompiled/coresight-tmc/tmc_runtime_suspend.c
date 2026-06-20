__int64 __fastcall tmc_runtime_suspend(__int64 a1)
{
  unsigned __int64 *v1; // x20
  unsigned __int64 v2; // x19
  unsigned __int64 v3; // x19

  v1 = *(unsigned __int64 **)(a1 + 152);
  if ( v1 )
  {
    v2 = *v1;
    if ( *v1 && v2 <= 0xFFFFFFFFFFFFF000LL )
    {
      clk_disable(*v1);
      clk_unprepare(v2);
    }
    v3 = v1[45];
    if ( v3 <= 0xFFFFFFFFFFFFF000LL )
    {
      clk_disable(v1[45]);
      clk_unprepare(v3);
    }
  }
  return 0;
}
