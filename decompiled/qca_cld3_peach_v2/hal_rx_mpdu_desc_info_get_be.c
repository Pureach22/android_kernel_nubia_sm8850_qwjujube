__int64 __fastcall hal_rx_mpdu_desc_info_get_be(__int64 result, __int64 a2)
{
  char v2; // w9

  *(_WORD *)a2 = *(unsigned __int8 *)(result + 8);
  *(_DWORD *)(a2 + 4) = (*(_DWORD *)(result + 8) << 17) & 0x40000000
                      | (((*(_DWORD *)(result + 8) >> 8) & 7) << 20) & 0x7FFFFFFF
                      | (*(_DWORD *)(result + 8) >> 27 << 31);
  v2 = *(_BYTE *)(a2 + 14);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(result + 12);
  *(_WORD *)(a2 + 12) = (*(_WORD *)(result + 8) >> 11) & 1;
  *(_BYTE *)(a2 + 14) = v2 & 0xF0 | (*(_DWORD *)(result + 8) >> 28);
  return result;
}
