__int64 __fastcall clk_runtime_get_regmap(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 112);
  v3 = *(_QWORD *)(v2 + 96);
  if ( v3 && (*(_WORD *)(v3 + 488) & 7) == 0 )
  {
    result = _pm_runtime_resume(*(_QWORD *)(v2 + 96), 4);
    if ( (result & 0x80000000) != 0 )
      return result;
    v2 = *(_QWORD *)(a1 + 112);
  }
  if ( (*(_WORD *)(v2 + 488) & 7) != 0 )
    return 0;
  result = _pm_runtime_resume(v2, 4);
  if ( (result & 0x80000000) == 0 )
    return 0;
  return result;
}
