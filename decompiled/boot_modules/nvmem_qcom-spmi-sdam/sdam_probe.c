__int64 __fastcall sdam_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 regmap; // x0
  int v6; // w9
  unsigned __int64 v7; // x0
  __int64 result; // x0
  const char *v9; // x1
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v1 = a1 + 16;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  v3 = devm_kmalloc(a1 + 16, 168, 3520);
  if ( !v3 )
  {
    result = 4294967284LL;
    goto LABEL_8;
  }
  v4 = v3;
  regmap = dev_get_regmap(*(_QWORD *)(a1 + 112), 0);
  *(_QWORD *)v4 = regmap;
  if ( !regmap )
  {
    dev_err(v1, "Failed to get regmap handle\n");
LABEL_14:
    result = 4294967290LL;
    goto LABEL_8;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "reg", v4 + 160, 1, 0) & 0x80000000) != 0 )
  {
    v9 = "Failed to get SDAM base, rc=%d\n";
LABEL_12:
    dev_err(v1, v9);
    result = 4294967274LL;
    goto LABEL_8;
  }
  if ( (regmap_read(*(_QWORD *)v4, (unsigned int)(*(_DWORD *)(v4 + 160) + 68), &v10) & 0x80000000) != 0 )
  {
    v9 = "Failed to read SDAM_SIZE rc=%d\n";
    goto LABEL_12;
  }
  v6 = v10;
  *(_QWORD *)(v4 + 16) = "spmi_sdam";
  *(_DWORD *)(v4 + 24) = -2;
  *(_QWORD *)(v4 + 32) = &_this_module;
  *(_BYTE *)(v4 + 52) = 1;
  *(_DWORD *)(v4 + 164) = 32 * v6;
  *(_QWORD *)(v4 + 124) = 0x100000001LL;
  *(_QWORD *)(v4 + 8) = v1;
  *(_QWORD *)(v4 + 104) = sdam_read;
  *(_QWORD *)(v4 + 112) = sdam_write;
  *(_QWORD *)(v4 + 136) = v4;
  v7 = devm_nvmem_register(v1, v4 + 8);
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v1, "Failed to register SDAM nvmem device rc=%ld\n", v7);
    goto LABEL_14;
  }
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
