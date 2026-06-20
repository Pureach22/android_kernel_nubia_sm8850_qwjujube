__int64 ucfg_ipa_is_ready()
{
  return ipa_cb_is_ready() & 1;
}
