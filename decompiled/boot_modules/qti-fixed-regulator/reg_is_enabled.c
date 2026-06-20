bool reg_is_enabled()
{
  return *(_DWORD *)(rdev_get_drvdata() + 336) != 0;
}
