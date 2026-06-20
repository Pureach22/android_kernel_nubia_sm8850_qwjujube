__int64 reg_clock_disable()
{
  __int64 drvdata; // x0
  __int64 v1; // x20
  __int64 v2; // x19

  drvdata = rdev_get_drvdata();
  v1 = *(_QWORD *)(drvdata + 328);
  v2 = drvdata;
  clk_disable(v1);
  clk_unprepare(v1);
  --*(_DWORD *)(v2 + 336);
  return 0;
}
