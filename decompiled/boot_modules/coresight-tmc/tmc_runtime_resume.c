__int64 __fastcall tmc_runtime_resume(__int64 a1)
{
  unsigned __int64 *v1; // x20
  unsigned __int64 v2; // x19
  unsigned __int64 v3; // x19

  v1 = *(unsigned __int64 **)(a1 + 152);
  if ( v1 )
  {
    v2 = *v1;
    if ( *v1 && v2 <= 0xFFFFFFFFFFFFF000LL && !(unsigned int)clk_prepare(*v1) && (unsigned int)clk_enable(v2) )
      clk_unprepare(v2);
    v3 = v1[45];
    if ( v3 <= 0xFFFFFFFFFFFFF000LL && !(unsigned int)clk_prepare(v1[45]) && (unsigned int)clk_enable(v3) )
      clk_unprepare(v3);
  }
  return 0;
}
