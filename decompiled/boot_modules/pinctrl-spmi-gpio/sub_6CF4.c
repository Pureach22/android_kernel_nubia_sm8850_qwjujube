__int64 sub_6CF4()
{
  __asm { PRFM            #8, 0xFFFFFFFFFFF153D8 }
  return pmic_gpio_get_group_name();
}
