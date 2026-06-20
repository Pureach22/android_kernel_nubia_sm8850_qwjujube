__int64 __fastcall ieee80211_aes_cmac_key_free(__int64 a1)
{
  return crypto_destroy_tfm(a1, a1 + 8);
}
