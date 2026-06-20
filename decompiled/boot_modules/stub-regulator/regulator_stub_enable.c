__int64 regulator_stub_enable()
{
  __int64 drvdata; // x8

  drvdata = rdev_get_drvdata();
  *(_BYTE *)(drvdata + 324) = 1;
  return 0;
}
