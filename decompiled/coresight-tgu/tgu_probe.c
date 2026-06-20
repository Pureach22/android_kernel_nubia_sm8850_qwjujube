unsigned __int64 __fastcall tgu_probe(_QWORD *a1)
{
  unsigned __int64 result; // x0
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x9
  unsigned __int64 v13; // x0
  unsigned int v14; // w21
  _QWORD v15[3]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v16; // [xsp+20h] [xbp-40h]
  _QWORD *v17; // [xsp+28h] [xbp-38h]
  _UNKNOWN **v18; // [xsp+30h] [xbp-30h]
  __int64 v20; // [xsp+40h] [xbp-20h]
  __int64 v21; // [xsp+48h] [xbp-18h]
  __int64 v22; // [xsp+50h] [xbp-10h]
  __int64 v23; // [xsp+58h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v22 = 0;
  v20 = 0;
  v17 = nullptr;
  v18 = nullptr;
  v16 = 0;
  memset(v15, 0, sizeof(v15));
  if ( !coresight_alloc_device_name(&tgu_devs, a1) )
    goto LABEL_15;
  result = coresight_get_platform_data(a1);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_16;
  a1[18] = result;
  v3 = devm_kmalloc(a1, 120, 3520);
  if ( !v3 )
    goto LABEL_15;
  v4 = v3;
  *(_QWORD *)(v3 + 8) = a1;
  a1[19] = v3;
  v5 = devm_ioremap_resource(a1, a1 + 114);
  *(_QWORD *)v4 = v5;
  if ( !v5 )
    goto LABEL_15;
  v6 = a1[93];
  *(_DWORD *)(v4 + 32) = 0;
  if ( (of_property_read_variable_u32_array(v6, "tgu-steps", v4 + 36, 1, 0) & 0x80000000) != 0
    || (of_property_read_variable_u32_array(a1[93], "tgu-conditions", v4 + 40, 1, 0) & 0x80000000) != 0
    || (of_property_read_variable_u32_array(a1[93], "tgu-regs", v4 + 44, 1, 0) & 0x80000000) != 0 )
  {
    result = 4294967274LL;
    goto LABEL_16;
  }
  v7 = devm_kmalloc(a1, 4608, 3520);
  *(_QWORD *)(v4 + 56) = v7;
  if ( !v7 )
    goto LABEL_15;
  v8 = devm_kmalloc(a1, 1024, 3520);
  *(_QWORD *)(v4 + 64) = v8;
  if ( !v8
    || (v9 = devm_kmalloc(a1, 1024, 3520), (*(_QWORD *)(v4 + 72) = v9) == 0)
    || (v10 = devm_kmalloc(a1, 128, 3520), (*(_QWORD *)(v4 + 80) = v10) == 0)
    || (v11 = devm_kmalloc(a1, 128, 3520), (*(_QWORD *)(v4 + 88) = v11) == 0) )
  {
LABEL_15:
    result = 4294967284LL;
    goto LABEL_16;
  }
  v12 = a1[18];
  LODWORD(v15[0]) = 4;
  *(_BYTE *)(v4 + 116) = 0;
  v16 = v12;
  v17 = a1;
  v18 = &tgu_attr_grps;
  v13 = coresight_register(v15);
  *(_QWORD *)(v4 + 16) = v13;
  if ( v13 < 0xFFFFFFFFFFFFF001LL )
  {
    _pm_runtime_idle(a1, 4);
    result = 0;
  }
  else
  {
    v14 = v13;
    _pm_runtime_idle(a1, 4);
    result = v14;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
