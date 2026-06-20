__int64 __fastcall pmic_mpp_config_get(__int64 a1, unsigned int a2, _QWORD *a3)
{
  __int64 v3; // x8
  __int64 result; // x0
  __int64 v5; // x9
  unsigned int v6; // w8
  __int64 v7; // x9
  int v8; // w9
  __int64 v9; // x9

  v3 = *(_QWORD *)(a1 + 16);
  result = 4294967274LL;
  v5 = *(_QWORD *)(v3 + 8) + 24LL * a2;
  v6 = *(unsigned __int8 *)a3;
  v7 = *(_QWORD *)(v5 + 16);
  if ( v6 > 0x11 )
  {
    if ( *(unsigned __int8 *)a3 <= 0x80u )
    {
      switch ( v6 )
      {
        case 0x12u:
          v8 = *(unsigned __int8 *)(v7 + 3);
          goto LABEL_31;
        case 0x16u:
          v8 = *(_DWORD *)(v7 + 12);
          goto LABEL_31;
        case 0x80u:
          v8 = *(_DWORD *)(v7 + 16);
LABEL_31:
          *a3 = v6 | (v8 << 8);
          return 0;
      }
      return result;
    }
    if ( v6 == 129 )
    {
      v8 = *(_DWORD *)(v7 + 20);
      goto LABEL_31;
    }
    if ( v6 == 130 )
    {
      v8 = *(_DWORD *)(v7 + 36);
      goto LABEL_31;
    }
    if ( v6 != 131 || (*(_BYTE *)(v7 + 6) & 1) == 0 )
      return result;
    goto LABEL_23;
  }
  if ( *(unsigned __int8 *)a3 <= 4u )
  {
    if ( v6 == 1 )
    {
      if ( *(_DWORD *)(v7 + 24) != 3 )
        return result;
    }
    else if ( v6 != 2 || (*(_BYTE *)(v7 + 2) & 1) != 0 )
    {
      return result;
    }
    goto LABEL_23;
  }
  if ( v6 == 5 )
  {
    v9 = *(unsigned int *)(v7 + 24);
    if ( (unsigned int)v9 < 3 )
    {
      v8 = dword_8848[v9];
      goto LABEL_31;
    }
    return result;
  }
  if ( v6 == 9 )
  {
    v8 = *(_DWORD *)(v7 + 32);
    goto LABEL_31;
  }
  if ( v6 == 12 && (*(_BYTE *)(v7 + 5) & 1) != 0 )
  {
LABEL_23:
    v8 = 1;
    goto LABEL_31;
  }
  return result;
}
