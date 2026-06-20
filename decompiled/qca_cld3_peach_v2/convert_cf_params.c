void __fastcall convert_cf_params(__int64 a1, __int64 a2, __int64 a3)
{
  *(_BYTE *)a2 = *(_BYTE *)(a3 + 1);
  *(_BYTE *)(a2 + 1) = *(_BYTE *)(a3 + 2);
  *(_WORD *)(a2 + 2) = *(_WORD *)(a3 + 4);
  *(_WORD *)(a2 + 4) = *(_WORD *)(a3 + 6);
}
