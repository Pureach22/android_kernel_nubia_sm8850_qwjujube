__int64 __fastcall cnss_pci_dump_qdss_reg(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x21
  __int64 v9; // x20
  __int64 v11; // x2
  __int64 result; // x0
  const char *v13; // x1
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  char *v19; // x1
  __int64 v20; // x3
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  char *v25; // x1
  __int64 v26; // x3
  __int64 v27; // x4
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x7
  char *v31; // x1
  __int64 v32; // x3
  __int64 v33; // x4
  __int64 v34; // x5
  __int64 v35; // x6
  __int64 v36; // x7
  const char *v37; // x1
  char v38; // [xsp+0h] [xbp-10h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = a1[1];
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 || (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    v11 = 2336;
    if ( !*(_QWORD *)(v9 + 6232) )
      goto LABEL_6;
  }
  else
  {
    v11 = 3520;
    if ( !*(_QWORD *)(v9 + 6232) )
    {
LABEL_6:
      result = devm_kmalloc(*a1 + 200LL, 16, v11);
      *(_QWORD *)(v9 + 6232) = result;
      if ( !result )
        return result;
    }
  }
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v13 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v13 = "soft_irq";
  }
  else
  {
    v13 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v13,
    "cnss_pci_dump_qdss_reg",
    7u,
    7u,
    "Start to dump qdss registers\n",
    a7,
    a8,
    v38);
  result = cnss_pci_reg_read(a1, 29364332, *(_DWORD **)(v9 + 6232), v14, v15, v16, v17, v18);
  if ( !(_DWORD)result )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      v19 = "irq";
    else
      v19 = (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(StatusReg + 2320);
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v19,
      "cnss_pci_dump_qdss_reg",
      7u,
      7u,
      "%s[0x%x] = 0x%x\n",
      (__int64)"QDSSCSR_ETRIRQCTRL",
      29364332,
      **(_DWORD **)(v9 + 6232));
    result = cnss_pci_reg_read(a1, 29364336, (_DWORD *)(*(_QWORD *)(v9 + 6232) + 4LL), v20, v21, v22, v23, v24);
    if ( !(_DWORD)result )
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        v25 = "irq";
      else
        v25 = (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(StatusReg + 2320);
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v25,
        "cnss_pci_dump_qdss_reg",
        7u,
        7u,
        "%s[0x%x] = 0x%x\n",
        (__int64)"QDSSCSR_PRESERVEETF",
        29364336,
        *(_DWORD *)(*(_QWORD *)(v9 + 6232) + 4LL));
      result = cnss_pci_reg_read(a1, 29364340, (_DWORD *)(*(_QWORD *)(v9 + 6232) + 8LL), v26, v27, v28, v29, v30);
      if ( !(_DWORD)result )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          v31 = "irq";
        else
          v31 = (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(StatusReg + 2320);
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v31,
          "cnss_pci_dump_qdss_reg",
          7u,
          7u,
          "%s[0x%x] = 0x%x\n",
          (__int64)"QDSSCSR_PRESERVEETR0",
          29364340,
          *(_DWORD *)(*(_QWORD *)(v9 + 6232) + 8LL));
        result = cnss_pci_reg_read(a1, 29364344, (_DWORD *)(*(_QWORD *)(v9 + 6232) + 12LL), v32, v33, v34, v35, v36);
        if ( !(_DWORD)result )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v37 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v37 = "soft_irq";
          }
          else
          {
            v37 = (const char *)(StatusReg + 2320);
          }
          return cnss_debug_ipc_log_print(
                   cnss_ipc_log_context,
                   v37,
                   "cnss_pci_dump_qdss_reg",
                   7u,
                   7u,
                   "%s[0x%x] = 0x%x\n",
                   (__int64)"QDSSCSR_PRESERVEETR1",
                   29364344,
                   *(_DWORD *)(*(_QWORD *)(v9 + 6232) + 12LL));
        }
      }
    }
  }
  return result;
}
