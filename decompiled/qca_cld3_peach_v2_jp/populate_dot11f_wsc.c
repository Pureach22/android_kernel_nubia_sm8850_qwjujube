__int64 __fastcall populate_dot11f_wsc(__int64 a1, __int64 a2)
{
  *(_WORD *)(a2 + 1) = 4097;
  LOBYTE(a1) = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5585LL);
  *(_BYTE *)(a2 + 5) = 0;
  *(_BYTE *)(a2 + 7) = 0;
  *(_BYTE *)(a2 + 4) = a1;
  *(_BYTE *)(a2 + 3) = 1;
  *(_BYTE *)(a2 + 10) = 0;
  *(_BYTE *)(a2 + 14) = 0;
  *(_BYTE *)(a2 + 18) = 0;
  *(_BYTE *)(a2 + 35) = 0;
  *(_BYTE *)a2 = 1;
  return 0;
}
