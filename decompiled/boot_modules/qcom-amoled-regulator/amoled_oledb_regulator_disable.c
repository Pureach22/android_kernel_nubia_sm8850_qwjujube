__int64 amoled_oledb_regulator_disable()
{
  __int64 drvdata; // x8

  drvdata = rdev_get_drvdata();
  *(_BYTE *)(drvdata + 356) = 0;
  return 0;
}
