int *__fastcall _cam_isp_ctx_copy_fcg_ch_ctx(int *result, __int64 a2)
{
  int v2; // w8
  __int64 v3; // x9
  __int64 v4; // x10
  unsigned int v5; // w8
  __int64 v6; // x12
  _DWORD *v7; // x13
  _DWORD *v8; // x12
  unsigned int v9; // w12
  _QWORD *v10; // x13
  _QWORD *v11; // x14
  __int64 v12; // x15
  __int64 v13; // x16

  *(_DWORD *)(a2 + 8) = result[2];
  *(_DWORD *)(a2 + 4) = result[1];
  v2 = *result;
  *(_DWORD *)a2 = *result;
  if ( v2 )
  {
    v3 = *(_QWORD *)(a2 + 16);
    v4 = *((_QWORD *)result + 2);
    v5 = 0;
    do
    {
      v6 = 16LL * (int)v5;
      v7 = (_DWORD *)(v4 + v6);
      v8 = (_DWORD *)(v3 + v6);
      *v8 = *v7;
      v8[1] = v7[1];
      if ( *(_DWORD *)(a2 + 4) )
      {
        v9 = 0;
        do
        {
          v10 = (_QWORD *)(*(_QWORD *)(v3 + 8) + 24LL * (int)v9);
          v11 = (_QWORD *)(*(_QWORD *)(v4 + 8) + 24LL * (int)v9++);
          v13 = v10[1];
          v12 = v10[2];
          *v11 = *v10;
          v11[1] = v13;
          v11[2] = v12;
        }
        while ( v9 < *(_DWORD *)(a2 + 4) );
      }
      ++v5;
    }
    while ( v5 < *(_DWORD *)a2 );
  }
  return result;
}
