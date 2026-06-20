__int64 __fastcall gpmu_create_load_cmds(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  unsigned int v4; // w22
  unsigned __int64 v7; // x21
  _DWORD *v8; // x0
  unsigned int *v9; // x24
  unsigned int v10; // w26
  unsigned __int64 v11; // x8
  unsigned int v12; // w9
  unsigned int v13; // w19
  __int64 v14; // x27
  unsigned __int64 v15; // x28
  char *v16; // x24
  unsigned __int64 v17; // x9
  unsigned __int64 v18; // x8
  bool v19; // cf
  unsigned __int64 v20; // x8
  char *v21; // [xsp+0h] [xbp-10h]
  __int64 v22; // [xsp+8h] [xbp-8h]

  if ( *(_QWORD *)(a1 + 14344) )
    return 0;
  v4 = a3;
  v7 = 4 * (a3 + a3 / 0x7F) + 20;
  v8 = (_DWORD *)devm_kmalloc(*(_QWORD *)(a1 + 11168) + 16LL, v7, 3264);
  *(_QWORD *)(a1 + 14344) = v8;
  if ( !v8 )
    return 4294967284LL;
  if ( !(_DWORD)v7 )
    goto LABEL_24;
  *v8 = 1893662721;
  if ( (_DWORD)v7 == 4 )
    goto LABEL_24;
  v9 = v8 + 2;
  v21 = (char *)v8;
  v22 = a1;
  v8[1] = 0;
  if ( v4 )
  {
    v10 = 0;
    v11 = 8;
    while ( v7 >= v11 && v7 - v11 >= 4 )
    {
      if ( v4 >= 0x7F )
        v13 = 127;
      else
        v13 = v4;
      v14 = 4LL * v13;
      v15 = v11 + v14;
      v12 = v10 + 34816;
      *v9 = (0x4B3480u >> (v13 & 0xF ^ (v13 >> 4))) & 0x80
          | ((v12 & 0x3FFFF) << 8) & 0xF7FFFFFF
          | (((0x9669u >> ((BYTE1(v12)
                          ^ (v12 >> 4)
                          ^ (v12 >> 12)
                          ^ BYTE2(v12)
                          ^ (v12 >> 20)
                          ^ HIBYTE(v12)
                          ^ (v12 >> 28)
                          ^ v10)
                         & 0xF))
            & 1) << 27)
          | v13
          | 0x40000000;
      v16 = (char *)(v9 + 1);
      v8 = memcpy(v16, (const void *)(a2 + 4LL * v10), 4 * v13);
      v4 -= v13;
      v11 = v15 + 4;
      v9 = (unsigned int *)&v16[v14];
      v10 += v13;
      if ( !v4 )
      {
        v17 = v7 - v11;
        if ( v7 >= v11 )
          goto LABEL_18;
        goto LABEL_24;
      }
    }
    goto LABEL_24;
  }
  v11 = 8;
  v17 = v7 - 8;
  if ( v7 < 8 )
  {
LABEL_24:
    __break(1u);
    return a5xx_gpmu_init(v8);
  }
LABEL_18:
  if ( v17 < 4 )
    goto LABEL_24;
  v18 = v11 + 4;
  v19 = v7 >= v18;
  v20 = v7 - v18;
  *v9 = 1893662721;
  if ( !v19 || v20 < 4 )
    goto LABEL_24;
  result = 0;
  v9[1] = 1;
  *(_QWORD *)(v22 + 14336) = ((char *)v9 - v21 + 8) >> 2;
  return result;
}
