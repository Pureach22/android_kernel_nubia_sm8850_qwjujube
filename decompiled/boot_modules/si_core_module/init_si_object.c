__int64 __fastcall init_si_object(
        unsigned int **a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  int v8; // w8
  __int64 result; // x0
  unsigned int *si_object; // x8
  unsigned int v12; // w20
  __int64 v13; // x0
  __int64 v14; // x21
  __int64 v15; // x9

  if ( (int)a2 >= 0 )
    v8 = 1;
  else
    v8 = 2;
  if ( !(_DWORD)a2 )
    v8 = 16;
  if ( v8 == 1 )
  {
    v12 = a2;
    v13 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
    if ( v13 )
    {
      *(_QWORD *)(v13 + 16) = 0;
      *(_DWORD *)(v13 + 12) = 16;
      *(_QWORD *)(v13 + 80) = 0;
      v14 = v13;
      *(_DWORD *)(v13 + 8) = 1;
      v15 = kasprintf(3264, "qtee-%u", v12);
      si_object = (unsigned int *)v14;
      result = 0;
      *(_DWORD *)(v14 + 12) = 1;
      *(_QWORD *)v14 = v15;
      *(_QWORD *)(v14 + 16) = v12;
      *(_QWORD *)(v14 + 80) = 0;
    }
    else
    {
      si_object = nullptr;
      result = 4294967284LL;
    }
  }
  else
  {
    result = 0;
    if ( v8 == 16 )
    {
      si_object = nullptr;
    }
    else
    {
      si_object = qtee_get_si_object((unsigned int)a2, a2, a3, a4, a5, a6, a7, a8);
      if ( si_object )
        result = 0;
      else
        result = 4294967274LL;
    }
  }
  *a1 = si_object;
  return result;
}
