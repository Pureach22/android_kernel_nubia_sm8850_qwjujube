char *__fastcall cam_eeprom_get_i3c_completion(unsigned int a1)
{
  if ( a1 < 0x10 )
    return (char *)&g_i3c_eeprom_data + 40 * a1 + 8;
  __break(0x5512u);
  __asm { PRFM            #0xC, [X16,#0x618] }
  return (char *)cam_eeprom_update_i2c_info();
}
