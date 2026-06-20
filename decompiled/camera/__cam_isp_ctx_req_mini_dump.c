_QWORD *__fastcall _cam_isp_ctx_req_mini_dump(_QWORD *result, __int64 a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 v4; // x20
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x19
  __int64 v8; // x21
  unsigned __int64 v9; // x22
  __int64 *v10; // x23
  __int64 v11; // x9
  __int64 v12; // x19
  __int64 v13; // x21
  unsigned __int64 v14; // x22
  __int64 *v15; // x23
  __int64 v16; // x20
  __int64 v17; // x9
  __int64 v18; // x19
  int v19; // w8
  __int64 v20; // x21
  __int64 *v21; // x22

  *a4 = 0;
  if ( a2 + 48 <= a3 )
  {
    v4 = result[4];
    *(_BYTE *)(a2 + 43) = *(_DWORD *)(v4 + 52);
    *(_BYTE *)(a2 + 44) = *(_DWORD *)(v4 + 56);
    *(_BYTE *)(a2 + 45) = *(_DWORD *)(v4 + 72) != 0;
    *(_BYTE *)(a2 + 46) = *(_BYTE *)(v4 + 4504);
    *(_DWORD *)(a2 + 24) = *(_DWORD *)(v4 + 4448);
    *(_QWORD *)(a2 + 32) = result[3];
    v5 = *a4 + 48;
    *a4 = v5;
    v6 = *(unsigned int *)(v4 + 32);
    if ( (_DWORD)v6 )
    {
      v7 = v6 << 6;
      result = (_QWORD *)(a2 + v5);
      if ( a2 + v5 + (v6 << 6) > a3 )
        return result;
      *(_QWORD *)a2 = result;
      v8 = a2;
      v9 = a3;
      v10 = a4;
      result = memcpy(result, *(const void **)(v4 + 24), v6 << 6);
      a3 = v9;
      a4 = v10;
      a2 = v8;
      *(_BYTE *)(v8 + 41) = *(_DWORD *)(v4 + 32);
      v5 = *v10 + v7;
      *v10 = v5;
    }
    v11 = *(unsigned int *)(v4 + 48);
    if ( (_DWORD)v11 )
    {
      v12 = v11 << 6;
      result = (_QWORD *)(a2 + v5);
      if ( a2 + v5 + (v11 << 6) > a3 )
        return result;
      *(_QWORD *)(a2 + 8) = result;
      v13 = a2;
      v14 = a3;
      v15 = a4;
      result = memcpy(result, *(const void **)(v4 + 40), v11 << 6);
      a3 = v14;
      a4 = v15;
      a2 = v13;
      *(_BYTE *)(v13 + 40) = *(_DWORD *)(v4 + 48);
      v5 = *v15 + v12;
      *v15 = v5;
    }
    v16 = *(_QWORD *)(v4 + 4320);
    if ( v16 )
    {
      v17 = *(unsigned int *)(v16 + 36);
      if ( (_DWORD)v17 )
      {
        v18 = v17 << 8;
        result = (_QWORD *)(a2 + v5);
        if ( a2 + v5 + (v17 << 8) <= a3 )
        {
          v19 = *(_DWORD *)(v16 + 32);
          *(_QWORD *)(a2 + 16) = result;
          v20 = a2;
          v21 = a4;
          result = memcpy(result, (const void *)(v16 + (v19 & 0xFFFFFFFC) + 56), v17 << 8);
          *v21 += v18;
          *(_BYTE *)(v20 + 42) = *(_DWORD *)(v16 + 36);
        }
      }
    }
  }
  return result;
}
