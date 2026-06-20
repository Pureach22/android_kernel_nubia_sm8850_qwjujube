__int64 __fastcall qcom_ice_suspend(__int64 a1)
{
  __int64 v1; // x19

  if ( *(_BYTE *)(a1 + 35) == 1 )
  {
    v1 = *(_QWORD *)(a1 + 24);
    clk_disable(v1);
    clk_unprepare(v1);
  }
  return 0;
}
