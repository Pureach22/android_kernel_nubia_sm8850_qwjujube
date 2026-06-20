__int64 amoled_ab_ibb_regulator_get_mode()
{
  return *(unsigned int *)(rdev_get_drvdata() + 1056);
}
