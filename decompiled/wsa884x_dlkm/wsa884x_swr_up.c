__int64 __fastcall wsa884x_swr_up(__int64 a1)
{
  __int64 result; // x0
  int v3; // w20

  result = msm_cdc_pinctrl_select_active_state(*(_QWORD *)(a1 + 200));
  if ( (_DWORD)result )
  {
    v3 = result;
    if ( (unsigned int)__ratelimit(&wsa884x_gpio_ctrl__rs, "wsa884x_gpio_ctrl") )
      dev_err(*(_QWORD *)(a1 + 8), "%s: Failed to turn state %d; ret=%d\n", "wsa884x_gpio_ctrl", 1, v3);
    result = __ratelimit(&wsa884x_swr_up__rs, "wsa884x_swr_up");
    if ( (_DWORD)result )
      return dev_err(*(_QWORD *)(a1 + 8), "%s: Failed to enable gpio\n", "wsa884x_swr_up");
  }
  return result;
}
