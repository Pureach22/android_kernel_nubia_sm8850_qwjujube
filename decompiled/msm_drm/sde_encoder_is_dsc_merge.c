bool __fastcall sde_encoder_is_dsc_merge(_BOOL8 result)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x9
  __int64 v5; // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 328);
    if ( !v1 )
      return 0;
    v2 = *(_QWORD *)(v1 + 8);
    if ( !v2 )
      return 0;
    v3 = *(_QWORD *)(result + 200);
    if ( v3 )
    {
      v4 = *(_QWORD *)(v3 + 424);
      if ( v4 )
      {
        if ( (*(_BYTE *)(v4 + 77) & 1) != 0 )
          return 0;
      }
    }
    v5 = *(_QWORD *)(v2 + 2512);
    return v5 && *(_DWORD *)(v5 + 1376) == 9;
  }
  return result;
}
