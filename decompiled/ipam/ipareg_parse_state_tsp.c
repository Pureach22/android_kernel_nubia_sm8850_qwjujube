void __fastcall ipareg_parse_state_tsp(__int64 a1, __int64 a2, char a3)
{
  *(_BYTE *)a2 = a3 & 1;
  *(_BYTE *)(a2 + 1) = (a3 & 2) != 0;
  *(_BYTE *)(a2 + 2) = (a3 & 4) != 0;
  *(_BYTE *)(a2 + 3) = (a3 & 8) != 0;
  *(_BYTE *)(a2 + 4) = (a3 & 0x10) != 0;
  *(_WORD *)(a2 + 5) = 0;
}
