__int64 __fastcall cnss_pci_dump_sbl_log(_QWORD *a1, unsigned int a2, unsigned int a3)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v4; // x25
  const char *v8; // x1
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v11; // x5
  __int64 v12; // x6
  __int64 v13; // x7
  unsigned int v14; // w21
  unsigned int v15; // w27
  unsigned int v16; // w23
  unsigned int v17; // w26
  bool v18; // cf
  const char *v19; // x1
  const char *v20; // x1
  __int64 result; // x0
  char v22; // [xsp+0h] [xbp-70h]
  char v23; // [xsp+0h] [xbp-70h]
  unsigned int v24; // [xsp+Ch] [xbp-64h]
  _QWORD v25[10]; // [xsp+10h] [xbp-60h] BYREF
  char v26; // [xsp+60h] [xbp-10h]
  __int64 v27; // [xsp+68h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = _ReadStatusReg(SP_EL0);
  v27 = *(_QWORD *)(StatusReg + 1808);
  v26 = 0;
  memset(v25, 0, sizeof(v25));
  if ( (*(_DWORD *)(v4 + 16) & 0xF0000) != 0 )
  {
    v8 = "irq";
  }
  else if ( (*(_DWORD *)(v4 + 16) & 0xFF00) != 0 )
  {
    v8 = "soft_irq";
  }
  else
  {
    v8 = (const char *)(v4 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v8,
    "cnss_pci_dump_sbl_log",
    7u,
    7u,
    "Dumping SBL log data(@0x%x[%u]) start\n",
    a2,
    a3,
    v22);
  if ( a3 >= 4 )
  {
    v15 = a3 >> 2;
    v16 = 0;
    v17 = 0;
    v24 = a2;
    while ( 1 )
    {
      if ( v16 >= 0x52 )
      {
        __break(0x5512u);
LABEL_36:
        __break(1u);
      }
      v14 = cnss_pci_reg_read(a1, a2, (_QWORD *)((char *)v25 + v16), v9, v10, v11, v12, v13);
      if ( v14 )
        break;
      if ( (unsigned __int64)v16 - 78 < 4 )
        goto LABEL_36;
      if ( *(_DWORD *)((char *)v25 + v16) )
      {
        v18 = v16 >= 0x49;
        v16 += 4;
        if ( v18 )
          v16 = cnss_dump_line_buf(v25, v16, 0);
        v17 = 0;
      }
      else
      {
        if ( v17 > 3 )
          goto LABEL_26;
        ++v17;
      }
      --v15;
      a2 += 4;
      if ( !v15 )
        goto LABEL_26;
    }
    if ( (*(_DWORD *)(v4 + 16) & 0xF0000) != 0 )
    {
      v19 = "irq";
    }
    else if ( (*(_DWORD *)(v4 + 16) & 0xFF00) != 0 )
    {
      v19 = "soft_irq";
    }
    else
    {
      v19 = (const char *)(v4 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v19,
      "cnss_pci_dump_sbl_log",
      3u,
      3u,
      "Failed to read reg 0x%x, ret: %d\n",
      a2,
      v14,
      v23);
LABEL_26:
    if ( v16 )
      cnss_dump_line_buf(v25, v16, 1);
    a2 = v24;
  }
  else
  {
    LOBYTE(v14) = 0;
  }
  if ( (*(_DWORD *)(v4 + 16) & 0xF0000) != 0 )
  {
    v20 = "irq";
  }
  else if ( (*(_DWORD *)(v4 + 16) & 0xFF00) != 0 )
  {
    v20 = "soft_irq";
  }
  else
  {
    v20 = (const char *)(v4 + 2320);
  }
  result = cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v20,
             "cnss_pci_dump_sbl_log",
             7u,
             7u,
             "Dumping SBL log data(@0x%x[%u]) ret: %d\n",
             a2,
             a3,
             v14);
  _ReadStatusReg(SP_EL0);
  return result;
}
