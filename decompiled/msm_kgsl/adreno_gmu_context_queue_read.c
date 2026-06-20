__int64 __fastcall adreno_gmu_context_queue_read(__int64 a1, _DWORD *s, unsigned int a3, unsigned int a4)
{
  __int64 v4; // x22
  unsigned int v5; // w8
  bool v6; // cf
  bool v7; // zf
  unsigned int v9; // w19
  _DWORD *v10; // x20
  __int64 v12; // x9

  v4 = *(_QWORD *)(a1 + 1648);
  v5 = *(_DWORD *)(v4 + 8);
  if ( v5 >= a4 )
  {
    v6 = v5 >= a3;
    v7 = v5 == a3;
  }
  else
  {
    v6 = 0;
    v7 = 0;
  }
  if ( v7 || !v6 )
    return 4294967274LL;
  v9 = a3;
  v10 = s;
  memset(s, 0, 4 * a4);
  if ( a4 )
  {
    v12 = a4;
    do
    {
      --v12;
      *v10++ = *(_DWORD *)(v4 + 48 + 4LL * v9);
      v9 = (v9 + 1) % *(_DWORD *)(v4 + 8);
    }
    while ( v12 );
  }
  return 0;
}
