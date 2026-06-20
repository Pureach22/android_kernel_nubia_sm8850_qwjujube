__int64 __fastcall qcom_va_md_driver_probe(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  __int64 v4; // x20
  unsigned int v5; // w0
  __int64 v6; // x0
  _QWORD *v7; // x9
  unsigned __int64 v8; // x22
  unsigned __int64 v9; // x10
  unsigned __int64 v10; // x11
  bool v11; // cf
  unsigned __int64 v12; // x11
  __int64 v13; // x23
  unsigned int v14; // w24
  __int64 v15; // x20
  unsigned __int64 v16; // x21
  __int64 v17; // x0
  unsigned __int64 v18; // x10
  unsigned __int64 v19; // x11
  __int64 v20; // x8
  unsigned __int64 v21; // x11
  __int64 v22; // x14
  unsigned __int64 v23; // x12
  unsigned __int64 v24; // x15
  _QWORD *v25; // x13
  unsigned __int64 v26; // x14
  __int64 v27; // x10
  unsigned __int64 v28; // x8
  __int64 v29; // x9
  __int64 v30; // x10
  __int64 v31; // x21
  __int64 v32; // x20
  _QWORD *v33; // x9
  __int64 v34; // x8
  unsigned __int64 v35; // x10
  unsigned __int64 v36; // x11
  unsigned __int64 v37; // x11
  void *v38; // x8
  unsigned int v39; // w20
  unsigned __int64 StatusReg; // x25
  __int64 v41; // x26
  unsigned __int64 v42; // [xsp+8h] [xbp-68h] BYREF
  __int64 v43; // [xsp+10h] [xbp-60h] BYREF
  _QWORD v44[11]; // [xsp+18h] [xbp-58h] BYREF

  v44[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  result = dma_set_mask(a1 + 16, -1);
  if ( (_DWORD)result )
    goto LABEL_47;
  dma_set_coherent_mask(a1 + 16, -1);
  v3 = *(_QWORD *)(a1 + 760);
  v43 = 0;
  memset(v44, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v3, "memory-region", 0, 0, 0, v44) )
    v4 = 0;
  else
    v4 = v44[0];
  if ( v4 )
  {
    v5 = of_reserved_mem_device_init_by_idx(a1 + 16, *(_QWORD *)(a1 + 760), 0);
    if ( v5 )
    {
      v38 = &unk_7C2E;
      goto LABEL_43;
    }
  }
  v5 = of_property_read_variable_u32_array(v4, "size", &v43, 2, 0);
  if ( (v5 & 0x80000000) != 0 )
  {
    v38 = &unk_7919;
LABEL_43:
    v39 = v5;
    printk(v38, "qcom_va_md_reserve_mem");
    dev_err(a1 + 16, "CMA for VA based minidump is not present\n");
    result = v39;
    goto LABEL_47;
  }
  dword_7780 = HIDWORD(v43);
  v6 = dma_alloc_attrs(a1 + 16, HIDWORD(v43), &v42, 3264, 0);
  if ( !v6 )
    goto LABEL_46;
  dma_free_attrs(a1 + 16, (unsigned int)dword_7780, v6, v42, 0);
  v7 = *(_QWORD **)(a1 + 680);
  v8 = v42;
  if ( v7 )
  {
    v9 = v7[2];
    if ( v9 )
    {
      while ( 1 )
      {
        v10 = v7[1];
        v11 = v42 >= v10;
        v12 = v42 - v10;
        if ( v11 && v12 < v9 )
          break;
        v9 = v7[5];
        v7 += 3;
        if ( !v9 )
          goto LABEL_11;
      }
      v8 = *v7 + v12;
    }
    else
    {
LABEL_11:
      v8 = -1;
    }
  }
  v13 = memstart_addr;
  v14 = dword_7780 + 4095;
  v15 = (unsigned int)(dword_7780 + 4095) >> 12;
  v16 = (unsigned int)(8 * v15);
  v17 = _kmalloc_noprof(v16, 3264);
  if ( v17 )
  {
    while ( v14 >= 0x1000 )
    {
      v18 = v8 >> 12;
      if ( v15 - 1 >= (v16 + 7) >> 3 )
        v19 = (v16 + 7) >> 3;
      else
        v19 = v15 - 1;
      v20 = v13 >> 12;
      if ( v19 >= 2 )
      {
        v22 = (v19 + 1) & 1;
        v23 = 0xFFFFFFFEC0000000LL - (v20 << 6) + (v18 << 6);
        if ( !v22 )
          v22 = 2;
        v24 = ~v19;
        v21 = v19 + 1 - v22;
        v25 = (_QWORD *)(v17 + 8);
        v26 = v24 + v22;
        do
        {
          v26 += 2LL;
          *(v25 - 1) = v23;
          *v25 = v23 + 64;
          v25 += 2;
          v23 += 128LL;
        }
        while ( v26 );
      }
      else
      {
        v21 = 0;
      }
      v27 = (v21 << 6) + (v18 << 6) - (v20 << 6);
      v28 = 8 * v21;
      v29 = v27 - 0x140000000LL;
      v30 = v15 - v21;
      while ( v16 > v28 )
      {
        --v30;
        *(_QWORD *)(v17 + v28) = v29;
        v28 += 8LL;
        v29 += 64;
        if ( !v30 )
          goto LABEL_31;
      }
      __break(1u);
      v16 = (unsigned int)(8 * v15);
      StatusReg = _ReadStatusReg(SP_EL0);
      v41 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &qcom_va_md_driver_probe__alloc_tag;
      v17 = _kmalloc_noprof(v16, 3264);
      *(_QWORD *)(StatusReg + 80) = v41;
      if ( !v17 )
        goto LABEL_46;
    }
LABEL_31:
    v31 = v17;
    v32 = vmap();
    kfree(v31);
    v33 = *(_QWORD **)(a1 + 680);
    v34 = v42;
    if ( v33 )
    {
      v35 = v33[2];
      if ( v35 )
      {
        while ( 1 )
        {
          v36 = v33[1];
          v11 = v42 >= v36;
          v37 = v42 - v36;
          if ( v11 && v37 < v35 )
            break;
          v35 = v33[5];
          v33 += 3;
          if ( !v35 )
            goto LABEL_33;
        }
        v34 = *v33 + v37;
      }
      else
      {
LABEL_33:
        v34 = -1;
      }
    }
    qword_7788 = v32;
    va_md_data = v34;
    atomic_notifier_chain_register(&panic_notifier_list, &qcom_va_md_panic_blk);
    atomic_notifier_chain_register(&panic_notifier_list, &qcom_va_md_elf_panic_blk);
    qword_7800 = (__int64)&qword_7800;
    qword_7808 = (__int64)&qword_7800;
    qword_7810 = kset_create_and_add("va-minidump", 0, kernel_kobj);
    if ( qword_7810 )
    {
      atomic_store(1u, (unsigned __int8 *)&byte_77FA);
      result = 0;
    }
    else
    {
      dev_err(a1 + 16, "Failed to create kset for va-minidump\n");
      vunmap(qword_7788);
      result = 4294967284LL;
    }
  }
  else
  {
LABEL_46:
    result = 4294967284LL;
  }
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}
