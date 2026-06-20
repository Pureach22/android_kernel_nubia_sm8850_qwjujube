unsigned __int64 __fastcall aead_key_setup_encrypt(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  unsigned __int64 result; // x0
  unsigned __int64 v6; // x20
  int v7; // w21

  result = crypto_alloc_aead(a1, 0, 128);
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    v6 = result;
    v7 = crypto_aead_setkey();
    if ( v7 || (v7 = crypto_aead_setauthsize(v6, a4)) != 0 )
    {
      crypto_destroy_tfm(v6, v6 + 8);
      return v7;
    }
    else
    {
      return v6;
    }
  }
  return result;
}
