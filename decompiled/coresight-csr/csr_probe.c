unsigned __int64 __fastcall csr_probe(_QWORD *a1)
{
  _QWORD *v1; // x19
  unsigned __int64 result; // x0
  __int64 v4; // x0
  __int64 v5; // x20
  _QWORD *resource_byname; // x0
  _QWORD *v7; // x22
  __int64 v8; // x0
  bool v9; // w9
  __int64 v10; // x0
  bool v11; // w9
  __int64 v12; // x0
  bool v13; // w9
  __int64 v14; // x0
  bool v15; // w9
  __int64 v16; // x0
  __int64 property; // x0
  int v18; // w8
  __int64 v19; // x0
  _QWORD *v20; // x0
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x0
  _DWORD *v24; // x0
  __int64 v25; // x9
  char v26; // w10
  _UNKNOWN **v27; // x8
  __int64 v28; // x8
  _QWORD v29[3]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v30; // [xsp+20h] [xbp-40h]
  _QWORD *v31; // [xsp+28h] [xbp-38h]
  _UNKNOWN **v32; // [xsp+30h] [xbp-30h]
  __int64 v33; // [xsp+38h] [xbp-28h]
  __int64 v34; // [xsp+40h] [xbp-20h]
  __int64 v35; // [xsp+48h] [xbp-18h]
  __int64 v36; // [xsp+50h] [xbp-10h]
  __int64 v37; // [xsp+58h] [xbp-8h]

  v1 = a1 + 2;
  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v36 = 0;
  v34 = 0;
  v31 = nullptr;
  v32 = nullptr;
  v30 = 0;
  memset(v29, 0, sizeof(v29));
  v33 = coresight_alloc_device_name(&csr_devs, a1 + 2);
  if ( !v33 )
    goto LABEL_24;
  result = coresight_get_platform_data(v1);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_25;
  a1[20] = result;
  v4 = devm_kmalloc(v1, 168, 3520);
  if ( !v4 )
    goto LABEL_24;
  v5 = v4;
  *(_QWORD *)(v4 + 32) = v1;
  a1[21] = v4;
  *(_QWORD *)(v4 + 144) = devm_clk_get(v1, "apb_pclk");
  resource_byname = (_QWORD *)platform_get_resource_byname(a1, 512, "csr-base");
  if ( !resource_byname )
  {
LABEL_14:
    result = 4294967277LL;
    goto LABEL_25;
  }
  v7 = resource_byname;
  *(_QWORD *)(v5 + 8) = *resource_byname;
  v8 = devm_ioremap(v1);
  *(_QWORD *)v5 = v8;
  if ( !v8 )
    goto LABEL_24;
  if ( (of_property_read_variable_u32_array(a1[95], "qcom,blk-size", v5 + 64, 1, 0) & 0x80000000) != 0 )
    *(_DWORD *)(v5 + 64) = 0;
  v9 = of_find_property(a1[95], "qcom,usb-bam-support", 0) != 0;
  v10 = a1[95];
  *(_BYTE *)(v5 + 156) = v9;
  v11 = of_find_property(v10, "qcom,hwctrl-set-support", 0) != 0;
  v12 = a1[95];
  *(_BYTE *)(v5 + 158) = v11;
  v13 = of_find_property(v12, "qcom,set-byte-cntr-support", 0) != 0;
  v14 = a1[95];
  *(_BYTE *)(v5 + 159) = v13;
  v15 = of_find_property(v14, "qcom,timestamp-support", 0) != 0;
  v16 = a1[95];
  *(_BYTE *)(v5 + 160) = v15;
  property = of_find_property(v16, "qcom,perflsheot-set-support", 0);
  v18 = *(unsigned __int8 *)(v5 + 156);
  *(_BYTE *)(v5 + 157) = property != 0;
  if ( v18 == 1 )
    *(_DWORD *)(v5 + 68) = 1;
  v19 = of_find_property(a1[95], "qcom,msr-support", 0);
  *(_BYTE *)(v5 + 162) = v19 != 0;
  if ( v19 )
  {
    v20 = (_QWORD *)platform_get_resource_byname(a1, 512, "msr-base");
    if ( !v20 )
      goto LABEL_14;
    v21 = *v20 - *v7;
    if ( *v20 < *v7 || v20[1] > v7[1] )
      goto LABEL_14;
    *(_QWORD *)(v5 + 16) = v21;
    v22 = v20[1] - *v7;
    *(_QWORD *)(v5 + 24) = v22;
    v23 = devm_kmalloc(v1, (v22 - v21 + 1) & 0xFFFFFFFFFFFFFFFCLL, 3520);
    *(_QWORD *)(v5 + 48) = v23;
    if ( v23 )
    {
      v24 = (_DWORD *)devm_kmalloc(v1, 4, 3520);
      *(_QWORD *)(v5 + 56) = v24;
      if ( v24 )
      {
        *v24 = 0;
        goto LABEL_18;
      }
    }
LABEL_24:
    result = 4294967284LL;
    goto LABEL_25;
  }
LABEL_18:
  v25 = a1[20];
  v26 = *(_BYTE *)(v5 + 160);
  LODWORD(v29[0]) = 4;
  v30 = v25;
  v31 = v1;
  if ( (v26 & 1) != 0 || (*(_BYTE *)(v5 + 162) & 1) != 0 )
  {
    v27 = &swao_csr_attr_grps;
LABEL_21:
    v32 = v27;
    goto LABEL_22;
  }
  if ( *(_BYTE *)(v5 + 156) == 1 )
  {
    v27 = &csr_attr_grps;
    goto LABEL_21;
  }
LABEL_22:
  result = coresight_register(v29);
  *(_QWORD *)(v5 + 40) = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v28 = v33;
    *(_DWORD *)(v5 + 152) = 0;
    *(_QWORD *)(v5 + 120) = v28;
    raw_spin_lock(&csr_spinlock);
    list_add_tail(v5 + 128);
    raw_spin_unlock(&csr_spinlock);
    dev_info(v1, "CSR initialized: %s\n", *(const char **)(v5 + 120));
    result = 0;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
