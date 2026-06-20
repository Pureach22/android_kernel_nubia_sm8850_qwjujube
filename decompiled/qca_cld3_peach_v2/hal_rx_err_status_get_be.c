__int64 __fastcall hal_rx_err_status_get_be(__int64 a1)
{
  return (*(unsigned __int8 *)(a1 + 28) >> 1) & 3;
}
