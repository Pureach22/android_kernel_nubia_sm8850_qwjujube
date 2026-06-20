unsigned __int64 ieee80211_aes_cmac_key_setup()
{
  unsigned __int64 result; // x0
  unsigned __int64 v1; // x21
  int v2; // w0
  int v3; // w19

  result = crypto_alloc_shash("cmac(aes)", 0, 0);
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    v1 = result;
    v2 = crypto_shash_setkey();
    if ( v2 )
    {
      v3 = v2;
      crypto_destroy_tfm(v1, v1 + 8);
      return v3;
    }
    else
    {
      return v1;
    }
  }
  return result;
}
