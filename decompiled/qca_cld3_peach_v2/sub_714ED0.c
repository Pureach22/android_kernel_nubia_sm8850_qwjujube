__int64 sub_714ED0()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x71BEA4);
  return ucfg_fwol_get_tsf_gpio_pin();
}
