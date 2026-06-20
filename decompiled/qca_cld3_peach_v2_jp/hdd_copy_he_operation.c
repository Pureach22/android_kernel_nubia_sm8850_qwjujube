_DWORD *__fastcall hdd_copy_he_operation(_DWORD *result, __int64 a2)
{
  unsigned int v2; // w8
  _DWORD *v4; // x19
  int v5; // w8
  int v6; // w21
  _BYTE *v7; // x22
  int v8; // w9
  unsigned int v9; // w8
  _BYTE *v10; // x10
  _BYTE *v11; // x8

  if ( *(_BYTE *)a2 )
  {
    v2 = *(_DWORD *)(a2 + 1);
    v4 = result;
    v5 = (v2 & 0x200000) != 0
       ? (((int)(v2 << 13) >> 31) & 3) + ((v2 >> 19) & 1) + 5
       : (((int)(v2 << 13) >> 31) & 3) + ((v2 >> 19) & 1);
    v6 = v5 + 6;
    result = (_DWORD *)_qdf_mem_malloc((unsigned int)(v5 + 6), "hdd_copy_he_operation", 1803);
    if ( result )
    {
      v7 = result;
      *result = *(_DWORD *)(a2 + 1) & 0xF
              | (16 * ((*(_DWORD *)(a2 + 1) >> 8) & 0x3FFF)) & 0xFFFFFF
              | (*(_DWORD *)(a2 + 1) >> 6) & 0xFC0000
              | ((*(_BYTE *)(a2 + 5) & 0x3F) << 24) & 0x3FFFFFFF
              | (*(_BYTE *)(a2 + 5) >> 7 << 31)
              | (((*(unsigned __int8 *)(a2 + 5) >> 6) & 1) << 30);
      qdf_mem_copy(result + 1, (const void *)(a2 + 6), 2u);
      v8 = *(_DWORD *)(a2 + 1);
      if ( (v8 & 0x40000) != 0 )
      {
        v7[6] = *(_BYTE *)(a2 + 8);
        v7[7] = *(_BYTE *)(a2 + 9);
        v7[8] = *(_BYTE *)(a2 + 10);
        v9 = 3;
        v8 = *(_DWORD *)(a2 + 1);
        if ( (v8 & 0x80000) == 0 )
          goto LABEL_11;
      }
      else
      {
        v9 = 0;
        if ( (v8 & 0x80000) == 0 )
        {
LABEL_11:
          if ( (v8 & 0x200000) != 0 )
          {
            v11 = &v7[v9];
            v11[6] = *(_BYTE *)(a2 + 12);
            v11[7] = *(_BYTE *)(a2 + 13) & 7 | (8 * ((*(_BYTE *)(a2 + 13) & 0x80) != 0));
            v11[8] = *(_BYTE *)(a2 + 14);
            v11[9] = *(_BYTE *)(a2 + 15);
            v11[10] = *(_BYTE *)(a2 + 16);
            result = *((_DWORD **)v4 + 177);
            if ( !result )
              goto LABEL_14;
          }
          else
          {
            result = *((_DWORD **)v4 + 177);
            if ( !result )
            {
LABEL_14:
              v4[356] = v6;
              *((_QWORD *)v4 + 177) = v7;
              return result;
            }
          }
          result = (_DWORD *)_qdf_mem_free((__int64)result);
          goto LABEL_14;
        }
      }
      v10 = &v7[v9++];
      v10[6] = *(_BYTE *)(a2 + 11);
      v8 = *(_DWORD *)(a2 + 1);
      goto LABEL_11;
    }
  }
  return result;
}
