__int64 __fastcall hal_rx_mpdu_get_addr3_be(__int64 a1, __int64 a2)
{
  if ( (*(_BYTE *)(a1 + 80) & 0x10) == 0 )
    return 16;
  *(_DWORD *)a2 = *(_QWORD *)(a1 + 112);
  *(_WORD *)(a2 + 4) = *(_DWORD *)(a1 + 116);
  return 0;
}
