void *__fastcall wlan_hdd_copy_hdd_stats_to_sinfo(__int64 a1, __int64 a2)
{
  void *result; // x0

  *(_BYTE *)(a1 + 45) = *(_BYTE *)a2;
  *(_BYTE *)(a1 + 46) = *(_BYTE *)(a2 + 1);
  *(_BYTE *)(a1 + 52) = *(_BYTE *)(a2 + 3);
  *(_BYTE *)(a1 + 53) = *(_BYTE *)(a2 + 4);
  *(_BYTE *)(a1 + 54) = *(_BYTE *)(a2 + 5);
  *(_BYTE *)(a1 + 55) = *(_BYTE *)(a2 + 6);
  *(_BYTE *)(a1 + 47) = *(_BYTE *)(a2 + 2);
  if ( !*(_BYTE *)a2 )
  {
    *(_WORD *)(a1 + 45) = -32640;
    *(_DWORD *)(a1 + 52) = -2139062144;
  }
  qdf_mem_copy((void *)(a1 + 56), (const void *)(a2 + 8), 0xEu);
  result = qdf_mem_copy((void *)(a1 + 70), (const void *)(a2 + 22), 0xEu);
  *(_QWORD *)(a1 + 24) = *(_QWORD *)(a2 + 40);
  *(_QWORD *)(a1 + 32) = *(_QWORD *)(a2 + 48);
  *(_DWORD *)(a1 + 84) = *(_DWORD *)(a2 + 56);
  *(_DWORD *)(a1 + 88) = *(_DWORD *)(a2 + 60);
  *(_DWORD *)(a1 + 92) = *(_DWORD *)(a2 + 64);
  *(_DWORD *)(a1 + 96) = *(_DWORD *)(a2 + 68);
  *(_DWORD *)(a1 + 212) = *(_DWORD *)(a2 + 72);
  *(_DWORD *)(a1 + 216) = *(_DWORD *)(a2 + 76);
  *(_QWORD *)a1 = *(_QWORD *)(a2 + 80);
  return result;
}
