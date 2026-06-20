__int64 __fastcall marshal_in_req(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned __int16 v3; // w20
  _QWORD *v5; // x9
  __int64 *v6; // x10
  __int64 v7; // x12
  __int64 v8; // t1
  unsigned __int64 v9; // x23
  unsigned __int64 v10; // x8
  __int64 v11; // x10
  __int64 *v12; // x9
  _QWORD *v13; // x10
  __int64 v14; // t1
  int v15; // w8
  unsigned __int64 v16; // x24
  int si_object_from_u_handle; // w0
  __int64 v18; // x21
  __int64 v19; // x22
  bool v20; // w8
  int v21; // w9
  unsigned __int64 v22; // x9
  unsigned __int64 v23; // x10
  unsigned __int64 v24; // x10
  _DWORD *v25; // x12
  unsigned __int64 v26; // x14
  _DWORD *v27; // x10
  __int64 result; // x0
  int i; // w21
  int *v30; // x8
  int v31; // w23
  unsigned __int64 v32; // x0
  int v33; // w9
  __int64 v34; // x8
  unsigned __int64 v35; // x0

  v3 = a3;
  if ( (a3 & 0xF) != 0 )
  {
    v5 = (_QWORD *)(a1 + 8);
    v6 = (__int64 *)(a2 + 8);
    v7 = a3 & 0xF;
    do
    {
      *((_DWORD *)v5 - 2) = 1;
      --v7;
      *((_BYTE *)v5 - 4) = 1;
      *v5 = *(v6 - 1);
      v8 = *v6;
      v6 += 3;
      v5[1] = v8;
      v5 += 3;
    }
    while ( v7 );
  }
  v9 = ((unsigned __int8)a3 >> 4) + (a3 & 0xF);
  if ( (unsigned __int8)a3 >> 4 )
  {
    v10 = a3 & 0xF;
    v11 = 24 * v10 + 8;
    v12 = (__int64 *)(a2 + v11);
    v13 = (_QWORD *)(a1 + v11);
    do
    {
      *((_DWORD *)v13 - 2) = 2;
      ++v10;
      *((_BYTE *)v13 - 4) = 1;
      *v13 = *(v12 - 1);
      v14 = *v12;
      v12 += 3;
      v13[1] = v14;
      v13 += 3;
    }
    while ( v10 < v9 );
  }
  v15 = (a3 >> 8) & 0xF;
  v16 = (unsigned int)(v9 + v15);
  if ( v15 )
  {
    si_object_from_u_handle = 0;
    v18 = a1 + 24 * v9;
    v19 = a2 + 24 * v9;
    do
    {
      *(_DWORD *)v18 = 3;
      if ( si_object_from_u_handle )
        *(_QWORD *)(v18 + 8) = 0;
      else
        si_object_from_u_handle = get_si_object_from_u_handle(v19, v18);
      ++v9;
      v18 += 24;
      v19 += 24;
    }
    while ( v9 < v16 );
    v20 = si_object_from_u_handle == 0;
    v21 = v3 >> 12;
    if ( !(v3 >> 12) )
      goto LABEL_25;
LABEL_16:
    v22 = (unsigned int)(v16 + v21);
    if ( v16 + 1 > v22 )
      v23 = v16 + 1;
    else
      v23 = v22;
    v24 = v23 - v16;
    if ( v24 < 2 )
      goto LABEL_23;
    v25 = (_DWORD *)(a1 + 24LL * (unsigned int)v16);
    v16 += v24 & 0xFFFFFFFFFFFFFFFELL;
    v26 = v24 & 0xFFFFFFFFFFFFFFFELL;
    do
    {
      *v25 = 4;
      v26 -= 2LL;
      v25[6] = 4;
      v25 += 12;
    }
    while ( v26 );
    if ( v24 != (v24 & 0xFFFFFFFFFFFFFFFELL) )
    {
LABEL_23:
      v27 = (_DWORD *)(a1 + 24LL * (int)v16);
      do
      {
        ++v16;
        *v27 = 4;
        v27 += 6;
      }
      while ( v16 < v22 );
    }
    goto LABEL_25;
  }
  v20 = 1;
  v21 = (unsigned __int16)a3 >> 12;
  if ( (unsigned __int16)a3 >> 12 )
    goto LABEL_16;
LABEL_25:
  result = 0;
  *(_DWORD *)(a1 + 24 * v16) = 0;
  if ( v20 )
    return result;
  for ( i = 0; ; ++i )
  {
    v30 = (int *)(a1 + 24LL * i);
    v31 = *v30;
    if ( *v30 != 3 )
      break;
    v32 = *((_QWORD *)v30 + 1);
    if ( v32 >= 2 )
    {
      v33 = *(_DWORD *)(v32 + 12);
      if ( v33 == 1 )
      {
        *((_QWORD *)v30 + 1) = 0;
      }
      else if ( v33 == 2 && *(__int64 (__fastcall ***)())(v32 + 24) == &cbo_sio_ops )
      {
        *(_DWORD *)(v32 + 88) = 0;
      }
    }
    put_si_object();
LABEL_29:
    ;
  }
  if ( v31 )
    goto LABEL_29;
  while ( 1 )
  {
    v34 = a1 + 24LL * v31;
    if ( *(_DWORD *)v34 != 3 )
      break;
    v35 = *(_QWORD *)(v34 + 8);
    if ( v35 < 2 || *(_DWORD *)(v35 + 12) != 1 )
      put_si_object();
LABEL_39:
    ++v31;
  }
  if ( *(_DWORD *)v34 )
    goto LABEL_39;
  return 0xFFFFFFFFLL;
}
