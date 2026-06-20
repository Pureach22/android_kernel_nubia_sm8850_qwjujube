__int64 __fastcall hal_rx_tid_get_be(__int64 a1, __int64 a2)
{
  if ( (*(_BYTE *)(a2 + 80) & 0x80) != 0 )
    return (*(_QWORD *)(a2 + 12) >> 51) & 0xFLL;
  else
    return 16;
}
