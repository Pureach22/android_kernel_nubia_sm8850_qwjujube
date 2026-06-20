__int64 __fastcall hal_rx_get_fisa_timeout_be(__int64 a1)
{
  return (*(unsigned __int8 *)(a1 + 37) >> 1) & 1;
}
