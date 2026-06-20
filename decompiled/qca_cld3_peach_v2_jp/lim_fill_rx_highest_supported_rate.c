void __fastcall lim_fill_rx_highest_supported_rate(__int64 a1, _WORD *a2, __int64 a3)
{
  *a2 = *(unsigned __int8 *)(a3 + 10) | ((*(_BYTE *)(a3 + 11) & 3) << 8);
}
