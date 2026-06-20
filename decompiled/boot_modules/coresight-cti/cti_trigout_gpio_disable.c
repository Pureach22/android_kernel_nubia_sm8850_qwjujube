__int64 __fastcall cti_trigout_gpio_disable(__int64 a1)
{
  __int64 result; // x0

  result = **(_QWORD **)(a1 + 1216);
  if ( result )
  {
    result = devm_pinctrl_put();
    **(_QWORD **)(a1 + 1216) = 0;
  }
  return result;
}
