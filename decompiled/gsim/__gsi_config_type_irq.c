__int64 __fastcall _gsi_config_type_irq(unsigned int a1)
{
  gsihal_read_reg_nk(0, a1, 0);
  return gsihal_write_reg_nk(0, a1, 0);
}
