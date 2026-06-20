__int64 __fastcall a6xx_load_pdc_ucode(__int64 a1)
{
  __int64 v2; // x25
  __int64 v3; // x27
  int addr; // w19
  int v5; // w21
  int v6; // w23
  int v7; // w0
  int v8; // w24
  _BOOL4 v9; // w8
  __int64 v10; // x19
  __int64 v11; // x28
  _QWORD *resource_byname; // x26
  __int64 *v13; // x0
  __int64 v14; // x22
  __int64 v15; // x1
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x2
  __int64 result; // x0
  _DWORD *v20; // x0
  __int64 *v21; // x0
  __int64 v22; // x1
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x2
  int *v26; // x8
  int v27; // w19
  unsigned int v28; // w9
  const char *v29; // x0
  int v30; // [xsp+Ch] [xbp-4h]

  v2 = *(_QWORD *)(a1 + 1544);
  v3 = *(_QWORD *)(a1 + 14264);
  addr = cmd_db_read_addr("vrm.soc");
  v5 = cmd_db_read_addr("xo.lvl");
  v6 = cmd_db_read_addr("cx.lvl");
  v7 = cmd_db_read_addr("mx.lvl");
  if ( !v5 )
  {
    dev_err(v2 + 16, "Failed to get 'xo.lvl' addr from cmd_db\n");
    return 4294967294LL;
  }
  if ( !v6 )
  {
    dev_err(v2 + 16, "Failed to get 'cx.lvl' addr from cmd_db\n");
    return 4294967294LL;
  }
  v8 = v7;
  if ( !v7 )
  {
    dev_err(v2 + 16, "Failed to get 'mx.lvl' addr from cmd_db\n");
    return 4294967294LL;
  }
  v30 = addr;
  v9 = **(_DWORD **)(a1 + 14264) == 640 && *(unsigned __int8 *)(a1 + 14248) == 1;
  if ( v9 )
    v10 = 589824;
  else
    v10 = 0x80000;
  if ( v9 )
    v11 = 2686976;
  else
    v11 = 2621440;
  resource_byname = (_QWORD *)platform_get_resource_byname(v2, 512, "kgsl_gmu_pdc_reg");
  v13 = (__int64 *)platform_get_resource_byname(v2, 512, "kgsl_gmu_pdc_cfg");
  v14 = *(_QWORD *)(a1 - 224);
  if ( !v14 )
  {
    if ( v13 )
    {
      v15 = *v13;
      v16 = v13[1];
      v17 = v2 + 16;
      v18 = v16 - v15 + 1;
    }
    else
    {
      if ( !resource_byname )
        goto LABEL_49;
      v17 = v2 + 16;
      v18 = 0x10000;
      v15 = *resource_byname + v10;
    }
    v14 = devm_ioremap(v17, v15, v18);
    *(_QWORD *)(a1 - 224) = v14;
    if ( v14 )
      goto LABEL_19;
LABEL_49:
    dev_err(v2 + 16, "Failed to map PDC CFG\n");
    return 4294967277LL;
  }
LABEL_19:
  if ( **(_DWORD **)(a1 + 14264) == 622 && (*(_BYTE *)(v3 + 157) & 1) != 0 )
    return 0;
  if ( (*(_BYTE *)(v3 + 157) & 1) != 0 )
    goto LABEL_42;
  v20 = *(_DWORD **)(a1 - 216);
  if ( !v20 )
  {
    v21 = (__int64 *)platform_get_resource_byname(v2, 512, "kgsl_gmu_pdc_seq");
    if ( v21 )
    {
      v22 = *v21;
      v23 = v21[1];
      v24 = v2 + 16;
      v25 = v23 - v22 + 1;
      goto LABEL_32;
    }
    if ( resource_byname )
    {
      v24 = v2 + 16;
      v25 = 0x10000;
      v22 = *resource_byname + v11;
LABEL_32:
      v20 = (_DWORD *)devm_ioremap(v24, v22, v25);
      *(_QWORD *)(a1 - 216) = v20;
      if ( v20 )
        goto LABEL_33;
      goto LABEL_51;
    }
    v20 = *(_DWORD **)(a1 - 216);
    if ( !v20 )
    {
LABEL_51:
      dev_err(v2 + 16, "Failed to map PDC SEQ\n");
      return 4294967277LL;
    }
  }
LABEL_33:
  *v20 = -21061151;
  v20[1] = -1515936862;
  v20[2] = -2088589600;
  v20[3] = -1125916028;
  v20[4] = 2130428;
  *(_DWORD *)(v14 + 21964) = 7;
  *(_DWORD *)(v14 + 21968) = 0;
  *(_DWORD *)(v14 + 21960) = 0;
  *(_DWORD *)(v14 + 21972) = 65800;
  *(_DWORD *)(v14 + 21976) = v8;
  *(_DWORD *)(v14 + 21980) = 1;
  *(_DWORD *)(v14 + 21988) = 65800;
  *(_DWORD *)(v14 + 21992) = v6;
  *(_DWORD *)(v14 + 21996) = 0;
  *(_DWORD *)(v14 + 22004) = 65800;
  *(_DWORD *)(v14 + 22008) = v5;
  *(_DWORD *)(v14 + 22012) = 0;
  if ( v30 && (unsigned int)(**(_DWORD **)(a1 + 14264) - 620) <= 2 )
  {
    *(_DWORD *)(v14 + 22020) = 65800;
    *(_QWORD *)(v14 + 22024) = (unsigned int)(v30 + 4);
  }
  *(_DWORD *)(v14 + 22364) = 7;
  *(_DWORD *)(v14 + 22368) = 0;
  *(_DWORD *)(v14 + 22360) = 0;
  *(_DWORD *)(v14 + 22372) = 65800;
  *(_DWORD *)(v14 + 22376) = v8;
  *(_DWORD *)(v14 + 22380) = 2;
  *(_DWORD *)(v14 + 22388) = 65800;
  *(_DWORD *)(v14 + 22392) = v6;
  v26 = *(int **)(a1 + 14264);
  v27 = *v26;
  v28 = *v26 - 618;
  if ( v28 <= 0x2A && ((1LL << v28) & 0x40100000007LL) != 0
    || (v29 = *((const char **)v26 + 3)) != nullptr && !strcmp(v29, "qcom,adreno-gpu-a642l")
    || (unsigned int)(v27 - 621) <= 0x2A && ((1LL << ((unsigned __int8)v27 - 109)) & 0x60000400003LL) != 0 )
  {
    *(_DWORD *)(v14 + 22396) = 2;
  }
  else
  {
    *(_DWORD *)(v14 + 22396) = 3;
  }
  *(_DWORD *)(v14 + 22404) = 65800;
  *(_DWORD *)(v14 + 22408) = v5;
  *(_DWORD *)(v14 + 22412) = 3;
  if ( v30 )
  {
    if ( (unsigned int)(**(_DWORD **)(a1 + 14264) - 620) <= 2 )
    {
      *(_DWORD *)(v14 + 22420) = 65800;
      *(_DWORD *)(v14 + 22424) = v30 + 4;
      *(_DWORD *)(v14 + 22428) = 1;
    }
  }
LABEL_42:
  result = 0;
  *(_DWORD *)(v14 + 17696) = 0;
  *(_DWORD *)(v14 + 17664) = -2147483647;
  __dsb(0xEu);
  return result;
}
