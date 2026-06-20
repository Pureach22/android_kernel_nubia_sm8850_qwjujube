__int64 qcom_scm_clk_enable()
{
  __int64 v0; // x19
  __int64 result; // x0
  unsigned int v2; // w21
  __int64 v3; // x19
  __int64 v4; // x19

  v0 = *(_QWORD *)(_scm + 8);
  result = clk_prepare(v0);
  if ( !(_DWORD)result )
  {
    v2 = clk_enable(v0);
    if ( !v2 )
    {
      v3 = *(_QWORD *)(_scm + 16);
      v2 = clk_prepare(v3);
      if ( !v2 )
      {
        v2 = clk_enable(v3);
        if ( !v2 )
        {
          v4 = *(_QWORD *)(_scm + 24);
          v2 = clk_prepare(v4);
          if ( !v2 )
          {
            result = clk_enable(v4);
            if ( !(_DWORD)result )
              return result;
            v2 = result;
            clk_unprepare(v4);
          }
          v3 = *(_QWORD *)(_scm + 16);
          clk_disable(v3);
        }
        clk_unprepare(v3);
      }
      v0 = *(_QWORD *)(_scm + 8);
      clk_disable(v0);
    }
    clk_unprepare(v0);
    return v2;
  }
  return result;
}
