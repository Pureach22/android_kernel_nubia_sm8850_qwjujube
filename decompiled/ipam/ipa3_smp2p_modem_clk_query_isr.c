__int64 ipa3_smp2p_modem_clk_query_isr()
{
  ipa3_freeze_clock_vote_and_notify_modem();
  return 1;
}
