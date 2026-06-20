__int64 amoled_ibb_regulator_enable()
{
  __int64 drvdata; // x8

  drvdata = rdev_get_drvdata();
  *(_BYTE *)(drvdata + 1060) = 1;
  return 0;
}
