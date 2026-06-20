__int64 __fastcall cnss_get_clk(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x25
  _QWORD **v10; // x19
  unsigned __int64 StatusReg; // x8
  const char *v12; // x1
  unsigned int v13; // w21
  __int64 v14; // x0
  __int64 v15; // x7
  __int64 v16; // x9
  __int64 v17; // x22
  unsigned __int64 v18; // x0
  unsigned __int64 v19; // x8
  int v20; // w9
  const char *v21; // x1
  __int16 v22; // w9
  const char *v23; // x8
  unsigned __int64 v24; // x8
  const char *v25; // x1
  __int16 v26; // w9
  const char *v27; // x8
  __int16 v28; // w9
  const char *v29; // x8
  const char *v30; // x5
  unsigned int v31; // w3
  unsigned int v32; // w4
  __int16 v33; // w9
  const char *v34; // x8
  int v35; // w23
  _QWORD *v36; // x22
  unsigned __int64 v37; // x26
  _QWORD *v38; // x8
  __int64 v39; // x9
  unsigned __int64 v40; // x8
  __int64 v41; // x28
  const char *v42; // x1
  __int64 *v43; // x1
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return (unsigned int)-19;
  v8 = *a1;
  v10 = (_QWORD **)(a1 + 5);
  if ( (_QWORD *)a1[5] != a1 + 5 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v22 = *(_DWORD *)(StatusReg + 16);
      v23 = (const char *)(StatusReg + 2320);
      if ( (v22 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v23;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v12,
      "cnss_get_clk",
      7u,
      7u,
      "Clocks have already been updated\n",
      a7,
      a8,
      vars0);
    return 0;
  }
  v14 = devm_kmalloc(v8 + 16, 48, 3520);
  if ( v14 )
  {
    v16 = *a1;
    v17 = v14;
    *(_QWORD *)(v14 + 24) = "rf_clk";
    *(_QWORD *)(v14 + 32) = 0;
    v18 = devm_clk_get(v16 + 16, "rf_clk");
    v13 = v18;
    if ( v18 < 0xFFFFFFFFFFFFF001LL )
    {
      *(_QWORD *)(v17 + 16) = v18;
      v24 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v24 + 16) & 0xF0000) != 0 )
      {
        v25 = "irq";
      }
      else
      {
        v26 = *(_DWORD *)(v24 + 16);
        v27 = (const char *)(v24 + 2320);
        if ( (v26 & 0xFF00) != 0 )
          v25 = "soft_irq";
        else
          v25 = v27;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v25,
        "cnss_get_clk_single",
        7u,
        7u,
        "Got clock: %s, freq: %u\n",
        (__int64)"rf_clk",
        *(unsigned int *)(v17 + 32),
        vars0);
    }
    else
    {
      v19 = _ReadStatusReg(SP_EL0);
      v20 = *(_DWORD *)(v19 + 16) & 0xF0000;
      if ( *(_DWORD *)(v17 + 36) )
      {
        if ( v20 )
        {
          v21 = "irq";
        }
        else
        {
          v28 = *(_DWORD *)(v19 + 16);
          v29 = (const char *)(v19 + 2320);
          if ( (v28 & 0xFF00) != 0 )
            v21 = "soft_irq";
          else
            v21 = v29;
        }
        v30 = "Failed to get clock %s, err = %d\n";
        v31 = 3;
        v32 = 3;
      }
      else
      {
        if ( v20 )
        {
          v21 = "irq";
        }
        else
        {
          v33 = *(_DWORD *)(v19 + 16);
          v34 = (const char *)(v19 + 2320);
          if ( (v33 & 0xFF00) != 0 )
            v21 = "soft_irq";
          else
            v21 = v34;
        }
        v30 = "Failed to get optional clock %s, err = %d\n";
        v31 = 7;
        v32 = 7;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v21,
        "cnss_get_clk_single",
        v31,
        v32,
        v30,
        (__int64)"rf_clk",
        (unsigned int)v18,
        vars0);
      if ( v13 )
      {
        v35 = *(_DWORD *)(v17 + 36);
        devm_kfree(v8 + 16, v17);
        if ( !v35 )
          return 0;
        goto LABEL_34;
      }
    }
    v43 = (__int64 *)a1[6];
    if ( (_QWORD **)v17 == v10 || v43 == (__int64 *)v17 || (_QWORD **)*v43 != v10 )
    {
      _list_add_valid_or_report(v17, v43);
      return 0;
    }
    else
    {
      v13 = 0;
      a1[6] = v17;
      *(_QWORD *)v17 = v10;
      *(_QWORD *)(v17 + 8) = v43;
      *v43 = v17;
    }
    return v13;
  }
  v13 = -12;
LABEL_34:
  v36 = *v10;
  if ( *v10 != v10 )
  {
    v37 = _ReadStatusReg(SP_EL0);
    do
    {
      v38 = (_QWORD *)v36[1];
      if ( (_QWORD *)*v38 == v36 && (v39 = *v36, *(_QWORD **)(*v36 + 8LL) == v36) )
      {
        *(_QWORD *)(v39 + 8) = v38;
        *v38 = v39;
      }
      else
      {
        _list_del_entry_valid_or_report(v36);
      }
      v40 = v36[2];
      *v36 = 0xDEAD000000000100LL;
      v36[1] = 0xDEAD000000000122LL;
      if ( v40 && v40 <= 0xFFFFFFFFFFFFF000LL )
      {
        v41 = *a1;
        v42 = "irq";
        if ( (*(_DWORD *)(v37 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v37 + 16) & 0xFF00) != 0 )
            v42 = "soft_irq";
          else
            v42 = (const char *)(v37 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v42,
          "cnss_put_clk_single",
          7u,
          7u,
          "Put clock: %s\n",
          v36[3],
          v15,
          vars0);
        devm_clk_put(v41 + 16, v36[2]);
        devm_kfree(v8 + 16, v36);
      }
      v36 = *v10;
    }
    while ( *v10 != v10 );
  }
  return v13;
}
