__int64 amoled_oledb_regulator_is_enabled()
{
  return *(unsigned __int8 *)(rdev_get_drvdata() + 356);
}
