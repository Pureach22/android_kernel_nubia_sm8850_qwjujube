unsigned __int64 __fastcall qcusb_emu_phy_probe(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *v3; // x0
  _QWORD *v4; // x20
  __int64 resource; // x0
  unsigned __int64 result; // x0
  __int64 v7; // x0
  char v8; // w9
  int v9; // w8
  __int64 variable_u32_array; // x0
  unsigned __int64 v11; // x8
  const char *v12; // x1
  unsigned __int64 v13; // x20
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v1 = a1 + 16;
  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v3 = (_QWORD *)devm_kmalloc(a1 + 16, 408, 3520);
  if ( !v3 )
    goto LABEL_12;
  v4 = v3;
  *v3 = v1;
  resource = platform_get_resource(a1, 512, 0);
  result = devm_ioremap_resource(v1, resource);
  v4[47] = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_13;
  of_get_property(*(_QWORD *)(a1 + 760), "qcom,emu-init-seq", &v14);
  if ( !v14 )
  {
    v12 = "emu-init-seq not specified\n";
LABEL_16:
    dev_err(v1, v12);
    result = 4294967274LL;
    goto LABEL_13;
  }
  v7 = devm_kmalloc(v1, v14, 3520);
  v4[49] = v7;
  if ( !v7 )
  {
LABEL_12:
    result = 4294967284LL;
    goto LABEL_13;
  }
  v8 = v14;
  v9 = v14 >> 2;
  *((_DWORD *)v4 + 100) = v14 >> 2;
  if ( (v8 & 4) != 0 )
  {
    v12 = "invalid emu_init_seq_len, must be in <data,addr> pairs\n";
    goto LABEL_16;
  }
  variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,emu-init-seq", v7, v9, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v13 = variable_u32_array;
    dev_err(v1, "could not read emu-init-seq, returned %d\n", variable_u32_array);
    result = v13;
  }
  else
  {
    v4[1] = "qcom-usb-emu-phy";
    v4[33] = qcusb_emu_phy_init;
    *(_QWORD *)(a1 + 168) = v4;
    *((_DWORD *)v4 + 5) = 1;
    result = usb_add_phy_dev(v4);
    if ( !(_DWORD)result )
    {
      result = platform_get_resource_byname(a1, 512, "qscratch_base");
      if ( result )
      {
        v11 = devm_ioremap(v1);
        result = 0;
        if ( v11 > 0xFFFFFFFFFFFFF000LL )
          v11 = 0;
        v4[48] = v11;
      }
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
