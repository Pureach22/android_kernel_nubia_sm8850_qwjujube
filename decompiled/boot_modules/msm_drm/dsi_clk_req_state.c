__int64 __fastcall dsi_clk_req_state(__int64 a1, unsigned int a2, unsigned int a3, char a4)
{
  __int64 v7; // x19
  __int64 result; // x0
  int v10; // w9
  int v11; // w22
  int v12; // w8
  int v13; // w8
  int v14; // w9
  int v15; // w9
  int v16; // w9
  int v17; // w8
  int v18; // w8
  int v19; // w8
  int v20; // w8
  int v21; // w8
  int v22; // w8
  unsigned int v23; // w20
  unsigned int v24; // w20

  if ( a3 > 2 || !a1 || a2 - 16 <= 0xFFFFFFF0 )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: Invalid params, client = %pK, clk = 0x%x, state = %d\n",
      (const void *)a1,
      a2,
      a3);
    return 4294967274LL;
  }
  v7 = *(_QWORD *)(a1 + 80);
  if ( *(_DWORD *)(v7 + 384) == 1 )
    return 0;
  if ( (a4 & 1) != 0 )
    mutex_lock(v7 + 32);
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: [%s]%s: CLK=%d, new_state=%d, core=%d, linkl=%d\n",
    (const char *)v7,
    (const char *)a1,
    a2,
    a3,
    *(_DWORD *)(a1 + 48),
    *(_DWORD *)(a1 + 52));
  if ( a3 == 1 )
  {
    if ( (a2 & 1) != 0 && (v10 = *(_DWORD *)(a1 + 48), ++*(_DWORD *)(a1 + 32), v10 != 1) )
    {
      v11 = 1;
      *(_DWORD *)(a1 + 48) = 1;
      if ( (a2 & 2) != 0 )
        goto LABEL_23;
    }
    else
    {
      v11 = 0;
      if ( (a2 & 2) != 0 )
      {
LABEL_23:
        v14 = *(_DWORD *)(a1 + 52);
        ++*(_DWORD *)(a1 + 36);
        if ( v14 != 1 )
        {
          v11 = 1;
          *(_DWORD *)(a1 + 52) = 1;
        }
      }
    }
    if ( (a2 & 4) != 0 )
    {
      v15 = *(_DWORD *)(a1 + 56);
      ++*(_DWORD *)(a1 + 40);
      if ( v15 != 1 )
      {
        v11 = 1;
        *(_DWORD *)(a1 + 56) = 1;
      }
    }
    if ( a2 >= 8 )
    {
      v16 = *(_DWORD *)(a1 + 60);
      ++*(_DWORD *)(a1 + 44);
      if ( v16 != 1 )
      {
        v11 = 1;
        *(_DWORD *)(a1 + 60) = 1;
      }
    }
    goto LABEL_59;
  }
  if ( (a3 | 2) != 2 )
  {
    v11 = 0;
    goto LABEL_59;
  }
  if ( (a2 & 1) == 0 )
  {
LABEL_19:
    v11 = 0;
    if ( (a2 & 2) == 0 )
      goto LABEL_43;
LABEL_36:
    v17 = *(_DWORD *)(a1 + 36);
    if ( v17 )
    {
      v18 = v17 - 1;
      *(_DWORD *)(a1 + 36) = v18;
      if ( v18 )
        goto LABEL_43;
      *(_DWORD *)(a1 + 52) = a3;
    }
    else
    {
      if ( a3 || *(_DWORD *)(a1 + 52) != 2 )
      {
        printk(&unk_222A1B, a1);
        goto LABEL_43;
      }
      *(_DWORD *)(a1 + 52) = 0;
    }
    v11 = 1;
    goto LABEL_43;
  }
  v12 = *(_DWORD *)(a1 + 32);
  if ( v12 )
  {
    v13 = v12 - 1;
    *(_DWORD *)(a1 + 32) = v13;
    if ( v13 )
      goto LABEL_19;
    *(_DWORD *)(a1 + 48) = a3;
LABEL_35:
    v11 = 1;
    if ( (a2 & 2) == 0 )
      goto LABEL_43;
    goto LABEL_36;
  }
  if ( !a3 && *(_DWORD *)(a1 + 48) == 2 )
  {
    *(_DWORD *)(a1 + 48) = 0;
    goto LABEL_35;
  }
  printk(&unk_23375C, a1);
  v11 = 0;
  if ( (a2 & 2) != 0 )
    goto LABEL_36;
LABEL_43:
  if ( (a2 & 4) == 0 )
    goto LABEL_51;
  v19 = *(_DWORD *)(a1 + 40);
  if ( v19 )
  {
    v20 = v19 - 1;
    *(_DWORD *)(a1 + 40) = v20;
    if ( v20 )
      goto LABEL_51;
    *(_DWORD *)(a1 + 56) = a3;
  }
  else
  {
    if ( a3 || *(_DWORD *)(a1 + 56) != 2 )
    {
      printk(&unk_230473, a1);
      if ( a2 < 8 )
        goto LABEL_59;
      goto LABEL_52;
    }
    *(_DWORD *)(a1 + 56) = 0;
  }
  v11 = 1;
LABEL_51:
  if ( a2 < 8 )
    goto LABEL_59;
LABEL_52:
  v21 = *(_DWORD *)(a1 + 44);
  if ( v21 )
  {
    v22 = v21 - 1;
    *(_DWORD *)(a1 + 44) = v22;
    if ( v22 )
      goto LABEL_59;
    *(_DWORD *)(a1 + 60) = a3;
    goto LABEL_58;
  }
  if ( !a3 && *(_DWORD *)(a1 + 60) == 2 )
  {
    *(_DWORD *)(a1 + 60) = 0;
LABEL_58:
    v11 = 1;
    goto LABEL_59;
  }
  printk(&unk_264217, a1);
LABEL_59:
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s]%s: changed=%d", (const char *)v7, (const char *)a1, v11);
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: Core  (ref=%d, state=%d), Link (ref=%d, state=%d)",
    *(_DWORD *)(a1 + 32),
    *(_DWORD *)(a1 + 48),
    *(_DWORD *)(a1 + 36),
    *(_DWORD *)(a1 + 52));
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: Esync (ref=%d, state=%d), Osc  (ref=%d, state=%d)",
    *(_DWORD *)(a1 + 40),
    *(_DWORD *)(a1 + 56),
    *(_DWORD *)(a1 + 44),
    *(_DWORD *)(a1 + 60));
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dsi_clk_req_state",
    1529,
    -1,
    a1,
    *(_DWORD *)(a1 + 32),
    *(_DWORD *)(a1 + 36),
    v11,
    239);
  result = 0;
  if ( v11 )
  {
    result = ((__int64 (__fastcall *)(__int64))dsi_recheck_clk_state)(v7);
    if ( (_DWORD)result )
    {
      v23 = result;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to adjust clock state rc = %d\n", result);
      result = v23;
    }
  }
  if ( (a4 & 1) != 0 )
  {
    v24 = result;
    mutex_unlock(v7 + 32);
    return v24;
  }
  return result;
}
