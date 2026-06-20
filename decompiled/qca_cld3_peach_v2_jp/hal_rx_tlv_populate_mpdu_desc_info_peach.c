__int64 __fastcall hal_rx_tlv_populate_mpdu_desc_info_peach(__int64 result, __int64 a2)
{
  *(_WORD *)(a2 + 2) = *(_DWORD *)(result + 80) >> 20;
  *(_DWORD *)(a2 + 4) = (*(_QWORD *)(result + 88) >> 37) & 0x100000
                      | *(_QWORD *)(result + 88) & 0x40000000
                      | ((unsigned int)*(_QWORD *)(result + 88) >> 6) & 0x400000
                      | (((*(_DWORD *)(result + 80) >> 19) & 1) << 21) & 0x7FFFFFFF
                      | ((unsigned __int8)(*(_DWORD *)(result + 80) >> 7) << 31);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(result + 84);
  *(_WORD *)(a2 + 12) = (*(_DWORD *)(result + 88) & 0x20000000) != 0;
  return result;
}
