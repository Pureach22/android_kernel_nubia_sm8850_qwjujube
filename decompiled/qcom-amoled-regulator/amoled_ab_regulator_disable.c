__int64 amoled_ab_regulator_disable()
{
  __int64 drvdata; // x8

  drvdata = rdev_get_drvdata();
  *(_BYTE *)(drvdata + 708) = 0;
  return 0;
}
