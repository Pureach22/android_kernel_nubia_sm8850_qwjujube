__int64 __fastcall hal_rx_wbm_err_src_get_be(__int64 a1)
{
  return *(_DWORD *)(a1 + 8) & 7;
}
