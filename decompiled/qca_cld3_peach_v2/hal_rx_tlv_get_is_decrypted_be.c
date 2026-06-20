bool __fastcall hal_rx_tlv_get_is_decrypted_be(__int64 a1)
{
  return (*(_BYTE *)(a1 + 61) & 0x1C) == 0;
}
