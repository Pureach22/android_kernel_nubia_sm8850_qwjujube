__int64 rpmh_regulator_arc_get_voltage_sel()
{
  return *(unsigned int *)(rdev_get_drvdata() + 348);
}
