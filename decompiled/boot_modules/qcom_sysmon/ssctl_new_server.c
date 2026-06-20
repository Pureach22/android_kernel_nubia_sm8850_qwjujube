__int64 __fastcall ssctl_new_server(__int64 a1, __int64 a2)
{
  int v2; // w19
  __int64 v3; // x20
  __int64 v4; // x21
  int v5; // w0
  int v6; // w8

  v2 = *(_DWORD *)(a2 + 4);
  if ( v2 == 2 )
  {
    if ( *(_DWORD *)(a2 + 8) != *(_DWORD *)(a1 - 288) )
      return 4294967274LL;
  }
  else
  {
    if ( v2 != 1 )
      return 4294967274LL;
    if ( *(_DWORD *)(a2 + 8) )
      return 4294967274LL;
    v3 = a1;
    v4 = a2;
    v5 = strcmp(*(const char **)(a1 - 304), "modem");
    a2 = v4;
    v6 = v5;
    a1 = v3;
    if ( v6 )
      return 4294967274LL;
  }
  *(_DWORD *)(a1 - 292) = v2;
  *(_WORD *)(a1 + 304) = 42;
  *(_DWORD *)(a1 + 308) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(a1 + 312) = *(_DWORD *)(a2 + 16);
  *(_QWORD *)(a2 + 24) = a1 - 432;
  complete(a1 - 88);
  return 0;
}
