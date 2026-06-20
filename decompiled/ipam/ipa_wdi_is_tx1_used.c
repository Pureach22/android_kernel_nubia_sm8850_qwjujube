__int64 ipa_wdi_is_tx1_used()
{
  char v0; // w8

  v0 = ipa_wdi_ctx_list;
  if ( ipa_wdi_ctx_list )
    v0 = *(_BYTE *)(ipa_wdi_ctx_list + 161);
  return v0 & 1;
}
