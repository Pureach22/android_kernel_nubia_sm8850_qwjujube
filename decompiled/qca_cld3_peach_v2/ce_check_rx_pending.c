bool __fastcall ce_check_rx_pending(__int64 a1)
{
  return *(_DWORD *)(a1 + 160) != 0;
}
