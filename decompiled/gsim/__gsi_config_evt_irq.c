__int64 __fastcall _gsi_config_evt_irq(unsigned int a1)
{
  gsihal_read_reg_nk(2, a1, 0);
  return gsihal_write_reg_nk(2, a1, 0);
}
