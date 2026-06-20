__int64 ipa3_get_r_rev_version()
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  result = (unsigned int)ipa3_get_r_rev_version_r_rev;
  if ( !ipa3_get_r_rev_version_r_rev )
  {
    ipa3_inc_client_enable_clks();
    ipa3_get_r_rev_version_r_rev = ipahal_read_reg_n(12, 0);
    ipa3_dec_client_disable_clks();
    result = (unsigned int)ipa3_get_r_rev_version_r_rev;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
