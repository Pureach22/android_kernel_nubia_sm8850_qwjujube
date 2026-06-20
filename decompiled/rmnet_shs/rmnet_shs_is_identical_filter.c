__int64 __fastcall rmnet_shs_is_identical_filter(__int64 a1, __int64 a2)
{
  int v2; // w8
  _BOOL4 v4; // w10
  bool v5; // zf
  _BOOL4 v6; // w11
  bool v7; // zf
  _BOOL4 v8; // w12
  _BOOL4 v9; // w13
  _BOOL4 v10; // w14
  _BOOL4 v11; // w8

  v2 = *(unsigned __int8 *)(a1 + 76);
  if ( *(_BYTE *)(a1 + 78) && *(unsigned __int8 *)(a1 + 78) == *(unsigned __int8 *)(a2 + 78) )
    return 1;
  v4 = (*(unsigned __int8 *)(a1 + 72) | *(unsigned __int8 *)(a2 + 72)) == 0;
  if ( *(_BYTE *)(a1 + 72) && *(_BYTE *)(a2 + 72) )
  {
    if ( v2 == 4 )
      v5 = (*(_DWORD *)(a1 + 96) & *(_DWORD *)(a1 + 48)) == (*(_DWORD *)(a2 + 96) & *(_DWORD *)(a2 + 48));
    else
      v5 = ((unsigned int)(*(_DWORD *)(a1 + 96) & *(_DWORD *)(a1 + 48))
          | ((unsigned __int64)(unsigned int)(*(_DWORD *)(a1 + 100) & *(_DWORD *)(a1 + 52)) << 32)) == ((unsigned int)(*(_DWORD *)(a2 + 96) & *(_DWORD *)(a2 + 48)) | ((unsigned __int64)(unsigned int)(*(_DWORD *)(a2 + 100) & *(_DWORD *)(a2 + 52)) << 32))
        && ((unsigned int)(*(_DWORD *)(a1 + 104) & *(_DWORD *)(a1 + 56))
          | ((unsigned __int64)(unsigned int)(*(_DWORD *)(a1 + 108) & *(_DWORD *)(a1 + 60)) << 32)) == ((unsigned int)(*(_DWORD *)(a2 + 104) & *(_DWORD *)(a2 + 56)) | ((unsigned __int64)(unsigned int)(*(_DWORD *)(a2 + 108) & *(_DWORD *)(a2 + 60)) << 32));
    v4 = v5;
  }
  v6 = (*(unsigned __int8 *)(a1 + 73) | *(unsigned __int8 *)(a2 + 73)) == 0;
  if ( *(_BYTE *)(a1 + 73) && *(_BYTE *)(a2 + 73) )
  {
    if ( v2 == 4 )
      v7 = (*(_DWORD *)(a1 + 80) & *(_DWORD *)(a1 + 32)) == (*(_DWORD *)(a2 + 80) & *(_DWORD *)(a2 + 32));
    else
      v7 = ((unsigned int)(*(_DWORD *)(a1 + 80) & *(_DWORD *)(a1 + 32))
          | ((unsigned __int64)(unsigned int)(*(_DWORD *)(a1 + 84) & *(_DWORD *)(a1 + 36)) << 32)) == ((unsigned int)(*(_DWORD *)(a2 + 80) & *(_DWORD *)(a2 + 32)) | ((unsigned __int64)(unsigned int)(*(_DWORD *)(a2 + 84) & *(_DWORD *)(a2 + 36)) << 32))
        && ((unsigned int)(*(_DWORD *)(a1 + 88) & *(_DWORD *)(a1 + 40))
          | ((unsigned __int64)(unsigned int)(*(_DWORD *)(a1 + 92) & *(_DWORD *)(a1 + 44)) << 32)) == ((unsigned int)(*(_DWORD *)(a2 + 88) & *(_DWORD *)(a2 + 40)) | ((unsigned __int64)(unsigned int)(*(_DWORD *)(a2 + 92) & *(_DWORD *)(a2 + 44)) << 32));
    v6 = v7;
  }
  v8 = (*(unsigned __int8 *)(a1 + 75) | *(unsigned __int8 *)(a2 + 75)) == 0;
  if ( *(_BYTE *)(a1 + 75) && *(_BYTE *)(a2 + 75) )
    v8 = *(unsigned __int8 *)(a1 + 74) == *(unsigned __int8 *)(a2 + 74);
  v9 = (*(unsigned __int16 *)(a1 + 66) | *(unsigned __int16 *)(a2 + 66)) == 0;
  if ( *(_WORD *)(a1 + 66) && *(_WORD *)(a2 + 66) )
    v9 = *(unsigned __int16 *)(a1 + 64) == *(unsigned __int16 *)(a2 + 64)
      && *(unsigned __int16 *)(a1 + 112) == *(unsigned __int16 *)(a2 + 112);
  v10 = (*(unsigned __int16 *)(a1 + 70) | *(unsigned __int16 *)(a2 + 70)) == 0;
  if ( *(_WORD *)(a1 + 70) && *(_WORD *)(a2 + 70) )
    v10 = *(unsigned __int16 *)(a1 + 68) == *(unsigned __int16 *)(a2 + 68)
       && *(unsigned __int16 *)(a1 + 114) == *(unsigned __int16 *)(a2 + 114);
  v11 = v2 == *(unsigned __int8 *)(a2 + 76) && v4;
  return (v11 && v6 && v8) & v9 & (unsigned int)v10;
}
