__int64 __fastcall aead_key_free(__int64 a1)
{
  return crypto_destroy_tfm(a1, a1 + 8);
}
