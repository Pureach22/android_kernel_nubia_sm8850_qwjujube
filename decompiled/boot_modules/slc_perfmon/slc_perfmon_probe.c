__int64 __fastcall slc_perfmon_probe(__int64 a1)
{
  unsigned __int64 qcom_scmi_device; // x0
  __int64 result; // x0
  unsigned __int64 v4; // x22
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x21
  unsigned __int64 v7; // x20
  __int64 (__fastcall *v8)(unsigned __int64, __int64, unsigned __int64); // x8
  unsigned __int64 v9; // x0
  unsigned __int64 resource_byname; // x0
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x1
  __int64 v13; // x0
  _DWORD *v14; // x8
  unsigned int v15; // w0
  int v16; // w9
  unsigned __int8 v17; // w8
  unsigned __int64 v18; // x1
  __int64 v19; // x0
  __int64 (__fastcall *v20)(__int64, unsigned __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v21; // x4
  unsigned int v22; // w0
  int v23; // w0
  __int64 v24; // x8
  unsigned __int64 v25; // x0
  unsigned __int64 v26; // x21
  unsigned __int64 v27; // x23
  unsigned __int64 v28; // x8
  __int64 inited; // x0
  unsigned __int64 v30; // x2
  unsigned __int64 v31; // x0
  unsigned __int64 v32; // x0
  unsigned __int64 v33; // x0
  unsigned __int64 v34; // x2
  bool v35; // zf
  __int64 v36; // x8
  char v37; // w9
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x1
  __int64 v44; // x0
  __int64 v45; // x1
  __int64 v46; // x0
  __int64 v47; // x9
  __int64 v48; // x9
  __int64 v49; // x8
  unsigned int v50; // w20
  unsigned __int64 v51; // x20
  _DWORD v52[76]; // [xsp+18h] [xbp-138h] BYREF
  __int64 v53; // [xsp+148h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qcom_scmi_device = get_qcom_scmi_device();
  if ( qcom_scmi_device >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (_DWORD)qcom_scmi_device == -517 )
    {
      result = 4294966779LL;
    }
    else
    {
      v50 = qcom_scmi_device;
      dev_err(a1 + 16, "Error getting scmi_dev ret=%d.\n", qcom_scmi_device);
      result = v50;
    }
    goto LABEL_74;
  }
  v4 = qcom_scmi_device;
  v5 = devm_clk_get(a1 + 16, "qdss_clk");
  if ( !v5 || (v6 = v5, v5 >= 0xFFFFFFFFFFFFF001LL) )
  {
    dev_warn(a1 + 16, "failed to get qdss clock node.\n");
    v6 = 0;
  }
  v7 = devm_kmalloc(a1 + 16, 224, 3520);
  result = 4294967284LL;
  if ( !v7 || v7 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_74;
  _mutex_init(v7 + 136, "&slc_priv->mutex", &slc_perfmon_probe___key);
  *(_QWORD *)(v7 + 80) = v4;
  *(_QWORD *)(v7 + 104) = v6;
  v8 = *(__int64 (__fastcall **)(unsigned __int64, __int64, unsigned __int64))(*(_QWORD *)(v4 + 928) + 24LL);
  if ( *((_DWORD *)v8 - 1) != -1171826031 )
    __break(0x8228u);
  v9 = v8(v4, 128, v7 + 88);
  *(_QWORD *)(v7 + 96) = v9;
  if ( v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(v7 + 96) = 0;
    v51 = v9;
    dev_err(a1 + 16, "Error getting vendor protocol ops: %d.\n", v9);
    result = v51;
    goto LABEL_74;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "perfmon_offset", v7 + 52, 1, 0) & 0x80000000) != 0 )
  {
    dev_err(a1 + 16, "Failed to get perfmon offset.\n");
LABEL_63:
    result = 4294967277LL;
    goto LABEL_74;
  }
  resource_byname = platform_get_resource_byname(a1, 512, "perfmon_base");
  *(_QWORD *)(v7 + 184) = resource_byname;
  if ( !resource_byname || resource_byname >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(a1 + 16, "Failed to get memory resource.\n");
    goto LABEL_63;
  }
  v11 = devm_ioremap(a1 + 16) + *(unsigned int *)(v7 + 52);
  *(_QWORD *)(v7 + 192) = v11;
  if ( !v11 || v11 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(a1 + 16, "Error ioremap perfmon_base.\n");
LABEL_73:
    result = 4294967284LL;
    goto LABEL_74;
  }
  v12 = devm_kmalloc(a1 + 16, 10, 3520);
  result = 4294967284LL;
  *(_QWORD *)(v7 + 112) = v12;
  if ( !v12 || v12 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_74;
  v13 = *(_QWORD *)(v7 + 88);
  v14 = *(_DWORD **)(*(_QWORD *)(v7 + 96) + 8LL);
  if ( *(v14 - 1) != 1134762728 )
    __break(0x8228u);
  v15 = ((__int64 (__fastcall *)(__int64, unsigned __int64, __int64, _QWORD, __int64, __int64))v14)(
          v13,
          v12,
          0x534C432D50455246LL,
          0,
          10,
          10);
  if ( v15 )
  {
    dev_err(a1 + 16, "Receive SCMI: attr %d err: %d, %s\n", 0, v15, "remove and try again.");
LABEL_69:
    result = 4294967274LL;
    goto LABEL_74;
  }
  v16 = *(unsigned __int16 *)(*(_QWORD *)(v7 + 112) + 8LL);
  v17 = *(_BYTE *)(v7 + 217);
  if ( *(_WORD *)(*(_QWORD *)(v7 + 112) + 8LL) )
  {
    do
    {
      ++v17;
      v16 &= v16 - 1;
    }
    while ( (_WORD)v16 );
    *(_BYTE *)(v7 + 217) = v17;
  }
  v18 = devm_kmalloc(a1 + 16, v17 + 12LL, 3520);
  result = 4294967284LL;
  *(_QWORD *)(v7 + 120) = v18;
  if ( !v18 || v18 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_74;
  v19 = *(_QWORD *)(v7 + 88);
  v20 = *(__int64 (__fastcall **)(__int64, unsigned __int64, __int64, __int64, __int64, __int64))(*(_QWORD *)(v7 + 96)
                                                                                                + 8LL);
  v21 = (unsigned __int8)(*(_BYTE *)(v7 + 217) + 12);
  if ( *((_DWORD *)v20 - 1) != 1134762728 )
    __break(0x8228u);
  v22 = v20(v19, v18, 0x534C432D50455246LL, 1, v21, v21);
  if ( v22 )
  {
    dev_err(a1 + 16, "Receive SCMI: attr %d err: %d, %s\n", 1, v22, "remove and try again.");
    goto LABEL_69;
  }
  v23 = of_property_count_elems_of_size(*(_QWORD *)(a1 + 760), "reg", 4);
  v24 = *(_BYTE *)(*(_QWORD *)(v7 + 112) + 6LL) & 0x3F;
  if ( v23 < (int)v24 + 2 )
  {
    dev_err(a1 + 16, "Insufficient no. of regmaps\n");
    goto LABEL_71;
  }
  v25 = devm_kmalloc(a1 + 16, 8 * v24, 3520);
  *(_QWORD *)(v7 + 200) = v25;
  if ( !v25 || v25 > 0xFFFFFFFFFFFFF000LL )
  {
    dev_err(a1 + 16, "Error: trp regmap allocation failedn %ld\n", v25);
    goto LABEL_73;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(v7 + 112) + 6LL) & 0x3F) != 0 )
  {
    v26 = 0;
    do
    {
      v27 = kasprintf(3264, "trp_%d_base", v26);
      memset(v52, 0, sizeof(v52));
      v52[3] = 32;
      BYTE1(v52[30]) = 1;
      v28 = platform_get_resource_byname(a1, 512, v27);
      inited = 0;
      if ( v28 )
      {
        if ( v28 <= 0xFFFFFFFFFFFFF000LL )
        {
          v30 = devm_ioremap(a1 + 16);
          inited = 0;
          if ( v30 )
          {
            if ( v30 <= 0xFFFFFFFFFFFFF000LL )
              inited = _devm_regmap_init_mmio_clk(a1 + 16, 0);
          }
        }
      }
      *(_QWORD *)(*(_QWORD *)(v7 + 200) + 8 * v26) = inited;
      if ( v27 && v27 <= 0xFFFFFFFFFFFFF000LL )
        kfree(v27);
      ++v26;
    }
    while ( v26 < (*(_BYTE *)(*(_QWORD *)(v7 + 112) + 6LL) & 0x3Fu) );
  }
  memset(v52, 0, sizeof(v52));
  v52[3] = 32;
  BYTE1(v52[30]) = 1;
  v31 = platform_get_resource_byname(a1, 512, "trp_or_bcast_base");
  if ( !v31 || v31 > 0xFFFFFFFFFFFFF000LL || (v32 = devm_ioremap(a1 + 16)) == 0 || v32 >= 0xFFFFFFFFFFFFF001LL )
  {
    v34 = 0;
    *(_QWORD *)(v7 + 208) = 0;
LABEL_67:
    dev_err(a1 + 16, "Error: bcast trp regmap allocation failed, %ld\n", v34);
    goto LABEL_73;
  }
  v33 = _devm_regmap_init_mmio_clk(a1 + 16, 0);
  v34 = v33;
  *(_QWORD *)(v7 + 208) = v33;
  if ( !v33 || v33 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_67;
  v35 = of_find_property(*(_QWORD *)(a1 + 760), "slc-scid-status-snapshot", 0) == 0;
  v36 = *(_QWORD *)(v7 + 112);
  v37 = !v35;
  *(_BYTE *)(v7 + 216) = v37;
  *(_DWORD *)(v7 + 44) = 120 * *(unsigned __int8 *)(v36 + 4);
  *(_DWORD *)(v7 + 48) = 4 * *(unsigned __int8 *)(v36 + 5);
  v38 = devm_kmalloc(a1 + 16, 2LL * *(unsigned __int8 *)(v36 + 4), 3520);
  v39 = *(_QWORD *)(v7 + 112);
  *(_QWORD *)(v7 + 64) = v38;
  v40 = devm_kmalloc(a1 + 16, 3LL * *(unsigned __int8 *)(v39 + 5), 3520);
  v41 = *(_QWORD *)(v7 + 112);
  *(_QWORD *)(v7 + 72) = v40;
  v42 = devm_kmalloc(a1 + 16, 8LL * *(unsigned __int8 *)(v41 + 5), 3520);
  v43 = *(unsigned int *)(v7 + 44);
  *(_QWORD *)(v7 + 56) = v42;
  v44 = devm_kmalloc(a1 + 16, v43, 3520);
  v45 = *(unsigned int *)(v7 + 48);
  *(_QWORD *)(v7 + 8) = v44;
  v46 = devm_kmalloc(a1 + 16, v45, 3520);
  v47 = *(_QWORD *)(v7 + 64);
  *(_QWORD *)(v7 + 24) = v46;
  if ( !v47 || !*(_QWORD *)(v7 + 72) )
    goto LABEL_73;
  v48 = *(_QWORD *)(v7 + 8);
  v49 = v46;
  result = 4294967284LL;
  if ( v48 && v49 )
  {
    *(_QWORD *)(v7 + 16) = v48;
    *(_QWORD *)(v7 + 32) = v49;
    if ( !(unsigned int)sysfs_create_group(a1 + 16, &slc_perfmon_group) )
    {
      *(_QWORD *)(a1 + 168) = v7;
      dev_info(a1 + 16, "Module inserted successfully.\n");
      result = 0;
      goto LABEL_74;
    }
    dev_err(a1 + 16, "Unable to create sysfs group.\n");
LABEL_71:
    result = 4294967274LL;
  }
LABEL_74:
  _ReadStatusReg(SP_EL0);
  return result;
}
