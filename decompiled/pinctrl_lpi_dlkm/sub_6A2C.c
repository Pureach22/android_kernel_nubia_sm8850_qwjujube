__int64 sub_6A2C()
{
  __asm { PRFM            #8, 0xFFFFFFFFFFF15110 }
  return lpi_gpio_get_group_name();
}
