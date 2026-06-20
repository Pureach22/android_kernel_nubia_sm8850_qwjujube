__int64 __fastcall parse_heap_dt(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x21
  __int64 v3; // x19
  __int64 next_available_child; // x0
  __int64 v5; // x1
  unsigned __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x22
  const char *v10; // x23
  unsigned int v11; // w26
  __int64 v12; // x0
  __int64 v13; // x24
  signed int v14; // w25
  __int64 v15; // x8
  __int64 v16; // x27
  int string; // w0
  int variable_u32_array; // w0
  int v19; // w0
  int v20; // w28
  int v21; // w0
  __int64 v22; // x27
  __int64 v23; // x26
  const char *v24; // x20
  __int64 v25; // x23
  __int64 v26; // x24
  __int64 v27; // x0
  __int64 v28; // x25
  int v29; // w0
  __int64 v30; // x0
  __int64 v31; // x22
  __int64 v32; // x23
  bool v33; // cc
  __int64 v34; // x21
  __int64 v35; // x0
  unsigned int v37; // [xsp+4h] [xbp-5Ch]
  __int64 v38; // [xsp+8h] [xbp-58h] BYREF
  __int64 v39; // [xsp+10h] [xbp-50h]
  __int64 v40; // [xsp+18h] [xbp-48h]
  __int64 v41; // [xsp+20h] [xbp-40h]
  __int64 v42; // [xsp+28h] [xbp-38h]
  __int64 v43; // [xsp+30h] [xbp-30h]
  __int64 v44; // [xsp+38h] [xbp-28h]
  __int64 v45; // [xsp+40h] [xbp-20h]
  __int64 v46; // [xsp+48h] [xbp-18h]
  __int64 v47; // [xsp+50h] [xbp-10h]
  __int64 v48; // [xsp+58h] [xbp-8h]

  v1 = a1;
  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v3 = _kmalloc_cache_noprof(of_find_property, 3520, 16);
  if ( !v3 )
    goto LABEL_41;
  next_available_child = of_get_next_available_child(v2, 0);
  if ( next_available_child )
  {
    v5 = next_available_child;
    do
    {
      ++*(_DWORD *)v3;
      v5 = of_get_next_available_child(v2, v5);
    }
    while ( v5 );
  }
  if ( !*(_DWORD *)v3 )
    goto LABEL_42;
  v6 = *(int *)v3;
  if ( !is_mul_ok(v6, 0x38u) )
  {
    *(_QWORD *)(v3 + 8) = 0;
    goto LABEL_40;
  }
  v7 = _kmalloc_noprof(56 * v6, 3520);
  *(_QWORD *)(v3 + 8) = v7;
  if ( !v7 )
  {
LABEL_40:
    kfree(v3);
LABEL_41:
    v3 = -12;
    goto LABEL_42;
  }
  v8 = of_get_next_available_child(v2, 0);
  if ( !v8 )
    goto LABEL_42;
  v9 = v8;
  v10 = "qcom,dma-heap-name";
  v11 = -1;
  while ( 1 )
  {
    v12 = of_platform_device_create(v9, 0, v1 + 16);
    if ( !v12 )
    {
      printk(&unk_E371, *(_QWORD *)v9);
      v20 = -22;
      goto LABEL_27;
    }
    v13 = v12 + 16;
    v14 = v11 + 1;
    of_dma_configure_id(v12 + 16, v9, 1, 0);
    v15 = 56LL * (int)(v11 + 1);
    *(_QWORD *)(*(_QWORD *)(v3 + 8) + v15 + 32) = v13;
    v16 = *(_QWORD *)(v3 + 8) + v15;
    string = of_property_read_string(v9, v10, v16 + 8);
    if ( string )
    {
      v20 = string;
LABEL_26:
      _warn_printk("%s: Unable to populate heap %s, err: %d\n", "populate_heap", *(const char **)(v9 + 16), v20);
      __break(0x800u);
      goto LABEL_27;
    }
    variable_u32_array = of_property_read_variable_u32_array(v9, "qcom,dma-heap-type", v16, 1, 0);
    if ( variable_u32_array < 0 )
    {
      v20 = variable_u32_array;
      printk(&unk_E062, "qcom,dma-heap-type");
      goto LABEL_26;
    }
    *(_BYTE *)(v16 + 40) = of_find_property(v9, "qcom,uncached-heap", 0) != 0;
    v19 = of_property_read_variable_u32_array(v9, "qcom,token", v16 + 44, 1, 0);
    v20 = v19 & (v19 >> 31);
    if ( v20 && v20 != -22 )
      goto LABEL_26;
    v21 = of_property_read_variable_u32_array(v9, "qcom,max-align", v16 + 48, 1, 0);
    v20 = v21 & (v21 >> 31);
    if ( v20 != -22 )
    {
      if ( v20 )
        goto LABEL_26;
    }
    v46 = 0;
    v47 = 0;
    v44 = 0;
    v45 = 0;
    v42 = 0;
    v43 = 0;
    v40 = 0;
    v41 = 0;
    v38 = 0;
    v39 = 0;
    if ( (unsigned int)_of_parse_phandle_with_args(v9, "memory-region", 0, 0, 0, &v38) )
      goto LABEL_11;
    v22 = v38;
    if ( !v38 )
      goto LABEL_11;
    v37 = v11;
    v23 = v1;
    v24 = v10;
    v25 = *(_QWORD *)(v3 + 8) + 56LL * v14;
    v26 = *(_QWORD *)(v25 + 32);
    v27 = of_reserved_mem_lookup(v38);
    if ( !v27 )
      break;
    v28 = v27;
    if ( *(_QWORD *)(v27 + 16) )
    {
      v29 = of_reserved_mem_device_init_by_idx(v26, *(_QWORD *)(v26 + 744), 0);
      if ( v29 )
      {
        v20 = v29;
        dev_err(v26, "Failed to initialize memory region rc: %d\n", v29);
        goto LABEL_38;
      }
    }
    *(_QWORD *)(v25 + 16) = *(_QWORD *)(v28 + 24);
    *(_QWORD *)(v25 + 24) = *(_QWORD *)(v28 + 32);
    *(_BYTE *)(v25 + 41) = of_find_property(v22, "no-map", 0) != 0;
    v10 = v24;
    v1 = v23;
    v11 = v37;
LABEL_11:
    v9 = of_get_next_available_child(v2, v9);
    ++v11;
    if ( !v9 )
      goto LABEL_42;
  }
  dev_err(v26, "Failed to find reserved memory region\n");
  v20 = -22;
LABEL_38:
  v11 = v37;
LABEL_27:
  v30 = *(_QWORD *)(v3 + 8);
  if ( (v11 & 0x80000000) == 0 )
  {
    v31 = v11 + 1LL;
    v32 = v30 + 56LL * v11 + 32;
    do
    {
      v34 = *(_QWORD *)v32;
      v35 = *(_QWORD *)(*(_QWORD *)v32 + 744LL);
      v46 = 0;
      v47 = 0;
      v44 = 0;
      v45 = 0;
      v42 = 0;
      v43 = 0;
      v40 = 0;
      v41 = 0;
      v38 = 0;
      v39 = 0;
      if ( !(unsigned int)_of_parse_phandle_with_args(v35, "memory-region", 0, 0, 0, &v38) && v38 )
        of_reserved_mem_device_release(v34);
      v33 = v31-- <= 1;
      v32 -= 56;
    }
    while ( !v33 );
    v30 = *(_QWORD *)(v3 + 8);
  }
  kfree(v30);
  kfree(v3);
  v3 = v20;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return v3;
}
