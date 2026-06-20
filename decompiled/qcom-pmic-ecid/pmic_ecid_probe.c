__int64 __fastcall pmic_ecid_probe(_QWORD *a1)
{
  unsigned __int64 v1; // x19
  __int64 v3; // x0
  _QWORD *v4; // x21
  __int64 regmap; // x0
  __int64 v6; // x22
  int v7; // w0
  unsigned int v8; // w0
  unsigned int v9; // w0
  const char **v10; // x8
  const char *v11; // x3
  __int64 result; // x0
  __int64 v13; // x1
  const char *v14; // x2
  const char **v15; // x8
  const char *v16; // x3
  unsigned __int64 v17; // x0
  unsigned int v18; // w0
  unsigned int v19; // w22
  unsigned int v20; // w0
  unsigned int v21; // w20
  int v22; // [xsp+Ch] [xbp-44h] BYREF
  const char *v23; // [xsp+10h] [xbp-40h] BYREF
  _QWORD v24[4]; // [xsp+18h] [xbp-38h] BYREF
  unsigned __int64 v25; // [xsp+38h] [xbp-18h] BYREF
  unsigned int v26; // [xsp+40h] [xbp-10h]
  __int64 v27; // [xsp+48h] [xbp-8h]

  v1 = (unsigned __int64)(a1 + 2);
  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v25 = 0;
  v23 = nullptr;
  memset(v24, 0, sizeof(v24));
  v22 = 0;
  v3 = devm_kmalloc(a1 + 2, 48, 3520);
  if ( v3 )
  {
    v4 = (_QWORD *)v3;
    regmap = dev_get_regmap(a1[14], 0);
    if ( !regmap )
    {
      dev_err(v1, "Couldn't get parent's regmap\n");
      result = 4294967277LL;
      goto LABEL_23;
    }
    v6 = regmap;
    v7 = ida_alloc_range(&pmic_ecid_dev_ida, 0, 0xFFFFFFFFLL, 3264);
    *((_DWORD *)v4 + 10) = v7;
    if ( v7 < 0 )
    {
      v21 = v7;
      dev_err(v1, "ida_alloc failed: %d\n", v7);
      result = v21;
      goto LABEL_23;
    }
    v8 = of_property_read_variable_u32_array(a1[95], "reg", &v22, 1, 0);
    if ( (v8 & 0x80000000) != 0 )
    {
      v13 = v8;
      v14 = "Couldn't find reg in node\n";
    }
    else
    {
      if ( !of_find_property(a1[95], "qcom,pmic-name", 0) )
      {
        v15 = (const char **)a1[14];
        v16 = v15[14];
        if ( !v16 )
          v16 = *v15;
        scnprintf(v24, 32, "%s", v16);
LABEL_15:
        *v4 = device_create(&pmic_ecid_class, 0, *((unsigned int *)v4 + 10), v4, "%s", (const char *)v24);
        if ( v1 < 0xFFFFFFFFFFFFF001LL )
        {
          v18 = regmap_bulk_read(v6, (unsigned int)(v22 + 243), &v25, 12);
          if ( v18 )
          {
            v19 = v18;
            device_remove_file(*v4, &dev_attr_ecid);
            device_destroy(&pmic_ecid_class, *((unsigned int *)v4 + 10));
            v14 = "Failed to read the ECID\n";
          }
          else
          {
            v20 = scnprintf(v4 + 1, 32, "0x%016llx%08x", bswap64(v25), bswap32(v26));
            if ( v20 )
              v19 = v20;
            else
              v19 = -22;
            if ( (v19 & 0x80000000) == 0 )
            {
              result = 0;
              a1[21] = v4;
              goto LABEL_23;
            }
            device_remove_file(*v4, &dev_attr_ecid);
            device_destroy(&pmic_ecid_class, *((unsigned int *)v4 + 10));
            v14 = "Failed to store the ecid info\n";
          }
          v17 = v1;
          v13 = v19;
        }
        else
        {
          v14 = "Failed to create qcom-pmic-ecid device\n";
          v17 = v1;
          v13 = (unsigned int)v1;
        }
        goto LABEL_22;
      }
      v9 = of_property_read_string(a1[95], "qcom,pmic-name", &v23);
      if ( (v9 & 0x80000000) == 0 )
      {
        v10 = (const char **)a1[14];
        v11 = v10[14];
        if ( !v11 )
          v11 = *v10;
        scnprintf(v24, 32, "%s:%s", v11, v23);
        goto LABEL_15;
      }
      v13 = v9;
      v14 = "Couldn't find pmic-name in node\n";
    }
    v17 = v1;
LABEL_22:
    result = dev_err_probe(v17, v13, v14);
    goto LABEL_23;
  }
  result = 4294967284LL;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
