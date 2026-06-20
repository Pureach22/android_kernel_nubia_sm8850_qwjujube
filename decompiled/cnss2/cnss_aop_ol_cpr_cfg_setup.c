__int64 __fastcall cnss_aop_ol_cpr_cfg_setup(__int64 a1, unsigned int *a2)
{
  size_t v4; // x2
  __int64 v5; // x6
  __int64 v6; // x7
  __int64 result; // x0
  _DWORD *v8; // x20
  __int64 v9; // x24
  unsigned int v10; // t1
  __int64 v11; // x25
  unsigned __int64 v12; // x23
  const char *v13; // x1
  const char *v14; // x1
  unsigned int *v15; // x26
  __int64 v16; // x7
  unsigned int v17; // w21
  size_t v18; // x0
  unsigned int v19; // w9
  const char *v20; // x28
  const char *v21; // x1
  __int64 v22; // x21
  const char *v23; // x27
  size_t v24; // x0
  size_t v25; // x0
  unsigned __int64 v26; // x2
  unsigned int v27; // w8
  unsigned int v28; // w9
  unsigned int v29; // w10
  __int64 v30; // x0
  const char *v31; // x1
  __int64 v32; // x7
  unsigned int v33; // w8
  unsigned int v34; // w10
  unsigned __int64 StatusReg; // x8
  const char *v36; // x1
  __int16 v37; // w9
  const char *v38; // x8
  unsigned int v39; // w8
  __int64 v40; // x21
  __int64 v41; // x22
  bool v42; // zf
  __int64 v43; // x0
  char v44; // [xsp+0h] [xbp-2C0h]
  char v45; // [xsp+0h] [xbp-2C0h]
  unsigned int v46; // [xsp+24h] [xbp-29Ch]
  _BYTE s[640]; // [xsp+30h] [xbp-290h] BYREF
  __int64 v48; // [xsp+2B0h] [xbp-10h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  result = 0;
  if ( (cnss_aop_ol_cpr_cfg_setup_config_done & 1) != 0 )
    goto LABEL_68;
  if ( *(int *)(a1 + 7704) < 1 || !*(_QWORD *)(a1 + 7688) || !*(_QWORD *)(a1 + 7640) && !*(_QWORD *)(a1 + 7648) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v36 = "irq";
    }
    else
    {
      v37 = *(_DWORD *)(StatusReg + 16);
      v38 = (const char *)(StatusReg + 2320);
      if ( (v37 & 0xFF00) != 0 )
        v36 = "soft_irq";
      else
        v36 = v38;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v36,
      "cnss_aop_ol_cpr_cfg_setup",
      7u,
      7u,
      "Mbox channel / QMP / PMU VReg Map not configured\n",
      v5,
      v6,
      v44);
    result = 0;
LABEL_67:
    cnss_aop_ol_cpr_cfg_setup_config_done = 1;
    goto LABEL_68;
  }
  if ( !a2 )
  {
    result = 4294967274LL;
LABEL_68:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v10 = *a2;
  v8 = a2 + 1;
  v9 = v10;
  if ( !v10 )
  {
    v39 = 1;
    goto LABEL_72;
  }
  v11 = 0;
  v12 = _ReadStatusReg(SP_EL0);
  v46 = 0;
  while ( 1 )
  {
    v14 = "irq";
    if ( (*(_DWORD *)(v12 + 16) & 0xF0000) == 0 )
    {
      if ( (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
        v14 = "soft_irq";
      else
        v14 = (const char *)(v12 + 2320);
    }
    v15 = &v8[12 * v11];
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v14,
      "cnss_aop_ol_cpr_cfg_setup",
      7u,
      7u,
      "FW_PMU Data: %s %d %d %d %d\n",
      (__int64)v15,
      v15[8],
      v15[9]);
    if ( !v15[8] && !v15[10] )
      goto LABEL_11;
    if ( *(_DWORD *)(a1 + 7704) )
    {
      v17 = 1;
      while ( 1 )
      {
        v18 = strlen(*(const char **)(*(_QWORD *)(a1 + 7688) + 8LL * (v17 - 1)));
        if ( strnstr(*(_QWORD *)(*(_QWORD *)(a1 + 7688) + 8LL * (v17 - 1)), &v8[12 * v11], v18) )
          break;
        v19 = v17 + 1;
        v17 += 2;
        if ( v19 >= *(_DWORD *)(a1 + 7704) )
          goto LABEL_9;
      }
      v20 = *(const char **)(*(_QWORD *)(a1 + 7688) + 8LL * v17);
      if ( v20 )
        break;
    }
LABEL_9:
    v13 = "irq";
    if ( (*(_DWORD *)(v12 + 16) & 0xF0000) == 0 )
    {
      if ( (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = (const char *)(v12 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v13,
      "cnss_aop_ol_cpr_cfg_setup",
      3u,
      3u,
      "No VREG mapping for %s\n",
      (__int64)&v8[12 * v11],
      v16,
      v45);
LABEL_11:
    if ( ++v11 == v9 )
    {
      v39 = v46 + 1;
LABEL_72:
      v40 = 0;
      result = 0;
      v41 = 40LL * v39 - 40;
      while ( 1 )
      {
        if ( v40 == 640 )
          goto LABEL_87;
        if ( (unsigned __int64)(v40 - 608) < 0xFFFFFFFFFFFFFD80LL )
          break;
        if ( *(_DWORD *)&s[v40 + 32] )
          result = cnss_aop_set_vreg_param(a1);
        if ( (unsigned __int64)(v40 - 605) < 0xFFFFFFFFFFFFFD7FLL )
          break;
        if ( *(_DWORD *)&s[v40 + 36] )
          result = cnss_aop_set_vreg_param(a1);
        if ( (result & 0x80000000) == 0 )
        {
          v42 = v41 == v40;
          v40 += 40;
          if ( !v42 )
            continue;
        }
        goto LABEL_67;
      }
      __break(1u);
LABEL_85:
      _fortify_panic(2, 32, v4 + 1);
LABEL_86:
      _fortify_panic(4, 32, 33);
LABEL_87:
      __break(0x5512u);
    }
  }
  v21 = "irq";
  if ( (*(_DWORD *)(v12 + 16) & 0xF0000) == 0 )
  {
    if ( (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
      v21 = "soft_irq";
    else
      v21 = (const char *)(v12 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v21,
    "cnss_aop_ol_cpr_cfg_setup",
    7u,
    7u,
    "%s mapped to %s\n",
    (__int64)&v8[12 * v11],
    (__int64)v20,
    v45);
  v22 = 0;
  v23 = s;
  while ( *v23 )
  {
    v24 = strnlen(v23, 0x20u);
    v4 = v24;
    if ( v24 >= 0x21 )
      goto LABEL_85;
    if ( v24 == 32 )
      goto LABEL_86;
    if ( strnstr(v23, v20, v24) )
      goto LABEL_44;
    ++v22;
    v23 += 40;
    if ( v22 == 16 )
      goto LABEL_11;
  }
  v25 = strnlen(v20, 0x20u);
  if ( v25 == -1 )
    goto LABEL_89;
  if ( v25 == 32 )
    v26 = 32;
  else
    v26 = v25 + 1;
  if ( v26 < 0x21 )
  {
    sized_strscpy(v23, v20);
LABEL_44:
    v27 = v15[8];
    if ( v27 )
      v27 = ((v15[9] + 3) & 0xFFFFFFFC) + 14;
    v28 = v15[10];
    if ( v28 )
      v28 = ((v15[11] + 3) & 0xFFFFFFFC) - 6;
    v29 = *((_DWORD *)v23 + 8);
    v30 = cnss_ipc_log_context;
    v31 = "irq";
    if ( v27 <= v29 )
      v32 = v29;
    else
      v32 = v27;
    if ( v28 <= *((_DWORD *)v23 + 9) )
      v33 = *((_DWORD *)v23 + 9);
    else
      v33 = v28;
    *((_DWORD *)v23 + 8) = v32;
    *((_DWORD *)v23 + 9) = v33;
    v34 = v46;
    if ( v46 <= (unsigned int)v22 )
      v34 = v22;
    v46 = v34;
    if ( (*(_DWORD *)(v12 + 16) & 0xF0000) == 0 )
    {
      if ( (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
        v31 = "soft_irq";
      else
        v31 = (const char *)(v12 + 2320);
    }
    cnss_debug_ipc_log_print(
      v30,
      v31,
      "cnss_aop_ol_cpr_cfg_setup",
      7u,
      7u,
      "Plat VReg Data: %s %d %d\n",
      (__int64)v23,
      v32,
      v33);
    goto LABEL_11;
  }
  v25 = _fortify_panic(7, 32, v26);
LABEL_89:
  v43 = _fortify_panic(2, -1, v25 + 1);
  return cnss_aop_set_vreg_param(v43);
}
