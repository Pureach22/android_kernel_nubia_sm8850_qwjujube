__int64 __fastcall hal_rx_tlv_l3_hdr_padding_get_be(__int64 a1)
{
  return (*(_QWORD *)(a1 + 12) >> 58) & 3LL;
}
