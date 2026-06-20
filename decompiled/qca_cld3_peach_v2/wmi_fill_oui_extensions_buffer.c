__int64 __fastcall wmi_fill_oui_extensions_buffer(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        __int64 a4,
        char *a5,
        char a6)
{
  __int64 v9; // x23
  char v10; // w24
  char v11; // w25
  unsigned int *v12; // x28
  int v13; // w27
  unsigned int v14; // t1
  _BYTE *v15; // x8
  __int64 v16; // x9
  unsigned int *v17; // x26
  char *v18; // x22
  size_t v19; // x2
  size_t v20; // x2
  unsigned int *v21; // x26
  size_t v22; // x2
  size_t v23; // x2
  unsigned int *v24; // x26
  size_t v25; // x2
  size_t v26; // x2
  char *v28; // [xsp+8h] [xbp-68h]

  if ( !a3 )
    return 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = (unsigned int *)(a2 + 4);
  v13 = 68 * a3;
  v28 = nullptr;
  do
  {
    if ( (a6 & 1) == 0 )
      goto LABEL_7;
    if ( *(_BYTE *)(a1 + v9 + 64) )
    {
      ++v11;
LABEL_7:
      v15 = a5;
      v16 = 1;
      goto LABEL_8;
    }
    if ( v28 )
      *v28 = v11;
    v15 = a5 + 1;
    v11 = 1;
    v16 = 2;
    v28 = a5;
LABEL_8:
    *v15 = v10;
    v17 = (unsigned int *)(a1 + v9);
    v18 = &a5[v16];
    v19 = *(unsigned int *)(a1 + v9 + 4);
    if ( (_DWORD)v19 )
    {
      qdf_mem_copy(&a5[v16], v17 + 7, v19);
      v18 += v17[1];
    }
    v20 = v17[2];
    if ( (_DWORD)v20 )
    {
      qdf_mem_copy(v18, (const void *)(a1 + v9 + 33), v20);
      v18 += v17[2];
    }
    v21 = (unsigned int *)(a1 + v9);
    v22 = *(unsigned int *)(a1 + v9 + 12);
    if ( (_DWORD)v22 )
    {
      qdf_mem_copy(v18, (char *)v21 + 53, v22);
      v18 += v21[3];
    }
    v23 = v21[4];
    if ( (_DWORD)v23 )
    {
      qdf_mem_copy(v18, (const void *)(a1 + v9 + 56), v23);
      v18 += v21[4];
    }
    v24 = (unsigned int *)(a1 + v9);
    v25 = *(unsigned int *)(a1 + v9 + 20);
    if ( (_DWORD)v25 )
    {
      qdf_mem_copy(v18, (char *)v24 + 62, v25);
      v18 += v24[5];
    }
    v26 = v24[6];
    if ( (_DWORD)v26 )
    {
      qdf_mem_copy(v18, (const void *)(a1 + v9 + 63), v26);
      v18 += v24[6];
    }
    v14 = *v12;
    v12 += 7;
    ((void (__fastcall *)(__int64, __int64, char *, _QWORD))qdf_trace_hex_dump)(49, 9, a5, v14);
    v9 += 68;
    ++v10;
    a5 = v18;
  }
  while ( v13 != (_DWORD)v9 );
  if ( v28 )
    *v28 = v11;
  return 0;
}
