__int64 __fastcall gpumv_llc_slice_enable_store(__int64 a1, char a2)
{
  unsigned __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 20856);
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL )
    *(_BYTE *)(a1 + 20864) = a2 & 1;
  return 0;
}
