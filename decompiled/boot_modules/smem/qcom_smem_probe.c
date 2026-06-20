__int64 __fastcall qcom_smem_probe(__int64 a1)
{
  __int64 v1; // x22
  __int64 v2; // x0
  __int64 property; // x0
  __int64 v4; // x23
  __int64 v5; // x24
  unsigned __int64 v6; // x21
  _QWORD *v7; // x19
  __int64 v8; // x0
  __int64 v9; // x20
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x0
  int id; // w0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  int item_count; // w0
  int v21; // w21
  unsigned int v22; // w20
  __int64 result; // x0
  __int64 v24; // x1
  __int64 v25; // x0
  __int64 v26; // x2
  __int64 v27; // x8
  __int64 v28; // x8
  unsigned __int64 StatusReg; // x20
  __int64 v30; // x25
  __int64 v31; // [xsp+0h] [xbp-C0h] BYREF
  __int64 v32; // [xsp+8h] [xbp-B8h] BYREF
  __int64 v33; // [xsp+10h] [xbp-B0h]
  __int64 v34; // [xsp+18h] [xbp-A8h]
  const char *v35; // [xsp+20h] [xbp-A0h]
  _QWORD v36[8]; // [xsp+28h] [xbp-98h] BYREF
  __int64 v37; // [xsp+68h] [xbp-58h] BYREF
  __int64 v38; // [xsp+70h] [xbp-50h]
  __int64 v39; // [xsp+78h] [xbp-48h]
  __int64 v40; // [xsp+80h] [xbp-40h]
  __int64 v41; // [xsp+88h] [xbp-38h]
  __int64 v42; // [xsp+90h] [xbp-30h]
  __int64 v43; // [xsp+98h] [xbp-28h]
  __int64 v44; // [xsp+A0h] [xbp-20h]
  __int64 v45; // [xsp+A8h] [xbp-18h]
  __int64 v46; // [xsp+B0h] [xbp-10h]
  __int64 v47; // [xsp+B8h] [xbp-8h]

  v1 = a1;
  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v31 = 0;
  property = of_find_property(v2, "qcom,rpm-msg-ram", 0);
  v4 = property;
  if ( property )
    LODWORD(v5) = 2;
  else
    LODWORD(v5) = 1;
  v6 = (unsigned int)((24 << (property != 0)) + 880);
  v7 = (_QWORD *)_kmalloc_noprof(v6, 3520);
  if ( !v7 )
  {
LABEL_57:
    result = 4294967284LL;
    goto LABEL_58;
  }
  while ( 1 )
  {
    v8 = *(_QWORD *)(v1 + 760);
    v9 = v1 + 16;
    *((_DWORD *)v7 + 218) = v5;
    *v7 = v1 + 16;
    v10 = of_reserved_mem_lookup(v8);
    if ( v10 )
    {
      v11 = *(_QWORD *)(v10 + 24);
      v7[110] = v11;
      if ( (v6 & 0x3F8) == 0x380 )
        goto LABEL_56;
      v7[112] = *(_QWORD *)(v10 + 32);
      if ( !v4 )
        goto LABEL_21;
    }
    else
    {
      v5 = *v7;
      v15 = *(_QWORD *)(*v7 + 744LL);
      memset(v36, 0, sizeof(v36));
      v34 = 0;
      v35 = nullptr;
      v32 = 0;
      v33 = 0;
      v45 = 0;
      v46 = 0;
      v43 = 0;
      v44 = 0;
      v41 = 0;
      v42 = 0;
      v39 = 0;
      v40 = 0;
      v37 = 0;
      v38 = 0;
      if ( (unsigned int)_of_parse_phandle_with_args(v15, "memory-region", 0, 0, 0, &v37) || !v37 )
      {
        dev_err(v5, "No %s specified\n", "memory-region");
        goto LABEL_47;
      }
      id = of_address_to_resource(v37, 0, &v32);
      if ( id )
        goto LABEL_48;
      v11 = v32;
      v7[110] = v32;
      if ( (v6 & 0x3F8) == 0x380 )
        goto LABEL_56;
      v7[112] = v33 - v11 + 1;
      if ( !v4 )
        goto LABEL_21;
    }
    v5 = *v7;
    v12 = *(_QWORD *)(*v7 + 744LL);
    memset(v36, 0, sizeof(v36));
    v34 = 0;
    v35 = nullptr;
    v32 = 0;
    v33 = 0;
    v45 = 0;
    v46 = 0;
    v43 = 0;
    v44 = 0;
    v41 = 0;
    v42 = 0;
    v39 = 0;
    v40 = 0;
    v37 = 0;
    v38 = 0;
    if ( (unsigned int)_of_parse_phandle_with_args(v12, "qcom,rpm-msg-ram", 0, 0, 0, &v37) || !v37 )
    {
      dev_err(v5, "No %s specified\n", "qcom,rpm-msg-ram");
LABEL_47:
      id = -22;
      goto LABEL_48;
    }
    id = of_address_to_resource(v37, 0, &v32);
    if ( id )
      goto LABEL_48;
    if ( v6 >= 0x388 && (v6 & 0x3F8) != 0x388 )
    {
      v14 = v32;
      v7[113] = v32;
      if ( v6 >= 0x398 && (v6 & 0x3F8) != 0x398 )
        break;
    }
LABEL_56:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v30 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v6 = (unsigned int)((24 << (v4 != 0)) + 880);
    v7 = (_QWORD *)_kmalloc_noprof(v6, 3520);
    *(_QWORD *)(StatusReg + 80) = v30;
    if ( !v7 )
      goto LABEL_57;
  }
  v11 = v7[110];
  v7[115] = v33 - v14 + 1;
LABEL_21:
  v7[111] = devm_ioremap_wc(*v7, v11, 4096);
  if ( (v6 & 0x3F8) == 0x380 )
    goto LABEL_56;
  v16 = devm_ioremap_wc(*v7, (unsigned int)(*((_DWORD *)v7 + 220) + *((_DWORD *)v7 + 224) - 4096), 4096);
  v5 = v7[111];
  v17 = v16;
  v7[4] = v16;
  id = -12;
  if ( !v5 || !v17 )
    goto LABEL_48;
  if ( v4 )
  {
    if ( v6 < 0x388 )
      goto LABEL_56;
    if ( (v6 & 0x3F8) == 0x388 )
      goto LABEL_56;
    if ( v6 < 0x398 )
      goto LABEL_56;
    if ( (v6 & 0x3F8) == 0x398 )
      goto LABEL_56;
    v18 = devm_ioremap_wc(v1 + 16, v7[113], v7[115]);
    if ( (v6 & 0x3F8) == 0x390 )
      goto LABEL_56;
    v7[114] = v18;
    if ( !v18 )
    {
      dev_err(v1 + 16, "failed to remap %pa\n", v7 + 113);
      id = -12;
      goto LABEL_48;
    }
    v5 = v7[111];
  }
  if ( *(_DWORD *)(v5 + 192) != 1 || *(_DWORD *)(v5 + 204) )
  {
    dev_err(v1 + 16, "SMEM is not initialized by SBL\n");
    goto LABEL_47;
  }
  id = of_hwspin_lock_get_id(*(_QWORD *)(v1 + 760), 0);
  if ( id < 0 )
  {
    if ( id != -517 )
    {
      v21 = id;
      dev_err(v1 + 16, "failed to retrieve hwlock\n");
      id = v21;
    }
    goto LABEL_48;
  }
  v19 = hwspin_lock_request_specific();
  v7[1] = v19;
  if ( !v19 )
  {
    id = -6;
    goto LABEL_48;
  }
  id = _hwspin_lock_timeout(v19, 1000, 1, &v31);
  if ( id )
    goto LABEL_48;
  v1 = (unsigned int)readl_relaxed(v5 + 200);
  v4 = (unsigned int)readl_relaxed(v5 + 196);
  _hwspin_unlock(v7[1], 1, &v31);
  LODWORD(v5) = *(_DWORD *)(v7[111] + 92LL);
  devm_iounmap(*v7);
  if ( WORD1(v5) == 11 )
  {
    if ( (v6 & 0x3F8) != 0x380 )
    {
      v24 = *((unsigned int *)v7 + 220);
      v25 = *v7;
      v26 = (unsigned int)(v4 + v1);
      v7[112] = v26;
      v27 = devm_ioremap_wc(v25, v24, v26);
      item_count = 512;
      v7[111] = v27;
      goto LABEL_51;
    }
    goto LABEL_56;
  }
  if ( WORD1(v5) != 12 )
  {
    dev_err(v9, "Unsupported SMEM version 0x%x\n", v5);
    goto LABEL_47;
  }
  id = qcom_smem_set_global_partition(v7);
  if ( id < 0 )
    goto LABEL_48;
  item_count = qcom_smem_get_item_count(v7);
LABEL_51:
  *((_DWORD *)v7 + 4) = item_count;
  id = qcom_smem_enumerate_partitions(v7);
  if ( id < 0 && id != -2 )
  {
LABEL_48:
    v22 = id;
    kfree(v7);
    result = v22;
    goto LABEL_58;
  }
  v32 = v9;
  v33 = 0;
  _smem = (__int64)v7;
  v34 = 0;
  v35 = "qcom-socinfo";
  LODWORD(v36[0]) = -1;
  memset((char *)v36 + 4, 0, 60);
  v28 = platform_device_register_full(&v32);
  result = 0;
  v7[3] = v28;
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return result;
}
