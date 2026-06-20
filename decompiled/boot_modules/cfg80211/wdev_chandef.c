__int64 __fastcall wdev_chandef(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  int v4; // w9
  __int64 v5; // x8

  v3 = *(unsigned __int16 *)(a1 + 1472);
  if ( *(_WORD *)(a1 + 1472) && ((1LL << a2) & v3) == 0 )
  {
    __break(0x800u);
    LODWORD(v3) = *(unsigned __int16 *)(a1 + 1472);
    if ( !(_DWORD)a2 )
      goto LABEL_6;
  }
  else if ( !(_DWORD)a2 )
  {
    goto LABEL_6;
  }
  if ( !(_DWORD)v3 )
    __break(0x800u);
LABEL_6:
  v4 = *(_DWORD *)(a1 + 8);
  v5 = 0;
  if ( v4 <= 6 )
  {
    if ( v4 == 1 )
      return a1 + 288;
    if ( v4 != 3 )
      return v5;
  }
  else
  {
    if ( v4 == 11 )
      return a1 + 280;
    if ( v4 != 9 )
    {
      if ( v4 == 7 )
        return a1 + 320;
      return v5;
    }
  }
  if ( (unsigned int)a2 < 0xF )
    return a1 + 72LL * (unsigned int)a2 + 408;
  __break(0x5512u);
  return check_chandef_primary_compat(a1, a2, a3);
}
