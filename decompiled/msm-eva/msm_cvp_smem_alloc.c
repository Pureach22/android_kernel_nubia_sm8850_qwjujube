__int64 __fastcall msm_cvp_smem_alloc(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5, unsigned int a6)
{
  unsigned __int64 v7; // x20
  __int64 v11; // x0
  unsigned __int64 v12; // x0
  unsigned __int64 v13; // x19
  int v14; // w9
  __int64 v15; // x8
  int v16; // w8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned int device_address; // w0
  unsigned int v23; // w20
  unsigned __int64 v24; // x8
  __int64 v25; // x2
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x5
  __int64 v28; // x8
  __int64 v29; // x9
  __int64 v30; // x26
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x8
  unsigned __int64 v33; // x8
  _QWORD v34[2]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v35; // [xsp+18h] [xbp-48h]
  __int64 v36; // [xsp+20h] [xbp-40h] BYREF
  int *v37; // [xsp+28h] [xbp-38h]
  int *v38; // [xsp+30h] [xbp-30h]
  __int64 v39; // [xsp+38h] [xbp-28h]
  __int64 v40; // [xsp+40h] [xbp-20h]
  unsigned __int64 v41; // [xsp+48h] [xbp-18h] BYREF
  int v42; // [xsp+50h] [xbp-10h] BYREF
  int v43; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+58h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a5 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_9443A, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      result = 4294967274LL;
    }
    goto LABEL_41;
  }
  v41 = 0;
  v39 = 0;
  v40 = 0;
  v37 = nullptr;
  v38 = nullptr;
  v35 = 0;
  v36 = 0;
  v43 = 0;
  v34[0] = 0;
  v34[1] = 0;
  if ( !a4 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v19 = _ReadStatusReg(SP_EL0);
      printk(&unk_8C66E, *(unsigned int *)(v19 + 1800), *(unsigned int *)(v19 + 1804), &unk_8E7CE);
      result = 4294967274LL;
    }
    goto LABEL_41;
  }
  v7 = (a1 + 4095) & 0xFFFFFFFFFFFFF000LL;
  if ( *(_QWORD *)(a4 + 336) == a4 + 336 )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v31 = _ReadStatusReg(SP_EL0);
      printk(&unk_96EDE, *(unsigned int *)(v31 + 1800), *(unsigned int *)(v31 + 1804), &unk_8E7CE);
    }
    goto LABEL_22;
  }
  v11 = dma_heap_find("qcom,system");
  if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
  {
    v30 = v11;
    printk(&unk_8B320, &unk_84256, "alloc_dma_mem", v7);
    v11 = v30;
    if ( v30 )
      goto LABEL_8;
LABEL_22:
    result = 4294967284LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v20 = _ReadStatusReg(SP_EL0);
      printk(&unk_94FD3, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
      result = 4294967284LL;
    }
    goto LABEL_41;
  }
  if ( !v11 )
    goto LABEL_22;
LABEL_8:
  v12 = dma_heap_buffer_alloc(v11, v7, a6, 0);
  v13 = v12;
  if ( !v12 || v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = 4294967284LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v21 = _ReadStatusReg(SP_EL0);
      printk(&unk_95013, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), &unk_8E7CE);
      result = 4294967284LL;
    }
    goto LABEL_41;
  }
  v14 = *(_DWORD *)(a5 + 88);
  LODWORD(v36) = 1;
  v42 = 6;
  v37 = &v43;
  v38 = &v42;
  if ( (v14 & 0x10) != 0 )
  {
    v16 = 11;
LABEL_29:
    v43 = v16;
    device_address = mem_buf_lend(v12, &v36);
    v15 = a5;
    if ( device_address )
    {
      if ( (msm_cvp_debug & 1) != 0 )
      {
        v23 = device_address;
        if ( !msm_cvp_debug_out )
        {
          v24 = _ReadStatusReg(SP_EL0);
          printk(&unk_901D2, *(unsigned int *)(v24 + 1800), *(unsigned int *)(v24 + 1804), &unk_8E7CE);
        }
        goto LABEL_40;
      }
LABEL_39:
      v23 = device_address;
LABEL_40:
      dma_heap_buffer_free(v13);
      result = v23;
      goto LABEL_41;
    }
    goto LABEL_33;
  }
  v15 = a5;
  if ( (v14 & 0x20) != 0 )
  {
    v16 = 10;
    goto LABEL_29;
  }
LABEL_33:
  if ( !qword_6CF38 )
    qword_6CF38 = *(_QWORD *)(*(_QWORD *)(v13 + 8) + 16LL);
  v25 = *(unsigned int *)(v15 + 88);
  *(_DWORD *)(v15 + 80) = v7;
  *(_QWORD *)(v15 + 48) = v13;
  *(_QWORD *)(v15 + 56) = 0;
  device_address = msm_dma_get_device_address(v13, &v41, v25, a4, v15 + 104);
  if ( device_address )
  {
    if ( (msm_cvp_debug & 1) != 0 )
    {
      v23 = device_address;
      if ( !msm_cvp_debug_out )
      {
        v26 = _ReadStatusReg(SP_EL0);
        printk(&unk_86CFD, *(unsigned int *)(v26 + 1800), *(unsigned int *)(v26 + 1804), &unk_8E7CE);
      }
      goto LABEL_40;
    }
    goto LABEL_39;
  }
  v27 = v41;
  *(_DWORD *)(a5 + 64) = v41;
  if ( HIDWORD(v27) )
  {
    v23 = 0;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v32 = _ReadStatusReg(SP_EL0);
      printk(&unk_86217, *(unsigned int *)(v32 + 1800), *(unsigned int *)(v32 + 1804), &unk_8E7CE);
      v23 = 0;
    }
    goto LABEL_40;
  }
  v28 = a5;
  if ( a3 )
  {
    dma_buf_begin_cpu_access(v13, 0);
    msm_cvp_dma_buf_vmap(v13, v34);
    v29 = v35;
    v28 = a5;
    *(_QWORD *)(a5 + 56) = v35;
    if ( !v29 )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v33 = _ReadStatusReg(SP_EL0);
        printk(&unk_8A8A3, *(unsigned int *)(v33 + 1800), *(unsigned int *)(v33 + 1804), &unk_8E7CE);
      }
      dma_buf_end_cpu_access(v13, 0);
      v23 = -5;
      goto LABEL_40;
    }
  }
  result = 0;
  if ( (msm_cvp_debug & 0x40) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_8582C, &unk_84256, "alloc_dma_mem", *(_QWORD *)(v28 + 48));
    result = 0;
  }
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
