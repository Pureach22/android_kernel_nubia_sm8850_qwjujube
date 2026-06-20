__int64 __fastcall hal_rx_tlv_decap_format_get_be(__int64 a1)
{
  return (*(_DWORD *)(a1 + 44) >> 8) & 3;
}
