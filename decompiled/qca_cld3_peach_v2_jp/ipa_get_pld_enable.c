__int64 ipa_get_pld_enable()
{
  return (unsigned __int8)g_ipa_pld_enable & (unsigned __int8)g_ipa_cap_offload & 1;
}
