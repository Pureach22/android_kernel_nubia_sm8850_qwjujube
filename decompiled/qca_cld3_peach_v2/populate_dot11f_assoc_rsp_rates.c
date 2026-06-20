void __fastcall populate_dot11f_assoc_rsp_rates(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned __int16 *a4, __int16 *a5)
{
  int v5; // w10
  _BYTE *v6; // x8
  unsigned __int16 v7; // w9
  unsigned __int16 v8; // w9
  unsigned __int16 v9; // w9
  char v10; // w11
  unsigned int v11; // w9
  __int16 v12; // w12
  __int64 v13; // x12
  __int16 v14; // w13
  __int16 v15; // w13
  __int16 v16; // w13
  __int16 v17; // w13
  _BYTE *v18; // x10
  __int16 v19; // w11
  _BYTE *v20; // x13
  unsigned __int8 v21; // w11
  _BYTE *v22; // x12
  __int16 v23; // w13
  __int64 v24; // x10
  __int64 v25; // x8

  v5 = *a4;
  v6 = a2 + 2;
  if ( !*a4 )
  {
    v11 = 0;
    goto LABEL_13;
  }
  *v6 = v5;
  v7 = a4[1];
  if ( !v7 )
  {
    v10 = 1;
    v11 = 1;
    v12 = *a5;
    if ( !*a5 )
      goto LABEL_9;
    goto LABEL_14;
  }
  a2[3] = v7;
  v8 = a4[2];
  if ( !v8 )
  {
    v11 = 2;
    goto LABEL_13;
  }
  a2[4] = v8;
  v9 = a4[3];
  if ( !v9 )
  {
    v11 = 3;
LABEL_13:
    v10 = 1;
    v12 = *a5;
    if ( !*a5 )
      goto LABEL_9;
    goto LABEL_14;
  }
  v10 = 0;
  a2[5] = v9;
  v11 = 4;
  v12 = *a5;
  if ( !*a5 )
  {
LABEL_9:
    a3 = a2;
    if ( !v5 )
      return;
LABEL_22:
    a3[1] = v11;
    *a3 = 1;
    return;
  }
LABEL_14:
  v6[v11] = v12;
  v13 = v11 + 1LL;
  v14 = a5[1];
  if ( !v14 )
    goto LABEL_21;
  v6[v13] = v14;
  v13 = v11 + 2LL;
  v15 = a5[2];
  if ( !v15
    || (v6[v13] = v15, v13 = v11 + 3LL, (v16 = a5[3]) == 0)
    || (v6[v13] = v16, v13 = v11 + 4LL, (v17 = a5[4]) == 0) )
  {
LABEL_21:
    a3 = a2;
    LOBYTE(v11) = v13;
    goto LABEL_22;
  }
  v18 = a3 + 2;
  if ( (v10 & 1) != 0 )
  {
    v6[v13] = v17;
    LODWORD(v13) = v11 + 5;
    v11 = 0;
    v19 = a5[5];
    if ( !v19 )
      goto LABEL_43;
  }
  else
  {
    *v18 = v17;
    v11 = 1;
    v19 = a5[5];
    if ( !v19 )
      goto LABEL_43;
  }
  v20 = &v6[(unsigned int)v13];
  if ( (unsigned int)v13 >= 8 )
    v20 = &v18[v11];
  *v20 = v19;
  if ( (unsigned int)v13 >= 8 )
    v21 = v13;
  else
    v21 = v13 + 1;
  if ( (unsigned int)v13 > 7 )
    LOBYTE(v11) = v11 + 1;
  if ( a5[6] )
  {
    v22 = &v6[v21];
    if ( v21 >= 8u )
      v22 = &v18[(unsigned __int8)v11];
    *v22 = a5[6];
    if ( v21 >= 8u )
      LOBYTE(v13) = v21;
    else
      LOBYTE(v13) = v21 + 1;
    v23 = a5[7];
    if ( v21 > 7u )
      LOBYTE(v11) = v11 + 1;
    if ( a5[7] )
    {
      if ( (unsigned __int8)v13 >= 8u )
      {
        v25 = (unsigned __int8)v11;
        LOBYTE(v11) = v11 + 1;
        v18[v25] = v23;
        a2[1] = v13;
        *a2 = 1;
        goto LABEL_22;
      }
      v24 = (unsigned __int8)v13;
      LOBYTE(v13) = v13 + 1;
      v6[v24] = v23;
    }
  }
  else
  {
    LOBYTE(v13) = v21;
  }
LABEL_43:
  a2[1] = v13;
  *a2 = 1;
  if ( (_BYTE)v11 )
    goto LABEL_22;
}
