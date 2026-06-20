unsigned __int64 __fastcall qfprom_probe(__int64 a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x20
  unsigned __int64 result; // x0
  int v5; // w9
  int v6; // w8
  __int64 match_data; // x0
  __int64 resource; // x0
  unsigned int v9; // w0
  int v10; // w8
  void *v11; // x8
  unsigned __int64 optional; // x0
  __int64 v13; // x0
  unsigned __int64 v14; // x20
  int *v15; // [xsp+8h] [xbp-A8h] BYREF
  _QWORD dest[20]; // [xsp+10h] [xbp-A0h] BYREF

  dest[19] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memcpy(dest, &unk_74C0, 0x98u);
  v15 = nullptr;
  v2 = devm_kmalloc(a1 + 16, 64, 3520);
  if ( !v2 )
  {
    result = 4294967284LL;
    goto LABEL_29;
  }
  v3 = (_QWORD *)v2;
  result = devm_platform_get_and_ioremap_resource(a1, 0, &v15);
  v3[2] = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v5 = v15[2];
    v6 = *v15;
    dest[0] = a1 + 16;
    dest[16] = v3;
    v3[4] = a1 + 16;
    LODWORD(dest[14]) = v5 - v6 + 1;
    match_data = device_get_match_data(a1 + 16);
    if ( match_data )
    {
      dest[7] = *(_QWORD *)match_data;
      LODWORD(dest[8]) = *(_DWORD *)(match_data + 8);
    }
    resource = platform_get_resource(a1, 512, 1);
    v15 = (int *)resource;
    if ( !resource )
    {
LABEL_24:
      pm_runtime_enable(a1 + 16);
      v13 = _devm_add_action(a1 + 16, qfprom_runtime_disable, a1 + 16, "qfprom_runtime_disable");
      if ( (_DWORD)v13 )
      {
        v14 = v13;
        _pm_runtime_disable(a1 + 16, 1);
        result = v14;
      }
      else
      {
        result = devm_nvmem_register(a1 + 16, dest);
        if ( result <= 0xFFFFFFFFFFFFF000LL )
          result = 0;
        else
          result = (unsigned int)result;
      }
      goto LABEL_29;
    }
    result = devm_ioremap_resource(a1 + 16, resource);
    *v3 = result;
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      result = devm_platform_ioremap_resource(a1, 2);
      v3[1] = result;
      if ( result < 0xFFFFFFFFFFFFF001LL )
      {
        result = devm_platform_ioremap_resource(a1, 3);
        v3[3] = result;
        if ( result < 0xFFFFFFFFFFFFF001LL )
        {
          v9 = readl();
          v10 = HIWORD(v9) & 0xFFF;
          if ( (v9 & 0xF0000000) == 0x70000000 && v10 == 8 )
          {
            v11 = &qfprom_7_8_data;
          }
          else
          {
            if ( (v9 & 0xF0000000) != 0x70000000 || v10 != 15 )
              goto LABEL_17;
            v11 = &qfprom_7_15_data;
          }
          v3[7] = v11;
LABEL_17:
          result = devm_regulator_get(a1 + 16, "vcc");
          v3[6] = result;
          if ( result >= 0xFFFFFFFFFFFFF001LL )
            goto LABEL_29;
          optional = devm_clk_get_optional(a1 + 16, "core");
          v3[5] = optional;
          if ( optional >= 0xFFFFFFFFFFFFF001LL )
          {
            result = dev_err_probe(a1 + 16, optional, "Error getting clock\n");
            goto LABEL_29;
          }
          if ( optional && v3[7] )
            dest[13] = qfprom_reg_write;
          goto LABEL_24;
        }
      }
    }
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
