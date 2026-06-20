__int64 __fastcall hal_reo_queue_stats_status_be(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v5)(__int64, __int64, __int64); // x8
  __int64 result; // x0

  v5 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a3 + 74392) + 432LL);
  if ( *((_DWORD *)v5 - 1) != -386617991 )
    __break(0x8228u);
  result = v5(a1, 285, a2);
  *(_WORD *)(a2 + 12) = *(_WORD *)(a1 + 16) & 0xFFF;
  *(_BYTE *)(a2 + 14) = *(_DWORD *)(a1 + 16) >> 12;
  *(_DWORD *)(a2 + 16) = *(_DWORD *)(a1 + 20);
  *(_DWORD *)(a2 + 20) = *(_DWORD *)(a1 + 24);
  *(_DWORD *)(a2 + 24) = *(_DWORD *)(a1 + 28);
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(a1 + 32);
  *(_DWORD *)(a2 + 32) = *(_DWORD *)(a1 + 36);
  *(_DWORD *)(a2 + 36) = *(_DWORD *)(a1 + 40);
  *(_DWORD *)(a2 + 40) = *(_DWORD *)(a1 + 44);
  *(_DWORD *)(a2 + 44) = *(_DWORD *)(a1 + 48);
  *(_DWORD *)(a2 + 48) = *(_DWORD *)(a1 + 52);
  *(_DWORD *)(a2 + 52) = *(_DWORD *)(a1 + 56);
  *(_DWORD *)(a2 + 56) = *(_DWORD *)(a1 + 60);
  *(_DWORD *)(a2 + 60) = *(_DWORD *)(a1 + 64);
  *(_DWORD *)(a2 + 64) = *(_DWORD *)(a1 + 68);
  *(_DWORD *)(a2 + 68) = *(_DWORD *)(a1 + 72);
  *(_BYTE *)(a2 + 72) = *(_BYTE *)(a1 + 80) & 0x7F;
  *(_BYTE *)(a2 + 73) = *(_DWORD *)(a1 + 80) >> 7;
  *(_BYTE *)(a2 + 74) = (*(_DWORD *)(a1 + 84) >> 4) & 0x3F;
  *(_BYTE *)(a2 + 75) = (unsigned __int16)*(_DWORD *)(a1 + 84) >> 10;
  *(_WORD *)(a2 + 76) = *(_WORD *)(a1 + 86);
  *(_DWORD *)(a2 + 80) = *(_DWORD *)(a1 + 88) & 0xFFFFFF;
  *(_BYTE *)(a2 + 84) = *(_BYTE *)(a1 + 91);
  *(_DWORD *)(a2 + 88) = *(_DWORD *)(a1 + 92);
  *(_DWORD *)(a2 + 92) = *(_DWORD *)(a1 + 96);
  *(_DWORD *)(a2 + 96) = *(_DWORD *)(a1 + 100);
  *(_WORD *)(a2 + 100) = *(_WORD *)(a1 + 104) & 0xFFF;
  *(_BYTE *)(a2 + 102) = *(_BYTE *)(a1 + 84) & 0xF;
  *(_WORD *)(a2 + 104) = *(_DWORD *)(a1 + 104) >> 12;
  return result;
}
