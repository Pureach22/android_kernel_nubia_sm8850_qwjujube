__int64 __fastcall hal_rx_msdu_flags_get_be(_DWORD *a1)
{
  return *a1 & 7
       | (((*a1 >> 18) & 1) << 23) & 0xE9FFFFFF
       | (((*a1 >> 19) & 3) << 25) & 0xEFFFFFFF
       | (((*a1 >> 26) & 1) << 28);
}
