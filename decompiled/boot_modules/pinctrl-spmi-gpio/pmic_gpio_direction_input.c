__int64 __fastcall pmic_gpio_direction_input(__int64 a1, unsigned int a2)
{
  __int64 v3; // x0
  __int64 result; // x0
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(gpiochip_get_data() + 16);
  v5[0] = 268;
  result = pmic_gpio_config_set(v3, a2, (__int64)v5, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
