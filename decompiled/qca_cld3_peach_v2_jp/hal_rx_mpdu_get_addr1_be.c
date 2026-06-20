__int64 __fastcall hal_rx_mpdu_get_addr1_be(__int64 a1, __int64 a2)
{
  if ( (*(_BYTE *)(a1 + 80) & 4) == 0 )
    return 16;
  *(_DWORD *)a2 = *(_DWORD *)(a1 + 100);
  *(_WORD *)(a2 + 4) = *(_QWORD *)(a1 + 104);
  return 0;
}
