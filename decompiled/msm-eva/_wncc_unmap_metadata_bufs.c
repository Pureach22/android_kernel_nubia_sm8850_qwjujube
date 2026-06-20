__int64 __fastcall wncc_unmap_metadata_bufs(__int64 a1, unsigned int *a2, _QWORD *a3)
{
  unsigned int v3; // w22
  __int64 result; // x0
  unsigned __int64 v5; // x8
  __int64 v6; // x1
  __int64 v7; // x2
  void *v8; // x0
  __int64 v9; // x8
  unsigned __int64 v10; // x8
  unsigned int *v11; // x23
  _QWORD *v12; // x19
  unsigned __int64 v13; // x0
  __int64 v14; // x2
  __int64 v15; // x3
  unsigned __int64 v16; // x8
  unsigned int v17; // w19
  __int64 v18; // x8
  _QWORD *v19; // x21
  unsigned __int64 v20; // x19
  unsigned int v21; // w20
  unsigned __int64 v22; // x8
  unsigned int v23; // w20
  _QWORD *v24; // x19
  __int64 v25; // x2
  __int64 v26; // x3
  unsigned __int64 StatusReg; // x8
  __int64 v28; // x8
  unsigned __int64 v29; // x20
  unsigned int v30; // w21
  _QWORD *v31; // x19
  __int64 v32; // x2
  __int64 v33; // x3
  __int64 v34; // x8
  _QWORD *v35; // x21
  unsigned __int64 v36; // x19
  unsigned int v37; // w20
  _QWORD *v38; // x19
  __int64 v39; // x2
  __int64 v40; // x3
  __int64 v41; // x8
  _QWORD *v42; // x20
  unsigned __int64 v43; // x19
  __int64 v44; // [xsp+0h] [xbp-20h] BYREF
  __int64 v45; // [xsp+8h] [xbp-18h]
  __int64 v46; // [xsp+10h] [xbp-10h]
  __int64 v47; // [xsp+18h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v46 = 0;
  v44 = 0;
  if ( !a2 || !a3 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v6 = *(unsigned int *)(StatusReg + 1800);
      v7 = *(unsigned int *)(StatusReg + 1804);
      v8 = &unk_8B4A1;
      goto LABEL_30;
    }
    goto LABEL_9;
  }
  v3 = a2[1];
  if ( v3 - 5 <= 0xFFFFFFFB )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v5 = _ReadStatusReg(SP_EL0);
      v6 = *(unsigned int *)(v5 + 1800);
      v7 = *(unsigned int *)(v5 + 1804);
      v8 = &unk_8F724;
LABEL_30:
      printk(v8, v6, v7, &unk_8E7CE);
      result = 4294967274LL;
      goto LABEL_9;
    }
    goto LABEL_9;
  }
  v9 = *a2;
  if ( (unsigned int)v9 <= (-48 * v3 + 2400) >> 2 )
  {
    v11 = (unsigned int *)(a1 + 4 * v9);
    if ( !*a3 )
      goto LABEL_45;
    v12 = a3;
    v13 = dma_buf_get(*v11);
    if ( v13 >= 0xFFFFFFFFFFFFF001LL )
    {
LABEL_16:
      result = (unsigned int)-(int)v13;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v16 = _ReadStatusReg(SP_EL0);
        v17 = result;
        printk(&unk_82820, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), &unk_8E7CE);
        result = v17;
      }
      goto LABEL_9;
    }
    v18 = *v12;
    v19 = v12;
    LOBYTE(v45) = 0;
    v20 = v13;
    v44 = v18;
    dma_buf_vunmap_unlocked(v13, &v44, v14, v15);
    *v19 = 0;
    v21 = dma_buf_end_cpu_access(v20, 1);
    dma_buf_put(v20);
    a3 = v19;
    if ( v21 )
    {
      result = v21;
    }
    else
    {
LABEL_45:
      if ( v3 == 1 )
        goto LABEL_25;
      if ( a3[1] )
      {
        v24 = a3;
        v13 = dma_buf_get(v11[12]);
        if ( v13 > 0xFFFFFFFFFFFFF000LL )
          goto LABEL_16;
        v28 = v24[1];
        LOBYTE(v45) = 0;
        v29 = v13;
        v44 = v28;
        dma_buf_vunmap_unlocked(v13, &v44, v25, v26);
        v24[1] = 0;
        v30 = dma_buf_end_cpu_access(v29, 1);
        dma_buf_put(v29);
        a3 = v24;
        if ( v30 )
        {
          result = v30;
          goto LABEL_21;
        }
      }
      if ( v3 == 2 )
        goto LABEL_25;
      if ( a3[2] )
      {
        v31 = a3;
        v13 = dma_buf_get(v11[24]);
        if ( v13 > 0xFFFFFFFFFFFFF000LL )
          goto LABEL_16;
        v34 = v31[2];
        v35 = v31;
        LOBYTE(v45) = 0;
        v36 = v13;
        v44 = v34;
        dma_buf_vunmap_unlocked(v13, &v44, v32, v33);
        v35[2] = 0;
        v37 = dma_buf_end_cpu_access(v36, 1);
        dma_buf_put(v36);
        a3 = v35;
        if ( v37 )
        {
          result = v37;
          goto LABEL_21;
        }
      }
      if ( v3 == 3 || !a3[3] )
      {
LABEL_25:
        result = 0;
        goto LABEL_9;
      }
      v38 = a3;
      v13 = dma_buf_get(v11[36]);
      if ( v13 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_16;
      v41 = v38[3];
      v42 = v38;
      LOBYTE(v45) = 0;
      v43 = v13;
      v44 = v41;
      dma_buf_vunmap_unlocked(v13, &v44, v39, v40);
      v42[3] = 0;
      LODWORD(v42) = dma_buf_end_cpu_access(v43, 1);
      dma_buf_put(v43);
      result = (unsigned int)v42;
      if ( !(_DWORD)v42 )
        goto LABEL_9;
    }
LABEL_21:
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v22 = _ReadStatusReg(SP_EL0);
      v23 = result;
      printk(&unk_8E089, *(unsigned int *)(v22 + 1800), *(unsigned int *)(v22 + 1804), &unk_8E7CE);
      result = v23;
    }
    goto LABEL_9;
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v10 = _ReadStatusReg(SP_EL0);
    v6 = *(unsigned int *)(v10 + 1800);
    v7 = *(unsigned int *)(v10 + 1804);
    v8 = &unk_86377;
    goto LABEL_30;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
