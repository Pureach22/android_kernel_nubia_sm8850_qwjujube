__int64 __fastcall convert_to_dsi_mode(__int64 a1, __int64 a2)
{
  int v4; // w8
  int v5; // w8
  __int64 result; // x0

  *(_QWORD *)(a2 + 176) = 0;
  *(_QWORD *)(a2 + 184) = 0;
  *(_QWORD *)(a2 + 160) = 0;
  *(_QWORD *)(a2 + 168) = 0;
  *(_QWORD *)(a2 + 144) = 0;
  *(_QWORD *)(a2 + 152) = 0;
  *(_QWORD *)(a2 + 128) = 0;
  *(_QWORD *)(a2 + 136) = 0;
  *(_QWORD *)(a2 + 112) = 0;
  *(_QWORD *)(a2 + 120) = 0;
  *(_QWORD *)(a2 + 96) = 0;
  *(_QWORD *)(a2 + 104) = 0;
  *(_QWORD *)(a2 + 80) = 0;
  *(_QWORD *)(a2 + 88) = 0;
  *(_QWORD *)(a2 + 64) = 0;
  *(_QWORD *)(a2 + 72) = 0;
  *(_QWORD *)(a2 + 48) = 0;
  *(_QWORD *)(a2 + 56) = 0;
  *(_QWORD *)(a2 + 32) = 0;
  *(_QWORD *)(a2 + 40) = 0;
  *(_QWORD *)(a2 + 16) = 0;
  *(_QWORD *)(a2 + 24) = 0;
  *(_QWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_DWORD *)a2 = *(unsigned __int16 *)(a1 + 4);
  v4 = *(unsigned __int16 *)(a1 + 10) - *(unsigned __int16 *)(a1 + 8);
  *(_DWORD *)(a2 + 4) = v4;
  *(_DWORD *)(a2 + 8) = *(unsigned __int16 *)(a1 + 10) - *(unsigned __int16 *)(a1 + 6) - v4;
  *(_DWORD *)(a2 + 12) = *(unsigned __int16 *)(a1 + 6) - *(unsigned __int16 *)(a1 + 4);
  *(_DWORD *)(a2 + 16) = *(unsigned __int16 *)(a1 + 12);
  *(_DWORD *)(a2 + 24) = *(unsigned __int16 *)(a1 + 14);
  v5 = *(unsigned __int16 *)(a1 + 20) - *(unsigned __int16 *)(a1 + 18);
  *(_DWORD *)(a2 + 28) = v5;
  *(_DWORD *)(a2 + 32) = *(unsigned __int16 *)(a1 + 20) - *(unsigned __int16 *)(a1 + 16) - v5;
  *(_DWORD *)(a2 + 36) = *(unsigned __int16 *)(a1 + 16) - *(unsigned __int16 *)(a1 + 14);
  result = drm_mode_vrefresh(a1);
  *(_DWORD *)(a2 + 44) = result;
  *(_BYTE *)(a2 + 20) = *(_BYTE *)(a1 + 24) & 1;
  *(_BYTE *)(a2 + 40) = (*(_BYTE *)(a1 + 24) & 4) != 0;
  return result;
}
