__int64 __fastcall dot11f_get_packed_ie_eht_cap(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8

  if ( !*(_BYTE *)a2 )
    return 0;
  v3 = *a3 + 24;
  *a3 = v3;
  if ( (*(_QWORD *)(a2 + 1) & 0x8000000000000000LL) == 0 )
    return 0;
  *a3 = v3 + *(unsigned __int8 *)(a2 + 26);
  return 0;
}
