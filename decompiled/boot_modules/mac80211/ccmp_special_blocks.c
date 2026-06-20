__int64 __fastcall ccmp_special_blocks(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x21
  __int64 result; // x0
  __int16 v7; // w9
  __int16 v8; // w9

  v4 = *(_QWORD *)(a1 + 224);
  result = ccmp_gcmp_aad();
  *(_BYTE *)a3 = 1;
  *(_BYTE *)(a3 + 1) = result | (16 * ((*(_WORD *)v4 & 0xC) == 0));
  v7 = *(_WORD *)(v4 + 14);
  *(_DWORD *)(a3 + 2) = *(_DWORD *)(v4 + 10);
  *(_WORD *)(a3 + 6) = v7;
  v8 = *(_WORD *)(a2 + 4);
  *(_DWORD *)(a3 + 8) = *(_DWORD *)a2;
  *(_WORD *)(a3 + 12) = v8;
  return result;
}
