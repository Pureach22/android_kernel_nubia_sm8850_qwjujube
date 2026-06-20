__int64 __fastcall dot11f_unpack_ie_wpa(_QWORD a1, char *a2, unsigned __int8 a3, _WORD *a4)
{
  __int64 result; // x0
  unsigned int v8; // w8
  unsigned __int8 v9; // w21
  size_t v10; // x2
  char *v11; // x20
  __int64 v12; // x8
  unsigned __int8 v13; // w21
  char *v14; // x20
  unsigned int v15; // w8
  unsigned __int8 v16; // w21
  size_t v17; // x2
  char *v18; // x20
  __int64 v19; // x8

  if ( *(_BYTE *)a4 )
    return 32;
  *(_BYTE *)a4 = 1;
  if ( a3 <= 1u )
    goto LABEL_26;
  qdf_mem_copy(a4 + 1, a2, 2u);
  if ( a4[1] != 1 )
  {
    *(_BYTE *)a4 = 0;
    return 64;
  }
  if ( a3 == 2 )
  {
    result = 0;
    *((_BYTE *)a4 + 4) = 0;
    goto LABEL_11;
  }
  *((_BYTE *)a4 + 4) = 1;
  if ( (unsigned __int8)(a3 - 2) <= 3u )
    goto LABEL_26;
  qdf_mem_copy((char *)a4 + 5, a2 + 2, 4u);
  if ( a3 == 6 )
  {
    result = 0;
LABEL_11:
    a4[5] = 0;
    a4[14] = 0;
    return result;
  }
  if ( a3 == 7 )
    goto LABEL_26;
  qdf_mem_copy(a4 + 5, a2 + 6, 2u);
  v8 = (unsigned __int16)a4[5];
  v9 = a3 - 8;
  v10 = 4 * v8;
  if ( (unsigned int)v10 > v9 )
    goto LABEL_26;
  if ( v8 >= 5 )
  {
LABEL_15:
    *(_BYTE *)a4 = 0;
    return 8;
  }
  v11 = a2 + 8;
  qdf_mem_copy(a4 + 6, v11, v10);
  v12 = 4LL * (unsigned __int16)a4[5];
  if ( (unsigned __int8)(4 * a4[5]) == v9 )
  {
    a4[14] = 0;
    return 0;
  }
  v13 = v9 - v12;
  if ( v13 <= 1u )
    goto LABEL_26;
  v14 = &v11[v12];
  qdf_mem_copy(a4 + 14, v14, 2u);
  v15 = (unsigned __int16)a4[14];
  v16 = v13 - 2;
  v17 = 4 * v15;
  if ( (unsigned int)v17 > v16 )
    goto LABEL_26;
  if ( v15 >= 5 )
    goto LABEL_15;
  v18 = v14 + 2;
  qdf_mem_copy(a4 + 15, v18, v17);
  v19 = 4LL * (unsigned __int16)a4[14];
  if ( (unsigned __int8)(4 * a4[14]) == v16 )
    return 0;
  if ( (unsigned __int8)(v16 - v19) <= 1u )
  {
LABEL_26:
    *(_BYTE *)a4 = 0;
    return 4;
  }
  qdf_mem_copy(a4 + 23, &v18[v19], 2u);
  return 0;
}
