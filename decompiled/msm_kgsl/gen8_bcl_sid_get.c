__int64 __fastcall gen8_bcl_sid_get(__int64 a1, int a2)
{
  unsigned __int64 v2; // x8

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x10) == 0 )
    return 0;
  v2 = *(unsigned int *)(a1 + 23992);
  if ( (v2 & 1) == 0 )
    return 0;
  if ( a2 == 2 )
    return (v2 >> 15) & 0x7F;
  if ( a2 == 1 )
    return (v2 >> 8) & 0x7F;
  if ( a2 )
    return 0;
  return (unsigned __int8)v2 >> 1;
}
