__int64 __fastcall hal_rx_tlv_rate_mcs_get_be(__int64 a1)
{
  return (*(_QWORD *)(a1 + 44) >> 46) & 0xFLL;
}
