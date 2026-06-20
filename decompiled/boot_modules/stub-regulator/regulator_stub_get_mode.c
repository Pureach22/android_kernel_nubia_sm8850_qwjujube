__int64 regulator_stub_get_mode()
{
  return *(unsigned int *)(rdev_get_drvdata() + 328);
}
