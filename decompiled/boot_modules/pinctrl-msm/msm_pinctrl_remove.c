__int64 __fastcall msm_pinctrl_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  gpiochip_remove(v1 + 16);
  return unregister_restart_handler(v1 + 728);
}
