__int64 __fastcall hal_rx_mpdu_get_addr2_be(__int64 a1, __int64 a2)
{
  if ( (*(_BYTE *)(a1 + 80) & 8) == 0 )
    return 16;
  *(_WORD *)a2 = WORD1(*(_QWORD *)(a1 + 104));
  *(_DWORD *)(a2 + 2) = *(_DWORD *)(a1 + 108);
  return 0;
}
