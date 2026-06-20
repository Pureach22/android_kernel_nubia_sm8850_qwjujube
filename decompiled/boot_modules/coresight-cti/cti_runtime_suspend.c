__int64 __fastcall cti_runtime_suspend(__int64 a1)
{
  __int64 v1; // x8
  unsigned __int64 v2; // x19

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
  {
    v2 = *(_QWORD *)(v1 + 1224);
    if ( v2 <= 0xFFFFFFFFFFFFF000LL )
    {
      clk_disable(*(_QWORD *)(v1 + 1224));
      clk_unprepare(v2);
    }
  }
  return 0;
}
