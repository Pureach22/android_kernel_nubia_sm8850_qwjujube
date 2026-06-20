__int64 __fastcall dummy_clk_set_rate(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a1 + 120) = a2;
  return 0;
}
