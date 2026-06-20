__int64 __fastcall hal_rx_tlv_decrypt_err_get_be(__int64 a1)
{
  return (*(_QWORD *)(a1 + 52) >> 61) & 1LL;
}
