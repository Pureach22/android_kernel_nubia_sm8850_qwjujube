__int64 __fastcall hdd_delete_peer(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  int v4; // w10
  __int64 i; // x9
  unsigned int v7; // w12
  __int64 v8; // x12
  bool v9; // cf
  char v10; // w10
  __int64 v11; // x12

  v3 = 0;
  v4 = 0;
  for ( i = a2 + 268; *(_DWORD *)i != *(_DWORD *)a3 || *(unsigned __int16 *)(i + 4) != *(unsigned __int16 *)(a3 + 4); i += 6 )
  {
    v3 += 4;
    ++v4;
    if ( v3 == 128 )
      return result;
  }
  v7 = *(_DWORD *)(a2 + 460 + v3) - 1;
  if ( v7 > 6 )
    v8 = 0;
  else
    v8 = qword_9FF3D8[v7];
  v9 = v4 != 0;
  v10 = v4 - 1;
  v11 = result + v8;
  if ( !v9 )
    v10 = 0;
  *(_BYTE *)(v11 + 52032) &= ~(unsigned __int8)(1LL << v10);
  *(_DWORD *)(a2 + 460 + v3) = 0;
  *(_WORD *)(i + 4) = 0;
  *(_DWORD *)i = 0;
  return result;
}
