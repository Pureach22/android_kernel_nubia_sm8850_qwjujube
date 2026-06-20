__int64 __fastcall replicator_runtime_suspend(__int64 a1)
{
  __int64 v1; // x20
  unsigned __int64 v2; // x19
  unsigned __int64 v3; // x19

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
  {
    v2 = *(_QWORD *)(v1 + 8);
    if ( v2 <= 0xFFFFFFFFFFFFF000LL )
    {
      clk_disable(*(_QWORD *)(v1 + 8));
      clk_unprepare(v2);
    }
    v3 = *(_QWORD *)(v1 + 16);
    if ( v3 && v3 <= 0xFFFFFFFFFFFFF000LL )
    {
      clk_disable(*(_QWORD *)(v1 + 16));
      clk_unprepare(v3);
    }
  }
  return 0;
}
