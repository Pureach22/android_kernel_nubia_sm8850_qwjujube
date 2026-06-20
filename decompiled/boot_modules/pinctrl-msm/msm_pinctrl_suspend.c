__int64 __fastcall msm_pinctrl_suspend(__int64 a1)
{
  return pinctrl_force_sleep(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 8LL));
}
