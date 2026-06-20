__int64 __fastcall hal_rx_tlv_da_is_valid_get_be(__int64 a1)
{
  return *(_BYTE *)(a1 + 19) & 1;
}
