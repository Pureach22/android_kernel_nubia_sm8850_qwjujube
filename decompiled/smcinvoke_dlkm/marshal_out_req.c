__int64 __fastcall marshal_out_req(__int64 a1, __int64 a2)
{
  int v4; // w22
  int v5; // w9
  __int64 i; // x8
  int v7; // w9
  __int64 result; // x0
  int v9; // w22
  __int64 v10; // x24
  _QWORD *v11; // x24
  __int64 v12; // t1

  v4 = -1;
  do
    v5 = *(_DWORD *)(a2 + 24LL * ++v4);
  while ( v5 == 1 );
  for ( i = v4; v5 == 2; v5 = *(_DWORD *)(a2 + 24LL * v4) )
  {
    ++v4;
    *(_QWORD *)(a1 + 24 * i + 8) = *(_QWORD *)(a2 + 24 * i + 16);
    i = v4;
  }
  if ( v5 == 3 )
  {
    do
    {
      put_si_object(*(_QWORD *)(a2 + 24 * i + 8));
      v7 = *(_DWORD *)(a2 + 24LL * ++v4);
      i = v4;
    }
    while ( v7 == 3 );
    if ( v7 == 4 )
      goto LABEL_8;
  }
  else if ( v5 == 4 )
  {
LABEL_8:
    LODWORD(result) = 0;
    v9 = v4 + 1;
    v10 = a2 + 24LL * (int)i;
    while ( 1 )
    {
      if ( (_DWORD)result )
      {
        v11 = (_QWORD *)(v10 + 8);
        *(_QWORD *)(a1 + 24 * i) = -1;
      }
      else
      {
        v12 = *(_QWORD *)(v10 + 8);
        v11 = (_QWORD *)(v10 + 8);
        result = get_u_handle_from_si_object(v12, a1 + 24 * i, 0);
        if ( !(_DWORD)result )
          goto LABEL_11;
      }
      put_si_object(*v11);
      result = 0xFFFFFFFFLL;
LABEL_11:
      v10 = a2 + 24LL * v9;
      i = v9++;
      if ( *(_DWORD *)v10 != 4 )
        return result;
    }
  }
  return 0;
}
