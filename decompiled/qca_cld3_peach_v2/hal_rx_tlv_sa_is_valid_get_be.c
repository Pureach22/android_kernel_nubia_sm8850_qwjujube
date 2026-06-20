__int64 __fastcall hal_rx_tlv_sa_is_valid_get_be(__int64 a1)
{
  return (*(_QWORD *)(a1 + 12) >> 55) & 1LL;
}
