__int64 __fastcall cnss_pci_bhi_debug_reg_dump(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  _QWORD *v8; // x19
  int v9; // w8
  __int64 v10; // x6
  __int64 v11; // x7
  unsigned __int64 StatusReg; // x24
  const char *v13; // x1
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  __int64 v19; // x23
  const char *v20; // x21
  char **v21; // x8
  const char *v22; // x1
  char v23; // [xsp+0h] [xbp-10h]
  char v24; // [xsp+0h] [xbp-10h]
  unsigned int v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v8 = (_QWORD *)result;
  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_DWORD *)(result + 24);
  if ( v9 == 4369 || v9 == 4366 )
  {
    result = cnss_pci_check_link_status(result, a2, a3, a4, a5, a6, a7, a8);
    if ( !(_DWORD)result )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
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
        "cnss_pci_bhi_debug_reg_dump",
        7u,
        7u,
        "Start to dump PCIE BHIE DEBUG registers\n",
        v10,
        v11,
        v23);
      v19 = 0;
      v20 = "PCIE_BHIE_DEBUG_0";
      do
      {
        result = cnss_pci_reg_read(v8, LODWORD((&pci_bhi_debug)[v19 + 1]), &v25, v14, v15, v16, v17, v18);
        if ( (_DWORD)result )
          break;
        v22 = "irq";
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            v22 = "soft_irq";
          else
            v22 = (const char *)(StatusReg + 2320);
        }
        result = cnss_debug_ipc_log_print(
                   cnss_ipc_log_context,
                   v22,
                   "cnss_pci_bhi_debug_reg_dump",
                   7u,
                   7u,
                   "PCIE__%s = 0x%x\n",
                   (__int64)v20,
                   v25,
                   v24);
        v21 = &(&pci_bhi_debug)[v19];
        v19 += 2;
        v20 = v21[2];
      }
      while ( v19 != 22 );
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
