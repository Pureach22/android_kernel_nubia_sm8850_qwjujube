__int64 msm_get_groups_count()
{
  return *(unsigned int *)(*(_QWORD *)(pinctrl_dev_get_drvdata() + 968) + 40LL);
}
