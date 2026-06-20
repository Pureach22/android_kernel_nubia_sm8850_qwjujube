unsigned int *__fastcall _cam_context_req_mini_dump(unsigned int *result, __int64 a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x9
  size_t v7; // x19
  __int64 v8; // x8
  unsigned int *v9; // x20
  __int64 v10; // x21
  unsigned __int64 v11; // x22
  __int64 *v12; // x23
  __int16 v13; // w8
  size_t v14; // x19
  unsigned int *v15; // x21
  __int64 v16; // x22
  unsigned __int64 v17; // x23
  __int64 *v18; // x24
  __int64 v19; // x21
  __int64 v20; // x8
  size_t v21; // x19
  int v22; // w8
  __int64 v23; // x23
  __int64 *v24; // x22

  v4 = a2 + 48;
  if ( a2 + 48 > a3 )
  {
    v5 = 0;
    goto LABEL_15;
  }
  *(_WORD *)(a2 + 32) = result[16];
  *(_WORD *)(a2 + 34) = result[20];
  *(_WORD *)(a2 + 38) = result[21];
  *(_WORD *)(a2 + 40) = result[22];
  *(_QWORD *)(a2 + 24) = *((_QWORD *)result + 3);
  v6 = result[20];
  if ( (_DWORD)v6 )
  {
    v7 = v6 << 6;
    if ( v4 + (v6 << 6) > a3 )
    {
      v5 = 48;
      goto LABEL_15;
    }
    *(_QWORD *)a2 = v4;
    v9 = result;
    v10 = a2;
    v11 = a3;
    v12 = a4;
    memcpy((void *)(a2 + 48), *((const void **)result + 9), v7);
    v13 = v9[20];
    result = v9;
    a3 = v11;
    a2 = v10;
    a4 = v12;
    v5 = v7 | 0x30;
    *(_WORD *)(v10 + 34) = v13;
    v8 = result[16];
    if ( !(_DWORD)v8 )
      goto LABEL_11;
    goto LABEL_9;
  }
  v5 = 48;
  v8 = result[16];
  if ( (_DWORD)v8 )
  {
LABEL_9:
    v14 = v8 << 6;
    if ( a2 + v5 + (v8 << 6) > a3 )
      goto LABEL_15;
    *(_QWORD *)(a2 + 8) = a2 + v5;
    v15 = result;
    v16 = a2;
    v17 = a3;
    v18 = a4;
    memcpy((void *)(a2 + v5), *((const void **)result + 7), v14);
    result = v15;
    a3 = v17;
    a2 = v16;
    a4 = v18;
    v5 += v14;
    *(_WORD *)(v16 + 32) = v15[16];
  }
LABEL_11:
  v19 = *((_QWORD *)result + 17);
  if ( v19 )
  {
    v20 = *(unsigned int *)(v19 + 36);
    if ( (_DWORD)v20 )
    {
      v21 = v20 << 8;
      result = (unsigned int *)(a2 + v5);
      if ( a2 + v5 + (v20 << 8) <= a3 )
      {
        v22 = *(_DWORD *)(v19 + 32);
        *(_QWORD *)(a2 + 16) = result;
        v23 = a2;
        v24 = a4;
        result = (unsigned int *)memcpy(result, (const void *)(v19 + (v22 & 0xFFFFFFFC) + 56), v21);
        a4 = v24;
        v5 += v21;
        *(_WORD *)(v23 + 36) = *(_DWORD *)(v19 + 36);
      }
    }
  }
LABEL_15:
  *a4 = v5;
  return result;
}
