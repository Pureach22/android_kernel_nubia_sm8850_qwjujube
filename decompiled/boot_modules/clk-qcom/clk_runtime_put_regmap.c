__int64 __fastcall clk_runtime_put_regmap(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 112);
  if ( (*(_WORD *)(v2 + 488) & 7) == 0 )
  {
    _pm_runtime_idle(v2, 4);
    v2 = *(_QWORD *)(a1 + 112);
  }
  result = *(_QWORD *)(v2 + 96);
  if ( result )
  {
    if ( (*(_WORD *)(result + 488) & 7) == 0 )
      return _pm_runtime_idle(result, 4);
  }
  return result;
}
