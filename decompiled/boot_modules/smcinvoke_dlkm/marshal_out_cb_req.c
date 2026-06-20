unsigned __int64 __fastcall marshal_out_cb_req(__int64 a1, __int64 a2)
{
  int v4; // w24
  __int64 v5; // x8
  unsigned __int64 *v6; // x9
  unsigned __int64 v7; // x10
  size_t v8; // x21
  __int64 v9; // x22
  unsigned __int64 v10; // x23
  unsigned __int64 result; // x0
  __int64 v12; // x1
  __int64 v13; // x8
  int i; // w20
  __int64 v15; // x23
  unsigned __int64 v16; // x0

  v4 = -1;
  do
    ++v4;
  while ( *(_DWORD *)(a1 + 24LL * v4) == 1 );
  while ( 1 )
  {
    v5 = a1 + 24LL * v4;
    if ( *(_DWORD *)v5 != 2 )
      break;
    v6 = (unsigned __int64 *)(a2 + 24LL * v4);
    v7 = v6[1];
    if ( v7 > *(_QWORD *)(v5 + 16) )
      return 0xFFFFFFFFLL;
    *(_QWORD *)(v5 + 16) = v7;
    v8 = v6[1];
    if ( v8 >> 31 )
    {
      __break(0x800u);
      return 0xFFFFFFFFLL;
    }
    v9 = *(_QWORD *)(v5 + 8);
    v10 = *v6;
    _check_object_size(v9, v6[1], 0);
    ++v4;
    if ( inline_copy_from_user(v9, v10, v8) )
      return 0xFFFFFFFFLL;
  }
  do
  {
    v12 = a1 + 24LL * v4;
    LODWORD(v13) = v4++;
  }
  while ( *(_DWORD *)v12 == 3 );
  if ( *(_DWORD *)v12 != 4 )
    return 0;
  v13 = (int)v13;
  result = 0;
  do
  {
    if ( (_DWORD)result )
      *(_QWORD *)(v12 + 8) = 0;
    else
      result = get_si_object_from_u_handle((__int64 *)(a2 + 24 * v13), v12);
    v12 = a1 + 24LL * v4;
    v13 = v4++;
  }
  while ( *(_DWORD *)v12 == 4 );
  if ( (_DWORD)result )
  {
    for ( i = 0; ; ++i )
    {
      v15 = a1 + 24LL * i;
      if ( *(_DWORD *)v15 == 4 )
        break;
      if ( !*(_DWORD *)v15 )
        return 0xFFFFFFFFLL;
LABEL_20:
      ;
    }
    v16 = *(_QWORD *)(v15 + 8);
    if ( v16 >= 2 && *(_DWORD *)(v16 + 12) == 2 && *(__int64 (__fastcall ***)())(v16 + 24) == &cbo_sio_ops )
    {
      *(_DWORD *)(v16 + 88) = 0;
      v16 = *(_QWORD *)(v15 + 8);
      if ( v16 < 2 )
        goto LABEL_27;
    }
    else if ( v16 < 2 )
    {
      goto LABEL_27;
    }
    if ( *(_DWORD *)(v16 + 12) == 1 )
    {
LABEL_28:
      put_si_object(v16);
      goto LABEL_20;
    }
LABEL_27:
    put_si_object(v16);
    v16 = *(_QWORD *)(v15 + 8);
    goto LABEL_28;
  }
  return result;
}
