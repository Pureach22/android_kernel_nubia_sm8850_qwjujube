__int64 __fastcall cti_trigin_gpio_disable(__int64 a1)
{
  __int64 result; // x0

  result = **(_QWORD **)(a1 + 1208);
  if ( result )
  {
    result = devm_pinctrl_put();
    **(_QWORD **)(a1 + 1208) = 0;
  }
  return result;
}
