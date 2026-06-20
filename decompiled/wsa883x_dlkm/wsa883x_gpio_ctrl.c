__int64 __fastcall wsa883x_gpio_ctrl(__int64 a1, char a2)
{
  __int64 v3; // x0
  __int64 result; // x0
  int v6; // w4

  v3 = *(_QWORD *)(a1 + 176);
  if ( (a2 & 1) != 0 )
  {
    result = msm_cdc_pinctrl_select_active_state(v3);
    v6 = result;
    if ( !(_DWORD)result )
      return result;
    return dev_err(*(_QWORD *)(a1 + 8), "%s: Failed to turn state %d; ret=%d\n", "wsa883x_gpio_ctrl", a2 & 1, v6);
  }
  result = msm_cdc_pinctrl_select_sleep_state(v3);
  v6 = result;
  if ( (_DWORD)result )
    return dev_err(*(_QWORD *)(a1 + 8), "%s: Failed to turn state %d; ret=%d\n", "wsa883x_gpio_ctrl", a2 & 1, v6);
  return result;
}
