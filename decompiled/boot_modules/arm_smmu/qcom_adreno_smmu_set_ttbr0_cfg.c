__int64 __fastcall qcom_adreno_smmu_set_ttbr0_cfg(__int64 *a1, __int64 a2)
{
  __int64 v2; // x8
  int v3; // w9
  unsigned int v4; // w10
  unsigned int v5; // w9
  int v6; // w10
  unsigned __int8 *v7; // x9
  __int64 v8; // x10
  unsigned __int64 v9; // x10
  __int64 v10; // x9
  unsigned int v11; // w10
  bool v12; // zf
  int v13; // w11
  int v14; // w10
  int v15; // w11
  int v16; // w10

  v2 = *(_QWORD *)(*a1 + 80) + 48LL * *((unsigned __int8 *)a1 + 48);
  v3 = *(_DWORD *)(v2 + 16);
  if ( (v3 & 0x800000) == 0 )
  {
    if ( a2 )
    {
      if ( (v3 & 0x80) != 0 )
      {
        v4 = *(_DWORD *)(a2 + 80);
        v5 = v3 & 0xFF7FFF7F;
        if ( (*(_QWORD *)(a2 + 8) & 0x20LL) != 0 )
          v6 = ((v4 << 7) & 0x3000
              | (((v4 >> 3) & 3) << 14)
              | (((v4 >> 7) & 3) << 10)
              | (v4 >> 1) & 0x300
              | (v4 >> 11) & 0x3F) << 16;
        else
          v6 = (v4 << 7) & 0x3000
             | (((v4 >> 3) & 3) << 14)
             | (((v4 >> 7) & 3) << 10)
             | (v4 >> 1) & 0x300
             | (v4 >> 11) & 0x3F;
        *(_DWORD *)(v2 + 16) = v6 | v5;
        v7 = *(unsigned __int8 **)(v2 + 40);
        v8 = *(_QWORD *)(a2 + 72);
        *(_QWORD *)v2 = v8;
        v9 = v8 | ((unsigned __int64)*((unsigned __int16 *)v7 + 1) << 48);
LABEL_12:
        *(_QWORD *)v2 = v9;
        arm_smmu_write_context_bank(*a1, *v7);
        return 0;
      }
    }
    else if ( (v3 & 0x80) == 0 )
    {
      v10 = a1[2];
      v11 = *(_DWORD *)(v10 - 32);
      v12 = (*(_QWORD *)(v10 - 104) & 0x20LL) == 0;
      v7 = *(unsigned __int8 **)(v2 + 40);
      v13 = (v11 << 7) & 0x3000
          | (((v11 >> 3) & 3) << 14)
          | (((v11 >> 7) & 3) << 10)
          | (v11 >> 1) & 0x300
          | (v11 >> 11) & 0x3F;
      v14 = v13 << 16;
      v15 = v13 | 0x800000;
      v16 = v14 | 0x80;
      if ( v12 )
        v16 = v15;
      *(_DWORD *)(v2 + 16) = v16;
      v9 = (unsigned __int64)*((unsigned __int16 *)v7 + 1) << 48;
      goto LABEL_12;
    }
  }
  return 4294967274LL;
}
