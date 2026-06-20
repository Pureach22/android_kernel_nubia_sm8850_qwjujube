_QWORD *__fastcall a5xx_crashdump_init(__int64 a1)
{
  __int64 v1; // x10
  __int64 v2; // x8
  __int64 v3; // x11
  unsigned int *v4; // x9
  __int64 v5; // x9
  unsigned int *v6; // t2
  __int64 v7; // x15
  __int64 v8; // x14
  __int64 v9; // x16
  _QWORD *v10; // x9
  int v11; // w10
  __int64 v12; // x10
  __int64 v13; // x11
  _QWORD *v14; // x0
  char *v15; // x2
  _QWORD *v16; // x1
  int v17; // w3
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x3
  _QWORD *v21; // x2
  __int64 v22; // x12
  int *v23; // x14
  _QWORD *result; // x0
  __int64 v25; // x17

  v1 = 0;
  v2 = 0;
  v3 = 0xF504000183573LL;
  do
  {
    v4 = (unsigned int *)((char *)&a5xx_registers + v1);
    v1 += 8;
    v6 = v4;
    v5 = *v4;
    v7 = v2 + 0x183560000F4F68LL;
    v8 = v6[1] - (unsigned int)v5 + 1;
    v9 = v8 | (v5 << 44);
    v10 = (_QWORD *)(v3 + 16);
    v2 += 4LL * (unsigned int)v8;
    *(_QWORD *)v3 = v7;
    *(_QWORD *)(v3 + 8) = v9;
    v3 += 16;
  }
  while ( v1 != 856 );
  v11 = **(_DWORD **)(a1 + 14264);
  if ( v11 == 530 || v11 == 540 )
  {
    *v10 = v2 + 0x183560000F4F68LL;
    v10[1] = 0xA80000000000100LL;
    v12 = v2 + 0x183560000F4F68LL;
    v2 += 1028;
    v10[2] = v12 + 1024;
    v10[3] = 0xAC6000000000001LL;
    v10 += 4;
  }
  v13 = 0;
  v14 = v10;
  do
  {
    v15 = (char *)&a5xx_shader_blocks + v13;
    v16 = &v10[v13];
    v13 += 16;
    *v16 = (unsigned int)(*(_DWORD *)v15 << 8);
    v16[1] = 0xBC0000000200001LL;
    v16[2] = v2 + 0x183560000F4F68LL;
    v16[3] = *((unsigned int *)v15 + 1) | 0xA00000000000000LL;
    v17 = *(_DWORD *)v15;
    v18 = *((unsigned int *)v15 + 1);
    *((_QWORD *)v15 + 1) = v2;
    v16[4] = (v17 << 8) | 1u;
    v16[5] = 0xBC0000000200001LL;
    v16[6] = v2 + 4 * v18 + 0x183560000F4F68LL;
    v16[7] = *((unsigned int *)v15 + 1) | 0xA00000000000000LL;
    v19 = *((unsigned int *)v15 + 1);
    v16[8] = (*(_DWORD *)v15 << 8) | 2u;
    v16[9] = 0xBC0000000200001LL;
    v16[10] = v2 + 4 * (v19 + v18) + 0x183560000F4F68LL;
    v16[11] = *((unsigned int *)v15 + 1) | 0xA00000000000000LL;
    v20 = v19 + v18 + *((unsigned int *)v15 + 1);
    v16[12] = (*(_DWORD *)v15 << 8) | 3u;
    v16[13] = 0xBC0000000200001LL;
    v16[14] = v2 + 4 * v20 + 0x183560000F4F68LL;
    v16[15] = *((unsigned int *)v15 + 1) | 0xA00000000000000LL;
    v2 += 4 * (v20 + *((unsigned int *)v15 + 1));
    v21 = v14;
    v14 = v16 + 16;
  }
  while ( v13 != 832 );
  v22 = 0;
  v23 = &dword_87F8;
  do
  {
    result = &v10[v22 + 832];
    v21[v22 + 16] = (unsigned int)(*(v23 - 2) << 8);
    v22 += 4;
    result[1] = 0xBC0000000200001LL;
    result[2] = v2 + 0x183560000F4F68LL;
    result[3] = (unsigned int)*v23 | 0xA00000000000000LL;
    v25 = (unsigned int)*v23;
    *((_QWORD *)v23 + 1) = v2;
    v23 += 6;
    v2 += 4 * v25;
  }
  while ( v22 != 60 );
  v21[76] = 0;
  v21[77] = 0;
  return result;
}
