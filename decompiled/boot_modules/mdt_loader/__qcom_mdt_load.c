__int64 __fastcall _qcom_mdt_load(
        __int64 a1,
        unsigned __int64 *a2,
        char *a3,
        __int64 a4,
        unsigned __int64 a5,
        unsigned __int64 a6,
        unsigned __int64 *a7)
{
  __int64 result; // x0
  unsigned __int64 v10; // x20
  unsigned __int64 v12; // x28
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x9
  unsigned int *v16; // x10
  bool v17; // w21
  unsigned int v18; // w11
  unsigned __int64 v19; // x12
  int v20; // w9
  _DWORD *v21; // x11
  unsigned __int64 v22; // x10
  __int64 v23; // x13
  unsigned __int64 v24; // x26
  _DWORD *v25; // x22
  __int64 v26; // x9
  __int64 v27; // x8
  size_t v28; // x2
  char *v29; // x27
  unsigned int v30; // w8
  unsigned int v31; // w9
  unsigned __int64 *v32; // [xsp+8h] [xbp-18h]
  __int64 v34; // [xsp+18h] [xbp-8h]

  result = 4294967274LL;
  if ( !a2 )
    return result;
  if ( !a4 )
    return result;
  v10 = a5;
  if ( !a5 || !a6 )
    return result;
  v12 = a2[1];
  v14 = *(unsigned __int16 *)(v12 + 44);
  if ( !*(_WORD *)(v12 + 44) )
    goto LABEL_38;
  v15 = 0;
  v16 = (unsigned int *)(v12 + 56);
  v17 = 1;
  do
  {
    v18 = v16[3];
    if ( v18 )
    {
      v19 = *v16;
      if ( *a2 < v19 || *a2 < (unsigned int)v19 + v18 )
        break;
    }
    ++v15;
    v16 += 8;
    v17 = v15 < v14;
  }
  while ( v14 != v15 );
  if ( !*(_WORD *)(v12 + 44) )
  {
LABEL_38:
    result = 0;
    if ( !a7 )
      return result;
    goto LABEL_39;
  }
  v20 = 0;
  v21 = (_DWORD *)(v12 + 76);
  v22 = -1;
  v23 = *(unsigned __int16 *)(v12 + 44);
  do
  {
    if ( *(v21 - 6) == 1 && (*v21 & 0x7000000) != 0x2000000 )
    {
      if ( *(v21 - 1) )
      {
        v20 |= (*v21 & 0x8000000u) >> 27;
        if ( v22 >= (unsigned int)*(v21 - 3) )
          v22 = (unsigned int)*(v21 - 3);
      }
    }
    --v23;
    v21 += 8;
  }
  while ( v23 );
  if ( (v20 & 1) != 0 )
    v10 = v22;
  v24 = 0;
  v25 = (_DWORD *)(v12 + 76);
  v34 = a1;
  v32 = a7;
  while ( 1 )
  {
    if ( *(v25 - 6) != 1 )
      goto LABEL_23;
    if ( (*v25 & 0x7000000) == 0x2000000 )
      goto LABEL_23;
    v26 = (unsigned int)*(v25 - 1);
    if ( !(_DWORD)v26 )
      goto LABEL_23;
    v27 = (unsigned int)*(v25 - 3) - v10;
    if ( v27 < 0 || v27 + v26 > a6 )
    {
      dev_err(v34, "segment outside memory range\n");
      result = 4294967274LL;
      goto LABEL_42;
    }
    v28 = (unsigned int)*(v25 - 2);
    if ( (unsigned int)v28 > (unsigned int)v26 )
    {
      dev_err(v34, "refusing to load segment %d with p_filesz > p_memsz\n", v24);
      result = 4294967274LL;
      goto LABEL_42;
    }
    v29 = (char *)(a4 + v27);
    if ( v17 || (_DWORD)v28 == 0 )
    {
      if ( (_DWORD)v28 )
      {
        result = mdt_load_split_segment(a4 + v27, v12 + 52, v24, a3, v34);
        if ( (_DWORD)result )
          goto LABEL_42;
      }
      goto LABEL_36;
    }
    if ( *a2 < (unsigned int)(*(v25 - 5) + v28) )
      break;
    memcpy(v29, (const void *)(a2[1] + (unsigned int)*(v25 - 5)), v28);
LABEL_36:
    v31 = *(v25 - 2);
    v30 = *(v25 - 1);
    if ( v30 > v31 )
      memset(&v29[*(v25 - 2)], 0, v30 - v31);
LABEL_23:
    ++v24;
    v25 += 8;
    if ( v24 >= *(unsigned __int16 *)(v12 + 44) )
    {
      result = 0;
      goto LABEL_42;
    }
  }
  dev_err(v34, "file %s segment %d would be truncated\n", a3, v24);
  result = 4294967274LL;
LABEL_42:
  a7 = v32;
  if ( v32 )
LABEL_39:
    *a7 = v10;
  return result;
}
