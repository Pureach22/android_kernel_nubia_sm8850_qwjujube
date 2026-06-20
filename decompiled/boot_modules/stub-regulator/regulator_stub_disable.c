__int64 regulator_stub_disable()
{
  __int64 drvdata; // x8

  drvdata = rdev_get_drvdata();
  *(_BYTE *)(drvdata + 324) = 0;
  return 0;
}
