__int64 __fastcall cam_cdm_get_ioremap_from_base(int a1, int a2, __int64 a3, _QWORD *a4)
{
  int v4; // w9
  __int64 v5; // x8
  __int64 v6; // x21
  int v7; // w24
  int v8; // w25
  __int64 v9; // x26
  _QWORD *v10; // x27

  if ( !a2 )
    return 4294967274LL;
  v4 = 0;
  while ( 1 )
  {
    v5 = *(_QWORD *)(a3 + 8LL * v4);
    v6 = v4;
    if ( v5 )
    {
      if ( (debug_mdl & 1) == 0 )
        goto LABEL_3;
      if ( debug_priority )
        goto LABEL_3;
      v7 = a1;
      v8 = a2;
      v9 = a3;
      v10 = a4;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_cdm_get_ioremap_from_base",
        482,
        "In loop %d ioremap for %x addr=%x",
        v4,
        *(_DWORD *)(v5 + 8),
        a1);
      v5 = *(_QWORD *)(v9 + 8 * v6);
      a1 = v7;
      a2 = v8;
      a3 = v9;
      a4 = v10;
      if ( v5 )
      {
LABEL_3:
        if ( *(_DWORD *)(v5 + 8) == a1 )
          break;
      }
    }
    v4 = v6 + 1;
    if ( a2 == (_DWORD)v6 + 1 )
      return 4294967274LL;
  }
  *a4 = *(_QWORD *)v5;
  return 0;
}
