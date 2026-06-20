__int64 reg_clock_enable()
{
  __int64 drvdata; // x0
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 result; // x0
  unsigned int v4; // w19

  drvdata = rdev_get_drvdata();
  v1 = *(_QWORD *)(drvdata + 328);
  v2 = drvdata;
  result = clk_prepare(v1);
  if ( !(_DWORD)result )
  {
    result = clk_enable(v1);
    if ( (_DWORD)result )
    {
      v4 = result;
      clk_unprepare(v1);
      return v4;
    }
    else
    {
      ++*(_DWORD *)(v2 + 336);
    }
  }
  return result;
}
