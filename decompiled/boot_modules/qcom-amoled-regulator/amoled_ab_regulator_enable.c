__int64 amoled_ab_regulator_enable()
{
  __int64 drvdata; // x8

  drvdata = rdev_get_drvdata();
  *(_BYTE *)(drvdata + 708) = 1;
  return 0;
}
