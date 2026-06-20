__int64 __fastcall perfmon_filter_configure_store(__int64 a1, __int64 a2, char *a3, __int64 a4)
{
  __int64 v6; // x26
  unsigned int v7; // w21
  char *v8; // x0
  const char *v9; // x22
  unsigned int v10; // w23
  size_t v11; // x0
  unsigned __int64 v12; // x2
  char *v13; // x0
  char *v14; // x0
  char v15; // w22
  char v16; // w24
  char *v17; // x0
  char *v18; // x25
  int v19; // w28
  __int64 v20; // x9
  void *v21; // x0
  __int64 v23; // x8
  char v24; // w9
  __int64 v25; // [xsp+8h] [xbp-38h] BYREF
  __int64 v26; // [xsp+10h] [xbp-30h] BYREF
  _BYTE v27[4]; // [xsp+1Ch] [xbp-24h] BYREF
  char *stringp; // [xsp+20h] [xbp-20h] BYREF
  _QWORD v29[3]; // [xsp+28h] [xbp-18h] BYREF

  v29[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  stringp = a3;
  memset(v29, 0, 15);
  v27[0] = 0;
  v25 = 0;
  v26 = 0;
  mutex_lock(v6 + 136);
  if ( *(_BYTE *)(v6 + 132) == 1 )
  {
    dev_err(a1, "FLTR_CFG_ERR: Perfmon is already configured, try again.\n");
    a4 = -22;
    goto LABEL_47;
  }
  v7 = *(unsigned __int8 *)(*(_QWORD *)(v6 + 112) + 4LL);
  v8 = strsep(&stringp, " ");
  v9 = v8;
  if ( !v8 )
    goto LABEL_25;
  if ( !strcmp(v8, "SCID") )
  {
    v10 = 0;
  }
  else if ( !strcmp(v9, "MULTISCID") )
  {
    v10 = 7;
  }
  else if ( !strcmp(v9, "MID") )
  {
    v10 = 1;
  }
  else if ( !strcmp(v9, "PROFILING_TAG") )
  {
    v10 = 2;
  }
  else if ( !strcmp(v9, "OPCODE") )
  {
    v10 = 3;
  }
  else if ( !strcmp(v9, "CACHEALLOC") )
  {
    v10 = 4;
  }
  else if ( !strcmp(v9, "MEMTAGOPS") )
  {
    v10 = 5;
  }
  else
  {
    v10 = -1;
  }
  v11 = strnlen(v9, 0xFu);
  if ( v11 == -1 )
  {
    _fortify_panic(2, -1, 0);
    goto LABEL_63;
  }
  if ( v11 == 15 )
    v12 = 15;
  else
    v12 = v11 + 1;
  if ( v12 >= 0x10 )
LABEL_63:
    _fortify_panic(7, 15, v12);
  sized_strscpy(v29, v9);
  if ( v10 == -1 )
  {
LABEL_25:
    dev_err(a1, "FLTR_CFG_ERR: Unsupported filter %s, try again.\n", v9);
LABEL_46:
    memset(*(void **)(v6 + 8), 0, *(unsigned int *)(v6 + 44));
    v20 = *(_QWORD *)(v6 + 112);
    v21 = *(void **)(v6 + 64);
    *(_QWORD *)(v6 + 16) = *(_QWORD *)(v6 + 8);
    memset(v21, 0, 2LL * *(unsigned __int8 *)(v20 + 4));
    *(_WORD *)(v6 + 128) = 0;
    a4 = -22;
    *(_BYTE *)(v6 + 130) = 0;
    goto LABEL_47;
  }
  v13 = strsep(&stringp, " ");
  if ( !v13 )
    goto LABEL_27;
  if ( (unsigned int)kstrtoull(v13, 0, &v25) )
  {
    dev_err(a1, "FLTR_CFG_ERR: Wrong match format, try again.\n");
    goto LABEL_46;
  }
  v14 = strsep(&stringp, " ");
  if ( !v14 )
  {
LABEL_27:
    dev_err(a1, "FLTR_CFG_ERR: Wrong input, try again.\n");
    goto LABEL_46;
  }
  if ( (unsigned int)kstrtoull(v14, 0, &v26) )
  {
    dev_err(a1, "FLTR_CFG_ERR: Wrong mask input, try again.\n");
    goto LABEL_46;
  }
  v16 = v25;
  v15 = v26;
  if ( (unsigned int)check_filter_match(*(_QWORD *)(v6 + 120), v10, v25, v26) )
  {
    dev_err(a1, "FLTR_CFG_ERR: %s match/mask above MAX value, try again.\n", v29);
    goto LABEL_46;
  }
  if ( !v10 )
  {
    v25 = 1LL << v16;
    v26 = 1LL << v15;
  }
  if ( v10 == 7 )
    LOBYTE(v10) = 0;
  v17 = strsep(&stringp, " ");
  if ( !v17 )
  {
LABEL_53:
    dev_err(a1, "FLTR_CFG_ERR: no ports provided, try again.\n");
    goto LABEL_46;
  }
  v18 = v17;
  v19 = 0;
  while ( 1 )
  {
    if ( (sysfs_streq(v18, "FILTER0") & 1) != 0 )
    {
      v7 = 0;
      goto LABEL_52;
    }
    if ( (sysfs_streq(v18, "FILTER1") & 1) != 0 )
      break;
    if ( (unsigned int)kstrtou8(v18, 0, v27) )
    {
      dev_err(a1, "FLTR_CFG_ERR: Wrong port input, try again.\n");
      goto LABEL_46;
    }
    if ( ((1 << v27[0]) & *(unsigned __int16 *)(*(_QWORD *)(v6 + 112) + 8LL)) == 0 )
    {
      dev_err(a1, "FLTR_CFG_ERR: port doesn't exist, try again.\n");
      goto LABEL_46;
    }
    if ( ((1 << v10) & *(unsigned __int8 *)(*(_QWORD *)(v6 + 120) + v27[0] + 12LL)) == 0 )
    {
      dev_err(a1, "FLTR_CFG_ERR: port %u don't support %s filter try again.\n", v27[0], (const char *)v29);
      goto LABEL_46;
    }
    v19 |= (unsigned __int16)(1 << v27[0]);
    v18 = strsep(&stringp, " ");
    if ( !v18 )
      goto LABEL_52;
  }
  v7 = 1;
LABEL_52:
  if ( !v19 )
    goto LABEL_53;
  if ( v7 >= *(unsigned __int8 *)(*(_QWORD *)(v6 + 112) + 4LL) )
  {
    dev_err(a1, "FLTR_CFG_ERR: Filter idx is not specified, try again.\n");
    goto LABEL_46;
  }
  *(_WORD *)(*(_QWORD *)(v6 + 64) + 2LL * v7) |= v19;
  if ( (unsigned __int64)*(unsigned __int8 *)(v6 + 130) + 20 > *(unsigned int *)(v6 + 44) )
  {
    dev_err(a1, "FLTR_CFG_ERR: Configuration limit exceeds, try again.\n");
    goto LABEL_46;
  }
  v23 = *(_QWORD *)(v6 + 16);
  *(_WORD *)(v23 + 2) = v19;
  *(_BYTE *)v23 = v10;
  *(_BYTE *)(v23 + 1) = v7;
  *(_QWORD *)(v23 + 4) = v25;
  *(_QWORD *)(v23 + 12) = v26;
  v24 = *(_BYTE *)(v6 + 130) + 20;
  *(_QWORD *)(v6 + 16) += 20LL;
  *(_BYTE *)(v6 + 130) = v24;
  *(_BYTE *)(v6 + 128) = 1;
  dev_info(a1, "%s filter applied on FILTER%u.\n", (const char *)v29, v7);
LABEL_47:
  mutex_unlock(v6 + 136);
  _ReadStatusReg(SP_EL0);
  return a4;
}
