__int64 __fastcall ufs_qcom_mcq_config_resource(__int64 a1)
{
  __int64 v2; // x21
  __int64 resource_byname; // x0
  __int64 v4; // x2
  _QWORD *v5; // x20
  const char **v6; // x22
  __int64 v7; // x1
  __int64 v8; // x0
  unsigned __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x0
  unsigned __int64 v20; // x2
  unsigned __int64 *v21; // x0
  unsigned __int64 *v22; // x21
  int v23; // w10
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x8
  int inserted; // w8
  __int64 v27; // x0
  __int64 result; // x0
  unsigned int v29; // w19
  unsigned int v30; // w20

  v2 = *(_QWORD *)(a1 + 64) - 16LL;
  memcpy((void *)(a1 + 4896), &ufs_res_info, 0xA8u);
  resource_byname = platform_get_resource_byname(v2, 512, "ufs_mem");
  *(_QWORD *)(a1 + 4904) = resource_byname;
  if ( !resource_byname )
  {
    dev_info(*(_QWORD *)(a1 + 64), "Resource %s not provided\n", *(const char **)(a1 + 4896));
    return 4294967277LL;
  }
  v4 = *(_QWORD *)(a1 + 4920);
  v5 = (_QWORD *)resource_byname;
  *(_QWORD *)(a1 + 4912) = *(_QWORD *)a1;
  v6 = (const char **)(a1 + 4920);
  v7 = platform_get_resource_byname(v2, 512, v4);
  v8 = *(_QWORD *)(a1 + 64);
  *(_QWORD *)(a1 + 4928) = v7;
  if ( v7 )
  {
    v9 = devm_ioremap_resource(v8);
    *(_QWORD *)(a1 + 4936) = v9;
    if ( v9 >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_19;
  }
  else
  {
    dev_info(v8, "Resource %s not provided\n", *v6);
  }
  v6 = (const char **)(a1 + 4944);
  v10 = platform_get_resource_byname(v2, 512, *(_QWORD *)(a1 + 4944));
  v11 = *(_QWORD *)(a1 + 64);
  *(_QWORD *)(a1 + 4952) = v10;
  if ( v10 )
  {
    v9 = devm_ioremap_resource(v11);
    *(_QWORD *)(a1 + 4960) = v9;
    if ( v9 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_19;
  }
  else
  {
    dev_info(v11, "Resource %s not provided\n", *v6);
  }
  v6 = (const char **)(a1 + 4968);
  v12 = platform_get_resource_byname(v2, 512, *(_QWORD *)(a1 + 4968));
  v13 = *(_QWORD *)(a1 + 64);
  *(_QWORD *)(a1 + 4976) = v12;
  if ( v12 )
  {
    v9 = devm_ioremap_resource(v13);
    *(_QWORD *)(a1 + 4984) = v9;
    if ( v9 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_19;
  }
  else
  {
    dev_info(v13, "Resource %s not provided\n", *v6);
  }
  v6 = (const char **)(a1 + 4992);
  v14 = platform_get_resource_byname(v2, 512, *(_QWORD *)(a1 + 4992));
  v15 = *(_QWORD *)(a1 + 64);
  *(_QWORD *)(a1 + 5000) = v14;
  if ( v14 )
  {
    v9 = devm_ioremap_resource(v15);
    *(_QWORD *)(a1 + 5008) = v9;
    if ( v9 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_19;
  }
  else
  {
    dev_info(v15, "Resource %s not provided\n", *v6);
  }
  v6 = (const char **)(a1 + 5016);
  v16 = platform_get_resource_byname(v2, 512, *(_QWORD *)(a1 + 5016));
  v17 = *(_QWORD *)(a1 + 64);
  *(_QWORD *)(a1 + 5024) = v16;
  if ( v16 )
  {
    v9 = devm_ioremap_resource(v17);
    *(_QWORD *)(a1 + 5032) = v9;
    if ( v9 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_19;
  }
  else
  {
    dev_info(v17, "Resource %s not provided\n", *v6);
  }
  v6 = (const char **)(a1 + 5040);
  v18 = platform_get_resource_byname(v2, 512, *(_QWORD *)(a1 + 5040));
  v19 = *(_QWORD *)(a1 + 64);
  *(_QWORD *)(a1 + 5048) = v18;
  if ( v18 )
  {
    v9 = devm_ioremap_resource(v19);
    *(_QWORD *)(a1 + 5056) = v9;
    if ( v9 <= 0xFFFFFFFFFFFFF000LL )
    {
      v20 = *(_QWORD *)(a1 + 4936);
      if ( v20 )
      {
LABEL_18:
        *(_QWORD *)(a1 + 5064) = v20;
        return 0;
      }
      goto LABEL_15;
    }
LABEL_19:
    dev_err(*(_QWORD *)(a1 + 64), "Failed to map res %s, err=%d\n", *v6, v9);
    result = *((unsigned int *)v6 + 4);
    v6[2] = nullptr;
    return result;
  }
  dev_info(v19, "Resource %s not provided\n", *v6);
  v20 = *(_QWORD *)(a1 + 4936);
  if ( v20 )
    goto LABEL_18;
LABEL_15:
  v21 = (unsigned __int64 *)devm_kmalloc(*(_QWORD *)(a1 + 64), 96, 3520);
  if ( !v21 )
    return 4294967284LL;
  v22 = v21;
  v23 = *(_DWORD *)(a1 + 4872);
  v24 = *v5 + ((unsigned __int64)*(unsigned __int8 *)(a1 + 150) << 9);
  *v21 = v24;
  v21[1] = (unsigned int)(v23 << 6) + v24 - 1;
  v25 = v5[3];
  v21[2] = (unsigned __int64)"mcq";
  v21[3] = v25;
  inserted = insert_resource(&iomem_resource, v21);
  v27 = *(_QWORD *)(a1 + 64);
  if ( inserted )
  {
    v29 = inserted;
    dev_err(v27, "Failed to insert MCQ resource, err=%d\n", inserted);
    return v29;
  }
  else
  {
    v20 = devm_ioremap_resource(v27);
    *(_QWORD *)(a1 + 4936) = v20;
    if ( v20 < 0xFFFFFFFFFFFFF001LL )
      goto LABEL_18;
    dev_err(*(_QWORD *)(a1 + 64), "MCQ registers mapping failed, err=%d\n", v20);
    v30 = *(_DWORD *)(a1 + 4936);
    *(_QWORD *)(a1 + 4936) = 0;
    remove_resource(v22);
    return v30;
  }
}
