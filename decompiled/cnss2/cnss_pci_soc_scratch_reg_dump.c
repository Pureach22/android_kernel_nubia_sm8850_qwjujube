__int64 __fastcall cnss_pci_soc_scratch_reg_dump(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned int v8; // w8
  bool v9; // cc
  int v10; // w8
  unsigned __int64 StatusReg; // x20
  _QWORD *v13; // x19
  __int64 v14; // x6
  __int64 v15; // x7
  char *v16; // x1
  __int64 v17; // x3
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 v21; // x7
  char *v22; // x1
  __int64 v23; // x3
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  char *v28; // x1
  __int64 v29; // x3
  __int64 v30; // x4
  __int64 v31; // x5
  __int64 v32; // x6
  __int64 v33; // x7
  const char *v34; // x1
  char v35; // [xsp+0h] [xbp-10h]
  char v36; // [xsp+0h] [xbp-10h]
  char v37; // [xsp+0h] [xbp-10h]
  char v38; // [xsp+0h] [xbp-10h]
  unsigned int v39; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v40; // [xsp+8h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_DWORD *)(result + 24) - 4353;
  v9 = v8 > 0x11;
  v10 = (1 << v8) & 0x32245;
  if ( !v9 && v10 != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) == 0 && (_ReadStatusReg(DAIF) & 0x80) == 0 )
    {
      v13 = (_QWORD *)result;
      result = cnss_pci_check_link_status(result, a2, a3, a4, a5, a6, a7, a8);
      if ( !(_DWORD)result )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          v16 = "irq";
        else
          v16 = (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(StatusReg + 2320);
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v16,
          "cnss_pci_soc_scratch_reg_dump",
          7u,
          7u,
          "Start to dump SOC Scratch registers\n",
          v14,
          v15,
          v35);
        result = cnss_pci_reg_read(v13, 31473728, &v39, v17, v18, v19, v20, v21);
        if ( !(_DWORD)result )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            v22 = "irq";
          else
            v22 = (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(StatusReg + 2320);
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v22,
            "cnss_pci_soc_scratch_reg_dump",
            7u,
            7u,
            "PCIE_SOC_REG_%s = 0x%x\n",
            (__int64)"PCIE_SCRATCH_0",
            v39,
            v36);
          result = cnss_pci_reg_read(v13, 31473732, &v39, v23, v24, v25, v26, v27);
          if ( !(_DWORD)result )
          {
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
              v28 = "irq";
            else
              v28 = (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(StatusReg + 2320);
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v28,
              "cnss_pci_soc_scratch_reg_dump",
              7u,
              7u,
              "PCIE_SOC_REG_%s = 0x%x\n",
              (__int64)"PCIE_SCRATCH_1",
              v39,
              v37);
            result = cnss_pci_reg_read(v13, 31473756, &v39, v29, v30, v31, v32, v33);
            if ( !(_DWORD)result )
            {
              if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
              {
                v34 = "irq";
              }
              else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              {
                v34 = "soft_irq";
              }
              else
              {
                v34 = (const char *)(StatusReg + 2320);
              }
              result = cnss_debug_ipc_log_print(
                         cnss_ipc_log_context,
                         v34,
                         "cnss_pci_soc_scratch_reg_dump",
                         7u,
                         7u,
                         "PCIE_SOC_REG_%s = 0x%x\n",
                         (__int64)"PCIE_SCRATCH_2",
                         v39,
                         v38);
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
