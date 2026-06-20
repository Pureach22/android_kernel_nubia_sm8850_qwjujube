__int64 __fastcall _gsi_config_glob_irq(unsigned int a1)
{
  gsihal_read_reg_nk(4, a1, 0);
  return gsihal_write_reg_nk(4, a1, 0);
}
