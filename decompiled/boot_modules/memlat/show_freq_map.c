__int64 __fastcall show_freq_map(__int64 a1, __int64 a2, __int64 a3)
{
  int *v4; // x21
  unsigned int v5; // w0
  int v6; // w3
  unsigned int v7; // w20
  __int64 v8; // x8
  _BOOL4 v9; // w9
  int *v10; // x23
  __int64 v11; // x22
  int v12; // w0

  v4 = *(int **)(a1 - 56);
  v5 = scnprintf(a3, 4096, "CPU freq (MHz)\tMem freq (kHz)\n");
  v6 = *v4;
  v7 = v5;
  v8 = v5;
  v9 = v5 < 0x1000;
  if ( !*v4 )
  {
    LODWORD(v11) = v5;
    if ( v5 >= 0x1000 )
      return (unsigned int)v11;
    goto LABEL_11;
  }
  if ( v5 <= 0xFFF )
  {
    v10 = v4 + 2;
    v11 = v5;
    while ( 1 )
    {
      v12 = scnprintf(a3 + v11, 4096 - v11, "%14u\t%14u\n", v6, *(v10 - 1));
      v11 = v12 + v7;
      v6 = *v10;
      v9 = (unsigned int)v11 < 0x1000;
      if ( !*v10 )
        break;
      v10 += 2;
      v7 += v12;
      v8 = v11;
      if ( (unsigned int)v11 >= 0x1000 )
        goto LABEL_10;
    }
    v8 = v12 + v7;
    if ( (unsigned int)v11 >= 0x1000 )
      return (unsigned int)v11;
LABEL_11:
    LODWORD(v11) = scnprintf(a3 + v8, 4096 - v8, "\n") + v11;
    return (unsigned int)v11;
  }
  LODWORD(v11) = v5;
LABEL_10:
  if ( v9 )
    goto LABEL_11;
  return (unsigned int)v11;
}
