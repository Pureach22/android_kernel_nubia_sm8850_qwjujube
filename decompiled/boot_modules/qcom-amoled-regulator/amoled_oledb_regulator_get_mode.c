__int64 amoled_oledb_regulator_get_mode()
{
  return *(unsigned int *)(rdev_get_drvdata() + 352);
}
