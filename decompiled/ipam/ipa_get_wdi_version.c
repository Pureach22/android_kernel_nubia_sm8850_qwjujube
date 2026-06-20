__int64 ipa_get_wdi_version()
{
  if ( ipa_wdi_ctx_list )
    return *(unsigned int *)(ipa_wdi_ctx_list + 144);
  else
    return 2;
}
