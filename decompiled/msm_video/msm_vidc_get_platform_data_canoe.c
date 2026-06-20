__int64 __fastcall msm_vidc_get_platform_data_canoe(__int64 *a1)
{
  __int64 v2; // x26
  unsigned int efuse; // w0
  unsigned int subpart_info; // w19
  unsigned int part_count; // w0
  __int64 v7; // x8
  int v8; // w9
  __int64 v9; // x9
  int v10; // w8
  __int64 v11; // x9
  int v12; // w10
  __int64 v13; // x8
  int v14; // w27
  int v15; // w22
  const char *v16; // x1
  __int64 v17; // x21
  const char *v18; // x1
  __int64 v19; // x22
  __int64 v20; // x28
  const char *v21; // x24
  __int64 v22; // x8
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v23 = 0;
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_91D42, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_get_platform_data_canoe");
  memcpy((void *)a1[489], &canoe_data, 0x288u);
  efuse = msm_vidc_read_efuse(a1);
  if ( efuse )
  {
    subpart_info = efuse;
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8D2B2, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_get_platform_data_canoe");
    goto LABEL_6;
  }
  part_count = socinfo_get_part_count(2);
  subpart_info = socinfo_get_subpart_info(2, &v23, part_count);
  if ( subpart_info )
    goto LABEL_8;
  v13 = a1[489];
  if ( !*(_DWORD *)(v13 + 40) )
    goto LABEL_8;
  v14 = 0;
  while ( v23 > 15 )
  {
    switch ( v23 )
    {
      case 16:
        v15 = v14;
        v16 = "apv";
        *(_DWORD *)(v13 + 324) = 2;
        goto LABEL_28;
      case 17:
        v18 = "vpp0";
        goto LABEL_40;
      case 18:
        v18 = "vpp1";
LABEL_40:
        *(_DWORD *)(v13 + 324) = 3;
        v19 = *(_QWORD *)(a1[489] + 32);
        v20 = v19 + 16LL * v14;
        v21 = *(const char **)v20;
        if ( !strcmp(*(const char **)v20, v18) )
        {
          *(_BYTE *)(v20 + 9) = 0;
          v19 = *(_QWORD *)(a1[489] + 32);
          v21 = *(const char **)(v19 + 16LL * v14);
        }
        if ( !strcmp(v21, "apv") )
          *(_BYTE *)(v19 + 16LL * v14 + 9) = 0;
        break;
    }
LABEL_29:
    v13 = a1[489];
    if ( (unsigned int)++v14 >= *(_DWORD *)(v13 + 40) )
      goto LABEL_8;
  }
  if ( v23 != 1 )
  {
    if ( v23 == 2 )
    {
      *(_DWORD *)(v13 + 324) = 1;
      v17 = *(_QWORD *)(a1[489] + 32);
      if ( !strcmp(*(const char **)(v17 + 16LL * v14), "vpp1") )
      {
        v22 = v14;
        goto LABEL_47;
      }
    }
    goto LABEL_29;
  }
  *(_DWORD *)(v13 + 324) = 1;
  v15 = v14;
  v16 = "vpp0";
LABEL_28:
  v17 = *(_QWORD *)(a1[489] + 32);
  if ( strcmp(*(const char **)(v17 + 16LL * v15), v16) )
    goto LABEL_29;
  v22 = v15;
LABEL_47:
  *(_BYTE *)(v17 + 16 * v22 + 9) = 0;
LABEL_8:
  v7 = a1[489];
  if ( (msm_vidc_debug & 2) != 0 )
  {
    printk(&unk_93606, "high", 0xFFFFFFFFLL, "codec", *(unsigned int *)(v7 + 324));
    v7 = a1[489];
  }
  v8 = *(_DWORD *)(v7 + 324);
  if ( v8 == 1 )
  {
    *(_QWORD *)(v7 + 224) = &core_data_canoe_sku_v1;
    *(_DWORD *)(a1[489] + 232) = 9;
    *(_QWORD *)(a1[489] + 256) = &instance_cap_data_canoe_sku_v1;
    *(_DWORD *)(a1[489] + 264) = 29;
    *(_BYTE *)(a1[489] + 204) = 0;
    v7 = a1[489];
    v8 = *(_DWORD *)(v7 + 324);
    if ( v8 != 2 )
      goto LABEL_12;
LABEL_23:
    *(_QWORD *)(v7 + 224) = &core_data_canoe_sku_v2;
    *(_DWORD *)(a1[489] + 232) = 2;
    *(_QWORD *)(a1[489] + 256) = &instance_cap_data_canoe_sku_v2;
    *(_DWORD *)(a1[489] + 264) = 16;
    *(_QWORD *)(a1[489] + 376) = 0;
    *(_DWORD *)(a1[489] + 384) = 0;
    *(_QWORD *)(a1[489] + 472) = 0;
    *(_DWORD *)(a1[489] + 480) = 0;
    *(_QWORD *)(a1[489] + 568) = 0;
    *(_DWORD *)(a1[489] + 576) = 0;
    *(_BYTE *)(a1[489] + 204) = 0;
    v7 = a1[489];
    if ( *(_DWORD *)(v7 + 324) != 3 )
      goto LABEL_14;
LABEL_13:
    *(_QWORD *)(v7 + 224) = &core_data_canoe_sku_v3;
    *(_DWORD *)(a1[489] + 232) = 11;
    *(_QWORD *)(a1[489] + 256) = &instance_cap_data_canoe_sku_v3;
    *(_DWORD *)(a1[489] + 264) = 27;
    *(_QWORD *)(a1[489] + 112) = &canoe_subcache_table_sku3;
    *(_DWORD *)(a1[489] + 120) = 2;
    *(_QWORD *)(a1[489] + 376) = 0;
    *(_DWORD *)(a1[489] + 384) = 0;
    *(_QWORD *)(a1[489] + 472) = 0;
    *(_DWORD *)(a1[489] + 480) = 0;
    *(_QWORD *)(a1[489] + 568) = 0;
    *(_DWORD *)(a1[489] + 576) = 0;
    *(_BYTE *)(a1[489] + 204) = 0;
    goto LABEL_14;
  }
  if ( v8 == 2 )
    goto LABEL_23;
LABEL_12:
  if ( v8 == 3 )
    goto LABEL_13;
LABEL_14:
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(v2 + 760), "qcom,canoe-vidc-v2") )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_8BBA1, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_get_platform_data_canoe");
    *(_QWORD *)(a1[489] + 128) = &canoe_context_bank_table_v2;
    *(_DWORD *)(a1[489] + 136) = 6;
    *(_QWORD *)(a1[489] + 72) = &canoe_clk_table_v2;
    *(_DWORD *)(a1[489] + 80) = 14;
    *(_QWORD *)(a1[489] + 88) = &canoe_corner_idx_tbl_v2;
    *(_QWORD *)(a1[489] + 192) = "vpu40_2v";
    v9 = a1[489];
    v10 = *(_DWORD *)(v9 + 248);
    if ( v10 )
    {
      v11 = *(_QWORD *)(v9 + 240);
      v12 = 0;
      while ( *(_DWORD *)(v11 + ((__int64)v12 << 6)) != 104 )
      {
        if ( v10 == ++v12 )
          goto LABEL_6;
      }
      *(_QWORD *)(v11 + ((__int64)v12 << 6) + 24) = 1;
    }
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return subpart_info;
}
