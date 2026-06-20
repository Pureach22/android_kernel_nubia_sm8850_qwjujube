__int64 ipa_pm_get_aggregated_throughput()
{
  if ( ipa_pm_ctx )
    return *(unsigned int *)(ipa_pm_ctx + 1200);
  else
    return 0;
}
