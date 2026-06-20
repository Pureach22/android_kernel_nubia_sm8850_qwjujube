__int64 __fastcall msm_get_function_name(__int64 a1, unsigned int a2)
{
  return *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(pinctrl_dev_get_drvdata() + 968) + 16LL) + 24LL * a2);
}
