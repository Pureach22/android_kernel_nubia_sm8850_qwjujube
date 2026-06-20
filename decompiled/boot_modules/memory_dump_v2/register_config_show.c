__int64 __fastcall register_config_show(__int64 a1, __int64 a2, const char *a3)
{
  __int64 v3; // x19
  __int64 v5; // x26
  size_t v6; // x25
  size_t v7; // x22
  size_t v8; // x0
  size_t v9; // x2
  __int64 v10; // x21
  int v11; // w27
  int v12; // w28
  int v13; // w21
  unsigned int v14; // w22
  size_t v15; // x2
  __int64 v16; // x23
  int *v17; // x9
  int v18; // w8
  int v19; // w0
  int v20; // w23
  unsigned int v21; // w9
  __int64 v22; // x3
  __int64 v23; // x4
  int v24; // w22
  size_t v25; // x2
  __int64 v26; // x23
  __int64 result; // x0
  size_t v28; // x2
  _QWORD string[9]; // [xsp+8h] [xbp-48h] BYREF

  string[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 152);
  *a3 = 0;
  if ( !v3 )
  {
    result = -14;
    goto LABEL_58;
  }
  memset(string, 0, 64);
  mutex_lock(v3);
  v5 = **(_QWORD **)(v3 + 56);
  v6 = (unsigned int)scnprintf(string, 64, "per-core registers:\n");
  v7 = strnlen(a3, 0x1000u);
  if ( v7 == -1 )
  {
    v28 = 0;
    goto LABEL_62;
  }
  v8 = strnlen((const char *)string, 0x40u);
  if ( v8 >= 0x41 )
  {
LABEL_59:
    _fortify_panic(2, 64, v8 + 1);
LABEL_60:
    _fortify_panic(4, 64, 65);
LABEL_61:
    v28 = v6 + 1;
LABEL_62:
    _fortify_panic(2, -1, v28);
  }
  if ( v8 == 64 )
    goto LABEL_60;
  if ( v7 <= 0xFFF )
  {
    if ( v8 + v7 >= 0x1000 )
      v9 = 4095 - v7;
    else
      v9 = v8;
    if ( v8 + v7 >= 0x1000 )
      v10 = 4095;
    else
      v10 = v8 + v7;
    memcpy((void *)&a3[v7], string, v9);
    a3[v10] = 0;
  }
  v11 = *(_DWORD *)(v5 + 8);
  v12 = v11 + (*(_DWORD *)(*(_QWORD *)(v3 + 56) + 24LL) >> 2) + 1;
  if ( v12 >= 5 )
  {
    v13 = 4;
    do
    {
      while ( 1 )
      {
        if ( v13 == v11 )
        {
          v14 = scnprintf(string, 64, "system registers:\n") + v6;
          if ( v14 > 0x1000 )
            goto LABEL_56;
          v6 = strnlen(a3, 0x1000u);
          if ( v6 == -1 )
            goto LABEL_61;
          v8 = strnlen((const char *)string, 0x40u);
          if ( v8 >= 0x41 )
            goto LABEL_59;
          if ( v8 == 64 )
            goto LABEL_60;
          if ( v6 <= 0xFFF )
          {
            if ( v8 + v6 >= 0x1000 )
              v15 = 4095 - v6;
            else
              v15 = v8;
            if ( v8 + v6 >= 0x1000 )
              v16 = 4095;
            else
              v16 = v8 + v6;
            memcpy((void *)&a3[v6], string, v15);
            a3[v16] = 0;
          }
          LODWORD(v6) = v14;
        }
        v17 = (int *)(v5 + 4LL * v13);
        v18 = *v17;
        if ( *v17 )
          break;
        if ( ++v13 >= v12 )
          goto LABEL_57;
      }
      if ( (*v17 & 3u) > 1 )
      {
        if ( (*v17 & 3) == 2 )
        {
          v19 = scnprintf(string, 64, "0x%x, 0x%x, w\n", v18 & 0xFFFFFFFC, (unsigned int)v17[1]);
        }
        else
        {
          v21 = v17[1];
          v22 = v18 & 0xFFFFFFFC;
          v23 = v21 & 0xFFFFFF;
          if ( HIBYTE(v21) == 1 )
            v19 = scnprintf(string, 64, "0x%x, 0x%x, d\n", v22, v23);
          else
            v19 = scnprintf(string, 64, "0x%x, 0x%x, R\n", v22, v23);
        }
      }
      else
      {
        if ( (v18 & 3) != 0 )
        {
          v19 = scnprintf(string, 64, "0x%x, 0x%x, r\n", v18 & 0xFFFFFFFC, 4);
          v20 = 1;
          goto LABEL_43;
        }
        v19 = scnprintf(string, 64, "0x%x, 0x%x, r\n", v18 & 0xFFFFFFFC, (unsigned int)v17[1]);
      }
      v20 = 2;
LABEL_43:
      v24 = v19 + v6;
      if ( (unsigned int)(v19 + v6) > 0x1000 )
      {
LABEL_56:
        dev_err(a1, "Couldn't write complete config\n");
        break;
      }
      v6 = strnlen(a3, 0x1000u);
      if ( v6 == -1 )
        goto LABEL_61;
      v8 = strnlen((const char *)string, 0x40u);
      if ( v8 >= 0x41 )
        goto LABEL_59;
      if ( v8 == 64 )
        goto LABEL_60;
      v13 += v20;
      if ( v6 <= 0xFFF )
      {
        if ( v8 + v6 >= 0x1000 )
          v25 = 4095 - v6;
        else
          v25 = v8;
        if ( v8 + v6 >= 0x1000 )
          v26 = 4095;
        else
          v26 = v8 + v6;
        memcpy((void *)&a3[v6], string, v25);
        a3[v26] = 0;
      }
      LODWORD(v6) = v24;
    }
    while ( v13 < v12 );
  }
LABEL_57:
  mutex_unlock(v3);
  result = (int)v6;
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return result;
}
