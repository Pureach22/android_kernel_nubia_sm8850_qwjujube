__int64 __fastcall populate_dot11f_mscs_dec_element(__int64 result, __int64 a2)
{
  char v2; // w9

  *(_BYTE *)(a2 + 5) = *(_BYTE *)(result + 8);
  *(_WORD *)(a2 + 6) = *(_WORD *)(result + 10);
  *(_DWORD *)(a2 + 8) = *(_QWORD *)(result + 16);
  *(_BYTE *)(a2 + 13) = *(_BYTE *)(result + 24);
  v2 = *(_BYTE *)(result + 25);
  *(_BYTE *)(a2 + 4) = 1;
  *(_BYTE *)(a2 + 12) = 1;
  *(_BYTE *)(a2 + 14) = v2;
  return result;
}
