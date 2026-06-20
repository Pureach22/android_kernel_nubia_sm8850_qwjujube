__int64 __fastcall mlo_is_set_key_defered(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x8
  _BYTE *v3; // x8

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 1360);
    if ( !v2 )
      return v2 & 1;
    v2 = *(_QWORD *)(v2 + 2224);
    if ( !v2 )
      return v2 & 1;
    if ( *(unsigned __int8 *)(v2 + 17) == a2 )
    {
      v3 = (_BYTE *)(v2 + 16);
      return *v3 & 1;
    }
    if ( *(unsigned __int8 *)(v2 + 19) == a2 )
    {
      v3 = (_BYTE *)(v2 + 18);
      return *v3 & 1;
    }
    if ( *(unsigned __int8 *)(v2 + 21) == a2 )
    {
      v3 = (_BYTE *)(v2 + 20);
      return *v3 & 1;
    }
  }
  LOBYTE(v2) = 0;
  return v2 & 1;
}
