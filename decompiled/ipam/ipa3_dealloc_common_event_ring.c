__int64 ipa3_dealloc_common_event_ring()
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  ipa3_inc_client_enable_clks();
  gsi_dealloc_evt_ring(*(_QWORD *)(ipa3_ctx + 32024));
  result = ipa3_dec_client_disable_clks();
  _ReadStatusReg(SP_EL0);
  return result;
}
