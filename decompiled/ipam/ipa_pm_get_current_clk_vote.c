__int64 ipa_pm_get_current_clk_vote()
{
  unsigned int *v0; // x8

  if ( ipa_pm_ctx )
    v0 = (unsigned int *)(ipa_pm_ctx + 1120);
  else
    v0 = (unsigned int *)(ipa3_ctx + 48848);
  return *v0;
}
