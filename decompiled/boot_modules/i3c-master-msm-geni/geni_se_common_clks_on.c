__int64 __fastcall geni_se_common_clks_on(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v7; // w22

  result = clk_prepare(a2);
  if ( !(_DWORD)result )
  {
    v7 = clk_enable(a2);
    if ( !v7 )
    {
      v7 = clk_prepare(a3);
      if ( !v7 )
      {
        v7 = clk_enable(a3);
        if ( !v7 )
        {
          v7 = clk_prepare(a1);
          if ( !v7 )
          {
            result = clk_enable(a1);
            if ( !(_DWORD)result )
              return result;
            v7 = result;
            clk_unprepare(a1);
          }
          clk_disable(a3);
        }
        clk_unprepare(a3);
      }
      clk_disable(a2);
    }
    clk_unprepare(a2);
    return v7;
  }
  return result;
}
