__int64 __fastcall adreno_getproperty(__int64 a1, _DWORD *a2)
{
  unsigned int v2; // w8
  _DWORD *v3; // x8

  v2 = *a2 - 1;
  if ( v2 > 0x2F || ((0xF73087D40063uLL >> v2) & 1) == 0 )
    return 4294967277LL;
  v3 = *((_DWORD **)*(&off_14F918 + v2) + 1);
  if ( *(v3 - 1) != -477936819 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _DWORD *))v3)(a1, a2);
}
