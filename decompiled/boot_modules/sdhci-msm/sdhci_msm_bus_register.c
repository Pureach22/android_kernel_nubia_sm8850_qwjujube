__int64 __fastcall sdhci_msm_bus_register(__int64 a1, __int64 a2)
{
  __int64 v3; // x24
  __int64 v4; // x0
  __int64 v5; // x20
  int array; // w0
  unsigned int string; // w0
  unsigned int variable_u32_array; // w0
  unsigned __int64 v9; // x22
  __int64 v10; // x0
  __int64 v11; // x23
  unsigned int v12; // w0
  __int64 property; // x0
  unsigned int v14; // w8
  __int64 v15; // x24
  int v16; // w26
  unsigned int v17; // w27
  unsigned __int64 v18; // x21
  unsigned __int64 v19; // x28
  unsigned __int64 v20; // x25
  __int64 v21; // x0
  int v22; // w9
  __int64 v23; // x10
  unsigned __int64 v24; // x11
  unsigned __int64 v25; // x13
  unsigned int v26; // w12
  unsigned __int64 v27; // x0
  unsigned __int64 v28; // x0
  __int64 result; // x0
  int v31; // [xsp+10h] [xbp-10h] BYREF
  int v32; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 760);
  v32 = 0;
  v31 = 0;
  if ( !a2 )
  {
    dev_err(16, "Null platform device!\n");
    goto LABEL_35;
  }
  v4 = devm_kmalloc(a2 + 16, 64, 3520);
  if ( !v4 )
    goto LABEL_35;
  v5 = v4;
  array = sdhci_msm_dt_get_array(a2 + 16, "qcom,bus-bw-vectors-bps", (__int64 *)(v5 + 24), (int *)(v5 + 32));
  if ( array )
  {
    if ( array == -22 )
      *(_BYTE *)(a1 + 233) = 1;
    goto LABEL_35;
  }
  string = of_property_read_string(v3, "qcom,msm-bus,name", v5);
  if ( string )
  {
    dev_err(a2 + 16, "Bus name missing err:(%d)\n", string);
    goto LABEL_35;
  }
  variable_u32_array = of_property_read_variable_u32_array(v3, "qcom,msm-bus,num-cases", v5 + 8, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    dev_err(a2 + 16, "num-usecases not found err:(%d)\n", variable_u32_array);
    goto LABEL_35;
  }
  v9 = 16LL * *(unsigned int *)(v5 + 8);
  v10 = devm_kmalloc(a2 + 16, v9, 3520);
  if ( !v10 )
  {
LABEL_35:
    dev_err(a2 + 16, "Failed to get bus_scale data\n");
    result = 4294967274LL;
    goto LABEL_36;
  }
  v11 = v10;
  v12 = of_property_read_variable_u32_array(v3, "qcom,msm-bus,num-paths", &v32, 1, 0);
  if ( (v12 & 0x80000000) != 0 )
  {
    dev_err(a2 + 16, "num_paths not found err:(%d)\n", v12);
    goto LABEL_35;
  }
  property = of_get_property(v3, "qcom,msm-bus,vectors-KBps", &v31);
  if ( !property )
  {
    dev_err(a2 + 16, "Vector array not found\n");
    goto LABEL_35;
  }
  if ( *(_DWORD *)(v5 + 8) )
  {
    v14 = v32;
    v15 = property;
    v16 = 0;
    v17 = 0;
    while ( 1 )
    {
      v18 = 16LL * (int)v17;
      if ( v9 <= v18 )
        goto LABEL_41;
      v19 = v11 + v18;
      *(_DWORD *)(v11 + 16LL * (int)v17) = v14;
      if ( (v14 & 0x80000000) != 0 )
        break;
      v20 = 16LL * v14;
      v21 = devm_kmalloc(a2 + 16, v20, 3520);
      if ( v9 < (v18 | 8) )
        goto LABEL_41;
      *(_QWORD *)(v19 + 8) = v21;
      if ( !v21 )
        goto LABEL_35;
      v14 = v32;
      if ( v32 >= 1 )
      {
        v22 = v32 * v16;
        v23 = 16LL * (unsigned int)v32;
        v24 = 0;
        while ( v20 != v24 )
        {
          if ( v20 <= v24 )
            break;
          *(_QWORD *)(v21 + v24) = bswap32(*(_DWORD *)(v15 + 4LL * v22));
          if ( v20 < v24 + 8 )
            break;
          v25 = v21 + v24;
          v24 += 16LL;
          v26 = *(_DWORD *)(v15 + 4LL * (v22 + 1));
          v22 += 2;
          *(_QWORD *)(v25 + 8) = bswap32(v26);
          if ( v23 == v24 )
            goto LABEL_11;
        }
LABEL_41:
        __break(1u);
      }
LABEL_11:
      ++v17;
      v16 += 2;
      if ( v17 >= *(_DWORD *)(v5 + 8) )
        goto LABEL_23;
    }
    if ( v9 < (v18 | 8) )
      goto LABEL_41;
    *(_QWORD *)(v19 + 8) = 0;
    goto LABEL_35;
  }
LABEL_23:
  *(_QWORD *)(v5 + 16) = v11;
  *(_QWORD *)(a1 + 240) = v5;
  v27 = of_icc_get(a2 + 16, "sdhc-ddr");
  *(_QWORD *)(v5 + 40) = v27;
  if ( !v27 || v27 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_info(a2 + 16, "(%ld): failed getting %s path\n", v27, "sdhc-ddr");
    *(_QWORD *)(v5 + 40) = 0;
  }
  v28 = of_icc_get(a2 + 16, "cpu-sdhc");
  *(_QWORD *)(v5 + 48) = v28;
  if ( v28 && v28 < 0xFFFFFFFFFFFFF001LL )
  {
    result = 0;
  }
  else
  {
    dev_info(a2 + 16, "(%ld): failed getting %s path\n", v28, "cpu-sdhc");
    result = 0;
    *(_QWORD *)(v5 + 48) = 0;
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
