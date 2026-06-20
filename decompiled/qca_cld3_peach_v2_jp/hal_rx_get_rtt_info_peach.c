_DWORD *__fastcall hal_rx_get_rtt_info_peach(_DWORD *result, __int64 a2)
{
  unsigned __int16 v2; // w8
  unsigned __int16 v3; // w8
  int v4; // w9

  *(_BYTE *)(a2 + 14219) = *result & 1;
  *(_DWORD *)(a2 + 14224) = result[2];
  *(_BYTE *)(a2 + 14221) = result[3];
  *(_BYTE *)(a2 + 14220) = (result[1] >> 17) & 3;
  *(_DWORD *)(a2 + 14248) = result[5];
  *(_WORD *)(a2 + 14228) = result[4];
  v2 = result[8];
  *(_DWORD *)(a2 + 14232) = v2;
  *(_DWORD *)(a2 + 14232) = result[8] & 0xFFFF0000 | v2;
  v3 = result[9];
  *(_DWORD *)(a2 + 14236) = v3;
  v4 = result[9];
  *(_QWORD *)(a2 + 14240) = 0;
  *(_DWORD *)(a2 + 14236) = v4 & 0xFFFF0000 | v3;
  *(_DWORD *)(a2 + 14252) = HIBYTE(result[3]);
  *(_DWORD *)(a2 + 14256) = HIBYTE(result[4]);
  return result;
}
