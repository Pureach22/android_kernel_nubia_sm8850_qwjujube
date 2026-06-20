__int64 __fastcall cam_ife_csid_ver2_drv_config(__int64 a1, __int64 a2)
{
  int v3; // w22
  __int64 v5; // x23
  __int64 v6; // x24
  __int64 v7; // x8
  int v8; // w25
  __int64 v9; // x9
  __int64 result; // x0
  unsigned int v11; // w21
  const char *v12; // x5
  __int64 v13; // x6
  __int64 v14; // x4
  int v15; // w9
  int v16; // w10
  unsigned int *v17; // x8
  unsigned int v18; // w9
  int v19; // w22
  const char *v20; // x8
  const char *v21; // x7
  const char *v22; // x9
  const char *v23; // x7

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_drv_config",
      8928,
      "Invalid params");
    return 4294967274LL;
  }
  v3 = *(unsigned __int8 *)(a2 + 1);
  v5 = **(_QWORD **)(a1 + 31136);
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 31128) + 384LL);
  v7 = *(_QWORD *)(v5 + 120);
  v8 = *(_DWORD *)(v7 + 468);
  if ( *(_BYTE *)a2 != 1 )
  {
    if ( (*(_BYTE *)(a1 + 32252) & 1) != 0 )
    {
      v11 = 0;
      goto LABEL_15;
    }
    v12 = "CSID:%u Failed to update drv config, init config not done";
    v13 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
    v14 = 8963;
    goto LABEL_11;
  }
  if ( *(_DWORD *)(a1 + 768) <= 1u )
  {
    if ( *(_DWORD *)(a1 + 8) > 1u )
    {
      v9 = 600;
      goto LABEL_14;
    }
    if ( *(_DWORD *)(a1 + 920) > 1u )
    {
      v9 = 624;
      goto LABEL_14;
    }
    v12 = "CSID:%u Failed to configure rup_en for drv";
    v13 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
    v14 = 8953;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_drv_config",
      v14,
      v12,
      v13);
    return 4294967274LL;
  }
  v9 = 620;
LABEL_14:
  v11 = *(_DWORD *)(v7 + v9);
  cam_io_w_mb(v11, v6 + *(unsigned int *)(v7 + 112));
  *(_BYTE *)(a1 + 32252) = 1;
LABEL_15:
  v15 = *(_DWORD *)(a2 + 8);
  v16 = v3 << v8;
  v17 = *(unsigned int **)(v5 + 120);
  if ( (v15 & 1) != 0 )
  {
    v16 |= v17[162];
    if ( (v15 & 2) != 0 )
    {
LABEL_17:
      v16 |= v17[163];
      if ( (v15 & 4) != 0 )
        goto LABEL_18;
      goto LABEL_26;
    }
  }
  else if ( (v15 & 2) != 0 )
  {
    goto LABEL_17;
  }
  if ( (v15 & 4) != 0 )
  {
LABEL_18:
    v16 |= v17[164];
    if ( (v15 & 8) != 0 )
      goto LABEL_19;
    goto LABEL_27;
  }
LABEL_26:
  if ( (v15 & 8) != 0 )
  {
LABEL_19:
    v16 |= v17[165];
    if ( (v15 & 0x10) != 0 )
      goto LABEL_20;
    goto LABEL_28;
  }
LABEL_27:
  if ( (v15 & 0x10) != 0 )
  {
LABEL_20:
    v16 |= v17[166];
    if ( (v15 & 0x20) != 0 )
      goto LABEL_21;
    goto LABEL_29;
  }
LABEL_28:
  if ( (v15 & 0x20) != 0 )
  {
LABEL_21:
    v16 |= v17[167];
    if ( (v15 & 0x40) != 0 )
      goto LABEL_22;
LABEL_30:
    if ( (v15 & 0x80) != 0 )
      goto LABEL_23;
LABEL_31:
    v18 = 0;
    goto LABEL_32;
  }
LABEL_29:
  if ( (v15 & 0x40) == 0 )
    goto LABEL_30;
LABEL_22:
  v16 |= v17[168];
  if ( (v15 & 0x80) == 0 )
    goto LABEL_31;
LABEL_23:
  v18 = v17[169];
LABEL_32:
  v19 = v18 | v16;
  cam_io_w_mb(v18 | v16, v6 + v17[27]);
  cam_io_w_mb(*(unsigned int *)(a2 + 4), v6 + *(unsigned int *)(*(_QWORD *)(v5 + 120) + 116LL));
  if ( debug_drv )
  {
    v20 = "Y";
    if ( *(_BYTE *)(a1 + 2160) )
      v21 = "Y";
    else
      v21 = "N";
    if ( !*(_BYTE *)a2 )
      v20 = "N";
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, const char *, const char *, int, unsigned int, _DWORD))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_csid_ver2_drv_config",
      8980,
      "CSID[%u] sfe_en:%s DRV config init_req:%s cfg0_val:0x%x cfg1_val:0x%x cfg2_val:0x%x",
      *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL),
      v21,
      v20,
      v19,
      v11,
      *(_DWORD *)(a2 + 4));
  }
  result = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v22 = "Y";
    if ( *(_BYTE *)(a1 + 2160) )
      v23 = "Y";
    else
      v23 = "N";
    if ( !*(_BYTE *)a2 )
      v22 = "N";
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, const char *, const char *, int, unsigned int, _DWORD))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_drv_config",
      8986,
      "CSID[%u] sfe_en:%s DRV config init_req:%s cfg0_val:0x%x cfg1_val:0x%x cfg2_val:0x%x",
      *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL),
      v23,
      v22,
      v19,
      v11,
      *(_DWORD *)(a2 + 4));
    return 0;
  }
  return result;
}
