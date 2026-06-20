__int64 __fastcall arm_smmu_init_context_bank(__int64 a1, __int64 a2)
{
  int v2; // w21
  __int64 v4; // x20
  unsigned int v5; // w8
  unsigned int v6; // w8
  unsigned int v7; // w8
  int v8; // w9
  int v9; // w10
  int v10; // w9
  int v11; // w10
  int v12; // w8
  int v13; // w9
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x9
  __int64 v17; // x10
  __int64 v18; // x8
  __int64 result; // x0
  int v20; // w8
  int v21; // w11
  unsigned int v22; // w8
  char v23; // w9
  unsigned int v24; // w8
  int v25; // w9

  v2 = *(_DWORD *)(a1 + 60);
  v4 = *(_QWORD *)(*(_QWORD *)a1 + 80LL) + 48LL * *(unsigned __int8 *)(a1 + 48);
  *(_QWORD *)(v4 + 40) = a1 + 48;
  if ( !v2 )
  {
    v6 = *(_DWORD *)(a2 + 80);
    *(_DWORD *)(v4 + 16) = (v6 << 11) & 0xC000
                         | ((v6 & 7) << 16)
                         | (v6 << 7) & 0x3000
                         | (8 * v6) & 0xC00
                         | (v6 >> 1) & 0x300
                         | (v6 >> 5) & 0xC0
                         | (v6 >> 13) & 0x3F
                         | 0x80000000;
    *(_QWORD *)v4 = *(_QWORD *)(a2 + 72);
    goto LABEL_21;
  }
  if ( *(_DWORD *)(a1 + 64) == 3 )
  {
    v5 = *(_DWORD *)(a2 + 76);
  }
  else
  {
    v7 = *(_DWORD *)(a2 + 80);
    v8 = (v7 << 7) & 0x3000 | (((v7 >> 3) & 3) << 14) | (((v7 >> 7) & 3) << 10) | (v7 >> 1) & 0x300 | (v7 >> 11) & 0x3F;
    v9 = v8 << 16;
    v10 = v8 | 0x800000;
    v11 = v9 | 0x80;
    if ( (*(_QWORD *)(a2 + 8) & 0x20LL) != 0 )
      v12 = v11;
    else
      v12 = v10;
    *(_DWORD *)(v4 + 16) = v12;
    v13 = *(_DWORD *)(a2 + 80);
    *(_DWORD *)(v4 + 20) = v13 & 7 | 0x38000;
    if ( *(_DWORD *)(a1 + 64) == 1 )
    {
      *(_DWORD *)(v4 + 20) = v13 & 7 | 0x38010;
      goto LABEL_12;
    }
    v5 = v12 | 0x80000000;
  }
  *(_DWORD *)(v4 + 16) = v5;
LABEL_12:
  if ( *(_DWORD *)(a1 + 64) == 3 )
  {
    v14 = *(unsigned int *)(a2 + 72);
    *(_QWORD *)(v4 + 8) = 0;
LABEL_16:
    *(_QWORD *)v4 = v14;
    goto LABEL_18;
  }
  v15 = (unsigned __int64)*(unsigned __int16 *)(a1 + 50) << 48;
  *(_QWORD *)v4 = v15;
  v16 = (unsigned __int64)*(unsigned __int16 *)(a1 + 50) << 48;
  *(_QWORD *)(v4 + 8) = v16;
  v17 = *(_QWORD *)(a2 + 72);
  if ( (*(_BYTE *)(a2 + 8) & 0x20) == 0 )
  {
    v14 = v17 | v15;
    goto LABEL_16;
  }
  *(_QWORD *)(v4 + 8) = v17 | v16;
LABEL_18:
  if ( *(_DWORD *)(a1 + 64) == 3 )
  {
    *(_DWORD *)(v4 + 24) = *(_DWORD *)(a2 + 84);
    *(_DWORD *)(v4 + 28) = *(_DWORD *)(a2 + 80);
  }
  else
  {
    *(_DWORD *)(v4 + 24) = *(_QWORD *)(a2 + 88);
    *(_DWORD *)(v4 + 28) = *(_DWORD *)(a2 + 92);
  }
LABEL_21:
  v18 = *(_QWORD *)(a1 + 8);
  *(_DWORD *)(a1 + 56) = 0;
  result = of_dma_is_coherent(*(_QWORD *)(v18 + 744));
  v20 = *(unsigned __int16 *)(a1 + 56);
  v21 = v20 | 0x30;
  v22 = v20 & 0xFFFFC000 | 0x7DA;
  if ( (result & 1) == 0 )
    v22 = v21;
  v23 = *(_BYTE *)(a1 + 137);
  v24 = (v22 & 0xFFFFC7FF
       | ((((unsigned __int8)(*(_BYTE *)(a1 + 136) & 2) >> 1) & 1) << 13)
       | ((((unsigned __int8)(*(_BYTE *)(a1 + 136) & 4) >> 2) & 1) << 12)
       | (((*(unsigned __int8 *)(a1 + 136) >> 3) & 1) << 11))
      ^ 0x3000;
  *(_WORD *)(a1 + 56) = v24;
  if ( (v23 & 1) != 0 )
  {
    if ( v2 )
      goto LABEL_29;
  }
  else if ( v2 && (*(_BYTE *)(a1 + 138) & 1) != 0 )
  {
    goto LABEL_29;
  }
  v24 |= 0x4000u;
  *(_WORD *)(a1 + 56) = v24;
LABEL_29:
  if ( *(_DWORD *)(a1 + 60) )
    v25 = 4166;
  else
    v25 = 70;
  *(_DWORD *)(v4 + 32) = (v25 | ((unsigned __int16)(v24 & 0xC000) >> 14)) & 0xF0FFFFFF
                       | ((v24 & 3) << 26)
                       | (v24 >> 3) & 0x100
                       | (v24 >> 5) & 0x80
                       | (v24 >> 8) & 0x20
                       | (((v24 >> 2) & 3) << 24)
                       | (v24 << 18) & 0xC00000
                       | (v24 << 14) & 0x100000
                       | (v24 << 9) & 0xF0000;
  return result;
}
