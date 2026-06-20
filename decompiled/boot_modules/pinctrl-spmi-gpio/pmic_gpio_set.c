__int64 __fastcall pmic_gpio_set(__int64 a1, unsigned int a2, int a3)
{
  __int64 v5; // x0
  __int64 result; // x0
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(gpiochip_get_data() + 16);
  v7[0] = (a3 << 8) | 0x12u;
  result = pmic_gpio_config_set(v5, a2, (__int64)v7, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
