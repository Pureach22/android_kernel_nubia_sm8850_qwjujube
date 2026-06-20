__int64 __fastcall zte_check_xbl_log_lines(_QWORD *a1, __int64 a2, __int64 a3, int *a4, char *a5)
{
  char *v5; // x23
  __int64 v6; // x8
  char *v7; // x8
  __int64 v11; // x26
  _BYTE *v12; // x0
  unsigned __int64 v13; // x27
  _BYTE *v14; // x28
  char *v15; // x20
  __int64 v16; // x25
  int *v17; // x8
  __int64 v18; // x9
  int v19; // t1
  __int64 v21; // [xsp+8h] [xbp-18h]

  v5 = (char *)a1[16];
  v6 = 12288;
  if ( a1[15] < 0x3000u )
    v6 = a1[15];
  v21 = v6;
  v7 = &v5[v6];
  if ( v5 >= v7 )
    return 0;
  while ( 1 )
  {
    v11 = v7 - v5;
    v12 = memchr(v5, 10, v7 - v5);
    if ( !v12 )
    {
      dev_info(*a1, "ztedbg xbl in the end of log\n");
      return 0;
    }
    v13 = v12 - v5;
    v14 = v12;
    if ( (unsigned __int64)(v12 - v5) < 2 )
      break;
    if ( !a3 )
    {
LABEL_19:
      dev_info(*a1, "ztedbg xbl all searched\n");
      return 0;
    }
    v15 = a5;
    v16 = 0;
    do
    {
      if ( a4[v16] >= 1 && strnstr(v5, *(_QWORD *)(a2 + 8 * v16), v13) )
      {
        if ( v13 > 0x80 )
        {
          dev_info(*a1, "ztedbg ignored matched long line for idx %zu / left %zu\n", v16, v11);
        }
        else
        {
          memcpy(v15, v5, v13 - 1);
          v15[v13 - 1] = 0;
          --a4[v16];
        }
      }
      ++v16;
      v15 += 128;
    }
    while ( a3 != v16 );
    v5 = v14 + 1;
    v17 = a4;
    v18 = a3;
    while ( 1 )
    {
      v19 = *v17++;
      if ( v19 > 0 )
        break;
      if ( !--v18 )
        goto LABEL_19;
    }
    v7 = (char *)(a1[16] + v21);
    if ( v5 >= v7 )
      return 0;
  }
  dev_err(*a1, "ztedbg unexpected matched len %zu : now offset %zu \n", v12 - v5, v11);
  return 0xFFFFFFFFLL;
}
