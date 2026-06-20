__int64 ipa3_read_ipahal_regs()
{
  _ReadStatusReg(SP_EL0);
  ipa3_inc_client_enable_clks();
  ipahal_print_all_regs(1);
  ipa3_dec_client_disable_clks();
  _ReadStatusReg(SP_EL0);
  return 0;
}
