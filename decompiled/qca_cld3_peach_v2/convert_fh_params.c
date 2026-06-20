void __fastcall convert_fh_params(__int64 a1, __int64 a2, __int64 a3)
{
  *(_WORD *)a2 = *(_WORD *)(a3 + 2);
  *(_BYTE *)(a2 + 2) = *(_BYTE *)(a3 + 4);
  *(_BYTE *)(a2 + 3) = *(_BYTE *)(a3 + 5);
  *(_BYTE *)(a2 + 4) = *(_BYTE *)(a3 + 6);
}
