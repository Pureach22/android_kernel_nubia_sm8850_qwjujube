__int64 __fastcall hal_rx_tlv_da_is_mcbc_get_be(__int64 a1)
{
  return (*(_QWORD *)(a1 + 12) >> 57) & 1LL;
}
