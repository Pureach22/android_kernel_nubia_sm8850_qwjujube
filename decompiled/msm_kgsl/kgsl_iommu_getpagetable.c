__int64 __fastcall kgsl_iommu_getpagetable(_QWORD *a1, __int64 a2)
{
  int v3; // w21
  __int64 result; // x0
  __int64 v5; // x0
  _QWORD *v6; // x20
  _QWORD *v7; // x0
  __int64 v8; // x10
  __int64 v9; // x9
  __int64 v10; // x8
  __int64 v11; // x12
  __int64 v12; // x9
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 *v15; // x24
  __int64 v16; // x21
  __int64 (__fastcall *v17)(_QWORD); // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 *v20; // x22
  __int64 v21; // x9
  __int64 v22; // x10
  __int64 v23; // x11
  __int64 v24; // x8
  __int64 v25; // x12
  __int64 v26; // x8
  __int64 v27; // x10
  __int64 v28; // x11
  __int64 v29; // x8
  __int64 v30; // x10
  __int64 v31; // x11
  __int64 v32; // x8
  __int64 v33; // x19

  v3 = a2;
  result = kgsl_get_pagetable(a2);
  if ( result )
    return result;
  if ( (a1[6] & 0x40) == 0 )
    return a1[2];
  v5 = _kmalloc_cache_noprof(clk_set_rate, 3520, 360);
  if ( !v5 )
    return -12;
  v6 = (_QWORD *)v5;
  kgsl_mmu_pagetable_init((__int64)a1, v5, v3);
  v6[15] = 0;
  v7 = v6;
  v6[12] = &iopgtbl_pt_ops;
  v6[13] = -1;
  v8 = a1[1776];
  v9 = a1[1775];
  v10 = *(_QWORD *)(v8 + 64) + v9;
  if ( (a1[6] & 1) == 0 )
  {
    if ( (a1[6] & 1LL) != 0 )
      v11 = 3932155904LL;
    else
      v11 = 4160749568LL;
    v6[16] = v10;
    v6[17] = v11;
    v6[20] = v10;
    v6[21] = v11;
    v6[18] = *(_QWORD *)(v8 + 64) + v9;
    if ( (a1[6] & 1) != 0 )
    {
      v12 = 4026527744LL;
      if ( (a1[6] & 0x40LL) == 0 )
        v12 = 3932155904LL;
    }
    else
    {
      v12 = 3204448256LL;
    }
    goto LABEL_25;
  }
  v6[20] = v10;
  if ( (a1[6] & 1) != 0 )
  {
    v13 = 4026527744LL;
    if ( (a1[6] & 0x40LL) == 0 )
      v13 = 3932155904LL;
  }
  else
  {
    v13 = 3204448256LL;
  }
  v6[21] = v13;
  v6[16] = 0x4000000000LL;
  v6[17] = 0x8000000000LL;
  if ( (*(_QWORD *)_ReadStatusReg(SP_EL0) & 0x400000) == 0 )
  {
    v12 = 0x4000000000LL;
    v6[18] = 0x1000000000LL;
LABEL_24:
    v10 = 0x4000000000LL;
    goto LABEL_25;
  }
  v6[18] = *(_QWORD *)(v8 + 64) + v9;
  if ( (a1[6] & 1) != 0 )
  {
    v12 = 3932155904LL;
    if ( (a1[6] & 0x40LL) != 0 )
      v12 = 4026527744LL;
    goto LABEL_24;
  }
  v10 = 0x4000000000LL;
  v12 = 3204448256LL;
LABEL_25:
  v6[19] = v12;
  v14 = a1[8];
  v6[22] = v10;
  v15 = *(__int64 **)(v14 + 168);
  v16 = *v15;
  if ( *v15 )
  {
    v17 = (__int64 (__fastcall *)(_QWORD))v15[1];
    v18 = *v15;
    if ( *((_DWORD *)v17 - 1) != -249716041 )
      __break(0x8228u);
    v19 = v17(v18);
    if ( v19 )
    {
      v20 = (__int64 *)v19;
      memcpy(v6 + 26, v15 + 6, 0x98u);
      v21 = v20[4];
      v23 = v20[2];
      v22 = v20[3];
      v6[31] = v20[5];
      v24 = *v20;
      v25 = v20[1];
      v6[29] = v22;
      v6[30] = v21;
      v6[27] = v25;
      v6[28] = v23;
      v6[26] = v24;
      v26 = v20[9];
      v27 = v20[6];
      v28 = v20[7];
      v6[34] = v20[8];
      v6[35] = v26;
      v6[32] = v27;
      v6[33] = v28;
      v29 = v20[13];
      v30 = v20[10];
      v31 = v20[11];
      v6[38] = v20[12];
      v6[39] = v29;
      v6[36] = v30;
      v6[37] = v31;
      v6[27] = v25 & 0xFFFFFFFFFFFFFFDFLL;
      v6[31] = kgsl_iopgtbl_tlb_ops;
      v32 = qcom_alloc_io_pgtable_ops(4294967294LL, v6 + 26, v16);
      v7 = v6;
      v6[25] = v32;
      if ( v32 )
      {
        v6[24] = v6[35];
        kgsl_mmu_pagetable_add((__int64)a1, (__int64)v6);
        return (__int64)v6;
      }
      v33 = -12;
    }
    else
    {
      v33 = -19;
      v7 = v6;
    }
  }
  else
  {
    v33 = -19;
  }
  kfree(v7);
  return v33;
}
