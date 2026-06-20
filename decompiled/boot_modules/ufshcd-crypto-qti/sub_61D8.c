__int64 sub_61D8()
{
  int v0; // w12

  if ( (v0 & 0x10000000) == 0 )
    JUMPOUT(0x90FC);
  return ufshcd_qti_crypto_keyslot_program();
}
