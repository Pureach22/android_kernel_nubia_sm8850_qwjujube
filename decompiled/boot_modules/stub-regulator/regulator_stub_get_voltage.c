__int64 regulator_stub_get_voltage()
{
  return *(unsigned int *)(rdev_get_drvdata() + 320);
}
