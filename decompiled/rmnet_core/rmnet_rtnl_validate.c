__int64 __fastcall rmnet_rtnl_validate(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 v4; // x8
  __int64 v5; // x8

  if ( !a2 )
    return 4294967274LL;
  v2 = a2[1];
  if ( v2 && *(unsigned __int16 *)(v2 + 4) > 0xFEu )
    return 4294967262LL;
  v4 = a2[4];
  if ( v4 )
  {
    if ( *(_DWORD *)(v4 + 8) < 0xF4240u )
      return 4294967274LL;
    v5 = a2[5];
    if ( v5 && *(unsigned __int8 *)(v5 + 4) > 1u )
      return 4294967262LL;
  }
  return 0;
}
