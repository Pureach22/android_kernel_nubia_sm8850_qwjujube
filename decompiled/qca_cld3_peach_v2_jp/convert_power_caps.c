void __fastcall convert_power_caps(__int64 a1, __int64 a2, __int64 a3)
{
  *(_WORD *)a2 = 545;
  *(_BYTE *)(a2 + 2) = *(_BYTE *)(a3 + 1);
  *(_BYTE *)(a2 + 3) = *(_BYTE *)(a3 + 2);
}
