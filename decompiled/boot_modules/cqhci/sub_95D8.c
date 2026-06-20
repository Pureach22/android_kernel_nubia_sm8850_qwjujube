__int64 sub_95D8()
{
  int v0; // w12

  if ( (v0 & 0x10000000) == 0 )
    JUMPOUT(0xC4FC);
  return cqhci_crypto_keyslot_program();
}
