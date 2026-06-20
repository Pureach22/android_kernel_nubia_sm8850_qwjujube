__int64 __fastcall hal_rx_reo_buf_type_get_be(__int64 a1)
{
  return *(_BYTE *)(a1 + 28) & 1;
}
