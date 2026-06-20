__int64 __fastcall lpi_config_get(__int64 a1, unsigned int a2, _BYTE *a3)
{
  __int64 v3; // x8
  __int64 result; // x0
  __int64 v5; // x9
  __int64 v6; // x8
  __int64 v7; // x9
  bool v8; // zf
  __int64 v9; // x10

  v3 = *(_QWORD *)(a1 + 16);
  result = 4294967274LL;
  v5 = *(_QWORD *)(v3 + 8) + 24LL * a2;
  v6 = (unsigned __int8)*a3;
  v7 = *(_QWORD *)(v5 + 16);
  if ( (unsigned __int8)*a3 <= 4u )
  {
    if ( *a3 )
    {
      if ( (_DWORD)v6 != 1 )
      {
        if ( (_DWORD)v6 != 3 )
          return result;
        v8 = *(_DWORD *)(v7 + 48) == 1;
        goto LABEL_12;
      }
      v9 = 0;
      *(_DWORD *)(v7 + 48) = 0;
    }
    else
    {
      v9 = 2;
      *(_DWORD *)(v7 + 48) = 2;
    }
LABEL_16:
    *(_QWORD *)a3 = v6 | (v9 << 8);
    return 0;
  }
  if ( (_DWORD)v6 == 5 )
  {
    v8 = *(_DWORD *)(v7 + 48) == 3;
LABEL_12:
    v9 = v8;
    goto LABEL_16;
  }
  if ( (_DWORD)v6 == 12 || (_DWORD)v6 == 18 )
  {
    v9 = *(unsigned __int8 *)(v7 + 12);
    goto LABEL_16;
  }
  return result;
}
