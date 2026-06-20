__int64 __fastcall hal_rx_tlv_last_msdu_get_be(__int64 a1)
{
  return (*(_QWORD *)(a1 + 12) >> 61) & 1LL;
}
