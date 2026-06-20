__int64 __fastcall etm_addr_filters_validate(__int64 *a1)
{
  _QWORD *v1; // x10
  __int64 v2; // x9
  bool v3; // w8
  __int64 ******v5; // x10
  _BOOL4 v6; // w9
  __int64 *****v7; // x10
  __int64 ****v8; // x10
  __int64 ***v9; // x10
  __int64 **v10; // x10
  __int64 *v11; // x10
  __int64 v12; // x10
  unsigned int v13; // w8

  v1 = (_QWORD *)*a1;
  if ( (__int64 *)*a1 == a1 )
    return 0;
  v2 = v1[5];
  v3 = v2 == 0;
  if ( v2 && *((_DWORD *)v1 + 12) < 2u )
    return 4294967201LL;
  v5 = (__int64 ******)*v1;
  if ( v5 == (__int64 ******)a1 )
    return 0;
  v6 = v2 != 0;
  if ( v5[5] )
  {
    if ( *((_DWORD *)v5 + 12) < 2u )
      return 4294967201LL;
    v6 = 1;
LABEL_12:
    if ( v3 )
      return 4294967201LL;
    goto LABEL_14;
  }
  v3 = 1;
  if ( v6 )
    goto LABEL_12;
LABEL_14:
  v7 = *v5;
  if ( v7 == (__int64 *****)a1 )
    return 0;
  if ( v7[5] )
  {
    if ( *((_DWORD *)v7 + 12) < 2u )
      return 4294967201LL;
    v6 = 1;
  }
  else
  {
    v3 = 1;
  }
  if ( v6 && v3 )
    return 4294967201LL;
  v8 = *v7;
  if ( v8 == (__int64 ****)a1 )
    return 0;
  if ( v8[5] )
  {
    if ( *((_DWORD *)v8 + 12) < 2u )
      return 4294967201LL;
    v6 = 1;
  }
  else
  {
    v3 = 1;
  }
  if ( v6 && v3 )
    return 4294967201LL;
  v9 = *v8;
  if ( v9 == (__int64 ***)a1 )
    return 0;
  if ( v9[5] )
  {
    if ( *((_DWORD *)v9 + 12) < 2u )
      return 4294967201LL;
    v6 = 1;
  }
  else
  {
    v3 = 1;
  }
  if ( v6 && v3 )
    return 4294967201LL;
  v10 = *v9;
  if ( v10 == (__int64 **)a1 )
    return 0;
  if ( v10[5] )
  {
    if ( *((_DWORD *)v10 + 12) < 2u )
      return 4294967201LL;
    v6 = 1;
  }
  else
  {
    v3 = 1;
  }
  if ( v6 && v3 )
    return 4294967201LL;
  v11 = *v10;
  if ( v11 == a1 )
    return 0;
  if ( v11[5] )
  {
    if ( *((_DWORD *)v11 + 12) < 2u )
      return 4294967201LL;
    v6 = 1;
  }
  else
  {
    v3 = 1;
  }
  if ( v6 && v3 )
    return 4294967201LL;
  v12 = *v11;
  if ( (__int64 *)v12 == a1 )
    return 0;
  if ( *(_QWORD *)(v12 + 40) )
  {
    LOBYTE(v6) = v3;
    if ( *(_DWORD *)(v12 + 48) < 2u )
      return 4294967201LL;
  }
  v13 = -95;
  if ( v6 )
    return v13;
  if ( *(__int64 **)v12 == a1 )
    return 0;
  else
    return 4294967201LL;
}
