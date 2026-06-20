__int64 __fastcall hal_rx_ret_buf_manager_get_be(__int64 a1)
{
  return *(_BYTE *)(a1 + 5) & 0xF;
}
