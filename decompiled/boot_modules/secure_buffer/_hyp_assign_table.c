__int64 __fastcall hyp_assign_table(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned int a4,
        _DWORD *a5,
        int *a6,
        int a7,
        char a8)
{
  __int64 result; // x0
  __int64 v11; // x19
  __int64 v15; // x20
  __int64 v16; // x23
  char v17; // w0
  unsigned int v18; // w21
  char v19; // w27
  const char *v20; // x0
  const char *v21; // x2
  __int64 v22; // x0
  __int64 v23; // x28
  unsigned __int64 v24; // x27
  __int64 v25; // x0
  __int64 v26; // x2
  __int64 v27; // x23
  int v28; // w28
  _DWORD *v29; // x11
  int *v30; // x10
  unsigned __int64 v31; // x8
  int v32; // w13
  __int64 v33; // x0
  __int64 v34; // x1
  int v35; // w8
  unsigned __int64 StatusReg; // x23
  __int64 v37; // x27
  __int64 v38; // [xsp+8h] [xbp-28h]
  __int64 v39; // [xsp+10h] [xbp-20h]
  __int64 v43; // [xsp+28h] [xbp-8h]

  if ( !qcom_secure_buffer_dev )
    return 4294966779LL;
  if ( !a1 )
    return 4294967274LL;
  result = 4294967274LL;
  if ( !a7 || !a6 || !a5 || !a4 || !a3 || !*(_QWORD *)a1 || !*(_DWORD *)(a1 + 8) )
    return result;
  v11 = 4LL * (int)a4;
  v43 = a1;
  v15 = kmemdup_noprof(a3, v11, 3264);
  if ( !v15 )
    return 4294967284LL;
LABEL_11:
  v16 = qcom_secure_buffer_dev;
  v17 = is_vmalloc_addr(v15);
  if ( (v17 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
  {
    v19 = v17;
    dma_map_single_attrs___already_done = 1;
    v20 = (const char *)dev_driver_string(v16);
    v21 = *(const char **)(v16 + 112);
    if ( !v21 )
      v21 = *(const char **)v16;
    _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v20, v21);
    __break(0x800u);
    if ( (v19 & 1) != 0 )
    {
LABEL_14:
      v18 = -12;
      goto LABEL_52;
    }
  }
  else if ( (v17 & 1) != 0 )
  {
    goto LABEL_14;
  }
  v22 = dma_map_page_attrs(
          v16,
          ((unsigned __int64)((v15 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
          v15 & 0xFFF,
          4LL * (int)a4,
          1,
          0);
  if ( v22 == -1 )
    goto LABEL_14;
  v23 = v22;
  v24 = 24LL * a7;
  if ( v24 > 0x1000 || (v25 = _kmalloc_noprof(24LL * a7, 3520), (v27 = v25) == 0) )
  {
    v18 = -12;
    goto LABEL_51;
  }
  v39 = v23;
  v28 = a7 - 1;
  if ( a7 >= 1 )
  {
    v29 = a5;
    v30 = a6;
    v31 = 0;
    do
    {
      if ( v25 + v31 )
      {
        if ( v24 <= v31
          || (v31 & 0x8000000000000000LL) != 0
          || v24 <= v31
          || (v32 = *v30, *(_DWORD *)(v25 + v31) = *v29, v24 < v31 + 4)
          || (*(_DWORD *)(v25 + v31 + 4) = v32, v24 <= v31 + 8)
          || (__int64)(v31 + 8) < 0
          || v24 <= v31 + 8
          || (*(_QWORD *)(v25 + v31 + 8) = 0, v24 <= v31 + 16)
          || (__int64)(v31 + 16) < 0
          || v24 <= v31 + 16 )
        {
          __break(1u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v37 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
          v15 = kmemdup_noprof(v26, 4LL * (int)a4, 3264);
          *(_QWORD *)(StatusReg + 80) = v37;
          if ( !v15 )
            return 4294967284LL;
          goto LABEL_11;
        }
        *(_DWORD *)(v25 + v31 + 16) = 0;
      }
      v31 += 24LL;
      ++v29;
      ++v30;
    }
    while ( 24LL * (unsigned int)a7 != v31 );
  }
  v33 = dma_map_single_attrs(qcom_secure_buffer_dev, v25, 24LL * a7);
  if ( v33 == -1 )
  {
    v18 = -12;
  }
  else
  {
    v38 = v33;
    trace_hyp_assign_info(a3, a4, a5, a6, (unsigned int)a7);
    v18 = batched_hyp_assign(v43, a2, v15, 4LL * (int)a4, v27, 24LL * a7, a8 & 1);
    if ( !v18 )
    {
      v34 = 4008636142LL;
      while ( v28 != -1 )
      {
        v35 = a5[v28--];
        if ( v35 == 3 )
        {
          v34 = 0;
          break;
        }
      }
      set_each_page_of_sg(v43, v34);
    }
    dma_unmap_page_attrs(qcom_secure_buffer_dev, v38, 24LL * a7, 1, 0);
  }
  kfree(v27);
  v23 = v39;
LABEL_51:
  dma_unmap_page_attrs(qcom_secure_buffer_dev, v23, v11, 1, 0);
LABEL_52:
  kfree(v15);
  return v18;
}
