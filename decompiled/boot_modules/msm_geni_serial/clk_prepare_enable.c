__int64 __fastcall clk_prepare_enable(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w20

  result = clk_prepare(a1);
  if ( !(_DWORD)result )
  {
    result = clk_enable(a1);
    if ( (_DWORD)result )
    {
      v3 = result;
      clk_unprepare(a1);
      return v3;
    }
  }
  return result;
}
