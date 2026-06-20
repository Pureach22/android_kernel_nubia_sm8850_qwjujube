bool rpmh_regulator_is_enabled()
{
  return *(_DWORD *)(rdev_get_drvdata() + 352) != 0;
}
