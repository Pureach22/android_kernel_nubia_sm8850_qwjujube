unsigned int *__fastcall msm_property_reset_state(unsigned int *result, void *s, __int64 a3, __int64 a4)
{
  __int64 v6; // x19
  int v7; // w8
  __int64 v8; // x8
  unsigned __int64 v9; // x9
  _QWORD *v10; // x10
  __int64 v11; // x11

  if ( !result )
    return (unsigned int *)_drm_err("invalid property info\n", s);
  v6 = (__int64)result;
  if ( s )
    result = (unsigned int *)memset(s, 0, result[18]);
  if ( a3 )
  {
    v7 = *(_DWORD *)(v6 + 32);
    *(_QWORD *)(a3 + 8) = a4;
    *(_DWORD *)a3 = v7;
    *(_QWORD *)(a3 + 16) = a3 + 16;
    *(_QWORD *)(a3 + 24) = a3 + 16;
  }
  if ( a4 && *(_DWORD *)(v6 + 32) )
  {
    v8 = 0;
    v9 = 0;
    v10 = (_QWORD *)(a4 + 16);
    do
    {
      ++v9;
      v11 = *(_QWORD *)(*(_QWORD *)(v6 + 24) + v8);
      v8 += 16;
      *(v10 - 2) = v11;
      *(v10 - 1) = 0;
      *v10 = v10;
      v10[1] = v10;
      v10 += 4;
    }
    while ( v9 < *(unsigned int *)(v6 + 32) );
  }
  return result;
}
