__int64 __fastcall qce_disable_clk(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x20
  __int64 v4; // x20
  __int64 v5; // x19

  if ( (*(_BYTE *)(a1 + 70249) & 1) == 0 )
  {
    v1 = *(_QWORD *)(a1 + 120);
    if ( v1 )
    {
      clk_disable(*(_QWORD *)(a1 + 120));
      clk_unprepare(v1);
    }
    v3 = *(_QWORD *)(a1 + 112);
    if ( v3 )
    {
      clk_disable(*(_QWORD *)(a1 + 112));
      clk_unprepare(v3);
    }
    v4 = *(_QWORD *)(a1 + 104);
    if ( v4 )
    {
      clk_disable(*(_QWORD *)(a1 + 104));
      clk_unprepare(v4);
    }
    v5 = *(_QWORD *)(a1 + 96);
    if ( v5 )
    {
      clk_disable(v5);
      clk_unprepare(v5);
    }
  }
  return 0;
}
