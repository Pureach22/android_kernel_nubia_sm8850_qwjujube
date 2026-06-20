void __fastcall populate_mdie(__int64 a1, __int64 a2, __int64 a3)
{
  char v3; // w9
  char v4; // w9

  v3 = *(_BYTE *)(a2 + 4);
  *(_BYTE *)a2 = 1;
  *(_WORD *)(a2 + 2) = *(_WORD *)a3;
  v4 = v3 & 0xFE | *(_BYTE *)(a3 + 2) & 1;
  *(_BYTE *)(a2 + 4) = v4;
  *(_BYTE *)(a2 + 4) = v4 & 0xFD | *(_BYTE *)(a3 + 2) & 2;
}
