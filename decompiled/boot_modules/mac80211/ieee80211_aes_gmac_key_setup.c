unsigned __int64 ieee80211_aes_gmac_key_setup()
{
  unsigned __int64 result; // x0
  unsigned __int64 v1; // x19
  int v2; // w20

  result = crypto_alloc_aead("gcm(aes)", 0, 128);
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    v1 = result;
    v2 = crypto_aead_setkey();
    if ( v2 || (v2 = crypto_aead_setauthsize(v1, 16)) != 0 )
    {
      crypto_destroy_tfm(v1, v1 + 8);
      return v2;
    }
    else
    {
      return v1;
    }
  }
  return result;
}
