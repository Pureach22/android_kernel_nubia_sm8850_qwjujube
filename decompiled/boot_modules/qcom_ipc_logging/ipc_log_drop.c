_QWORD *__fastcall ipc_log_drop(_QWORD *result, char *dest, unsigned int a3)
{
  __int64 v3; // x8
  __int64 v6; // x19
  __int64 v7; // x9
  size_t v8; // x22
  __int64 v9; // x8
  unsigned __int64 v10; // x9
  int v11; // w23
  __int64 v12; // x9
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x8
  unsigned __int64 v16; // x9
  __int64 v17; // x10
  int v18; // w9
  __int64 v19; // x9

  v3 = result[14];
  v6 = (__int64)result;
  v7 = *(unsigned __int16 *)(v3 + 12);
  if ( 4024 - v7 >= (unsigned __int64)a3 )
    v8 = a3;
  else
    v8 = 4024 - v7;
  if ( dest )
  {
    if ( (unsigned int)v7 >= 0xFB9 || (v9 = result[14], v10 = *(unsigned __int16 *)(v9 + 12), v10 > 0xFB8) )
    {
LABEL_36:
      __break(0x5512u);
LABEL_37:
      __break(0x800u);
      return result;
    }
    result = memcpy(dest, (const void *)(v9 + v10 + 72), v8);
    v3 = *(_QWORD *)(v6 + 112);
  }
  v11 = a3 - v8;
  if ( a3 != (_DWORD)v8 )
  {
    v12 = *(_QWORD *)(v6 + 120);
    if ( v12 == v3 && *(unsigned __int16 *)(v3 + 12) == *(unsigned __int16 *)(v12 + 64) )
    {
      *(_WORD *)(v3 + 12) = 0;
      *(_WORD *)(*(_QWORD *)(v6 + 112) + 64LL) = 0;
      if ( v6 )
      {
        v13 = *(_QWORD *)(v6 + 112);
        if ( v13 )
        {
          if ( *(_QWORD *)(v6 + 96) == v13 )
            v3 = *(_QWORD *)(v6 + 88);
          else
            v3 = *(_QWORD *)(v13 + 48) - 48LL;
          *(_QWORD *)(v6 + 112) = v3;
          if ( !v3 )
            goto LABEL_37;
          *(_QWORD *)(v6 + 120) = v3;
          if ( !dest )
            goto LABEL_24;
LABEL_21:
          if ( *(unsigned __int16 *)(v3 + 12) <= 0xFB8u )
          {
            v15 = *(_QWORD *)(v6 + 112);
            v16 = *(unsigned __int16 *)(v15 + 12);
            if ( v16 <= 0xFB8 )
            {
              result = memcpy(&dest[v8], (const void *)(v15 + v16 + 72), v11);
              v3 = *(_QWORD *)(v6 + 112);
              goto LABEL_24;
            }
          }
          goto LABEL_36;
        }
      }
    }
    else
    {
      *(_WORD *)(v3 + 12) = 0;
      if ( v6 )
      {
        v14 = *(_QWORD *)(v6 + 112);
        if ( v14 )
        {
          if ( *(_QWORD *)(v6 + 96) == v14 )
          {
            v3 = *(_QWORD *)(v6 + 88);
            *(_QWORD *)(v6 + 112) = v3;
            if ( !v3 )
              goto LABEL_37;
          }
          else
          {
            v3 = *(_QWORD *)(v14 + 48) - 48LL;
            *(_QWORD *)(v6 + 112) = v3;
            if ( !v3 )
              goto LABEL_37;
          }
          if ( !dest )
            goto LABEL_24;
          goto LABEL_21;
        }
      }
    }
    *(_QWORD *)(v6 + 112) = 0;
    __break(0x800u);
    return result;
  }
  LOWORD(v11) = a3;
LABEL_24:
  v17 = *(_QWORD *)(v6 + 120);
  v18 = *(unsigned __int16 *)(v3 + 12);
  if ( v17 == v3 && v18 == *(unsigned __int16 *)(v17 + 64) )
  {
    *(_WORD *)(v3 + 12) = v18 + v11;
    v19 = *(_QWORD *)(v6 + 120);
    *(_DWORD *)(v6 + 128) += a3;
    *(_WORD *)(v19 + 64) += v11;
  }
  else
  {
    *(_WORD *)(v3 + 12) = v18 + v11;
    *(_DWORD *)(v6 + 128) += a3;
  }
  return result;
}
