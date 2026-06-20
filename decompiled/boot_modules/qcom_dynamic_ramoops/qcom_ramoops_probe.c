__int64 __fastcall qcom_ramoops_probe(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w8
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x0
  int v8; // w21
  __int64 v9; // x20
  __int64 v10; // x8
  __int64 v11; // x0
  int v12; // w0
  __int64 v13; // x0
  int v14; // w0
  unsigned int v15; // w3
  __int64 v16; // x0
  int v17; // w0
  unsigned int v18; // w3
  __int64 v19; // x0
  int v20; // w0
  unsigned int v21; // w3
  __int64 v22; // x0
  int v23; // w0
  unsigned int v24; // w3
  __int64 v25; // x0
  int v26; // w0
  int v27; // w3
  __int64 v28; // x0
  int v29; // w0
  int v30; // w3
  unsigned __int64 v31; // x20
  unsigned int v32; // w20
  __int64 v33; // x0
  int v34; // [xsp+4h] [xbp-6Ch] BYREF
  __int64 v35; // [xsp+8h] [xbp-68h] BYREF
  __int64 v36; // [xsp+10h] [xbp-60h]
  __int64 v37; // [xsp+18h] [xbp-58h]
  const char *v38; // [xsp+20h] [xbp-50h]
  _QWORD v39[3]; // [xsp+28h] [xbp-48h] BYREF
  __int64 v40; // [xsp+40h] [xbp-30h]
  __int64 v41; // [xsp+48h] [xbp-28h]
  __int64 v42; // [xsp+50h] [xbp-20h]
  __int64 v43; // [xsp+58h] [xbp-18h]
  __int64 v44; // [xsp+60h] [xbp-10h]
  __int64 v45; // [xsp+68h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v34 = 0;
  v41 = 0;
  v42 = 0;
  v40 = 0;
  memset(v39, 0, sizeof(v39));
  v37 = 0;
  v38 = nullptr;
  v35 = 0;
  v36 = 0;
  v3 = _of_parse_phandle_with_args(v2, "memory-region", 0, 0, 0, &v35);
  result = 4294967277LL;
  if ( v3 || !v35 )
    goto LABEL_48;
  v5 = of_reserved_mem_lookup(v35);
  if ( !v5 )
  {
    dev_err(a1 + 16, "failed to locate DT /reserved-memory resource\n");
    result = 4294967274LL;
    goto LABEL_48;
  }
  v6 = v5;
  v7 = devm_kmalloc(a1 + 16, 88, 3520);
  if ( !v7 )
  {
    result = 4294967284LL;
    goto LABEL_48;
  }
  v8 = 2;
  v9 = v7;
  *(_QWORD *)v7 = *(_QWORD *)(v6 + 32);
  v10 = *(_QWORD *)(v6 + 24);
  *(_DWORD *)(v7 + 56) = 1;
  *(_DWORD *)(v7 + 16) = 2;
  v11 = *(_QWORD *)(a1 + 760);
  *(_QWORD *)(v9 + 8) = v10;
  LODWORD(v35) = 0;
  v12 = of_property_read_variable_u32_array(v11, "mem-type", &v35, 1, 0);
  if ( v12 != -22 )
  {
    if ( v12 < 0 )
    {
      v32 = v12 & (v12 >> 31);
LABEL_45:
      dev_err(a1 + 16, "failed to parse property %s: %d\n");
      result = v32;
      goto LABEL_48;
    }
    v8 = v35;
    if ( (v35 & 0x80000000) != 0 )
    {
      v33 = a1 + 16;
LABEL_47:
      dev_err(v33, "%s %u > INT_MAX\n");
      result = 4294967221LL;
      goto LABEL_48;
    }
  }
  v13 = *(_QWORD *)(a1 + 760);
  v34 = v8;
  LODWORD(v35) = 0;
  *(_DWORD *)(v9 + 16) = v8;
  v14 = of_property_read_variable_u32_array(v13, "record-size", &v35, 1, 0);
  v15 = 0;
  if ( v14 == -22 )
    goto LABEL_11;
  if ( v14 < 0 )
  {
    v32 = v14 & (v14 >> 31);
    goto LABEL_45;
  }
  v15 = v35;
  if ( (v35 & 0x80000000) != 0 )
    goto LABEL_46;
LABEL_11:
  v16 = *(_QWORD *)(a1 + 760);
  *(_QWORD *)(v9 + 24) = v15;
  LODWORD(v35) = 0;
  v17 = of_property_read_variable_u32_array(v16, "console-size", &v35, 1, 0);
  v18 = 0;
  if ( v17 == -22 )
    goto LABEL_14;
  if ( v17 < 0 )
  {
    v32 = v17 & (v17 >> 31);
    goto LABEL_45;
  }
  v18 = v35;
  if ( (v35 & 0x80000000) != 0 )
    goto LABEL_46;
LABEL_14:
  v19 = *(_QWORD *)(a1 + 760);
  v34 = v18;
  LODWORD(v35) = 0;
  *(_QWORD *)(v9 + 32) = v18;
  v20 = of_property_read_variable_u32_array(v19, "ftrace-size", &v35, 1, 0);
  v21 = 0;
  if ( v20 == -22 )
    goto LABEL_17;
  if ( v20 < 0 )
  {
    v32 = v20 & (v20 >> 31);
    goto LABEL_45;
  }
  v21 = v35;
  if ( (v35 & 0x80000000) != 0 )
    goto LABEL_46;
LABEL_17:
  v22 = *(_QWORD *)(a1 + 760);
  *(_QWORD *)(v9 + 40) = v21;
  LODWORD(v35) = 0;
  v23 = of_property_read_variable_u32_array(v22, "pmsg-size", &v35, 1, 0);
  v24 = 0;
  if ( v23 == -22 )
    goto LABEL_20;
  if ( v23 < 0 )
  {
    v32 = v23 & (v23 >> 31);
    goto LABEL_45;
  }
  v24 = v35;
  if ( (v35 & 0x80000000) != 0 )
    goto LABEL_46;
LABEL_20:
  v25 = *(_QWORD *)(a1 + 760);
  v34 = v24;
  LODWORD(v35) = 0;
  *(_QWORD *)(v9 + 48) = v24;
  v26 = of_property_read_variable_u32_array(v25, "ecc-size", &v35, 1, 0);
  v27 = 0;
  if ( v26 == -22 )
    goto LABEL_23;
  if ( v26 < 0 )
  {
    v32 = v26 & (v26 >> 31);
    goto LABEL_45;
  }
  v27 = v35;
  if ( (v35 & 0x80000000) != 0 )
  {
LABEL_46:
    v33 = a1 + 16;
    goto LABEL_47;
  }
LABEL_23:
  v28 = *(_QWORD *)(a1 + 760);
  *(_DWORD *)(v9 + 68) = v27;
  LODWORD(v35) = 0;
  v29 = of_property_read_variable_u32_array(v28, "flags", &v35, 1, 0);
  v30 = 0;
  if ( v29 == -22 )
    goto LABEL_26;
  if ( v29 < 0 )
  {
    v32 = v29 & (v29 >> 31);
    goto LABEL_45;
  }
  v30 = v35;
  if ( (v35 & 0x80000000) != 0 )
    goto LABEL_46;
LABEL_26:
  v34 = v30;
  *(_DWORD *)(v9 + 60) = v30;
  result = ramoops_parse_dt_u32(a1, "max-reason", 1, &v34);
  if ( (result & 0x80000000) == 0 )
  {
    v35 = 0;
    v36 = 0;
    *(_QWORD *)((char *)v39 + 4) = 0;
    *(_DWORD *)(v9 + 56) = v34;
    v37 = 0;
    v38 = "qcom-ramoops";
    LODWORD(v39[0]) = -1;
    *(_QWORD *)((char *)&v39[1] + 4) = 0;
    HIDWORD(v39[2]) = 0;
    v40 = v9;
    v41 = 88;
    v42 = 0;
    v43 = 0;
    v44 = 0;
    v31 = platform_device_register_full(&v35);
    if ( v31 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(a1 + 16, "could not create platform device: %ld\n", v31);
      result = (unsigned int)v31;
      v31 = 0;
    }
    else
    {
      result = 0;
    }
    *(_QWORD *)(a1 + 168) = v31;
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
