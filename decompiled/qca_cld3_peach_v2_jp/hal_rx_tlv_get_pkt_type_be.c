__int64 __fastcall hal_rx_tlv_get_pkt_type_be(__int64 a1)
{
  return (*(_QWORD *)(a1 + 44) >> 40) & 0xFLL;
}
