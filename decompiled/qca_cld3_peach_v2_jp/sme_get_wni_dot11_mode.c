__int64 __fastcall sme_get_wni_dot11_mode(__int64 a1)
{
  return csr_translate_to_wni_cfg_dot11_mode(a1, *(unsigned int *)(a1 + 17132));
}
