__int64 __fastcall hal_rx_mpdu_info_ampdu_flag_get_peach(__int64 a1)
{
  return (*(unsigned __int8 *)(a1 + 91) >> 4) & 1;
}
