__int64 __fastcall _gsi_config_ch_irq(unsigned int a1)
{
  gsihal_read_reg_nk(1, a1, 0);
  return gsihal_write_reg_nk(1, a1, 0);
}
