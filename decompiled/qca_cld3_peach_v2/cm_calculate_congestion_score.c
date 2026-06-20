__int64 __fastcall cm_calculate_congestion_score(__int64 a1, __int64 a2, _DWORD *a3, char a4)
{
  int v4; // w8
  int v5; // w9
  __int64 v6; // x9
  unsigned int v7; // w9
  unsigned int v8; // w10
  unsigned int v10; // w9
  char v11; // w10
  unsigned int v12; // w9

  v4 = *(unsigned __int8 *)(a2 + 9);
  if ( !a1 )
    return (unsigned int)*(unsigned __int8 *)(a2 + 44) * v4;
  v5 = *(unsigned __int8 *)(a1 + 82);
  if ( *(_BYTE *)(a1 + 82) )
  {
    if ( ((100 * (_WORD)v5 - 25500) & 0xFFFCu) < 0xFF )
      LODWORD(v6) = 1;
    else
      LODWORD(v6) = 100 - ((unsigned int)(3289700 * v5) >> 23);
  }
  else
  {
    v6 = *(_QWORD *)(a1 + 1504);
    if ( v6 )
    {
      LODWORD(v6) = (3289700 * (unsigned int)*(unsigned __int8 *)(a1 + 83)) >> 23;
      if ( (unsigned int)v6 <= 1 )
        LODWORD(v6) = 1;
    }
  }
  *a3 = v6;
  v7 = *(unsigned __int8 *)(a2 + 40);
  if ( !*(_BYTE *)(a2 + 40) )
    return 0;
  if ( v7 >= 0x10 )
  {
    v7 = 15;
    *(_BYTE *)(a2 + 40) = 15;
  }
  if ( (a4 & 1) == 0 && *(char *)(a1 + 60) > -*(unsigned __int8 *)(a2 + 29) )
  {
    if ( *a3 )
    {
      if ( (unsigned __int8)(*a3 / (0x64 / v7) + 1) < v7 )
        v7 = (unsigned __int8)(*a3 / (0x64 / v7) + 1);
      if ( v7 > 3 )
        goto LABEL_18;
LABEL_22:
      v8 = *(_DWORD *)(a2 + 44);
      goto LABEL_23;
    }
    return (unsigned int)*(unsigned __int8 *)(a2 + 44) * v4;
  }
  if ( v7 <= 3 )
    goto LABEL_22;
LABEL_18:
  if ( v7 > 7 )
  {
    v11 = 8 * v7;
    if ( v7 > 0xB )
      v12 = *(_DWORD *)(a2 + 56);
    else
      v12 = *(_DWORD *)(a2 + 52);
    v10 = v12 >> v11;
    return (unsigned int)(unsigned __int8)v10 * v4;
  }
  v8 = *(_DWORD *)(a2 + 48);
LABEL_23:
  v10 = v8 >> (8 * v7);
  return (unsigned int)(unsigned __int8)v10 * v4;
}
