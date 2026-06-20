__int64 rpmh_regulator_vrm_get_mode()
{
  __int64 drvdata; // x0

  drvdata = rdev_get_drvdata();
  return *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(drvdata + 336) + 232LL) + 12LL * *(int *)(drvdata + 368) + 4);
}
