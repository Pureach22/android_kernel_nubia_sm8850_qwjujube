__int64 sub_65E5F8()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x6655CC);
  return ucfg_fwol_get_tsf_gpio_pin();
}
