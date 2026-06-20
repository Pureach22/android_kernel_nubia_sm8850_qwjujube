__int64 __fastcall hal_rx_get_bb_info_peach(__int64 result, _BYTE *a2)
{
  a2[14216] = (*(_DWORD *)(result + 12) & 0x2000000) != 0;
  a2[14217] = (*(_DWORD *)(result + 12) & 0x20000000) != 0;
  a2[14218] = (*(_DWORD *)(result + 12) >> 26) & 7;
  return result;
}
