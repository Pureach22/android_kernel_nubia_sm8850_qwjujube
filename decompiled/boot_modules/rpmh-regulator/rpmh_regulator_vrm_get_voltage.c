__int64 rpmh_regulator_vrm_get_voltage()
{
  unsigned int v0; // w8

  v0 = 1000 * *(_DWORD *)(rdev_get_drvdata() + 348);
  if ( v0 <= 1 )
    return 1;
  else
    return v0;
}
