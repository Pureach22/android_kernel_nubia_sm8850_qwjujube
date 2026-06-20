__int64 __fastcall _gsi_config_ieob_irq_k(unsigned int a1, unsigned int a2)
{
  gsihal_read_reg_nk(132, a1, a2);
  return gsihal_write_reg_nk(132, a1, a2);
}
