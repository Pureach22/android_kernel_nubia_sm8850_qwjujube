__int64 ipa_get_tx_buf_count()
{
  if ( g_ipa_config )
    return *(unsigned int *)(g_ipa_config + 8);
  else
    return 0;
}
