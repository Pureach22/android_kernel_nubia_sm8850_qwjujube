bool __fastcall valid_puncturing_bitmap(__int64 a1)
{
  int v1; // w8
  int v2; // w11
  __int64 v3; // x10
  int v4; // w8
  _BOOL8 result; // x0
  char *v6; // x9
  __int64 v7; // x10
  unsigned __int16 *v8; // x9
  __int64 v9; // x10
  int v10; // t1

  v1 = *(_DWORD *)(a1 + 8);
  if ( v1 == 3 )
  {
    v3 = 0;
    v2 = -40;
    v4 = *(unsigned __int16 *)(a1 + 30);
    if ( *(_WORD *)(a1 + 30) )
      goto LABEL_7;
    return 1;
  }
  if ( v1 == 13 )
  {
    v2 = -160;
    v3 = 2;
    v4 = *(unsigned __int16 *)(a1 + 30);
    if ( *(_WORD *)(a1 + 30) )
      goto LABEL_7;
    return 1;
  }
  if ( v1 != 5 )
    return *(_WORD *)(a1 + 30) == 0;
  v2 = -80;
  v3 = 1;
  v4 = *(unsigned __int16 *)(a1 + 30);
  if ( !*(_WORD *)(a1 + 30) )
    return 1;
LABEL_7:
  if ( ((unsigned int)(1LL << ((*(_DWORD *)(*(_QWORD *)a1 + 4LL) - (*(_DWORD *)(a1 + 12) + v2)) / 0x14u)) & v4) != 0 )
    return 0;
  v6 = &per_bw_puncturing[16 * v3];
  v7 = (unsigned __int8)*v6;
  if ( !*v6 )
    return 0;
  v8 = *((unsigned __int16 **)v6 + 1);
  v9 = v7 - 1;
  do
  {
    v10 = *v8++;
    result = v10 == v4;
    if ( v10 == v4 )
      break;
  }
  while ( v9-- );
  return result;
}
