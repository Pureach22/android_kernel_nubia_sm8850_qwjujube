__int64 __fastcall cnss_dev_sol_handler(
        unsigned int a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  const char *v9; // x1
  __int64 v11; // x0
  __int64 v13; // x0
  int raw_value; // w8
  __int64 v15; // x7
  __int16 v16; // w9
  const char *v17; // x8
  int v18; // w9
  unsigned __int64 v19; // x21
  __int64 v20; // x0
  unsigned int v21; // w9
  char v22; // w10
  const char *v23; // x1
  unsigned __int64 v24; // x9
  const char *v25; // x1
  __int16 v26; // w10
  const char *v27; // x9
  __int64 v29; // x0
  const char *v30; // x1
  const char *v31; // x1
  unsigned int v38; // w8
  unsigned int v39; // w8
  unsigned int v42; // w8
  unsigned int v43; // w8
  char v44; // [xsp+0h] [xbp-10h]
  char v45; // [xsp+0h] [xbp-10h]

  if ( *(_QWORD *)(a2 + 528) == 4369 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v9 = "irq";
    }
    else
    {
      v16 = *(_DWORD *)(StatusReg + 16);
      v17 = (const char *)(StatusReg + 2320);
      if ( (v16 & 0xFF00) != 0 )
        v9 = "soft_irq";
      else
        v9 = v17;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v9,
      "cnss_dev_sol_handler",
      6u,
      6u,
      "Dev sol received for fig\n",
      a7,
      a8,
      v44);
    return 1;
  }
  v11 = *(unsigned int *)(a2 + 136);
  if ( (v11 & 0x80000000) != 0 )
  {
    raw_value = -22;
    v15 = *(_QWORD *)(a2 + 552);
    if ( (v15 & 0x10000000) != 0 )
      goto LABEL_18;
  }
  else
  {
    v13 = gpio_to_desc(v11);
    raw_value = gpiod_get_raw_value(v13);
    v15 = *(_QWORD *)(a2 + 552);
    if ( (v15 & 0x10000000) != 0 )
      goto LABEL_18;
  }
  v15 = *(_QWORD *)(a2 + 552);
  if ( (v15 & 0x40000000) != 0
    || (v15 = *(_QWORD *)(a2 + 552), (v15 & 0x10000) != 0)
    || (v15 = *(_QWORD *)(a2 + 552), (v15 & 0x20000000) != 0)
    || raw_value == 1 )
  {
LABEL_18:
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
      "cnss_dev_sol_handler",
      7u,
      7u,
      "Ignore Dev SOL IRQ (%u) with driver state 0x%lx, dev_sol_val: %d\n",
      a1,
      v15,
      raw_value);
    return 1;
  }
  v18 = *(_DWORD *)(a2 + 144);
  v19 = _ReadStatusReg(SP_EL0);
  v20 = cnss_ipc_log_context;
  v21 = v18 + 1;
  *(_DWORD *)(a2 + 144) = v21;
  if ( (*(_DWORD *)(v19 + 16) & 0xF0000) != 0 )
  {
    v22 = v15;
    v23 = "irq";
  }
  else
  {
    v22 = v15;
    if ( (*(_DWORD *)(v19 + 16) & 0xFF00) != 0 )
      v23 = "soft_irq";
    else
      v23 = (const char *)(v19 + 2320);
  }
  v29 = cnss_debug_ipc_log_print(
          v20,
          v23,
          "cnss_dev_sol_handler",
          7u,
          7u,
          "Dev SOL IRQ (%u) is asserted #%u with driver state 0x%lx, dev_sol_val: %d\n",
          a1,
          v21,
          v22);
  _X9 = (unsigned int *)(a2 + 6264);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v38 = __ldxr(_X9);
    v39 = v38 + 1;
  }
  while ( __stlxr(v39, _X9) );
  __dmb(0xBu);
  if ( v39 == 1 )
  {
    if ( (*(_DWORD *)(v19 + 16) & 0xF0000) != 0 )
    {
      v30 = "irq";
    }
    else if ( (*(_DWORD *)(v19 + 16) & 0xFF00) != 0 )
    {
      v30 = "soft_irq";
    }
    else
    {
      v30 = (const char *)(v19 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v30,
      "cnss_pm_stay_awake",
      7u,
      7u,
      "PM stay awake, state: 0x%lx, count: %d\n",
      *(_QWORD *)(a2 + 552),
      *(unsigned int *)(a2 + 6264),
      v45);
    v29 = pm_stay_awake(*(_QWORD *)a2 + 16LL);
  }
  _X9 = (unsigned int *)(a2 + 6264);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v42 = __ldxr(_X9);
    v43 = v42 - 1;
  }
  while ( __stlxr(v43, _X9) );
  __dmb(0xBu);
  if ( (v43 & 0x80000000) != 0 )
  {
    __break(0x800u);
  }
  else if ( !v43 )
  {
    if ( (*(_DWORD *)(v19 + 16) & 0xF0000) != 0 )
    {
      v31 = "irq";
    }
    else if ( (*(_DWORD *)(v19 + 16) & 0xFF00) != 0 )
    {
      v31 = "soft_irq";
    }
    else
    {
      v31 = (const char *)(v19 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v31,
      "cnss_pm_relax",
      7u,
      7u,
      "PM relax, state: 0x%lx, count: %d\n",
      *(_QWORD *)(a2 + 552),
      *(unsigned int *)(a2 + 6264),
      v45);
    v29 = pm_relax(*(_QWORD *)a2 + 16LL);
  }
  pm_system_wakeup(v29);
  cnss_bus_handle_dev_sol_irq(a2);
  return 1;
}
