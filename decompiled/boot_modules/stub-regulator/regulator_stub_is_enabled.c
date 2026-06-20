__int64 regulator_stub_is_enabled()
{
  return *(unsigned __int8 *)(rdev_get_drvdata() + 324);
}
