__int64 __fastcall hal_rx_tlv_sgi_get_be(__int64 a1)
{
  return (*(_QWORD *)(a1 + 44) >> 44) & 3LL;
}
