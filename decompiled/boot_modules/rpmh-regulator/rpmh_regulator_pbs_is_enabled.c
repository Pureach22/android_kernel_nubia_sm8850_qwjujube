bool rpmh_regulator_pbs_is_enabled()
{
  return *(_DWORD *)(rdev_get_drvdata() + 348) != 0;
}
