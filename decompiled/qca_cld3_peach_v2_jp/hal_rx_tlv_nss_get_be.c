__int64 __fastcall hal_rx_tlv_nss_get_be(__int64 a1)
{
  unsigned int v1; // w8

  v1 = (*(_BYTE *)(a1 + 51) & 0x7F) - ((*(unsigned __int8 *)(a1 + 51) >> 1) & 0x15);
  return (((v1 >> 2) & 0x33) + (v1 & 0x33) + ((((v1 >> 2) & 0x33) + (v1 & 0x33)) >> 4)) & 0xF;
}
