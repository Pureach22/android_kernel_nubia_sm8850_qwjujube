__int64 __fastcall dp_soc_print_inactive_objects(__int64 result)
{
  _QWORD *v1; // x23
  __int64 v2; // x19
  _DWORD *v3; // x21
  __int64 i; // x22
  int v5; // w3
  _QWORD *v6; // x22
  _DWORD *v7; // x21
  __int64 j; // x20
  int v9; // w3

  v1 = *(_QWORD **)(result + 18864);
  v2 = result;
  while ( v1 )
  {
    v3 = v1;
    v1 = (_QWORD *)v1[30];
    for ( i = 0; i != 31; ++i )
    {
      v5 = v3[i + 64];
      if ( v5 )
        result = DP_PRINT_STATS("peer %pK Module id %u ==> %u", v3, i, v5);
    }
  }
  v6 = *(_QWORD **)(v2 + 18896);
  while ( v6 )
  {
    v7 = v6;
    v6 = (_QWORD *)v6[5316];
    for ( j = 0; j != 31; ++j )
    {
      v9 = v7[j + 10641];
      if ( v9 )
        result = DP_PRINT_STATS("vdev %pK Module id %u ==> %u", v7, j, v9);
    }
  }
  return result;
}
