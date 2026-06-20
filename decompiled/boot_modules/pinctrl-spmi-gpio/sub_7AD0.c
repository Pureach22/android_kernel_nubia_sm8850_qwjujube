__int64 sub_7AD0()
{
  __int16 v0; // w11

  if ( (v0 & 0x100) == 0 )
    JUMPOUT(0xF4C);
  return pmic_gpio_of_xlate();
}
