__int64 __fastcall hw_fence_utils_get_client_id_priv(__int64 a1, unsigned int a2)
{
  __int64 v2; // x9
  __int64 v3; // x8
  unsigned int v4; // w10
  __int64 result; // x0
  __int64 v6; // x10
  int v7; // w11
  int *v8; // x12
  __int64 v9; // x13
  int v10; // w14
  int v11; // t1
  __int64 v12; // x8
  int *v13; // x9
  int v14; // t1

  if ( !a2 )
    return 0;
  v2 = *(_QWORD *)(a1 + 48);
  v3 = (a2 - 1) >> 6;
  v4 = (a2 - 1) & 0x3F;
  if ( v4 >= *(_DWORD *)(v2 + 56LL * (unsigned int)v3 + 16) )
    return 1665;
  result = v4 + 1;
  if ( a2 < 0x41 )
    return result;
  if ( a2 < 0x81 )
  {
    v6 = 0;
LABEL_11:
    v12 = v3 - v6;
    v13 = (int *)(v2 + 56LL * (unsigned int)v6 + 16);
    do
    {
      v14 = *v13;
      v13 += 14;
      --v12;
      result = (unsigned int)(v14 + result);
    }
    while ( v12 );
    return result;
  }
  v6 = v3 & 0x3FFFFFE;
  v7 = 0;
  v8 = (int *)(v2 + 72);
  v9 = v6;
  do
  {
    v10 = *(v8 - 14);
    v11 = *v8;
    v8 += 28;
    v9 -= 2;
    LODWORD(result) = v10 + result;
    v7 += v11;
  }
  while ( v9 );
  result = (unsigned int)(v7 + result);
  if ( v6 != v3 )
    goto LABEL_11;
  return result;
}
